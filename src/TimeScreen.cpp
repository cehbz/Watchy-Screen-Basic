#include "TimeScreen.h"

#include "MenuScreen.h"
#include "Watchy.h"

using namespace Watchy;

TimeScreen timeScreen;

void TimeScreen::show() {
  tmElements_t currentTime;
  RTC.read(currentTime);
  display.setFont(&DSEG7_Classic_Bold_53);
  display.setCursor(5, 53 + 60);
  display.printf("%02d:%02d", currentTime.Hour, currentTime.Minute);
}

void TimeScreen::menu() { setScreen(&menuScreen); }