`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:38:15 10/30/2023 
// Design Name: 
// Module Name:    Register4b 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Register4b(
	input wire clk,
	input wire [3:0]IN,
	input wire Load,
	output reg [3:0]OUT
    );
	
	always @ (posedge clk) begin
		if (Load) OUT <= IN;
	end
	
	

endmodule
