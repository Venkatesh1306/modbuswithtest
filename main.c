/*
 * File:   main.c
 * Author: Vivek
 *
 * Created on 8 April, 2024, 11:03 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "D:\Version6\GenericTypeDefs_1.h"
#include "D:\Version6\Modbus1\testingdata.h"

WORD frame_function(BYTE *ModbusTcpRxBuf, WORD *DataRegister, parse1 *parse, BYTE *ModbusTcpTxBuf);
WORD testingfun(BYTE *ModbusTcpTxBuf, BYTE *op1, BYTE *ModbusTcpRxBuf, WORD *DataRegister);
WORD DataRegister[25] = {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890};
BYTE ModbusTcpRxBuf[25] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x10, 0x03, 0x00, 0x1B, 0x00, 0x02};
BYTE ModbusTcpTxBuf[25];
BYTE op1[25];
parse1 parse;

main()
{
   frame_function(&ModbusTcpRxBuf[0], &DataRegister[0], &parse, &ModbusTcpTxBuf[0]);
}
