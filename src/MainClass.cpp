/*
 * MainClass.cpp
 *
 *  Created on: 09.10.2011
 *      Author: vl
 */

#include "MainClass.h"

CWork* CWork::NewL()
	{
	__LOGSTR("CWork::NewL");
	CWork* self = new(ELeave) CWork();
	return self;
	}
CWork::CWork()
	{

	}
CWork::~CWork()
	{

	}
void CWork::Work(const TDesC& aConfigName)
	{
	RFs fs;
		__CPUSHC(fs);
		__CH__( fs.Connect() );
		if(BaflUtils::FileExists(fs,_L("E:\\macro.stop")) || BaflUtils::FileExists(fs,_L("F:\\macro.stop")))
			{
			User::Exit(KErrNone);
			}
		__CPOPD(&fs);
		__LOGSTR("Log file of AutoMacro...\nProgram starting...\n");
		TInt pos;
		SetPriority();
		CDesC16Array* arr;
		RFs aFs;
		RFile file;
		TFileText aTextFile;
		TInt found;
		TInt aScanCode;
		TBuf<256> aTempBuf;
		TBuf<256> aMacroName;
		TBuf<256> aMacroParameter;
		TLex lex;

		__CH__( aFs.Connect() );
		__LOGSTR("Open file session");
		__CPUSHC(aFs);
		__CHD__(file.Open(aFs,aConfigName,EFileShareAny|EFileRead|EFileStreamText),_L("OpenFile"));
		__LOGSTR("Open config file");
		__CPUSHC(file);
		aTextFile.Set(file);
		__LOGSTR("Set text file for config");

		arr = InitialiseFunctions();
		while(aTextFile.Read(aTempBuf) == KErrNone)
			{
			if(aTempBuf.Left(2) != KMultiComStart)
				{
					if(aTempBuf.Left(1) != KComment)
						{
						found = aTempBuf.Find(KParseParameters);
						__LOGSTR1("Parsered string: %S",&aTempBuf);
						__LOGSTR1("Found parsered symbol = %d",found);
						if(found != KErrNotFound)
							{
							aMacroName = aTempBuf.Left(found);

							aMacroName.UpperCase();// В верхний регистр

							__LOGSTR1("aMacroName: %S",&aMacroName);
							aMacroParameter = aTempBuf.Right(aTempBuf.Length()-(found+1));
							__LOGSTR1("aMacroParameter:%S",&aMacroParameter);
							arr->Find(aMacroName,pos);
							if(pos != arr->Count())
								{
								switch(pos){
									case EFuncCopy:
										{
										ParseCopy(aMacroParameter);
										/*RLibrary library;
										library.Load(_L("copy.dll"));
										TLibraryFunction entry = library.Lookup(1);
										CCopy* copy = (CCopy*) entry();
										_CPUSH(copy);
										copy->ParseCopy(aMacroParameter);
										_CPOPD(copy);
										library.Close();*/
										}
										break;
									case EFuncStart:
										if(aMacroParameter.Left(2) == _L("0x"))
											{
											aMacroParameter.Delete(0,2);
											lex.Assign(aMacroParameter);
											TUint KTestUid;
											lex.Val(KTestUid,EHex);
											TUid testUid;
											testUid.iUid=KTestUid;
											StartProcessUid(testUid);
											}
										else
											{
											StartProcessName(aMacroParameter);
											}
										break;
									case EFuncKill:
										KillProcess(aMacroParameter);
										break;
	#ifndef __ALLCAPS
									case EFuncWait:
										lex.Assign(aMacroParameter);
										TInt waiting;
										lex.Val(waiting);
										Wait(waiting);
										break;

									case EFuncKey:
										lex.Assign(aMacroParameter);
										lex.Val(aScanCode);
										SimulateKeyEvent(aScanCode);
										break;
									case EFuncLongKey:
										SimulateLongKey(aMacroParameter);
										break;
									case EFuncKeyNew:
										lex.Assign(aMacroParameter);
										lex.Val(aScanCode);
										SimulateRawEvent(aScanCode);
										break;

									case EFuncNote:
										ShowNoteL(aMacroParameter);
										break;
	#endif
									case EFuncDelF:
										FileDelete(aMacroParameter);
										break;
									case EFuncDelD:
										DirsDelete(aMacroParameter);
										break;
	#ifndef __ALLCAPS
									case EFuncOpen:
										OpenFile(aMacroParameter);
										break;
									case EFuncVibra:
										VibratE(aMacroParameter);
										break;
									case EFuncKeyLock:
										lex.Assign(aMacroParameter);
										TInt state;
										lex.Val(state);
										KeyLock(state);
										break;
									case EFuncSendKey:
										SendKey(aMacroParameter);
										break;
	#endif
									case EFuncRen:
										Rename(aMacroParameter);
										break;
									case EFuncMkdir:
										MkDir(aMacroParameter);
										break;
	#ifndef __ALLCAPS
									case EFuncKeyApa:
										SendKeyApa(aMacroParameter);
										break;
	#endif
									case EFuncInclude:
										{
										__LOGSTR("EFuncInclude");
										/*ConfLogName.Delete(0,ConfLogName.Length());
										ConfLogName.Append(_L("log_"));
										//TODO добавить вычисление имени
										TParse parser;
										parser.Set(aMacroParameter,NULL,NULL);
										ConfLogName.Append(parser.Name());
										ConfLogName.Append(_L(".txt"));
										__LOGSTR1("New conf log: %S",&ConfLogName);*/
										CWork* worker = CWork::NewL();
										__CPUSH(worker);
										worker->Work(aMacroParameter);
										__CPOPD(worker);
										//ConfLogName = _L("log_Main.txt");
										}
										break;
									default:
	__LOGSTR1("Undefined function: %S",&aMacroName);
										break;
								}
								}
							}
						}
				}else{
					while(aTempBuf.Right(2) != KMultiComEnd)
						{
						aTextFile.Read(aTempBuf);
						}
				}
				}
		__CPOPD(&file);

	__LOGSTR("Close file");

		__CPOPD(&aFs);
	__LOGSTR("Close fileserver session");

	}
