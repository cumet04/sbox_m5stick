#include "M5StickCPlus.h"

void setup()
{
    M5.begin();
    M5.Lcd.setCursor(0, 0, 2);
    M5.Lcd.println("Serial sample.");
    Serial.begin(115200);
}

void loop()
{
    Serial.print("hoge");
    delay(1000);
}
