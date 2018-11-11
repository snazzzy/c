
#include <stdio.h>
#include <string.h>
# define MAX_LINE 50
unsigned int subu(char *reg1, char *reg2);
unsigned int addiu(char *reg1, char *reg2);
int addi(char *reg1, char *reg2);
int sub(char *reg1, char *reg2);
int jump(int bol);
int bne(char *reg1, char *reg2);
int li(char *number);
int add(char *reg2, char *reg3);
int jal(char *arg1);
int stackp(char *reg1, int move, int sp);

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
	registers[2][0] = "$ra";
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
	char *memory[1001][5];
	char line[MAX_LINE];
	FILE *fp = fopen("mips.txt", "r");
	char *temp;
	char *trash;
	int counter = 0;
	int zero = 0;
	int hexvar = 0;
	int hexvar2 = 400;
	for(int i = 0; i <= 1000; i++){
		sprintf(&memory[i][0],"%x", hexvar);
		sprintf(&memory[i][1],"%d", zero);
		sprintf(&memory[i][2],"%d", zero);
		sprintf(&memory[i][3],"%d", zero);
		sprintf(&memory[i][4], "%d", zero);	
		hexvar = hexvar +4;	
	}

	//grabes a line, and uses sscan to input arguments into memory
	while(fgets(line, 40, fp)){
		if(sscanf(line, "%40[^, ^\t]", &temp)){
			printf("temp: %s\n", &temp);
			for(int i = 0; i <= 900; i++){
				if(!strcmp(&temp, &memory[i][0])){
					printf("in if %i\n",i);
					sscanf(line, " %40[^,^\n], %40[^,^\n], %40[^,^\n], %40[^,^\n], %40[^,^\n]", &memory[i][0], &memory[i][1], &memory[i][2], &memory[i][3], &memory[i][4]);
				}
			}
		}

	}
	for(int j = 0; j <= 1000; j++){
		for(int k = 0; k < 5; k++){
			printf("memory[%i][%i] : %s\n", j, k, &memory[j][k]);
		}
	}
	fclose(fp);
	//These instructions are to start the compare statements
	char instruction1[] = {'a', 'd', 'd', 'i', '\0'};
	char instruction2[] = {'s', 'u', 'b', '\0'};
	char instruction3[] = {'j','\0'};
	char instruction4[] = {'s','l','l','\0'};
	char instruction5[] = {'b','n','e','\0'};
	char instruction6[] = {'a', 'd', 'd', 'i', 'u', '\0'};
	char instruction7[] = {'s', 'u', 'b', 'u', '\0'};
	char instruction8[] = {'l','i','\0'};
	char instruction9[] = {'a', 'd', 'd', '\0'};
	char instruction10[] = {'j', 'a', 'l', '\0'};
	char instruction11[] = {'j', 'r', '\0'};
	char instruction12[] = {'s', 'w', '\0'};
	char instruction13[] = {'l', 'w', '\0'};
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
	int addiu1 = 0;
	int addiu2 = 0;
	int addiu3 = 0;
	int addiu4 = 0;
	int subu1 = 0;
	int subu2 = 0;
	int subu3 = 0;
	int subu4 = 0;
	int subu5 = 0;
	int li1 = 0;
	int li2 = 0;
	int li3 = 0;
	int add1 = 0;
	int add2 = 0;
	int add3 = 0;
	int add4 = 0;
	int jal1 = 0;
	int jal2 = 0;
	int jal3 = 0;
	int jal4 = 0;
	int jr1 = 0;
	int jr2 = 0;
	int jr3 = 0;
	int sw1 = 0;
	int sw2 = 0;
	int sw3 = 0;
	int sw4 = 0;
	int lw1 = 0;
	int lw2 = 0;
	int lw3 = 0;
	int lw4 = 0;
	//flag1 is used to break jump when bne is equal.
	int flag1 = 1;
	int flag2 = 1;
	int flag3 = 1;
	int flag4 = 1;
	//test1 is used to calc the total result of addi
	int test1 = 0;
	//test2 is used to calc the total result of sub
	int test2 = 0;
	//test3 is used to calc the total result of add
	int test3 = 0;
	//test4 is used to calc the total result of addiu
	unsigned long test4 = 0;
	//test5 is used to calc the total result of subu
	unsigned long test5 = 0;
	unsigned long subuhold = 0;
	unsigned long addiuhold = 0;
	int jalhold = 0;
	int jmpcntr = 0;
	int m = 0;
	int sp = 1000;
	sprintf(&registers[30][1], "%d", sp);

	//this loop goes through the entire memory[][] to compare
	for(m; m <=901; m++){
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
			test1 = holdaddi + atoi(&registers[addi2][1]);
			printf("\nADDI:\n");
			printf("%s was %s",registers[addi2][0], &registers[addi2][1]);
			//this updates the reg array value
			sprintf(&registers[addi2][1], "%d", test1);
			printf("\nregister: %s has %s + %s\n",registers[addi2][0], registers[addi3][0], &memory[addi1][4]);
			printf("%s = %s\n",registers[addi2][0],&registers[addi2][1]);
		}
		//captures the instruction on the line
		else if(!strcmp(&memory[m][1], instruction2)){
			sub1 = m;
			int asize = strlen(&memory[sub1][4]);
			//goes through my reg array
			for(int i = 0; i < 32; i++){
				//grab the instructions and store them
				if(!strcmp(&memory[sub1][2], registers[i][0])){
					sub2 = i;
				}
				if(!strcmp(&memory[sub1][3], registers[i][0])){
					sub3 = i;
				}
				if(!strncmp(&memory[sub1][4], registers[i][0], asize-1)){
					sub4 = i;
				}

			}
			//holds the function call
			int holdsub = sub(registers[sub3][1], &registers[sub4][1]);
			test2 = holdsub + atoi(&registers[sub2][1]);
			printf("\nSUB:\n");
			printf("%s was %s",registers[sub2][0], &registers[sub2][1]);
			//updates the reg array to the new value
			sprintf(&registers[sub2][1], "%d", test2);
			printf("\nregister: %s has %s  %s\n",registers[sub2][0], registers[sub3][0], registers[sub4][0]);
			printf("%s = %s\n",registers[sub2][0],&registers[sub2][1]);

		}
		else if(!strcmp(&memory[m][1], instruction9)){
			add1 = m;
			int asize = strlen(&memory[add1][4]);
			for(int i = 0; i < 32; i++){
				if(!strcmp(&memory[add1][2], registers[i][0])){
					add2 = i;
				}
				if(!strcmp(&memory[add1][3], registers[i][0])){
					add3 = i;
				}
				if(!strncmp(&memory[add1][4], registers[i][0], asize-1)){
					add4 = i;
				}
			}
			int holdadd = add(registers[add3][1], registers[add4][1]);
			test3 = holdadd + atoi(&registers[add2][1]);
			printf("\nADD\n");
			printf("%s was %s",registers[add2][0], &registers[add2][1]);
			sprintf(&registers[add2][1], "%d", test3);
			printf("\nregister: %s has %s + %s\n",registers[add2][0], registers[add3][0], registers[add4][0]);
			printf("%s = %s\n",registers[add2][0],&registers[add2][1]);


		}


		else if(!strcmp(&memory[m][1], instruction4)){
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
		else if(!strcmp(&memory[m][1], instruction5)){
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
			}
			for(int j = 0; j <= 900; j++){
				int asize = strlen(&memory[bne1][4]);
				//grabs the memory address to jump to
				if(!strncmp(&memory[j][0], &memory[bne1][4], asize-1)){
					bne4 = j;
					printf("\nbne4:%i",bne4);
				}
			}
			int holdbne = bne(registers[bne2][1], registers[bne3][1]);
			printf("\nBNE\n");
			if(holdbne == 0){
				//if true
				printf("%s(%s) == %s(%s)\n",registers[bne2][0],&registers[bne2][1], registers[bne3][0],&registers[bne3][1]);
				printf("jumped to \"%s\"\n", &memory[bne1][4]);
				printf("bne4 = %i\n", bne4);
				flag1 = 1;

			}else{
				printf("%s != %s\n",registers[bne2][0], registers[bne3][0]);
				flag1 = 0;
				m = bne4-1;
			}

		}


			//grabs the location (line) of the first instruction
	else if(strcmp(&memory[m][1], instruction6) == 0){
		addiu1 = m;
		//this loop is to go through my register array
		for(int i = 0; i < 32; i++){
			//here i compare the first argument
			if(!strcmp(&memory[addiu1][2], registers[i][0])){
				addiu2 = i;
			}
			//compare the second arugment
			if(!strcmp(&memory[addiu1][3], registers[i][0])){
				addiu3 = i;
			}
		}
			//holds the value from the function call
		unsigned int holdaddiu = addiu(registers[addiu3][1], &memory[addiu1][4]);
		addiuhold = atoi(&registers[addiu2][1]);
		test4 = holdaddiu + addiuhold;
		printf("\nADDIu:\n");
		printf("%s was %s",registers[addiu2][0], &registers[addiu2][1]);
		//this updates the reg array value
		sprintf(&registers[addiu2][1], "%lu", test4);
		printf("\nregister: %s has %s + %s\n",registers[addiu2][0], registers[addiu3][0], &memory[addiu1][4]);
		printf("%s = %s\n",registers[addiu2][0],&registers[addiu2][1]);
		}

	else if(!strcmp(&memory[m][1], instruction7)){
		subu1 = m;
		int asize = strlen(&memory[subu1][4]);
		for(int i = 0; i < 32; i++){
			if(!strcmp(&memory[subu1][2], registers[i][0])){
				subu2 = i;
			}
			if(!strcmp(&memory[subu1][3], registers[i][0])){
				subu3 = i;
			}
			if(!strncmp(&memory[subu1][4], registers[i][0], asize-1)){
				subu4 = i;
			}
		}
		printf("\nSUBU\n");
		printf("%s was %s",registers[subu2][0], &registers[subu2][1]);
		unsigned long holdsubu = subu(registers[subu3][1], registers[subu4][1]);
		subuhold = atol(&registers[subu2][1]);
		test5 = holdsubu + subuhold;
		printf("\ntest5: : %i\n");
		sprintf(&registers[subu2][1], "%lu", test5);
		printf("\nregister: %s has %s + %s\n",registers[subu2][0], registers[subu3][0], registers[subu4][0]);
		printf("%s = %s\n",registers[subu2][0],&registers[subu2][1]);


	}
	else if(!(strcmp(&memory[m][1], instruction3))){
		printf("\nJUMP\n");
		printf("jump # %i\n", flag4);
		flag4++;
		//captures insturction line at memory
		j1 = m;
		for(int j = 0; j <= 900; j++){
			int asize =strlen(&memory[j1][2]);
			if(!strncmp(&memory[j1][2], &memory[j][0], asize-1)){
				j3 = j;
				printf("jumping to %i\n",j1);
				m = j3-1;
			}	

		}
	}
	else if(!strcmp(&memory[m][1], instruction8)){
		li1 = m;
		printf("li1 %i\n",li1);
		for(int i = 0; i < 32; i++){
			if(!strcmp(&memory[li1][2], registers[i][0])){
				li2 = i;
			}
		}
		printf("\nLI\n");
		int holdli = li(memory[li1][3]);
		sprintf(&registers[li2][1], "%d", holdli);
		printf("\nregister:%s now has %s\n",registers[li2][0], &registers[li2][1]);
	}

	else if(!strcmp(&memory[m][1], instruction10)){

		jal1 = m;
		int asize = strlen(&memory[jal1][2]);
		//go through mem array to find a match for jal to jmp to
		for(int i = 0; i <= 900; i++){
			if(!strncmp(&memory[jal1][2], &memory[i][0], asize-1)){
				jal2 = i;
			}
		}
		jal3 = m +1;
		strcpy(&registers[2][1], &memory[jal3][0]);
		printf("jal: %i\n",jal2);
		printf("REG RA:::%s\n", &registers[2][1]);
		printf("m before: %i\n", m);
		flag2 = 1;
		m = jal2-1;
		printf("m after: %i\n", m);

	}
	//matches the first instruction
	else if(!strcmp(&memory[m][1], instruction11)){
		//stores the memory address to jump to in $ra register
		printf("JR\n");
		for(int f = 0; f <= 900; f++){
			if(!strcmp(&memory[f][0], &registers[2][1])){
				jr2 = f;
			}
		}
			printf("jumping to index %i\n",jr2);
			flag2 = 0;
			m = jr2;


	}
	else if(!strcmp(&memory[m][1], instruction12)){
		sw1 = m;
		int move = 1;
		int asize = strlen(&memory[sw1][2]);
		for(int i = 0; i < 32; i++){
			if(!strncmp(&memory[sw1][2], registers[i][0], asize-1)){
				sw2 = i;
			}
			if(!strncmp(&memory[sw1][3], registers[i][0], asize -1)){
				//this is the stack pointer register
				sw3 = i;
			}
		}
		printf("\nSW\n");
		//int holdsw = atoi(&registers[sw3][1]);
		sp = atoi(&registers[sw3][1]);
		printf("sp: %i\n", sp);
		if(sp < 900){
			printf("Memory out of bounds, please proceed with care, my program is fragile\n");
			printf("The stack pointer goes past memory bounds, only 900 to 1000\n");
			exit(0);
		}
		if(sp > 1000){
			printf("Woooow there, sir you need to take your flock and turn back from winst you came\n");
			printf("The stack pointer goes past memory bounds, only 900 to 1000\n");
			exit(0);
		}
		strcpy(&memory[sp][1], &registers[sw2][1]);

	}
	else if(!strcmp(&memory[m][1], instruction13)){
		lw1 = m;
		int asize = strlen(&memory[lw1][2]);
		int bsize = strlen(&memory[lw1][3]);
		for(int i = 0; i < 32; i++){	
			if(!strcmp(&memory[lw1][2], registers[i][0])){
				lw2 = i;
			}
			if(!strncmp(&memory[lw1][3], registers[i][0], asize -1)){
				lw3 = i;
			}
		}
		printf("\n LW \n");
		//grabs the stack pointer
		sp = atoi(&registers[lw3][1]);
				printf("sp: %i\n", sp);

		if(sp > 1000){
			printf("Dude, ur trying to read stuff out of memory, chillax and review your MIPS.txt\n");
			printf("The stack pointer goes past memory bounds, only 900 to 1000\n");
			exit(0);
		}
		strcpy(&registers[lw2][1], &memory[sp][1]);
		printf("reg: %s is now %s\n", registers[lw2][0], &registers[lw2][1]);
}
}
	for(int j = 0; j <= 1000; j++){
		for(int k = 0; k < 5; k++){
			//printf("memory[%i][%i] : %s\n", j, k, &memory[j][k]);
		}
	}
}
//combonation of J and JR cuases loop. 
//passed strings
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
}//doesnt work.
int jump(int bol){
	if(bol == 1){
		return 0;
	}else{
		return 1;
	}
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
	if(strcmp(&reg1, &reg2)){
		return 1;
	}
	else{
		return 0;
	}
}
unsigned int addiu(char *reg1, char *reg2){
	unsigned long a = atol(&reg1);
	unsigned long b = atol(&reg2);
	printf("a: %lu	b: %lu\n",a,b);
	if(a < b){
		printf("unsigned out of bounds ( result - );\nReturning 0;\n");
		return 0;
	}else{

	printf("a: %lu	b: %lu\n",a,b);
	unsigned long c = a + b;
	return c;
	}
}

