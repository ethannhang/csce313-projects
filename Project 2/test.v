module test (
	// inputs of the top-level-design 
	input CLOCK_50, 		   // clock
	input [3:0] KEY,			// reset 
	input [4:0] SW,
	output [15:0] LEDR, 
	output [7:0] LEDG
	
);
	
	nios_system u0 (
		
		.clk_clk        (CLOCK_50),        //     clk.clk
		.doutput_export (LEDG), // doutput.export
		.dinput_export  (SW[4:2]),  //  dinput.export
		.reset_reset_n  (KEY[0]),  //   reset.reset_n
		.counter_export (LEDR[7:0]), // counter.export
		.modes_export (SW[1:0]), // modes_1.export
		.pattern_export (LEDR[15:8])  // pattern.export
	);

	
	endmodule 