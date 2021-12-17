#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

//this method checking if char is a lowercase latter
int isLowercase(char ch){
if (ch>64 && ch<91) return 0;
else if(ch>96 && ch<123) return 1;
else return -1;
}

//this mehodt convert char to gematria
int charToGematria(char ch){
    int ans=0;
    if(isLowercase(ch)==1) ans = (ch -'a')+1;
    else if(isLowercase(ch)==0) ans = (ch -'A')+1;

    return ans;
}

//this method convert word to gematria
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

//this mehodt convert word to gematria
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

//this mehodt convert char to gematria
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

//this method removes the last char of the word
void removeLastCh(char* t){
    int len= strlen(t);
    int i=1;
    while (*(t+len-i)!='~' && i<len+1)
    {
      i++;
    }
    if(*(t+len-i)=='~') *(t+len-i)='\0';
}

//this method solve the 1nd question
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

//this method gets a word and reversed it
const char* reverseWord(char* word){
    static char ansOfR1[]="";
    int len = strlen(word);
    int i=1;
    while (len-i>=0){
       ansOfR1[i-1]=*(word+len-i);
       i++;
    }
    return ansOfR1;
}

int isValid0(char* word, char* newWord, int to){
if (strlen(word)>to+1 ||*(newWord)==' '|| charToGematria(*(newWord)==0)) return 0;

const char* reversedWord=reverseWord(word);
int chOfWord=charToGematria(*(word));
int chOfNewWord=27-charToGematria(*(newWord));
int k=1,i=1,ans1=1;


for (i = 0; i <= to; i++){
       chOfNewWord=27-charToGematria(*(newWord+i));
        if (*(newWord+i)!=' ' && chOfNewWord==27){
            ans1=0;
            break;
        } 
        if (chOfNewWord!=27 && chOfWord!=chOfNewWord) {
            ans1=0;
            break;
        }
        if (*(newWord+i)!=' '){
            chOfWord=charToGematria(*(word+k));
             k++;
        }  
   }
if (ans1==1) return 1; 

ans1=1;
k=1;
chOfWord=charToGematria(*(reversedWord));
   for (int i = 0; i <= to; i++){
       chOfNewWord=27-charToGematria(*(newWord+i));
        if (*(newWord+i)!=' ' && chOfNewWord==27) {
            ans1=0;
            break;
            }
        if (chOfNewWord!=27 && chOfWord!=chOfNewWord) {
            ans1=0;
            break;
            }
            if (*(newWord+i)!=' '){
       chOfWord=charToGematria(*(reversedWord+k));
       k++;
            }
   }

if(ans1==1) return 1;
else return 0;
}

int howManylatters(char *word,int to){
    int c=0;
for (int i = 0; i <= to; i++)
{
    if (charToGematria(*(word+i))!=0)
    {
        c++;
    }
}
return c;
}

 const char* findInTxt2(char* word, char* txt){
static char ans202[1024]="";  
int j;

for (int i = 0; i < strlen(txt); i++){
       for (j=strlen(word)-1; j < strlen(txt); j++){

            if (howManylatters(txt,j)+1<strlen(word)) break;

            if (isValid0(word,txt+i,j)==1){
            strncat(ans202, (txt+i), j+1);
            strncat(ans202, "~", 2);
             
         }
         
       }  
    }
    removeLastCh(ans202);
return ans202;
 }

//this method solve the 2nd question
// const char* findInTxt2(char* word, char* txt){
// int i=0,j=0,chOfTxt=0;

// int lenOfWord=strlen(word);
// int lenOfTxt=strlen(txt);

// char reversedWord[WORD];
// strcpy(reversedWord,reverseWord(word));
// static char ans1[TXT]="";


//     int chOfWord=charToGematria(*(word));
//     int chOfReversedWord=charToGematria(*(reversedWord+i));

//     while (j<lenOfTxt){
//         chOfTxt=27-charToGematria(*(txt+j));
//         printf("%d",j);
//         if (chOfTxt==chOfWord){
//           int i1=1;
//           int j1=j+1;
//           int chOfTxt1=27-charToGematria(*(txt+j1));
//           int chOfWord1=charToGematria(*(word+i1));

