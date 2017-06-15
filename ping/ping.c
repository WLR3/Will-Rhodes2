/*
 * Will Rhodes
 * ping
 * Program #7
 * 06/15/17
*/
#include "simpletools.h"                      // Include simple tools

const int TRIGGER_PIN = 0;
const int ECHO_PIN = 1;

int main()                                    // Main function
{
  long duration;
  long distance;
  
  low(TRIGGER_PIN);
  low(ECHO_PIN);
  pause(250);
 
  while(1)
  {
    pulse_out(TRIGGER_PIN, 10);
    duration = pulse_in(ECHO_PIN, 1);
    print("%c%c", HOME, CLREOL);
    distance = duration / 148;
    print("Distanc3e = %d inches\n", distance);
    pause(250);
  }  
}
