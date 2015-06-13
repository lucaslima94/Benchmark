#include<stdio.h>

main(){
	FILE *fp;
	//fp=fopen("saida","w");
	char caractere;
	int random,i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			random = (rand()%94)+33;
			caractere=(char) random;
			printf("%c ", caractere);
		}
		printf("\n");
	}

}
