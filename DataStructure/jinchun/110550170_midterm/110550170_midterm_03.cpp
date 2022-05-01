#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main() {
	char inp[20];
	int oper[20];
	int ans = 0;
	printf("Roman numeral: ");
	scanf("%s", inp);

	for(int i=0;i<strlen(inp);i++){
		if(inp[i]=='I') oper[i]=1;
		else if(inp[i]=='V') oper[i]=5;
		else if(inp[i]=='X') oper[i]=10;
		else if(inp[i]=='L') oper[i]=50;
		else if(inp[i]=='C') oper[i]=100;
		else if(inp[i]=='D') oper[i]=500;
		else if(inp[i]=='M') oper[i]=1000;
	}

	for(int i=0;i<strlen(inp)-1;i++){
		if(oper[i]<oper[i+1]) ans-=oper[i];
		else ans+=oper[i];
	}
	ans+=oper[strlen(inp)-1];

	printf("This roman numeral is %d\n", ans);

	system("pause");
	return 0;
}
