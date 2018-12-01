#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char selector[1];
    // check for up to 3 command-line arguments
    if (argc > 3) {
        puts("Usage: ./Lab1 word1 word2\n");
        return 1;
    }

    if(argc == 3 || argv[2] == NULL){
        if(argv[2] == NULL){
            return 1;
        }else if(strlen(argv[2]) > 1){
            printf("2nd argument too big\n");
            return 1;
        }else{
            printf("%s\n", argv[2]);
            strncpy(selector, argv[2], 1);
        }
    }
    int flag = 1;
    printf("selector: %c\n", selector[0]);
    if(selector[0] == 'r' || selector[0] == 's' || selector[0] == 'b'){
      flag = 0;
    }else{
      printf("invalid argument 2, must be r or s\n");
      return 1;
    }
    char numbers[100];
    strcpy(numbers, argv[1]);
    printf("input : %s\n", numbers);
    if(flag == 1){
      for(int i = 0; i < strlen(numbers); i++){
        top(numbers[i], 0);
      }
        printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        middle(numbers[i], 0);
      }
      printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        bottom(numbers[i], 0);
      }
      printf("\n");
    }
    if(selector[0] == 's'){
      for(int i = 0; i < strlen(numbers); i++){
        tops(numbers[i], 0);
      }
        printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        middles(numbers[i], 0);
      }
      printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        bottoms(numbers[i], 0);
      }
      printf("\n");
    }
    if(selector[0] == 'b'){
      for(int i = 0; i < strlen(numbers); i++){
        topb(numbers[i], 0);
      }
        printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        middleb(numbers[i], 0);
      }
      printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        bottomb(numbers[i], 0);
      }
      printf("\n");
    }
}
void top(char number){
    switch(number){
        case '-':
            printf(" ");
            break;
        case '0':
          printf(" _ ");
          break;
        case '1':
          printf("   ");
          break;
        case '2':
          printf(" _ ");
          break;
        case '3':
          printf(" _ ");
          break;
        case '4':
          printf("   ");
          break;
        case '5':
          printf(" _ ");
          break;
        case '6':
          printf(" _ ");
          break;
        case '7':
          printf("__ ");
          break;
        case '8':
          printf(" _ ");
          break;
        case '9':
          printf(" _ ");
          break;

    }
}

void middle(char number){
    switch(number){
        case '-':
            printf("-");
            break;
        case '0':
          printf("| |");
          break;
        case '1':
          printf(" | ");
          break;
        case '2':
          printf(" _|");
          break;
        case '3':
          printf(" _|");
          break;
        case '4':
          printf("|_|");
          break;
        case '5':
          printf("|_ ");
          break;
        case '6':
          printf("|_ ");
          break;
        case '7':
          printf("  |");
          break;
        case '8':
          printf("|_|");
          break;
        case '9':
          printf("|_|");
          break;

    }
}

void bottom(char number){
    switch(number){
        case '-':
            printf(" ");
            break;
        case '0':
          printf("|_|");
          break;
        case '1':
          printf(" | ");
          break;
        case '2':
          printf("|_ ");
          break;
        case '3':
          printf(" _|");
          break;
        case '4':
          printf("  |");
          break;
        case '5':
          printf(" _|");
          break;
        case '6':
          printf("|_|");
          break;
        case '7':
          printf("  |");
          break;
        case '8':
          printf("|_|");
          break;
        case '9':
          printf(" _|");
          break;

    }
}
void tops(char number){
    switch(number){
        case '-':
            printf(" ");
            break;
        case '0':
          printf("      ");
          break;
        case '1':
          printf("      ");
          break;
        case '2':
          printf("      ");
          break;
        case '3':
          printf("      ");
          break;
        case '4':
          printf("      ");
          break;
        case '5':
          printf("      ");
          break;
        case '6':
          printf("      ");
          break;
        case '7':
          printf("      ");
          break;
        case '8':
          printf("      ");
          break;
        case '9':
          printf("      ");
          break;

    }
}

void middles(int number){
    switch(number){
        case '-':
            printf("-");
            break;
        case '0':
          printf("  /   / \t\n");
          printf(" /   /  ");
          break;
        case '1':
          printf("  /   \t\n");
          printf(" /    ");
          break;
        case '2':
          printf("      ");
          break;
        case '3':
          printf("      ");
          break;
        case '4':
          printf("      ");
          break;
        case '5':
          printf("      ");
          break;
        case '6':
          printf("      ");
          break;
        case '7':
          printf("      ");
          break;
        case '8':
          printf("      ");
          break;
        case '9':
          printf("      ");
          break;

    }
}

void bottoms(int number){
    switch(number){
        case '-':
            printf(" ");
            break;
        case '0':
          printf("/___/   ");
          break;
        case '1':
          printf(" /    ");
          break;
        case '2':
          printf("      ");
          break;
        case '3':
          printf("      ");
          break;
        case '4':
          printf("      ");
          break;
        case '5':
          printf("      ");
          break;
        case '6':
          printf("      ");
          break;
        case '7':
          printf("      ");
          break;
        case '8':
          printf("      ");
          break;
        case '9':
          printf("      ");
          break;

    }
}

void topb(char number){
    switch(number){
        case '-':
            printf(" ");
            break;
        case '0':
          printf(" _ ");
          break;
        case '1':
          printf("   ");
          break;
        case '2':
          printf(" _ ");
          break;
        case '3':
          printf(" _ ");
          break;
        case '4':
          printf("   ");
          break;
        case '5':
          printf(" _ ");
          break;
        case '6':
          printf(" _ ");
          break;
        case '7':
          printf("__ ");
          break;
        case '8':
          printf(" _ ");
          break;
        case '9':
          printf(" _ ");
          break;

    }
}

void middleb(int number){
    switch(number){
        case '-':
            printf("-");
            break;
        case '0':
          printf("| |");
          break;
        case '1':
          printf(" | ");
          break;
        case '2':
          printf(" _|");
          break;
        case '3':
          printf(" _|");
          break;
        case '4':
          printf("|_|");
          break;
        case '5':
          printf("|_ ");
          break;
        case '6':
          printf("|_ ");
          break;
        case '7':
          printf("  |");
          break;
        case '8':
          printf("|_|");
          break;
        case '9':
          printf("|_|");
          break;

    }
}

void bottomb(int number){
    switch(number){
        case '-':
            printf(" ");
            break;
        case '0':
          printf("|_|");
          break;
        case '1':
          printf(" | ");
          break;
        case '2':
          printf("|_ ");
          break;
        case '3':
          printf(" _|");
          break;
        case '4':
          printf("  |");
          break;
        case '5':
          printf(" _|");
          break;
        case '6':
          printf("|_|");
          break;
        case '7':
          printf("  |");
          break;
        case '8':
          printf("|_|");
          break;
        case '9':
          printf(" _|");
          break;

    }
}
