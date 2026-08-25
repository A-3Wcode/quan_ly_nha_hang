#include "../include/nha_hang.h"
#include "../include/nha_hang.h"
bool ghiFileThucDon(TD*td, char tenFile[])
{
    FILE*f = fopen(tenFile, "w");
    if (f== NULL)
        return false;
    MA*p =td->head;
    while(p!= NULL)
    {
        fprintf(f,"%s|%s|%s|%.2f\n",p->MaMon, p->Ten, p->Loai, p->Gia);
        p = p->next;
    }
    fclose(f);
    return true;
}
bool docFileThucDon(TD*td, char tenFile[])
{
    FILE*f = fopen(tenFile, "r");
    if (f== NULL)
        return false;
    char ma[50], ten[50], loai[50];
    float  gia;
    while (fscanf(f, "%49[^|]|%49[^|]|%49[^|]|%lf\n",ma, ten, loai, &gia)== 4)
    {
    MA*monMoi = taoMonAn(ma, ten, loai, gia);
    themMonAn(td, monMoi);
    }
    fclose(f);
    return true;
}
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