unsigned int subu(char *reg1, char *reg2){
	printf("\nreg1 = %s\n reg2 = %s\n", &reg1, &reg2);
	unsigned long a = atol(&reg1);
	unsigned long b = atol(&reg2);
	if( a < b){
		printf("unsigned out of bounds ( result - );\nReturning 0;");
		return 0;
	}else{
	long c = a - b;
	printf("\nin subu() c = %lu\n",c);
	return c;	
	}


}
int li(char *number){
	int a = atoi(&number);
	return a;

}
int add(char *reg1, char *reg2){
	int a = atoi(&reg1);
	int b = atoi(&reg2);
	int c = a + b;
	return c;
}
int jal(char *arg1){
	printf("\n JAL()\n");
	printf("arg1: %s\n",arg1);
	int a = 0;
	int b = atoi(arg1);
	printf("arg1: %i\n", b);
	if(a == b){
		printf("returning 0\n");
		return 0;
	}else{
		a = b;
		printf("returning 1\n");
		return 1;
	}
}
int stackp(char *reg1, int move, int sp){
	int a = atoi(&reg1);
	if(sp < 900){
		printf("Memory out of bounds, please proceed with care, my program is fragile\n");
		exit(0);
	}
	if(sp > 1000){
		printf("Woooow there, sir you need to take your flock and turn back from winst you came\n");
		exit(0);
	}
 	if(move = 1){
 		sp -1;
 		return sp;
 	}else if(sp < 1000){
 		sp+1;
 		return sp;
 	}else{
 		printf("Dude, how?\n");
 		exit(0);
 	}
}