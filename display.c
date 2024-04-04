#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

// displayPaddle(paddle1XPos, paddle1YPos, paddleWidth, paddleHeight);
// Går igenom hela oled skärmen och markerar var vår paddle finns och sedan
// anropar setPixel som gör att den visas på skärmen.
void displayPaddle(int xPos, int yPos, int width, int height)
{
  int y, x;
  for (y = 0; y < 32; y++)
  {
    for (x = 0; x < 128; x++)
    {
      if (y >= yPos && y <= (yPos + height) && x >= xPos && x <= (xPos + width))
      {
        setPixel(x, y, 1);
      }
    }
  }
}

// displayBall(ballXPos, ballYPos, ballSize);
// Går igenom hela oled skärmen och markerar var vår boll finns
void displayBall(int xPos, int yPos, int diameter)
{
  int y, x;
  for (y = 0; y < 32; y++)
  {
    for (x = 0; x < 128; x++)
    {
      if (y >= yPos && y <= (yPos + diameter) && x >= xPos && x <= (xPos + diameter))
      {
        setPixel(x, y, 1);
      }
    }
  }
}

// Översätter till till oled skrämen
void setPixel(int x, int y, int val)
{
  int row = (y / 8);       // Vilken rad (0-3) ska vi ändra
  int ind = row * 128 + x; // Index inom oled_display
  int rest = y % 8;        // Vilken pixel på raden som ska ändras (%=modulo)
  int bitPos = 1 << rest;  // Vilken bit som ska ändras blir antingen 1,2,4,8,16,32,64,128

  uint8_t oldVal = oled_display[ind]; // Hämta gamla värdet

  if (val == 1)
  {
    oled_display[ind] |= bitPos; // Tänd pixel på bitPos utan att förstöra pixlarna runt omkring
  }
  else
  {
    oled_display[ind] &= ~bitPos; // Släck pixel på bitPos utan att förstöra pixlarna runt omkring
  }
}

void clearDisplay()
{
  int i;
  for (i = 0; i < 512; i++)
  {
    oled_display[i] = 0;
  }
}
