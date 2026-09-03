#include "../include/nha_hang.h"
/*Thuc hien: Tran Pham Vinh Quang*/
bool ghiFileThucDon(TD* td, char tenFile[])
{
    FILE* f = fopen(tenFile, "w");
    if (f == NULL)
        return false;
    MA* p = td->head;
    while (p != NULL)
    {
        fprintf(f, "%s,%s,%s,%.lf\n", p->MaMon, p->Ten, p->Loai, p->Gia);
        p = p->next;
    }
    fclose(f);
    return true;
}
bool docFileThucDon(TD* td, char tenFile[])
{
    FILE* f = fopen(tenFile, "r");
    if (f == NULL)
        return false;
    char ma[15], ten[50], loai[50];
    double gia;
        while (fscanf(f, "%14[^,],%49[^,],%49[^,],%lf\n", ma, ten, loai, &gia) == 4)
    {
        MA* monMoi = taoMonAn(ma, ten, loai, gia);
        themMonAn(td, monMoi);
    }
    fclose(f);
    return true;
}
