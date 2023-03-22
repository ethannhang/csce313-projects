//library to use altera i/o functions
#include "sys/alt_stdio.h"

//library to use altera variable types
#include "alt_types.h"

//library to get all hardware definitions
#include "system.h"

//library that has the definition of pio functions
#include "altera_avalon_pio_regs.h"

//C standard libraries
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

//Define the random_pattern base address as shown below. Take its value from system.h
#define RANDOM_PATTERN_BASE 0x21000

//Define the decoder_input base address. Take its value from system.h
#define DECODER_INPUT_BASE 0x21030

//Define the decoder_output base address. Take its value from system.h
#define DECODER_OUTPUT_BASE 0x21020

//Define the system_mode base address. Take its value from system.h
#define SYSTEM_MODES_BASE 0x21040

//Define the system_counter base address. Take its value from system.h
#define SYSTEM_COUNTER_BASE 0x21010


int main()
{ 
  alt_putstr("Project2 - CSCE 313\n");


  // declare the mode variable as alt_u8 and initialize with 0
  alt_u8 modes = 0x00;

  // declare the counter variable as alt_u8 and initialize with 0
  alt_u8 counter = 0x00;


  // declare the random variable as alt_u8 and initialize with 0
  alt_u8 pattern = 0x00;

  // declare the decoder-input variable as alt_u8 and initialize with 0
  alt_u8 dinput = 0x00;

  // declare number of random patterns as int. You can initialize it with any number you wish
  int rpattern = 3;


  /* Event loop never exits. */
  while (1){


	// read the mode values from system_modes using the function: IORD_ALTERA_AVALON_PIO_DATA
	  modes = IORD_ALTERA_AVALON_PIO_DATA(SYSTEM_MODES_BASE);



	// check If the mode is 0 so all LEDs must light up
		if(modes == 0x00){
			alt_putstr("LEDs light \n");

			// Example to how light Decoder_output LEDs. Do the same to light other leds
			IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0xFFFF);
			IOWR_ALTERA_AVALON_PIO_DATA(SYSTEM_COUNTER_BASE, 0xFFFF);
			IOWR_ALTERA_AVALON_PIO_DATA(RANDOM_PATTERN_BASE, 0xFFFF);


		}


	 // check if the mode is 1 so system counter starts counting
		if(modes == 0x01){
				alt_putstr("System counter \n");

				// First, reset all LEDs as shown in the example below
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x0000);
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(SYSTEM_COUNTER_BASE, 0x0000);
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(RANDOM_PATTERN_BASE, 0x0000);

				// Counter starts counting from 0 (0x00) to 255 (0xFF)
				for(int i=0; i<256; i++){

					// always keep checking If the mode values changed. If mode changes, break the loop. See the below code
						modes = IORD_ALTERA_AVALON_PIO_DATA(SYSTEM_MODES_BASE);
						if(modes != 0x01) break;

					// display the counter value onto the system-counter LEDs using IOWR_ALTERA_AVALON_PIO_DATA
						IOWR_ALTERA_AVALON_PIO_DATA(SYSTEM_COUNTER_BASE, counter);

					// increment counter by 1
					counter++;

					// time the display period of each counter value using usleep()
					usleep(1000000); // time for 1 million micro seconds


				}
		}

	// check if the mode is 2 so random pattern starts
			if (modes == 0x02){
				alt_putstr("Random pattern \n");

				// First, reset all LEDs as shown in the example below
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x0000);
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(SYSTEM_COUNTER_BASE, 0x0000);
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(RANDOM_PATTERN_BASE, 0x0000);



		  		for(int i=0; i<rpattern; i++){

					// always keep checking If the mode values changed. If mode changes, break the loop. (as code shown in mode=1 code)
					if(modes != 0x02) break;

					// generate random pattern using rand() function
					pattern = rand();

					// display the random value onto the random-pattern LEDs using IOWR_ALTERA_AVALON_PIO_DATA
					IOWR_ALTERA_AVALON_PIO_DATA(RANDOM_PATTERN_BASE, pattern);



		 			// time the display period of each counter value using usleep()
					usleep(1000000); // time for 1 million micro seconds

		  		  }
			}


	  // check If the mode is 3 so system decoder starts operating
				if(modes == 0x03){

					alt_putstr("System Decoder \n");

				// First, reset all LEDs as shown in the example below
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x0000);
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(SYSTEM_COUNTER_BASE, 0x0000);
		  	  	  IOWR_ALTERA_AVALON_PIO_DATA(RANDOM_PATTERN_BASE, 0x0000);



					// read the decoder input-switches using IORD_ALTERA_AVALON_PIO_DATA
		  	  	  	  dinput = IORD_ALTERA_AVALON_PIO_DATA(DECODER_INPUT_BASE);

						// display the decoder output based on the input value. As the example below
		  		  		  if(dinput == 0x00) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x00);
							// continue for all decoder cases
		  		  		if(dinput == 0x01) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x01);
		  		  		if(dinput == 0x02) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x02);
		  		  		if(dinput == 0x03) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x03);
		  		  	    if(dinput == 0x04) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x04);
		  		  	    if(dinput == 0x05) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x05);
		  		  	    if(dinput == 0x06) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x06);
		  		  	    if(dinput == 0x07) IOWR_ALTERA_AVALON_PIO_DATA(DECODER_OUTPUT_BASE, 0x07);


						usleep(1000000);
				}

}
  return 0;
}
