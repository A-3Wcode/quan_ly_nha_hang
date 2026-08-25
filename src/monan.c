#include "../include/nha_hang.h"
/*Thuc hien: Nguyen Tai Nang*/
// 1. Khoi tao va quan ly bo nho
MA* taoMonAn(char ma[], char ten[], char loai[], double gia){
    MA* mon =(MA*)malloc(sizeof(MA)); // khai báo vùng nhớ cho món ăn
    if(mon == NULL){                    // kiểm tra NULL và báo lỗi
        printf("Loi!"); return NULL;
    }
    strcpy(mon->MaMon, ma);     // sao chép mã món ăn 
    strcpy(mon->Ten, ten);
    strcpy(mon->Loai, loai);
    mon->Gia = gia;
    mon-> next = NULL;           // gấn con trỏ next  =NULL  vì chưa liên kết 
    return mon;
}

void khoiTaoThucDon(TD *td){
    if(td != NULL){     // kiểm tra con trỏ td khác null 
        td->head = NULL;
        td->count = 0;
    }
}
void giaiPhongThucDon(TD *td){
    MA *current = td->head;             //Bắt đầu từ nút đầu
    while(current != NULL){
        MA *temp = current;             //Giữ nút hiện tại
        current = current->next;        //Nhảy sang nút tiếp theo
        free(temp);                     //Giair phóng
    }
    td-> head = NULL;                   // Đặt con trỏ đầu danh sách về NULL
    td->count = 0;                      // ds rỗng
}

// 2. Nhap va Them mon
bool kiemTraTrungMa(TD *td, char ma[]){
    if(td == NULL || td->head == NULL) return false;
    MA *p = td->head; // con tro p start from head
    while(p != NULL){
        if(strcmp(p->MaMon, ma) == 0) return true; // da tim thay ma trung 
        p = p->next;  // chua tim thay ma trung
    }
    return false;
}
bool themMonAn(TD *td, MA *monMoi){
    if(td == NULL || monMoi == NULL) return false;
    if(kiemTraTrungMa(td, monMoi -> MaMon)) return false;
    
    if(td -> head == NULL ){
    td->head = monMoi;
    } else {
    MA *p = td->head;
    while(p->next != NULL){
        p = p->next ; 
    }
    p->next = monMoi;   
    }
    td->count++; 
    return true;
}


void nhapDanhSachMonAn(TD *td){
    int n;
    printf("Nhap so luong mon an:");
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        char ma[15], ten[50], loai[30]; 
        double gia;

        printf("\n---Nhap mon an thu %d---\n", i+1);
        do{
            printf("Nhap ma mon an:");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';
            if(kiemTraTrungMa(td, ma)){
                printf("Ma mon da ton tai! Vui long nhap lai.\n");

            }
        }while(kiemTraTrungMa(td, ma));

        printf("Nhap mon an: ");
        fgets(ten, sizeof(ten), stdin);
        ten[strcspn(ten, "\n")] = '\0';

        printf("Nhap loai mon an: ");
        fgets(loai, sizeof(loai), stdin);
        loai[strcspn(loai, "\n")] = '\0';

        printf("Nhap gia mon an: ");
        scanf("%lf", &gia);
        getchar();

        MA *monMoi = taoMonAn(ma, ten, loai, gia);
        if(!themMonAn(td, monMoi)){
            printf("Them mon an that bai!\n");
            free(monMoi);
        }
    }
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
    printf("\n-----DANH SACH THUC DON-----\n");
    printf("| %-12s | %-25s | %-15s | %-10.2f |\n", "Ma Mon", " Ten","Loai", "Gia");
    printf("---------------------------------------------------------------\n");
    MA *p = td->head;
    while(p != NULL){
        hienThiMonAn(p);
        p = p->next;
    }
    printf("---------------------------------------------------------------\n");
    printf("Tong so mon an: %d\n", td->count);

}
