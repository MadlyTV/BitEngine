#pragma once

#ifndef TIME_H
#define TIME_H

#include <string>
#include <sstream>
#include "platform.h"

#ifdef PLATFORM_WIN32
#include <atltime.h>
#elif PLATFORM_LINUX
//TODO: handling LINUX
#elif PLATFORM_MACOSX
//TOTO: handling MACOSX
#endif

class Time {
public:
	static const std::string getTime() {
		
		std::ostringstream oss;

#ifdef PLATFORM_WIN32

		CTime time = CTime::GetCurrentTime();
		oss << time.GetHour()
			<< ":"
			<< time.GetMinute()
			<< ":"
			<< time.GetSecond();

#else

		//TODO: Linux and MacOS X

#endif 

		return oss.str();

	}

	static const std::string getDate() {

		std::ostringstream oss;

#ifdef PLATFORM_WIN32

		CTime time = CTime::GetCurrentTime();
		oss << time.GetDay()
			<< ":"
			<< time.GetMonth()
			<< ":"
			<< time.GetYear();

#else

		//TODO: Linux and MacOS X

#endif 

		return oss.str();

	}
};

#endif //TIME_H
