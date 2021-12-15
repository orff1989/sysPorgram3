#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

int isLowercase(char ch){
if (ch>64 && ch<91) return 0;
else if(ch>96 && ch<123) return 1;
else return -1;
}

int charToGematria(char ch){
    int ans=0;
    if(isLowercase(ch)==1) ans = (ch -'a')+1;
    else if(isLowercase(ch)==0) ans = (ch -'A')+1;

    return ans;
}

int wordToGematria(char* word){
    char ch=*word;
    int sum=0;
    int i=1;
    while (ch!='\0' && ch!=' ')
     {
        int n=charToGematria(ch);
        sum=sum+n;
        ch=*(word+i);
        i++;
    }
    return sum;
}

int wordToGematriaFromTo(char* word,int to){
    if(to==0) return charToGematria(*word);
    char ch=*word;
    int sum=0;
    int i=1;
    while (i<=to && ch!='\0')
     {
        int n=charToGematria(ch);
        sum=sum+n;
        ch=*(word+i);
        i++;
    }
    return sum;
}

int wordToGematriaFromTo2(char* word,int to){
    if(to==0) return 27-charToGematria(*word);
    char ch=*word;
    int sum=0;
    int i=1;
    while (i<=to && ch!='\0')
     {
        int n=27-charToGematria(ch);
        sum=sum+n;
        ch=*(word+i);
        i++;
    }
    return sum;
}

void removeLastCh(char* t){
    int len= strlen(t);
    int i=1;
    while (*(t+len-i)!='~')
    {
      i++;
    }
*(t+len-i)='\0';
}

const char* findInTxt(char* word, char* txt){
int i=0;
int j=0;
int gOfWord= wordToGematria(word);
static char ans[TXT]="";

int n=0;
while (*(txt+i)!='\0' && i<strlen(txt))
{
    while (wordToGematriaFromTo((txt+i),j)<gOfWord && j<strlen(txt) && *(txt+i+j)!='\0' && charToGematria(*(txt+i))!=0){ 
        j++;
    }
    n=wordToGematriaFromTo((txt+i),j);
        if(n==gOfWord){
            if (j==0){
            strncat(ans, (txt+i), 1);
            strncat(ans, "~", 2);
            }
            else{
            strncat(ans, (txt+i), j);
            strncat(ans, "~", 2);
            }
        }
    i++;
    j=0;
}
removeLastCh(ans);
return ans;
}

const char* reverseWord(char* word){
    static char ansOfR[WORD]="";
    int len = strlen(word);
    int i=1;
    while (len-i>=0){
       strncat(ansOfR, word+len-i, 1);
       i++;
    }
    return ansOfR;
}

const char* findInTxt2(char* word, char* txt){
int i=0,j=0,chOfTxt=0;

int lenOfWord=strlen(word);
int lenOfTxt=strlen(txt);

char reversedWord[WORD];
strcpy(reversedWord,reverseWord(word));
static char ans1[TXT]="";


    int chOfWord=charToGematria(*(word));
    int chOfReversedWord=charToGematria(*(reversedWord+i));

    while (j<lenOfTxt){
        chOfTxt=27-charToGematria(*(txt+j));

        if (chOfTxt==chOfWord){
          int i1=1;
          int j1=j+1;
          int chOfTxt1=27-charToGematria(*(txt+j1));
          int chOfWord1=charToGematria(*(word+i1));

          while (chOfTxt1==chOfWord1 && i1<lenOfWord && j1<lenOfTxt){
              chOfTxt1=27-charToGematria(*(txt+j1));
              chOfWord1=charToGematria(*(word+i1));
              i1++;
              j1++;
          }
            int check1=wordToGematria(word);
            int check2=wordToGematriaFromTo2(txt+j,j1-j);
          if (check1==check2){
              strncat(ans1, (txt+j), j1-j);
          }
        }
        if (chOfTxt==chOfReversedWord){
          int i1=1;
          int j1=j+1;
          int chOfTxt1=27-charToGematria(*(txt+j1));
          int chOfWord1=charToGematria(*(reversedWord+i1));

          while (chOfTxt1==chOfWord1 && i1<lenOfWord && j1<lenOfTxt){
              chOfTxt1=27-charToGematria(*(txt+j1));
              chOfWord1=charToGematria(*(reversedWord+i1));
              i1++;
              j1++;
          }
            int check1=wordToGematria(reversedWord);
            int check2=wordToGematriaFromTo2(txt+j,j1-j);
          if (check1==check2){
              strncat(ans1, (txt+j), j1-j);
              strncat(ans1, "~", 2);
          }
        }
        j++; 
}
return ans1;
}


