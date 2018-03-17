#include "bt\bt.h"
#include "VFS.h"

#include "Memory.h"
#include "FileSystem.h"
#include "bt\utils\Log.h"

namespace bt {
	VFS* VFS::s_Instance = nullptr;

	void VFS::Init() {
		s_Instance = btnew VFS();
	}

	void VFS::Shutdown() {
		btdel s_Instance;
	}

	void VFS::Mount(const String& virtualPath, const String& physicalPath) {
		BT_ASSERT(s_Instance);
		m_MountPoints[virtualPath].push_back(physicalPath);
	}

	void VFS::UnMount(const String& path) {
		BT_ASSERT(s_Instance);
		m_MountPoints[path].clear();
	}

	bool VFS::ResolvePhysicalPath(const String& path, String& OutPhysicalPath) {
		if (path[0] != '/') {
			OutPhysicalPath = path;
			return FileSystem::FileExists(path);
		}

		std::vector<String> dirs = SplitString(path, '/');
		const String& virtualDir = dirs.front();

		if (m_MountPoints.find(virtualDir) == m_MountPoints.end() || m_MountPoints[virtualDir].empty())
			return false;

		String remainder = path.substr(virtualDir.size() + 1, path.size() - virtualDir.size());
		for (const String& physicalpath : m_MountPoints[virtualDir]) {
			String path = physicalpath + remainder;
			if (FileSystem::FileExists(path)) {
				OutPhysicalPath = path;
				return true;
			}
		}
		return false;
	}

	byte* VFS::ReadFile(const String& path) {
		BT_ASSERT(s_Instance);
		String physicalPath;
		return ResolvePhysicalPath(path, physicalPath) ? FileSystem::ReadFile(physicalPath) : nullptr;
	}

	String VFS::ReadTextFile(const String& path) {
		BT_ASSERT(s_Instance);
		String physicalPath;
		return ResolvePhysicalPath(path, physicalPath) ? FileSystem::ReadTextFile(physicalPath) : nullptr;
	}

	bool VFS::WriteFile(const String& path, byte* buffer) {
		BT_ASSERT(s_Instance);
		String physicalPath;
		return ResolvePhysicalPath(path, physicalPath) ? FileSystem::WriteFile(physicalPath, buffer) : nullptr;
	}

	bool VFS::WriteTextFile(const String& path, const String& text) {
		BT_ASSERT(s_Instance);
		String physicalPath;
		return ResolvePhysicalPath(path, physicalPath) ? FileSystem::WriteTextFile(physicalPath, text) : nullptr;
	}
}