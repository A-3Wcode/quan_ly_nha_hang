#include "include/nha_hang.h"
#include "include/nang_cao.h"
StackUndo undoStack, redoStack;
int main() {
    TD td;
    QueueBep q;
    DanhSachLichSu ls;
    khoiTaoThucDon(&td);
<<<<<<< HEAD
    khoiTaoStack(&undoStack);
    khoiTaoStack(&redoStack);
=======
    khoiTaoQueue(&q);
    khoiTaoLichSu(&ls);
>>>>>>> b377f18fed010c7381111270654b02fb9682cc4d
    int luonChon;
    docFileThucDon(&td, "data/thucdon.txt");
    // themMonAn(&td, taoMonAn("MA01", "Com Tam", "Mon chinh", 35.0));
    // themMonAn(&td, taoMonAn("MA02", "Pho Bo", "Mon chinh", 45.0));
    // themMonAn(&td, taoMonAn("MA03", "Tra Sua", "Giai khat", 25.0));
    // themMonAn(&td, taoMonAn("MA04", "Bun Ca", "Mon chinh", 30.0));
    // themMonAn(&td, taoMonAn("MA05", "Bun Cha", "Mon chinh", 35.0));
    // themMonAn(&td, taoMonAn("MA06", "Com Ga", "Mon chinh", 30.0));
    // themMonAn(&td, taoMonAn("MA07", "Pho Ga", "Mon chinh", 30.0));
    // themMonAn(&td, taoMonAn("MA08", "Tra Da", "Gia khat", 5.0));
    // themMonAn(&td, taoMonAn("MA09", "Bun Dau", "Mon chinh", 80.0));
    // themMonAn(&td, taoMonAn("MA10", "Banh Chuoi", "Trang mieng", 25.0));
    // themMonAn(&td, taoMonAn("MA11", "Salad", "Khai vi", 30.0));
    // themMonAn(&td, taoMonAn("MA12", "Banh My", "Mon phu", 8.0));

    do {
        printf("\n+------------------------------------------------------+\n");
        printf("|                QUAN LY NHA HANG                      |\n");
        printf("+------------------------------------------------------+\n");
        printf("| QUAN LY THUC DON                                     |\n");
        printf("| 1. Nhap/them mon an moi                              |\n");
        printf("| 2. Hien thi danh sach thuc don                       |\n");
        printf("| 3. Tim kiem mon an                                   |\n");
        printf("| 4. Xoa mon an                                        |\n");
        printf("| 5. Cap nhat thong tin mon an                         |\n");
        printf("| 6. Sap xep thuc don                                  |\n");
        printf("| QUAN LY BAN AN                                       |\n");
        printf("| 7. Quan ly ban an va thanh toan                      |\n");
        printf("| CHUC NANG NANG CAO                                   |\n");
        printf("| 8. Hoan tac thao tac                                 |\n");
        printf("| 9. REDO THAO TAC                                 |\n");
        printf("| 10. Hang doi che bien                                 |\n");
        printf("| 11. Tim kiem bang cay AVL                            |\n");
        printf("| 12. Thong ke                                         |\n");
        printf("| 13. Lich su thao tac                                 |\n");
        printf("| 0. Thoat chuong trinh                                |\n");
        printf("+------------------------------------------------------+\n");
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
            case 1: {
                xoaBoDem();
                nhapDanhSachMonAn(&td);
                break;
            }

            case 2: {
                hienThiThucDon(&td);
                break;
            }

            case 3: {
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
                    }while(1);

                    switch(timKiemLuaChon){
                        case 1:{
                            char timKiemMa[15];
                            printf("Nhap ma mon an can tim: ");
                            while (getchar() != '\n');
                            fgets(timKiemMa, sizeof(timKiemMa), stdin);
                            timKiemMa[strcspn(timKiemMa, "\n")] = '\0';
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
                            while (getchar() != '\n');
                            fgets(timKiemTen, sizeof(timKiemTen), stdin);
                            timKiemTen[strcspn(timKiemTen, "\n")] = '\0';
                            TD danhSachTimKiem = timKiemTheoTen(&td, timKiemTen);
                            if(danhSachTimKiem.count > 0){
                                printf("Danh sach mon an tim thay:\n");
                                hienThiThucDon(&danhSachTimKiem);
                            } else {
                                printf("Khong tim thay mon an voi ten %s\n", timKiemTen);
                            }
                            giaiPhongThucDon(&danhSachTimKiem);
                            break;
                        }

                        case 3:{
                            char timKiemLoai[30];
                            printf("Nhap loai mon an can tim: ");
                            while (getchar() != '\n');
                            fgets(timKiemLoai, sizeof(timKiemLoai), stdin);
                            timKiemLoai[strcspn(timKiemLoai, "\n")] = '\0';
                            TD danhSachTimKiem = timKiemTheoLoai(&td, timKiemLoai);
                            if(danhSachTimKiem.count > 0){
                                printf("Danh sach mon an tim thay:\n");
                                hienThiThucDon(&danhSachTimKiem);
                            } else {
                                printf("Khong tim thay mon an voi loai %s\n", timKiemLoai);
                            }
                            giaiPhongThucDon(&danhSachTimKiem);
                            break;
                        }

                        case 4: {
                            double giaMin, giaMax;
                            bool hopLe = false;
                            printf("Nhap khoang gia can tim (giaMin giaMax): ");
                            do{
                                if(scanf("%lf %lf", &giaMin, &giaMax) != 2) {
                                    printf("Lua chon khong hop le! Vui long nhap lai: ");
                                    while (getchar() != '\n');
                                } else if(giaMin < 0 || giaMax < 0 || giaMin > giaMax) {
                                    printf("Khoang gia khong hop le! Vui long nhap lai: ");
                                } else {
                                    hopLe = true;
                                }
                            }while(!hopLe);

                            TD danhSachTimKiem = timKiemTheoKhoangGia(&td, giaMin, giaMax);

                            if(danhSachTimKiem.count > 0){
                                printf("Danh sach mon an tim thay:\n");
                                hienThiThucDon(&danhSachTimKiem);
                            } else {
                                printf("Khong tim thay mon an trong khoang gia %.2f - %.2f\n", giaMin, giaMax); 
                            }
                            giaiPhongThucDon(&danhSachTimKiem);
                            break;
                        }

                        case 0:{
                            printf("Quay lai menu chinh\n");
                            break;
                        }

                        default: printf("Lua chon khong hop le!\n");
                    }
                }while(timKiemLuaChon != 0);
                break;
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
                            while (getchar() != '\n');
                            fgets(xoaMa, sizeof(xoaMa), stdin);
                            xoaMa[strcspn(xoaMa, "\n")] = '\0';
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
                            while (getchar() != '\n');
                            fgets(xoaTen, sizeof(xoaTen), stdin);
                            xoaTen[strcspn(xoaTen, "\n")] = '\0';
                            int soLuongXoa = xoaTheoTen(&td, xoaTen);
                            if(soLuongXoa > 0){
                                printf("Da xoa %d mon an voi ten %s!\n", soLuongXoa, xoaTen);
                            } else {
                                printf("Khong tim thay mon an voi ten %s\n", xoaTen);
                            }
                            break;
                        }

                        case 0:{
                            printf("Quay lai menu chinh\n");
                            break;
                        }

                        default: printf("Lua chon khong hop le!\n");
                    }

                }while(xoaLuaChon != 0);
                break;
            }

            case 5: {
                char ma[15];
                printf("Nhap ma mon an can cap nhat: ");
                while (getchar() != '\n');
                fgets(ma, sizeof(ma), stdin);
                ma[strcspn(ma, "\n")] = '\0';
                if(capNhatMonAn(&td, ma)){
                    printf("Cap nhat mon an voi ma %s thanh cong!\n", ma);
                } else {
                    printf("Khong tim thay mon an voi ma %s\n", ma);
                }
                break;
            }
            
            case 6: {
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
                    
                    int hopLe = 0;
                    do{
                        if(scanf("%d", &sapXepLuaChon) != 1) {
                            printf("Lua chon khong hop le! Vui long nhap lai: ");
                            while (getchar() != '\n');
                        } else {
                            hopLe = 1;
                        }
                    }while(!hopLe);

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
                break;
            }
            
            case 7: {
                Ban ban[10];
                for(int i = 0; i < 10; i++)
                    khoiTaoBan(&ban[i], i + 1);
                int luaChonBan = -1;
                do
                {
                    printf("\n====== QUAN LY BAN AN & THANH TOAN ======\n");
                    printf("1. Hien thi trang thai ban\n");
                    printf("2. Goi mon cho ban\n");
                    printf("3. Xem hoa don ban\n");
                    printf("4. Thanh toan ban\n");
                    printf("0. Quay lai menu chinh\n");
                    printf("Nhap lua chon: ");
                    scanf("%d", &luaChonBan);
                    switch(luaChonBan)
                    {
                        case 1:
                        {
                            printf("\n====== TRANG THAI BAN ======\n");
                            for(int i = 0; i < 10; i++)
                            {
                                printf("Ban %d: ", ban[i].SoBan);

                                if(ban[i].TrangThai)
                                {
                                    printf("Dang phuc vu - Tong tien: %.2lf\n",
                                           tinhTongTien(&ban[i]));
                                }
                                else
                                {
                                    printf("Trong\n");
                                }
                            }

                            break;
                        }

                        case 2:
                        {
                            int soBan;
                            char maMon[15];
                            printf("Nhap so ban: ");
                            scanf("%d", &soBan);
                            if(soBan < 1 || soBan > 10)
                            {
                                printf("So ban khong hop le!\n");
                                break;
                            }
                            printf("Nhap ma mon an: ");
                            scanf("%s", maMon);
                            MA*mon = timKiemTheoMa(&td, maMon);
                            if(mon == NULL)
                            {
                                printf("Khong tim thay mon an!\n");
                            }
                            else
                            {
                                if(goiMon(&ban[soBan - 1], mon))
                                {
                                    printf("Goi mon thanh cong!\n");
                                    printf("Mon: %s - %.2lf\n",
                                           mon->Ten, mon->Gia);
                                }
                                else
                                {
                                    printf("Goi mon that bai!\n");
                                }
                            }
                            break;
                        }

                        case 3:
                        {
                            int soBan;
                            printf("Nhap so ban: ");
                            scanf("%d", &soBan);
                            if(soBan < 1 || soBan > 10)
                            {
                                printf("So ban khong hop le!\n");
                                break;
                            }
                            if(!ban[soBan - 1].TrangThai)
                        {
                                printf("Ban %d dang trong!\n", soBan);
                                break;
                            }
                            printf("\n====== HOA DON BAN %d ======\n", soBan);
                            MA *p = ban[soBan - 1].HoaDon;
                            while(p != NULL)
                            {
                                printf("%s - %s - %.2lf\n",
                                       p->MaMon,
                                       p->Ten,
                                       p->Gia);

                                p = p->next;
                            }
                            printf("Tong tien: %.2lf\n",
                                   tinhTongTien(&ban[soBan - 1]));
                            break;
                        }

                        case 4:
                        {
                            int soBan;
                            printf("Nhap so ban can thanh toan: ");
                            scanf("%d", &soBan);
                            if(soBan < 1 || soBan > 10)
                            {
                                printf("So ban khong hop le!\n");
                                break;
                            }
                            if(!ban[soBan - 1].TrangThai)
                            {
                                printf("Ban %d dang trong!\n", soBan);
                                break;
                            }
                            double tong = tinhTongTien(&ban[soBan - 1]);
                            printf("\nTong tien ban %d: %.2lf\n",
                                   soBan, tong);
                            printf("Thanh toan thanh cong!\n");
                            thanhToanBan(&ban[soBan - 1]);
                            break;
                        }

                        case 0:
                        {
                            printf("Quay lai menu chinh\n");
                            break;
                        }

                        default:
                        {
                            printf("Lua chon khong hop le!\n");
                        }
                    }
                }while(luaChonBan != 0);
                break;
            }

           case 8: {
                printf("\n====== UNDO THAO TAC ======\n");
                thucHienUndo(&td, &undoStack, &redoStack);
                break;
            }
            case 9: {
<<<<<<< HEAD
                printf("\n====== REDO THAO TAC ======\n");
                thucHienRedo(&td, &redoStack, &undoStack);
=======
    int chonBep;
    do {
        printf("\n====== HANG DOI CHE BIEN ======\n");
        printf("1. Them don hang vao bep\n");
        printf("2. Hien thi danh sach cho bep\n");
        printf("3. Xu ly don hang dau tien\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &chonBep) != 1) {
            printf("Lua chon khong hop le!\n");
            while (getchar() != '\n');
            chonBep = -1;
            continue;
        }

        switch (chonBep) {
            case 1: {
                int soBan;
                char maMon[15];

                printf("Nhap so ban: ");
                if (scanf("%d", &soBan) != 1) {
                    printf("So ban khong hop le!\n");
                    while (getchar() != '\n');
                    break;
                }

                if (soBan < 1 || soBan > 10) {
                    printf("So ban phai tu 1 den 10!\n");
                    break;
                }

                printf("Nhap ma mon an: ");
                scanf("%14s", maMon);

                MA *mon = timKiemTheoMa(&td, maMon);

                if (mon == NULL) {
                    printf("Khong tim thay mon an!\n");
                    break;
                }

                if (enqueueOrder(&q, soBan, mon)) {
                    char noiDung[150];
                    snprintf(noiDung, sizeof(noiDung),
                             "Them mon %s vao hang doi bep, ban %d",
                             mon->Ten, soBan);
                    ghiLog(&ls, noiDung);
                    printf("Them don hang vao bep thanh cong!\n");
                } else {
                    printf("Them don hang that bai!\n");
                }
>>>>>>> b377f18fed010c7381111270654b02fb9682cc4d
                break;
            }

            case 2: {
                hienThiDanhSachChoBep(&q);
                break;
            }

            case 3: {
                DonHangBep don;

                if (dequeueOrder(&q, &don)) {
                    printf("\nDa xu ly don hang:\n");
                    printf("So ban: %d\n", don.soBan);
                    printf("Ma mon: %s\n", don.maMon);
                    printf("Ten mon: %s\n", don.tenMon);

                    char noiDung[150];
                    snprintf(noiDung, sizeof(noiDung),
                             "Xu ly mon %s, ban %d",
                             don.tenMon, don.soBan);
                    ghiLog(&ls, noiDung);
                } else {
                    printf("Khong co don hang de xu ly!\n");
                }
                break;
            }

            case 0:
                printf("Quay lai menu chinh\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chonBep != 0);

    break;
}

            case 10: {
                printf("Chuc nang tim kiem AVL chua duoc trien khai!\n");
                break;
            }

            case 11: {
                printf("Chuc nang thong ke chua duoc trien khai!\n");
                break;
            }

            case 12: {
    int chonLichSu;
    do {
        printf("\n====== LICH SU THAO TAC ======\n");
        printf("1. Hien thi lich su\n");
        printf("2. Ghi them lich su\n");
        printf("3. Xuat lich su ra file\n");
        printf("0. Quay lai menu chinh\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &chonLichSu) != 1) {
            printf("Lua chon khong hop le!\n");
            while (getchar() != '\n');
            chonLichSu = -1;
            continue;
        }

        switch (chonLichSu) {
            case 1: {
                hienThiLichSu(&ls);
                break;
            }

            case 2: {
                char noiDung[200];

                while (getchar() != '\n');

                printf("Nhap noi dung thao tac: ");
                if (fgets(noiDung, sizeof(noiDung), stdin) == NULL) {
                    printf("Khong doc duoc noi dung!\n");
                    break;
                }

                noiDung[strcspn(noiDung, "\n")] = '\0';

                if (ghiLog(&ls, noiDung)) {
                    printf("Ghi lich su thanh cong!\n");
                } else {
                    printf("Ghi lich su that bai!\n");
                }
                break;
            }

            case 3: {
                if (xuatLogRaFile(&ls, "data/lichsu.txt")) {
                    printf("Da xuat lich su ra data/lichsu.txt\n");
                } else {
                    printf("Xuat file that bai!\n");
                }
                break;
            }

            case 0:
                printf("Quay lai menu chinh\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chonLichSu != 0);

    break;
}

            case 0: {
                printf("Thoat chuong trinh!\n");
                break;
            }

            default: {
                printf("Lua chon khong hop le!\n");
            }
        }
<<<<<<< HEAD
    } while (luonChon != 0);
    ghiFileThucDon(&td, "data/thucdon.txt");
    giaiPhongThucDon(&td);
    giaiPhongStack(&undoStack);
    giaiPhongStack(&redoStack);
    
    return 0;
=======
} while (luonChon != 0);
ghiFileThucDon(&td, "data/thucdon.txt");
giaiPhongQueue(&q);
giaiPhongLichSu(&ls);
giaiPhongThucDon(&td);
return 0;
>>>>>>> b377f18fed010c7381111270654b02fb9682cc4d
}
