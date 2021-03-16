#include "pch.h"
#include "VaListener.h"
#include <iostream>

VaListener::VaListener()
{
	this->onError = DefaultErrorCallback();
	this->onSuccess = DefaultSuccessCallback();
}

OnErrorCallback VaListener::DefaultErrorCallback()
{
	return [](int code, const char* msg)
	{
		std::cout << code << " : " << msg << std::endl;
	};
}

OnSuccessCallback VaListener::DefaultSuccessCallback()
{
	return [](int code, const char* msg)
	{
		std::cout << code << " : " << msg << std::endl;
	};
}
