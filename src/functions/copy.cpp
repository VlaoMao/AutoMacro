/*
 * AutoMacro : copy.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "copy.h"

TInt Copy(const TDesC& aOld,const TDesC& aNew)
	{
	__LOGSTR("Copy");
	TInt err;
	RFs session;
	__CH__(session.Connect());
	__CPUSHC(session);
	CFileMan* manager = CFileMan::NewL(session);
	__CPUSH(manager);
	err = manager->Copy(aOld,aNew,CFileMan::ERecurse | CFileMan::EOverWrite);

	__LOGSTR1("Copy returned value: %d",err);
	__CPOPD(manager);
	__CPOPD(&session);
	return err;
	}
TInt ParseCopy(const TDesC& aString)
	{
	__LOGSTR("ParseCopy");
	TBuf<256> aOld;
	TBuf<256> aNew;
	TInt found;
	TInt err = -1;
	found = aString.Find(KParseCopyString);

	__LOGSTR1("found parsered statement: %d",found);

	if(found != KErrNotFound)
		{
	aOld = aString.Left(found);
	aNew = aString.Right(aString.Length()-(found+3));

	__LOGSTR1("aOld:%S",&aOld);
	__LOGSTR1("aNew:%S",&aNew);

	err = Copy(aOld,aNew);
		}
	return err;
	}
