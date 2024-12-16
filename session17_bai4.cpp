#include <stdio.h>

void menu();
void inputArray(int **arr, int *size);
void printEvenNumbers(const int *arr, int size);
void printPrimeNumbers(const int *arr, int size);
int isPrime(int n); 
void reverseArray(int *arr, int size);
void sortArray(int *arr, int size, int ascending);
void findElement(const int *arr, int size);

int main() {
    int *arr = 0; 
    int size = 0;    
    int choice;

    do {
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&arr, &size);
                break;
            case 2:
                printEvenNumbers(arr, size);
                break;
            case 3:
                printPrimeNumbers(arr, size);
                break;
            case 4:
                reverseArray(arr, size);
                printf("Mang sau khi duoc dao nguoc: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 5: {
                int subChoice;
                printf("1.Sap xep tang dan\n");
                printf("2.Sap xep giam dan\n");
                printf("lua chon cua ban: ");
                scanf("%d", &subChoice);
                sortArray(arr, size, subChoice == 1);
                printf("Mang sau khi sap xep: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 6:
                findElement(arr, size);
                break;
            case 7:
                printf("thoat  truong trinh.\n");
                break;
            default:
                printf("Lua chon lai!\n");
                break;
        }
    } while (choice != 7);


    return 0;
}


void menu() {
    printf("\n\tMENU\n");
    printf("1.Nhap vao so phan tu va tung phan tu\n");
    printf("2.In ra cac phan tu la so chan\n");
    printf("3.In ra cac phan tu la so nguyen to\n");
    printf("4.Dao nguoc mang\n");
    printf("5.Sap xep mang\n");
    printf("\t1.Tang dan\n");
    printf("\t2.Giam dan\n");
    printf("6.Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
    printf("7. thoat\n");
}


void inputArray(int **arr, int *size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);

    if (*size <= 0) {
        printf("So luong phan tu lon hon\n");
        return;
    }

    
    if (*arr == NULL) {
        printf("mang trong\n");
        return;
    }

    for (int i = 0; i < *size; i++) {
        printf("phan tu [%d]: ", i);
        scanf("%d", &(*arr)[i]);
    }
}


void printEvenNumbers(const int *arr, int size) {
    printf("cac phan tu la so chan: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}


int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


void printPrimeNumbers(const int *arr, int size) {
    printf("cac phan tu la so nguyen to: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}


void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}


void sortArray(int *arr, int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void findElement(const int *arr, int size) {
    int target;
    printf("nhap phan tu can tim: ");
    scanf("%d", &target);

    int found = 0;
    printf("phan tu %d xuat hien tai ca vi tri: ", target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", target);
    } else {
        printf("\n");
    }
}

