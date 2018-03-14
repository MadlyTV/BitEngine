#pragma once

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <Windows.h>
#include <sstream>
#include <iostream>

#include "../utils/time.h"

enum loglevel_e
{
	logERROR, logWARNING, logINFO, logDEBUG, logDEBUG1, logDEBUG2, logDEBUG3, logDEBUG4
};

class logIt
{
public:
	logIt(loglevel_e _loglevel = logERROR) {
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		/*switch (_loglevel)
		{
		case logERROR:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_INTENSITY));
			break;
		case logWARNING:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY));
			break;
		case logINFO:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY));
			break;
		case logDEBUG:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY));
			break;
		case logDEBUG1:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN * 2 | FOREGROUND_BLUE));
			break;
		case logDEBUG2:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN  | FOREGROUND_BLUE * 2 | FOREGROUND_INTENSITY));
			break;
		case logDEBUG3:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED  | FOREGROUND_BLUE | FOREGROUND_INTENSITY));
			break;
		case logDEBUG4:
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED * 2 | FOREGROUND_BLUE | FOREGROUND_INTENSITY));
			break;
		}*/
		_buffer << Time::getTime() << " :" <<
				std::string(
				_loglevel > logDEBUG
				? (_loglevel - logDEBUG) * 4
				: 1
				, ' ');
	}

	template <typename T>
	logIt & operator<<(T const & value)
	{
		_buffer << value;
		return *this;
	}

	~logIt()
	{
		_buffer << std::endl;
		std::cerr << _buffer.str();
		//SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED));
	}

private:
	std::ostringstream _buffer;
};

extern loglevel_e loglevel;

#define log(level) \
if (level > loglevel) ; \
else logIt(level)

#endif