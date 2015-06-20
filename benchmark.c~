#include <stdio.h>
#include <sys/time.h>
#include <math.h>

struct resultados{
	float es,la,ls,ea,tempoexecucao;
};


void leituraaleatoria(long int n){
	FILE *arquivo,*arquivo2;
	arquivo=fopen("saida","r");
	//arquivo2=fopen("leitura","w");
	char caractere;
	long int i,random,j;
	long int index;
	index = n*1000;	
	for(j=0;j<1000;j++){
		random=rand()%index;
		fseek(arquivo,random,0);
		for(i=0;i<(n/10);i++){
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
	for(i=0;i<(n*100);i++){
		
			caractere=fgetc(fp);
		
	}
	fclose(fp);
}

void escritaaleatoria(long int n){
	FILE *fp;
	fp=fopen("saida","r+");
	long int i,j,random,index;
	index=n*1000;
	for(i=0;i<1000;i++){
		random=rand()%index;
		fseek(fp,random,0);
		for(j=0;j<(n/10);j++){
			fprintf(fp,"c");
		}
	}
	fclose(fp);
}
			
		
	
	

main(int argc,char *argv[]){
	FILE *fp;
	struct timeval inicio, final;
	char caractere;
	long long int n,i,bloco,random,j,loopi,loopj,nmax;
	float tmili,mbs,seconds,totaltime,mediaes,medials,mediaea,mediala,tempofinal,vares,varls,varea,varla,dif1,dif2,dif3,dif4;
	struct resultados *resultadosfinais;
	n=atol(argv[1]);
	nmax=atol(argv[2]);
	resultadosfinais=malloc(nmax*(sizeof(struct resultados)));
	for(loopi=0;loopi<nmax;loopi++){
	tempofinal=0;
	mediaes=0;
	medials=0;
	mediaea=0;
	mediala=0;
	vares=0;
	varls=0;
	varea=0;
	varla=0;
	dif1=0,dif2=0,dif3=0,dif4=0;
	fp=fopen("saida","w");
	gettimeofday(&inicio, NULL);
	for(i=0;i<(n*1000);i++){
		
			//random = (rand()%94)+33;
			//caractere=(char) random;
			fprintf(fp,"a");
		
	}
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    totaltime=seconds;
    mbs=(n/1000)/seconds;
    resultadosfinais[loopi].es=mbs;
	printf("Tempo medio de escrita sequencial: %f MB/s \n",mbs); 
    
    
    
    gettimeofday(&inicio, NULL);
    leituraaleatoria(n);
    gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    totaltime=totaltime+seconds;
    mbs=(n/10000)/seconds;
    resultadosfinais[loopi].la=mbs;
    printf("Tempo medio de leitura aleatoria: %f MB/s \n",mbs);
    
	gettimeofday(&inicio, NULL);
	leiturasequencial(n);
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    mbs=(n/10000)/seconds;
    resultadosfinais[loopi].ls=mbs;
    printf("Tempo medio de leitura sequencial: %f  MB/s \n",mbs);
    
    
    gettimeofday(&inicio, NULL);
    escritaaleatoria(n);
    gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    totaltime=totaltime+seconds;
    mbs=(n/10000)/seconds;
    resultadosfinais[loopi].ea=mbs;
    printf("Tempo medio de escrita aleatoria: %f MB/s \n",mbs);
    
    printf("Tempo total : %f \n",totaltime);
    resultadosfinais[loopi].tempoexecucao=totaltime;
    printf("\n");
    
    
	
    fclose(fp);
}
	for(loopi=0;loopi<nmax;loopi++){
		mediaes=mediaes+resultadosfinais[loopi].es;
		mediaea=mediaea+resultadosfinais[loopi].ea;
		medials=medials+resultadosfinais[loopi].ls;
		mediala=mediala+resultadosfinais[loopi].la;
		tempofinal=tempofinal+resultadosfinais[loopi].tempoexecucao;
	}
	mediaes=mediaes/nmax;
	mediaea=mediaea/nmax;
	medials=medials/nmax;
	mediala=mediala/nmax;
	printf("\n");
	printf("Media de escrita sequencial: %f MB/s \n",mediaes);
	printf("Media de letura aleatoria: %f MB/s \n",mediala);
	printf("Media de leitura sequencial: %f MB/s \n",medials);
	printf("Media de escrita aleatoria: %f MB/s \n",mediaea);
	for(loopi=0;loopi<nmax;loopi++){
		vares=vares+(pow((resultadosfinais[loopi].es-mediaes),2));
		varla=varla+(pow((resultadosfinais[loopi].la-mediala),2));
		varls=varls+(pow((resultadosfinais[loopi].ls-medials),2));
		varea=varea+(pow((resultadosfinais[loopi].ea-mediaea),2));
	}
	vares=vares/nmax;
	varla=varla/nmax;
	varls=varls/nmax;
	varea=varea/nmax;
	vares=sqrt(vares);
	varla=sqrt(varla);
	varls=sqrt(varls);
	varea=sqrt(varea);
	printf("\n");
	printf("Desvio padrao escrita sequencial: %f MB/s \n",vares);
	printf("Desvio padrao letura aleatoria: %f MB/s \n",varla);
	printf("Desvio padrao leitura sequencial: %f MB/s \n",varls);
	printf("Desvio padrao escrita aleatoria: %f MB/s \n",varea);
	printf("Tempo total de execução: %f s \n",tempofinal);
	
	
}


