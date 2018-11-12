
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
	char place[] = {'0', '\0'};
	//I am going loading all of the registers with 0 to start
	for(int i = 0; i < 32; i++){
		//printf("%i ", i);
		sscanf(place, "%s", &registers[i][1]);
	}
	//declartion of memory and stack
	char *memory[1001][5];
	char line[MAX_LINE];
	//opening the file to be read in
	FILE *fp = fopen("mips.txt", "r");
	char *temp;
	char *trash;
	int counter = 0;
	int zero = 0;
	int hexvar = 0;
	//variable used to load the memory addresses
	int hexvar2 = 400;
	//here I load the array of memory addresses.
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
		//I grab the memory address and store it in temp
		if(sscanf(line, "%40[^, ^\t]", &temp)){
			for(int i = 0; i <= 900; i++){
				//I find the memory address in memory and the file, and load it in that spot
				if(!strcmp(&temp, &memory[i][0])){
					sscanf(line, " %40[^,^\n], %40[^,^\n], %40[^,^\n], %40[^,^\n], %40[^,^\n]", &memory[i][0], &memory[i][1], &memory[i][2], &memory[i][3], &memory[i][4]);
				}
			}
		}

	}
	//just my print statement printing memory
	for(int j = 0; j <= 1000; j++){
		for(int k = 0; k < 5; k++){
			//printf("memory[%i][%i] : %s\n", j, k, &memory[j][k]);
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
	char instruction14[] = {'b', 'g', 't', 'z', '\0'};
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
	int bgtz1 = 0;
	int bgtz2 = 0;
	int bgtz3 = 0;
	int bgtz4 = 0;
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
	printf("To increment Stack Pointer, please use the following:\n");
	printf("\naddi, $sp, $zero, -1\n");
	printf("\nwhen using JAL and JR, you must use jump. Please take note of the folloing mips code:\n");
	printf("\n1f8, jal, 208\n1fc, \n200, addi, $t5, $zero, $s1\n204, j, 224 <----Here, you must jump passed the Jump Return, Or you will get an infinte	loop\n208, addi, $s2, $zero, 2\n20c, addi, $s1, $zero, -1\n210, addi, $s0, $zero, 18\n214, bgtz, $s1, 220\n218, addi, $s1, $zero, 1\n21c, j, 214\n220, jr, $ra\n");
	printf("\nPress enter to continue\n");
	char enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }


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
			//here I add the original vallue and its new one
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
			//finds the registers in instruction and saves them
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
			//passes the registers
			int holdadd = add(registers[add3][1], registers[add4][1]);
			//adds the old value with the new value
			test3 = holdadd + atoi(&registers[add2][1]);
			printf("\nADD\n");
			printf("%s was %s",registers[add2][0], &registers[add2][1]);
			//updates the array value
			sprintf(&registers[add2][1], "%d", test3);
			printf("\nregister: %s has %s + %s\n",registers[add2][0], registers[add3][0], registers[add4][0]);
			printf("%s = %s\n",registers[add2][0],&registers[add2][1]);


		}


		else if(!strcmp(&memory[m][1], instruction4)){
			sll1 = m;
			//grabs the 2 registers, the third argument is an immediate value
			for(int b = 0; b < 32; b++){
				if(!strcmp(&memory[sll1][2], registers[b][0])){
					sll2 = b;
				}
				if(!strcmp(&memory[sll1][3], registers[b][0])){
					sll3 = b;
				}
			}
			//passes the register and the immediate value
			int holdsll = sll(registers[sll2][1], memory[sll1][4]);
			printf("\nSLL:\n");
			printf("%s was %s",registers[sll2][0], &registers[sll2][1]);
			//update the register valeu
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
			//go through the memory addresses in memory for a match
			for(int j = 0; j <= 900; j++){
				int asize = strlen(&memory[bne1][4]);
				//grabs the memory address to jump to
				//grabs the memory address to jump to
				if(!strncmp(&memory[j][0], &memory[bne1][4], asize-1)){
					bne4 = j;
					printf("\nbne4:%i",bne4);
				}
			}
			//passes the registers and stores the bol 
			int holdbne = bne(registers[bne2][1], registers[bne3][1]);
			printf("\nBNE\n");
			//The function returns a Bol, if 1, jump to the memory address
			if(holdbne == 0){
				//if true
				printf("%s(%s) == %s(%s)\n",registers[bne2][0],&registers[bne2][1], registers[bne3][0],&registers[bne3][1]);
				printf("jumped to \"%s\"\n", &memory[bne1][4]);
				printf("bne4 = %i\n", bne4);
				flag1 = 1;

			}else{
				printf("%s != %s\n",registers[bne2][0], registers[bne3][0]);
				flag1 = 0;
				//here I adjust my program counter(the main for())
				m = bne4-1;
			}

		}
		else if(!strcmp(&memory[m][1], instruction14)){
			bgtz1 = m;
			int asize = strlen(&memory[bgtz1][3]);
			for(int i = 0; i < 32; i++){
				//grab the register value in my array
				if(!strcmp(&memory[bgtz1][2], registers[i][0])){
					bgtz2 = i;
				}
				//go through the mem addresses to find a match
				for(int f = 0; f < 900; f++){
					if(!strncmp(&memory[bgtz1][3], &memory[f][0], asize-1)){
						bgtz3 = f;
					}
				}

			}
			printf("\nBGTZ\n");
			printf("reg passed : %s\n",&registers[bgtz2][1]);
			//passes the registers and stores the bol
			int holdbgtz = bgtz(registers[bgtz2][1]);
			//If flase
			if(holdbgtz	== 0){
				printf("%s (%s) is not greater that zero\n", registers[bgtz2][0], &registers[bgtz2][1]);
				printf("Not jumping\n");
			}else{
				//if true
				printf("%s (%s) is greater that zero\n", registers[bgtz2][0], &registers[bgtz2][1]);
				printf("going to index %s\n", &memory[bgtz3][0]);
				//adjust my program counter
				m = bgtz3-1;
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
		unsigned long holdaddiu = addiu(registers[addiu3][1], memory[addiu1][4]);
		//I take the old value and add it to the new
		addiuhold = atoi(&registers[addiu2][1]);
		test4 = holdaddiu + addiuhold;
		printf("\nADDIu:\n");
		printf("%s was %s\n",registers[addiu2][0], &registers[addiu2][1]);
		//this updates the reg array value 
		sprintf(&registers[addiu2][1], "%lu", test4);
		printf("register: %s has %s + %s\n",registers[addiu2][0], registers[addiu3][0], &memory[addiu1][4]);
		if(addiuhold == 0){
			printf("Unsigned out of bounds (Result -)\nReturning 0\n");
			// printf("Result was negative, to prevent unsigned 2s compliment issues (seg fualts)\nYour value has been changed to zero, Please review your mips code.\n");
		}
		printf("%s = %s\n",registers[addiu2][0],&registers[addiu2][1]);
		}

	else if(!strcmp(&memory[m][1], instruction7)){
		subu1 = m;
		int asize = strlen(&memory[subu1][4]);
		//matches the registers in the instruction
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
		//passes the registers and store the int
		unsigned long holdsubu = subu(registers[subu3][1], registers[subu4][1]);
		//add the old value to the new value
		subuhold = atol(&registers[subu2][1]);
		test5 = holdsubu + subuhold;
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
		//goes through memory and matches address to jump to
		for(int j = 0; j <= 900; j++){
			int asize =strlen(&memory[j1][2]);
			if(!strncmp(&memory[j1][2], &memory[j][0], asize-1)){
				j3 = j;
				printf("jumping to index %i\n",j1);
				//then i set my program counter to the address to jump to
				m = j3-1;
			}	

		}
	}
	else if(!strcmp(&memory[m][1], instruction8)){
		li1 = m;
		printf("li1 %i\n",li1);
		//matches the registers in the instruction
		for(int i = 0; i < 32; i++){
			if(!strcmp(&memory[li1][2], registers[i][0])){
				li2 = i;
			}
		}
		printf("\nLI\n");
		//holds the new value passed
		int holdli = li(memory[li1][3]);
		//updates the reg array value
		sprintf(&registers[li2][1], "%d", holdli);
		printf("register:%s now has %s\n",registers[li2][0], &registers[li2][1]);
	}

	else if(!strcmp(&memory[m][1], instruction10)){
		printf("\nJAL\n");
		jal1 = m;
		int asize = strlen(&memory[jal1][2]);
		//go through mem array to find a match for jal to jmp to
		for(int i = 0; i <= 900; i++){
			if(!strncmp(&memory[jal1][2], &memory[i][0], asize-1)){
				jal2 = i;
			}
		}
		//saves the return address after jal
		jal3 = m +1;
		//copies the return address into the register
		strcpy(&registers[2][1], &memory[jal3][0]);
		printf("Return address saved: %s\n", &registers[2][1]);
		flag2 = 1;
		//adjusts my program counter
		printf("jumping to: %i\n", jal2-1);
		m = jal2-1;

	}
	//matches the first instruction
	else if(!strcmp(&memory[m][1], instruction11)){
		//stores the memory address to jump to in $ra register
		printf("\nJR\n");
		//go through mem array to find a match for the address
		for(int f = 0; f <= 900; f++){
			if(!strcmp(&memory[f][0], &registers[2][1])){
				jr2 = f;
			}
		}
			printf("jumping to index %i\n",jr2);
			flag2 = 0;
			//jumps to that address
			m = jr2;


	}
	else if(!strcmp(&memory[m][1], instruction12)){
		sw1 = m;
		int move = 1;
		int asize = strlen(&memory[sw1][2]);
		//matches the registers in the instruction
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
		//stores the stack pointer address
		sp = atoi(&registers[sw3][1]);
		printf("Stack Pointer: %i\n", sp);
		//These if() check if the stack is in the correct range
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
		//write to the stack
		strcpy(&memory[sp][1], &registers[sw2][1]);
		printf("register stored %s (%s)\n", registers[sw2][0], &registers[sw2][1]);
		printf("Stack index modified: %s = %s\n", &memory[sp][0], &memory[sp][1]);

	}
	else if(!strcmp(&memory[m][1], instruction13)){
		lw1 = m;
		int asize = strlen(&memory[lw1][2]);
		int bsize = strlen(&memory[lw1][3]);
		//match the registers
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
		//make sure you dont load word out of memory array
		if(sp > 1000){
			printf("Dude, ur trying to read stuff out of memory, chillax and review your MIPS.txt\n");
			printf("The stack pointer goes past memory bounds, only 900 to 1000\n");
			exit(0);
		}
		//writes from stack to the register
		strcpy(&registers[lw2][1], &memory[sp][1]);
		printf("reg: %s is now %s\n", registers[lw2][0], &registers[lw2][1]);
		printf("Stack index read: %s = %s\n",&memory[sp][0], &memory[sp][1]);
}
}
	//just for printing the stack
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
//used to check if reg is greater that 0
int bgtz(char *reg1){
	int a = atoi(&reg1);
	if(a > 0){
		return 1;
	}else{
		return 0;
	}
}
unsigned int addiu(char *reg1, char *reg2){
	//stores values into unsigned
	unsigned long a = atol(&reg1);
	unsigned long b = atol(&reg2);
	//adds them up
	long c = a + b;
	//make sure result is not negative, or the number is fucking huge, cuases seg fualts
	if(c < 0){
		return 0;
	}else{

	printf("\nc = %lu\n",c);
	//return value
	return c;
	}
}

