#include <stdio.h>
#include <string.h>

struct Library {
    int bookCode;
    char bookTitle[50];
    char author[50];
    float price;
    char genre[50];
};

struct Library books[100];
int n = 0;

void inputBooks();

void saveBooks();

void loadBooks();

void printBooks();

int main() {
    int type;
    do{
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&type);
        fflush(stdin);
        switch(type){
            case 1:
                inputBooks();
                break;
            case 2:
                saveBooks();
                break;
            case 3:
                loadBooks();
                break;
            case 4:
                printBooks();
                break;
        }
    }while(type!=5);
    return 0;
}

void inputBooks(){
    printf("Nhap so luong sach: ");
    scanf("%d",&n);
    fflush(stdin);
    int i=0;
    while(i<n){
        printf("Ma sach: ");
        scanf("%d",&books[i].bookCode);
        fflush(stdin);
        printf("	Ten sach: ");
        fgets(books[i].bookTitle,50,stdin);
        books[i].bookTitle[strcspn(books[i].bookTitle,"\n")]='\0';
        printf("	Tac gia: ");
        fgets(books[i].author,50,stdin);
        books[i].author[strcspn(books[i].author,"\n")]='\0';
        printf("	Gia tien: ");
        scanf("%f",&books[i].price);
        fflush(stdin);
        printf("	The loai: ");
        fgets(books[i].genre,50,stdin);
        books[i].genre[strcspn(books[i].genre,"\n")]='\0';
        i++;
    }
}

void saveBooks(){
    FILE *fptr=fopen("library.bin","wb");
    fwrite(&n,sizeof(int),1,fptr);
    fwrite(books,sizeof(struct Library),n,fptr);
    fclose(fptr);
}

void loadBooks() {
    FILE *fptr=fopen("library.bin","rb");
    fread(&n,sizeof(int),1,fptr);
    fread(books,sizeof books,n,fptr);
    fclose(fptr);
}

void printBooks(){
    printf("Danh sach sach:\n");
    int i=0;
    while(i<n){
        printf("Sach %d:\n",i+1);
        printf("	Ma sach: %d\n",books[i].bookCode);
        printf("	Ten sach: %s\n",books[i].bookTitle);
        printf("	Tac gia: %s\n",books[i].author);
        printf("	Gia tien: %.2f\n",books[i].price);
        printf("	The loai: %s\n",books[i].genre);
        i++;
    }
}

