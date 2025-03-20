#pragma once.
#include "esphome.h"

void display_time(esphome::display::Display &display, float x, float y, 
                 esphome::display::TextAlign align, const char* format, 
                 esphome::Color color, const char* font) {
  auto time = id(homeassistant_time).now();
  if (!time.is_valid()) {
    return;
  }
  
  char buffer[64];
  time.strftime(buffer, sizeof(buffer), format);
  
  display.printf(x, y, font, color, align, "%s", buffer);
}
