# Watchy-Screen-Basic

This is a port of the Watchy "basic" face to [Watchy-Screen](https://github.com/charles-haynes/Watchy-Screen). It's intended just as a minimal running example of using that library.

## Changes

* Watchy is no longer a class, so we don't need an instance.
* Watchy is a namespace, so we need to qualify with `Watchy::`
* Watchy requires a default Screen to be set before calling `init`
* The basic watchface has been split out into a `Screen` subclass called `TimeScreen`

## Files

 ```c++
 // TimeScreen.h

 #pragma once

#include "Screen.h"

class TimeScreen : public Screen {
 public:
  TimeScreen() : Screen("TimeScreen", GxEPD_WHITE){};
  virtual void show();  // display this screen
  virtual void menu();
};

extern TimeScreen timeScreen;
```

```c++
// TimeScreen.cpp

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
```

```c++
// main.cpp

#include "TimeScreen.h"
#include "Watchy.h"

void setup() {
  Serial.begin(921600);
  DEBUG("  %ld: setup %d\n", millis(), esp_sleep_get_wakeup_cause());

  Watchy::defaultScreen = &timeScreen;
  Watchy::init();
}

void loop() {}  // this should never run, Watchy deep sleeps after init();
```
