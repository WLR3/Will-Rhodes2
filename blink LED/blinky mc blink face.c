/*
* Will Rhodes 
* Program 2
* Blink a LED
* 06/12/17
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  while(1)
  {
   high(0);
   low(15);
   pause(400);
   low(0);
   high(15);
   pause(400);
  }  
}
