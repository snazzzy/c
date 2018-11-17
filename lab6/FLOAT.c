#include <stdio.h>

typedef unsigned float_bits;

float_bits negate(float_bits f){
  //create a mask that affects the signed bit
  int mask = 128 << 24;
  //xor the signed bit against the signed bit
  return f ^ mask;
}

float_bits absval(float_bits f){
  //create a mask that affects the signed bit
  int mask = 128 << 24;
  //xor and or against the signed bit
  return (f | mask) ^ mask;
}

float_bits twice(float_bits f){
	//generate a mask of 1s to capture the exponent 
	int mask = 255 << 23;
	int res = 0;
	//capture the exponent and store it in res
	res = f & mask;
	res = res >> 23;
	//double the res
	res++;
	//shift it back 
	res = res << 23;
	//zero out f for read in
	f = f & ~mask;
	return f | res;
}

float_bits half(float_bits f){
	//generate a mask of 1s to capture the exponent 
	int mask = 255 << 23;
	int res = 0;
	//capture the exponent and store it in res
	res = f & mask;
	res = res >> 23;
	//divide the res
	res--;
	res = res << 23;
	//zero out f for read in
	f = f & ~mask;
	return f | res;
}

float_bits class();

int main(int arc, char * argv[]){
  //declares fbits and fbits1
  float_bits fbits, fbits1;
  float *f;
  //grabs the float out of standard input
  sscanf(argv[1], "%f", (float *)&fbits);
  //calls function
  fbits1 = negate(fbits);
  f = (float *)&fbits;
  printf("negate: %f\n", *f);
  //calls the function and stores it
  fbits1 = absval(fbits);
  //casts float into f
  f = (float *)&fbits1;
  printf("absval: %f\n", *f);
  //calls the function and stores it
  fbits1 = twice(fbits);
  //casts float into f
  f = (float *)&fbits1;
  printf("twice: %f\n", *f);
    //calls the function and stores it
  fbits1 = half(fbits);
  //casts float into f
  f = (float *)&fbits1;
  printf("half: %f\n", *f);
}
