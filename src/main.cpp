#include "Screen.h"
#include "TimeScreen.h"
#include "Watchy.h"  //include the Watchy library

using namespace Watchy;

void setup() {
  Serial.begin(921600);
  DEBUG("  %ld: setup %d\n", millis(), esp_sleep_get_wakeup_cause());
  defaultScreen = &timeScreen;

  Watchy::init();  // call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}