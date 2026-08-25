#include "../include/nha_hang.h"
/*
Các hàm taoMonAn, khoiTaoThucDon, giaiPhongThucDon, kiemTraTrungMa, themMonAn, nhapDanhSachMonAn, hienThiMonAn, hienThiThucDon.
*/
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
