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
	fptr=fopen("students.txt","w");
	struct Student students[50];
	int i=0,n;
	printf("vui long nhap so hoc sinh: ");
	scanf("%d",&n);
	while(i<n){
		printf("vui long nhap id: ");
		scanf("%d",&students[i].id);
		fflush(stdin);
		printf("	vui long nhap ten: ");
		fgets(students[i].name,sizeof students[i].name,stdin);
		students[i].name[strcspn(students[i].name,"\n")]='\0';
		printf("	vui long nhap tuoi: ");
		scanf("%d",&students[i].age);
		fflush(stdin);
		printf("	vui long nhap so dien thoai: ");
		fgets(students[i].phoneNumber,sizeof students[i].phoneNumber,stdin);
		i++;
	}
	i=0;
	while(i<n){
		fprintf(fptr,"id: %d/ho va ten: %s/tuoi: %d/so dien thoai: %s",students[i].id,students[i].name,students[i].age,students[i].phoneNumber);
		i++;
	}
	fclose(fptr);
	return 0;
}
