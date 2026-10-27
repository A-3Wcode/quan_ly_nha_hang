#ifndef NANG_CAO_H
#define NANG_CAO_H

#include "nha_hang.h"
#include <time.h>

// 1. STACK (LIFO): UNDO THAO TÁC THÊM / XÓA / SỬA MÓN

typedef enum {
    UNDO_THEM,
    UNDO_XOA,
    UNDO_SUA
} LoaiUndo;

typedef struct ThaoTacUndo {
    LoaiUndo loai;
    MA monAnCu;
    MA monAnMoi;
} ThaoTacUndo;

typedef struct NodeStack {
    ThaoTacUndo data;
    struct NodeStack* next;
} NodeStack;

typedef struct StackUndo {
    NodeStack* top;
    int count;
} StackUndo;

void khoiTaoStack(StackUndo* stack);
bool pushUndo(StackUndo* stack, LoaiUndo loai, const MA* monAnCu, const MA* monAnMoi);
bool thucHienUndo(TD* td, StackUndo* stackUndo, StackUndo* stackRedo);
bool thucHienRedo(TD* td, StackUndo* stackRedo, StackUndo* stackUndo);
void giaiPhongStack(StackUndo* stack);


// 2. QUEUE (FIFO): CÀI ĐẶT HÀNG ĐỢI CHẾ BIẾN CHO NHÀ BẾP

typedef struct DonHangBep {
    int soBan;
    char maMon[15];
    char tenMon[50];
    time_t thoiGianGoi;
} DonHangBep;

typedef struct NodeQueue {
    DonHangBep data;
    struct NodeQueue* next;
} NodeQueue;

typedef struct QueueBep {
    NodeQueue* front;
    NodeQueue* rear;
    int count;
} QueueBep;

void khoiTaoQueue(QueueBep* q);
bool enqueueOrder(QueueBep* q, int soBan, const MA* mon);
bool dequeueOrder(QueueBep* q, DonHangBep* donXuly);
void hienThiDanhSachChoBep(const QueueBep* q);
void giaiPhongQueue(QueueBep* q);


// 3. TREE (CÂY AVL CÂN BẰNG): TÌM KIẾM MÓN TỐC ĐỘ CAO O(log N)

typedef struct NodeAVL {
    char maMon[15];
    MA* monAnPtr;               // Con trỏ trỏ trực tiếp đến nút trong TD
    int height;                 // Chiều cao nút
    struct NodeAVL* left;
    struct NodeAVL* right;
} NodeAVL;

typedef struct AVLThucDon {
    NodeAVL* root;
} AVLThucDon;

void khoiTaoAVL(AVLThucDon* tree);
int layChieuCao(NodeAVL* node);
int layHeSoCanBang(NodeAVL* node);
NodeAVL* xoayPhai(NodeAVL* y);
NodeAVL* xoayTrai(NodeAVL* x);
NodeAVL* chenVaoAVL(NodeAVL* node, MA* monAnPtr);
void xayDungCayTuThucDon(AVLThucDon* tree, const TD* td);
MA* timKiemAVL(const NodeAVL* root, const char maMon[]);
void giaiPhongAVL(NodeAVL* root);


// 4. THỐNG KÊ DỮ LIỆU

double tinhGiaTrungBinhThucDon(const TD* td);
double tinhTongGiaTriThucDon(const TD* td);
void thongKeSoMonTheoLoai(const TD* td);
double tinhTongDoanhThuCacBan(const Ban danhSachBan[], int soBanToiDa);


// 5. LỊCH SỬ THAO TÁC (LOGGING SYSTEM)

typedef struct NodeLog {
    char thoiGian[20];          // Định dạng [HH:MM:SS]
    char noiDung[100];
    struct NodeLog* next;
} NodeLog;

typedef struct LichSuLog {
    NodeLog* head;
    NodeLog* tail;
} LichSuLog;

void khoiTaoLichSu(LichSuLog* logList);
void ghiLog(LichSuLog* logList, const char noiDung[]);
void hienThiLichSu(const LichSuLog* logList);
bool xuatLogRaFile(const LichSuLog* logList, const char tenFile[]);
void giaiPhongLichSu(LichSuLog* logList);

extern StackUndo undoStack, redoStack;
#endif
