/*
 * AutoMacro : cope.h
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#ifndef COPE_H_
#define COPE_H_

#include <f32file.h>
#include <badesca.h>
#include "logger1.h"
#include "constants.h"
#include "crash_handler.h"

class CCopy : public CBase
	{
public:
	CCopy();
	static CCopy* NewL();
	virtual ~CCopy();
	virtual TInt Copy(const TDesC& aOld,const TDesC& aNew);
	virtual TInt ParseCopy(const TDesC& aString);
	virtual void ListMethods();
private:
	virtual void ConstructL();
	CDesC16Array* iMethods;
	TBuf<256> iName;
	};


#endif /* COPE_H_ */
