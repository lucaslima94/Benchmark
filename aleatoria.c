#include<stdio.h>

main(){
	int random,i,c,caractere;
	char dados[10];
	FILE *fp;
	fp=fopen("saida","r");
	if(fp==NULL){
		printf("erro ao abrir arquivo\n");
	}
	for(i=0;i<10;i++){
		random=rand()%5050;
		fseek(fp,random,0);
		dados[i]=fgetc(fp);
	}
	for(i=0;i<10;i++){
		printf("%c ",dados[i]);
	}
}
	
	
