#include "testingdata.h"
unsigned int a, b;
unsigned int bytes;

// ModbusTcpRxBuf
// ModbusTcpTxBuf
/*
 Parametes
 * ModbusPacketParser
 * 
 * 1.DataRegister
 * 2.ModbusTcpRxBuf - QUERY Buffer
 * 3.ModbusTcpTxBuf - Response Buffer
 * 
 * Return
 * No of bytes to send
 * Bit Test
 * 
 * 0000 1000
 * 0001 0000
 * ---------
 * 0000 0000
 * 
 * 0001 1000
 * 0001 0000
 * ---------
 * 0001 0000
 * 
 

//|   dff    |
//|          |
//  2 bytes

//parse->TransactionID.v[0] = *DataRegister;
//  parse->TransactionID.v[1] = *DataRegister++;

QUERY FRAME:

| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Starting Address | Quantity of Registers |
|------------------------|---------------------|--------|-----------------|---------------|------------------|-----------------------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |     2 bytes      |       2 bytes         |

RESPONSE FRAME:

| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Byte Count | Data                |
|------------------------|---------------------|--------|-----------------|---------------|------------|---------------------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |   1 byte   | Variable (n bytes)  |

 * INPUT FRAME  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x03, 0x00, 0x6, 0x00, 0x03} - 12 bytes
 * DATAREGISTER = {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890}

 * The Query Message specifies the starting register and Quantity of registers to be read
 * This Query Request to read 3 register values from starting address 0x06 (0x06, 0x07, 0x08)
 * RESPONSE FRAME = {0x0, 0x1, 0x2, 0x3, 0x0, 0x9, 0x10, 0x3, 0x6, 0x0, 0x6, 0x0, 0x7, 0x0, 0x8} - 15 bytes(9 bytes + (2* no of Registers))
 * 
 * when error detected :
 * RESPONSE FRAME = {0x0, 0x1, 0x2, 0x3, 0x0, 0x3, 0x10, 0x91, 0x1} - 9 bytes
 */ 




WORD
ReadHoldingRegisters (BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse)
{
   
   
  ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
  ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

  ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
  ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

  ModbusTcpTxBuf[4] = 0X0;

  // Output[5] = 0X3 + Output[8];
  ModbusTcpTxBuf[6] = parse->UnitID;
  ModbusTcpTxBuf[7] = parse->FunctionCode;
  ModbusTcpTxBuf[8] = (char)(parse->NumberofRegister.Val * 2);
  ModbusTcpTxBuf[5] = ModbusTcpTxBuf[8]+ 0X03;

  for (a = 0; a < parse->NumberofRegister.Val; a++)
    {
      b = a * 2;

      ModbusTcpTxBuf[9 + b] = DataRegister[parse->StartAddress.Val + a] / 0x100;
      ModbusTcpTxBuf[10 + b] = DataRegister[parse->StartAddress.Val + a] % 0x100;
    }
  
  bytes = 0x9 + ModbusTcpTxBuf[8];
  return bytes;
  //return &ModbusTcpTxBuf;
}

