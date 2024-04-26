#include "D:\Testing_Final\Modbus1\testingdata.h"
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))
#define SET(byte,nbit) ((byte) |= (1 << (nbit)))
unsigned int e, byte_count, h, bit_index, register_index, byte_index, register_status;
unsigned char byteValue;

WORD
readcoilstatus (BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse)
{

  ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
  ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

  ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
  ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

  ModbusTcpTxBuf[4] = 0X0;
  ModbusTcpTxBuf[5] = parse->Length;
  // Output[5] = 0X3 + Output[8];
  ModbusTcpTxBuf[6] = parse->UnitID;
  ModbusTcpTxBuf[7] = parse->FunctionCode;

  e = parse->NumberofRegister.Val/8 + 1;
  ModbusTcpTxBuf[8] = e;
  parse->ForceData[0].Val = 0;
for (int i = parse->StartAddress.Val; i < (parse->NumberofRegister.Val / 16) + parse->StartAddress.Val; i++) {
    for (int j = 15; j >= 0; j--) {
        if (bitcheck(DataRegister[i], j)) {
            SET(parse->ForceData[i - parse->StartAddress.Val].Val, j);
        }
    }
}

if ((parse->NumberofRegister.Val % 16 != 0)) {
    for (int j = (parse->NumberofRegister.Val % 16) - 1; j >= 0; j--) {
        if (bitcheck(DataRegister[parse->NumberofRegister.Val / 16 + parse->StartAddress.Val ], j)) {
            SET(parse->ForceData[parse->NumberofRegister.Val / 16].Val, j);
        }
    }
}

  for(int i = 0; i < e/2 +1 ;i++){
      ModbusTcpTxBuf[i*2 +9] = parse->ForceData[i].byte.HB;
      ModbusTcpTxBuf[i*2 +10] = parse->ForceData[i].byte.LB;       
  }

  return 0x9 + ModbusTcpTxBuf[8];
//  return &ModbusTcpTxBuf;

}
