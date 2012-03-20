/*
 * AutoMacro : wait.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#ifndef WAIT_CPP_
#define WAIT_CPP_

#include <e32base.h>
#include "logger1.h"

const TInt KMaximalTime = 2147483; // Максимальное время для TTimeIntervalMicroSeconds32, около 35 минут

void Wait(TInt aMilliSeconds);

#endif /* WAIT_CPP_ */
