#include "myfunc.h"
#include <iostream>

extern "C" {
    float mysqrtC(float a) {
        return mysqrt(a);
    }
    
    void mysqrtArrayC(int n, float* a, float* b) {
        mysqrtArray(n, a, b);
    }
}

int main() {
    std::cout<<mysqrtC(5)<<std::endl;
    
    float a[7], b[7];
    for(int i=0; i<7; i++) {
        a[i] = i;
    }
    mysqrtArrayC(7, a, b);
    for(int i=0; i<7; i++) {
        std::cout<<b[i];
        if(i==7-1) {
            std::cout<<std::endl;
        } else {
            std::cout<<", ";
        }
    }
    
    return 0;
}