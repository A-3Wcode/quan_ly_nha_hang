#include "../include/nha_hang.h"
/*Thuc hien: Tran Pham Vinh Quang*/
// 8. Quan ly Ban an & Thanh toan
void khoiTaoBan(Ban *ban, int soBan)
{
    ban->SoBan = soBan;
    ban->TrangThai = false;
    ban->HoaDon= NULL;
    ban->TongHoaDon = 0;
}
bool goiMon(Ban*ban, MA*mon)
{
    if (ban == NULL || mon == NULL)
        return false;
    MA *monMoi = taoMonAn(
        mon->MaMon,
        mon->Ten,
        mon->Loai,
        mon->Gia
    );
    if (monMoi == NULL)
        return false;
    monMoi->next = ban->HoaDon;
    ban->HoaDon = monMoi;
    ban->TrangThai = true;
    return true;
}
double tinhTongTien(Ban *ban)
{
    double tong = 0;
    MA *p = ban->HoaDon;
    while (p != NULL)
    {
    tong += p->Gia;
    p = p->next;
    }
    ban->TongHoaDon = tong;
    return tong;
}
void thanhToanBan(Ban *ban)
{
    MA *p=ban->HoaDon;
    while (p != NULL)
    {
    MA *temp = p;
    p = p->next;
    free(temp);
    }
    ban->HoaDon = NULL;
    ban->TongHoaDon = 0;
    ban->TrangThai = false;
}
