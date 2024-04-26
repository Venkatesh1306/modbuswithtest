#include "D:\Testing_Final\Modbus1\testingdata.h"

void modbuserror(parse1 *parse, BYTE ModbusTcpTxBuf[], unsigned char exceptioncode) {
    ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
    ModbusTcpTxBuf[1] = parse->TransactionID.v[0];
    ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
    ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];
    ModbusTcpTxBuf[4] = 0X00;
    ModbusTcpTxBuf[5] = 0X03;
    ModbusTcpTxBuf[6] = parse->UnitID;
    ModbusTcpTxBuf[7] = parse->FunctionCode;
    ModbusTcpTxBuf[8] = exceptioncode;

}
