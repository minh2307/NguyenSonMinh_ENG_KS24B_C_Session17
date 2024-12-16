#include <stdio.h>
#include <ctype.h>
#include <string.h>
void menu();
void addItem(char *str);
void show(char *str);
int countCharacter(char *str);
int countNumber(char *str);
int countSpecial(char *str);
int main(){ 
	int choice;
	char str[100]="";
	do{	
		menu();
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
	switch(choice){
		case 1:
			addItem(str);
		break;
		
		case 2:
			show(str);
		break;
		
		case 3:
			countCharacter(str);
		break;
		
		case 4:
			countNumber(str);
		break;
		
		case 5:
			countSpecial(str);
		break;
		
		default:
			printf("Moi ban lua chon lai\n");
		break;
	}
	}while(choice!=6);


return 0;
}

void menu(){
	printf("\n\tMENU \n");
	printf("1.Nhap vao chuoi\n");
	printf("2.In ra chuoi\n");
	printf("3.Dem so luong chu cai\n");
	printf("4.Dem so luong chu so trong chuoi\n");
	printf("5.Dem so luong ky tu dac biet trong chuoi\n");
	printf("6.Thoat\n");

}

void addItem(char *str){
	printf("nhap chuoi cua ban: ");
	fflush(stdin);
	fgets(str,100,stdin);
}

void show(char *str){
	fputs(str,stdout);
}

int countCharacter(char *str){
	int count = 0;
	for(int i=0;str[i] != '\0';i++){
		if(isalpha(str[i])){
			count++;
		}
	}
	return count;
}

int countNumber(char *str){
	int count=0;
	for(int i=0;str[i] != '\0';i++){
		if(isalnum(str[i])){
			count++;
		}
	}
	return count;
}

int countSpecial(char *str){
	int count=0;
	for(int i=0;str[i] != '\0';i++){
		if(!isalpha(str[i])&&!isalnum(str[i])){
			count++;
		}
	}
	return count;
}
