// #include "../include/nang_cao.h"#include "../include/nang_cao.h"
// void khoiTaoLichSu(DanhSachLichSu* ls)
// {
//     if (ls == NULL)
//         return;
//     ls->head = NULL;
//     ls->count = 0;
// }
// bool ghiLog(DanhSachLichSu* ls, const char noiDung[])
// {
//     if (ls == NULL || noiDung == NULL)
//         return false;
//     NodeLichSu* p = (NodeLichSu*)malloc(sizeof(NodeLichSu));
//     if (p == NULL)
//         return false;
//     time_t now = time(NULL);
//     struct tm* tg = localtime(&now);
//     if (tg != NULL)
//     {
//         strftime(
//             p->data.thoiGian,
//             sizeof(p->data.thoiGian),
//             "%H:%M:%S",
//             tg
//         );
//     }
//     else
//     {
//         strcpy(p->data.thoiGian, "Unknown");
//     }
//     strncpy(
//         p->data.noiDung,
//         noiDung,
//         sizeof(p->data.noiDung) - 1
//     );
//     p->data.noiDung[sizeof(p->data.noiDung) - 1] = '\0';
//     p->next = NULL;
//     if (ls->head == NULL)
//     {
//         ls->head = p;
//     }
//     else
//     {
//         NodeLichSu* q = ls->head;
//         while (q->next != NULL)
//         {
//             q = q->next;
//         }
//         q->next = p;
//     }
//     ls->count++;
//     return true;
// }
// void hienThiLichSu(const DanhSachLichSu* ls)
// {
//     if (ls == NULL || ls->head == NULL)
//     {
//         printf("Chua co lich su thao tac!\n");
//         return;
//     }
//     NodeLichSu* p = ls->head;
//     printf("\n========== Lich su thao tac ==========\n");

//     while (p != NULL)
//     {
//         printf(
//             "[%s] %s\n",
//             p->data.thoiGian,
//             p->data.noiDung
//         );
//         p = p->next;
//     }
//     printf("Tong so thao tac: %d\n", ls->count);
// }
// bool xuatLogRaFile(const DanhSachLichSu* ls, const char tenFile[])
// {
//     if (ls == NULL || tenFile == NULL)
//         return false;
//     FILE* f = fopen(tenFile, "w");
//     if (f == NULL)
//         return false;
//     NodeLichSu* p = ls->head;
//     while (p != NULL)
//     {
//         fprintf(
//             f,
//             "[%s] %s\n", p->data.thoiGian,p->data.noiDung
//         );
//         p = p->next;
//     }
//     fclose(f);
//     return true;
// }
// void giaiPhongLichSu(DanhSachLichSu* ls)
// {
//     if (ls == NULL)
//         return;
//     NodeLichSu* p;
//     while (ls->head != NULL)
//     {
//         p = ls->head;
//         ls->head = ls->head->next;
//         free(p);
//     }
//     ls->count = 0;
// }
