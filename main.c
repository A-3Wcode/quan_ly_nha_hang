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
        printf("1. Nhap/Them mon an moi\n");
        printf("2. Hien thi danh sach thuc don\n");
        printf("3. Tim kiem mon an\n");
        printf("4. Xoa mon an\n");
        printf("5. Cap nhat thong tin mon an\n");
        printf("6. Sap xep thuc don\n");
        printf("7. Doc/Ghi file text\n");
        printf("8. Quon ly ban an & Thanh toan\n");
        printf("0. Thoat chuong trinh\n");
        printf("==================================================\n");
        printf("Nhap lua chon cua ban: ");

        do {
            if(scanf("%d", &luonChon) != 1) {
                printf("Lua chon khong hop le! Vui long nhap lai: ");
                while (getchar() != '\n');
            } else {
                break;
            }
        } while(luonChon != -1);

        switch (luonChon) {
            case 1:{
                nhapDanhSachMonAn(&td);
                break;
            }
            
            case 2:{
                hienThiThucDon(&td);
            	break;
            }
            
            case 3:{
                int timKiemLuaChon = -1;
                do{
                    printf("====== TIM KIEM MON AN ======\n");
                    printf("1. Tim kiem theo ma\n");
                    printf("2. Tim kiem theo ten\n");
                    printf("3. Tim kiem theo loai\n");
                    printf("4. Tim kiem theo khoang gia\n");
                    printf("0. Quay lai menu chinh\n");
                    printf("Nhap lua chon cua ban: ");
                    do{
                        if(scanf("%d", &timKiemLuaChon) != 1) {
                            printf("Lua chon khong hop le! Vui long nhap lai: ");
                            while (getchar() != '\n');
                        } else {
                            break;
                        }
                    }while(timKiemLuaChon != -1);

                    switch(timKiemLuaChon){
                        case 1:{
                            char timKiemMa[15];
                            printf("Nhap ma mon an can tim: ");
                            scanf("%s", timKiemMa);
                            MA* monTimKiem = timKiemTheoMa(&td, timKiemMa);
                            if(monTimKiem != NULL){
                                printf("Mon an tim thay:\n");
                                hienThiMonAn(monTimKiem);
                            } else {
                                printf("Khong tim thay mon an voi ma %s\n", timKiemMa);
                            }
                            break;
                        }

                        case 2:{
                            char timKiemTen[50];
                            printf("Nhap ten mon an can tim: ");
                            fgets(timKiemTen, sizeof(timKiemTen), stdin);
                            timKiemTen[strcspn(timKiemTen, "\n")] = '\0';
                            TD danhSachTimKiem = timKiemTheoTen(&td, timKiemTen);
                            if(danhSachTimKiem.count > 0){
                                printf("Danh sach mon an tim thay:\n");
                                hienThiThucDon(&danhSachTimKiem);
                            } else {
                                printf("Khong tim thay mon an voi ten %s\n", timKiemTen);
                            }
                        }

                        case 3:{
                            char timKiemLoai[30];
                            printf("Nhap loai mon an can tim: ");
                            fgets(timKiemLoai, sizeof(timKiemLoai), stdin);
                            timKiemLoai[strcspn(timKiemLoai, "\n")] = '\0';
                            TD danhSachTimKiem = timKiemTheoLoai(&td, timKiemLoai);
                            if(danhSachTimKiem.count > 0){
                                printf("Danh sach mon an tim thay:\n");
                                hienThiThucDon(&danhSachTimKiem);
                            } else {
                                printf("Khong tim thay mon an voi loai %s\n", timKiemLoai);
                            }
                        }

                        case 4:{
                            double giaMin, giaMax;
                            printf("Nhap khoang gia can tim (giaMin giaMax): ");
                            scanf("%lf %lf", &giaMin, &giaMax);
                            TD danhSachTimKiem = timKiemTheoKhoangGia(&td, giaMin, giaMax);
                            if(danhSachTimKiem.count > 0){
                                printf("Danh sach mon an tim thay:\n");
                                hienThiThucDon(&danhSachTimKiem);
                            } else {
                                printf("Khong tim thay mon an trong khoang gia %.2f - %.2f\n", giaMin, giaMax);
                            }
                        }

                        case 0:{
                            printf("Quay lai menu chinh\n");
                            break;
                        }

                        default: printf("Lua chon khong hop le!\n");
                    }
                }while(timKiemLuaChon != 0);
            }
            
            case 4:{
                int xoaLuaChon = -1;
                do{
                    printf("====== XOA MON AN ======\n");
                    printf("1. Xoa theo ma\n");
                    printf("2. Xoa theo ten\n");
                    printf("0. Quay lai menu chinh\n");
                    printf("Nhap lua chon cua ban: ");
                    do{
                        if(scanf("%d", &xoaLuaChon) != 1) {
                            printf("Lua chon khong hop le! Vui long nhap lai: ");
                            while (getchar() != '\n');
                        } else {
                            break;
                        }
                    }while(xoaLuaChon != -1);

                    switch(xoaLuaChon){
                        case 1:{
                            char xoaMa[15];
                            printf("Nhap ma mon an can xoa: ");
                            scanf("%s", xoaMa);
                            if(xoaTheoMa(&td, xoaMa)){
                                printf("Xoa mon an voi ma %s thanh cong!\n", xoaMa);
                            } else {
                                printf("Khong tim thay mon an voi ma %s\n", xoaMa);
                            }
                            break;
                        }

                        case 2:{
                            char xoaTen[50];
                            printf("Nhap ten mon an can xoa: ");
                            fgets(xoaTen, sizeof(xoaTen), stdin);
                            xoaTen[strcspn(xoaTen, "\n")] = '\0';
                            int soLuongXoa = xoaTheoTen(&td, xoaTen);
                            if(soLuongXoa > 0){
                                printf("Da xoa %d mon an voi ten %s!\n", soLuongXoa, xoaTen);
                            } else {
                                printf("Khong tim thay mon an voi ten %s\n", xoaTen);
                            }
                        }

                        case 0:{
                            printf("Quay lai menu chinh\n");
                            break;
                        }

                        default: printf("Lua chon khong hop le!\n");
                    }

                }while(xoaLuaChon != 0);
            }
            case 5:{
                char ma[15];
                printf("Nhap ma mon an can cap nhat: ");
                scanf("%s", ma);
                if(!capNhatMonAn(&td, ma)){
                    printf("Khong tim thay mon an voi ma %s\n", ma);
                }
            }
            
            case 6:{
                int sapXepLuaChon = -1;
                do{
                    printf("====== SAP XEP THUC DON ======\n");
                    printf("1. Sap xep theo ma (Tang Dan)\n");
                    printf("2. Sap xep theo ma (Giam Dan)\n");
                    printf("3. Sap xep theo ten (Tang Dan)\n");
                    printf("4. Sap xep theo ten (Giam Dan)\n");
                    printf("5. Sap xep theo loai (Tang Dan)\n");
                    printf("6. Sap xep theo loai (Giam Dan)\n");
                    printf("7. Sap xep theo gia (Tang Dan)\n");
                    printf("8. Sap xep theo gia (Giam Dan)\n");
                    printf("0. Quay lai menu chinh\n");
                    printf("Nhap lua chon cua ban: ");
                    do{
                        if(scanf("%d", &sapXepLuaChon) != 1) {
                            printf("Lua chon khong hop le! Vui long nhap lai: ");
                            while (getchar() != '\n');
                        } else {
                            break;
                        }
                    }while(sapXepLuaChon != -1);

                    switch (sapXepLuaChon){
                        case 1:{
                            sapXepTheoMa(&td, true);
                            printf("Da sap xep thuc don theo ma (Tang Dan)\n");
                            break;
                        }
                        case 2:{
                            sapXepTheoMa(&td, false);
                            printf("Da sap xep thuc don theo ma (Giam Dan)\n");
                            break;
                        }
                        case 3:{
                            sapXepTheoTen(&td, true);
                            printf("Da sap xep thuc don theo ten (Tang Dan)\n");
                            break;
                        }
                        case 4:{
                            sapXepTheoTen(&td, false);
                            printf("Da sap xep thuc don theo ten (Giam Dan)\n");
                            break;
                        }
                        case 5:{
                            sapXepTheoLoai(&td, true);
                            printf("Da sap xep thuc don theo loai (Tang Dan)\n");
                            break;
                        }
                        case 6:{
                            sapXepTheoLoai(&td, false);
                            printf("Da sap xep thuc don theo loai (Giam Dan)\n");
                            break;
                        }
                        case 7:{
                            sapXepTheoGia(&td, true);
                            printf("Da sap xep thuc don theo gia (Tang Dan)\n");
                            break;
                        }
                        case 8:{
                            sapXepTheoGia(&td, false);
                            printf("Da sap xep thuc don theo gia (Giam Dan)\n");
                            break;
                        }
                        case 0:{
                            printf("Quay lai menu chinh\n");
                            break;
                        }
                        default: printf("Lua chon khong hop le!\n");
                    }
                }while(sapXepLuaChon != 0);
            }
            
            case 7:{}
           
            case 8:{}
            
            case 0:{
                printf("Thoat chuong trinh!\n");
                break;
            }
            default: printf("Lua chon khong hop le!\n");
        }
    } while (luonChon != 0);

    return 0;
}
