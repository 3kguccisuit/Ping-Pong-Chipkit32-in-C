#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

//Om paddeln åker upp eller ner medans den träffar bollen så ändrar vi bollens riktning på Y axeln
void paddle1Physics()
{
  if (paddle1Up == 1)
  {
        ballSpeedY = -1;
  }
  if (paddle1Down == 1)
  {
      ballSpeedY = 1;
  }
}
//Om paddeln åker upp eller ner medans den träffar bollen så ändrar vi bollens riktning på Y axeln
void paddle2Physics()
{

  if (paddle2Up == 1)
  {
      ballSpeedY = -1;
  }

  else if (paddle2Down == 1)
  {
      ballSpeedY = 1;
  }
}
//Om paddlen träffar bollen så byter bollen riktning i x-axeln och anropar paddlephysics
//Eller om paddeln missar bollen blir det mål
void paddleHit() {
  if (ballXPos == paddleWidth) {
    if (((ballYPos + ballSize) > paddle1YPos) && (ballYPos - ballSize) < (paddle1YPos + paddleHeight)) {
      ballSpeedX = -(ballSpeedX);
      paddle1Physics();
    }
  }
  else if(ballXPos < -5) //-21 
  {
    goal(2);
  }

  if (ballXPos == (128 - paddleWidth - 4)) {
    if (((ballYPos + ballSize) > paddle2YPos) && (ballYPos - ballSize) < (paddle2YPos + paddleHeight)) {
      ballSpeedX = -(ballSpeedX);
      paddle2Physics();
    }
  }
  else if (ballXPos > 133) //138
  { 
    goal(1);
  }
}

