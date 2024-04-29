#include "testingdata.h"
#define SET(x,y)  x |= (1 << y) 
#define READ(x,y)  ((0u == (x & (1<<y)))?0u:1u)
#define CLEAR(x,y) x &= ~(1<< y)


// coil address -> reg and bit ->
unsigned int coil_byte_index,coil_byte_count, coil_byte_count,coil_byteValue,coil_bit_index,coil_register_index, coil_register_status,coil_data;
WORD
forcemultiplecoils (BYTE *ModbusTcpTxBuf, unsigned char  *COIL , parse1 *parse)
{
    unsigned int NoOfBits,bit_count ,Regbit, regTx, RegbitTx, reg;
    
  ModbusTcpTxBuf[0] = parse->TransactionID.v[1];
  ModbusTcpTxBuf[1] = parse->TransactionID.v[0];

  ModbusTcpTxBuf[2] = parse->ProtocolID.v[1];
  ModbusTcpTxBuf[3] = parse->ProtocolID.v[0];

  ModbusTcpTxBuf[4] = 0X0;
  ModbusTcpTxBuf[5] = parse->Length;
  // Output[5] = 0X3 + Output[8];
  ModbusTcpTxBuf[6] = parse->UnitID;
  ModbusTcpTxBuf[7] = parse->FunctionCode;

  ModbusTcpTxBuf[8] = parse->StartAddress.v[1];
  ModbusTcpTxBuf[9] = parse->StartAddress.v[0];

  ModbusTcpTxBuf[10] = parse->NumberofRegister.v[1];
  ModbusTcpTxBuf[11] = parse->NumberofRegister.v[0];
  
  NoOfBits = parse->NumberofRegister.Val; // Quantity of coils
  
     for (bit_count = NoOfBits+1; bit_count >= 0; bit_count--) // byte count 
    {
        Regbit = (parse->StartAddress.Val + bit_count - 1) % 16; // 20 - 1 % 16 = 4th bit
        reg = (parse->StartAddress.Val + bit_count - 1) / 16; // 20 - 1 /16 = 1st  reg
       
        RegbitTx = (bit_count) % 8; // 20 - 1 % 16 = 4th bit -- bit increment
        regTx = (bit_count) / 8; // 20 - 1 /16 = 1st  reg -- register increment
        
        
       // if(Regbit == 0 ){}
        // Txtempbuf[regTx] |= READ(COIL[reg], Regbit) << RegbitTx;
        
        coil_data = READ(parse->Coil_data[regTx],RegbitTx);
        
        if(coil_data == 0x1)
        {
            SET(COIL[reg],Regbit);
        }
        else
        {
            CLEAR(COIL[reg],Regbit);
        }
        if(bit_count == 0)
        {
            break;
        }
     }        
  return 0x12;
        
}
