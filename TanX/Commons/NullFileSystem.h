#pragma once
#include<string>
#include<vector>
#include "FileSystem.h"

// FileSystem which does nothing

class NullFileSystem : public FileSystem {
public:
	std::vector<std::string> listDirectory(const std::string &path) { return {}; }
	std::vector<std::string> listDirectoryRec(const std::string &path) { return {}; }
};
