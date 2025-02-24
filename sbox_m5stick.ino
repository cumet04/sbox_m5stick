#include "M5StickCPlus.h"

void setup()
{
    M5.begin();
    Serial.begin(115200);
}

void loop()
{
    Serial.println(ESP.getFreeHeap());
    delay(3000);
}
