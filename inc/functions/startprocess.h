/*
 * AutoMacro : startprocess.h
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#ifndef STARTPROCESS_H_
#define STARTPROCESS_H_

#include <apgtask.h>
#include <apgcli.h>
#include <apacmdln.h>
#include "logger1.h"
#include "crash_handler.h"

TInt StartProcessName(const TDesC& aFile);
TInt StartProcessUid(const TUid& aUid);

#endif /* STARTPROCESS_H_ */
