#include "D:\Testing_Final\Modbus1\testingdata.h"
//#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))
#define SET(x,y)  x |= (1 << y) 
#define READ(x,y)  ((0u == (x & (1<<y)))?0u:1u)
unsigned int NoOfBits, Regbit, reg, RegbitTx, regTx, byte_index, bit_count,wordOffset;
WORD Txtempbuf[100];
unsigned int byte_count, h, bit_index, coil_index, limit, coil_bit;
unsigned int TempReg;

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

WORD
readcoilstatus(BYTE *ModbusTcpTxBuf, WORD COIL[0], parse1 *parse) {

    // WORD dummy[100];

    ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
    ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

    ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
    ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

    ModbusTcpTxBuf[4] = 0X0;

    ModbusTcpTxBuf[6] = parse->UnitID;
    ModbusTcpTxBuf[7] = parse->FunctionCode;

    byte_count = (parse->NumberofRegister.Val / 0x8) + 1;
    ModbusTcpTxBuf[8] = byte_count;
    //byte_index = 9;
    ModbusTcpTxBuf[5] = 0x03 + byte_count;

    NoOfBits = parse->NumberofRegister.Val;


    for (bit_count = 0; bit_count < NoOfBits; bit_count++) // byte count 
    {
        Regbit = (parse->StartAddress.Val + bit_count) % 16; // 20 - 1 % 16 = 4th bit
        reg = (parse->StartAddress.Val + bit_count) / 16; // 20 - 1 /16 = 1st  reg
        RegbitTx = (bit_count) % 16; // 20 - 1 % 16 = 4th bit -- bit increment
        regTx = (bit_count) / 16; // 20 - 1 /16 = 1st  reg -- register increment
        
        
       // if(Regbit == 0 ){}
        // Txtempbuf[regTx] |= READ(COIL[reg], Regbit) << RegbitTx;
        coil_bit = READ(COIL[reg], Regbit);
        Txtempbuf[regTx] |=  coil_bit << RegbitTx;
        
        //if(parse->NumberofRegister == 0xFF)
        //{
        //    SET(COIL[reg], Regbit)
        //}
        //else
        //{
        //    //CLEAR(COIL[reg], Regbit)
        //}

    }

//    if (byte_count % 2 != 0) {
//        h = (byte_count / 2) + 1;
//    } else {
//        h = byte_count / 2;
//    }

    for (byte_index = 0; byte_index < (regTx+1); byte_index++) {
        //4times
        wordOffset = byte_index * 2;
        ModbusTcpTxBuf[9 + wordOffset] = (Txtempbuf[byte_index] % 0x100);
        ModbusTcpTxBuf[10 + wordOffset] = (Txtempbuf[byte_index] / 0x100);
    }

    limit = ModbusTcpTxBuf[5] + 0x6;
    return limit;
}

