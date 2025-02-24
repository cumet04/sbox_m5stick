#include "M5StickCPlus.h"
#include "BLEDevice.h"
#include <ArduinoJson.h>
#include <vector>

using namespace std;

using RawEntry = pair<array<uint8_t, 31>, array<uint8_t, ESP_BD_ADDR_LEN>>;

void setup()
{
    M5.begin();
    Serial.begin(115200);
    BLEDevice::init("");
}

class ScanCallback : public BLEAdvertisedDeviceCallbacks
{
    vector<RawEntry> deviceList;

    void onResult(BLEAdvertisedDevice ad)
    {
        string m = ad.getManufacturerData();

        bool isSwitchBot = (m[0] == 0x59 && m[1] == 0x00) || (m[0] == 0x69 && m[1] == 0x09);
        if (!isSwitchBot)
            return;

        uint8_t *pPayload = ad.getPayload();
        array<uint8_t, 31> payload = {0};
        copy(pPayload, pPayload + ad.getPayloadLength(), payload.begin());

        esp_bd_addr_t &pAddress = *ad.getAddress().getNative();
        array<uint8_t, ESP_BD_ADDR_LEN> address = {0};
        copy(pAddress, pAddress + ESP_BD_ADDR_LEN, address.begin());

        deviceList.push_back(make_pair(payload, address));
    }
};

void loop()
{
    BLEScan *pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new ScanCallback());
    pBLEScan->setActiveScan(true);
    pBLEScan->start(3);
    // Serial.println(ESP.getFreeHeap());
    delay(3000);
}
