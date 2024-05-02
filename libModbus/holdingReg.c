
#include "ModbusTcp.h"
unsigned int a, b;


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
 */

//|   dff    |
//|          |
//  2 bytes

//parse->TransactionID.v[0] = *DataRegister;
//  parse->TransactionID.v[1] = *DataRegister++;



uint16_t readHoldingRegisters(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData)
{
 uint16_t length;
 
// if(p_parseModbusTcpData->numberofRegister.Val>(MaxSizeTcpTx-8))
//   {
//     modbusError ()
//   }
  p_modbusTxBuf[0] = p_parseModbusTcpData->transactionID.v[1];
  p_modbusTxBuf[1] = p_parseModbusTcpData->transactionID.v[0];

  p_modbusTxBuf[2] = p_parseModbusTcpData->protocolID.v[1];
  p_modbusTxBuf[3] = p_parseModbusTcpData->protocolID.v[0];

  p_modbusTxBuf[4] = 0X0;
 

  p_modbusTxBuf[6] = p_parseModbusTcpData->unitID;
  p_modbusTxBuf[7] = p_parseModbusTcpData->functionCode;
  p_modbusTxBuf[8] = p_parseModbusTcpData->numberofRegister.Val * 2;
  p_modbusTxBuf[5] =  p_modbusTxBuf[8]+ 0X03;





  for (a = 0; a < p_parseModbusTcpData->numberofRegister.Val; a++)
    {
      b = a * 2;

      p_modbusTxBuf[9 + b] = p_dataMemory[p_parseModbusTcpData->startAddress.Val + a] / 0x100;
      p_modbusTxBuf[10 + b] = p_dataMemory[p_parseModbusTcpData->startAddress.Val + a] % 0x100;
    }

  length = 0x9 + p_modbusTxBuf[8];
  return length;
}


