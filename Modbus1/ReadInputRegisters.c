#include "testingdata.h"

unsigned int a, b;
unsigned int bytes;

WORD ReadInputReg(BYTE *ModbusTcpTxBuf, WORD *InputRegister, parse1 *parse)
{

  ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
  ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

  ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
  ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

  ModbusTcpTxBuf[4] = 0X0;

  // Output[5] = 0X3 + Output[8];
  ModbusTcpTxBuf[6] = parse->UnitID;
  ModbusTcpTxBuf[7] = parse->FunctionCode;
  ModbusTcpTxBuf[8] = (char)(parse->NumberofRegister.Val * 2);
  ModbusTcpTxBuf[5] = ModbusTcpTxBuf[8] + 0X03;

  for (a = 0; a < parse->NumberofRegister.Val; a++)
  {
    b = a * 2;

    ModbusTcpTxBuf[9 + b] = InputRegister[parse->StartAddress.Val + a] / 0x100;
    ModbusTcpTxBuf[10 + b] = InputRegister[parse->StartAddress.Val + a] % 0x100;
  }

  bytes = 0x9 + ModbusTcpTxBuf[8];
  return bytes;
  // return &ModbusTcpTxBuf;
}
