
/*
    Free to use, coded by juve <3
*/

#pragma once

#include <utility/include.h>

class file
{
public:
	void createfolder(const string& folderpath);
	void copyfolder(const string& sourcepath, const string& destPath);
	void copyfile(const string& file, const string& destPath);
	void deletefile(const string& sourcePath);
	void cleanfolder(const string& folderPath);
};
