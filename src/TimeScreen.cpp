#include "TimeScreen.h"

#include "MenuScreen.h"
#include "Watchy.h"

TimeScreen timeScreen;

void TimeScreen::show() {
  tmElements_t currentTime;
  Watchy::RTC.read(currentTime);
  Watchy::display.setFont(&DSEG7_Classic_Bold_53);
  Watchy::display.setCursor(5, 53 + 60);
  Watchy::display.printf("%02d:%02d", currentTime.Hour, currentTime.Minute);
}

void TimeScreen::menu() { Watchy::setScreen(&menuScreen); }