#pragma once

#ifndef TIME_H
#define TIME_H

#include <string>
#include <sstream>
#include <ctime>

class Time {
public:
	static const std::string getTime() {
		
		time_t t = time(0);
		struct tm * now = localtime(&t);

		return std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);

	}

	/*static const std::string getDate() {

		std::ostringstream oss;

		CTime time = CTime::GetCurrentTime();
		oss << time.GetDay()
			<< ":"
			<< time.GetMonth()
			<< ":"
			<< time.GetYear();
		return oss.str();

	}*/
};

#endif //TIME_H
