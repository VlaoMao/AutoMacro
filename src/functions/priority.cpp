/*
 * AutoMacro : priority.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "priority.h"

void SetPriority()
	{
	RProcess processHandle;
	__LOGSTR("Set process priority");
	processHandle.SetPriority(EPriorityHigh);
	processHandle.Close();
	}
