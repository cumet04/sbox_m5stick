#include "M5StickCPlus.h"
#include "BLEDevice.h"
#include <ArduinoJson.h>
#include <vector>
#include "BLEAdvertisedDevice.h"

void setup()
{
    M5.begin();
    Serial.begin(115200);
    BLEDevice::init("");
}

std::vector<std::pair<std::array<uint8_t, 31>, std::array<uint8_t, ESP_BD_ADDR_LEN>>> deviceList;

class ScanCallbacks : public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice ad)
    {
        std::string m = ad.getManufacturerData();

        bool isSwitchBot = (m[0] == 0x59 && m[1] == 0x00) || (m[0] == 0x69 && m[1] == 0x09);
        if (!isSwitchBot)
            return;

        uint8_t *pPayload = ad.getPayload();
        std::array<uint8_t, 31> payload = {0};
        std::copy(pPayload, pPayload + ad.getPayloadLength(), payload.begin());

        esp_bd_addr_t &pAddress = *ad.getAddress().getNative();
        std::array<uint8_t, ESP_BD_ADDR_LEN> address = {0};
        std::copy(pAddress, pAddress + ESP_BD_ADDR_LEN, address.begin());

        deviceList.push_back(std::make_pair(payload, address));
        // Serial.println(ad.getAddress().toString().c_str());
    }
};

void loop()
{
    BLEScan *pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new ScanCallbacks());
    pBLEScan->setActiveScan(true);
    // deviceList.clear();
    // Serial.println(ESP.getFreeHeap());
    BLEScanResults foundDevices = pBLEScan->start(30);
    Serial.print(deviceList.size());
    Serial.print(", ");
    Serial.println(ESP.getFreeHeap());
    delay(3000);
}
