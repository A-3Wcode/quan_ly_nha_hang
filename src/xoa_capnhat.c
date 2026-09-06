#include "../include/nha_hang.h"

// 5. Cap nhat va Xoa phan tu
bool capNhatMonAn(TD *td, char ma[]){
	if (td == NULL || td->head == NULL) {
        printf("Thuc don rong!\n");
        return false;
    }
	
	MA *mon = timKiemTheoMa(td, ma);
	if (mon == NULL) {
        return false;
    }
	
	char ten[50];
	char loai[30];
	double gia;
	int choose = 0;
	
	do{
		printf("\n=== CHON THONG TIN CAN CAP NHAT (%s) ===\n", mon->MaMon);
        printf("1. Cap nhat Ten mon\n");
        printf("2. Cap nhat Loai mon\n");
        printf("3. Cap nhat Gia tien\n");
        printf("0. Hoan tat & Thoat\n");
        printf("Lua chon: ");
		int hopLe = 0;
        do{
            if(scanf("%d", &choose) != 1) {
                printf("Lua chon khong hop le! Vui long nhap lai: ");
                while (getchar() != '\n');
            } else {
                hopLe = 1;
            }
        }while(!hopLe);
		
		switch(choose){
			case 1:{
				printf("Nhap ten mon moi: ");
                while (getchar() != '\n');
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
    			strcpy(mon->Ten, ten);
                printf("Cap nhat Ten thanh cong!\n");
                break;
			}
			case 2:{
				printf("Nhap loai mon moi: ");
                while (getchar() != '\n');
                fgets(loai, sizeof(loai), stdin);
                loai[strcspn(loai, "\n")] = '\0';
                strcpy(mon->Loai, loai);
                printf("Cap nhat Loai thanh cong!\n");
                break;
			}
			case 3:{
				int hopLeGia = 0;
                do{
                    printf("Nhap gia tien moi: ");
                    if(scanf("%lf", &gia) != 1 || gia < 0) {
                        printf("Gia tien khong hop le! Vui long nhap lai.\n");
                        while (getchar() != '\n');
                    } else {
                        hopLeGia = 1;
                    }
                }while(!hopLeGia);
                
                mon->Gia = gia;
                printf("Cap nhat Gia thanh cong!\n");
                break;
			}
			
			case 0:{
				printf("Thoat cap nhat mon!\n");
				break;
			}
			default:{
				printf("Lua chon khong hop le!\n");
				break;
			}   
		}
	}while(choose != 0);
	
	return true;
}

bool xoaTheoMa(TD *td, char ma[]){
	if(td == NULL || td->head == NULL) return false;
	
	MA *current = td->head;
	MA *truoc = NULL;
	
	if(strcmp(current->MaMon, ma) == 0){
		td->head = current->next;

        if(td->head == NULL) {
            td->tail = NULL; 
        }

		free(current);
		td->count--;
		return true;
	}
	
	while(current != NULL && strcmp(current->MaMon, ma) != 0) {
        truoc = current;
        current = current->next;
    }
	
	if(current == NULL) return false;

    truoc->next = current->next;

    if(current == td->tail) {
        td->tail = truoc; 
    }

    free(current);
    td->count--;

    return true;
}

int xoaTheoTen(TD *td, char ten[]){
    if(td == NULL || td->head == NULL) return 0;

    int soLuongDaXoa = 0;
    MA *current = td->head;
    MA *truoc = NULL;

    while(current != NULL){
        if(strcmp(current->Ten, ten) == 0){
            MA *temp = current;

            if(truoc == NULL){
                td->head = current->next;
                current = td->head;
            }else{
                truoc->next = current->next;
                current = current->next;
            }

            if(temp == td->tail){
                td->tail = truoc;
            }

	        free(temp);
	        td->count--;
	        soLuongDaXoa++;
        }else{
            truoc = current;
            current = current->next;
        }
    }

    if(td->head == NULL){
        td->tail = NULL;
    }

    return soLuongDaXoa;
}
