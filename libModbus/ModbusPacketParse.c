#include "../libModbus/ModbusTcp.h"
unsigned int c2, d2, bytesrx;
unsigned char exceptioncode;

uint16_t
modbusTcpParse(mbPacketParse_t *p_parseModbusTcpData, uint8_t *p_modbusRxBuf)
{
  // BYTE *ModbusTxBuf;

  p_parseModbusTcpData->transactionID.v[1] = p_modbusRxBuf[0];
  p_parseModbusTcpData->transactionID.v[0] = p_modbusRxBuf[1];

  p_parseModbusTcpData->protocolID.v[1] = p_modbusRxBuf[2];
  p_parseModbusTcpData->protocolID.v[0] = p_modbusRxBuf[3];

  p_parseModbusTcpData->length = p_modbusRxBuf[5];

  p_parseModbusTcpData->unitID = p_modbusRxBuf[6];

  p_parseModbusTcpData->functionCode = p_modbusRxBuf[7];

  p_parseModbusTcpData->startAddress.v[1] = p_modbusRxBuf[8];
  p_parseModbusTcpData->startAddress.v[0] = p_modbusRxBuf[9];

  if (p_parseModbusTcpData->functionCode == PresetSingleRegister)
  {
    p_parseModbusTcpData->preset_Data.v[1] = p_modbusRxBuf[10];
    p_parseModbusTcpData->preset_Data.v[0] = p_modbusRxBuf[11];
  }

  else if (p_parseModbusTcpData->functionCode == PresetMultipleRegisters)
  {

    p_parseModbusTcpData->numberofRegister.v[1] = p_modbusRxBuf[10];
    p_parseModbusTcpData->numberofRegister.v[0] = p_modbusRxBuf[11];
    p_parseModbusTcpData->byteCount = p_modbusRxBuf[12];

    for (c2 = 0; c2 < p_parseModbusTcpData->numberofRegister.Val; c2++)
    {
      d2 = c2 * 2;

      p_parseModbusTcpData->data[c2].v[1] = p_modbusRxBuf[13 + d2];
      p_parseModbusTcpData->data[c2].v[0] = p_modbusRxBuf[14 + d2];
    }
  }

  else if (p_parseModbusTcpData->functionCode == ForceSingleCoil)
  {
    p_parseModbusTcpData->forceData[0].v[1] = p_modbusRxBuf[10];
    p_parseModbusTcpData->forceData[0].v[0] = p_modbusRxBuf[11];
  }

  else if (p_parseModbusTcpData->functionCode == ForceMultipleCoils) // force multiple coils
  {
    p_parseModbusTcpData->byteCount = p_modbusRxBuf[12];
    for (c2 = 0; c2 < p_parseModbusTcpData->byteCount / 2; c2++)
    {

      p_parseModbusTcpData->coilData[c2] = (p_modbusRxBuf[14 + c2 * 2] << 8) | p_modbusRxBuf[13 + c2 * 2];
      // printf("%04x \n",parse->Coil_data[c2]);
    }
  }

  else
  {
    p_parseModbusTcpData->numberofRegister.v[1] = p_modbusRxBuf[10];
    p_parseModbusTcpData->numberofRegister.v[0] = p_modbusRxBuf[11];
  }

  //    bytesrx = 0x6 + parseModbusTcpData->Length;
  return 0;
}
