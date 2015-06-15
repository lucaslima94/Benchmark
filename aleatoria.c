#include<stdio.h>

main(){
	FILE *arquivo;
	arquivo=fopen("saida","r");
	char caractere;
	long long int i,random,n=1000000;
	n=n*10;
	for(i=0;i<n;i++){
		fseek(arquivo,i,0);
		caractere=fgetc(arquivo);
	}
	fclose(arquivo);
}
	
	
