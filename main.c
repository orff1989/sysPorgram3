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
    
    scanf("%c", &ch);
    while (ch!='~'){ //while to get the txt
       strncat(txt,&ch,1);
       scanf("%c", &ch);
    }

const char* ans1 = findInTxt(word,(txt+1));   //q1
const char* ans2 = findInTxt2(word,(txt+1));  //q2
const char* ans3 = findInTxt3(word,(txt+1));  //q3

printf("Gematria Sequences: %s\n",ans1);
printf("Atbash Sequences: %s\n",ans2);
printf("Anagram Sequences: %s\n",ans3);


    return 0;
}
