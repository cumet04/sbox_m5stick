#include "M5StickCPlus.h"

void setup()
{
    M5.begin();
    M5.Lcd.println("hoge");
}

void loop() { M5.update(); }
