module spi_controller (
    input clk,
    input rst,
    input start,
    input [7:0] tx_data,
    input miso,
    output logic sclk,
    output mosi,
    output cs_n,
    output [7:0] rx_data,
    output done
);
logic [4:0]div_cnt;
always @(posedge clk) begin
    if (div_cnt == 19) begin
        div_cnt <= 0;
        sclk <= ~sclk;
    end else
        div_cnt <= div_cnt +1; 
end
endmodule