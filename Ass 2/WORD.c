#include <stdio.h>
#include <string.h>

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
		//printf("%s\n", &words[i]);
		i++;
	}
	fgets(input, 40, stdin);
	for(int i = 0; i < strlen(input); i++){
		input[i] = tolower(input[i]);
	}
	int inlen = strlen(input);
	for(int i = 0; i < 109582; i++){
		//printf("%s\n",&word[i]);
		if(!strncmp(words[i], input, inlen-1)){
			printf("word matched\n");
			break;
		}
	}
	int word = 97;
	int word1 = 97 + 97 + 104;
	int word2 = 97 + 97 + 104 + 101 + 100;
	int word3 = 97 + 97 + 104 + 105 + 110 + 103;
	int word4 = 97 + 97 + 104 + 115;
	int word5 = +97 +97 +114 +100 +118 +97 +114 +107;
	int location1 = 0;
	int location2 = 0;
	int location3 = 0;
	int location4 = 0;
	int location5 = 0;
	int inasci = 0;
	for(int i = 0; i <= inlen; i++){
		int a = (int) input[i];
		inasci = inasci + a;
	}
	printf("%i\n",inasci);
	int worasci = 0;
	for(int i = 0; i < 109583; i++){
		int wordsize = strlen(words[i]);
		for(int j = 0; j <= wordsize; j++){
			int a = (int) words[i][j];
			worasci = worasci + a;
		}
		int z = worasci - inasci;
		//printf("z: %i\n", z);
		if(word < 0 && word > z && wordsize == inlen){
			printf("updated\n");
			word = z;
			location1 = i;
			continue;
		}
		else if(word > 0 && word1 < z && wordsize == inlen){
			word = z;
			location1 = i;
			continue;
		}

		else if(word2 < 0 && word2 > z && wordsize == inlen){
			word2 = z;
			location2 = i;
			continue;
		}
		else if(word2 > 0 && word2 < z && wordsize == inlen){
			word2 = z;
			location2 = i;
			continue;
		}
		else if(word3 < 0 && word3 > z && wordsize == inlen){
			word3 = z;
			location3 = i;
			continue;
		}
		else if(word3 > 0 && word3 < z && wordsize == inlen){
			word3 = z;
			location3 = i;
			continue;
		}
		else if(word4 < 0 && word4 > z && wordsize == inlen){
			word4 = z;
			location4 = i;
			continue;
		}
		else if(word4 > 0 && word4 < z && wordsize == inlen){
			word4 = z;
			location4 = i;
			continue;
		}
		else if(word5 < 0 && word5 > z && wordsize == inlen){
			word5 = z;
			location5 = i;
			continue;
		}
		else if(word5 > 0 && word5 < z && wordsize == inlen){
			word5 = z;
			location5 = i;
			continue;
		}
		worasci = 0;
	}
		printf("word1: %i\n", word1);
		printf("word2: %i\n", word2);
		printf("word3: %i\n", word3);
		printf("word4: %i\n", word4);
		printf("word5: %i\n", word5);
		printf("word3 : %s\n",words[location3]);
	//printf("woasci = %i\n", worasci);
	// printf("%li\n", sizeof(words));
	// int ham = 0;
	// int count = 0;
	// printf("%c\n", words[1][2]);
	// for(int k = 0; k < 109583; k++){
	// 	int wsize = strlen(words[k]);
	// 	printf("%i\n",wsize);
	// 	printf("asdfasdffdsa\n");
	// 	for(int d = 0; d <= wsize; d++){
	// 		printf("in for");
	// 		for(int m = 0; m <= inlen; m++){
	// 			if(!strcmp(words[1], input)){
	// 				count++;
	// 			}
	// 			if(strcmp(words[1], input) != 0){
	// 				ham++;
	// 			}

	// 		}
	// 	}
	// }

}