/*
 * AutoMacro : deletedirfiles.h
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#ifndef DIRFILES_H_
#define DIRFILES_H_
#include <e32base.h>
#include <f32file.h>
#include "logger1.h"
#include "crash_handler.h"

TInt FileDelete(const TDesC& aName);
TInt DirsDelete(const TDesC& aName);
TInt Rename(const TDesC& aParam);
TInt MkDir(const TDesC& aPath);


#endif /* DELETEDIRFILES_H_ */
