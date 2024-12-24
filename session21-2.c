#include <stdio.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr=fopen("bt01.txt","r");
	char oneChar;
	oneChar=fgetc(fptr);
	printf("ki tu dau tien la %c",oneChar);
	fclose(fptr);
	return 0;
}
