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
