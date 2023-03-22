#include "sys/alt_stdio.h"
#include "sys/alt_driver.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include <math.h>
#include <sys/alt_alarm.h>
#include "myfile.h"
#include <stdio.h>

// add the pixel buffer dma as shown in no.5 of the software requirements in the assignment sheet
#include <altera_up_avalon_video_pixel_buffer_dma.h>
int main()
{ 
  // declare the key1 variable as alt_u8 and initialize with 0
    alt_u8 key1=0;

    // declare the key2 variable as alt_u8 and initialize with 0
    alt_u8 key2=0;

    // declare the key3 variable as alt_u8 and initialize with 0
    alt_u8 key3=0;

    // Read pixel buffer (go to no.6 of software requirements in the assignment sheet)

    alt_up_pixel_buffer_dma_dev *my_pixel_buffer;
    my_pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/dma_buffer");

    // Check if the pixel array contains the image (go to no.7 of software requirements in the assignment sheet)
    if(!my_pixel_buffer) printf("Error opening pixel buffer\n");

   // Clear the screen (go to no.8 of software requirements in the assignment sheet)
    alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);

    float f;

    while(1) {
    // Read the key1 value
     key1 = IORD_ALTERA_AVALON_PIO_DATA(KEY1_BASE);

    // Read the key2 value, same as above
     key2 = IORD_ALTERA_AVALON_PIO_DATA(KEY2_BASE);

   // Read the key3 value, same as above
     key3 = IORD_ALTERA_AVALON_PIO_DATA(KEY3_BASE);
     //printf("k1: %u, k2: %u, k3: %u", key1, key2, key3);


   	// check the key1 value. Remember key is on if it is zero and off it is one.
     if(!key1) {
      	//Clear the screen (go to no.8 of software requirements in the assignment sheet)
  	   alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
  		// display the image (go to no.9 of software requirements in the assignment sheet)
  	   for(int i = 0; i<240; i++){
  		   for(int j = 0; j<320; j++){
  			   alt_up_pixel_buffer_dma_draw(my_pixel_buffer, (myimage[(i*320*3+j*3+2)]) + (myimage[(i*320*3+j*3+1)]<<8) + (myimage[(i*320*3+j*3+0)]<<16),j,i);
  		   }
  	   }
      }

  	// check the key2 value. Remember key is on if it is zero and off it is one.
     else if(!key2){
  	  f = 0.5;

  		//Clear the screen (go to no.8 of software requirements in the assignment sheet)
  	   alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);

      	// Resize the image by 0.5 and display the image (go to no.10 of software requirements in the assignment sheet)
  	   for(int i = 0; i<240; i++){
  	   		   for(int j = 0; j<320; j++){
  	   			alt_up_pixel_buffer_dma_draw(my_pixel_buffer, (myimage[(i*320*3+j*3+2)]) + (myimage[(i*320*3+j*3+1)]<<8) + (myimage[(i*320*3+j*3+0)]<<16),j*f,i*f);
  	   		   }
  	   	   }

     }
     // check the key3 value. Remember key is on if it is zero and off it is one.
     else if(!key3){
  	   f = 2.0;
  		//Clear the screen (go to no.8 of software requirements in the assignment sheet)
  	   alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);

      	// Resize the image by 2 and display the image (go to no.10 of software requirements in the assignment sheet)
  	   for( int i = 0; i<240; i++){
  	   	   for( int j = 0; j< 320; j++){
  	   	   		alt_up_pixel_buffer_dma_draw(my_pixel_buffer, (myimage[(i*320*3+j*3+2)]) + (myimage[(i*320*3+j*3+1)]<<8) + (myimage[(i*320*3+j*3+0)]<<16),j*f,i*f);
  	   	   		}
  	   	   	 }
     }
     // check if all keys are off, print the message "Video message" on the console
     else {
  	   alt_putstr("Video message\n");
     }
    }
    return 0;
}
