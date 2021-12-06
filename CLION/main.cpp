#include "headers/proxy.h"

int main() {
    proxy px(10); 

    message_future mr_sw = px.execute_pos_sw(); 
    message_future mr_hw = px.execute_pos_hw(); 

    message ms_sw = mr_sw.result(10); 
    message ms_hw = mr_hw.result(10); 

    ms_sw.print(); 
    ms_hw.print(); 

    return 0; 
}