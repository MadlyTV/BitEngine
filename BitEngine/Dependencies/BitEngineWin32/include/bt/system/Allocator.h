#pragma once

#include "bt\common.h"
#include "bt\types.h"

namespace bt {

	class BT_API Allocator {
	public:
		static void* Allocate(size_t size);
		static void* AllocateDebug(size_t size, const char* file, uint line);

		static void Free(void* block);
		static void FreeDebug(void* block, const char* file, uint line);
	};
}