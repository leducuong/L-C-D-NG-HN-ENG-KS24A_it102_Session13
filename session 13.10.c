#include <stdio.h>
#include <stdlib.h>
#define KICH_THUOC_TOI_DA 100

int nhapMang(int mang[], int *soLuong) {
    printf("Nhap so phan tu: ");
    scanf("%d", soLuong);

    if (*soLuong > KICH_THUOC_TOI_DA) {
        printf("So phan tu vuot qua gioi han %d. Thu lai!\n", KICH_THUOC_TOI_DA);
        return 0;
    }

    for (int i = 0; i < *soLuong; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &mang[i]);
    }
    return 1;
}

int inMang(int mang[], int soLuong) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < soLuong; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
    return 1;
}

int themPhanTu(int mang[], int *soLuong, int viTri, int giaTri) {
    if (*soLuong >= KICH_THUOC_TOI_DA) {
        printf("Mang da day. Khong the them!\n");
        return 0;
    }

    if (viTri < 0 || viTri > *soLuong) {
        printf("Vi tri khong hop le!\n");
        return 0;
    }

    for (int i = *soLuong; i > viTri; i--) {
        mang[i] = mang[i - 1];
    }

    mang[viTri] = giaTri;
    (*soLuong)++;
    return 1;
}

int suaPhanTu(int mang[], int soLuong, int viTri, int giaTri) {
    if (viTri < 0 || viTri >= soLuong) {
        printf("Vi tri khong hop le!\n");
        return 0;
    }

    mang[viTri] = giaTri;
    return 1;
}

int xoaPhanTu(int mang[], int *soLuong, int viTri) {
    if (viTri < 0 || viTri >= *soLuong) {
        printf("Vi tri khong hop le!\n");
        return 0;
    }

    for (int i = viTri; i < *soLuong - 1; i++) {
        mang[i] = mang[i + 1];
    }

    (*soLuong)--;
    return 1;
}

int sapXepMang(int mang[], int soLuong, int thuTu) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if ((thuTu == 1 && mang[i] < mang[j]) || (thuTu == 0 && mang[i] > mang[j])) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
    return 1;
}

int timKiemTuyenTinh(int mang[], int soLuong, int khoa) {
    for (int i = 0; i < soLuong; i++) {
        if (mang[i] == khoa) {
            return i;
        }
    }
    return -1;
}

int timKiemNhiPhan(int mang[], int soLuong, int khoa) {
    int trai = 0, phai = soLuong - 1;

    while (trai <= phai) {
        int giua = trai + (phai - trai) / 2;

        if (mang[giua] == khoa) {
            return giua;
        } else if (mang[giua] < khoa) {
            trai = giua + 1;
        } else {
            phai = giua - 1;
        }
    }
    return -1;
}

int main() {
    int mang[KICH_THUOC_TOI_DA], soLuong = 0;
    int luaChon, luaChonPhu, viTri, giaTri, khoa, ketQua;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri\n");
        printf("2. In ra cac phan tu\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapMang(mang, &soLuong);
            break;

        case 2:
            inMang(mang, soLuong);
            break;

        case 3:
            printf("Nhap vi tri muon them: ");
            scanf("%d", &viTri);
            printf("Nhap gia tri muon them: ");
            scanf("%d", &giaTri);
            themPhanTu(mang, &soLuong, viTri, giaTri);
            break;

        case 4:
            printf("Nhap vi tri muon sua: ");
            scanf("%d", &viTri);
            printf("Nhap gia tri moi: ");
            scanf("%d", &giaTri);
            suaPhanTu(mang, soLuong, viTri, giaTri);
            break;

        case 5:
            printf("Nhap vi tri muon xoa: ");
            scanf("%d", &viTri);
            xoaPhanTu(mang, &soLuong, viTri);
            break;

        case 6:
            printf("1. Giam dan\n");
            printf("2. Tang dan\n");
            printf("Nhap lua chon: ");
            scanf("%d", &luaChonPhu);
            if (luaChonPhu == 1) {
                sapXepMang(mang, soLuong, 1);
            } else if (luaChonPhu == 2) {
                sapXepMang(mang, soLuong, 0);
            } else {
                printf("Lua chon khong hop le!\n");
            }
            break;

        case 7:
            printf("1. Tim kiem tuyen tinh\n");
            printf("2. Tim kiem nhi phan\n");
            printf("Nhap lua chon: ");
            scanf("%d", &luaChonPhu);
            printf("Nhap gia tri can tim: ");
            scanf("%d", &khoa);
            if (luaChonPhu == 1) {
                ketQua = timKiemTuyenTinh(mang, soLuong, khoa);
            } else if (luaChonPhu == 2) {
                sapXepMang(mang, soLuong, 0);
                ketQua = timKiemNhiPhan(mang, soLuong, khoa);
            } else {
                printf("Lua chon khong hop le!\n");
                break;
            }

            if (ketQua != -1) {
                printf("Gia tri tim thay tai vi tri %d\n", ketQua);
            } else {
                printf("Khong tim thay gia tri!\n");
            }
            break;

        case 8:
            printf("Thoat chuong trinh.\n");
            exit(0);

        default:
            printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

