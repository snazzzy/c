#include <stdio.h>


typedef unsigned float_bits;


float_bits negate(float_bits f){
  printf("f %f\n",f);
  int mask = 128;
  mask = mask << 24;
  printf("mask : %i\n", mask);
  return f ^ mask;
}

float_bits absval(float_bits f){
  int mask = 128;
  mask = mask << 24;
  return (f | mask) ^ mask;
}

float_bits twice();

float_bits half();

float_bits class();

int main(int arc, char * argv[]){
  printf("%s\n", argv[1]);
  float_bits fbits;
  float *f;
  sscanf(argv[1], "%f", (float *)&fbits);
  fbits = negate(fbits);
  f = (float *)&fbits;
  printf("negate: %f\n", *f);

  fbits = absval(fbits);
  f = (float *)&fbits;
  printf("absval: %f\n", *f);
}
