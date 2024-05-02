//#include"../GenericTypeDefs_1.h"
#include "D:\Project_mp\testfinal\modhead.h"
#include<stdio.h>

#define ReadCoilStatus 01
#define ReadInputStatus 02
#define	ReadHoldingRegister 03
#define ReadInputRegisters 04
#define ForceSingleCoil 05
#define PresetSingleRegister 06
#define ForceMultipleCoils 15
#define PresetMultipleRegisters 16

#define DataRegistersize 0x20
#define DataRegister1size 0x50

#define MaxSizeTcpTx 100

#define Illegal_Function_Code   0x01u       
#define Illegal_Data_Address    0x02u
#define Illegal_Data_Value      0x03u

typedef struct {
    uint16_t_VAL transactionID;
    uint16_t_VAL protocolID;
    uint16_t length;
    uint8_t unitID;
    uint8_t functionCode;
    uint16_t coilData[25];
    uint16_t_VAL startAddress;
    uint16_t_VAL st_addr;
    uint16_t_VAL numberofRegister;
    uint16_t_VAL num_reg;
    uint16_t byteCount;
    uint16_t_VAL forceData[25];
    uint16_t_VAL preset_Data;
    uint16_t_VAL data[125];

} mbPacketParse_t;

typedef struct {
    uint8_t Val;
    uint8_t Addr;

} WORD_VAL1, WORD_BITS1;
//extern uint16_t *length;
uint16_t modbusTcpFrame(uint8_t *p_modbusRxBuf, uint16_t *p_dataMemory, uint8_t *p_modbusTxBuf,uint16_t modBusframeLength);

uint16_t modbusTcpParse(mbPacketParse_t *p_parseModbusTcpData, uint8_t *p_modbusRxBuf);

void modbusError(mbPacketParse_t *p_parseModbusTcpData, uint8_t *p_modbusTxBuf, unsigned char exceptioncode);

uint16_t readHoldingRegisters(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);
uint16_t presetSingleRegister(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);
uint16_t presetMultipleRegisters(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);

uint16_t readInputStatus(uint8_t *p_modbusTxBuf, uint16_t * p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);
uint16_t readCoilStatus(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);
uint16_t readInputReg(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);
uint16_t forceMultipleCoils(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);
uint16_t forceSingleCoil(uint8_t *p_modbusTxBuf, uint16_t *p_dataMemory, mbPacketParse_t *p_parseModbusTcpData);

 

 

