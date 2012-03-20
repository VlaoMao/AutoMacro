/*
 * AutoMacro : wait.cpp
 *
 *  Created on: 17.01.2011
 *  Author: vl
 */
#include "wait.h"

void WaitLong(TInt aMilliSeconds)
    {
        TInt count = 0;// Полные циклы по 35 минут
        TInt diff = 0;// Остаток
        while(true)
            {
                diff = aMilliSeconds - KMaximalTime;
                if(diff < KMaximalTime)
                    break;
                ++count;//Считаем только максимальные сроки
            }
        __LOGSTR2("Full counts: %d, diff: %d",count,diff);
        for(TInt i = 0; i <= count; ++i)
            {
                User::After(KMaximalTime);//Максимальные сроки ожидания
            }
        User::After(diff);// плюс остаток
    }

void Wait(TInt aMilliSeconds)
	{
        if(aMilliSeconds <= KMaximalTime)
            {
                //Сложный таймер не нужен
                User::After(aMilliSeconds*1000);
            }else{
                //Нужен составной таймер
                WaitLong(aMilliSeconds);
            }

	}
