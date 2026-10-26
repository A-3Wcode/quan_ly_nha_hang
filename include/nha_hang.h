#ifndef NHA_HANG_H
#define NHA_HANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// 1. CÁC CẤU TRÚC DỮ LIỆU CƠ BẢN

// Struct MonAn (Nút danh sách liên kết đơn món ăn)
typedef struct MonAn {
    char MaMon[15];         // Mã món ăn (duy nhất)
    char Ten[50];           // Tên món ăn
    char Loai[30];          // Loại món (Khai vị, Món chính, Đồ uống...)
    double Gia;             // Giá tiền
    struct MonAn* next;     // Con trỏ đến món kế tiếp
} MA;

// Struct ThucDon (Quản lý Danh sách liên kết đơn)
typedef struct ThucDon {
    MA* head;               // Con trỏ đầu danh sách
    MA* tail;               // Con trỏ cuối danh sách
    int count;              // Số lượng món trong thực đơn
} TD;

// Struct Ban (Quản lý bàn ăn và hóa đơn)
typedef struct Ban {
    int SoBan;              // Số thứ tự bàn
    bool TrangThai;         // true: Có khách | false: Bàn trống
    MA* HoaDon;             // Danh sách liên kết món bàn đã gọi
    double TongHoaDon;      // Tổng tiền hiện tại của bàn
} Ban;


// 2. KHAI BÁO CÁC HÀM CƠ BẢN

// Khởi tạo & Quản lý bộ nhớ
MA* taoMonAn(const char ma[], const char ten[], const char loai[], double gia);
void khoiTaoThucDon(TD *td);
void giaiPhongThucDon(TD *td);

// Hàm bổ trợ nhập liệu & kiểm tra
bool laChuoiSo(const char *s);
void xoaBoDem(void);
bool TenVaLoaiHopLe(const char *s);
bool kiemTraMonHopLe(const char ma[], const char ten[], double gia);

// Nhập & Thêm món (CRUD)
bool kiemTraTrungMa(const TD *td, const char ma[]);
bool themMonAn(TD *td, MA *monMoi);
void nhapDanhSachMonAn(TD *td);

// Hiển thị dữ liệu
void hienThiMonAn(const MA *mon);
void hienThiThucDon(const TD *td);

// Tìm kiếm
MA* timKiemTheoMa(const TD *td, const char ma[]);
TD timKiemTheoTen(const TD *td, const char ten[]);
TD timKiemTheoLoai(const TD *td, const char loai[]);
TD timKiemTheoKhoangGia(const TD *td, double giaMin, double giaMax);

// Xóa & Cập nhật
bool xoaTheoMa(TD *td, const char ma[]);
int xoaTheoTen(TD *td, const char ten[]);
bool capNhatMonAn(TD *td, const char ma[]);

// Sắp xếp (Thuật toán Merge Sort)
void sapXepTheoMa(TD *td, bool tangDan);
void sapXepTheoTen(TD *td, bool tangDan);
void sapXepTheoLoai(TD *td, bool tangDan);
void sapXepTheoGia(TD *td, bool tangDan);

// Đọc & Ghi File Text
bool ghiFileThucDon(const TD *td, const char tenFile[]);
bool docFileThucDon(TD *td, const char tenFile[]);

// Quản lý Bàn ăn & Thanh toán
void khoiTaoBan(Ban *ban, int soBan);
bool goiMon(Ban *ban, const MA *mon);
double tinhTongTien(Ban *ban);
void thanhToanBan(Ban *ban);

#endif
