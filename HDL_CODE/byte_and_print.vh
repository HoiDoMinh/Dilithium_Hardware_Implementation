`ifndef BYTE_AND_PRINT_VH
`define BYTE_AND_PRINT_VH

// Macro: Byte-wise assignment using generate
`define BYTE_ASSIGN_GEN(NAME, WIDTH, BUS, BYTE_ARRAY)           \
  genvar NAME``_i;                                              \
  generate                                                      \
    for (NAME``_i = 0; NAME``_i < (WIDTH); NAME``_i = NAME``_i + 1) begin: NAME``_gen \
      assign BYTE_ARRAY[NAME``_i] = BUS[8*NAME``_i + 7 : 8*NAME``_i]; \
    end                                                         \
  endgenerate

// Macro: Print hex bytes
`define PRINT_HEX_ARRAY(LABEL, BYTE_ARRAY, SIZE)                \
  $display("%s (hex)", LABEL);                                  \
  for (i = 0; i < (SIZE); i = i + 1) begin                      \
      $write("%02x ", BYTE_ARRAY[i]);                           \
      if ((i % 68) == 67) $write("\n");                         \
  end                                                           \
  $write("\n");

`endif
