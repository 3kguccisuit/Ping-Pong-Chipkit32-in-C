/* mipslabwork.c
   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall
   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):
   Thias file modified 2022-03-04 by Ludwig Hahn and Erik Göransson
   For copyright and licensing, see file COPYING */

#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t oled_display[512];
//int initial_active = 0;

// Game specific variables
float game_active = 0;
int scorePlayer1 = 0;
float scorePlayer2 = 0;
float player = 0;


/* Interrupt Service Routine */
void user_isr(void)
{
  return;
}

/* Lab-specific initialization goes here */
void labinit(void)
{
  volatile int *trise = (volatile int *)0xbf886100;
  // TRISECLR = 0xff;  // Set as output (LED:S)
  TRISDSET = 0xfe0; // Set as input (BTN 2-4, SW 1-4)
  TRISFSET = 0x2;   // Set as input (BTN 1)
                    // PORTE = 0x0;      // LED:s
}

/* This function is called repetitively from the main program */
void labwork(void)
{
  //Hämtar knappar
  int btns = getbtns();
 

// om spelet inte är aktivt visas det här under. 
  if (!game_active)
  {
    display_string(0, "Pong Game");
    display_string(1, "Made by");
    display_update();
    delay(2000);

    display_string(2, "Erik Goransson");
    display_update();
    delay(2000);

    display_string(2, "&");
    display_update();
    delay(2000);

    display_string(2, "Ludwig Hahn");
    display_update();
    delay(2000);

    string_clear();
  }

//Kör spelet
  game_active = 1;
  twoPlayerMode(btns);
  ballMovement();
  paddleHit();

//Uppdatera displayen
  clearDisplay();
  displayPaddle(paddle1XPos, paddle1YPos, paddleWidth, paddleHeight);
  displayPaddle(paddle2XPos, paddle2YPos, paddleWidth, paddleHeight);
  displayBall(ballXPos, ballYPos, ballSize);
  
  display_image(0, oled_display);
}
