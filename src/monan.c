
#include "../include/nha_hang.h"
#include <ctype.h>
/*Thuc hien: Nguyen Tai Nang*/
// 1. Khoi tao va quan ly bo nho
bool laChuoiSo(const char *s){
    if(s == NULL || strlen(s) == 0) return false;
	for(int i = 0; s[i] != '\0'; i++){
		if(!isdigit((unsigned char )s[i])){
			return false;
		}
	}
	return true;
}

bool TenVaLoaiHopLe(const char *s){
	if( s == NULL || strlen(s) == 0) return false;
	bool coKyTu = false;
	for(int i = 0; s[i] != '\0'; i++){
		if(isdigit((unsigned char)s[i])){
			return false;
		}
		if(!isspace((unsigned char)s[i])){
			coKyTu = true;
		}
	}
	return coKyTu;
}


MA* taoMonAn(char ma[], char ten[], char loai[], double gia){
    MA* mon =(MA*)malloc(sizeof(MA)); 
    if(mon == NULL){                    
        printf("Loi cap phat bo nho!\n"); 
		return NULL;
    }
    strncpy(mon->MaMon, ma, sizeof(mon->MaMon) - 1);
	mon->MaMon[sizeof(mon->MaMon) - 1] = '\0';
	  
    strncpy(mon->Ten, ten, sizeof(mon->Ten) - 1);
    mon->Ten[sizeof(mon->Ten) - 1] = '\0';
    
    strncpy(mon->Loai, loai, sizeof(mon->Loai) -  1);
    mon->Loai[sizeof(mon->Loai) -  1] = '\0';
    
    mon->Gia = gia;
    mon->next = NULL;          
    return mon;
}

void khoiTaoThucDon(TD *td){
    if(td != NULL){    
        td->head = NULL;
        td->tail = NULL;
        td->count = 0;
    }
}
void giaiPhongThucDon(TD *td){
	if(td == NULL) return;
	
    MA *current = td->head;             
    while(current != NULL){
        MA *temp = current;             
        current = current->next;        
        free(temp);                     
    }
    td-> head = NULL;  
	td->tail = NULL;                 
    td->count = 0;                     
}

// 2. Nhap va Them mon
bool kiemTraTrungMa(TD *td, char ma[]){
    if(td == NULL || td->head == NULL) return false;
    MA *p = td->head;
    while(p != NULL){
        if(strcmp(p->MaMon, ma) == 0) return true;  
        p = p->next; 
	}
    return false;
}

bool themMonAn(TD *td, MA *monMoi){
    if(td == NULL || monMoi == NULL) return false;
    if(kiemTraTrungMa(td, monMoi -> MaMon)) return false;
    
    if(td -> head == NULL ){
    	td->head = monMoi;
    	td->tail = monMoi;
    } else {
    	td->tail->next = monMoi;
		td->tail = monMoi;  
    }
    td->count++; 
    return true;
}

