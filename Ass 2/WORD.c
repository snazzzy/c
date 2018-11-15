#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int hamming(char *wordlist, char *input);
int main(int argc, char *argv[]){
	if (argc < 1){
		printf("error with commands\n");
		return 0;
	}
	FILE *fp = fopen("wordsEN.txt", "r");
	char line[40];
	char words[109582][40];
	char input[40];
	int i = 0;
	while(fgets(line, 40, fp)){
		sscanf(line, "%s", words[i]);
		i++;
	}
	int flag =1;
	int flag1 = 1;
	while(flag == 1){
	printf("Enter your word here!\n");
	fgets(input, 40, stdin);
	for(int i = 0; i < strlen(input); i++){
		input[i] = tolower(input[i]);
		if(input[i] == '\n'){
			input[i] = 0;
		}
	}
	if(strlen(input) == 0){
		printf("CYAA\n");
		flag = 0;
		exit(0);
	}
	int minham = 40;
	int inlen = strlen(input);
	for(int i = 0; i < 109582; i++){
		if(!strncmp(words[i], input, inlen)){
			printf("Congrats, you passed 3rd grade\n");
			flag1 = 0;
			break;
		}else{
			int worlen = strlen(words[i]);
			if(worlen == inlen){
				int ham = hamming(words[i], input);
				if(minham > ham){
					minham = ham;
					flag1 = 1;
				}
			}
		}
	}
	int counter = 0;
	for(int i = 0; i < 109582 && flag1 == 1; i++){		
		int hamy = hamming(words[i], input);
		if(minham == hamy && counter < 5){
			printf("%s\n", words[i]);
			counter++;
		}
	}
}
}

int hamming(char* wordlist, char *input){
	int ham = 0;
	int count = 0;
	int wsize = strlen(wordlist);
	int insize = strlen(input);
	if(wsize == insize){
		for(int d = 0; d < insize; d++){
			ham = wordlist[d] - input[d];
			if(ham !=0){
				count++;
			}
		}
	}
	return count;
}