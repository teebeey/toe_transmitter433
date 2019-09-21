#include <Toe_Transmitter433.h>

// Optional overrides of library defaults
#define ENSURE_FACTOR 3
#define PAUSE 11000

// Configuration variables
#define DATA_PIN 10

// Measured values of transmitter to be cloned
#define CODE_LENGTH 40
#define PRE_HI 4800
#define PRE_LO 1540
#define ZERO_HI 360
#define ZERO_LO 740
#define ONE_HI 720
#define ONE_LO 380

// Codes to send
#define CH_A_UP   "0101000101011011101011101000001000010001"
#define CH_A_DOWN "0101000101011011101011101000001000110011"
#define CH_A_STOP "0101000101011011101011101000001001010101"

Toe_Transmitter433 xmit(CODE_LENGTH, DATA_PIN, PRE_HI, PRE_LO, ZERO_HI, ZERO_LO, ONE_HI, ONE_LO);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  xmit.transmit(CH_A_UP);
  delay(3000);
  xmit.transmit(CH_A_STOP);
  delay(3000);
  xmit.transmit(CH_A_DOWN);
  delay(3000);
  xmit.transmit(CH_A_STOP);
  delay(3000);
}
