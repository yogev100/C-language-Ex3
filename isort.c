#include <stdio.h>
#define SIZE 50

void shift_element(int* arr,int i){
    for(int j=i;j>1;j--){
       *(arr+j)=*(arr+j-1);    
    }
}

void insertion_sort(int* arr,int len){
    for(int i=0;i<len;i++){
        int j=0;
        while((*(arr+j)<*(arr+i))&&(j<i)){
            j++;
        }
        int tmp=*(arr+i);
        shift_element((arr+j-1),i-j+1);
        *(arr+j)=tmp;
    }
}


int main(){
    int arr[SIZE]={0};
    int num;
    printf("enter 50 numbers:\n");
    for(int i=0;i<5;i++){
        int flag=(scanf("%d",&num));
        if(flag==1){
            *(arr+i)=num;
        }
        else {
            printf("illegal input\n");
            i--;
        }
    }
    insertion_sort(arr,5);
    for(int i=0;i<5;i++){
        if(i<4){
        printf("%d,",arr[i]);
        }
        else {
            printf("%d\n",arr[i]);
        }
    }

    // int a[]={5,6,7,8,9,0};
    // int* p;
    // p=&a[0];
    // shift_element(p,2);

    // for(int i=0;i<6;i++){
    //     printf("the value number %d is:%d\n",i,a[i]);
    // }

    return 0;
}