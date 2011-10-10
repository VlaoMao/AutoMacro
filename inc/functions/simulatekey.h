/*
 * AutoMacro : simulatekey.h
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#ifndef SIMULATEKEY_H_
#define SIMULATEKEY_H_

#include <e32base.h>
#include <e32event.h>
#include <e32svr.h>
#include <w32std.h>
#include <apgtask.h>
#include "logger1.h"
#include "constants.h"
#include "crash_handler.h"

void SimulateKeyEvent(const TInt aScan);
void SimulateRawEvent(const TInt aScan);
void SimulateLongKey(const TDesC& aParam);
void SendKey(const TDesC& aParam);
void SendKeyApa(const TDesC& aParam);

#endif /* SIMULATEKEY_H_ */
