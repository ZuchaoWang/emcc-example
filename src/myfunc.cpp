#include <cmath>

float mysqrt(float a) {
    return sqrt(a);
}

void mysqrtArray(int n, float* a, float* b) {
    int i;
    for (i = 0; i < n; i++) {
        b[i] = sqrt(a[i]);
    }
}