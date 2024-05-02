#include "ModbusTcp.h"

uint16_t readInputReg(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData) {
    unsigned int bytes;
    unsigned int a, b;

    p_modbusTxBuf[0] = p_parseModbusTcpData->transactionID.v[1];
    p_modbusTxBuf[1] = p_parseModbusTcpData->transactionID.v[0];

    p_modbusTxBuf[2] = p_parseModbusTcpData->protocolID.v[1];
    p_modbusTxBuf[3] = p_parseModbusTcpData->protocolID.v[0];

    p_modbusTxBuf[4] = 0X0;

    // Output[5] = 0X3 + Output[8];
    p_modbusTxBuf[6] = p_parseModbusTcpData->unitID;
    p_modbusTxBuf[7] = p_parseModbusTcpData->functionCode;
    p_modbusTxBuf[8] = (char) (p_parseModbusTcpData->numberofRegister.Val * 2);
    p_modbusTxBuf[5] = p_modbusTxBuf[8] + 0X03;

    for (a = 0; a < p_parseModbusTcpData->numberofRegister.Val; a++) {
        b = a * 2;

        p_modbusTxBuf[9 + b] = p_dataMemory[p_parseModbusTcpData->startAddress.Val + a] / 0x100;
        p_modbusTxBuf[10 + b] = p_dataMemory[p_parseModbusTcpData->startAddress.Val + a] % 0x100;
    }

    bytes = 0x9 + p_modbusTxBuf[8];
    return bytes;
    // return &p_modbusTxBuf;
}
