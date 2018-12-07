#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    printf("EXTRA CREDIT: s and b work for 0,1,2,3,8. I had spacing problems. I Gave up.\n");
    char selector[1];
    // check for up to 3 command-line arguments
    if (argc > 3) {
        puts("Usage: ./Lab1 word1 word2\n");
        return 1;
    }
    if(argv[2] == NULL){
      selector[0] = '0';
    }

    if(argc == 3){
      if(strlen(argv[2]) > 1){
          printf("2nd argument too big\n");
          return 1;
      }else{
          //printf("%s\n", argv[2]);
          strncpy(selector, argv[2], 1);
        }
    }
    int flag = 1;
    int flag1 = 0;
    printf("\nselector: %c\n", selector[0]);
    if(selector[0] == 'r' || selector[0] == 's' || selector[0] == 'b'){
        flag = 0;
        flag1 = 1;
    }
    else if(selector[0] == '0'){
      //Included these flags just in case, even thow they dont do anything
      flag = 1;
      flag1 = 0;
    }else{
      printf("invalid selector, must be r (roman), s (slash), b (backslash)\n\n");
      return 1;
    }

    char numbers[100];
    strcpy(numbers, argv[1]);
    printf("input : %s\n", numbers);
    if(flag == 1){
      for(int i = 0; i < strlen(numbers); i++){
        top(numbers[i]);
      }
        printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        middle(numbers[i]);
      }
      printf("\n");
      for(int i = 0; i < strlen(numbers); i++){
        bottom(numbers[i]);
      }
      printf("\n");
    }
    if(flag1 == 1){
      for(int i = 0; i < strlen(numbers); i++){
        tops(numbers[i], selector[0]);
      }
      printf("\n");

      for(int i = 0; i < strlen(numbers); i++){
        topmiddles(numbers[i], selector[0]);
      }
      printf("\n");

      for(int i = 0; i < strlen(numbers); i++){
        middles(numbers[i], selector[0]);
      }
      printf("\n");

      for(int i = 0; i < strlen(numbers); i++){
        botmiddles(numbers[i], selector[0]);
      }
      printf("\n");

      for(int i = 0; i < strlen(numbers); i++){
        bottoms(numbers[i], selector[0]);
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
        default:
        printf("Please enter numbers my dude, not letters.\n\n");
        exit(0);
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
          default:
          printf("input numbers, not letters my dude\n");
          exit(0);
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
void tops(char number, char selector){
  char symbols[] = {'_', '|', '/', '\\', ' ', '\0'};
  int a = 0;
  int b = 0;
  int spf = 0;
  int spr = 0;
  int sp = 4;
  if(selector == 's'){
   // printf("slector = s, fun\n");
    a = 0;
    b = 2;
    spf = 6;
    spr = 0;
  }else if(selector == 'b'){
       // printf("slector = b, fun\n");
    a = 0;
    b = 3;
    spf = 0;
    spr = 6;
  }
  //printf("char printing :%c %c\n", symbols[a], symbols[b]);
    switch(number){
        case '-':
          printf(" ");
          break;
        case '0':
          printf("%*c%c%c%c%*c", spf, symbols[sp], symbols[a],symbols[a],symbols[a], spr, symbols[sp]);
          break;
        case '1':
          printf("%*c%c%*c", spf, symbols[sp], symbols[sp], spr, symbols[sp]);
          break;
        case '2':
        //s 10
        //b 10
          printf("%*c%c%c%*c ", spf, symbols[sp], symbols[a], symbols[a], spr, symbols[sp]);
          break;
        case '3':
          printf("%*c%c%c%*c", spf, symbols[sp], symbols[a], symbols[a], spr, symbols[sp]);
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
          printf("%*c%c%c%c%*c", spf, symbols[sp], symbols[a],symbols[a],symbols[a], spr, symbols[sp]);
          break;
        case '9':
          printf(" _ ");
          break;

    }
}
void topmiddles(char number, char selector){
  char symbols[] = {'_', '|', '/', '\\', ' ', '\0'};
  int a = 0;
  int b = 0;
  int spf = 0;
  int spr = 0;
  int sp = 4;
  if(selector == 's'){
        //printf("slector = s, fun\n");
    a = 0;
    b = 2;
    spf = 4;
    spr = 2;
  }else if(selector == 'b'){
       // printf("slector = b, fun\n");
    a = 0;
    b = 3;
    spf = 1;
    spr = 5;
  }
    switch(number){
        case '-':
            printf("-");
            break;
        case '0':
          printf("%*c%c   %c%*c",spf, symbols[sp], symbols[b], symbols[b], spr, symbols[sp]);
          break;
        case '1':
          printf("%*c%c%*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
          break;
        case '2':
        //s : 11
        //b : 11
          printf("%*c  %c%*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
          break;
        case '3':
          printf("%*c  %c  %*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
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
          printf("%*c%c   %c%*c", spf, symbols[sp], symbols[b], symbols[b], spr, symbols[sp]);
          break;
        case '9':
          printf("|_|");
          break;

    }
}

void middles(char number, char selector){
  char symbols[] = {'_', '|', '/', '\\', ' ', '\0'};
  int a = 0;
  int b = 0;
  int spf = 0;
  int spr = 0;
  int sp = 4;
  if(selector == 's'){
        //printf("slector = s, fun\n");
    a = 0;
    b = 2;
    spf = 3;
    spr = 3;
  }else if(selector == 'b'){
       // printf("slector = b, fun\n");
    a = 0;
    b = 3;
    spf = 2;
    spr = 4;
  }
    switch(number){
        case '-':
            printf("_");
            break;
        case '0':
          //S 17
          //B 15
          printf("%*c%c   %c%*c", spf, symbols[sp], symbols[b], symbols[b], spr, symbols[sp]);
          break;
        case '1':
          printf("%*c%c%*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
          break;
        case '2':
        //s : 11
        //b : 11
          printf("%*c%c%c%c%*c", spf, symbols[sp], symbols[a], symbols[a], symbols[b], spr, symbols[sp]);
          break;
        case '3':
          printf("%*c%c%c%c%*c", spf, symbols[sp], symbols[a], symbols[a], symbols[b], spr, symbols[sp]);
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
          printf("%*c%c%c%c%c%c%*c",spf, symbols[sp], symbols[b], symbols[a], symbols[a], symbols[a], symbols[b], spr, symbols[sp]);
          break;
        case '9':
          printf("|_|");
          break;

    }
}
void botmiddles(char number, char selector){
  char symbols[] = {'_', '|', '/', '\\', ' ', '\0'};
  int a = 0;
  int b = 0;
  int sp = 4;
  int spf = 0;
  int spr = 0;
  if(selector == 's'){
        //printf("slector = s, fun\n");
    a = 0;
    b = 2;
    spf = 2;
    spr = 4;
  }else if(selector == 'b'){
       // printf("slector = b, fun\n");
    a = 0;
    b = 3;
    spf = 3;
    spr = 3;
  }
    switch(number){
        case '-':
            printf("-");
            break;
        case '0':

          printf("%*c%c   %c%*c", spf, symbols[sp], symbols[b], symbols[b], spr, symbols[sp]);
          break;
        case '1':
          printf("%*c%c%*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
          break;
        case '2':
        //s : 11
        //b : 11
          printf("%*c%c  %*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
          break;
        case '3':
          printf("%*c  %c  %*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
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
          printf("%*c%c   %c%*c", spf, symbols[sp], symbols[b], symbols[b], spr, symbols[sp]);
          break;
        case '9':
          printf("|_|");
          break;

    }
}

void bottoms(char number, char selector){
  char symbols[] = {'_', '|', '/', '\\', ' ', '\0'};
  int a = 0;
  int b = 0;
  int spf = 0;
  int spr = 0;
  int sp = 4;
  int val = 0;
  if(selector == 's'){
        //printf("slector = s, fun\n");
    a = 0;
    b = 2;
    spr = 6;
    spf = 0;
    // printf("char printing :%c %c\n", symbols[a], symbols[b]);
  }else if(selector == 'b'){
        //printf("slector = b, fun\n");
    a = 0;
    b = 3;
    spf = 4;
    spr = 2;
  }
 // printf("char printing :%c %c\n", symbols[a], symbols[b]);
    switch(number){
        case '-':
            printf("");
            break;
        case '0':
        //4 spaces
          printf("%*c%c%c%c%c%c%*c",spf, symbols[sp], symbols[b], symbols[a], symbols[a], symbols[a], symbols[b], spr, symbols[sp]);
          break;
        case '1':
          printf("%*c%c%*c", spf, symbols[sp], symbols[b], spr, symbols[sp]);
          break;
        case '2':
        //11
        //11
          printf("%*c%c%c%c%*c", spf, symbols[sp], symbols[b], symbols[a], symbols[a], spr, symbols[sp]);
          break;
        case '3':
          printf("%*c%c%c%c%*c", spf, symbols[sp], symbols[a], symbols[a], symbols[b], spr, symbols[sp]);
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
          printf("%*c%c%c%c%c%c%*c",spf, symbols[sp], symbols[b], symbols[a], symbols[a], symbols[a], symbols[b], spr, symbols[sp]);
          break;
        case '9':
          printf(" _|");
          break;

    }
}