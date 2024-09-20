
/*
    Free to use, coded by juve <3
*/

#pragma once
#include <utility/include.h>

class services
{
public:
	bool stopservice(const std::string& serviceName);
	void stop();
	bool startservice(const std::string& serviceName);
	void start();
};
