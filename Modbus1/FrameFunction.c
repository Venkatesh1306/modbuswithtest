#include "testingdata.h"


WORD frame_function(BYTE *ModbusTcpRxBuf, WORD *DataRegister, WORD *InputRegister, unsigned short int *COIL, parse1 *parse, BYTE *ModbusTcpTxBuf, unsigned int *ModbusTxLength)
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
  }
  else if (parse->FunctionCode == ReadHoldingRegister ||
           parse->FunctionCode == ReadInputRegisters ||
           parse->FunctionCode == PresetMultipleRegisters)
  {
    if ((parse->StartAddress.Val > (int)(DataRegistersize)) ||
        ((parse->StartAddress.Val + parse->NumberofRegister.Val) > (int)(DataRegistersize)))
    {
      parse->FunctionCode = parse->FunctionCode + 0x80;
      modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Address);
      *ModbusTxLength = 0x9;
    }
  }
  else if (parse->FunctionCode == ReadCoilStatus ||
           parse->FunctionCode == ReadInputStatus ||
           parse->FunctionCode == ForceMultipleCoils)
  {
    if ((parse->StartAddress.Val > (int)(DataRegister1size)) ||
        ((parse->StartAddress.Val + parse->NumberofRegister.Val) > (int)(DataRegister1size)))
    {
      parse->FunctionCode = parse->FunctionCode + 0x80;
      modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Address);
      *ModbusTxLength = 0x9;
    }
  }
  else if (parse->FunctionCode == ForceSingleCoil)
  {
    if (parse->StartAddress.Val > (int)(DataRegister1size))
    {
      parse->FunctionCode = parse->FunctionCode + 0x80;
      modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Address);
      *ModbusTxLength = 0x9;
    }
  }
  else if (parse->FunctionCode == PresetSingleRegister)
  {
    if (parse->StartAddress.Val > (int)(DataRegistersize))
    {
      parse->FunctionCode = parse->FunctionCode + 0x80;
      modbuserror(parse, ModbusTcpTxBuf, Illegal_Data_Address);
      *ModbusTxLength = 0x9;
    }
  }

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
    *ModbusTxLength = forcemultiplecoils(ModbusTcpTxBuf, COIL, parse);
  }
   return *ModbusTxLength;
}
