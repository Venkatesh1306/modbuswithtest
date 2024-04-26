#include "testingdata.h"
/*QUERY FRAME:

| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Starting Address | Quantity of Registers | Byte Count | Data (2 bytes per register) |
|------------------------|---------------------|--------|-----------------|---------------|------------------|-----------------------|------------|-----------------------------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |     2 bytes      |       2 bytes         |   1 byte   |         n bytes            |


RESPONSE FRAME:

| Transaction Identifier | Protocol Identifier | Length | Unit Identifier | Function Code | Starting Address | Quantity of Registers |
|------------------------|---------------------|--------|-----------------|---------------|------------------|-----------------------|
|       2 bytes          |      2 bytes        |2 bytes |      1 byte     |     1 byte    |     2 bytes      |       2 bytes         |

 * Function Code - 16 (10 HEX)
 * DataRegister[25]={0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890};
 * INPUT FRAME = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x10, 0x00, 0x01, 0x00, 0x02, 0x04, 0x00, 0x0A, 0x01, 0x02}
 * 
 * After Processing the Query the DataRegister changes if no error is detected i.e to preset two registers starting at 01 to 0x0000A, 0x0102  
 * RESPONSE FRAME = {0x0, 0x1, 0x2, 0x3, 0x0, 0x12, 0x10, 0x10, 0x0, 0x1, 0x0, 0x2} - 12 bytes.
 * DATAREGISTER = {0x0000, 0x000A, 0x0102, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890 }

 * If error detected
 * RESPONSE FRAME = {0x0, 0x1, 0x2, 0x3, 0x0, 0x9, 0x10, 0x90, 0x3} - last byte refers to exception code
 * DATAREGISTER UNMODIFIED.

 */



WORD presetmultipleregisters(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse) {
    unsigned int limit, limit1, data1, data2, DATA, check;

    ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
    ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

    ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
    ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

    ModbusTcpTxBuf[4] = 0X0;

    // Output[5] = 0X3 + Output[8];
    ModbusTcpTxBuf[6] = parse->UnitID;

    ModbusTcpTxBuf[7] = parse->FunctionCode;



    for (limit = 0; limit < parse->NumberofRegister.v[0]; limit++) {
        //data1 = parse->ForceData[limit].v[0];
        //data2 = parse->ForceData[limit].v[1]*0x100;
        //DATA = data1 + data2;
        if ( parse->ForceData[limit].Val >= 65000) {

            parse->FunctionCode = parse->FunctionCode + 128;
            modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Value);
            limit = parse->NumberofRegister.v[0] + 1;
            ModbusTcpTxBuf[5] = 0X3;
            check = 1;
        } else {

            DataRegister[parse->StartAddress.Val + limit] = parse->ForceData[limit].v[0]+(parse->ForceData[limit].v[1]*0x100);


        }

        //limit1 = limit * 2;

        //DataRegister[parse->StartAddress.Val + limit1] = parse->ForceData.v[0 + limit];
    }
    if (check!= 1) {
        ModbusTcpTxBuf[8] = parse->StartAddress.v[1];
        ModbusTcpTxBuf[9] = parse->StartAddress.v[0];
        ModbusTcpTxBuf[10] = parse->NumberofRegister.v[1];
        ModbusTcpTxBuf[11] = parse->NumberofRegister.v[0];
        ModbusTcpTxBuf[5] = 0X06;
    }


    // DataRegister[parse->StartAddress.Val] = (parse->NumberofRegister.v[0] + parse->NumberofRegister.v[1]*0x100);

    return ModbusTcpTxBuf[5] + 0x06;
}
