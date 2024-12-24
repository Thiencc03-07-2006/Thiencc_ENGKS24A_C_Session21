#include <stdio.h>
#include <string.h>

struct Student{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

int main(){
	FILE *fptr;
	fptr=fopen("students.txt","r");
	struct Student students[50];
	int i=0,n=0;
	char string[100];
	while(fgets(string, sizeof string, fptr) != NULL){
		sscanf(string,"id: %d/ho va ten: %49[^/]/tuoi: %d/so dien thoai: %14[^\n]",&students[i].id,students[i].name,&students[i].age,students[i].phoneNumber);
		i++;
		n++;
	}
	fclose(fptr);
	i=0;
	while(i<n){
		printf("id: %d	ho va ten: %s	tuoi: %d	so dien thoai: %s\n",students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
		i++;
	}
	return 0;
}
