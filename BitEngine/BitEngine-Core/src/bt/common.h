#pragma once
#pragma warning (disable:4251)

#ifdef BT_PLATFORM_WINDOWS
	#ifdef BT_CORE_DLL
		#define BT_API __declspec(dllexport)
	#else
		#define BT_API __declspec(dllimport)
	#endif 
#else
	#define BT_API
#endif

//common define

#define BIT(x) (1 << x)

#define METHOD_1(x) std::bind(x,this,std::placeholders::_1)
#define METHOD(x) METHOD_1(x)

#ifdef BT_DEBUG
	#define BT_DEBUG_METHOD_V(x) x;
#else
	#define BT_DEBUG_METHOD_V(x) x {}
#endif