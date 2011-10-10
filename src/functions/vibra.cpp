/*
 * AutoMacro : vibra.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */

#include "vibra.h"

void VibratE(const TDesC& aParam)
	{
	TLex Lex;
	TInt err;
	TInt found;
	TInt32 Duration;
	TInt32 Intensive;
	TBuf<256> Buf;
	CHWRMVibra* vibra = CHWRMVibra::NewLC();

	found = aParam.Find(KParseParameters);
	if(found != KErrNotFound)
		{
		Buf = aParam.Left(found);
		Lex.Assign(Buf);
		Lex.Val(Duration);

		Buf = aParam.Right(aParam.Length()-(found+1));
		Lex.Assign(Buf);
		err = Lex.Val(Intensive);
		if(err != KErrNone)
			Intensive = 50;
		}
	else
		{
		Lex.Assign(aParam);
		Lex.Val(Duration);
		Intensive = 50;
		}
	err = vibra->VibraStatus();
	if(err != CHWRMVibra::EVibraStatusNotAllowed)
		{
				vibra->StartVibraL(Duration,Intensive);
				User::After(Duration*1000);
		}
	__CPOPD(vibra);
	}
