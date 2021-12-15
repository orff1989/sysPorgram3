#include <stdio.h>
#include "Ex3.c"
#include <string.h>

#define TXT 1024
#define WORD 30

int main(){
    char ch;
    char word[WORD];
    char txt[TXT]="";

    scanf("%s",word); //getting the word
    printf("The word is: %s\n",word);

    scanf("%c", &ch);
    while (ch!='~'){ //while to get the txt
       strncat(txt,&ch,1);
       scanf("%c", &ch);
    }
printf("The txt is: %s\n",txt);

const char* ans = findInTxt2(word,(txt+1));
printf("the words are: %s\n",ans);
    return 0;
}
