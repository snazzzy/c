#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define forty 40
#define muchowords 109582
//Prototype for function used below
int hamming(char *wordlist, char *input);
int main(int argc, char *argv[]){
	//Make sure starting the program uses the correct format.
	if (argc > 1){
		printf("error with commands\n");
		return 0;
	}
	//This opens the file
	FILE *fp = fopen("wordsEN.txt", "r");
	//decleration of my arrays 
	char line[forty];
	char words[muchowords][forty];
	char input[forty];
	int i = 0;
	int locate = 0;
	/*grabs, parses, and stores the words from 
	wordsEN.txt and loads them in my array*/
	while(fgets(line, forty, fp)){
		sscanf(line, "%s", words[i]);
		i++;
	}
	int flag =1;
	int flag1 = 1;
	//This is for looping until nothing is entered
	while(flag == 1){
	printf("Enter your word here!\n");
	//gets my input
	fgets(input, forty, stdin);
	//casts input to lowercase
	for(int i = 0; i < strlen(input); i++){
		input[i] = tolower(input[i]);
		if(input[i] == '\n'){
			input[i] = 0;
		}
	}
	//exits if nothing is entered
	if(strlen(input) == 0){
		printf("CYAA\n");
		flag = 0;
		exit(0);
	}
	int minham = forty;
	int inlen = strlen(input);
	//Goes through my entire array and checks if there is a match
	for(int i = 0; i < muchowords; i++){
		if(!strncmp(words[i], input, inlen)){
			printf("Congrats, you passed 3rd grade\n");
			flag1 = 0;
			break;
		}else{
			//only call hamming when the words are the same lenght
			int worlen = strlen(words[i]);
			if(worlen == inlen){
				//function call
				int ham = hamming(words[i], input);
				//this locates the min hamming distance
				if(minham > ham){
					minham = ham;
					flag1 = 1;
				}
			}
		}
	}
	int counter = 0;
	//have to go through my wordlist again after I find min
	for(int i = 0; i < muchowords && flag1 == 1; i++){
		//another function call		
		int hamy = hamming(words[i], input);
		//this prevents printing a words recomending when you typed z word
		for(int a = 0; a < strlen(input); a++){
			/*Goes through the characters and compares when they match. when they dont mach
			store location i*/
			if(words[i][a] == input[a] && strlen(words[i]) == inlen){
				locate = i;
			}
		}
		//Printing the words
		if(minham == hamy && counter < 5 && strlen(words[i]) == inlen){
			printf("%s\n", words[i]);
			counter++;
		}
	}
}
}
//function call for finding hamming distance
int hamming(char* wordlist, char *input){
	int ham = 0;
	int count = 0;
	int wsize = strlen(wordlist);
	int insize = strlen(input);
	/*goes through my word length, and if one of the
	characters do not equal, I increase my counter */
		for(int d = 0; d < insize; d++){
			ham = wordlist[d] - input[d];
			if(ham !=0){
				count++;
			}
		}
	return count;
}