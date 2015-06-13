#include<stdio.h>

main(){
	FILE *fp;
	fp=fopen("saida2.txt","w");
	char caractere;
	int random,i,j;
	for(i=0;i<5000;i++){
		for(j=0;j<10000;j++){
			random = (rand()%94)+33;
			caractere=(char) random;
			fprintf(fp,"%c ", caractere);
		}
		fprintf(fp,"\n");
	}

}
