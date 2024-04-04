#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>


//Om en spelare gör mål ökar vi scorePlayer med 1. Och om en spelare får 3 vinner den. 
void goal(player) {


  if (player == 1) {  
    scorePlayer1 += 1;
    display_string(2, "Player 1 scored!");
    display_update(); 
    delay(2000);
  }
  if (player == 2) {   
    scorePlayer2 += 1;
    display_string(2, "Player 2 scored!"); 
    display_update();
    delay(2000);
  }
    if (scorePlayer1 == 3){
      player1Win();
    }

    if (scorePlayer2 == 3){
      player2win();
    }

  reset_game();
}