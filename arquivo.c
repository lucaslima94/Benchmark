#include<stdio.h>
#include <sys/time.h>


main(int argc,char *argv[]){
	FILE *fp;
	struct timeval inicio, final;
	char caractere;
	int random,i,n;
	float tmili,mbs;
	float seconds;
	fp=fopen("saida","w");
	gettimeofday(&inicio, NULL);
	n=atoi(argv[1]);
	n=n*1000;
	for(i=0;i<n;i++){
		random = (rand()%94)+33;
		caractere=(char) random;
		fprintf(fp,"%c", caractere);
	}
	fprintf(fp,"\n");
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    tmili=tmili/1000;
    mbs=(n/1000000)/tmili;

    printf("Tempo medio de escrita sequencial: %f MB/s \n",mbs); 
}


