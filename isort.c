#include <stdio.h>
#include "txtfind.h"
#define SIZE 50


/*
function that get from the user 50 number, puting them into array
and printing the sorted array after being sort
*/
int main(){
    int arr[SIZE]={0};
    int num;
    printf("enter 50 numbers:\n");
    for(int i=0;i<SIZE;i++){//retrieving 50 numbers
        int flag=(scanf("%d",&num));
        if(flag==1){
            *(arr+i)=num;
        }
        else {
            printf("illegal input\n");
            i--;
        }
    }
    insertion_sort(arr,SIZE);//sorting the array
    for (int i = 0; i < SIZE; i++)//print the array
    {
        if(i==SIZE-1){
            printf("%d\n",arr[i]);
        }
        else
        {
            printf("%d,",arr[i]);
        }
    }
    
    return 0;
}

void shift_element(int* arr,int i){
    if(i>0){
        for(int j=i;j>0;j--){//we starting at the last element that we want to shift on, and running backword
            *(arr+j)=*(arr+j-1);    
        }
    }
}

void insertion_sort(int* arr,int len){
    for(int i=0;i<len;i++){
        int j=0;
        while((*(arr+j)<*(arr+i))&&(j<i)){//we running till we get unsort elements
            j++;
        }
        int tmp=*(arr+i);//we saving the element value that we want to shift
        shift_element((arr+j-1),i-j+1);//shifting the max element to the on before last 
        *(arr+j)=tmp;//update the last element
    }
}