// including the required header files
#include "D:\Version6\GenericTypeDefs_1.h"
#include "D:\Version6\Modbus1\testingdata.h"
#include <stdio.h>

// define the values
#define test_ing
#define result
#define INR_SIZE 11
#define GET_BIT(x, pos) ((x >> pos) & 1)
#define SET(PIN, N) (PIN |= (1 << N))
#define CLR(PIN, N) (PIN &= ~(1 << N))

// ANSI escape codes for text color - for testing features
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_ORANGE "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Variables and Values
extern unsigned char ModbusTcpRxBuftest[INR_SIZE][100];
extern unsigned char Test_TXtest[INR_SIZE][100];
extern unsigned char ModbusTcpRxBuf[100];
extern unsigned char ModbusTcpTxBuf[25];
extern unsigned char Test_TX[25];
extern unsigned short int Dataregister[100];
extern int increment;
extern int Test_Res;
extern int inc;
extern int test_c;
extern unsigned int ModbusTxLength;
extern unsigned short int receivedData;
extern unsigned short int add;
extern unsigned short int numRegisters;
parse1 parse;

// declaration of the function
unsigned short int processexpecteddata(unsigned char *ModbusTcpRxBuf, unsigned char *Test_TX, unsigned short int Dataregister[]);
unsigned short int Test_ing(const unsigned char ModbusTcpTxBuf[], const unsigned char Test_TX[]);
WORD frame_function(BYTE *ModbusTcpRxBuf, WORD *Dataregister, parse1 *parse, BYTE *ModbusTcpTxBuf, unsigned int *ModbusTxLength);
void printfunction();