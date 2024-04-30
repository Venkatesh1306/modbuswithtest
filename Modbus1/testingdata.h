//unsigned int c, d, e;

//unsigned int pack[25];
//unsigned int y;
//extern int z1, l, value;
//l=value;
#include "D:\Project_mp\testfinal\GenericTypeDefs_1.h"
#include<stdio.h>


#define ReadCoilStatus 01
#define ReadInputStatus 02
#define	ReadHoldingRegister 03
#define ReadInputRegisters 04
#define ForceSingleCoil 05
#define PresetSingleRegister 06
#define ForceMultipleCoils 15
#define PresetMultipleRegisters 16

#define DataRegistersize 0x25
#define DataRegister1size 0x50

#define Illegal_Function_Code   0x01u       
#define Illegal_Data_Address    0x02u
#define Illegal_Data_Value      0x03u

typedef struct 
{
  WORD_VAL TransactionID;
  WORD_VAL ProtocolID;
  WORD Length;
  BYTE UnitID;
  BYTE FunctionCode;
  WORD_VAL StartAddress;
  WORD_VAL NumberofRegister;
  WORD Coil_data[25];
  WORD ByteCount;
  WORD_VAL ForceData[];
  
} parse1;

typedef struct 
{
    BYTE Val;
    BYTE Addr;
  
} WORD_VAL1, WORD_BITS1;



void modbuserror(parse1 *parse, BYTE ModbusTcpTxBuf[], unsigned char exceptioncode);
WORD deserialize (parse1 *parse,BYTE *ModbusTcpRxBuf);

WORD ReadHoldingRegisters(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse);
WORD forcesinglecoil(BYTE *ModbusTcpTxBuf, unsigned short int *COIL, parse1 *parse);
WORD presetmultipleregisters(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse);
WORD ReadInputReg(BYTE *ModbusTcpTxBuf, WORD *InputRegister, parse1 *parse);
WORD readinputstatus(BYTE *ModbusTcpTxBuf, WORD *InputRegister, parse1 *parse);
WORD presetsingleregister(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse);
WORD presetmultipleregisters(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse);
WORD readcoilstatus(BYTE *ModbusTcpTxBuf, WORD *DataRegister, parse1 *parse);
WORD forcemultiplecoils (BYTE *ModbusTcpTxBuf, unsigned short int  *COIL , parse1 *parse);
//parse1 parse;
//BYTE ModbusTcpTxBuf[25];
//BYTE ModbusTcpRxBuf[25] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x03, 0x00, 0x02, 0x00, 0x02, 0x01, 0x03, 0x03};
//WORD ModbusTxLength;
//WORD DataRegister[26] = {0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0009, 0x0008, 0x0007, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0025, 0x0035, 0x0036, 0x9957, 0x7890}; 

