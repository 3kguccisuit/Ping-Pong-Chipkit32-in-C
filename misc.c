#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

// Om en spelare vinner resettar vi score
void quit() {
    delay(1000);
  scorePlayer1 = 0;
  scorePlayer2 = 0;

  clearDisplay();
  display_image(0, oled_display);
}


// Börjar om på nytt när en spelare vinner och bestämmer riktning på bollen beroende vem som leder
void reset_game() {

  paddle1XPos = 0;
  paddle1YPos = 32 / 2 - 2;

  paddle2XPos = 128 - 4;
  paddle2YPos = 32 / 2 - 2;

  ballXPos = 128 / 2 - 5;
  ballYPos = 32 / 2;

  if (scorePlayer1 > scorePlayer2) {
    ballSpeedX = -1;
  }
  else if (scorePlayer1 < scorePlayer2) {
    ballSpeedX = 1;
  }
  else {
    ballSpeedX = 1;
  }
  ballSpeedY = 1;

  clearDisplay();
  
  displayPaddle(paddle1XPos, paddle1YPos, paddleWidth, paddleHeight);
  displayPaddle(paddle2XPos, paddle2YPos, paddleWidth, paddleHeight);
  displayBall(ballXPos, ballYPos, ballSize);
  display_image(0, oled_display);
  delay(1000);
}

//Töm skärmen
void string_clear() {
  display_string(0, "");
  display_string(1, "");
  display_string(2, "");
  display_string(3, "");
  display_string(4, "");
  display_update();
}
