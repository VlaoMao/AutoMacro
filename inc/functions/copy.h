/*
 * AutoMacro : cope.h
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#ifndef COPE_H_
#define COPE_H_
#include <f32file.h>

#include "logger1.h"
#include "constants.h"
#include "crash_handler.h"

TInt Copy(const TDesC& aOld,const TDesC& aNew);
TInt ParseCopy(const TDesC& aString);

#endif /* COPE_H_ */
