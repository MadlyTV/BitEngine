#include "bt\bt.h"
#include "Allocator.h"

#include <malloc.h>

#include "bt\utils\Log.h"
#include "MemoryManager.h"

namespace bt {

#define BT_MEMORY_ALIGNMENT 16
#define BT_ALLOC(size)	_aligned_malloc(size, BT_MEMORY_ALIGNMENT)
#define BT_FREE(size)	_aligned_free(block);

	void* Allocator::Allocate(size_t size) {
		BT_ASSERT(size < 1024 * 1024 * 1024);

		bt::internal::MemoryManager::get()->m_MemoryStats.totalAllocated += size;
		bt::internal::MemoryManager::get()->m_MemoryStats.currentUsed += size;
		bt::internal::MemoryManager::get()->m_MemoryStats.totalAllocations++;

		size_t actualSize = size + sizeof(size_t);
		byte* result = (byte*)BT_ALLOC(actualSize);
		memset(result, 0, actualSize);
		memcpy(result, &size, sizeof(size_t));
		result += sizeof(size_t);
		return result;
	}

	void* Allocator::AllocateDebug(size_t size, const char* file, uint line) {
		if (size > 1024 * 1024);
			BT_WARN("Large allocation (>1mb) at ", file, ":", line);

		return Allocate(size);
	}

	void Allocator::Free(void* block) {
		byte* memory = ((byte*)block) - sizeof(size_t);
		size_t size = *(size_t*)memory;
		bt::internal::MemoryManager::get()->m_MemoryStats.totalFreed += size;
		bt::internal::MemoryManager::get()->m_MemoryStats.currentUsed -= size;
		BT_FREE(memory);
	}

	void Allocator::FreeDebug(void* block, const char* file, uint line) {
		free(block);
	}

}