/*
 * AutoMacro : startprocess.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "constants.h"
#include "startprocess.h"

TInt StartProcessName(const TDesC& aFile)
	{
	TInt err = KErrNone;
	RProcess proc;
	TFullName name = proc.FullName();
	TBuf<256> buf = name.Left(name.Length()-4);

	__LOGSTR1("name.Left = %S",&buf);

	TBuf<256> digit = name.Right(4);

	__LOGSTR1("digit = %S",&digit);

	TLex lex;
	lex.Assign(digit);
	TInt num;
	lex.Val(num);
	if(num>8000)
	{
		buf.AppendNum(1111);
		TInt error = User::RenameProcess(buf);

		__LOGSTR1("User::RenameProcess return %d", error);
	}
	err = proc.Create(aFile,KNullDesC);

	__LOGSTR1("Start process by name return value: %d",err);

	proc.Resume();
	proc.Close();
	return err;
	}

TInt StartProcessUid(const TUid& aUid)
	{
	RApaLsSession apaLsSession;

	__LOGSTR1("UID: %d",aUid);

	__CH__(apaLsSession.Connect());
	__CPUSHC(apaLsSession);

	TApaAppInfo appInfo;
	TInt retVal=apaLsSession.GetAppInfo(appInfo,aUid);

	__LOGSTR1("Start process by UID return value: %d",retVal);

	if(retVal == KErrNone)
		{
		CApaCommandLine* cmdLine = CApaCommandLine::NewLC();
		cmdLine->SetExecutableNameL(appInfo.iFullName);
		//if(aParameter==KNullDesC)
		//{
			cmdLine->SetCommandL(EApaCommandRun);
		/*}
		else
		{
			cmdLine->SetCommandL(EApaCommandOpen);
			cmdLine->SetDocumentNameL(aParameter);
		}*/
		apaLsSession.StartApp(*cmdLine);

		__CPOPD(cmdLine);
		}
	else
		{

		}
	__CPOPD(&apaLsSession);
	return retVal;
	}
