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
	for(j=0;j<n;j++){
		random=rand()%index;
		fseek(arquivo,random,0);
		for(i=0;i<100;i++){
			caractere=fgetc(arquivo);
			//fprintf(arquivo2,"%c",caractere);
		}
		//fprintf(arquivo2,"\n");
	}
	//fclose(arquivo2);
	fclose(arquivo);
}

void leiturasequencial(long int n){
	FILE *fp;
	fp=fopen("saida","r");
	long int i,j;
	char caractere;
	for(i=0;i<100;i++){
		for(j=0;j<n;j++){
			caractere=fgetc(fp);
		}
	}
	fclose(fp);
}

void escritaaleatoria(long int n){
	FILE *fp;
	fp=fopen("saida","r+");
	long int i,j,random,index;
	index=n*1000;
	for(i=0;i<n;i++){
		random=rand()%index;
		fseek(fp,random,0);
		for(j=0;j<1000;j++){
			fprintf(fp,"c");
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
			
		
	
	

main(int argc,char *argv[]){
	FILE *fp;
	struct timeval inicio, final,inicio2,final2;
	char caractere;
	long int n,i,bloco,random,j;
	float tmili,mbs,seconds,totaltime;
	fp=fopen("saida","w");
	n=atol(argv[1]);
	gettimeofday(&inicio, NULL);
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
    mbs=(n/10000)/seconds;
    printf("Tempo medio de leitura aleatoria: %f MB/s \n",mbs);
    
	gettimeofday(&inicio, NULL);
	leiturasequencial(n);
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    mbs=(n/10000)/seconds;
    printf("Tempo medio de leitura sequencial: %f  MB/s \n",mbs);
    
    
    gettimeofday(&inicio, NULL);
    escritaaleatoria(n);
    gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    totaltime=totaltime+seconds;
    mbs=(n/1000)/seconds;
    printf("Tempo medio de escrita aleatoria: %f MB/s \n",mbs);
    
    printf("Tempo total : %f \n",totaltime);
    
    
	
    fclose(fp);
}


