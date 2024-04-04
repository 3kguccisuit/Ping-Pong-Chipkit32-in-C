#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

//Paddle varibler
float paddleHeight = 10;
float paddleWidth = 2;
float paddleSpeed = 1;

float paddle1XPos = 0;
float paddle1YPos = 32 / 2 - 2;

float paddle2XPos = 128 - 4;
float paddle2YPos = 32 / 2 - 2;

float paddle2Up = 0;
float paddle2Down = 0;
float paddle1Up = 0;
float paddle1Down = 0;

//Boll variabeler
float ballSize = 2;
float ballSpeedX = 1;
float ballSpeedY = 1; 

int ballXPos = 128 / 2 - 5;
int ballYPos = 32/2;
int count = 0;

//Styrning av paddeln med knapparna
void twoPlayerMode(btns) {
  paddle2Up = 0;
  paddle2Down = 0;
  paddle1Up = 0;
  paddle1Down = 0;

  if ((btns & 0x1) && (paddle2YPos < (32 - paddleHeight))) {
    paddle2YPos += paddleSpeed;
    paddle2Up = 1;
  }
  if ((btns & 0x2) && (paddle2YPos > 0)) {
    paddle2YPos -= paddleSpeed;
    paddle2Down = 1;
  }
  if ((btns & 0x4) && (paddle1YPos < (32 - paddleHeight))) {
    paddle1YPos += paddleSpeed;
    paddle1Up = 1;
  }
  if ((btns & 0x8) && (paddle1YPos > 0)) {
    paddle1YPos -= paddleSpeed;
    paddle1Down = 1;
  }
}

//Hur bollen rör sig
void ballMovement() {
  ballXPos += ballSpeedX;
  ballYPos += ballSpeedY;
  if(ballSpeedY > 1.7){
    ballSpeedY = 1.7;
  }
  if(ballSpeedY < -1.7){
    ballSpeedY = -1.7;
  }

  if (ballYPos < 1 || ballYPos > (31 - ballSize)) {
    ballSpeedY = -(ballSpeedY);
  }
  
   if((ballSpeedY < 0.3) && (ballYPos <= 10)) {
     count++;
     if(count >= 10){
       ballSpeedY = 1;
       count = 0;
     }
   }
   else{
     count = 0;
   }
}
