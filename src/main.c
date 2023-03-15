#include <nanolib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "nanopong/nanopong.h"


void init_game()
{
  write_column_MAX7219(1, 0b00111000);
  write_column_MAX7219(5, 0b00001000);
  write_column_MAX7219(8, 0b00111000);
}

void init_potentiometers()
{
  init_ADC(ADC_AVCC, ADC_RIGHT_ADJUST, ADC_NO_INTERRUPT, ADC_PRESCALER_128);
  init_pin_ADC(A0);
  init_pin_ADC(A1);

  //printf("A0: %d ; A1: %d ", potA0, potA1);
}

int main(void) {
  //sei();
  init_block_USART0();
  //init_MAX7219();
  //clear_MAX7219();

  //set_brightness_MAX7219(0b00001111);
  init_potentiometers();

  // uint8_t gameIsStarted = 0;
  // uint8_t gameIsFinished = 0;

  uint16_t potA0;
  uint16_t potA1; 
  uint8_t isInitLoad = 1;

  for(;;) {
    //init_game();
    uint16_t adcValA0 = (analog_read(A0) & 0b1111111111111100);
    uint16_t adcValA1 = (analog_read(A1) & 0b1111111111111100);

    // if (isInitLoad == 1) {
    //   potA0 = adcValA0;
    //   potA1 = adcValA1;
    //   isInitLoad = 0;
    // }

    if ((adcValA0 > potA0   || adcValA0 < potA0 ) || (adcValA1 > potA1 || adcValA1 < potA1)) {
      potA0 = adcValA0 ;
      potA1 = adcValA1 ;
      printf("A0: %d ; A1: %d\n", potA0, potA1);
    }
  }
  //_delay_ms(100);

  return 0;
}