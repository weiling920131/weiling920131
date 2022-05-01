#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *compare(const char *s,const char *t,int n);

int main(){

    int n=0;
    printf("input n:");
    scanf("%d",&n);
    char *a = (char*)calloc(n,sizeof(char));
    char *b = (char*)calloc(n,sizeof(char));

    printf("input a:");
    scanf("%s",a);
    printf("input b:");
    scanf("%s",b);

    for(int i=0;i<n;i++){
        printf("%d",*(compare(a,b,n)+i));
    }

    return 0;
}

int *compare(const char *s,const char *t,int n){

    int *cmp=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        if(*(s+i)==*(t+i)) *(cmp+i)=1;
        else *(cmp+i)=0;
    }
    return cmp;
}




