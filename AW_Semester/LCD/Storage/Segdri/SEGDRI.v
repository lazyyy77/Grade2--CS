`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:00:26 06/23/2023 
// Design Name: 
// Module Name:    SEGDRI 
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
module SEGDRI(
	input wire clk,
    input wire [31:0]num,
	output wire SEG_CLK, SEG_OUT
);

    wire [63:0]seg;
	 //wire [31:0]clk_div;
	 reg [63:0]Q;
    //wire finish, S_L;
	reg [5:0]count;
	reg finish;
	reg OUT;
	//assign finish = &Q;
	assign SEG_CLK = clk | finish;
    //Q[1] & Q[2] & Q[3] & Q[4] & Q[5] & Q[6] & Q[7] & Q[8] & Q[9] & Q[10] & Q[11] & Q[12] & Q[13] & Q[14] & Q[15] & Q[16] & Q[17] & Q[18] & Q[19] & Q[20] & Q[21] & Q[22] & Q[23] & Q[24] & Q[25] & Q[26] & Q[27] & Q[28] & Q[29] & Q[30] & Q[31] & Q[32] & Q[33] & Q[34] & Q[35] & Q[36] & Q[37] & Q[38] & Q[39] & Q[40] & Q[41] & Q[42] & Q[43] & Q[44] & Q[45] & Q[46] & Q[47] & Q[48] & Q[49] & Q[50] & Q[51] & Q[52] & Q[53] & Q[54] & Q[55] & Q[56] & Q[57] & Q[58] & Q[59] & Q[60] & Q[61] & Q[62] & Q[63] & Q[64];
	assign SEG_OUT = OUT;

	//clkdiv m_clk(clk, 1'b0, clk_div);
	 
	 Load_Seg m_lg(clk, start);


    MC_Decoder m_mcd7(num[ 3: 0], 1'b0, 1'b0, seg[63:56]);
    MC_Decoder m_mcd6(num[ 7: 4], 1'b0, 1'b0, seg[55:48]);
    MC_Decoder m_mcd5(num[11: 8], 1'b0, 1'b0, seg[47:40]);
    MC_Decoder m_mcd4(num[15:12], 1'b0, 1'b0, seg[39:32]);
    MC_Decoder m_mcd3(num[19:16], 1'b0, 1'b0, seg[31:24]);
    MC_Decoder m_mcd2(num[23:20], 1'b0, 1'b0, seg[23:16]);
    MC_Decoder m_mcd1(num[27:24], 1'b0, 1'b0, seg[15: 8]);
    MC_Decoder m_mcd0(num[31:28], 1'b0, 1'b0, seg[ 7: 0]);

	always @ (posedge clk) begin
		if (start) begin
			count <= 6'b111111;
			OUT <= seg[0];
			Q <= {1'b0, seg[63:1]};
			finish <= 0;
		end else begin
			if (~finish) begin
				OUT <= Q[0];
				Q <= {1'b1, Q[63:1]};
				if (count == 6'b0) begin
					finish <= 1;
				end else begin
					count <= count - 1;
				end
			end
		end
	end
	
	
endmodule
