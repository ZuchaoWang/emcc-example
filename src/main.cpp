#include "mysqrt.h"
#include <iostream>

extern "C" {
    float mysqrtc(float a) {
        return mysqrt(a);
    }
}

int main() {
    std::cout<<mysqrtc(5)<<std::endl;
    return 0;
}