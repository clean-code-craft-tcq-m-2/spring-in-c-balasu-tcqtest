#include "alerter.h"
#inlcude "stats.h"

void emailAlerter(void)
{
  emailAlertCallCount++;
}

void ledAlerter(void)
{
  ledAlertCallCount++;
}
