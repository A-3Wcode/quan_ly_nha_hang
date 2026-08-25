#include "../include/nha_hang.h"

// 4. Tim kiem
MA* timKiemTheoMa(TD *td, char ma[]){
	if(td == NULL || td->head == NULL) return NULL;
	
	MA* troDuyet = td->head;
	while(troDuyet != NULL){
		if(strcmp(troDuyet->MaMon, ma) == 0){
			return troDuyet;
		}
		troDuyet = troDuyet->next;
	}
	return NULL;
}

TD timKiemTheoTen(TD *td, char ten[]){
	TD ketQua;
	ketQua.head = NULL;
	ketQua.count = 0;
	
	if (td == NULL || td->head == NULL) return ketQua;
	
	MA *troDuyet = td->head;
	while(troDuyet != NULL){
		if(strstr(troDuyet->Ten, ten) != NULL){
			MA *monTimThay = taoMonAn(troDuyet->MaMon, 
				troDuyet->Ten, troDuyet->Loai, troDuyet->Gia);
				themMonAn(&ketQua, monTimThay);
		}
		troDuyet = troDuyet->next;
	}
	return ketQua;
}

TD timKiemTheoLoai(TD *td, char loai[]){
	TD ketQua;
	ketQua.head = NULL;
	ketQua.count = 0;
	
	if (td == NULL || td->head == NULL) return ketQua;
	
	MA *troDuyet = td->head;
	while(troDuyet != NULL){
		if(strstr(troDuyet->Loai, loai) != NULL){
			MA *monTimThay = taoMonAn(troDuyet->MaMon, 
				troDuyet->Ten, troDuyet->Loai, troDuyet->Gia);
				themMonAn(&ketQua, monTimThay);
		}
		troDuyet = troDuyet->next;
	}
	return ketQua;
}

TD timKiemTheoKhoangGia(TD *td, double giaMin, double giaMax){
	TD ketQua;
	ketQua.head = NULL;
	ketQua.count = 0;
	
	if (td == NULL || td->head == NULL) return ketQua;
	
	MA *troDuyet = td->head;
	while(troDuyet != NULL){
		if(troDuyet->Gia >= giaMin && troDuyet->Gia <= giaMax){
			MA *monTimThay = taoMonAn(troDuyet->MaMon, 
				troDuyet->Ten, troDuyet->Loai, troDuyet->Gia);
				themMonAn(&ketQua, monTimThay);
		}
		troDuyet = troDuyet->next;
	}
	return ketQua;
}

// 6. Cap nhat va Sap xep
bool capNhatMonAn(TD *td, char ma[]){
	if (td == NULL || td->head == NULL) {
        printf("Thuc don rong!\n");
        return false;
    }
	
	MA *mon = timKiemTheoMa(td, ma);
	if (mon == NULL) {
        printf("Khong tim thay mon an co ma %s!\n", ma);
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
        printf("4. Cap nhat Tat ca\n");
        printf("0. Hoan tat & Thoat\n");
        printf("Lua chon: ");
		
		if (scanf("%d", &choose) != 1) {
            getchar();
            continue;
        }
        getchar();
        
		switch(choose){
			case 1:{
				printf("Nhap ten mon moi: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
    			strcpy(mon->Ten, ten);
                printf("Cap nhat Ten thanh cong!\n");
                break;
			}
			case 2:{
				printf("Nhap loai mon moi: ");
                fgets(loai, sizeof(loai), stdin);
                loai[strcspn(loai, "\n")] = '\0';
                strcpy(mon->Loai, loai);
                printf("Cap nhat Loai thanh cong!\n");
                break;
			}
			case 3:{
				do {
                    printf("Nhap gia tien moi (>0): ");
                    scanf("%lf", &gia);
                    getchar();
                    if (gia <= 0) printf("Gia phai lon hon 0!\n");
                }while (gia <= 0);
                mon->Gia = gia;
                printf("Cap nhat Gia thanh cong!\n");
                break;
			}
			case 4:{
				printf("Nhap ten mon moi: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
                strcpy(mon->Ten, ten);

                printf("Nhap loai mon moi: ");
                fgets(loai, sizeof(loai), stdin);
                loai[strcspn(loai, "\n")] = '\0';
                strcpy(mon->Loai, loai);
                
                do {
                    printf("Nhap gia tien moi (>0): ");
                    scanf("%lf", &gia);
                    getchar();
                    if (gia <= 0) printf("Gia phai lon hon 0!\n");
                } while (gia <= 0);
                mon->Gia = gia;

                printf("Cap nhat tat ca thong tin thanh cong!\n");
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

void sapXepTheoMa(TD *td, bool tangDan);
void sapXepTheoTen(TD *td, bool tangDan);
void sapXepTheoGia(TD *td, bool tangDan);
