/*
 * play.h
 *
 *  Created on: 05.11.2010
 *      Author: vl
 */

#ifndef _PLAY_H_
#define _PLAY_H_
#include <mdaaudiosampleplayer.h>
#include "constants.h"
#include "logger1.h"

class CmyPlay : public CBase, public MMdaAudioPlayerCallback
    {
public:
    ~CmyPlay();
    static CmyPlay* NewL();
    void Open(TDesC& aFIle);
    void  Stop();
    TInt MaxVolume();
    TBool iAllow;
    void SetVolume(TInt aVolume);
    TBool iNeedToSetVolume;
    TInt iNewVolume;
private:
    CMdaAudioPlayerUtility* iPlayer;
protected:
    CmyPlay();
    void ConstructL();
    virtual void MapcInitComplete(TInt aError, const TTimeIntervalMicroSeconds &aDuration);
    virtual void MapcPlayComplete(TInt aError);
private:
     enum TState{
     ENotReady,
     EReady,
     EPlaying
     };
     TState iState;
    };

inline void PlayFile(const TDesC& aParam)
    {
        __LOGSTR1("PlayFile :: Trying to play: %S",&aParam);
        TLex Lex;
        TInt err;
        TInt found;
        TBuf<256> fileName;
        TInt volume = 100;
        TBuf<256> Buf;
        found = aParam.Find(KParseParameters);
        if(found != KErrNotFound)
            {
                __LOGSTR("PlayFile :: KParseParameters found");
            Buf = aParam.Left(found);
            fileName.Copy(Buf);

            Buf = aParam.Right(aParam.Length()-(found+1));
            Lex.Assign(Buf);
            err = Lex.Val(volume);
            if(err != KErrNone)
                volume = 100;
            }
        else
            {
                __LOGSTR("PlayFile :: KParseParameters not found");
                fileName.Copy(aParam);
            }
        if(fileName.Length() > 0)
            {
                CmyPlay* player = CmyPlay::NewL();
                player->SetVolume(volume);
                player->Open(fileName);
            }else{
                __LOGSTR("PlayFile :: CRITICAL :: Filename length is 0");
            }
    }

#endif /* PLAY_H_ */
