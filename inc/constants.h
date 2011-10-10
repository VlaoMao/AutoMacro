/*
 * AutoMacro : constants.h
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#ifndef CONSTANTS_ORIGINAL_H_
#define CONSTANTS_ORIGINAL_H_

#include <e32base.h>

_LIT(KConfig,"C:\\System\\AutoMacro\\MacroMain.cfg");
_LIT(KParseCopyString," - ");
_LIT(KParseParameters," ");
_LIT(KComment,"#");
_LIT(KAltComment,"# *");
_LIT(KMultiComStart,"/*");
_LIT(KMultiComEnd,"*/");

_LIT(KCopy,"COPY");
_LIT(KStart,"START");
_LIT(KKill,"KILL");
_LIT(KWait,"WAIT");
_LIT(KKey,"KEY");
_LIT(KLongKey,"LONGKEY");
_LIT(KKeyNew,"KEYNEW");
_LIT(KNote,"NOTE");
_LIT(KDelFiles,"DELF");
_LIT(KDelDirs,"DELD");
_LIT(KOpen,"OPEN");
_LIT(KVibra,"VIBRA");
_LIT(KKeyLock,"KEYLOCK");
_LIT(KSendKey,"SENDKEY");
_LIT(KRename,"REN");
_LIT(KMkDir,"MKDIR");
_LIT(KKeyApa,"KEYAPA");
_LIT(KInclude,"INCLUDE");

enum functions{
    EFuncCopy,
    EFuncStart,
    EFuncKill,
    EFuncWait,
    EFuncKey,
    EFuncLongKey,
    EFuncKeyNew,
    EFuncNote,
    EFuncDelF,
    EFuncDelD,
    EFuncOpen,
    EFuncVibra,
    EFuncKeyLock,
    EFuncSendKey,
    EFuncRen,
    EFuncMkdir,
    EFuncKeyApa,
    EFuncInclude
};

#endif /* CONSTANTS_H_ */
