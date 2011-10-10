/*
 * AutoMacro : wait.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#include "wait.h"

void Wait(TInt aMilliSeconds)
	{
	User::After(aMilliSeconds*1000);
	}
