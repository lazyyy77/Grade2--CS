`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:35:28 12/19/2023 
// Design Name: 
// Module Name:    ShiftReg8b 
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
module ShiftReg8b(
	input wire clk, S_IN, S_L,
	input wire [7:0] P_IN,
	output wire [7:0] Q
    );

	ShiftReg1b reg7(.clk(clk), .S_L(S_L), .S_IN(S_IN), .P_IN(P_IN[7]), .R_(1'b1), .S_(1'b1), .Q(Q[7]));
	ShiftReg1b reg6(.clk(clk), .S_L(S_L), .S_IN(Q[7]), .P_IN(P_IN[6]), .R_(1'b1), .S_(1'b1), .Q(Q[6]));
	ShiftReg1b reg5(.clk(clk), .S_L(S_L), .S_IN(Q[6]), .P_IN(P_IN[5]), .R_(1'b1), .S_(1'b1), .Q(Q[5]));
	ShiftReg1b reg4(.clk(clk), .S_L(S_L), .S_IN(Q[5]), .P_IN(P_IN[4]), .R_(1'b1), .S_(1'b1), .Q(Q[4]));
	ShiftReg1b reg3(.clk(clk), .S_L(S_L), .S_IN(Q[4]), .P_IN(P_IN[3]), .R_(1'b1), .S_(1'b1), .Q(Q[3]));
	ShiftReg1b reg2(.clk(clk), .S_L(S_L), .S_IN(Q[3]), .P_IN(P_IN[2]), .R_(1'b1), .S_(1'b1), .Q(Q[2]));
	ShiftReg1b reg1(.clk(clk), .S_L(S_L), .S_IN(Q[2]), .P_IN(P_IN[1]), .R_(1'b1), .S_(1'b1), .Q(Q[1]));
	ShiftReg1b reg0(.clk(clk), .S_L(S_L), .S_IN(Q[1]), .P_IN(P_IN[0]), .R_(1'b1), .S_(1'b1), .Q(Q[0]));

endmodule
