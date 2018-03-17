#pragma once

#include "bt\common.h"
#include "bt\types.h"

#include "bt\String.h"

#include "bt\maths\vec2.h"
#include "bt\maths\Rectangle.h"
#include "bt\events\Events.h"

#define BITENGINE_LOG_LEVEL_FATAL 0
#define BITENGINE_LOG_LEVEL_ERROR 1
#define BITENGINE_LOG_LEVEL_WARN 2
#define BITENGINE_LOG_LEVEL_INFO 3

#ifdef MOUSE_MOVED
	#undef MOUSE_MOVED
#endif // MOUSE_MOVED

namespace std {
	template <typename T>
	string to_string(const T& t) {
		return string("[Unsupported type (") + typeid(T).name() + string(")!] (to_string)");
	}
}

//
//	WIP
//
//-------------------------------
//			TODO:
//--------------------------------
// - Better containder type logging
// - Better platform support
//	- logging to other destinations (eg. files)
//	- Include (almost) all bitengine class types
// - Mouse and Key events
//	- more
//

namespace bt { namespace internal {

	static char to_string_buffer[1024 * 10];
	static char sprintf_buffer[1024 * 10];

	BT_API void PlatformLogMessage(uint level, const char* message);

	template <class T>
	struct has_iterator
	{
		template<class U> static char(&test(typename U::iterator const*))[1];
		template<class U> static char(&test(...))[2];
		static const bool value = (sizeof(test<T>(0)) == 1);
	};

	template <typename T>
	static const char* to_string(const T& t) {
		return to_string_internal<T>(t, std::integral_constant<bool, has_iterator<T>::value>());
	}

	template <>
	static const char* to_string<char>(const char& t) {
		return &t;
	}

	template <>
	static const char* to_string<char*>(char* const& t) {
		return t;
	}

	template <>
	static const char* to_string<unsigned char const*>(unsigned char const* const& t) {
		return(const char*)t;
	}

	template <>
	static const char* to_string<wchar_t*>(wchar_t* const& t) {
		wcstombs(sprintf_buffer, t, 1024 * 10);
		return sprintf_buffer;
	}

	template <>
	static const char* to_string<const wchar_t*>(const wchar_t* const& t) {
		wcstombs(sprintf_buffer, t, 1024 * 10);
		return sprintf_buffer;
	}

	template <>
	static const char* to_string<const char*>(const char* const& t) {
		return t;
	}

	template <>
	static const char* to_string<String>(const String& t) {
		return t.c_str();
	}

	template <>
	static const char* to_string<bool>(const bool& t) {
		return t ? "true" : "false";
	}

	template <>
	static const char* to_string<maths::vec2>(const maths::vec2& t) {
		//TODO sprintf
		String string = String("Vec2: (") + StringFormat::ToString(t.x) + ", " + StringFormat::ToString(t.y) + ")";
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
	}

	template <>
	static const char* to_string<maths::vec3>(const maths::vec3& t) {
		//TODO sprintf
		String string = String("Vec2: (") + StringFormat::ToString(t.x) + ", " + StringFormat::ToString(t.y) + ", " + StringFormat::ToString(t.z) +  ")";
		char* result = new char[string.length()];
		strcpy(result, &string[0]);
		return result;
	}

	template <>
	static const char* to_string<maths::Rectangle>(const maths::Rectangle& r)
	{
		sprintf(sprintf_buffer, "Rectangle: (%f, %f, %f, %f)", r.x, r.y, r.width, r.height);
		char* result = new char[strlen(sprintf_buffer)];
		strcpy(result, &sprintf_buffer[0]);
		return result;
	}

	//TODO: mouse and key events

	template <>
	static const char* to_string<events::Event>(const events::Event& e) {
		sprintf(sprintf_buffer, "Event: %s (%d)", events::Event::TypeToString(e.GetType()).c_str(), e.GetType());
		char* result = new char[strlen(sprintf_buffer)];
		strcpy(result, &sprintf_buffer[0]);
		return result;
	}

	template <>
	static const char* to_string<events::Event*>(events::Event* const& e) {
		using namespace events;

		switch (e->GetType())
		{
			//add Key and mouse events
		}
		return "Unkown Event";
	}

