#include<stdio.h>
#include <sys/time.h>

main(){
	FILE *fp;
	struct timeval inicio, final;
	fp=fopen("saida","r+");
	long int i,j,n,random,index;
	float tmili,mbs,seconds;
	char caractere;
	n=10000;
	index=n*1000;
	gettimeofday(&inicio, NULL);
	for(i=0;i<n;i++){
		random=rand()%index;
		fseek(fp,random,0);
		for(j=0;j<1000;j++){
			fprintf(fp,"c");
		}
	}
	gettimeofday(&final, NULL);
    tmili = (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    seconds=tmili/1000;
    mbs=(n/1000)/seconds;
    printf("Tempo medio de escrita aleatoria: %f \n",mbs);
	fclose(fp);
}
