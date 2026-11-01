#include "../include/nang_cao.h"

void khoiTaoAVL(AVLThucDon* tree){
    if (tree == NULL){
        printf("Loi: Cay AVL khong hop le\n");
        return;
    }
    tree->root = NULL;
}

int layChieuCao(NodeAVL* node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}

int layHeSoCanBang(NodeAVL* node){
    if (node == NULL){
        return 0;
    }
    return layChieuCao(node->left) - layChieuCao(node->right);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

NodeAVL* xoayPhai(NodeAVL* y){
    NodeAVL* x = y->left;
    NodeAVL* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật chiều cao
    y->height = 1 + max(layChieuCao(y->left), layChieuCao(y->right));
    x->height = 1 + max(layChieuCao(x->left), layChieuCao(x->right));

    // Trả về nút gốc mới
    return x;
}

NodeAVL* xoayTrai(NodeAVL* x){
    NodeAVL* y = x->right;
    NodeAVL* T2 = y->left;

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = 1 + max(layChieuCao(x->left), layChieuCao(x->right));
    y->height = 1 + max(layChieuCao(y->left), layChieuCao(y->right));

    // Trả về nút gốc mới
    return y;
}

NodeAVL* chenVaoAVL(NodeAVL* node, MA* monAnPtr){
    // Nếu cây rỗng, tạo một nút mới
    if (node == NULL) {
        NodeAVL* newNode = (NodeAVL*)malloc(sizeof(NodeAVL));
        if (!newNode){
            printf("Loi cap bo nho cho NodeAVL\n");
            return NULL;
        }

        newNode->monAnPtr = monAnPtr;
        newNode->height = 1; // Chiều cao của nút mới là 1
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // So sánh mã món để xác định vị trí chèn
    int cmp = strcmp(monAnPtr->MaMon, node->monAnPtr->MaMon);
    if (cmp < 0) {
        node->left = chenVaoAVL(node->left, monAnPtr);
    } else if (cmp > 0) {
        node->right = chenVaoAVL(node->right, monAnPtr);
    } else {
        // Nếu mã món đã tồn tại, không thêm vào cây
        return node;
    }

    // Cập nhật chiều cao của nút hiện tại
    node->height = 1 + max(layChieuCao(node->left), layChieuCao(node->right));

    // Tính toán hệ số cân bằng
    int balance = layHeSoCanBang(node);
    // Trái Trái
    if (balance > 1 && strcmp(monAnPtr->MaMon, node->left->monAnPtr->MaMon) < 0) {
        return xoayPhai(node);
    }
    // Phải Phải
    if (balance < -1 && strcmp(monAnPtr->MaMon, node->right->monAnPtr->MaMon) > 0) {
        return xoayTrai(node);
    }
    // Trái Phải
    if (balance > 1 && strcmp(monAnPtr->MaMon, node->left->monAnPtr->MaMon) > 0) {
        node->left = xoayTrai(node->left);
        return xoayPhai(node);
    }
    // Phải Trái
    if (balance < -1 && strcmp(monAnPtr->MaMon, node->right->monAnPtr->MaMon) < 0) {
        node->right = xoayPhai(node->right);
        return xoayTrai(node);
    }

    return node;
}

void xayDungCayTuThucDon(AVLThucDon* tree, const TD* td){
    if (!tree || !td){
        printf("Loi: Cay AVL hoac ThucDon khong hop le\n");
        return;
    }

    if(tree->root != NULL){
        giaiPhongAVL(tree->root);
    }
    tree->root = NULL; // Khởi tạo cây AVL rỗng

    MA *curr = td->head;
    while (curr != NULL) {
        tree->root = chenVaoAVL(tree->root, curr);
        if(tree->root == NULL){
            printf("Loi: Khong the chen vao cay AVL\n");
            return;
        }
        curr = curr->next;
    }
}

MA* timKiemAVLTheoMa(const NodeAVL* root, const char maMon[]){
    if (root == NULL || maMon == NULL) {
        return NULL; // Không tìm thấy
    }

    int cmp = strcmp(maMon, root->monAnPtr->MaMon);
    if (cmp == 0) {
        return root->monAnPtr; // Tìm thấy
    } else if (cmp < 0) {
        return timKiemAVLTheoMa(root->left, maMon); // Tìm ở cây con trái
    } else {
        return timKiemAVLTheoMa(root->right, maMon); // Tìm ở cây con phải
    }
}

void duyetAVLTen(const NodeAVL* root, const char ten[], TD* ketQua){
    if (root == NULL || ten == NULL || ketQua == NULL) {
        return;
    }

    duyetAVLTen(root->left, ten, ketQua);
    if (strstr(root->monAnPtr->Ten, ten) != NULL) {
        themMonAnSaoChep(ketQua, root->monAnPtr);
    }
    duyetAVLTen(root->right, ten, ketQua);
}

void duyetAVLLoai(const NodeAVL* root, const char loai[], TD* ketQua){
    if (root == NULL || loai == NULL || ketQua == NULL) {
        return;
    }

    duyetAVLLoai(root->left, loai, ketQua);
    if (strstr(root->monAnPtr->Loai, loai) != NULL) {
        themMonAnSaoChep(ketQua, root->monAnPtr);
    }
    duyetAVLLoai(root->right, loai, ketQua);
}

void duyetAVLKhoangGia(const NodeAVL* root, double giaMin, double giaMax, TD* ketQua){
    if (root == NULL || ketQua == NULL) {
        return;
    }

    duyetAVLKhoangGia(root->left, giaMin, giaMax, ketQua);
    if (root->monAnPtr->Gia >= giaMin && root->monAnPtr->Gia <= giaMax) {
        themMonAnSaoChep(ketQua, root->monAnPtr);
    }
    duyetAVLKhoangGia(root->right, giaMin, giaMax, ketQua);
}

TD timKiemAVLTheoTen(const NodeAVL* root, const char ten[]){
    TD ketQua;
    khoiTaoThucDon(&ketQua);

    if (root != NULL && ten != NULL) {
        duyetAVLTen(root, ten, &ketQua);
    }
    return ketQua;

}

TD timKiemAVLTheoLoai(const NodeAVL* root, const char loai[]){
    TD ketQua;
    khoiTaoThucDon(&ketQua);

    if (root != NULL && loai != NULL) {
        duyetAVLLoai(root, loai, &ketQua);
    }
    return ketQua;
}

TD timKiemAVLTheoKhoangGia(const NodeAVL* root, double giaMin, double giaMax){
    TD ketQua;
    khoiTaoThucDon(&ketQua);

    if (root != NULL && giaMin <= giaMax && giaMin >= 0) {
        duyetAVLKhoangGia(root, giaMin, giaMax, &ketQua);
    }
    return ketQua;
}

void giaiPhongAVL(NodeAVL* root){
    if (root == NULL) {
        return;
    }

    giaiPhongAVL(root->left);
    giaiPhongAVL(root->right);
    free(root);
}
