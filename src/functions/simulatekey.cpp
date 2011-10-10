/*
 * AutoMacro : simulatekey.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#include "simulatekey.h"

void SimulateKeyEvent(const TInt aScan)
	{
	__LOGSTR("SimulateKeyEvent");
	RWsSession ws;
	TRawEvent RawEvent;
	__CH__( ws.Connect() );
	__CPUSHC(ws);
	RawEvent.Set(TRawEvent::EKeyDown,aScan);
	ws.SimulateRawEvent(RawEvent);
	User::After(100000);

	__LOGSTR("simulate 100000");

	RawEvent.Set(TRawEvent::EKeyUp,aScan);
	ws.SimulateRawEvent(RawEvent);

	__LOGSTR1("SimulateKeyEvent: %d",aScan);

	__CPOPD(&ws);
	}
void SimulateRawEvent(const TInt aScan)
	{
	__LOGSTR("SimulateRawEvent");
	TRawEvent lEventDown;
	TRawEvent lEventUp;
	lEventDown.Set(TRawEvent::EKeyDown, aScan);
	UserSvr::AddEvent(lEventDown);

	__LOGSTR("Added event down");

	User::After(10000);
	lEventUp.Set(TRawEvent::EKeyUp, aScan);
	UserSvr::AddEvent(lEventUp);

	__LOGSTR("Added event up");

	}
void SimulateLongKey(const TDesC& aParam)
{
	__LOGSTR("SimulateLongKey");
	TLex lex;
	TInt err;
	TInt key;
	TInt32 longest;
	TInt found;
	TBuf<256> buf;

	found = aParam.Find(KParseParameters);
	if(found != KErrNotFound)
	    {
	    buf = aParam.Left(found);
	    lex.Assign(buf);
	    lex.Val(key);

	    buf = aParam.Right(aParam.Length()-(found+1));
	    lex.Assign(buf);
	    err = lex.Val(longest);
	    if(err != KErrNone)
		longest = 2000;
	    }
	TRawEvent lEventDown;
	TRawEvent lEventUp;
	lEventDown.Set(TRawEvent::EKeyDown, key);
	UserSvr::AddEvent(lEventDown);

	__LOGSTR("Added event down");

	User::After(longest*1000);
	lEventUp.Set(TRawEvent::EKeyUp, key);
	UserSvr::AddEvent(lEventUp);

	__LOGSTR("Added event up");
}

void SendKey(const TDesC& aParam)
    {
	__LOGSTR("SendKey");
    TLex lex;
    TUid uid;
    TUint tempuid;
    TInt found;
    TInt key;
    TBuf<64> buf;
    TBuf<64> bufuid;
    RWsSession ws;
    found = aParam.Find(KParseParameters);

    __LOGSTR1("found: %d", found);

    if(found != KErrNotFound)
    	{
    	bufuid = aParam.Left(found);
    	buf = aParam.Right(aParam.Length()-(found+1));

    	__LOGSTR2("buf: %S, bufuid: %S",&buf,&bufuid);

    	lex.Assign(bufuid);
    	lex.Val(tempuid,EHex);
    	uid.iUid = tempuid;

    	lex.Assign(buf);
    	lex.Val(key);
	__CH__(ws.Connect());
	__CPUSHC(ws);

	TApaTaskList tlist(ws);
	TApaTask app(tlist.FindApp(uid));

	TInt id = app.WgId();

    __LOGSTR1("ID: %d", id);

	TWsEvent event;
	event.SetType(EEventKey);
	event.SetTimeNow();
	event.Key()->iCode = 0;
	event.Key()->iModifiers = 0;
	event.Key()->iScanCode = key;
	event.Key()->iRepeats = 0;
	ws.SendEventToWindowGroup(id,event);
	ws.Flush();

	User::After(10000);

	event.SetType(EEventKeyUp);
	event.SetTimeNow();
	event.Key()->iCode = 0;
	event.Key()->iModifiers = 0;
	event.Key()->iScanCode = key;
	event.Key()->iRepeats = 0;
	ws.SendEventToWindowGroup(id,event);

	ws.Flush();
	__CPOPD(&ws);
    	}
    }
void SendKeyApa(const TDesC& aParam)
    {
	__LOGSTR("SendKeyApa");
    TLex lex;
    TInt found;
    TUid uid;
    TUint tempuid;
    RWsSession ws;
    TBuf<256> buf;
    TBuf<256> bufuid;
    TInt key;

    found = aParam.Find(KParseParameters);
    if(found != KErrNotFound)
	{
	bufuid = aParam.Left(found);
	buf = aParam.Right(aParam.Length()-(found+1));
	__LOGSTR2("buf: %S, bufuid: %S",&buf,&bufuid);
	lex.Assign(bufuid);
	lex.Val(tempuid,EHex);
	uid.iUid = tempuid;

	lex.Assign(buf);
	lex.Val(key);

	__CH__(ws.Connect());
	__CPUSHC(ws);
	TApaTaskList tlist(ws);
	TApaTask app(tlist.FindApp(uid));
	if(app.Exists())
		{
		TKeyEvent keyevent;
		keyevent.iCode = 0;
		keyevent.iModifiers = 0;
		keyevent.iRepeats = 0;
		keyevent.iScanCode = key;
		app.SendKey(keyevent);
		}else{
			__LOGSTR("Task not found or not exist");
		}
	__CPOPD(&ws);
	}
    }
