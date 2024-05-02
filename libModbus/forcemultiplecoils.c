#include "ModbusTcp.h"

#define SET(x, y) x |= (1 << y)
#define READ(x, y) ((0u == (x & (1 << y))) ? 0u : 1u)
#define CLEAR(x, y) x &= ~(1 << y)

// coil address -> reg and bit ->

uint16_t forceMultipleCoils(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData)
{
    unsigned int NoOfBits, bit_count, Regbit, regTx, RegbitTx, reg;
    // unsigned int coil_byte_index,coil_byte_count, coil_byte_count,coil_byteValue,coil_bit_index,coil_register_index, coil_register_status,coil_data;
    unsigned int coil_data;
    p_modbusTxBuf[0] = p_parseModbusTcpData->transactionID.v[1];
    p_modbusTxBuf[1] = p_parseModbusTcpData->transactionID.v[0];

    p_modbusTxBuf[2] = p_parseModbusTcpData->protocolID.v[1];
    p_modbusTxBuf[3] = p_parseModbusTcpData->protocolID.v[0];

    p_modbusTxBuf[4] = 0X0;
    p_modbusTxBuf[5] = 0x06;

    p_modbusTxBuf[6] = p_parseModbusTcpData->unitID;
    p_modbusTxBuf[7] = p_parseModbusTcpData->functionCode;

    p_modbusTxBuf[8] = p_parseModbusTcpData->startAddress.v[1];
    p_modbusTxBuf[9] = p_parseModbusTcpData->startAddress.v[0];

    p_modbusTxBuf[10] = p_parseModbusTcpData->numberofRegister.v[1];
    p_modbusTxBuf[11] = p_parseModbusTcpData->numberofRegister.v[0];

    NoOfBits = p_parseModbusTcpData->numberofRegister.Val; // Quantity of coils

    for (bit_count = NoOfBits - 1; bit_count >= 0; bit_count--) // byte count
    {
        Regbit = (p_parseModbusTcpData->startAddress.Val + bit_count - 1) % 16; // 20 - 1 % 16 = 4th bit
        reg = (p_parseModbusTcpData->startAddress.Val + bit_count - 1) / 16;    // 20 - 1 /16 = 1st  reg

        RegbitTx = (bit_count) % 16; // 20 - 1 % 16 = 4th bit -- bit increment
        regTx = (bit_count) / 16;    // 20 - 1 /16 = 1st  reg -- register increment

        if (p_parseModbusTcpData->coilData[regTx] > 65000)
        {
            p_parseModbusTcpData->functionCode = p_parseModbusTcpData->functionCode + 0x80;
            modbusError(p_parseModbusTcpData, p_modbusTxBuf, Illegal_Data_Value);
            break;
        }
        else
        {
            coil_data = READ(p_parseModbusTcpData->coilData[regTx], RegbitTx);

            if (coil_data == 0x1)
            {
                SET(p_dataMemory[reg], Regbit);
            }
            else
            {
                CLEAR(p_dataMemory[reg], Regbit);
            }
            if (bit_count == 0)
            {
                break;
            }
        }
    }
    return 0x12;
}
