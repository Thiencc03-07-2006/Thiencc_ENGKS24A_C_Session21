#include <stdio.h>
#include <string.h>

int main(){
	FILE *fptr1;
	FILE *fptr2;
	fptr1=fopen("bt06.txt","w");
	fptr2=fopen("bt01.txt","r");
	char string[100];
	while(fgets(string,sizeof string,fptr2)!=NULL){
		fprintf(fptr1,"%s",string);
	}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
