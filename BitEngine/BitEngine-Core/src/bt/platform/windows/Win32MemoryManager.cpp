#include "bt\bt.h"
#include "bt\system\MemoryManager.h"

#include <Windows.h>

namespace bt { namespace internal {
	SystemMemoryInfo MemoryManager::GetSystemInfo() {
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&status);

		SystemMemoryInfo result = {
			(int64)status.ullAvailPhys,
			(int64)status.ullTotalPhys,

			(int64)status.ullAvailVirtual,
			(int64)status.ullTotalVirtual
		};
		return result;
	}
} }