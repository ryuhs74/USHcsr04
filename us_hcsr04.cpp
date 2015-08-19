#include "us_hcsr04.h"
#include "Arduino.h"

usHcsr_04::usHcsr_04(int _trig, int _echo)
{
    m_lduration = 0;
    m_ldistance = 0;
    m_ntrigPin = _trig;
    m_nechoPin = _echo;
    
    pinMode(m_ntrigPin, OUTPUT);
    pinMode(m_nechoPin, INPUT);
}

long usHcsr_04::get_distance()
{
    m_lduration = 0;
    m_ldistance = 0;
    
    digitalWrite(m_ntrigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(m_ntrigPin, HIGH);
  
    delayMicroseconds(10); // Added this line
    digitalWrite(m_ntrigPin, LOW);
    m_lduration = pulseIn(m_nechoPin, HIGH);
    m_ldistance = (m_lduration/2) / 29.1;
}

