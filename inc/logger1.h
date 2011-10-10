/*
 * logger1.h
 *
 *  Created on: 28.02.2010
 *      Author: SQR
 */

#ifndef __FILELOGGER_H__
#define __FILELOGGER_H__
#ifdef __DEBUG

#include <e32std.h>
#include <flogger.h>

_LIT(KLogsDir,"automacro");
_LIT(KLogsFileName,"log.txt");
extern TBuf<256> ConfLogName;

#ifdef __DEBUG_MACROS__

#define __LOGSTR(S)\
		{\
			_LIT(KTmpStr,S);\
			RFileLogger::WriteFormat(KLogsDir(),\
			ConfLogName,EFileLoggingModeAppend,KTmpStr());\
		}
#define __LOGSTR1(S,P0)\
		{\
			_LIT(KTmpStr,S);\
			RFileLogger::WriteFormat(KLogsDir(),\
			ConfLogName,EFileLoggingModeAppend,TRefByValue<const TDesC>(KTmpStr()),P0);\
		}
#define __LOGSTR2(S,P0,P1)\
		{\
			_LIT(KTmpStr,S);\
			RFileLogger::WriteFormat(KLogsDir(),\
			ConfLogName,EFileLoggingModeAppend,TRefByValue<const TDesC>(KTmpStr()),P0,P1);\
		}
#define __LOGSTR3(S,P0,P1,P2)\
		{\
			_LIT(KTmpStr,S);\
			RFileLogger::WriteFormat(KLogsDir(),\
			/*KLogsFileName*/ConfLogName,EFileLoggingModeAppend,TRefByValue<const TDesC>(KTmpStr()),P0,P1,P2);\
		}
#define __LOGSTR4(S,P0,P1,P2,P3)\
		{\
			_LIT(KTmpStr,S);\
			RFileLogger::WriteFormat(KLogsDir(),\
			ConfLogName,EFileLoggingModeAppend,TRefByValue<const TDesC>(KTmpStr()),P0,P1,P2,P3);\
		}
#else

LOCAL_C void __LOGSTR(const TDesC& aArgument)
	{
	RFileLogger::Write(KLogsDir(),ConfLogName,EFileLoggingModeAppend,aArgument);
	}
LOCAL_C void __LOGSTR(const char* aArgument)
	{
	RFileLogger::Write(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArgument)));
	}
LOCAL_C void __LOGSTR1(const char* aArg1,const TDesC* aArg2)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),&aArg2);
	}
LOCAL_C void __LOGSTR1(const char* aArg1,const TInt aArg2)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2);
	}

LOCAL_C void __LOGSTR1(const char* aArg1,const TUid aArg2)
	{
	TInt32 uid(aArg2.iUid);
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),uid);
	}
LOCAL_C void __LOGSTR2(const char* aArg1,const TDesC* aArg2,const TDesC* aArg3)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3);
	}
LOCAL_C void __LOGSTR2(const char* aArg1,const TDesC* aArg2,const TInt aArg3)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3);
	}
LOCAL_C void __LOGSTR2(const char* aArg1,const TInt aArg2,const TInt aArg3)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3);
	}
LOCAL_C void __LOGSTR3(const char* aArg1,const TDesC* aArg2,const TDesC* aArg3,const TDesC* aArg4)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3,aArg4);
	}
LOCAL_C void __LOGSTR3(const char* aArg1,const TDesC* aArg2,const TDesC* aArg3,const TInt aArg4)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3,aArg4);
	}
LOCAL_C void __LOGSTR3(const char* aArg1,const TDesC* aArg2,const TInt aArg3,const TInt aArg4)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3,aArg4);
	}
LOCAL_C void __LOGSTR3(const char* aArg1,const char* aArg2,const TInt aArg3,const TInt aArg4)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3,aArg4);
	}
/*LOCAL_C void __LOGSTR3(const char* aArg1,const TInt aArg2,const TInt aArg3,const TInt aArg4)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3,aArg4);
	}*/
LOCAL_C void __LOGSTR3(const char* aArg1,const wchar_t* aArg2,const int aArg3,const TInt aArg4)
	{
	RFileLogger::WriteFormat(KLogsDir(),ConfLogName, EFileLoggingModeAppend, TPtrC8(reinterpret_cast<const TUint8*>(aArg1)),aArg2,aArg3,aArg4);
	}

#endif//__DEBUG_MACROS__
#endif//__DEBUG
#endif//__FILELOGGER_H__

#ifndef __DEBUG// Если релиз, объявляем только заглушки макросов
#define __LOGSTR(S){}
#define __LOGSTR1(S,P0){}
#define __LOGSTR2(S,P0,P1){}
#define __LOGSTR3(S,P0,P1,P2){}
#define __LOGSTR4(S,P0,P1,P2,P3){}
#endif

#define __CPUSH(S){CleanupStack::PushL(S);}
#define __CPUSHC(S){CleanupClosePushL(S);}
#define __CPOP(S){CleanupStack::Pop(S);}
#define __CPOPD(S){CleanupStack::PopAndDestroy(S);}
