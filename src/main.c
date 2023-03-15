#include <nanolib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "nanopong/nanopong.h"


// void init_game()
// {
//   write_column_MAX7219(1, 0b00111000);
//   write_column_MAX7219(5, 0b00001000);
//   write_column_MAX7219(8, 0b00111000);
// }

void init_potentiometers()
{
  init_pin_ADC(A0);
  init_pin_ADC(A1);
  init_ADC(ADC_AVCC, ADC_RIGHT_ADJUST, ADC_NO_INTERRUPT, ADC_PRESCALER_128);

  //printf("A0: %d ; A1: %d ", potA0, potA1);
}

void led()
{
  init_output_GPIO(D2);
  write_output_GPIO(D2, HIGH);
  init_output_GPIO(D3);
  write_output_GPIO(D3, HIGH);
  init_output_GPIO(D4);
  write_output_GPIO(D4, HIGH);
  init_output_GPIO(D5);
  write_output_GPIO(D5, HIGH);
  init_output_GPIO(D6);
  write_output_GPIO(D6, HIGH);
  init_output_GPIO(D7);
  write_output_GPIO(D7, HIGH);
}

int main(void) {
  
  sei();
  init_block_USART0();
  init_potentiometers();
  init_MAX7219();
  clear_MAX7219();
  // led();
  set_brightness_MAX7219(0b00001111);

  t_game game = init_game();
  draw_game(game);

  printf("Game started: %u\n", game.isGameStarted);

  for(;;) {
    printf("------------------------------------------------------------------\n");
    updatePaddles(&game);
    game.ball = updateBall(game);

    clear_MAX7219();
    draw_game(game);
    
    _delay_ms(2000);
  }

  return 0;
}