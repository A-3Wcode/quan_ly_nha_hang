#include "../include/nang_cao.h"
#include <string.h>

// 1. Khởi tạo Stack
void khoiTaoStack(StackUndo* stack) {
    if (stack != NULL) {
        stack->top = NULL;
        stack->count = 0;
    }
}

// 2. Đẩy thao tác vào Stack (push)
bool pushUndo(StackUndo* stack, LoaiUndo loai, const MA* monAnCu, const MA* monAnMoi) {
    if (stack == NULL) return false;
    
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho cho Stack!\n");
        return false;
    }
    
    newNode->data.loai = loai;
    
    // Lưu trạng thái dữ liệu
    if (monAnCu != NULL) newNode->data.monAnCu = *monAnCu; 
    if (monAnMoi != NULL) newNode->data.monAnMoi = *monAnMoi;
    
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
    
    return true;
}

// Hàm phụ trợ: Lấy thao tác khỏi Stack (pop)
bool popUndo(StackUndo* stack, ThaoTacUndo* outData) {
    if (stack == NULL || stack->top == NULL) return false;
    
    NodeStack* temp = stack->top;
    *outData = temp->data;
    
    stack->top = temp->next;
    stack->count--;
    free(temp);
    
    return true;
}

// 3. Thực hiện Undo (Hành động ngược lại)
bool thucHienUndo(TD* td, StackUndo* stackUndo, StackUndo* stackRedo) {
    ThaoTacUndo thaoTac;
    if (!popUndo(stackUndo, &thaoTac)) {
        printf("Khong co thao tac nao de Undo!\n");
        return false;
    }
    
    // Đẩy thao tác vừa Undo vào Stack Redo
    if (stackRedo != NULL) {
        pushUndo(stackRedo, thaoTac.loai, &thaoTac.monAnCu, &thaoTac.monAnMoi);
    }
    
    switch (thaoTac.loai) {
        case UNDO_THEM: {
            // Undo Thêm -> Xóa món ăn
            xoaTheoMa(td, thaoTac.monAnMoi.MaMon);
            printf("Da Undo: Xoa mon an %s vua them.\n", thaoTac.monAnMoi.MaMon);
            break;
        }
        case UNDO_XOA: {
            // Undo Xóa -> Thêm lại món ăn cũ
            MA* monPhucHoi = taoMonAn(thaoTac.monAnCu.MaMon, thaoTac.monAnCu.Ten, thaoTac.monAnCu.Loai, thaoTac.monAnCu.Gia);
            themMonAn(td, monPhucHoi);
            printf("Da Undo: Khoi phuc mon an %s vua xoa.\n", thaoTac.monAnCu.MaMon);
            break;
        }
        case UNDO_SUA: {
            // Undo Sửa -> Gán lại giá trị cũ
            MA* mon = timKiemTheoMa(td, thaoTac.monAnMoi.MaMon);
            if (mon != NULL) {
                strcpy(mon->Ten, thaoTac.monAnCu.Ten);
                strcpy(mon->Loai, thaoTac.monAnCu.Loai);
                mon->Gia = thaoTac.monAnCu.Gia;
                printf("Da Undo: Khoi phuc thong tin cu cua mon %s.\n", mon->MaMon);
            }
            break;
        }
    }
    return true;
}

// 4. Thực hiện Redo (Làm lại thao tác vừa Undo)
bool thucHienRedo(TD* td, StackUndo* stackRedo, StackUndo* stackUndo) {
    ThaoTacUndo thaoTac;
    if (!popUndo(stackRedo, &thaoTac)) {
        printf("Khong co thao tac nao de Redo!\n");
        return false;
    }
    
    // Đẩy ngược lại vào Undo
    if (stackUndo != NULL) {
        pushUndo(stackUndo, thaoTac.loai, &thaoTac.monAnCu, &thaoTac.monAnMoi);
    }
    
    switch (thaoTac.loai) {
        case UNDO_THEM: {
            // Redo Thêm -> Thêm lại món ăn
            MA* monThem = taoMonAn(thaoTac.monAnMoi.MaMon, thaoTac.monAnMoi.Ten, thaoTac.monAnMoi.Loai, thaoTac.monAnMoi.Gia);
            themMonAn(td, monThem);
            printf("Da Redo: Them lai mon an %s.\n", thaoTac.monAnMoi.MaMon);
            break;
        }
        case UNDO_XOA: {
            // Redo Xóa -> Xóa lại món ăn
            xoaTheoMa(td, thaoTac.monAnCu.MaMon);
            printf("Da Redo: Xoa lai mon an %s.\n", thaoTac.monAnCu.MaMon);
            break;
        }
        case UNDO_SUA: {
            // Redo Sửa -> Gán lại giá trị mới cập nhật
            MA* mon = timKiemTheoMa(td, thaoTac.monAnMoi.MaMon);
            if (mon != NULL) {
                strcpy(mon->Ten, thaoTac.monAnMoi.Ten);
                strcpy(mon->Loai, thaoTac.monAnMoi.Loai);
                mon->Gia = thaoTac.monAnMoi.Gia;
                printf("Da Redo: Cap nhat lai thong tin mon %s.\n", mon->MaMon);
            }
            break;
        }
    }
    return true;
}

// 5. Giải phóng Stack
void giaiPhongStack(StackUndo* stack) {
    if (stack == NULL) return;
    NodeStack* current = stack->top;
    while (current != NULL) {
        NodeStack* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->count = 0;
}