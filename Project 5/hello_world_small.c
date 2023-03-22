// p5
#include "sys/alt_stdio.h"
#include "sys/alt_driver.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include <math.h>
#include "myfile.h"
#include <stdio.h>
//#include <altera_avalon_performance_counter.h>
#include <sys/alt_alarm.h>
#include <altera_avalon_mutex.h>
#include <io.h>

// add the pixel buffer dma as shown in no.5 of the software requirements in the assignment sheet
#include <altera_up_avalon_video_pixel_buffer_dma.h>

double theta;
double shifted_row;
double shifted_col;
double original_row, original_col;
alt_up_pixel_buffer_dma_dev *my_pixel_buffer;

void frame_function (){

	// frame code
	// for loop that rotates over image rows
	for (int i = 0; i < 240; i+=2) {
	// for loop that rotates over image cols
		for (int j = 0; j < 320; j++){
			pixel_code(i,j);
		}
	}

	// End frame code
}

void pixel_code (int i, int j){
	 shifted_row = i-240/2;
	// calculate shifted_col
	shifted_col = j - 320/2;
	// calculate original_row
	original_row = round ((shifted_row*cos(theta) - shifted_col*sin(theta)) + 240/2);
	//calculate original_col
	original_col = round ((shifted_row*sin(theta) + shifted_col*cos(theta)) + 320/2);
	// check if the image is out of boundary
	if ((i>=240) || (j>=320) || (i<0) || (j<0)) {
	// if original_row is out of bound
	 if (original_row >= 0 && original_row < 1)
			// set i to 0
			 i = 0;
			// if original_col is out of bound
	if (original_col >=0 && original_col < 1)
			// set j to 0
			 j = 0;
		}
			// display the image based on the values of original_row and original_col
		alt_up_pixel_buffer_dma_draw(my_pixel_buffer,
		 (myimage[(i*320*3+j*3+2)]) +
		 (myimage[(i*320*3+j*3+1)]<<8) +
		 (myimage[(i*320*3+j*3+0)]<<16),original_col,original_row);

}

/*void barrier () {

// counters are declared as pointer to point to the onchip locations
// That means updated these locations will be using this pointer

volatile alt_u32 *counters = 0x20000;

int i,count;
alt_mutex_dev *my_mutex;
alt_u32 cpuid;
cpuid = ALT_CPU_CPU_ID_VALUE; // or  __builtin_rdctl(5);

my_mutex = altera_avalon_mutex_open("/dev/mutex_0");

if (!my_mutex) {
alt_printf("error opening mutex");
return;
}
for (i=0;i<2;i++) {
if (i!=cpuid) {
altera_avalon_mutex_lock(my_mutex, 1);

// to read the counter value from the onchip memory
count = IORD_32DIRECT(&counters[i],0);
count++;

// to write the new counter value to the onchip memory
IOWR_32DIRECT(&counters[i],0,count);
altera_avalon_mutex_unlock(my_mutex);
}
}
do {
	// processor keeps checking if its counter is incremented by any other cpus
	count = IORD_32DIRECT(&counters[cpuid],0);
} while (count != 2-1);

	// if the cpu counter is incremented, the operation resumes
	altera_avalon_mutex_lock(my_mutex, 1);
	IOWR_32DIRECT(&counters[cpuid],0,0);
	altera_avalon_mutex_unlock(my_mutex);
	altera_avalon_mutex_close(my_mutex);
}
*/

int main()
{

    my_pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/dma_buffer");

    // Check if the pixel array contains the image (go to no.7 of software requirements in the assignment sheet)
    if(!my_pixel_buffer) printf("Error opening pixel buffer\n");

   // Clear the screen (go to no.8 of software requirements in the assignment sheet)
    alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
    int ticks_per_second, ticks_start, ticks_end, frame_ticks;
    unsigned long long duration;


    while(1) {
    	for (int t = 0; t > -360; t = t-90) {
    		// calculate theta
    		theta = (t*3.14)/180;
    		alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
    		ticks_per_second = alt_ticks_per_second();
    		ticks_start = alt_nticks();
    		frame_function();
    		ticks_end = alt_nticks();
    		frame_ticks = ticks_end - ticks_start;
    		duration= (unsigned long long) frame_ticks / (unsigned long long) ticks_per_second;
    		printf("Total duration %llu seconds \n\n", duration);
    		}
    	}

    	return 0;
}
