/*
  Toe_Transmitter433.cpp - Library to transmit messages using 433 ASK transmitter.
*/

#include "Toe_Transmitter433.h"
#include <Arduino.h>

Toe_Transmitter433::Toe_Transmitter433(int bitLength, int pin, int preHi, int preLo, int zerHi, int zerLo, int oneHi, int oneLo)
{
    _bitLength=bitLength;
    _pin=pin;
    _preHi=preHi;
    _preLo=preLo;
    _zerHi=zerHi;
    _zerLo=zerLo;
    _oneHi=oneHi;
    _oneLo=oneLo;

	pinMode(pin, OUTPUT);
	
	digitalWrite(pin, LOW);
}

void Toe_Transmitter433::transmit(char* msg)
{
  for (int j = 0; j < ENSURE_FACTOR; j++)
  {
    //pause
    digitalWrite(_pin, LOW);
    delayMicroseconds(PAUSE);

    //preamble
    digitalWrite(_pin, HIGH);
    delayMicroseconds(_preHi);
    digitalWrite(_pin, LOW);
    delayMicroseconds(_preLo);

    //message
    for (int i = 0; i < _bitLength; i++)
    {
      if(msg[i] == '1')
      {
        digitalWrite(_pin, HIGH);
        delayMicroseconds(_oneHi);
        digitalWrite(_pin, LOW);
        delayMicroseconds(_oneLo);
      }
      else
      {
        digitalWrite(_pin, HIGH);
        delayMicroseconds(_zerHi);
        digitalWrite(_pin, LOW);
        delayMicroseconds(_zerLo);
      }
    }

    //close
    digitalWrite(_pin, LOW);
  }
}
