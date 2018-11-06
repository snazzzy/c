
#include <stdio.h>
#include <string.h>
# define MAX_LINE 50
//github test
//work please


int main(int arc, char *argv[]){
	//Defines input
	if(arc < 1){
		printf("feed into .txt");
		return 0;
	}
	//all 32 registers
	char *registers[32][2];
	registers[0][0] = "$zero";
	registers[1][0] = "$at";
	registers[2][0] = "$at";
	registers[3][0] = "$v0";
	registers[4][0] = "$v1";
	registers[5][0] = "$a0";
	registers[6][0] = "$a1";
	registers[7][0] = "$a2";
	registers[8][0] = "$a3";
	registers[9][0] = "$t0";
	registers[10][0] = "$t1";
	registers[11][0] = "$t2";
	registers[12][0] = "$t3";
	registers[13][0] = "$t4";
	registers[14][0] = "$t5";
	registers[15][0] = "$t6";
	registers[16][0] = "$t7";
	registers[17][0] = "$s0";
	registers[18][0] = "$s1";
	registers[19][0] = "$s2";
	registers[20][0] = "$s3";
	registers[21][0] = "$s4";
	registers[22][0] = "$s5";
	registers[23][0] = "$s6";
	registers[24][0] = "$s7";
	registers[25][0] = "$t8";
	registers[26][0] = "$t9";
	registers[27][0] = "$k0";
	registers[28][0] = "$k1";
	registers[29][0] = "$gp";
	registers[30][0] = "$sp";
	registers[31][0] = "$fp";
	//this is the value I load into the registers
	char place[] = {'0', '\0'};
	//here I load zero into the 2nd dem.
	for(int i = 0; i < 32; i++){
		//printf("%i ", i);
		sscanf(place, "%s", &registers[i][1]);
	}
	//Prep for reading file into memory
	char *memory[40][5];
	char line[MAX_LINE];
	FILE *fp = fopen("mips.txt", "r");
	char *temp;
	int counter = 0;
	//grabes a line, and uses sscan to input arguments into memory
	while(fgets(line, 40, fp)){

		if(sscanf(line, " %40[^, ^\t], %40[^, ^\t], %40[^,^\t], %40[^,^\t], %s ", &memory[counter][0], &memory[counter][1], &memory[counter][2], &memory[counter][3], &memory[counter][4])){
			counter++;
		}

	}
	fclose(fp);
	//These instructions are to start the compare statements
	char instruction1[] = {'a', 'd', 'd', 'i', '\0'};
	char instruction2[] = {'s', 'u', 'b', '\0'};
	char instruction3[] = {'j','\0'};
	char instruction4[] = {'s','l','l','\0'};
	char instruction5[] = {'b','n','e','\0'};
	int addi1 = 0;
	int addi2 = 0;
	int addi3 = 0;
	int sub1 = 0;
	int sub2 = 0;
	int sub3 = 0;
	int sub4 = 0;
	int j1 = 0;
	int j2 = 0;
	int j3 = 0;
	int sll1 = 0;
	int sll2 = 0;
	int sll3 = 0;
	int bne1 = 0;
	int bne2 = 0;
	int bne3 = 0;
	int bne4 = 0;
	int flag1 = 1;
	int flag2 = 1;
	int flag3 = 1;
	int flag4 = 1;
	int test1 = 1;
	int test2 = 1;
	int test3 = 1;
	int jmpcntr = 0;
	int m = 0;
	int f = 0;
	//this loop goes through the entire memory[][] to compare 
	for(m; m < counter; m++){
		//grabs the location (line) of the first instruction
		if(strcmp(&memory[m][1], instruction1) == 0){
			addi1 = m;
		//this loop is to go through my register array
		for(int i = 0; i < 32; i++){
			//here i compare the first argument
			if(!strcmp(&memory[addi1][2], registers[i][0])){
				addi2 = i;
			}
			//compare the second arugment
			if(!strcmp(&memory[addi1][3], registers[i][0])){
				addi3 = i;
			}
		}
			//holds the value from the function call
			int holdaddi = addi(registers[addi3][1], memory[addi1][4]);
			printf("\nADDI:\n");
			printf("%s was %s",registers[addi2][0], &registers[addi2][1]);
			//this updates the reg array value
			sprintf(&registers[addi2][1], "%d", holdaddi);
			printf("\nregister: %s has %s + %s\n",registers[addi2][0], registers[addi3][0], &memory[addi1][4]);
			printf("%s = %s\n",registers[addi2][0],&registers[addi2][1]);
		}
		//captures the instruction on the line
		if(!strcmp(&memory[m][1], instruction2)){
			sub1 = m;
			//goes through my reg array
			for(int i = 0; i < 32; i++){
				//grab the instructions and store them
				if(!strcmp(&memory[sub1][2], registers[i][0])){
					sub2 = i;
				}
				if(!strcmp(&memory[sub1][3], registers[i][0])){
					sub3 = i;
				}
				if(!strcmp(&memory[sub1][4], registers[i][0])){
					sub4 = i;
				}


			}
			//holds the function call
			int holdsub = sub(registers[sub3][1], &registers[sub4][1]);
			printf("\nSUB:\n");
			printf("%s was %s",registers[sub2][0], &registers[sub2][1]);
			//updates the reg array to the new value
			sprintf(&registers[sub2][1], "%d", holdsub);
			printf("\nregister: %s has %s  %s\n",registers[sub2][0], registers[sub3][0], registers[sub4][0]);
			printf("%s = %s\n",registers[sub2][0],&registers[sub2][1]);

		}


		if(!strcmp(&memory[m][1], instruction4)){
			sll1 = m;
			
			for(int b = 0; b < 32; b++){
				if(!strcmp(&memory[sll1][2], registers[b][0])){
					sll2 = b;
				}
				if(!strcmp(&memory[sll1][3], registers[b][0])){
					sll3 = b;
				}
			}
			int holdsll = sll(registers[sll2][1], memory[sll1][4]);
			printf("\nSLL:\n");
			printf("%s was %s",registers[sll2][0], &registers[sll2][1]);
			sprintf(&registers[sll2][1], "%d", holdsll);
			printf("\nregister: %s has %s  %s\n",registers[sll2][0], registers[sll3][0], &memory[sll1][4]);
			printf("%s = %s\n",registers[sll2][0],&registers[sll2][1]);
		}
		//grabs the new instruction
		if(!strcmp(&memory[m][1], instruction5)){
			bne1 = m;
		//goes through the reg array
		for(int d = 0; d < 32; d++){
			//grabs the instructions and store them
			if(!strcmp(&memory[bne1][2], registers[d][0])){
				bne2 = d;
			}
			if(!strcmp(&memory[bne1][3], registers[d][0])){
				bne3 = d;
			}
			if(!strcmp(&memory[bne1][4], &memory[d][0])){
				bne4 = d;
			}
		}	//holds the value from the function call
			int holdbne = bne(registers[bne2][1], registers[bne3][1]);
			//the function returns true of false
			if(holdbne == 1){
				//if true
				m = bne4 -1;
				printf("\nBNE\n");
				printf("%s(%s) != %s(%s)\n",registers[bne2][0],&registers[bne2][1], registers[bne3][0],&registers[bne3][1]);
				printf("jumped to \"%s\"\n", &memory[bne1][4]);
			}else{
				//else do nothing becuase this print statement doesnt work
				printf("%s == %s\n",registers[bne2][0], registers[bne3][0]);
			}

		}
		
}

}	//passed strings
int addi(char *reg1, char *reg2){
	//conterts to int and adds them
	int a = atoi(&reg1);
	int b = atoi(&reg2);
	int c = a + b;
	return c;
}//passed strings
int sub(char *reg1, char *reg2){
	//converts to int and subtracts them
	int a = atoi(&reg1);
	int b = atoi(&reg2);
	int c = a - b;
	return c;
}//doesnt work. leaving in becuase I have to implement it for part 2
int jump(int index, int ammount){
	return index - ammount;
}//passed strings
int sll(char *reg1, char *reg2){
	//converts to int and shifts them
	int a = atoi(&reg1);
	int b = atoi(&reg2);
	int c = a << b;
	return c;
}//passed strings
int bne(char *reg1, char *reg2){
	//if the strings do not equal, return true
	if(strcmp(&reg1, &reg2) == 0){
		return 0;
	}
	else{
		return 1;
	}
}

