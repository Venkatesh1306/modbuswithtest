#include "testingdata.h"
#define SET(x, y) x |= (1 << y)
#define READ(x, y) ((0u == (x & (1 << y))) ? 0u : 1u)
#define CLEAR(x, y) x &= ~(1 << y)

/* Force Single Coil - Function Code - 05
 *  The query message specifies the coil reference to be forced
 * A value of FF 00 hex requests the coil to be ON.
 * A value of 00 00 requests it to be OFF.
 *  All other values are illegal and will not affect the coil.
 *
 * QUERY FRAME:
| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Coil Address |   Force Data Value     |
|------------------------|---------------------|--------|-----------------|---------------|--------------|------------------------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |    2 bytes   |           2 bytes      |

RESPONSE FRAME:
| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Coil Address |     Force Data Value   |
|------------------------|---------------------|--------|-----------------|---------------|--------------|------------------------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |    2 bytes   |         2 bytes        |
 *
 * INPUT FRAME    = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x05, 0x00, 0xAC, 0xFF, 0x00}
 * RESPONSE FRAME = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x05, 0x00, 0xAC, 0xFF, 0x00}
 */

WORD forcesinglecoil(BYTE *ModbusTcpTxBuf, unsigned short int *COIL, parse1 *parse)
{
    unsigned int length, Regbit, reg;

    ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
    ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

    ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
    ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

    ModbusTcpTxBuf[4] = 0X0;
    ModbusTcpTxBuf[5] = parse->Length;
    // Output[5] = 0X3 + Output[8];
    ModbusTcpTxBuf[6] = parse->UnitID;
    ModbusTcpTxBuf[7] = parse->FunctionCode;

    ModbusTcpTxBuf[8] = parse->StartAddress.v[1]; // coil address Hi
    ModbusTcpTxBuf[9] = parse->StartAddress.v[0]; // coil address Lo

    ModbusTcpTxBuf[10] = parse->ForceData[0].v[1]; // Force data Hi (FF/00)
    ModbusTcpTxBuf[11] = parse->ForceData[0].v[0]; // Force data Lo (00)

    Regbit = (parse->StartAddress.Val - 1) % 16; // 20 - 1 % 16 = 4th bit
    reg = (parse->StartAddress.Val - 1) / 16;    // 20 - 1 /16 = 1st  reg

    if ((parse->ForceData[0].Val == 0xff00) || (parse->ForceData[0].Val == 0x0000))
    {
        if (parse->ForceData[0].Val == 0xFF00)
        {
            SET(COIL[reg], Regbit);
        }
        else
        {
            CLEAR(COIL[reg], Regbit);
        }
    }
    else
    {
        parse->FunctionCode = parse->FunctionCode + 0x80;
        modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Value);
    }
    //  COIL.Addr = parse->StartAddress.v[0];
    //  COIL.Val = parse->NumberofRegister.v[1];
   
    length = 0x6 + ModbusTcpTxBuf[5];
    return length;
}
