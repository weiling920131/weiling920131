#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void bigadd(char a[],char b[]);
void bigmulti(char a[],char b[]);
void bigsub(char a[],char b[]);

int main() {
    
    char a[]="990";
    char b[]="999";

    bigadd(a,b);
    printf("\n-----------------\n");
    bigmulti(a,b);
    printf("\n-----------------\n");
    bigsub(a,b);
    
	system("pause");
	return 0;
}

void bigadd(char a[],char b[]){
    int alen = strlen(a);
    int blen = strlen(b);
    int al = alen - 1;
    int bl = blen - 1;
    int *ans=(int *)calloc((alen>blen)?(alen+1):(blen+1),sizeof(int));
    int i=0;
    while(i<alen && i<blen){
        *(ans+i)=(a[al]-'0')+(b[bl]-'0');
        al--;
        bl--;
        i++;
    }
    if(alen>=blen){
        for(int j=al;j>=0;j--,i++){
            *(ans+i)=a[j]-'0';
        }
    }
    else{
        for(int j=bl;j>=0;j--,i++){
            *(ans+i)=b[j]-'0';
        }
    }
    for(int j=0;j<i;j++){ 
        *(ans+j+1)+=*(ans+j)/10;
        *(ans+j)=*(ans+j)%10;
    }
    for(int j=i;j>=0;j--){
        if(j==i && ans[j]==0) continue;
        printf("%d",ans[j]);
    }
}

void bigmulti(char a[],char b[]){
    int alen=strlen(a);
    int blen=strlen(b);
    int *ans=(int*)calloc(alen+blen,sizeof(int));
    for(int i=alen-1;i>=0;i--){
        for(int j=blen-1;j>=0;j--){
            *(ans+i+j+1)+=(a[i]-'0')*(b[j]-'0');
        }
    }
    for(int i=alen+blen-1;i>0;i--){
        *(ans+i-1)+=*(ans+i)/10;
        *(ans+i)%=10;
    }
    for(int i=0;i<alen+blen;i++){
        if(i==0&&ans[i]==0) continue;
        printf("%d",ans[i]);
    }
}

void bigsub(char a[],char b[]){
    int al=strlen(a),bl=strlen(b);
    int all=al,bll=bl;
    int max,min;
    char*mx,*mn;
    if(strcmp(a,b)==0){ 
        printf("0\n");
        return;
    }
    else if(al>bl){
        max=al;
        min=bl;
        mx=a;
        mn=b;
    }
    else if(al<bl){
        printf("-");
        max=bl;
        min=al;
        mx=b;
        mn=a;
    }
    else{
        while(1){
            all--;
            bll--;
            if(a[all]<b[bll]){
                printf("-");
                max=bl;
                min=al;
                mx=b;
                mn=a;
                break;
            }
            else if(a[all]>b[bll]){
                max=al;
                min=bl;
                mx=a;
                mn=b;
                break;
            }
        }
    }
    
    int fin=max;
    int *ans=(int*)calloc(max,sizeof(int));
    for(int j=min-1;j>=0;j--){
        ans[max-1]+=(mx[max-1]-'0')-(mn[min-1]-'0');
        max--;
        min--;
    }
    for(int i=max-1;i>=0;i--){
        ans[i]=mx[i]-'0';
    }
    for(int i=fin-1;i>0;i--){
        if(ans[i]<0){
            ans[i-1]--;
            ans[i]+=10;
        }
    }
    int confirm=0;
    for(int i=0;i<fin;i++){
        if(confirm==0&&ans[i]==0) continue;
        printf("%d",ans[i]);
        confirm++;
    }
    printf("\n");
}

