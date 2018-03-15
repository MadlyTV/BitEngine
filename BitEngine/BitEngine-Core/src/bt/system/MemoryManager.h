#pragma once

#include "bt\String.h"

namespace bt { namespace internal {

	struct BT_API SystemMemoryInfo
	{
		int64 availblePhysicalMemory;
		int64 totalPhysicalMemory;

		int64 availableVirtualMemory;
		int64 totalVirtualMemory;

		void Log();
	};

	struct BT_API MemoryStats
	{
		int64 totalAllocated;
		int64 totalFreed;
		int64 currentUsed;
		int64 totalAllocations;

		MemoryStats() 
			: totalAllocated(0), totalFreed(0), currentUsed(0), totalAllocations(0)
		{ }
	};

	class BT_API MemoryManager {
	public:
		static MemoryManager* s_Instance;
	public:
		MemoryStats m_MemoryStats;
	public:
		MemoryManager();

		static void init();
		static void Shutdown();

		static MemoryManager* get();
		inline MemoryStats GetMemoryStats() { return m_MemoryStats; }
	public:
		SystemMemoryInfo GetSystemInfo();
	public:
		static String BytesToString(int64 bytes);
	};

} }