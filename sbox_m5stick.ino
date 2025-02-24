#include <WiFi.h>
#include "M5StickCPlus.h"
#include "secrets.h"

void setup()
{

    M5.begin();
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        M5.Lcd.print(".");
    }
    M5.Lcd.println("WiFi connected");
    M5.Lcd.println("IP address: ");
    M5.Lcd.println(WiFi.localIP());
    // Serial.begin(115200);
}

void loop()
{
    delay(3000);
}
