/*
 * AutoMacro : copy.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "copy.h"

EXPORT_C CCopy* NewCCopy()
	{
	return CCopy::NewL();
	}
CCopy* CCopy::NewL()
	{
	CCopy* self = new (ELeave) CCopy();
	self->ConstructL();
	return self;
	}
void CCopy::ConstructL()
	{
	iMethods = new (ELeave) CDesC16ArrayFlat(10);
	iMethods->AppendL(_L("Test Copy module methods text"));
	iName.Copy(_L("C:\\copy_dll.txt"));
	}
CCopy::CCopy()
	{

	}
CCopy::~CCopy()
	{
	iMethods->Reset();
	delete iMethods;
	}
TInt CCopy::Copy(const TDesC& aOld,const TDesC& aNew)
	{
	TInt err;
	RFs session;
	User::LeaveIfError(session.Connect());
	CFileMan* manager = CFileMan::NewL(session);
	err = manager->Copy(aOld,aNew,CFileMan::ERecurse | CFileMan::EOverWrite);

	__LOGSTR1("Copy returned value: %d",err);

	session.Close();
	return err;
	}
TInt CCopy::ParseCopy(const TDesC& aString)
	{
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
void CCopy::ListMethods()
	{
	RFs fs;
	RFile file;
	TFileText text;
	__CH__(fs.Connect());
	__CPUSHC(fs);
	__CH__(file.Create(fs,iName,EFileWrite));
	__CPUSHC(file);
	text.Set(file);
	for(TInt i = 0; i < iMethods->Count(); ++i)
		{
		text.Write(iMethods->operator [](i));
		}
	__CPOPD(&file);
	__CPOPD(&fs);
	}
