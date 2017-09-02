#pragma once
#include<string>
#include<vector>

// FileSystem utilities provider - Interface
class FileSystem {
public:
	virtual ~FileSystem() {}
	
	using Path = std::string;

	// Function is supposed to list all files in directory (without subdirectories and theirs name)
	virtual std::vector<Path> listDirectory(const Path& path) = 0;
	// Function is supposed to list all files in given directory and all subdirectories recursively
	virtual std::vector<Path> listDirectoryRec(const Path& path) = 0;
};
