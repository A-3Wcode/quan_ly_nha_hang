#include "../include/nha_hang.h"

// 4. Tim kiem
MA* timKiemTheoMa(TD *td, char ma[]){
	if(td == NULL || td->head == NULL) return NULL;
	
	for(MA* troDuyet = td->head; troDuyet != NULL; troDuyet = troDuyet->next){
		if(strcmp(troDuyet->MaMon, ma) == 0){
			return troDuyet;
		}
	}
	return NULL;
}

TD timKiemTheoTen(TD *td, char ten[]){
	TD ketQua;
	khoiTaoThucDon(&ketQua);
	
	if (td == NULL || td->head == NULL) return ketQua;
	
	MA *troDuyet = td->head;
	for(MA* troDuyet = td->head; troDuyet != NULL; troDuyet = troDuyet->next){
		if(strstr(troDuyet->Ten, ten) != NULL){
			MA *monTimThay = taoMonAn(troDuyet->MaMon, 
				troDuyet->Ten, troDuyet->Loai, troDuyet->Gia);
				themMonAn(&ketQua, monTimThay);
		}
	}
	return ketQua;
}

TD timKiemTheoLoai(TD *td, char loai[]){
	TD ketQua;
	khoiTaoThucDon(&ketQua);
	
	if (td == NULL || td->head == NULL) return ketQua;
	
	for(MA* troDuyet = td->head; troDuyet != NULL; troDuyet = troDuyet->next){
		if(strcmp(troDuyet->Loai, loai) == 0){
			MA *monTimThay = taoMonAn(troDuyet->MaMon, 
				troDuyet->Ten, troDuyet->Loai, troDuyet->Gia);
				themMonAn(&ketQua, monTimThay);
		}
	}
	return ketQua;
}

TD timKiemTheoKhoangGia(TD *td, double giaMin, double giaMax){
	TD ketQua;
	khoiTaoThucDon(&ketQua);
	
	if (td == NULL || td->head == NULL) return ketQua;
	
	for(MA* troDuyet = td->head; troDuyet != NULL; troDuyet = troDuyet->next){
		if(troDuyet->Gia >= giaMin && troDuyet->Gia <= giaMax){
			MA *monTimThay = taoMonAn(troDuyet->MaMon, 
				troDuyet->Ten, troDuyet->Loai, troDuyet->Gia);
				themMonAn(&ketQua, monTimThay);
		}
	}
	return ketQua;
}

// 6. Sap xep
void capNhatTail(TD *td) {
	if(td == NULL || td->head == NULL) {
		td->tail = NULL;
		return;
	}
	
	MA *current = td->head;
	while(current->next != NULL) {
		current = current->next;
	}
	td->tail = current;
}

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
			temp = strcmp(a->Loai, b->Loai);
			break;
		}
		case 4:{
			if(a->Gia < b->Gia) temp = -1;
			else if(a->Gia > b->Gia) temp = 1;
			else temp = 0;
		}
	}
	
	return tangDan? (temp<=0) : (temp>=0);
}

MA* tron2DanhSach(MA *a, MA *b, int tieuChuan, bool tangDan){
	if(a == NULL) return b;
	if(b == NULL) return a;
	
	MA mocGia;
	MA *tail = &mocGia;
	mocGia.next = NULL;

	while(a != NULL && b != NULL){
		if(soSanhMonAn(a, b, tieuChuan, tangDan)){
			tail->next = a;
			a = a->next;
		}else{
			tail->next = b;
			b = b->next;
		}
		tail = tail->next;
	}

	if(a != NULL) tail->next = a;
	else tail->next = b;
	
	return mocGia.next;
}

void mergeSort(MA **headRef, int tieuChuan, bool tangDan){
	if(headRef == NULL ||  *headRef == NULL || (*headRef)->next == NULL) return;

	MA *head = *headRef;
	MA *a = NULL, *b = NULL;
	
	chiaDoiDanhSach(head, &a, &b);

    mergeSort(&a, tieuChuan, tangDan);
    mergeSort(&b, tieuChuan, tangDan);
    
    *headRef = tron2DanhSach(a, b, tieuChuan, tangDan);
}


void sapXepTheoMa(TD *td, bool tangDan) {
    if(td == NULL || td->head == NULL) return;
    mergeSort(&(td->head), 1, tangDan);
	capNhatTail(td);
}

void sapXepTheoTen(TD *td, bool tangDan) {
    if(td == NULL || td->head == NULL) return;
    mergeSort(&(td->head), 2, tangDan);
	capNhatTail(td);
}

void sapXepTheoLoai(TD *td, bool tangDan) {
	if(td == NULL || td->head == NULL) return;
	mergeSort(&(td->head), 3, tangDan);
	capNhatTail(td);
}

void sapXepTheoGia(TD *td, bool tangDan) {
    if(td == NULL || td->head == NULL) return;
    mergeSort(&(td->head), 4, tangDan);
	capNhatTail(td);
}
