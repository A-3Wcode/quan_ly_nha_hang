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

// 6. Sap xep
void chiaDoiDanhSach(MA *mon, MA **dsTruoc, MA **dsSau){
	if(mon == NULL || mon->next == NULL){
		return;
	}
	
	MA *slow = mon;
	MA *fast = mon->next;
	
	while(fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*dsTruoc = mon;
	*dsSau = slow->next;
	slow->next = NULL;
}

bool soSanhMonAn(MA *a, MA *b, int tieuChuan, bool tangDan){
	int temp = 0;
	
	switch(tieuChuan){
		case 1:{
			temp = strcmp(a->MaMon, b->MaMon);
			break;
		}
		case 2:{
			temp = strcmp(a->Ten, b->Ten);
			break;
		}
		case 3:{
			if(a->Gia < b->Gia) temp = -1;
			else if(a->Gia > b->Gia) temp = 1;
			else temp = 0;
			break;
		}
	}
	
	return tangDan? (temp<=0) : (temp>=0);
}

MA* tron2DanhSach(MA *a, MA *b, int tieuChuan, bool tangDan){
	if(a == NULL) return b;
	if(b == NULL) return a;
	
	MA *ketQua = NULL;
	
	if(soSanhMonAn(a, b, tieuChuan, tangDan)){
		ketQua = a;
		ketQua->next = tron2DanhSach(a->next, b, tieuChuan, tangDan);	
	}else{
		ketQua = b;
		ketQua->next = tron2DanhSach(a, b->next, tieuChuan, tangDan);
	}
	
	return ketQua;
}

void mergeSort(MA **headRef, int tieuChuan, bool tangDan){
	MA *head = *headRef;
	if(head == NULL || head->next == NULL) return;
	MA *a = NULL, *b = NULL;
	
	chiaDoiDanhSach(head, &a, &b);

    mergeSort(&a, tieuChuan, tangDan);
    mergeSort(&b, tieuChuan, tangDan);
    
    *headRef = tron2DanhSach(a, b, tieuChuan, tangDan);
}


void sapXepTheoMa(TD *td, bool tangDan) {
    if(td == NULL || td->head == NULL) return;
    mergeSort(&(td->head), 1, tangDan);
}

void sapXepTheoTen(TD *td, bool tangDan) {
    if(td == NULL || td->head == NULL) return;
    mergeSort(&(td->head), 2, tangDan);
}

void sapXepTheoGia(TD *td, bool tangDan) {
    if(td == NULL || td->head == NULL) return;
    mergeSort(&(td->head), 3, tangDan);
}
