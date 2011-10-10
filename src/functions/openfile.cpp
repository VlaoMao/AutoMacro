/*
 * AutoMacro : openfile.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "openfile.h"

void OpenFile(const TDesC& aName)
	{
	TThreadId Id;
	TInt retVal;
	RApaLsSession apaLsSession;
	__CH__(apaLsSession.Connect());
	__CPUSHC(apaLsSession);
	retVal = apaLsSession.StartDocument(aName,Id);
	__LOGSTR2("Open file %S returned value: %d",&aName,retVal);
	__CPOPD(&apaLsSession);
	}
