#include<stdio.h>
#include <sys/time.h>

void leituraaleatoria(long int n){
	FILE *arquivo,*arquivo2;
	arquivo=fopen("saida","r");
	//arquivo2=fopen("leitura","w");
	char caractere;
	long int i,random,j;
	long int index;
	index = n*1000;	
	for(j=0;j<100;j++){
		random=rand()%index;
		fseek(arquivo,random,0);
		for(i=0;i<n;i++){
			caractere=fgetc(arquivo);
			//fprintf(arquivo2,"%c",caractere);
		}
		//fprintf(arquivo2,"\n");
	}
	//fclose(arquivo2);
	fclose(arquivo);
}
		
	
	

main(int argc,char *argv[]){
	FILE *fp;
	struct timeval inicio, final;
	char caractere;
	long int n,i,bloco,random,j;
	float tmili,mbs,seconds,totaltime;
	fp=fopen("saida","w");
	gettimeofday(&inicio, NULL);
	n=atol(argv[1]);
	for(i=0;i<1000;i++){
		for(j=0;j<n;j++){
			//random = (rand()%94)+33;
			//caractere=(char) random;
			fprintf(fp,"a");
		}
		fprintf(fp,"\n");
	}
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    totaltime=seconds;
    mbs=(n/1000)/seconds;

    printf("Tempo medio de escrita sequencial: %f MB/s \n",mbs); 
    gettimeofday(&inicio, NULL);
    leituraaleatoria(n);
    gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    totaltime=totaltime+seconds;
    mbs=(n/100000)/seconds;
    printf("Tempo medio de leitura aleatoria: %f MB/s \n",mbs);
    printf("Tempo total : %f s \n",totaltime);
    fclose(fp);
}


