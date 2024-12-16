#include <stdio.h>
#include <string.h>
#include <ctype.h>


void menu();
void inputString(char *str);
void printReversedString(const char *str);
int countCharacter(const char *str);
void compareStrings(const char *original, char *other);
void convertToUpper(char *str);
void appendString(char *original, const char *additional);

int main() {
    int choice;
    char Str[500] = ""; 
    char compareStr[500] = "";  

    do {
        menu();
        printf("lua chon cua ban: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                inputString(Str);
                break;
            case 2:
                printReversedString(Str);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", countCharacter(Str));
                break;
            case 4:
                printf("Nhap chuoi khac de so sanh: ");
                fflush(stdin);
                fgets(compareStr, sizeof(compareStr), stdin);
                
                break;
            case 5:
                convertToUpper(Str);
                printf("Chuoi sau khi chuyen thanh in hoa: %s\n", Str);
                break;
            case 6:
                printf("Nhap chuoi khac de them vao: ");
                fflush(stdin);
                fgets(compareStr, sizeof(compareStr), stdin);
                
                break;
           
            default:
                printf("Lua chon lai!\n");
        }

    } while(choice != 7);

    return 0;
}

void menu() {
    printf("\n\tMENU\n");
    printf("1.Nhap vao chuoi\n");
    printf("2.In ra chuoi dao nguoc\n");
    printf("3.Dem so luong tu trong chuoi\n");
    printf("4.Nhap vao chuoi khac,so sanh chuoi\n");
    printf("5.in hoa cac chu cai dau tien\n");
    printf("6.Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
    printf("7.thoat\n");
}

void inputString(char *str) {
    printf("Nhap chuoi cua ban: ");
    fflush(stdin);
    fgets(str, 500, stdin);
    str[strcspn(str, "\n")] = '\0'; 
}

void printReversedString(const char *str) {
    int len = strlen(str);
    printf("chuoi dao nguoc: ");
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", *(str + i)); 
    }
    printf("\n");
}


int countCharacter(const char *str) {
    int count = 0;
    int inWord = 0;

    while(*str) {
        if(!isspace(*str)) { 
            if(!inWord) {     
                count++;
                inWord = 1;
            }
        }
        else {
            inWord = 0; 
        }
        str++;
    }

    return count;
}


void compareStrings(const char *original, char *other) {
    int lenOriginal = strlen(original);
    int lenOther = strlen(other);

    if(lenOther < lenOriginal) {
        printf("Chu?i m?i ng?n hon chu?i ban d?u.\n");
    }
    else if(lenOther > lenOriginal) {
        printf("Chu?i m?i dài hon chu?i ban d?u.\n");
    }
    else {
        printf("Chu?i m?i có d? dài b?ng chu?i ban d?u.\n");
    }
}


void convertToUpper(char *str) {
    while(*str) {
        *str = toupper(*str);
        str++;
    }
}


void appendString(char *original, const char *additional) {
    while(*original) { 
        original++;
    }
    while(*additional) { 
        *original = *additional;
        original++;
        additional++;
    }
    *original = '\0'; 
}


