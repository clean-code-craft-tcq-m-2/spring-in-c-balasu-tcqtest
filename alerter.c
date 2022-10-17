#include "alerter.h"
#include "stats.h"

void emailAlerter(void)
{
  emailAlertCallCount++;
}

void ledAlerter(void)
{
  ledAlertCallCount++;
}
