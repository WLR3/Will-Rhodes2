/*
 * Will Rhodes
 * Reaction game
 * Program #6
 * 6/15/17
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  int timeCounter;
  char playAgain = 'Y';
  int interval;
  float scoreSum;
  int rounds = 0;
  int best = 1500;
  
  srand(CNT);
  
  print("Game instructions:\n");
  print("The blue LED turns on when the game start.\n");
  print("When the yellow LED turns on,\n");
  print("let go of the button as fast as you can.\n\n");
  
  while (playAgain == 'Y' || playAgain == 'y')
  {
    print("Press and hold the button to start.\n");
    while (input(0) == 0)
    {
     // this loop is intintionally empty 
    }                
    
    high(15);
    low(14);
    
    interval = (rand() % 1001) + 500;
    pause(interval);
    
    low(15);
    high(14);
    
    timeCounter = 0;
    while (input(0) == 1)
    {
      pause(1);
      timeCounter = timeCounter + 1;
    }
    low(14);
    
    if (timeCounter > 0)
    {
      rounds = rounds + 1;
      scoreSum = scoreSum + timeCounter;
      print("Your time was %d ms. \n", timeCounter);
      
      if (timeCounter < best)
      {
        best = timeCounter;
      }        
    }
    else
    {
      print("Oops! you let go of the button too soon.\n");
    }
    
    print("Would you like to play again (Y/n) ");
    scan("%c", &playAgain);
    
  } // end of playAgain loop
  
  print("Goodbye! Your average time was %0.2f ms.\n", scoreSum / rounds);
  print("Your best time was %d ms.\n", best);
  
  return 0;
  }                    
  