module test (
	// inputs of top level design
	input CLOCK_50,
	input reset
);

	nios_system u0 (
		.clk_clk			(CLOCK_50),
		.reset_reset_n	(reset)
	);
	
	endmodule
	