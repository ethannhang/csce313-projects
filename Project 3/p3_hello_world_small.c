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



//Define the decoder_input base address. Take its value from system.h
#define ROTATION_INPUTS_BASE 0x21080

//Define the decoder_output base address. Take its value from system.h

//Define the system_mode base address. Take its value from system.h
#define SYSTEM_MODES_BASE 0x21090

#define SEGMENT0_BASE 0x21070
#define SEGMENT1_BASE 0x21060
#define SEGMENT2_BASE 0x21050
#define SEGMENT3_BASE 0x21040
#define SEGMENT4_BASE 0x21030
#define SEGMENT5_BASE 0x21020
#define SEGMENT6_BASE 0x21010
#define SEGMENT7_BASE 0x21000

int main()
{ 
  alt_putstr("Project3 - CSCE 313\n");


  // declare the mode variable as alt_u8 and initialize with 0
  alt_u8 modes = 0x00;
  //alt_u8 one = 0xF9;
  alt_u8 pattern = 0x00;
  int counter = 0;
  int counterb = 0;
  int counterc = 0;
  alt_u8 rotation = 0x00;
  int sleep = 125000;

  // declare number of random patterns as int. You can initialize it with any number you wish
  int rpattern = 3;


  /* Event loop never exits. */
  while (1){
	// read the mode values from system_modes using the function: IORD_ALTERA_AVALON_PIO_DATA
	  modes = IORD_ALTERA_AVALON_PIO_DATA(SYSTEM_MODES_BASE);
		if(modes == 0x00){
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT4_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT5_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0x0000);
			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0x0000);
		}
	 // check if the mode is 1
		if(modes == 0x01){
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT4_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT5_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFFFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFC0);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFC0);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFC0);
		IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFC0);
		while(modes == 0x01){
			modes = IORD_ALTERA_AVALON_PIO_DATA(SYSTEM_MODES_BASE);
			if(modes != 0x01){
				break;
			}
					//for(int p =0; p<20; p++){
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFC0);//0
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFF9);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFA4);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFB0);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF99);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF92);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF82);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFF8);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF80);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF98);//9
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF88);//A
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF80);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFC6);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFC0);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF86);
					usleep(10000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFF8E);
					usleep(10000);
					counter++;
					switch(counter) {
					case 1:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFF9);
						break;
					case 2:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFA4);
						break;
					case 3:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFB0);
						break;
					case 4:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF99);
						break;
					case 5:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF92);
						break;
					case 6:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF82);
						break;
					case 7:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFF8);
						break;
					case 8:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF80);
						break;
					case 9:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF98);
						break;
					case 10:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF88);
						break;
					case 11:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF80);
						break;
					case 12:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFC6);
						break;
					case 13:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFC0);
						break;
					case 14:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF86);
						break;
					case 15:
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFF8E);
						counterb++;
						counter = 0;
						break;
					}
					switch(counterb) {
							case 1:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFF9);
								break;
							case 2:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFA4);
								break;
							case 3:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFB0);
								break;
							case 4:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF99);
								break;
							case 5:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF92);
								break;
							case 6:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF82);
								break;
							case 7:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFF8);
								break;
							case 8:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF80);
								break;
							case 9:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF98);
								break;
							case 10:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF88);
								break;
							case 11:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF80);
								break;
							case 12:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFC6);
								break;
							case 13:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFC0);
								break;
							case 14:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF86);
								break;
							case 15:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFF8E);
								counterb = 0;
								counterc++;
								break;
							}
					switch(counterc) {
							case 1:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFF9);
								break;
							case 2:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFA4);
								break;
							case 3:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFB0);
								break;
							case 4:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF99);
								break;
							case 5:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF92);
								break;
							case 6:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF83);
								break;
							case 7:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFF8);
								break;
							case 8:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF80);
								break;
							case 9:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF98);
								break;
							case 10:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF88);
								break;
							case 11:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF80);
								break;
							case 12:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFC6);
								break;
							case 13:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFC0);
								break;
							case 14:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF86);
								break;
							case 15:
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFF8E);
								counterc = 0;
								break;
					}
}
		}

	// check if the mode is 2 so random pattern starts
			if (modes == 0x02){
				//alt_putstr("Random pattern \n");

				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT4_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT5_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFFFF);
				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFFFF);

		  		for(int i=0; i<rpattern; i++){
					// always keep checking If the mode values changed. If mode changes, break the loop. (as code shown in mode=1 code)
					if(modes != 0x02) break;
					// generate random pattern using rand() function
					pattern = rand();
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT4_BASE, pattern);
					usleep(100000);
					IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT5_BASE, pattern);
					usleep(100000); // time sleep
		  		  }
			}

	  // check If the mode is 3
				if(modes == 0x03){

					while(modes == 0x03){

						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT0_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT1_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT2_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT3_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT4_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT5_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFFFF);
						IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFFFF);

						rotation = IORD_ALTERA_AVALON_PIO_DATA(ROTATION_INPUTS_BASE);

		  		  			if(rotation == 0x00){ // nothing
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFFFF);
								IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFFFF);
							}

		  		  			if(rotation == 0x01 || rotation == 0x05){
		  		  				if(rotation == 0x05) {
									sleep = 300000;
								}else{
									sleep = 125000;
								}
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFE);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFD);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFB);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xF7);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFF);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xF7);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xEF);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xDF);
		  		  				usleep(sleep);
		  		  				IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFE);
		  		  				usleep(sleep);
		  		  		}
		  		  		if(rotation == 0x02 || rotation == 0x06) {
		  		  			if(rotation == 0x06){
		  		  				sleep = 300000;
		  		  			}else{
		  		  				sleep = 125000;
		  		  			}
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFE);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xDF);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xEF);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xF7);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT7_BASE, 0xFF);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xF7);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFB);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFD);
		  		  			usleep(sleep);
		  		  			IOWR_ALTERA_AVALON_PIO_DATA(SEGMENT6_BASE, 0xFE);
		  		  			usleep(sleep);
					}
				}
			}
}
  return 0;
}
