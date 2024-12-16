#include <stdio.h>

int a[100],size,sum=0,max=a[0];
void Menu();
void addItem();
void showItem();
int sumArr();
int find();

int main(){
	int choice;
	do{
		Menu();
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
	switch(choice){
		case 1:
			addItem();
		break;
		
		case 2:
			showItem();
		break;
		
		case 3:
			printf("Do dai cua mang la %d\n",size);
		break;
		
		case 4:		
			printf("Tong cua cac phan tu trong mang la %d",sumArr());
		break;	
		
		case 5: 
			printf("Phan tu lon nhat trong mang la %d",find());
		break;
		
		default:
			printf("Moi ban lua chon lai\n");
		break;
	}
	}while(choice!=6);
		
		


return 0;
}

void Menu(){
	printf("\tMENU \n");
	printf("1.Nhap so phan tu va tung phan tu\n");
	printf("2.Hien thi cac phan tu trong mang\n");
	printf("3.Tinh do dai mang\n");
	printf("4.Tinh tong cac phan tu trong mang\n");
	printf("5.Hien thi phan tu lon nhat\n");
	printf("6.Thoat\n");

}

void addItem(){
		printf("Nhap Vao Phan tu muon them: ");
		scanf("%d",&size);
	for(int i=0;i<size;i++){
		printf("Nhap vao gia tu thu %d trong mang: ",i);
		scanf("%d",&a[i]);
	}
}

void showItem(){
	for(int i=0;i<size;i++){
		printf("a[%d] = %d\n",i,a[i]);
	}
}

int sumArr(){
	for(int i=0;i<size;i++){
		sum+=a[i];
	}
return sum;
}

int find(){
	for(int i=0;i<size;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
return max;
}
