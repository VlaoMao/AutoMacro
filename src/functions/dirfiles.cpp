/*
 * AutoMacro : dirfiles.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#include "dirfiles.h"
#include "constants.h"

TInt FileDelete(const TDesC& aName)
	{
	__LOGSTR("FileDelete");
	TInt err;
	RFs session;
	__CH__(session.Connect());
	__CPUSHC(session);
	CFileMan* manager = CFileMan::NewL(session);
	__CPUSH(manager);
	err = manager->Delete(aName,CFileMan::ERecurse);

	__LOGSTR2("Delete file %S returned value: %d",&aName,err);
	__CPOPD(manager);
	__CPOPD(&session);
	return err;
	}

TInt DirsDelete(const TDesC& aName)
	{
	__LOGSTR("DirsDelete");
	TInt err;
	RFs session;
	__CH__(session.Connect());
	__CPUSHC(session);
	CFileMan* manager = CFileMan::NewL(session);
	__CPUSH(manager);
	err = manager->RmDir(aName);

	__LOGSTR2("Delete dir %S returned value: %d",&aName,err);

	__CPOPD(manager);
	__CPOPD(&session);
	return err;
	}
TInt Rename(const TDesC& aParam)
    {
	__LOGSTR("Rename");
	TInt err = -1;
	TLex lex;
	TInt found;
	RFs session;
	TBuf<256> old_name;
	TBuf<256> new_name;
	found = aParam.Find(KParseParameters);
	if(found != KErrNotFound)
	    {

		__LOGSTR("Found old and new names");

	    old_name = aParam.Left(found);
	    new_name = aParam.Right(aParam.Length()-(found+1));
	    __CH__(session.Connect());
	    __CPUSHC(session);
	    CFileMan* manager = CFileMan::NewL(session);
	    __CPUSH(manager);
	    err = manager->Rename(old_name,new_name,CFileMan::EOverWrite);
	    __LOGSTR1("Rename returned value: %d",err);
	    __CPOPD(manager);
	    __CPOPD(&session);
	    }
	return err;
    }
TInt MkDir(const TDesC& aPath)
    {
	__LOGSTR("MkDir");
    RFs fs;
    TInt err = -1;
    __CH__(fs.Connect());
    __CPUSHC(fs);
    err = fs.MkDir(aPath);

	__LOGSTR1("MkDir returned value: %d",err);
	__CPOPD(&fs);

    return err;
    }
