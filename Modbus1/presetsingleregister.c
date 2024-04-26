#include "D:\Testing_Final\Modbus1\testingdata.h"

/*QUERY FRAME:
| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Address | Value |
|------------------------|---------------------|--------|-----------------|---------------|---------|-------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |  2 bytes| 2 bytes|

RESPONSE FRAME:
| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Address | Value |
|------------------------|---------------------|--------|-----------------|---------------|---------|-------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |  2 bytes| 2 bytes|
 * 
 * 
 * Function Code - 06
 * DataRegister[25]={0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890};
 * INPUT FRAME = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x06, 0x00, 0x01, 0x00, 0x03}
 *
 * Preset Register 01 to 0x0003
 * RESPONSE FRAME = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x06, 0x00, 0x01, 0x00, 0x03}
 * DATAREGISTER [] ={0x0000, 0x0003, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890}
 * 
 *When Error detected
 * RESPONSE FRAME = {0x0, 0x1, 0x2, 0x3, 0x0, 0x3, 0x10, 0x86, 0x3} - 9 bytes
 * DATAREGISTER UNMODIFIED.
 * 
 * 
 */

WORD presetsingleregister(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse) {
    unsigned int length, data1, data2, DATA;

    ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
    ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

    ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
    ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

    ModbusTcpTxBuf[4] = 0X0;
    ModbusTcpTxBuf[5] = parse->Length;
    // Output[5] = 0X3 + Output[8];
    ModbusTcpTxBuf[6] = parse->UnitID;
    ModbusTcpTxBuf[7] = parse->FunctionCode;


    //data1 = parse->NumberofRegister.v[0];
    //data2 = parse->NumberofRegister.v[1]*0x100;
    //DATA = data1 + data2;
    if (parse->NumberofRegister.Val >= 65000) {
        parse->FunctionCode = parse->FunctionCode + 128 ;
        modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Value);
        length = 0x9;
    } else {  
    DataRegister[parse->StartAddress.Val] = (parse->NumberofRegister.v[0] + parse->NumberofRegister.v[1]*0x100);

    ModbusTcpTxBuf[8] = parse->StartAddress.v[1];
    ModbusTcpTxBuf[9] = parse->StartAddress.v[0];

    ModbusTcpTxBuf[10] = parse->NumberofRegister.v[1]; //Preset Data Hi
    ModbusTcpTxBuf[11] = parse->NumberofRegister.v[0]; //Preset Data Lo
    //DataRegister[parse->StartAddress.Val] = parse->NumberofRegister.Val;
    length = 0x6 + parse->Length;
    }
    return length;
    
}
