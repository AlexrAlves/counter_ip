`include "register_interface/typedef.svh"
`include "register_interface/assign.svh"

module counter_ip_top
    #(
      parameter int unsigned AXI_ADDR_WIDTH = 32,
      localparam int unsigned AXI_DATA_WIDTH = 32,
      parameter int unsigned AXI_ID_WIDTH,
      parameter int unsigned AXI_USER_WIDTH
      )
    (
     input logic clk_i,
     input logic rst_ni,
     input logic test_mode_i,

     AXI_BUS.Slave axi_slave
     );

    import counter_ip_reg_pkg::counter_ip_reg2hw_t;
    import counter_ip_reg_pkg::counter_ip_hw2reg_t;

    //Wiring Signals
    REG_BUS #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) axi_to_regfile();
    counter_ip_reg2hw_t reg_file_to_ip;
    counter_ip_hw2reg_t ip_to_reg_file;

    axi_to_reg_intf #(
                      .ADDR_WIDTH(AXI_ADDR_WIDTH),
                      .DATA_WIDTH(AXI_DATA_WIDTH),
                      .ID_WIDTH(AXI_ID_WIDTH),
                      .USER_WIDTH(AXI_USER_WIDTH),
                      .DECOUPLE_W(0)
    ) i_axi2reg (
                 .clk_i,
                 .rst_ni,
                 .testmode_i(test_mode_i),
                 .in(axi_slave),
                 .reg_o(axi_to_regfile)
    );

    //Convert the REG_BUS interface to the struct signals used by autogenerated register file
    typedef logic [AXI_ADDR_WIDTH-1:0] addr_t;
    typedef logic [AXI_DATA_WIDTH-1:0] data_t;
    typedef logic [AXI_DATA_WIDTH/8-1:0] strb_t;
    `REG_BUS_TYPEDEF_REQ(reg_req_t, addr_t, data_t, strb_t);
    `REG_BUS_TYPEDEF_RSP(reg_rsp_t, data_t);
    reg_req_t to_reg_file_req;
    reg_rsp_t from_reg_file_rsp;

    `REG_BUS_ASSIGN_TO_REQ(to_reg_file_req, axi_to_regfile);
    `REG_BUS_ASSIGN_FROM_RSP(axi_to_regfile, from_reg_file_rsp);

    counter_ip_reg_top #(
                         .reg_req_t(reg_req_t),
                         .reg_rsp_t(reg_rsp_t)
    ) i_regfile (
                 .clk_i,
                 .rst_ni,
                 .devmode_i(1'b1),

                 //From the protocol converters to regfile
                 .reg_req_i(to_reg_file_req),
                 .reg_rsp_o(from_reg_file_rsp),

                 //Signals to counter_ip IP
                 .reg2hw(reg_file_to_ip),
                 .hw2reg(ip_to_reg_file)
    );

    counter_ip #( 
                  .OUTPUT_WIDTH(16),
                  .IDATA_WIDTH(16)
    ) i_counter_ip (
                     .clk_i,
                     .reset(reg_file_to_ip.ctrl.reset.q),
                     .load(reg_file_to_ip.ctrl.load.q),
                     .enable(reg_file_to_ip.ctrl.en.q),
                     .data_in(reg_file_to_ip.dtin),
                     .count(ip_to_reg_file.ctout)
    );

endmodule : counter_ip_top