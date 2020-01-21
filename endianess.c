#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

bool is_big_endian(void)
{
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01020304};

    return bint.c[0] == 1; 
}

int main(){
	printf("big endian: %d\n", is_big_endian());
}
