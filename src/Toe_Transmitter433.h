/*
  Toe_Transmitter433.h - Library to transmit messages using 433 ASK transmitter.
*/
#ifndef TOE_TRANSMITTER443_H
#define TOE_TRANSMITTER443_H

#ifndef ENSURE_FACTOR
#define ENSURE_FACTOR 3
#endif #ENSURE_FACTOR

#ifndef PAUSE
#define PAUSE 11000
#endif #PAUSE

class Toe_Transmitter433
{
  public:
    Toe_Transmitter433(int bitLength, int pin, int preHi, int preLo, int zerHi, int zerLo, int oneHi, int oneLo);
    void transmit(char* msg);

  private:
    int _bitLength;
    int _pin;
    int _preHi;
    int _preLo;
    int _zerHi;
    int _zerLo;
    int _oneHi;
    int _oneLo;
};
 
#endif #TOE_TRANSMITTER443_H
