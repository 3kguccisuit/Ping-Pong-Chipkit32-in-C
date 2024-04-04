#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

void player1Win(){
  display_string(2, "Player 1 wins!");
  display_update();
  delay(2000);
   quit();

}

void player2win(){
  display_string(2, "Player 2 wins!");
 display_update();
 delay(2000);
  quit();
}
