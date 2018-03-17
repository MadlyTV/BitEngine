#pragma once

#include "MemoryManager.h"

namespace bt { namespace internal {

	struct SystemInfo
	{
		SystemMemoryInfo memoryInfo;
	};

	//Low-Level system operations
	class System {
	private:
		static SystemInfo s_SystemInfo;
	public:
		static void Init();
		static void Shutdown();

		static SystemInfo GetSystemInfo();
	private:
		static void LogSystemInfo();
	};

} }