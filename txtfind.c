#include <stdio.h>
#include <string.h>

#define LINE 256

void searchA(char* c){
    char space[255];
    char enter[7]="";
    printf("the size is :%ld",strlen(enter));
    gets(space);//dont used
    while( 1){
        int j=1;
        gets(space);
       // printf("%s",space);
        for(int i=0;(i<strlen(space))&&j<(strlen(c));i++){
            if(*(c)==*(space+i)){
                int flag=1;//for check if the string is equals
                for(j=1;(j<strlen(c))&&(flag==1);j++){
                    if(*(c+j)!=*(space+i+j)){
                        flag=0;
                    }
                }
                if((flag==1)&&(j==strlen(c))){
                    printf("%s\n",space);
                }
            }
        } 
        //gets(space); 
    }


}
void searchB(char* c){

}

int Getline(char s[]){
    int i=0;
    while((s[i]!='\n')&&(i<strlen(s))){
        i++;
    }
    return i;
}

int getword(char w[]){
    int i=0;
    while((w[i]!='\n')&&(w[i]!='\t')&&(w[i]!=' ')&&(i<strlen(w))){
        i++;
    }
    return i;
}

int substring(char *str1,char *str2){
    if(strcmp(str2,"")==0){
        return 1;
    }
    int j=0;
    for(int i=0;(i<strlen(str1))&&j<(strlen(str2));i++){
        if(*(str2)==*(str1+i)){
            int flag=1;//for check if the string is equals
            for(j=1;(j<strlen(str2))&&(flag==1);j++){
                if(*(str2+j)!=*(str1+i+j)){
                    flag=0;
                }
            }
            if((flag==1)&&(j==strlen(str2))){
                return 1;
            }
        }
    } 
    return 0;
}

int similar(char *s,char *t,int n){
    int count=0;

    for(int i=0;i<strlen(t);i++){
        int j;
        for(j=i+count;(j<strlen(s))&&(i<strlen(t));j++){
            if(t[i]!=s[j]){
                count++;
                j++;
                i--;
                break;
            }
            i++;
        }
    }
    if(count==n) return 1;
    else return 0;
}

void print_lines(char *str){
    char space[LINE];
    gets(space);
    while(strcmp(space,"")!=0){
        if(substring(space,str)==1){
            printf("%s\n",space);
        }
        gets(space);
    }
}

void print_similar_words(char *str){
    char space[LINE];
    gets(space);
    while(strcmp(space,"")!=0){
        if(similar(space,str,1)==1){
            printf("%s\n",space);
        }
        gets(space);
    }
}

int main(){
    // char s[255];
    // char ans[255]="";
    // char c;
    // gets(s);
    // printf("%s\n",s);
    // for(int i=0;i<strlen(s);i++){
   
    //     if(*(s+i)==' '){
    //         c=*(s+i+1);
    //         break;
    //     }
    //     *(ans+i)=*(s+i);
    // }
    // printf("%s\n",ans);
    // if(c=='a'){
    //     searchA(ans);
    // }
    // else if(c=='b'){
    //     searchB(ans);
    // }
    // else {
    //     printf("wrong character");
    // }

    char s[LINE]="tamotek";
    printf("%d\n",Getline(s));
    printf("%d\n",getword(s));
    char c[LINE]="";
    printf("%d\n",substring(s,c));

    char t[LINE]="";
    char d[LINE]="";
    printf("%d\n",similar(d,t,0));

    char cat[LINE]="cat";

    //print_lines(cat); 
    char x[LINE];
    gets(x);
    printf("%d\n",similar(x,cat,1));
    return 0;
}