#include<stdio.h>
#include<inttypes.h>

char bin[33] = {0};

void to_binary(int n, int bit){
    memset(bin, 0, sizeof(bin));
    for (int c = bit-1; c >= 0; c--)
      {
        int k = n >> c;
        bin[bit-c-1] = (k&1) + '0';
      }
    bin[bit] = '\0';

    printf("%s\n", bin);
}

int main(){
    to_binary(7, 3);
    to_binary(254, 8);
    to_binary(0xA, 8);
}
