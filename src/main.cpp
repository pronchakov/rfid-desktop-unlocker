#include "main.h"


void setup() {
    SPI.begin();
    mfrc522.PCD_Init();
    mfrc522.PCD_DumpVersionToSerial();
    Keyboard.begin();
}

void enterpassword() {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_DELETE);
    delay(200);
    Keyboard.releaseAll();
    delay(200);

    Keyboard.print(password);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
}

bool arrayEquals(byte expected[], byte actual[]) {
    for (int i = 0; i < 4; i++) {
        if (expected[i] != actual[i]) {
            return false;
        }
    }
    return true;
}

void loop() {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    for ( uint8_t i = 0; i < 4; i++) {
        readCard[i] = mfrc522.uid.uidByte[i];
    }
    mfrc522.PICC_HaltA();

    if (arrayEquals(successCard, readCard)) {
        enterpassword();
    }

}