bool kiemTraMonHopLe(char ma[], char ten[], double gia){
	if(ma == NULL || strlen(ma) == 0 || strlen(ma) >= 15){
		printf("Loi ky tu vuot qua gioi han cho phep, xin vui long nhap lai!\n");
		return false;
	}
	if(ten == NULL || strlen(ten) == 0){
		printf("Loi ky tu vuot qua gioi han cho phep, xin vui long nhap lai!\n");
		return false;
	}
	if(gia <= 0 ){
		printf("Loi: Gia mon khong hop le!\n");
		return false;
	}
	return true;
	
}
void xoaBoDem(void){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}
void nhapDanhSachMonAn(TD *td){
	if (td == NULL){
		return;
	}
	
    char tieptuc;
    int i = 0;
        
    do{
    	char ma[15], ten[50], loai[30]; 
        double gia;
        printf("\n---Nhap mon an thu %d---\n", i+1);
        
    	do{
            printf("Nhap ma mon an (toi da 14 ky tu): ");
            if(fgets(ma, sizeof(ma), stdin) == NULL) continue;

            char *pos = strchr(ma, '\n');
            if(pos != NULL){
            	*pos = '\0';
			}else{
				xoaBoDem();
				printf("Loi ky tu vuot qua gioi han cho phep! Xin vui long nhap lai!");
				continue;
			}
			if(strlen(ma) == 0){
				printf("Ma khong duoc bo trong!\n");
			}else if(!laChuoiSo(ma)){
				printf("Ma mon an phai la chuoi so!Vui long nhap lai!\n");
			}else if(kiemTraTrungMa(td, ma)){
				printf("Ma mon da ton tai!Vui long nhap la ma.\n");
			}else{
				break;
			}
        }while(1);
        
        do{
        	printf("Nhap ten mon an: ");
        	if(fgets(ten, sizeof(ten), stdin) == NULL) continue;
        	
        	char *pos = strchr(ten, '\n');
        	if(pos != NULL){
        		*pos = '\0';
			}else{
				xoaBoDem();
				printf("Loi ky tu qua gioi han cho phep, xin vui long nhap lai!\n");
				continue;
			}
			if(strlen(ten) == 0){
				printf("Ten mon khong duoc de trong.Vui long nhap lai!\n");
			}else if(!TenVaLoaiHopLe(ten)){
				printf("Ten mon khong hop le!Vui long nhap lai!\n");
			}else{
				break;
			}
		}while(1);
		
		do{
			printf("Nhap loai mon an: ");
			if(fgets(loai, sizeof(loai), stdin) == NULL) continue;
			char *pos = strchr(loai, '\n');
			if(pos != NULL){
				*pos = '\0';
			}else{
				xoaBoDem();
				printf("Loi ky tu vuot qua gioi han cho phep! Xin vui long nhap lai!\n");
				continue;
			}
			if(strlen(loai) == 0){
				printf("Loai mon khong duoc de trong!Vui long nhap lai!\n");
			}else if(!TenVaLoaiHopLe(loai)){
				printf("Loai mon khong hop le!Vui long nhap lai!\n");
			}else{
				break;
			}
		}while(1);
		
		do{
			printf("Nhap gia mon an (>0): ");
			if(scanf("%lf", &gia) != 1){
				printf("Loi: Gia tien phai la dinh dang so!Vui long nhap lai!\n");
				xoaBoDem();
				continue;
			}
			xoaBoDem();
			
			if(gia <= 0){
				printf("Loi: Gia mon phai lon hon 0!Vui long nhap lai.\n");
			}else{
				break;
			}
		}while(1);
		
    	
		if(kiemTraMonHopLe(ma, ten, gia)){
			MA *monMoi = taoMonAn(ma, ten, loai, gia);
        	if(!themMonAn(td, monMoi)){
            	printf("Them mon an that bai!\n");
            	free(monMoi);
			}else{
				printf("Them mon an thanh cong!\n");
				i++;
			}
        }
		do{
			printf("\nBan co muon nhap tiep khong? (y/n): ");
			scanf(" %c", &tieptuc);
			while(getchar() != '\n');
			
			if(tieptuc == 'y' || tieptuc == 'Y' || tieptuc == 'n' || tieptuc == 'N'){
				break;
			}
			printf("Vui long chi nhap 'y' hoac 'n'!\n");
		}while(1);
		
    }while(tieptuc == 'y' || tieptuc == 'Y');
    printf("Da xong qua trinh nhap danh sach mon an\n");
}

// 3. Hien thi
void hienThiMonAn(MA *mon){
    if(mon == NULL) return;
    printf("| %-12s | %-25s | %-15s | %-10.2f |\n", mon->MaMon, mon->Ten, mon->Loai, mon->Gia);
}
void hienThiThucDon(TD *td){
    if(td == NULL || td->head == NULL){
        printf("Thuc don hien dang trong!\n");
        return;
    }
    printf("\n---------------------------DANH SACH THUC DON------------------------------\n");
    printf("| %-12s | %-25s | %-15s | %-10s |\n", "Ma Mon", " Ten","Loai", "Gia");
    printf("---------------------------------------------------------------------------\n");
    MA *p = td->head;
    while(p != NULL){
        hienThiMonAn(p);
        p = p->next;
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Tong so mon an: %d\n", td->count);

}
