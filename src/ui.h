#pragma once

#include <Arduino.h>

#ifdef U8G2
#include <U8g2_for_Adafruit_GFX.h>
U8G2_FOR_ADAFRUIT_GFX u8g2;
#endif

#define USE_HSPI_FOR_EPD
#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>
#define GxEPD2_DISPLAY_CLASS GxEPD2_BW
#define GxEPD2_DRIVER_CLASS GxEPD2_420
#ifndef EPD_CS
#define EPD_CS SS
#endif
#define MAX_DISPLAY_BUFFER_SIZE 65536ul // e.g.
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))

#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>

class ClockUI {
public:
  ClockUI(GxEPD2_DISPLAY_CLASS<GxEPD2_DRIVER_CLASS, MAX_HEIGHT(GxEPD2_DRIVER_CLASS)> *display) : _display(display) { };

  void begin();

  void test();

  void show_wifi_symbol();
  void clear_wifi_symbol();

  void show_network_info(IPAddress local_ip, const char* name, const char* ssid);
  void clear_network_info();

  void setup_time();
  void show_time(struct tm* timeinfo);
  void clear_time();

  void show_indoor(float temperature, float humidity);
  void show_outdoor(float temperature, float humidity);

private:
  GxEPD2_DISPLAY_CLASS<GxEPD2_DRIVER_CLASS, MAX_HEIGHT(GxEPD2_DRIVER_CLASS)>* _display;
};

