#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256

/*
the main function that gets text file from the user and and execute function according to char 'c' assignment
*/

int main(){
    char s[255];//the first line
    char ans[255]="";//for know what the word
    char c;//for type of the assignment
    gets(s);//the first line - we want to extract the word to find and the assignment (a/b)
    for(int i=0;i<strlen(s);i++){
        if(*(s+i)==' '){
            c=*(s+i+1);
            break;
        }
        *(ans+i)=*(s+i);
    }
    gets(s);//empty row
    if(c=='a'){
        print_lines(ans);
    }
    else if(c=='b'){
        print_similar_words(ans);
    }
    else {
        printf("wrong character");
    }

    return 0;
}

int Getline(char s[]){//counting the chars in the line
    int i=0;
    while((s[i]!='\n')&&(i<strlen(s))){
        i++;
    }
    return i;
}

int getword(char w[]){//counting the chars in the first word
    int i=0;
    while((w[i]!='\n')&&(w[i]!='\t')&&(w[i]!=' ')&&(i<strlen(w))){
        i++;
    }
    return i;
}

int substring(char *str1,char *str2){
    if(Getline(str2)==0){
        return 1;
    }
    int j=0;
    for(int i=0;(i<strlen(str1))&&j<(strlen(str2));i++){
        if(*(str2)==*(str1+i)){//str1+i is pointer that point to the adress of that holding the character equals to str2[0]
            int flag=1;//for check if the string is equals
            for(j=1;(j<strlen(str2))&&(flag==1);j++){
                if(*(str2+j)!=*(str1+i+j)){
                    flag=0;//if its not equal- so false
                }
            }
            if((flag==1)&&(j==strlen(str2))){//if we get to the end without falsing the flag str2 is substring of str1
                return 1;
            }
        }
    } 
    return 0;
}

int similar(char *s,char *t,int n){
    int count=0;//counting the mistakes of s string
    int i,j;
    for(i=0;i<strlen(t);i++){
        for(j=i+count;(j<strlen(s))&&(i<strlen(t));j++){//we initializing j to i+count because we want to check the next char
            if(t[i]!=s[j]){//if there is a mistake
                count++;
                j++;
                i--;//we reducing i inorder to keep it at the same value in the next iteration
                break;
            }
            i++;
        }
    }
    if(strlen(s)-strlen(t)<=n&&count<=n) return 1;//just when rhe mistake's range and the count <=n, we know that its similar.
    else return 0;
}

void print_lines(char *str){
    char row[LINE];
    char *p=row;//we will running row addres
    char ch;//for input
    while (scanf("%c",&ch)!=EOF){//for get each char
        p=row;
        while(ch!='\n'){//for get each line
            *(p)=ch;
            if(scanf("%c",&ch)==EOF){
                break;
            }
            p++;
        }
        *p=0;
        if(substring(row,str)==1){//just when its happend, we will print the current line
            printf("%s\n",row);
        }
    }
}

void print_similar_words(char *str){
    char word[LINE];
    char *p=word;//we will running row addres
    char ch;//for input
    while (scanf("%c",&ch)!=EOF){//for each char till the end of the input
        if(ch!=' '&&ch!='\n'){//if we didnt arrive to the end of the word, we will continue 
            *p=ch;
            p++;
            continue;
        }
        else {//we arrive the end of the word, so we checking if its similar 
            *(p)=0;
            if(similar(word,str,1)==1){
                printf("%s\n",word);

            }
        }
        p=word;
    }
}