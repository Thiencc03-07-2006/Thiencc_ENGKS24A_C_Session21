#include <stdio.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr=fopen("bt05.txt","w");
	char string[100];
	int i=1,n;
	printf("vui long nhap: ");
	scanf("%d",&n);
	fflush(stdin);
	while(i<=n){
		printf("vui long nhap vao dong[%d]: ",i);
		fgets(string,sizeof string,stdin);
		fprintf(fptr,"%s",string);
		i++;
	}
	fclose(fptr);
	fptr=fopen("bt05.txt","r");
	i=1;
	while(i<=n){
		fgets(string,sizeof string,fptr);
		printf("dong [%d] la %s",i,string);
		i++;
	}
	fclose(fptr);
	return 0;
}
