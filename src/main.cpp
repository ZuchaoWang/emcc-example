#include "myfunc.h"
#include "myclass.h"
#include <iostream>

extern "C" {
    float mysqrtC(float a) {
        return mysqrt(a);
    }
    
    void mysqrtArrayC(int n, float* a, float* b) {
        mysqrtArray(n, a, b);
    }
    
    int createMyClassC() {
        return createMyClass();
    }
    
    void deleteMyClassC(int _id) {
        deleteMyClass(_id);
    }
    
    void setMyClassValueC(int _id, float _x) {
        setMyClassValue(_id, _x);
    }
    
    float getMyClassAnswerC(int _id) {
        return getMyClassAnswer(_id);
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
    
    int handler = createMyClassC();
    setMyClassValueC(handler, 10);
    std::cout<<getMyClassAnswerC(handler)<<std::endl;
    deleteMyClassC(handler);
    
    return 0;
}