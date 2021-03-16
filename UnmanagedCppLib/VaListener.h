#pragma once

#include "delegates.h"

public class VaListener
{
public:
	VaListener();

	OnErrorCallback onError;
	OnSuccessCallback onSuccess;

	static OnErrorCallback DefaultCallback();
};
