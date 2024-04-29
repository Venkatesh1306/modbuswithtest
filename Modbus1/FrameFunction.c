#include "testingdata.h"
// void modbuserror(parse1 parse, BYTE *ModbusTcpTxBuf, unsigned char exceptioncode);
// BYTE ModbusTcpTxBuf[25];
// BYTE ModbusTcpRxBuf[25] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x03, 0x00, 0x02, 0x00, 0x02, 0x01, 0x03, 0x03};
// WORD ModbusTxLength;
// WORD DataRegister[26] = {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890};

unsigned char COIL[100] = {0};
WORD frame_function(BYTE *ModbusTcpRxBuf, WORD *DataRegister, WORD *InputRegister, unsigned char *COIL, parse1 *parse, BYTE *ModbusTcpTxBuf, unsigned int *ModbusTxLength)
{

    deserialize(parse, ModbusTcpRxBuf);

    if (!(parse->FunctionCode == ReadCoilStatus ||
          parse->FunctionCode == ReadInputStatus ||
          parse->FunctionCode == ReadHoldingRegister ||
          parse->FunctionCode == ReadInputRegisters ||
          parse->FunctionCode == ForceSingleCoil ||
          parse->FunctionCode == PresetSingleRegister ||
          parse->FunctionCode == ForceMultipleCoils ||
          parse->FunctionCode == PresetMultipleRegisters))
    {
        parse->FunctionCode = parse->FunctionCode + 0x80;
        modbuserror(parse, ModbusTcpTxBuf, Illegal_Function_Code);
        *ModbusTxLength = 0x9;
        //      modbuserror(&parsedes, &ModbusTcpTxBuf,exceptioncode);
        // modbuserror(&parsedes,&ModbusTcpTxBuf[0],Illegal_Function_Code);
    }
    else if ((parse->StartAddress.Val > ((int)(DataRegistersize)-1)) ||
             (((parse->StartAddress.Val - 1 + parse->NumberofRegister.Val) > (int)(DataRegistersize)) && parse->FunctionCode != PresetSingleRegister) && (parse->FunctionCode != 0x01))
    {
        parse->FunctionCode = parse->FunctionCode + 0x80;
        modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Address);
        *ModbusTxLength = 0x9;
    }

    //    else if(
    //            )

    if (parse->FunctionCode == ReadHoldingRegister)
    {
        *ModbusTxLength = ReadHoldingRegisters(ModbusTcpTxBuf, DataRegister, parse);
    }
    if (parse->FunctionCode == ReadCoilStatus)
    {
        *ModbusTxLength = readcoilstatus(ModbusTcpTxBuf, DataRegister, parse);
    }
    if (parse->FunctionCode == ForceSingleCoil)
    {
        *ModbusTxLength = forcesinglecoil(ModbusTcpTxBuf, COIL, parse);
    }
    if (parse->FunctionCode == PresetMultipleRegisters)
    {
        *ModbusTxLength = presetmultipleregisters(ModbusTcpTxBuf, DataRegister, parse);
    }
    if (parse->FunctionCode == PresetSingleRegister)
    {
        *ModbusTxLength = presetsingleregister(ModbusTcpTxBuf, DataRegister, parse);
    }
    if (parse->FunctionCode == ReadInputRegisters)
    {
        *ModbusTxLength = ReadInputReg(ModbusTcpTxBuf, InputRegister, parse);
    }
    if (parse->FunctionCode == ReadInputStatus)
    {
        *ModbusTxLength = readinputstatus(ModbusTcpTxBuf, InputRegister, parse);
    }
    if (parse->FunctionCode == ForceMultipleCoils)
    {
        *ModbusTxLength = forcemultiplecoils (ModbusTcpTxBuf, COIL , parse);
    }

    return *ModbusTxLength;
}
