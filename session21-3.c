#include <stdio.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr=fopen("bt01.txt","a");
	char string[100];
	printf("vui long nhap chuoi muon them vao: ");
	fgets(string,sizeof string,stdin);
	string[strcspn(string,"\n")]='\0';
	fprintf(fptr,"%s",string);
	fclose(fptr);
	return 0;
}
