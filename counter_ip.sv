module counter_ip
  #(
   parameter OUTPUT_WIDTH = 16,
   parameter IDATA_WIDTH = 16
  )(
    input logic clk,
    input logic reset,
    input logic load,
    input logic enable, 
    input logic [IDATA_WIDTH - 1:0] data_in,
    output logic [OUTPUT_WIDTH - 1:0] count
  );
  
  //always block will be executed at each and every positive edge of the clock
  always_ff@(posedge clk) 
  begin
    if(reset == 1 || count == '1) begin    //Set Counter to Zero
      count <= '0;
    end
    else if(load) begin    //load the counter with data value
      count <= data_in;
    end
    else if(enable) begin      //count up
      count <= count + 1;
  	end
    else begin
      count <= count;
    end
  end
endmodule : counter_ip