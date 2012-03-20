/*
 * array_functions.cpp
 *
 *  Created on: 16.03.2011
 *      Author: vl
 */
#include <e32base.h>
#include "array_functions.h"

CDesC16Array* InitialiseFunctions()
    {
    CDesC16Array* functions = new(ELeave) CDesC16ArrayFlat(10);
    functions->AppendL(KCopy);
    functions->AppendL(KStart);
    functions->AppendL(KKill);
    functions->AppendL(KWait);
    functions->AppendL(KKey);
    functions->AppendL(KLongKey);
    functions->AppendL(KKeyNew);
    functions->AppendL(KNote);
    functions->AppendL(KDelFiles);
    functions->AppendL(KDelDirs);
    functions->AppendL(KOpen);
    functions->AppendL(KVibra);
    functions->AppendL(KKeyLock);
    functions->AppendL(KSendKey);
    functions->AppendL(KRename);
    functions->AppendL(KMkDir);
    functions->AppendL(KKeyApa);
    functions->AppendL(KInclude);
    functions->AppendL(KPlay);
    return functions;
    }

