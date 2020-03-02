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
    pcprintf("big endian: %d\n", is_big_endian());
}

/*		Big Endian
	a[]  0   1   2   3
	   0x1 0x2 0x3 0x4
	   
	     Little Endian
	a[]  0   1   2   3
	   0x4 0x3 0x2 0x1
*/
