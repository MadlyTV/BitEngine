#include "bt\bt.h"
#include "MemoryManager.h"

#include "bt\utils\Log.h"
#include "Memory.h"

namespace bt { namespace internal {

	MemoryManager* MemoryManager::s_Instance = nullptr;

	MemoryManager::MemoryManager() {

	}

	void MemoryManager::init() {

	}

	void MemoryManager::Shutdown() {
		btdel s_Instance;
	}

	MemoryManager* MemoryManager::get() {
		if (s_Instance == nullptr) {
			s_Instance = (MemoryManager*)malloc(sizeof(MemoryManager));
			s_Instance = new(s_Instance)MemoryManager();
		}
		return s_Instance;
	}

	String MemoryManager::BytesToString(int64 bytes) {
		static const float gb = 1024 * 1024 * 1024;
		static const float mb = 1024 * 1024;
		static const float kb = 1024;

		String result;
		if (bytes > gb) {
			result = StringFormat::Float(bytes / gb) + " GB";
		}
		else if (bytes > gb) {
			result = StringFormat::Float(bytes / mb) + " MB";
		}
		else if (bytes > gb) {
			result = StringFormat::Float(bytes / kb) + " KB";
		}
		else {
			result = StringFormat::Float((float)bytes) + " bytes";
		}

		return result;
	}

	void SystemMemoryInfo::Log() {
		String apm, tpm, avm, tvm;

		uint gb = 1024 * 1024 * 1024;
		uint mb = 1024 * 1024;
		uint kb = 1024;

		apm = MemoryManager::BytesToString(availblePhysicalMemory);
		tpm = MemoryManager::BytesToString(totalPhysicalMemory);
		avm = MemoryManager::BytesToString(availableVirtualMemory);
		tvm = MemoryManager::BytesToString(totalVirtualMemory);

		BT_INFO();
		BT_INFO("Memory Info:");
		BT_INFO("\tPhysical Memory (Avail/Total): ", apm, " / ", tpm);
		BT_INFO("\tVirtual Memory (Avail/Total): ", avm, " / ", tvm);
		BT_INFO();
	}

} }