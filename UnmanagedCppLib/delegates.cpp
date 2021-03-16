#include "pch.h"
#include "delegates.h"
#include "VaListener.h"

__declspec(dllexport) void __stdcall SetCallback(
	OnErrorCallback errorCallback, OnSuccessCallback successCallback)
{
	VaListener* test = new VaListener();

	// call
	test->onError(-1, "error");
	test->onSuccess(0, "success");

	// binding
	test->onError = errorCallback;
	test->onSuccess = successCallback;

	// call
	test->onError(-1, "error");
	test->onSuccess(0, "success");

	delete test;
}