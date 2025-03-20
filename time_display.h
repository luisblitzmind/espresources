#pragma once
#include "esphome.h"

class TimeDisplay : public Component {
 public:
  void setup() override {
    // Nothing to do here
  }
  
  void loop() override {
    // Nothing to do here
  }
  
  void display_time(display::Display &display, float x, float y, TextAlign align, 
                   const char* format, Color color, const char* font) {
    auto time = id(homeassistant_time).now();
    if (!time.is_valid()) {
      return;
    }
    
    char buffer[64];
    time.strftime(buffer, sizeof(buffer), format);
    
    display.printf(x, y, font, color, align, "%s", buffer);
  }
};
