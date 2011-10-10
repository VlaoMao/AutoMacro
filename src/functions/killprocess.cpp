/*
 * AutoMacro : killprocess.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "killprocess.h"


TInt KillProcess(const TDesC& aName)
	{
	TInt err = -1;
	TFindProcess processFinder(aName);
	TFullName result;
	RProcess processHandle;
	while(processFinder.Next(result) == KErrNone)
		{
		err = processHandle.Open(processFinder,EOwnerThread);
		processHandle.Kill(KErrNone);
		processHandle.Close();
		}

	__LOGSTR1("KillProcess return value: %d",err);

	return err;
	}
