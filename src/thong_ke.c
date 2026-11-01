#include "../include/nang_cao.h"

void khoiTaoQuanLyDoanhThu(QuanLyDoanhThu *qldt){
    if (qldt == NULL) return;
    qldt->tongDoanhThuDaThanhToan = 0.0;
    qldt->soHoaDonDaThanhToan = 0;
}

int khoiTaoDanhSachThongKe(const TD *td, ThongKeMon dsThongKe[]){
    if (td == NULL || dsThongKe == NULL) return 0;

    MA* current = td->head;
    int index = 0;

    while (current != NULL) {
        strcpy(dsThongKe[index].maMon, current->MaMon);
        strcpy(dsThongKe[index].tenMon, current->Ten);
        strcpy(dsThongKe[index].loai, current->Loai);
        dsThongKe[index].gia = current->Gia;
        dsThongKe[index].soLuongBan = 0;
        dsThongKe[index].tongDoanhThuMon = 0.0;
        index++;
        current = current->next;
    }

    return index;
}

void capNhatThongKeKhiThanhToan(Ban *ban, QuanLyDoanhThu *qldt, ThongKeMon dsThongKe[], int soLuongMon){
    if (ban == NULL || qldt == NULL || dsThongKe == NULL) return;

    // Cập nhật tổng doanh thu và số hóa đơn đã thanh toán
    qldt->tongDoanhThuDaThanhToan += ban->TongHoaDon;
    qldt->soHoaDonDaThanhToan++;

    // Cập nhật thống kê cho từng món ăn trong hóa đơn của bàn
    MA* current = ban->HoaDon;
    while (current != NULL) {
        for (int i = 0; i < soLuongMon; i++) {
            if (strcmp(dsThongKe[i].maMon, current->MaMon) == 0) {
                dsThongKe[i].soLuongBan++;
                dsThongKe[i].tongDoanhThuMon += current->Gia;
                break;
            }
        }
        current = current->next;
    }
}

double tinhGiaTriHoaDonTrungBinh(const QuanLyDoanhThu *qldt){
    if (qldt == NULL || qldt->soHoaDonDaThanhToan == 0) return 0.0;
    return qldt->tongDoanhThuDaThanhToan / qldt->soHoaDonDaThanhToan;
}

void sapXepBestSellersGiamDan(ThongKeMon dsThongKe[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dsThongKe[j].soLuongBan < dsThongKe[j + 1].soLuongBan) {
                ThongKeMon temp = dsThongKe[j];
                dsThongKe[j] = dsThongKe[j + 1];
                dsThongKe[j + 1] = temp;
            }
        }
    }
}
void hienThiBaoCaoThongKe(const QuanLyDoanhThu *qldt, ThongKeMon dsThongKe[], int n){
    if (qldt == NULL || dsThongKe == NULL) return;

    printf("\n+------------------------------------------------------------+\n");
    printf("|                 BAO CAO THONG KE DOANH THU                 |\n");
    printf("+------------------------------------------------------------+\n");
    printf("| Tong doanh thu da thanh toan: %-28.2lf |\n",
           qldt->tongDoanhThuDaThanhToan);
    printf("| So hoa don da thanh toan:    %-29d |\n",
           qldt->soHoaDonDaThanhToan);
    printf("| Gia tri hoa don trung binh:  %-29.2lf |\n",
           tinhGiaTriHoaDonTrungBinh(qldt));
    printf("+------------------------------------------------------------+\n");

    sapXepBestSellersGiamDan(dsThongKe, n);
    printf("\n+-----+--------+------------------+--------------+----------+----------+----------------+\n");
    printf("|%-87s|\n", "                    BANG XEP HANG BEST SELLERS");
    printf("+-----+--------+------------------+--------------+----------+----------+----------------+\n");
    printf("| %-3s | %-6s | %-16s | %-12s | %8s | %8s | %14s |\n",
           "STT", "Ma mon", "Ten mon", "Loai", "Gia",
           "So luong", "Tong doanh thu");
    printf("+-----+--------+------------------+--------------+----------+----------+----------------+\n");

    for (int i = 0; i < n; i++) {
        printf("| %-3d | %-6.6s | %-16.16s | %-12.12s | %8.2lf | %8d | %14.2lf |\n",
                i + 1, dsThongKe[i].maMon, dsThongKe[i].tenMon,
                dsThongKe[i].loai, dsThongKe[i].gia,
                dsThongKe[i].soLuongBan, dsThongKe[i].tongDoanhThuMon);
    }
    printf("+-----+--------+------------------+--------------+----------+----------+----------------+\n");
}