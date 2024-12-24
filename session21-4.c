#include <stdio.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr=fopen("bt01.txt","r");
	char string[100];
	fgets(string,sizeof string,fptr);
	printf("dong dau tien la %s",string);
	fclose(fptr);
	return 0;
}
