#include "../include/nang_cao.h"
void khoiTaoQueue(QueueBep* q);
bool enqueueOrder(QueueBep* q, int soBan, const MA* mon);
bool dequeueOrder(QueueBep* q, DonHangBep* donXuly);
void hienThiDanhSachChoBep(const QueueBep* q);
void giaiPhongQueue(QueueBep* q);
