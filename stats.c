#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

Stats compute_statistics(const float* numberset, int setlength) {
    Stats s;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;
    float tempMin = 0.0;
    float tempMax = 0.0;
    float sum = 0.0;
    int tempLen = 0;
    
    tempMin = numberset[0];
    tempMax = numberset[0];
    
    while(tempLen < setlength)
    {
        if( tempMax < numberset[tempLen])
        {
            tempMax = numberset[tempLen];
        }
        if( tempMin > numberset[tempLen])
        {
            tempMin = numberset[tempLen];
        }
        sum += numberset[tempLen];
        tempLen++;
    }
    s.min = tempMin;
    s.max = tempMax;
    s.average = sum / setlength;
    
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
{
    int tempCnt = 0;
    int alerterCount = sizeof(alerters)/sizeof(alerters[0]);
    
    if(computedStats.max > maxThreshold)
    {
        while(tempCnt < alerterCount)
        {
            if(alerters[tempCnt] != (void *)0)
            {
                alerters[tempCnt]();
            }
            tempCnt++;
        }
    }
}
        
