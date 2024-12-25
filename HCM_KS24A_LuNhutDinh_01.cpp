	#include <stdio.h>
	#define maxSize 100 // so phan tu toi da cua mang
	
	int main(){
		int arr[maxSize]={0};
		int choice=0,currentSize=0;
		do{
			printf("==========MENU==========\n");
			printf("1. Nhap so phan tu va gia tri cho mang\n");
			printf("2. In ra gia tri cac phan tu tu co trong mang\n");
			printf("3. Tim ra gia tri nho nhat va lon nhat co trong mang\n");
			printf("4. In ra tong cac phan tu\n");
			printf("5. Them vao mot phan tu vao cuoi mang\n");
			printf("6. Xoa phan tu tai vi tri cu the\n");
			printf("7. Sap xep mang theo thu tu giam dan (Bubble Sort)\n");
			printf("8. Kiem tra su ton tai cua phan tu trong mang (Linear search)\n");
			printf("9. In ra toan bo so nguyen to trong mang\n");
			printf("10. Sap xep mang theo thu tu tang dan (Selection sort)\n");
			printf("11. Thoat\n");
			printf("Lua chon cua ban: ");	scanf("%d",&choice);
			printf("\n");
			switch(choice){
				case 1://Nhap so phan tu va gia tri cho mang
					{
						currentSize = 0;
						printf("Moi nhap vao so phan tu (1->100): ");	scanf("%d", &currentSize);
						
						while(currentSize <= 0 || currentSize > 100){
							printf("So phan tu ban nhap khong hop le vui long nhap lai (1->100): ");
							scanf("%d",&currentSize);
						}
						printf("So phan tu ban nhap vao hop le !!!\n");
						
						for(int i=0;i<currentSize;i++){
							printf("Moi nhap vao gia tri phan tu arr[%d]: ",i);
							scanf("%d",arr+i);
						}
						printf("Mang da duoc nhap xong !!!");
					}
					break;
				case 2://In ra gia tri cac phan tu tu co trong mang
					{
						if(currentSize != 0){
							printf("Gia tri cua cac phan tu trong mang: ");
							for(int i=0;i<currentSize;i++){
								printf("arr[%d] = %d",i,arr[i]);
								if(i < currentSize-1){
									printf(", ");
								}
							}
						}
					}
					break;
				case 3://Tim ra gia tri nho nhat va lon nhat co trong mang
					{
						if(currentSize != 0){
							int min=arr[0],max=arr[0];
							
							for(int i=1;i<currentSize;i++){
								if(min > arr[i]){
									min = arr[i];
								}
								if(max < arr[i]){
									max = arr[i];
								}
							}
							
							printf("Phan tu nho nhat trong mang: %d\n",min);
							printf("Phan tu lon nhat trong mang: %d",max);
						}
					}
					break;
				case 4://In ra tong cac phan tu
					{
						if(currentSize != 0){
							int sum=0;
							printf("Bat dau thuc hien thao tac tinh tong:\n");
							for(int i=0;i<currentSize;i++){
								sum+=arr[i];
							}
							printf("Thao tac tinh tong da xong !!!\n");
							printf("Tong gia tri cac phan tu trong mang: %d", sum);
						}
					}
					break;
				case 5://Them vao mot phan tu vao cuoi mang
					{
						if(currentSize != 0){
							int addValue=0;
							printf("Moi ban nhap vao gia tri phan tu ban muon them vao cuoi mang: ");	scanf("%d",&addValue);
							arr[currentSize] = addValue;
							printf("Da them xong !!!");
							currentSize++;
						}
					}
					break;
				case 6://Xoa phan tu tai vi tri cu the
					{
						if(currentSize != 0){
							int deleteIndex=0;
							printf("Moi nhap vao vi tri ban muon xoa(0 -> %d): ",currentSize-1);	scanf("%d", &deleteIndex);
							while(deleteIndex < 0 || deleteIndex > currentSize-1){
								printf("Vi tri ban nhap vao khong ton tai vui long nhap lai(0 -> %d): ",currentSize-1);
								scanf("%d",&deleteIndex);
							}
							
							printf("Vi tri nhap vao hop le !!!\n");
							printf("Bat dau xoa\n");
							
							currentSize--;
							
							for(int i=deleteIndex;i<currentSize;i++){
								arr[i] = arr[i+1];
							}
							printf("Da xoa xong !!!");
						}
					}
					break;
				case 7://Sap xep mang theo thu tu giam dan (Bubble Sort)
					{
						if(currentSize != 0){
							printf("Bat dau sap xep mang\n");
							for(int i=0;i<currentSize-1;i++){
								for(int j=0;j<currentSize-i-1;j++){
									if(arr[j] < arr[j+1]){
										int tmp=arr[j];
										arr[j]=arr[j+1];
										arr[j+1]=tmp;
									}
								}
							}
							printf("Da xap xep xong !!!");
						}
					}
					break;
				case 8://Kiem tra su ton tai cua phan tu trong mang (Linear search)
					{
						if(currentSize != 0){
							int checkNumber=0,flag=0;
							printf("Moi ban nhap vao gia tri phan tu ban muon kiem tra: ");	scanf("%d", &checkNumber);
							for(int i=0;i<currentSize;i++){
								if(checkNumber == arr[i]){
									flag = 1;
									break;
								}
							}
							if(flag == 1){
								printf("Phan tu nay co ton tai trong mang !!!");
							}
							else{
								printf("Phan tu nay khong ton tai trong mang !!!");
							}
						}
					}
					break;
				case 9://In ra toan bo so nguyen to trong mang
					{
						if(currentSize != 0){
							int flag = 1,countPrime=0;
							for(int i=0;i<currentSize;i++){
								flag = 1;
								if(arr[i] < 2){
									continue;
								}
								
								for(int j=2;j*j<=arr[i];j++){
									if(arr[i] % j == 0){
										flag = 0;
										break;
									}
								}
								
								if(flag == 1){
									if(i == 0){
										printf("Day la tat ca so nguyen to trong mang: ");
									}
									printf("%d ",arr[i]);
									countPrime++;
								}
							}
							if(countPrime == 0){
								printf("Khong co so nguyen to nao trong mang !!!");
							}
						}
					}
					break;
				case 10://Sap xep mang theo thu tu tang dan (Selection sort)
					{
						if(currentSize != 0){
							printf("Bat dau sap xep\n");
							for(int i=0;i<currentSize-1;i++){
								int minIndex=i;
								for(int j=i+1;j<currentSize;j++){
									if(arr[minIndex] > arr[j]){
										minIndex = j;
									}
								}
								int tmp=arr[i];
								arr[i] = arr[minIndex];
								arr[minIndex] = tmp;
							}
							printf("Da sap xep xong !!!");
						}
					}
					break;
				case 11://Thoat
					{
						printf("Chuong trinh ket thuc !!!");
					}
					break;
				default:
					printf("Lua chon cua ban khong hop le vui long nhap lai !!!");
				
			}
			if(currentSize == 0 && choice != 11){
				printf("\nMang cua ban dang rong vui long nhap mang truoc khi thuc hien thao tac !!!");
			}
			printf("\n\n");
		}while(choice!=11);
		
		return 0;
	}
