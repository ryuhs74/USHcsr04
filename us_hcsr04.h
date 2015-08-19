#ifndef _HCSR_04
#define _HCSR_04

#include "Arduino.h"

class usHcsr_04
{
  public:
    usHcsr_04(int _trig, int _echo);
    long get_distance(); 
  private:
    long m_lduration; 
    long m_ldistance;

    int m_ntrigPin;
    int m_nechoPin;
};
#endif
