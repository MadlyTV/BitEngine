#pragma once

#include "bt\bt.h"
#include "bt\String.h"

namespace bt {

	class BT_API VFS {
	private:
		static VFS* s_Instance;
	private:
		std::unordered_map<String, std::vector<String>> m_MountPoints;
	public:
		void Mount(const String& virtualPath, const String& physicalPath);
		void UnMount(const String& path);
		bool ResolvePhysicalPath(const String& path, String& OutPhysicalPath);

		byte* ReadFile(const String& path);
		String ReadTextFile(const String& path);

		bool WriteFile(const String& path, byte* buffer);
		bool WriteTextFile(const String& path, const String& text);
	public:
		static void Init();
		static void Shutdown();

		inline static VFS* Get() { return s_Instance; }
	};
}