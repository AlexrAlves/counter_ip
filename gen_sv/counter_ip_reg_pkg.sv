// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Register Package auto-generated by `reggen` containing data structure

package counter_ip_reg_pkg;

  ////////////////////////////
  // Typedefs for registers //
  ////////////////////////////
  typedef struct packed {
    logic [15:0] q;
  } counter_ip_reg2hw_dtin_reg_t;

  typedef struct packed {
    struct packed {
      logic        q;
    } reset;
    struct packed {
      logic        q;
    } load;
    struct packed {
      logic        q;
    } en;
  } counter_ip_reg2hw_ctrl_reg_t;


  typedef struct packed {
    logic [15:0] d;
  } counter_ip_hw2reg_ctout_reg_t;


  ///////////////////////////////////////
  // Register to internal design logic //
  ///////////////////////////////////////
  typedef struct packed {
    counter_ip_reg2hw_dtin_reg_t dtin; // [19:4]
    counter_ip_reg2hw_ctrl_reg_t ctrl; // [3:1]
  } counter_ip_reg2hw_t;

  ///////////////////////////////////////
  // Internal design logic to register //
  ///////////////////////////////////////
  typedef struct packed {
    counter_ip_hw2reg_ctout_reg_t ctout; // [16:17]
  } counter_ip_hw2reg_t;

  // Register Address
  parameter logic [3:0] COUNTER_IP_DTIN_OFFSET = 4'h 0;
  parameter logic [3:0] COUNTER_IP_CTOUT_OFFSET = 4'h 4;
  parameter logic [3:0] COUNTER_IP_CTRL_OFFSET = 4'h 8;


  // Register Index
  typedef enum int {
    COUNTER_IP_DTIN,
    COUNTER_IP_CTOUT,
    COUNTER_IP_CTRL
  } counter_ip_id_e;

  // Register width information to check illegal writes
  parameter logic [3:0] COUNTER_IP_PERMIT [3] = '{
    4'b 0011, // index[0] COUNTER_IP_DTIN
    4'b 0011, // index[1] COUNTER_IP_CTOUT
    4'b 0001  // index[2] COUNTER_IP_CTRL
  };
endpackage

