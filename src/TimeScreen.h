#pragma once

#include "Screen.h"

class TimeScreen : public Screen {
 public:
  TimeScreen() : Screen("TimeScreen", GxEPD_WHITE){};
  virtual void show();  // display this screen
  virtual void menu();
};

extern TimeScreen timeScreen;