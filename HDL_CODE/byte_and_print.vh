`ifndef BYTE_AND_PRINT_VH
`define BYTE_AND_PRINT_VH

// =====================================================
// Byte-wise assignment: BUS -> BYTE_ARRAY
// =====================================================
`define BYTE_ASSIGN_GEN(NAME, WIDTH, BUS, BYTE_ARRAY)                 \
  genvar NAME``_i;                                                    \
  generate                                                            \
    for (NAME``_i = 0; NAME``_i < (WIDTH); NAME``_i = NAME``_i + 1) begin: NAME``_gen \
      assign BYTE_ARRAY[NAME``_i] = BUS[8*NAME``_i + 7 : 8*NAME``_i]; \
    end                                                               \
  endgenerate


// =====================================================
// Print hex to transcript
// NOTE: requires integer i declared in TB
// =====================================================
`define PRINT_HEX_ARRAY(LABEL, BYTE_ARRAY, SIZE)                      \
  begin                                                               \
    $display("%s (hex)", LABEL);                                      \
    for (i = 0; i < (SIZE); i = i + 1) begin                          \
      $write("%02x ", BYTE_ARRAY[i]);                                 \
      if ((i % 68) == 67) $write("\n");                               \
    end                                                               \
    $write("\n");                                                     \
  end


// =====================================================
// Dump hex to file (MATCH C print_hex FORMAT EXACTLY)
// NOTE: requires integer i, fd declared in TB
// =====================================================
`define DUMP_HEX_FILE(FNAME, BYTE_ARRAY, SIZE)                        \
  begin                                                               \
    fd = $fopen(FNAME, "w");                                          \
    if (fd == 0) begin                                                \
      $display("ERROR: cannot open %s", FNAME);                       \
      $finish;                                                        \
    end                                                               \
    for (i = 0; i < (SIZE); i = i + 1) begin                          \
      $fwrite(fd, "%02x ", BYTE_ARRAY[i]);                            \
      if ((i % 52) == 51)                                             \
        $fwrite(fd, "\n");                                            \
    end                                                               \
    $fwrite(fd, "\n"); /* final blank line like C */                  \
    $fclose(fd);                                                      \
  end


`endif
