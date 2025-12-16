`timescale 1ns/1ps
`include "byte_and_print.vh"   // include macro

module tb_poly_uniform_gamma1;

    reg clock = 0;
    reg reset = 1;
    reg start = 0;

    reg  [511:0] seed;
    reg  [15:0]  nonce;

    wire [8191:0] a_out;

    // 8192-bit output = 1024 bytes
    wire [7:0] a_out_bytes [0:1023];

    wire done;

    always #5 clock = ~clock;

    poly_uniform_gamma1 dut(
        .clock(clock),
        .reset(reset),
        .start(start),
        .seed(seed),
        .nonce(nonce),
        .a_out(a_out),
        .done(done)
    );

    integer i;
    `BYTE_ASSIGN_GEN(AOUT, 1024, a_out, a_out_bytes)

    initial begin
        
        reset = 1;
	start =0;
	

        // giá tr? seed ví d?
        seed =
        //512'h4de186f6b7da92eb4f93dcd9cbf2d40d221cc1c29a0931bf3bf01ad2bff55fe454a15c8085a46622ad2d0a5e8bd9662108f6b161e77ececf853cab3bf0a03d4a;
	//512'h7ae1cb8932d135ba7a95ddd8d312dfbce68e6799a1a8f7c51e3511dabfaa7395708008d0decc18ccce443ff6bfed0746dd0eede89c4fcc5c0da38f315773b393;
	//512'h5d670b7261955177315bf6340438c2da5c4f5a19348332cd328b833255a689c5d2511fa2e4850f5a7bbf194777b9fdd527f6b0e7db669c62dfc860636d5691a8;
        //512'hbde2c071e2bd19eeff5323cfd2251f1193cee284588213ceb8edd778376c976fa75b3fced8c7464af11f9da38172183f72832793f901d0717885b6237f27fb15;
	//512'h0764d277da65be55a2bde33c689eb863f145de7780ec5c6a25cc2161238ed45b14ed584fab6022b60410f2c4019dbd21089796fe974e586b24f0b1120909346a;
	512'h73c099445665ec86c3e82b4eea45ad9f71e96eee3101c7235114444134c1c418d1c385c286ed7591dea73d0bdf3028a49df6ef266d6df1046446e5a21a170d06;

        nonce = 16'd123;

        #20 reset = 0;
        #20 start = 1;
        

        wait(done);
        #20;

        $display("=== OUTPUT POLY (8192 BYTES) ===");

        // In 1024 byte (8192 bit)
        `PRINT_HEX_ARRAY("a_out", a_out_bytes, 1024)
        #10 start = 0;
        $finish;
    end
    // Timeout
    initial begin
        #200000;
        $display("\n[ERROR] SIMULATION TIMEOUT!\n");
        $finish;
    end

endmodule

