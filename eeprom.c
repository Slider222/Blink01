


#include "EEPROM.h"

void EEPROMWriteByte(unsigned char addr, unsigned char dt){
    uint8_t status;
    while (WR){};
    EEADR = addr;
    EEDATA = dt;
    WREN = 1;
    status = GIE;
    GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    WR = 1;
    GIE = status;
    WREN = 0;
}

unsigned char EEPROMReadByte(unsigned char addr){
    while(RD || WR){};
    EEADR = addr;
    RD = 1;
    return EEDATA;
}

void EEPROMWriteWord(unsigned char addr, unsigned int ucData){
    EEPROMWriteByte(addr, (unsigned char)ucData);
    unsigned char dt = ucData >> 8;
    EEPROMWriteByte(addr + 1, dt);
}

unsigned int EEPROMReadWord(unsigned char addr){
    unsigned int dt = EEPROMReadByte(addr + 1) * 256;
    dt += EEPROMReadByte(addr);
    return dt;
}