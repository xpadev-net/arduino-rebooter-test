/*
 * std_arduino.hpp
 * ArduinoをC/C++で実装するに当たって必須のヘッダファイル
 */
#ifndef STD_ARDUINO_HPP
#define STD_ARDUINO_HPP

#include "Arduino.h"    // ここでArduino.hをインクルードする
#include <SPI.h>
#include <Ethernet.h>
#include "lib/http_parser.hpp"
#include "lib/router.hpp"
 
// Arduinoで必須な関数をここで宣言しておく。
void setup();
void loop();

#endif //STD_ARDUINO_HPP
