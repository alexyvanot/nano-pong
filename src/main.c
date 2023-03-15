#include <nanolib.h>
#include <avr/io.h>
#include <util/delay.h>


#include "nanopong/nanopong.h"

int main(void) {
  init_block_USART0();

  t_ball ball = initBall();

  for(;;) {
    printf("Ball : x = %d | y = %d | direction = %d\n", ball.x, ball.y, ball.direction);
    ball = initBall();
    _delay_ms(1000);
  }
  

  return 0;
}