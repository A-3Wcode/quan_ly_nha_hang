// #include "../include/nang_cao.h"
// void khoiTaoQueue(QueueBep* q);
// bool enqueueOrder(QueueBep* q, int soBan, const MA* mon);
// bool dequeueOrder(QueueBep* q, DonHangBep* donXuly);
// void hienThiDanhSachChoBep(const QueueBep* q);
// void giaiPhongQueue(QueueBep* q);
// void khoiTaoQueue(QueueBep* q)
// {
//     if (q == NULL)
//         return;
//     q->front = NULL;
//     q->rear = NULL;
//     q->count = 0;
// }
// bool enqueueOrder(QueueBep* q, int soBan, const MA* mon)
// {
//     if (q == NULL || mon == NULL)
//         return false;
//     NodeQueue* p = (NodeQueue*)malloc(sizeof(NodeQueue));
//     if (p == NULL)
//         return false;
//     p->data.soBan = soBan;
//     strcpy(p->data.maMon, mon->MaMon);
//     strcpy(p->data.tenMon, mon->Ten);
//     p->data.thoiGianGoi = time(NULL);
//     p->next = NULL;
//     if (q->front == NULL)
//     {
//         q->front = p;
//         q->rear = p;
//     }
//     else
//     {
//         q->rear->next = p;
//         q->rear = p;
//     }
//     q->count++;
//     return true;
// }
// bool dequeueOrder(QueueBep* q, DonHangBep* donXuly)
// {
//     if (q == NULL || q->front == NULL || donXuly == NULL)
//         return false;

//     NodeQueue* p = q->front;
//     *donXuly = p->data;
//     q->front = q->front->next;
//     if (q->front == NULL)
//     {
//         q->rear = NULL;
//     }
//     free(p);
//     q->count--;
//     return true;
// }
// void hienThiDanhSachChoBep(const QueueBep* q)
// {
//     if (q == NULL || q->front == NULL)
//     {
//         printf("Khong co don hang cho bep!\n");
//         return;
//     }
//     NodeQueue* p = q->front;
//     printf("\n==========Danh sach cho bep ==========\n");

//     while (p != NULL)
//     {
//         char gio[20];
//         struct tm* tg = localtime(&p->data.thoiGianGoi);
//         if (tg != NULL)
//         {
//             strftime(gio, sizeof(gio), "%H:%M:%S", tg);
//         }
//         else
//         {
//             strcpy(gio, "Khong ro");
//         }
//         printf("So ban: %d\n", p->data.soBan);
//         printf("Ma mon: %s\n", p->data.maMon);
//         printf("Ten mon: %s\n", p->data.tenMon);
//         printf("Thoi gian goi: %s\n", gio);
//         printf("---------------------------------------\n");
//         p = p->next;
//     }
//     printf("Tong so don dang cho: %d\n", q->count);
// }
// void giaiPhongQueue(QueueBep* q)
// {
//     if (q == NULL)
//         return;
//     NodeQueue* p;
//     while (q->front != NULL)
//     {
//         p = q->front;
//         q->front = q->front->next;
//         free(p);
//     }
//     q->rear = NULL;
//     q->count = 0;
// }