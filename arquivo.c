#include<stdio.h>
#include <sys/time.h>

void leituraaleatoria(long long int n){
	FILE *arquivo;
	arquivo=fopen("saida","r");
	char caractere;
	long long int i,random;
	n=n*10;
	for(i=0;i<n;i++){
		//random=rand()%n;
		fseek(arquivo,i,0);
		caractere=fgetc(arquivo);
	}
	fclose(arquivo);
}
		
	
	

main(int argc,char *argv[]){
	FILE *fp;
	struct timeval inicio, final;
	char caractere;
	long long int n,i,bloco,random,j;
	float tmili,mbs,seconds;
	fp=fopen("saida","w");
	gettimeofday(&inicio, NULL);
	n=atol(argv[1]);
	for(i=0;i<1024;i++){
		for(j=0;j<n;j++){
			random = (rand()%94)+33;
			caractere=(char) random;
			fprintf(fp,"%c", caractere);
		}
		fprintf(fp,"\n");
	}
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    mbs=(n/1000)/seconds;

    printf("Tempo medio de escrita sequencial: %f MB/s \n",mbs); 
    gettimeofday(&inicio, NULL);
    leituraaleatoria(n);
    gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    mbs=(n/100000)/seconds;
    printf("Tempo medio de leitura aleatoria: %f MB/s \n",mbs);
    printf("Tempo total : %f \n",seconds);
    fclose(fp);
}


