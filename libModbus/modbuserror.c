#include "../libModbus/ModbusTcp.h"

void
modbusError (mbPacketParse_t *p_parseModbusTcpData, uint8_t*p_modbusTxBuf, unsigned char exceptioncode)
{
  p_modbusTxBuf[0] = p_parseModbusTcpData->transactionID.v[1];
  p_modbusTxBuf[1] = p_parseModbusTcpData->transactionID.v[0];
  p_modbusTxBuf[2] = p_parseModbusTcpData->protocolID.v[1];
  p_modbusTxBuf[3] = p_parseModbusTcpData->protocolID.v[0];
  p_modbusTxBuf[4] = 0X00;
  p_modbusTxBuf[5] = 0X03;
  p_modbusTxBuf[6] = p_parseModbusTcpData->unitID;
  p_modbusTxBuf[7] = p_parseModbusTcpData->functionCode;
  p_modbusTxBuf[8] = exceptioncode;

}
