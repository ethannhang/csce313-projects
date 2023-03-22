module test (
	 
	input CLOCK_50, 		   
	input [3:0] KEY,			
	input [4:0] SW,
	output [7:0] HEX0,		// First 7-segment 
	output [7:0] HEX1,		// Second 7-segment 
	output [7:0] HEX2,		// Third 7-segment 
	output [7:0] HEX3,		// Fourth 7-segment 
	output [7:0] HEX4,		// Fifth 7-segment 
	output [7:0] HEX5,		// Sixth 7-segment 
	output [7:0] HEX6,		// Seventh 7-segment 
	output [7:0] HEX7			// Eight 7-segment 
	

	
);
	
	
	nios_system_p3 u0 (
		.clk_clk       (CLOCK_50),       //    clk.clk
		.rotation_export (SW[4:2]), // dinput.export
		.modes_export  (SW[1:0]),  //  modes.export
		.reset_reset_n (KEY[0]), //  reset.reset_n
		.seg0_export   (HEX0),   //   seg0.export
		.seg1_export   (HEX1),   //   seg1.export
		.seg2_export   (HEX2),   //   seg2.export
		.seg3_export   (HEX3),   //   seg3.export
		.seg4_export   (HEX4),    //   seg4.export
		.seg5_export   (HEX5),   //   seg7.export
		.seg6_export   (HEX6),   //   seg6.export
		.seg7_export   (HEX7)   //   seg5.export
		
	);

	
	endmodule 