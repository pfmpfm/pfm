module top(
input clk, reset_n, ps2_clk, ps2_data,
output reg [7:0] seg1, seg2, seg3, seg4, seg5, seg6,
output reg [1:0] led_output);

reg [7:0] data_reg, ascii_out_reg;
reg ovf_flag, data_ready, nextdata_flag;
wire data_ready_p1, data_ready_p2;
reg data_ready_d1, data_ready_d2;
reg [7:0] key_val;
reg [7:0] key_cnt;
reg [2:0] key_state, key_state_next;
reg [7:0] data_d1;
reg [7:0] seg_data0;
reg [7:0] seg_data2;

// 键的三种状态：按下，松开和按下后的松开
parameter [2:0] KEY_PRESS = 3'b100, KEY_RELEASE = 3'b010, KEY_RELEASED_PREVIOUS = 3'b001;

always @(*) begin // 按键值和次数赋值
    seg_data0 = key_val;
    seg_data2 = key_cnt;
end

ps2_keyboard ps2_key (.clk(clk), .clrn(clk), .ps2_clk(ps2_clk), .ps2_data(ps2_data), .data(data_reg), .nextdata_n(nextdata_flag), .ready(data_ready), .overflow(ovf_flag));

assign data_ready_p1 = data_ready & !data_ready_d1;  // 记录ready信号的变化状态 - 第一阶段
assign data_ready_p2 = data_ready_d1 & !data_ready_d2; // 第二阶段

always @(posedge clk or posedge reset_n) begin // 两级触发器存储ready信号
    if (reset_n) begin 
        data_ready_d1 <= 1'd0;
        data_ready_d2 <= 1'b0;
    end
    else begin
        data_ready_d1 <= data_ready;
        data_ready_d2 <= data_ready_d1;
    end
end

always @(posedge clk or posedge reset_n) begin
    if (reset_n) begin
        data_d1 <= 8'b0;
        nextdata_flag <= 1'b1;
    end
    else if (data_ready_p1) begin //第一阶段有效
        nextdata_flag <= 1'b0;  //继续输入下一数据
        data_d1 <= data_reg;    //data赋值给data_d1
    end
    else begin
        data_d1 <= 8'b0;        
        nextdata_flag <= 1'b1;  //不需要读取下一数据
    end
end

always @(posedge clk or posedge reset_n) begin // 状态转换
    if (reset_n) key_state <= KEY_RELEASE;
    else key_state <= key_state_next;  //更新状态机的状态
end 

always @(negedge clk or posedge reset_n) begin
    if (reset_n) begin
        key_cnt <= 8'b0;
        key_val <= 8'b0;
        key_state_next <= KEY_RELEASE;
    end
    else if (data_ready_p2) begin  //第二阶段有效
        case (key_state)
            KEY_RELEASE: begin
                if (data_d1 == key_val) begin // 保持原状态	
                    key_val <= key_val;
                    key_state_next <= key_state;
                    key_cnt <= key_cnt;
                end
                else begin // 按下
                    key_val <= data_d1;
                    key_state_next <= KEY_PRESS;
                    key_cnt <= key_cnt;
                end
            end
            KEY_PRESS: begin 
                if (data_d1 == 8'hf0) begin // 按键按下
                    key_val <= key_val;
                    key_state_next <= KEY_RELEASED_PREVIOUS;
                    key_cnt <= key_cnt + 1'b1;
                end
                else if (data_d1 == key_val) begin
                    key_val <= key_val;
                    key_state_next <= KEY_PRESS;
                    key_cnt <= key_cnt;
                end
                else begin
                    key_val <= 8'h00;
                    key_state_next <= KEY_RELEASE;
                    key_cnt <= 8'b0;
                end
            end
            KEY_RELEASED_PREVIOUS: begin
                if (data_d1 == key_val) begin
                    key_val <= 8'h00;
                    key_state_next <= KEY_RELEASE;
                    key_cnt <= key_cnt;
                end
                else begin 
                    key_val <= 8'b0;
                    key_state_next <= KEY_RELEASE;
                    key_cnt <= key_cnt;
                end
            end
            default: begin
                key_val <= 8'b0;
                key_state_next <= key_state;
                key_cnt <= key_cnt;
            end
        endcase
    end
    else begin
        key_cnt <= key_cnt;
        key_val <= key_val;
        case (key_state)
            KEY_RELEASE: key_state_next <= KEY_RELEASE;
            KEY_PRESS: key_state_next <= KEY_PRESS;
            KEY_RELEASED_PREVIOUS: key_state_next <= KEY_RELEASED_PREVIOUS;
            default: key_state_next <= KEY_RELEASE;
        endcase
    end
end

// 显示编码
seg seg1_inst (.x(seg_data0[3:0]), .y(seg1));
seg seg2_inst (.x(seg_data0[7:4]), .y(seg2));

ps2_keyboard_decoder ps2_dec (.data(data_reg), .clk(clk), .ascout(ascii_out_reg));

// ASCII显示
seg seg3_inst (.x(ascii_out_reg[3:0]), .y(seg3));
seg seg4_inst (.x(ascii_out_reg[7:4]), .y(seg4));
// 计数器
seg seg5_inst (.x(seg_data2[3:0]), .y(seg5));
seg seg6_inst (.x(seg_data2[7:4]), .y(seg6));

assign led_output = {data_ready, ovf_flag};

endmodule

