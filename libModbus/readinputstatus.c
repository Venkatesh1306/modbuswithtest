#include "ModbusTcp.h"
//#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))
#define SET(x,y)  x |= (1 << y) 
#define READ(x,y)  ((0u == (x & (1<<y)))?0u:1u)


//unsigned char byteValue;

/* Basic bit manipulation macros
   No one should ever have to rewrite these

//Set bit y (0-indexed) of x to '1' by generating a a mask with a '1' in the proper bit location and ORing x with the mask.

#define SET(x,y) x |= (1 << y)

//Set bit y (0-indexed) of x to '0' by generating a mask with a '0' in the y position and 1's elsewhere then ANDing the mask with x.

#define CLEAR(x,y) x &= ~(1<< y)

//Return '1' if the bit value at position y within x is '1' and '0' if it's 0 by ANDing x with a bit mask where the bit in y's position is '1' and '0' elsewhere and comparing it to all 0's.  Returns '1' in least significant bit position if the value of the bit is '1', '0' if it was '0'.

#define READ(x,y) ((0u == (x & (1<<y)))?0u:1u)

//Toggle bit y (0-index) of x to the inverse: '0' becomes '1', '1' becomes '0' by XORing x with a bitmask where the bit in position y is '1' and all others are '0'.

#define TOGGLE(x,y) (x ^= (1<<y))

 */
unsigned int NoOfBits, Regbit, reg, RegbitTx, regTx, byte_index, bit_count, wordOffset;
uint16_t Txtempbuf1[100];
unsigned int byte_count, limit, coil_bit;
uint16_t
readInputStatus(uint8_t *p_modbusTxBuf, uint16_t * p_dataMemory, mbPacketParse_t *p_parseModbusTcpData) {


    //unsigned int TempReg;
    // uint16_t dummy[100];

    p_modbusTxBuf[0] = p_parseModbusTcpData->transactionID.v[1];
    p_modbusTxBuf[1] = p_parseModbusTcpData->transactionID.v[0];

    p_modbusTxBuf[2] = p_parseModbusTcpData->protocolID.v[1];
    p_modbusTxBuf[3] = p_parseModbusTcpData->protocolID.v[0];

    p_modbusTxBuf[4] = 0X0;

    p_modbusTxBuf[6] = p_parseModbusTcpData->unitID;
    p_modbusTxBuf[7] = p_parseModbusTcpData->functionCode;

    byte_count = (p_parseModbusTcpData->numberofRegister.Val / 0x8) + 1;
    p_modbusTxBuf[8] = byte_count;
    //byte_index = 9;
    p_modbusTxBuf[5] = 0x03 + byte_count;

    NoOfBits = p_parseModbusTcpData->numberofRegister.Val;


    for (bit_count = 0; bit_count < NoOfBits; bit_count++) // byte count 
    {
        Regbit = (p_parseModbusTcpData->startAddress.Val + bit_count - 1) % 16; // 20 - 1 % 16 = 4th bit
        reg = (p_parseModbusTcpData->startAddress.Val + bit_count - 1) / 16; // 20 - 1 /16 = 1st  reg
        RegbitTx = (bit_count) % 16; // 20 - 1 % 16 = 4th bit -- bit increment
        regTx = (bit_count) / 16; // 20 - 1 /16 = 1st  reg -- register increment


        coil_bit = READ(p_dataMemory[reg], Regbit);
        Txtempbuf1[regTx] |= coil_bit << RegbitTx;


    }

    for (byte_index = 0; byte_index < (regTx + 1); byte_index++) {
        //4times
        wordOffset = byte_index * 2;
        p_modbusTxBuf[9 + wordOffset] = (Txtempbuf1[byte_index] % 0x100);
        p_modbusTxBuf[10 + wordOffset] = (Txtempbuf1[byte_index] / 0x100);
    }

    limit = p_modbusTxBuf[5] + 0x6;
    return limit;
}

