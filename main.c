#include "include/nha_hang.h"

int main() {
    TD td;
    khoiTaoThucDon(&td);
    int luonChon;

    themMonAn(&td, taoMonAn("MA01", "Com Tam", "Mon chinh", 35.0));
    themMonAn(&td, taoMonAn("MA02", "Pho Bo", "Mon chinh", 45.0));
    themMonAn(&td, taoMonAn("MA03", "Tra Sua", "Giai khat", 25.0));
    themMonAn(&td, taoMonAn("MA04", "Bun Ca", "Mon chinh", 30.0));

    do {
        printf("\n================ QUAN LY NHA HANG ================\n");
        printf("1. Nhap / Them mon an moi\n");
        printf("2. Hien thi danh sach thuc don\n");
        printf("3. Tim kiem mon an\n");
        printf("4. Xoa mon an\n");
        printf("5. Cap nhat thong tin mon an\n");
        printf("6. Sap xep thuc don\n");
        printf("7. Doc / Ghi file text\n");
        printf("8. Quon ly ban an & Thanh toan\n");
        printf("0. Thoat chuong trinh\n");
        printf("==================================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luonChon);

        switch (luonChon) {
            case 1:{}
            case 2:{}
            case 3:{}
            case 4:{}
            case 5:{}
            case 6:{}
            case 7:{}
            case 8:{}
            case 0:{}
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luonChon != 0);

    return 0;
}
