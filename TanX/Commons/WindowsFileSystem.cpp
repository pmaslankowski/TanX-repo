#include<vector>
#include<string>
#include<stack>
#include<Windows.h>
#include "WindowsFileSystem.h"


std::vector<std::string> WindowsFileSystem::listDirectory(const std::string& path, bool rec) {
	std::vector<std::string> filenames;
	std::stack<std::string> stack;
	stack.push(path);

	WIN32_FIND_DATAA searchData;

	while (!stack.empty()) {
		auto filename = stack.top() + "\\*";
		auto currDir = stack.top();
		stack.pop();

		HANDLE handle = FindFirstFileA(filename.c_str(), &searchData);
		while (handle != INVALID_HANDLE_VALUE) {
			if (searchData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				std::string curr = searchData.cFileName;
				if (curr[0] != '.' && rec) // directory is hidden
					stack.push(currDir + "\\" + searchData.cFileName);
			}
			else {
				auto filepath = currDir + "\\" + searchData.cFileName;
				filenames.push_back(filepath);
			}

			if (!FindNextFileA(handle, &searchData))
				break;
		}

		if (handle != nullptr)
			FindClose(handle);
	}

	return filenames;
}
