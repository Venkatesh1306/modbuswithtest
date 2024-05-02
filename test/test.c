/*
 * File:   test.c
 * Author: Green2
 *
 * Created on 9 April, 2024, 11:13 AM
 * developed for testing the inputs
 */

#include "testhead.h"
// recived packet frame
unsigned char ModbusTcpRxBuftest[INR_SIZE][100] = {
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x09, 0x00, 0x07, 0x00, 0x06},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x01, 0x00, 0x01, 0x00, 0x09},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x01, 0x00, 0x51, 0x00, 0x09},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x02, 0x00, 0x02, 0x00, 0x03},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x02, 0x00, 0x56, 0x00, 0x03},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x03, 0x00, 0x09, 0x00, 0x03},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x03, 0x00, 0x28, 0x00, 0x03},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x04, 0x00, 0x06, 0x00, 0x02},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x04, 0x00, 0x31, 0x00, 0x02},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x05, 0x00, 0x03, 0xff, 0x00},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x05, 0x00, 0x53, 0xff, 0x00},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x05, 0x00, 0x07, 0xfc, 0x00},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x06, 0x00, 0x03, 0x03, 0x04},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x06, 0x00, 0x27, 0x00, 0x06},
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x06, 0x00, 0x09, 0xff, 0xff},
    {0x11, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0B, 0x03, 0x0F, 0x00, 0x01, 0x00, 0x15, 0x04, 0xcd, 0x01, 0x03, 0x02},
    {0x11, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0B, 0x03, 0x0F, 0x00, 0x55, 0x00, 0x15, 0x04, 0xcd, 0x01, 0x03, 0x02},
    {0x11, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0B, 0x03, 0x0F, 0x00, 0x01, 0x00, 0x15, 0x04, 0xff, 0xff, 0x03, 0x02},
    {0x11, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x10, 0x00, 0x06, 0x00, 0x02, 0x04, 0x03, 0x04, 0x3c, 0x7e},
    {0x0e, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x10, 0x00, 0x30, 0x00, 0x01, 0x00, 0x03},
    {0x13, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x10, 0x00, 0x0C, 0x00, 0x03, 0x06, 0xff, 0xff, 0x06, 0x05, 0x06, 0x05},
};

// expected frame to send
unsigned char Test_TXtest[INR_SIZE][100] = {
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x89, 0x01},                                    // Function ErrorCrt
    {0x0b, 0x00, 0x01, 0x00, 0x02, 0x00, 0x05, 0x03, 0x01, 0x02, 0xff, 0x01},                        // F-01
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x81, 0x02},                                    // F-01 Addr Error
    {0x0A, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x03, 0x02, 0x01, 0x07},                              // F-02
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x82, 0x02},                                    // F-02 Addr Error
    {0x0f, 0x00, 0x01, 0x00, 0x02, 0x00, 0x09, 0x03, 0x03, 0x6, 0x3c, 0x7e, 0x03, 0x02, 0xFF, 0xFF}, // f-03
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x83, 0x02},                                    // F-03 Addr Error
    {0x0D, 0x00, 0x01, 0x00, 0x02, 0x00, 0x07, 0x03, 0x04, 0x4, 0x00, 0xff, 0xff, 0x00},             // F-04
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x84, 0x02},                                    // F-04 Addr Error
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x05, 0x00, 0x03, 0xff, 0x00},                  // F-05
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x85, 0x02},                                    // F-05 Addr Error
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x85, 0x03},                                    // F-05 Data Error
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x06, 0x00, 0x03, 0x03, 0x04},                  // F-06
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x86, 0x02},                                    // F-06 Adrr Error
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x86, 0x03},                                    // F-06 Data Error
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x0F, 0x00, 0x01, 0x00, 0x20},                  // F-0F
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x8F, 0x02},                                    // F-0F Addr Error
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x8F, 0x03},                                    // F-0F Data Error
    {0x0c, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x03, 0x10, 0x00, 0x06, 0x00, 0x02},                  // F-10
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x90, 0x02},                                    // F-10 Addr Error
    {0x09, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x90, 0x03},                                    // F-10 Data Error
};

// Data register
unsigned short int Dataregister[100] = {0xffff, 0x00ff, 0x0000, 0xFFFF, 0x00ff, 0x00ff, 0x00ff, 0xff00, 0x3A2B, 0x3c7e, 0x0302, 0xFFFF, 0x1123, 0x1321, 0x3A2B, 0x3c7e, 0x0065, 0x2217, 0x1123, 0x1321, 0x3A2B, 0x3c7e, 0x0065, 0x2217, 0x1123, 0x1321, 0x3A2B, 0x3c7e, 0x0065, 0x2217, 0x1123, 0x1321, 0x3A2B, 0x3c7e};

//unsigned short int InputRegister[100] = {0x00ff, 0x3c7e, 0x0302, 0xFFFF, 0x1123, 0x1321, 0x3A2B, 0x3c7e, 0xff00, 0x00ff, 0x0000, 0x0065, 0x2217, 0x1123, 0x1321, 0x3A2B, 0x3c7e, 0xFFFF, 0x00ff, 0x00ff, 0x00ff, 0xff00, 0x0065, 0x2217, 0x1123, 0x1321, 0x3A2B, 0x3c7e, 0x0065, 0x2217, 0x1123, 0x1321, 0x3A2B, 0x3c7e};

/*
main function for testing
generates the expected frame by cosidering the ModbusTcpRxBuf
stores the frame in Test_TX
finally checks the expected and actual outputs are same
expected -- Test_Tx
*/
int main()
{

   int j;
   for (incrs = 0; incrs < INR_SIZE; incrs++)
   {
      for (j = 0; j <= ModbusTcpRxBuftest[incrs][0]; j++)
      {
         ModbusTcpRxBuf[j] = ModbusTcpRxBuftest[incrs][j + 1];
      }
      for (j = 0; j <= Test_TXtest[incrs][0]; j++)
      {
         Test_tx[j] = Test_TXtest[incrs][j + 1];
      }

      modbusTcpFrame(&ModbusTcpRxBuf[0], &Dataregister[0], &ModbusTcpTxBuf[0], ModbusTxLength); // main call function

      Test_ing(ModbusTcpTxBuf, Test_tx); // comparing expected and actual frame

      printfunction(); // printing the output
   }
}