#include "D:\Testing_Final\Modbus1\testingdata.h"
unsigned int c2, d2, l2, bytesrx;
unsigned char exceptioncode;

WORD deserialize(parse1 *parse, BYTE *ModbusTcpRxBuf) {
    //BYTE ModbusTcpTxBuf[0];

    parse->TransactionID.v[1] = ModbusTcpRxBuf[0];
    parse->TransactionID.v[0] = ModbusTcpRxBuf[1];
    parse->ProtocolID.v[1] = ModbusTcpRxBuf[2];
    parse->ProtocolID.v[0] = ModbusTcpRxBuf[3];
    parse->Length = ModbusTcpRxBuf[5];
    parse->UnitID = ModbusTcpRxBuf[6];
    parse->FunctionCode = ModbusTcpRxBuf[7];
    parse->StartAddress.v[1] = ModbusTcpRxBuf[8];
    parse->StartAddress.v[0] = ModbusTcpRxBuf[9];
    parse->NumberofRegister.v[1] = ModbusTcpRxBuf[10];
    parse->NumberofRegister.v[0] = ModbusTcpRxBuf[11];

    if(parse->FunctionCode == ForceMultipleCoils) //force multiple coils
    {
        parse->ByteCount = ModbusTcpRxBuf[12];
//        l2 = parse->ByteCount % 2;
//        if (l2 != 0) {
//            l2 = (parse->ByteCount / 2) + 1;
//        } else {
//            l2 = parse->ByteCount / 2;
//        }

        for (c2 = 0; c2 < parse->NumberofRegister.v[0]; c2++) {
            d2 = c2 * 2;

            parse->ForceData[c2].v[1] = ModbusTcpRxBuf[13 + d2];
            parse->ForceData[c2].v[0] = ModbusTcpRxBuf[14 + d2];
        }
    }


    //  if (!(parse->FunctionCode == ReadCoilStatus || 
    //            parse->FunctionCode == ReadInputStatus ||
    //            parse->FunctionCode == ReadHoldingRegister ||
    //            parse->FunctionCode == ReadInputRegisters ||
    //            parse->FunctionCode == ForceSingleCoil ||
    //            parse->FunctionCode == PresetSingleRegister ||
    //            parse->FunctionCode == ForceMultipleCoils ||
    //            parse->FunctionCode == PresetMultipleRegisters
    //            )) {
    //        parse->FunctionCode = parse->FunctionCode + 0x80;
    //        modbuserror(parse, ModbusTcpTxBuf, Illegal_Function_Code);
    //        //      modbuserror(&parsedes, &ModbusTcpTxBuf,exceptioncode);
    //        //modbuserror(&parsedes,&ModbusTcpTxBuf[0],Illegal_Function_Code);
    //        //return;
    //    }
    //else



    if(parse->FunctionCode == PresetMultipleRegisters){ //Preset multiple register

        parse->ByteCount = ModbusTcpRxBuf[12];
//        l2 = parse->ByteCount % 2;
//        
//        if (l2 != 0) {
//            l2 = (parse->ByteCount / 2) + 1;
//        } else {
//            l2 = parse->ByteCount / 2;
//        }

        for (c2 = 0; c2 < parse->NumberofRegister.v[0]; c2++) {
            d2 = c2 * 2;

            parse->ForceData[c2].v[1] = ModbusTcpRxBuf[13 + d2];
            parse->ForceData[c2].v[0] = ModbusTcpRxBuf[14 + d2];
        }


    }
    bytesrx = 0x6 + parse->Length;
    return bytesrx;
}

