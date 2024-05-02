#include "../libModbus/ModbusTcp.h"
mbPacketParse_t p_parseModbusTcpData;
//WORD frameLength;

uint16_t
modbusTcpFrame (uint8_t *p_modbusRxBuf, uint16_t *p_dataMemory, uint8_t *p_modbusTxBuf,uint16_t modBusframeLength)
{


  modbusTcpParse (&p_parseModbusTcpData, p_modbusRxBuf);

  if (!(p_parseModbusTcpData.functionCode == ReadCoilStatus ||
        p_parseModbusTcpData.functionCode == ReadInputStatus ||
        p_parseModbusTcpData.functionCode == ReadHoldingRegister ||
        p_parseModbusTcpData.functionCode == ReadInputRegisters ||
        p_parseModbusTcpData.functionCode == ForceSingleCoil ||
        p_parseModbusTcpData.functionCode == PresetSingleRegister ||
        p_parseModbusTcpData.functionCode == ForceMultipleCoils ||
        p_parseModbusTcpData.functionCode == PresetMultipleRegisters
        ))
    {
      p_parseModbusTcpData.functionCode = p_parseModbusTcpData.functionCode + 0x80;
      modbusError (&p_parseModbusTcpData, p_modbusTxBuf, Illegal_Function_Code);
       modBusframeLength = 0x9;
    }
  else if(p_parseModbusTcpData.numberofRegister.Val>(MaxSizeTcpTx-8))
    {
      p_parseModbusTcpData.functionCode = p_parseModbusTcpData.functionCode + 0x80;
      modbusError (&p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Value );
      modBusframeLength = 0x9;
    }
  else if
    (p_parseModbusTcpData.functionCode == ReadInputStatus ||
     p_parseModbusTcpData.functionCode == ReadHoldingRegister ||
     p_parseModbusTcpData.functionCode == ReadInputRegisters ||
     p_parseModbusTcpData.functionCode == PresetMultipleRegisters)
    {
      if ((p_parseModbusTcpData.startAddress.Val > (int) (DataRegistersize)) ||
          ((p_parseModbusTcpData.startAddress.Val + p_parseModbusTcpData.numberofRegister.Val) > (int) (DataRegistersize)))
        {
          p_parseModbusTcpData.functionCode = p_parseModbusTcpData.functionCode + 0x80;
          modbusError (&p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Address);
          modBusframeLength = 0x9;
        }
    }
    else if (p_parseModbusTcpData.functionCode == ReadCoilStatus ||
           p_parseModbusTcpData.functionCode == ReadInputStatus ||
           p_parseModbusTcpData.functionCode == ForceMultipleCoils)
  {
      if ((p_parseModbusTcpData.startAddress.Val > (int) (DataRegister1size)) ||
          ((p_parseModbusTcpData.startAddress.Val + p_parseModbusTcpData.numberofRegister.Val) > (int) (DataRegister1size)))
    {
        p_parseModbusTcpData.functionCode = p_parseModbusTcpData.functionCode + 0x80;
          modbusError (&p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Address);
          modBusframeLength = 0x9;
    }
  }
  else if
    (p_parseModbusTcpData.functionCode == ForceSingleCoil)
    {
      if (p_parseModbusTcpData.startAddress.Val  > (int) (DataRegister1size))
        {
          
        p_parseModbusTcpData.functionCode = p_parseModbusTcpData.functionCode + 0x80;
          modbusError (&p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Address);
          modBusframeLength = 0x9;
        }
    }
  else if
    (p_parseModbusTcpData.functionCode == PresetSingleRegister)
    {
      if (p_parseModbusTcpData.startAddress.Val > (int) (DataRegistersize))
        {
          p_parseModbusTcpData.functionCode = p_parseModbusTcpData.functionCode + 0x80;
          modbusError (&p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Address);
          modBusframeLength = 0x9;
        }
    }


 

  if (p_parseModbusTcpData.functionCode == ReadHoldingRegister)
    {
      modBusframeLength = readHoldingRegisters(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
  if (p_parseModbusTcpData.functionCode == PresetSingleRegister)
    {
      modBusframeLength  = presetSingleRegister(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
  if (p_parseModbusTcpData.functionCode == PresetMultipleRegisters)
    {
      modBusframeLength = presetMultipleRegisters(p_modbusTxBuf,p_dataMemory, &p_parseModbusTcpData);
    }

    
    if (p_parseModbusTcpData.functionCode == ReadInputStatus)
    {
      modBusframeLength = readInputStatus(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
    if (p_parseModbusTcpData.functionCode == ReadCoilStatus)
    {
      modBusframeLength = readCoilStatus(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
     if (p_parseModbusTcpData.functionCode == ReadInputRegisters)
    {
      modBusframeLength = readInputReg(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
     if (p_parseModbusTcpData.functionCode == ForceMultipleCoils)
    {
      modBusframeLength = forceMultipleCoils(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
    if (p_parseModbusTcpData.functionCode == ForceSingleCoil)
    {
      modBusframeLength = forceSingleCoil(p_modbusTxBuf, p_dataMemory, &p_parseModbusTcpData);
    }
  return modBusframeLength;
}



