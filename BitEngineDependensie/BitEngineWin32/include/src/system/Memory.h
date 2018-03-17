#pragma once

#include "Allocator.h"

#define btnew	new(__FILE__, __LINE__)
#define btdel	delete

#pragma warning(diable : 4595)

inline void* operator new(size_t size) {
	return bt::Allocator::Allocate(size);
}

inline void* operator new(size_t size, const char* file, uint line) {
	return bt::Allocator::AllocateDebug(size, file, line);
}

inline void* operator new[](size_t size) {
	return bt::Allocator::Allocate(size);
}

inline void* operator new[](size_t size, const char* file, uint line) {
	return bt::Allocator::AllocateDebug(size, file, line);
}

inline void operator delete(void* block) {
	bt::Allocator::Free(block);
}

inline void operator delete(void* block, const char* file, uint line) {
	bt::Allocator::FreeDebug(block, file, line);
}

inline void operator delete[](void* block) {
	bt::Allocator::Free(block);
}

inline void operator delete[](void* block, const char* file, uint line) {
	bt::Allocator::FreeDebug(block, file, line);
}

#pragma warning(default : 4595)