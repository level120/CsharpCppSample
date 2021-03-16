#include "pch.h"
#include "VaListener.h"
#include <iostream>

VaListener::VaListener()
{
	this->onError = DefaultCallback();
	this->onSuccess = DefaultCallback();
}

OnErrorCallback VaListener::DefaultCallback()
{
	return [](int code, const char* msg)
	{
		std::cout << code << " : " << msg << std::endl;
	};
}