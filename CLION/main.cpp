#include "headers/proxy.h"

int main() {
    proxy px(10); 

    message_future mr_sw = px.execute_pos_sw(); 
    message_future mr_hw = px.execute_pos_hw(); 

    message ms_sw = mr_sw.result(3);
    message ms_hw = mr_hw.result(3);

    ms_sw.print(); 
    ms_hw.print();

    px.join();
    return 0; 
}