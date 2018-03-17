#pragma once

#include "bt\common.h"

namespace bt {

	struct Members;
	
	class BT_API Timer {
	private:
		byte m_Reserverd[32];
		Members* m_Members;
	public:
		//Creates and starts timer
		Timer();
		//Resets and restarts Timer
		virtual void Reset();
		//returns timer in seconds
		virtual float Elapsed();
		//return time in milliseconds
		virtual float ElapsedMillis();
	};
}