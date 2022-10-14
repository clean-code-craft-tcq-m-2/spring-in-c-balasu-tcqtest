typedef struct
{
  float min;
  float max;
  float average;
}Stats;

Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], int alertCount, Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
