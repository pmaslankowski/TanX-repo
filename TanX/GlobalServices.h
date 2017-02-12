#pragma once
#include<memory>
#include "FileSystem.h"
#include "WindowsFileSystem.h"
// Locator for all global services such as audio, filesystem itp.

class GlobalServices {
public:
	static FileSystem* getFileSystem() { return &filesystem_; }
private:
	static WindowsFileSystem filesystem_;
};