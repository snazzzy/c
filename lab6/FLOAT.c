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

float_bits twice(float_bits f){
	int mask = 255 << 23;
	int res = 0;
	res = f & mask;
	printf("res : %d\n", res);
	res = res >> 23;
	printf("res : %d\n", res);
	res++;
	res = res << 23;
	printf("res : %d\n", res);
	f = f & ~mask;
	return f | res;
}

float_bits half(float_bits f){
	int mask = 255 << 23;
	int res = 0;
	res = f & mask;
	printf("res : %d\n", res);
	res = res >> 23;
	printf("res : %d\n", res);
	res--;
	printf("res : %d\n", res);
	res = res << 23;
	printf("res : %d\n", res);
	f = f & ~mask;
	return f | res;
}

float_bits class();

int main(int arc, char * argv[]){
  printf("%s\n", argv[1]);
  float_bits fbits, fbits1;
  float *f;
  sscanf(argv[1], "%f", (float *)&fbits);
  fbits1 = negate(fbits);
  f = (float *)&fbits;
  printf("negate: %f\n", *f);
  
  fbits1 = absval(fbits);
  f = (float *)&fbits1;
  printf("absval: %f\n", *f);

  fbits1 = twice(fbits);
  f = (float *)&fbits1;
  printf("twice: %f\n", *f);
  
  fbits1 = half(fbits);
  f = (float *)&fbits1;
  printf("half: %f\n", *f);

}
