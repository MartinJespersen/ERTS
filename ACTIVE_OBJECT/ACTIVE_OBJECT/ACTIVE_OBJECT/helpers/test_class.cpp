#include "test_class.h"
#include <iostream>
test_class::test_class(int n){
    number = n;
}

void test_class::print(){
    std::cout<<number<<std::endl;
}