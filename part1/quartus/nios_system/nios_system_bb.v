
module nios_system (
	button_export,
	clk_clk,
	leds_export,
	reset_reset_n);	

	input		button_export;
	input		clk_clk;
	output	[7:0]	leds_export;
	input		reset_reset_n;
endmodule
