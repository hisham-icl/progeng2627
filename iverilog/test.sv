//SystemVerilog
// when red, amber or green are high the corresponding traffic light turns on and when they are low it turns or remains off
module trafficlightcontroller(
input clk,
 input reset,
 output red,
  output amber,
  output green
);
logic red;
logic amber;
logic green
//cycle number out of 4
logic [1:0]cyclenum
always_ff @(posedge clk) begin
  //if reset is high send to cycle 0 and set cyclenum to 0
  if (reset) begin
    red <= 1;
    amber <= 0;
    green <= 0;
    cyclenum <= 2'b00;
  end
  //first cycle only red
  if (cyclenum==2'b00)
    red <= 1;
    amber <=0;
    green <= 0;
  //second cycle red and amber
  else if (cyclenum == 2'b01)
    amber <= 1;
    red <= 1;
    green <= 0;
  //third cycle only green
  else if (cyclenum == 2'b10)
    amber<= 0;
    red <= 0;
    green <= 1;
  //fourth cycle only amber
  else if (cyclenum == 2'b11)
     amber <=1;
     red <= 0;
     green <= 0;
   //if its not at cycle 4, increment cycle number
   if (cyclenum !=2'b11)
       cyclenum++;
   //if it is cycle 4 send it to cycle 0
   else
       cyclenum <= 2'b00;
endmodule
       
          
     
  
    
    
  