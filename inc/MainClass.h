/*
 * MainClass.h
 *
 *  Created on: 09.10.2011
 *      Author: vl
 */

#ifndef MAINCLASS_H_
#define MAINCLASS_H_

#include <bautils.h>
#include "constants.h"

#include "note.h"
#include "openfile.h"
#include "keylock.h"
#include "vibra.h"
#include "simulatekey.h"
#include "wait.h"
#include "crash_handler.h"
#include "startprocess.h"
#include "copy.h"
//#include "../src/functions/copy/copy.h"
#include "killprocess.h"
#include "priority.h"
#include "dirfiles.h"
#include "array_functions.h"

class CWork : public CBase
	{
	CWork();
	~CWork();
public:
	static CWork* NewL();
	void Work(const TDesC& aConfigName);
	};
#endif /* MAINCLASS_H_ */
