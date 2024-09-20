
/*
    Free to use, coded by juve <3
*/

#pragma once
#include <utility/include.h>

class regedit
{
public:
	bool clearkey(HKEY hKeyRoot, const std::string& subKey);
	bool regdelete(const std::string& subKey);
};