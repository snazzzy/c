int main() {
//part2
  int array[13];
  array[13] = 0; //g
  array[12] = 23; //a
  array[11] = 19; //b
  array[10] = 12; //c
  array[7] = 3; //e
  array[6] = 1; //f
  array[8] = 2; //d

   array[13] = array[12] * array[8] // + array[13];
   array[13] = array[11] * array[7];
   array[13] = array[10] * array[6];

  //array[13] += ((array[12] * array[8])) + ((array[11] * array[7])) + ((array[10] * array[6]));
}
