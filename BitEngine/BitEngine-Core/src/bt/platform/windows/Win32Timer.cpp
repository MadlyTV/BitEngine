#include "bt\bt.h"
#include "bt\utils\timer.h"

#include <Windows.h>

namespace bt {
	struct Members {
		LARGE_INTEGER m_Start;
		double m_Frequency;
	};

	Timer::Timer() 
		: m_Members(new (m_Reserverd) Members())
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		m_Members->m_Frequency = 1.0f / frequency.QuadPart;

		Reset();
	}

	void Timer::Reset() {
		QueryPerformanceCounter(&m_Members->m_Start);
	}

	float Timer::Elapsed() {
		LARGE_INTEGER current;
		QueryPerformanceCounter(&current);
		uint64 cycles = current.QuadPart - m_Members->m_Start.QuadPart;
		return (float)(cycles* m_Members->m_Frequency);
	}

	float Timer::ElapsedMillis() {
		return Elapsed() * 1000.0f;
	}
}