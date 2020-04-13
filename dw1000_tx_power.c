#include<stdio.h>
#include<inttypes.h>
const float da_offset = -3;
float mixer_value = 0;
float da_value = 18;


float mixer_arrary[40] = {0};
float da_arrary[40] = {0};

char bin[33] = {0};

void to_binary(int n, int bit){
    for (int c = bit-1; c >= 0; c--)
      {
        int k = n >> c;
        bin[bit-c-1] = (k&1) + '0';
      }
    bin[bit] = '\0';

    printf("%s\n", bin);
}

void calc_mixer(){
    for(int i = 0; i < 32; i++){
        mixer_arrary[i] = i * 0.5;
    }
}

void calc_da(){
    for(int i = 0; i < 7; i++){
        da_arrary[i] = da_value;
        da_value += da_offset;
    }
}

void mix_gain(int da_id){
    uint8_t Hi = da_id << 5;
    uint8_t mix = 0;

    to_binary(da_id, 3);
    for(int i = 0; i < 32; i++){
        if(i!=0 && i%4 ==0){
            puts("");
        }
        mix = Hi | i;
        printf("0x%02x %4.1f\t", mix, da_arrary[da_id] + mixer_arrary[i]);

    }
}

int main(){

    calc_mixer();
    calc_da();
    for(int i = 0; i < 8; i++){
        mix_gain(i);
         puts("\n");
    }

    return 0;
}