unsigned int subu(char *reg1, char *reg2){
	//grabs the values
	unsigned long a = atol(&reg1);
	unsigned long b = atol(&reg2);
	//make sure result is not negative, or the number is fucking huge, cuases seg fualts
	if( a < b){
		printf("unsigned out of bounds ( result - );\nReturning 0;");
		return 0;
	}else{
	//adds the values up
	long c = a - b;
	//returns the values
	return c;	
	}


}
//pretty dumb function, should have just done this in main
int li(char *number){
	int a = atoi(&number);
	return a;

}
int add(char *reg1, char *reg2){
	//grabs the values
	int a = atoi(&reg1);
	int b = atoi(&reg2);
	//adds em up
	int c = a + b;
	//returns the value
	return c;
}
int jal(char *arg1){
	printf("\n JAL()\n");
	printf("arg1: %s\n",arg1);
	int a = 0;
	//grabs the jal address
	int b = atoi(arg1);
	printf("arg1: %i\n", b);
	//this is to prevent a infinte loop. Just in case there is a failure, I makes sure it doesnt
	//hit the same jal and jr 2 times
	if(a == b){
		printf("returning 0\n");
		return 0;
	}else{
		a = b;
		printf("returning 1\n");
		return 1;
	}
}
//this function is not used, keeping it in for my thoughts
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