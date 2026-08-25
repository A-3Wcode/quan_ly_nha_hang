#include "../include/nha_hang.h"

// 4. Tim kiem
MA* timKiemTheoMa(TD *td, char ma[]);
TD timKiemTheoTen(TD *td, char ten[]);
TD timKiemTheoLoai(TD *td, char loai[]);
TD timKiemTheoKhoangGia(TD *td, double giaMin, double giaMax);

// 6. Cap nhat va Sap xep
bool capNhatMonAn(TD *td, char ma[]);
void sapXepTheoMa(TD *td, bool tangDan);
void sapXepTheoTen(TD *td, bool tangDan);
void sapXepTheoGia(TD *td, bool tangDan);
