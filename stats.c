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
    
    while(tempLen < setlength)
    {
        if( numberset[tempLen]  > tempMax)
        {
            tempMax = numberset[tempLen];
        }
        else if( numberset[tempLen] < tempMin)
        {
            tempMin = numberset[tempLen];
        }
        else
        {
            // Do nothing
        }
        sum += numberset[tempLen];
        tempLen++;
    }
    s.min = tempMin;
    s.max = tempMax;
    s.average = sum / setlength;
    
    return s;
}

// void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
// {
//     if(computedStats.max > maxThreshold)
//     {
        
//     }
// }
        
