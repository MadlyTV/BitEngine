#include "bt\bt.h"
#include "System.h"

#include "MemoryManager.h"
#include "VFS.h"

#include "bt\utils\Log.h"

namespace bt { namespace internal {

	SystemInfo System::s_SystemInfo;

	void System::Init() {
		BT_INFO("Initializing BitEngine System...");
		MemoryManager::Init();
		VFS::Init();

		s_SystemInfo.memoryInfo = MemoryManager::Get()->GetSystemInfo();
		LogSystemInfo();
	}

	void System::Shutdown() {
		BT_INFO("Shutting down BitEngien System...");
		VFS::Shutdown();
		MemoryManager::Shutdown();
	}

	SystemInfo System::GetSystemInfo() {
		return s_SystemInfo;
	}

	void System::LogSystemInfo() {
		BT_INFO("--------------------");
		BT_INFO(" System Information ");
		BT_INFO("--------------------");
		s_SystemInfo.memoryInfo.Log();
	}

} }