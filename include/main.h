#ifndef RFID_UNLOCKER_MAIN_H
#define RFID_UNLOCKER_MAIN_H

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

#include <Keyboard.h>
byte readCard[4];
#include <secure.h>

#endif //RFID_UNLOCKER_MAIN_H
