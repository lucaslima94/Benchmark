#include<stdio.h>

main(){
	char caractere;
	int random,i,j;
	for(i=0;i<500;i++){
		for(j=0;j<10000;j++){
			random = (rand()%94)+33;
			caractere=(char) random;
			printf("%c ", caractere);
		}
		printf("\n");
		j++;
	}

}
