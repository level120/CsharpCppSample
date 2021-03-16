#pragma once

typedef void(__stdcall* OnErrorCallback)(int errorCode, const char* errorText);
typedef void(__stdcall* OnSuccessCallback)(int errorCode, const char* keyword);

extern "C"
{
	__declspec(dllexport) void __stdcall SetCallback(OnErrorCallback errorCallback, OnSuccessCallback successCallback);
};