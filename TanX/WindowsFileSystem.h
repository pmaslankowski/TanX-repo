#pragma once
#include<vector>
#include<string>
#include "FileSystem.h"
// Implementation of FileSystem for Windows 

class WindowsFileSystem : public FileSystem {
public:
	WindowsFileSystem() {}
	~WindowsFileSystem() {}

	std::vector<std::string> listDirectory(const std::string& path) { return listDirectory(path, false); }
	std::vector<std::string> listDirectoryRec(const std::string& path) { return listDirectory(path, true); }
private:
	// function lists files in given directory and does it recursively or not depending on rec flag
	std::vector<std::string> listDirectory(const std::string& path, bool rec);
};