//           while (chOfTxt1==chOfWord1 && i1<lenOfWord && j1<lenOfTxt){
//               chOfTxt1=27-charToGematria(*(txt+j1));
//               chOfWord1=charToGematria(*(word+i1));
//               i1++;
//               j1++;
//           }
//             int check1=wordToGematria(word);
//             int check2=wordToGematriaFromTo2(txt+j,j1-j);
//           if (check1==check2 && strlen(word)<j1-j+1){
//               strncat(ans1, (txt+j), j1-j);
//               strncat(ans1, "~", 2);
//           }
//         }
//         if (chOfTxt==chOfReversedWord){
//           int i1=1;
//           int j1=j+1;
//           int chOfTxt1=27-charToGematria(*(txt+j1));
//           int chOfWord1=charToGematria(*(reversedWord+i1));

//           while (chOfTxt1==chOfWord1 && i1<lenOfWord && j1<lenOfTxt){
//               chOfTxt1=27-charToGematria(*(txt+j1));
//               chOfWord1=charToGematria(*(reversedWord+i1));
//               i1++;
//               j1++;
//           }
//             int check1=wordToGematria(reversedWord);
//             int check2=wordToGematriaFromTo2(txt+j,j1-j);
//           if (check1==check2 && strlen(reversedWord)<j1-j+1){
//               strncat(ans1, (txt+j), j1-j);
//               strncat(ans1, "~", 2);
//           }
//         }
//         j++; 
// }
// removeLastCh(ans1);
// return ans1;
// }

//this method checking how many char occurrence int the word
int howManyCh(char* word, char ch){
    int lenOfWord=strlen(word);
    int c=0;
    for (int i = 0; i < lenOfWord; i++)
    {
        if (*(word+i)==ch) c++;
    }
    return c;
}

//this method checking how many char occurrence int the word
int howManyChFromTo(char* word, char ch, int to){
    int lenOfWord=strlen(word);
    int c=0;
    for (int i = 0; i<=to && i < lenOfWord; i++){
        if (*(word+i)==ch) c++;
    }
    return c;
}

//this method checking if the words are valid by the 3nd question
int isValid(char* word,char* newWord1, int to2){
    if(*(newWord1)=='\n' || *(newWord1)=='\r' || *(newWord1)=='\0') return 0;
    if(*(newWord1+to2)=='\n' || *(newWord1+to2)=='\r' || *(newWord1+to2)=='\0') return 0;
    
    
    int lenOfWord=strlen(word);
    int lenOfNewWord=strlen(newWord1);

    if(lenOfWord>to2+1) return 0;
    

    char chOfWord,chOfNewWord;
    int numOfOccurrencesInWord,numOfOccurrencesInNewWord;

    for (int i = 0; i < lenOfWord; i++){
        chOfWord=*(word+i);
        numOfOccurrencesInWord = howManyCh(word,chOfWord);
        numOfOccurrencesInNewWord = howManyChFromTo(newWord1,chOfWord,to2);

        if (numOfOccurrencesInNewWord!=numOfOccurrencesInWord) return 0;
    }
    
    for (int i = 0; i<=to2 && i < lenOfNewWord; i++){
        chOfNewWord=*(newWord1+i);
        numOfOccurrencesInWord = howManyCh(word,chOfNewWord);
        numOfOccurrencesInNewWord = howManyChFromTo(newWord1,chOfNewWord,to2);

        if (numOfOccurrencesInNewWord!=numOfOccurrencesInWord) return 0;
    }
    return 1;  
}

//this method solve the 3nd question
const char* findInTxt3(char* word, char* txt){
static char ans3[TXT]="";  
int j;

for (int i = 0; i < strlen(txt); i++){
    j=0;
       for (j=0; j < strlen(txt); j++){
         if (isValid(word,txt+i,j)==1)
         {
            strncat(ans3, (txt+i), j+1);
            strncat(ans3, "~", 2);
             
         }
         
       }  
    }
    removeLastCh(ans3);
return ans3;
}