	template <typename T>
	static String format_iterators(T& begin, T& end) {
		String result;
		bool first = true;
		while (begin != end) {
			if (!first)
				result += ", ";
			result += to_string(*begin);
			first = false;
			begin++;
		}
		return result;
	}

	template <typename T>
	static const char* to_string_internal(const T& v, const std::true_type& ignored) {
		sprintf(to_string_buffer, "Container of size: %d, contents: %s", v.size(), format_iterators(v.begin(), v.end()).c_str());
		return to_string_buffer;
	}

	template <typename T>
	static const char* to_string_internal(const T& t, const std::false_type& ignored) {
		auto x = StringFormat::ToString(t);
		return strcpy(to_string_buffer, x.c_str());
	}

	template <typename X, typename Y>
	static const char* to_string(const std::pair<typename X, typename Y>& v) {
		sprintf(to_string_buffer, "(Key: %s, Value: %s)", to_string(v.first), to_string(v.second));
		return to_string_buffer;
	}

	template <>
	static const char* to_string_internal<const char*>(const char* const& v, const std::false_type& ignored) {
		return v;
	}

	template<typename First>
	static void print_log_internal(char* buffer, int32& position, First&& first) {
		const char* formatted = bt::internal::to_string<First>(first);
		int32 lenght = strlen(formatted);
		memcpy(&buffer[position], formatted, lenght);
		position += lenght;
	}

	template<typename First, typename... Args>
	static void print_log_internal(char* buffer, int32& position, First&& first, Args&&... args) {
		const char* formatted = bt::internal::to_string<First>(first);
		int32 lenght = strlen(formatted);
		memcpy(&buffer[position], formatted, lenght);
		position += lenght;
		if (sizeof...(Args)) 
			print_log_internal(buffer, position, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static void log_message(int32 level, bool newline, Args... args) {
		char buffer[1024 * 10];
		int32 position = 0;
		print_log_internal(buffer, position, std::forward<Args>(args)...);

		if (newline)
			buffer[position++] = '\n';

		buffer[position] = 0;

		PlatformLogMessage(level, buffer);
	}
} }

// windows (wingdi.h) defines BT_ERROR
#ifdef BT_ERROR
#undef BT_ERROR
#endif

#ifndef BITENGINE_LOG_LEVEL
#define BITENGINE_LOG_LEVEL BITENGINE_LOG_LEVEL_INFO
#endif

#if BITENGINE_LOG_LEVEL >= BITENGINE_LOG_LEVEL_FATAL
#define BT_FATAL(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_FATAL, true, "BITENGINE:    ", __VA_ARGS__)
#define _BT_FATAL(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_FATAL, false, __VA_ARGS__)
#else
#define BT_FATAL(...)
#define _BT_FATAL(...)
#endif

#if BITENGINE_LOG_LEVEL >= BITENGINE_LOG_LEVEL_ERROR
#define BT_ERROR(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_ERROR, true, "BITENGINE:    ", __VA_ARGS__)
#define _BT_ERROR(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_ERROR, false, __VA_ARGS__)
#else
#define BT_ERROR(...)
#define _BT_ERROR(...)
#endif

#if BITENGINE_LOG_LEVEL >= BITENGINE_LOG_LEVEL_WARN
#define BT_WARN(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_WARN, true, "BITENGINE:    ", __VA_ARGS__)
#define _BT_WARN(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_WARN, false, __VA_ARGS__)
#else
#define BT_WARN(...)
#define _BT_WARN(...)
#endif

#if BITENGINE_LOG_LEVEL >= BITENGINE_LOG_LEVEL_INFO
#define BT_INFO(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_INFO, true, "BITENGINE:    ", __VA_ARGS__)
#define _BT_INFO(...) bt::internal::log_message(BITENGINE_LOG_LEVEL_INFO, false, __VA_ARGS__)
#else
#define BT_INFO(...)
#define _BT_INFO(...)
#endif

#ifdef BT_DEBUG
#define BT_ASSERT(x, ...) \
			if (!(x)) {\
				BT_FATAL("*************************"); \
				BT_FATAL("    ASSERTION FAILED!    "); \
				BT_FATAL("*************************"); \
				BT_FATAL(__FILE__, ": ", __LINE__); \
				BT_FATAL("Condition: ", #x); \
				BT_FATAL(__VA_ARGS__); \
				__debugbreak(); \
			}
#else
	#define BT_ASSERT(x,...)
#endif