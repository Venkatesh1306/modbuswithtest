#include"../libModbus/ModbusTcp.h"


uint16_t
presetSingleRegister(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData)
{
  uint16_t length;
  p_modbusTxBuf[0] = p_parseModbusTcpData->transactionID.v[1];
  p_modbusTxBuf[1] = p_parseModbusTcpData->transactionID.v[0];

  p_modbusTxBuf[2] = p_parseModbusTcpData->protocolID.v[1];
  p_modbusTxBuf[3] = p_parseModbusTcpData->protocolID.v[0];

  p_modbusTxBuf[4] = 0X0;
  p_modbusTxBuf[5] = p_parseModbusTcpData->length;

  p_modbusTxBuf[6] = p_parseModbusTcpData->unitID;
  p_modbusTxBuf[7] = p_parseModbusTcpData->functionCode;


  if (p_parseModbusTcpData->preset_Data.Val >= 65000)
    {
      p_parseModbusTcpData->functionCode = p_parseModbusTcpData->functionCode + 128;
      modbusError (p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Value);
      length = 0x9;
    }
  else
    {
      p_dataMemory[p_parseModbusTcpData->startAddress.Val] = (p_parseModbusTcpData->preset_Data.v[0] + p_parseModbusTcpData->preset_Data.v[1]*0x100);

      p_modbusTxBuf[8] = p_parseModbusTcpData->startAddress.v[1];
      p_modbusTxBuf[9] = p_parseModbusTcpData->startAddress.v[0];

      p_modbusTxBuf[10] = p_parseModbusTcpData->preset_Data.v[1]; //Preset Data Hi
      
      p_modbusTxBuf[11] = p_parseModbusTcpData->preset_Data.v[0]; //Preset Data Lo
      //DataRegister[parse->StartAddress.Val] = parse->NumberofRegister.Val;
      length = 0x6 + p_parseModbusTcpData->length;
    }
  return length;
}



