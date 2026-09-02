#ifndef NHA_HANG_H
#define NHA_HANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct Khai bao Mon An
typedef struct MonAn {
    char MaMon[15];         // Ma mon (Duy nhat)
    char Ten[50];           // Ten mon
    char Loai[30];          // Loai mon (Khai vi, Mon chinh, Do uong,...)
    double Gia;             // Gia tien
    struct MonAn* next;     // Con tro den mon tiep theo
} MA;

// Struct Danh sach Thuc Don (Danh sach lien ket don)
typedef struct ThucDon {
    MA* head;
    int count;
} TD;

// Struct Quan ly Ban An
typedef struct Ban {
    int SoBan;              // So ban
    bool TrangThai;         // true: Co khach, false: Trong
    MA* HoaDon;             // Danh sach mon ban da goi
    double TongHoaDon;      // Tong tien bill
} Ban;

// === KHAI BÁO PROTOTYPE HÀM ===

// 1. Khoi tao va Quan ly bo nho
MA* taoMonAn(char ma[], char ten[], char loai[], double gia);
void khoiTaoThucDon(TD *td);
void giaiPhongThucDon(TD *td);

// 2. Nhap va Them mon
bool kiemTraTrungMa(TD *td, char ma[]);
bool kiemTraHopLeMonAn(char ma[], char ten[], double gia);
bool themMonAn(TD *td, MA *monMoi);
void nhapDanhSachMonAn(TD *td);

// 3. Hien thi
void hienThiMonAn(MA *mon);
void hienThiThucDon(TD *td);

// 4. Tim kiem
MA* timKiemTheoMa(TD *td, char ma[]);
TD timKiemTheoTen(TD *td, char ten[]);
TD timKiemTheoLoai(TD *td, char loai[]);
TD timKiemTheoKhoangGia(TD *td, double giaMin, double giaMax);

// 5. Xoa phan tu
bool xoaTheoMa(TD *td, char ma[]);
int xoaTheoTen(TD *td, char ten[]);

// 6. Cap nhat va Sap xep
bool capNhatMonAn(TD *td, char ma[]);
void sapXepTheoMa(TD *td, bool tangDan);
void sapXepTheoTen(TD *td, bool tangDan);
void sapXepTheoLoai(TD *td, bool tangDan);
void sapXepTheoGia(TD *td, bool tangDan);

// 7. Doc va Ghi file text
bool ghiFileThucDon(TD *td, char tenFile[]);
bool docFileThucDon(TD *td, char tenFile[]);

// 8. Quan ly Ban an & Thanh toan
void khoiTaoBan(Ban *ban, int soBan);
bool goiMon(Ban *ban, MA *mon);
double tinhTongTien(Ban *ban);
void thanhToanBan(Ban *ban);

#endif
