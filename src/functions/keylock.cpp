/*
 * AutoMacro : keylock.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "keylock.h"

void KeyLock(const TInt aParameter)
{
	RAknKeyLock keylock;
	__CHD__(keylock.Connect(),_L("keylock connect"));
	__CPUSHC(keylock);

	if(aParameter == 1)
	{
		keylock.EnableWithoutNote();
	}else{
		if(aParameter == 0)
		{
			keylock.DisableWithoutNote();
		}
	}
	__CPOPD(&keylock);
}
