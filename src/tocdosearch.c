#include "../include/nang_cao.h"
#include "../include/nha_hang.h"

void timeLinearTheoMa(const TD* td, const char maMon[]) {
    if (td == NULL || maMon == NULL) return;

    MA* result = NULL;
    int k = 10000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        result = timKiemTheoMa(td, maMon);
    }
    clock_t end = clock();

    // Tính thời gian trung bình cho 1 lần tìm kiếm
    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k; // Đơn vị: Giây
    double time_avg_us  = time_avg_sec * 1000000.0;                    // Đơn vị: Microgiây (us)

    if (result != NULL) {
        printf("=> Tim thay mon an: %s - %s - %s - %.2f\n", 
               result->MaMon, result->Ten, result->Loai, result->Gia);
    } else {
        printf("=> Khong tim thay mon an voi ma: %s\n", maMon);
    }

    printf("Thoi gian tim kiem tuyen tinh theo ma: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);
}

void timeLinearTheoTen(const TD* td, const char ten[]){
    if (td == NULL || ten == NULL) return;

    TD result;
    khoiTaoThucDon(&result);
    int k = 10000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        giaiPhongThucDon(&result); // Giải phóng kết quả trước khi tìm kiếm lại
        result = timKiemTheoTen(td, ten);
    }
    clock_t end = clock();

    // Tính thời gian trung bình cho 1 lần tìm kiếm
    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k; // Đơn vị: Giây
    double time_avg_us  = time_avg_sec * 1000000.0;                    // Đơn vị: Microgiây (us)

    if (result.count > 0) {
        printf("=> Tim thay %d mon an voi ten chua '%s':\n", result.count, ten);
        hienThiThucDon(&result);
    } else {
        printf("=> Khong tim thay mon an voi ten chua: '%s'\n", ten);
    }

    printf("Thoi gian tim kiem tuyen tinh theo ten: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);

    giaiPhongThucDon(&result); // Giải phóng kết quả sau khi hiển thị
}

void timeLinearTheoLoai(const TD* td, const char loai[]){
    if (td == NULL || loai == NULL) return;

    TD result;
    khoiTaoThucDon(&result);
    int k = 10000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        giaiPhongThucDon(&result); // Giải phóng kết quả trước khi tìm kiếm lại
        result = timKiemTheoLoai(td, loai);
    }
    clock_t end = clock();

    // Tính thời gian trung bình cho 1 lần tìm kiếm
    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k; // Đơn vị: Giây
    double time_avg_us  = time_avg_sec * 1000000.0;                    // Đơn vị: Microgiây (us)

    if (result.count > 0) {
        printf("=> Tim thay %d mon an voi loai '%s':\n", result.count, loai);
        hienThiThucDon(&result);
    } else {
        printf("=> Khong tim thay mon an voi loai: '%s'\n", loai);
    }

    printf("Thoi gian tim kiem tuyen tinh theo loai: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);

    giaiPhongThucDon(&result); // Giải phóng kết quả sau khi hiển thị
}

void timeLinearTheoKhoangGia(const TD* td, double giaMin, double giaMax){
    if (td == NULL) return;

    TD result;
    khoiTaoThucDon(&result);
    int k = 10000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        giaiPhongThucDon(&result); // Giải phóng kết quả trước khi tìm kiếm lại
        result = timKiemTheoKhoangGia(td, giaMin, giaMax);
    }
    clock_t end = clock();

    // Tính thời gian trung bình cho 1 lần tìm kiếm
    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k; // Đơn vị: Giây
    double time_avg_us  = time_avg_sec * 1000000.0;                    // Đơn vị: Microgiây (us)

    if (result.count > 0) {
        printf("=> Tim thay %d mon an trong khoang gia %.2f - %.2f:\n", result.count, giaMin, giaMax);
        hienThiThucDon(&result);
    } else {
        printf("=> Khong tim thay mon an trong khoang gia %.2f - %.2f\n", giaMin, giaMax);
    }

    printf("Thoi gian tim kiem tuyen tinh theo khoang gia: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);

    giaiPhongThucDon(&result); // Giải phóng kết quả sau khi hiển thị
}

void timeAVLTheoMa(const AVLThucDon* tree, const char maMon[]) {
    if (tree == NULL || tree->root == NULL || maMon == NULL) return;

    MA* result = NULL;
    int k = 100000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        result = timKiemAVLTheoMa(tree->root, maMon);
    }
    clock_t end = clock();

    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k;
    double time_avg_us  = time_avg_sec * 1000000.0;

    if (result != NULL) {
        printf("=> Tim thay mon an: %s - %s - %s - %.2f\n", 
               result->MaMon, result->Ten, result->Loai, result->Gia);
    } else {
        printf("=> Khong tim thay mon an voi ma: %s\n", maMon);
    }

    printf("Thoi gian tim kiem AVL (Pure Search) theo ma: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);
}

void timeAVLTheoTen(const AVLThucDon* tree, const char ten[]) {
    if (tree == NULL || tree->root == NULL || ten == NULL) return;

    TD result;
    khoiTaoThucDon(&result);
    int k = 2000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        giaiPhongThucDon(&result);
        duyetAVLTen(tree->root, ten, &result);
    }
    clock_t end = clock();

    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k;
    double time_avg_us  = time_avg_sec * 1000000.0;

    if (result.count > 0) {
        printf("=> Tim thay %d mon an voi ten chua '%s':\n", result.count, ten);
        hienThiThucDon(&result);
    } else {
        printf("=> Khong tim thay mon an voi ten chua: '%s'\n", ten);
    }

    printf("Thoi gian tim kiem AVL theo ten: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);

    giaiPhongThucDon(&result);
}

void timeAVLTheoLoai(const AVLThucDon* tree, const char loai[]) {
    if (tree == NULL || tree->root == NULL || loai == NULL) return;

    TD result;
    khoiTaoThucDon(&result);
    int k = 2000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        giaiPhongThucDon(&result);
        duyetAVLLoai(tree->root, loai, &result);
    }
    clock_t end = clock();

    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k;
    double time_avg_us  = time_avg_sec * 1000000.0;

    if (result.count > 0) {
        printf("=> Tim thay %d mon an voi loai '%s':\n", result.count, loai);
        hienThiThucDon(&result);
    } else {
        printf("=> Khong tim thay mon an voi loai: '%s'\n", loai);
    }

    printf("Thoi gian tim kiem AVL theo loai: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);

    giaiPhongThucDon(&result);
}

void timeAVLTheoKhoangGia(const AVLThucDon* tree, double giaMin, double giaMax) {
    if (tree == NULL || tree->root == NULL) return;

    TD result;
    khoiTaoThucDon(&result);
    int k = 2000;

    clock_t start = clock();
    for (int i = 0; i < k; i++) {
        giaiPhongThucDon(&result);
        duyetAVLKhoangGia(tree->root, giaMin, giaMax, &result);
    }
    clock_t end = clock();

    double time_avg_sec = ((double)(end - start) / CLOCKS_PER_SEC) / k;
    double time_avg_us  = time_avg_sec * 1000000.0;

    if (result.count > 0) {
        printf("=> Tim thay %d mon an trong khoang gia %.2f - %.2f:\n", result.count, giaMin, giaMax);
        hienThiThucDon(&result);
    } else {
        printf("=> Khong tim thay mon an trong khoang gia %.2f - %.2f\n", giaMin, giaMax);
    }

    printf("Thoi gian tim kiem AVL theo khoang gia: %.8f giay (%.2f us)\n", time_avg_sec, time_avg_us);

    giaiPhongThucDon(&result);
}

