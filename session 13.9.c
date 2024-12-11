#include <stdio.h>
#include <stdlib.h>
#define KICH_THUOC_TOI_DA 100

int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int nhapMaTran(int maTran[][KICH_THUOC_TOI_DA], int *hang, int *cot) {
    printf("Nhap so hang: ");
    scanf("%d", hang);
    printf("Nhap so cot: ");
    scanf("%d", cot);

    if (*hang > KICH_THUOC_TOI_DA || *cot > KICH_THUOC_TOI_DA) {
        printf("Kich thuoc vuot qua gioi han %d. Thu lai!\n", KICH_THUOC_TOI_DA);
        return 0;
    }

    for (int i = 0; i < *hang; i++) {
        for (int j = 0; j < *cot; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
    return 1;
}

int inMaTran(int maTran[][KICH_THUOC_TOI_DA], int hang, int cot) {
    printf("Ma tran:\n");
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int inGocMaTran(int maTran[][KICH_THUOC_TOI_DA], int hang, int cot) {
    printf("Cac phan tu o goc:\n");
    printf("%d %d\n", maTran[0][0], maTran[0][cot - 1]);
    printf("%d %d\n", maTran[hang - 1][0], maTran[hang - 1][cot - 1]);
    return 1;
}

int inBienMaTran(int maTran[][KICH_THUOC_TOI_DA], int hang, int cot) {
    printf("Cac phan tu tren bien:\n");
    for (int i = 0; i < cot; i++) printf("%d ", maTran[0][i]);
    for (int i = 1; i < hang - 1; i++) printf("%d %d ", maTran[i][0], maTran[i][cot - 1]);
    for (int i = 0; i < cot; i++) printf("%d ", maTran[hang - 1][i]);
    printf("\n");
    return 1;
}

int inCheoMaTran(int maTran[][KICH_THUOC_TOI_DA], int hang, int cot) {
    if (hang != cot) {
        printf("Ma tran khong vuong, khong co duong cheo!\n");
        return 0;
    }

    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < hang; i++) printf("%d ", maTran[i][i]);
    printf("\n");

    printf("Cac phan tu tren duong cheo phu:\n");
    for (int i = 0; i < hang; i++) printf("%d ", maTran[i][hang - i - 1]);
    printf("\n");
    return 1;
}

int inSoNguyenTo(int maTran[][KICH_THUOC_TOI_DA], int hang, int cot) {
    printf("Cac so nguyen to trong ma tran:\n");
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            if (laSoNguyenTo(maTran[i][j])) {
                printf("%d ", maTran[i][j]);
            }
        }
    }
    printf("\n");
    return 1;
}

int main() {
    int maTran[KICH_THUOC_TOI_DA][KICH_THUOC_TOI_DA], hang, cot;
    int luaChon;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapMaTran(maTran, &hang, &cot);
            break;

        case 2:
            inMaTran(maTran, hang, cot);
            break;

        case 3:
            inGocMaTran(maTran, hang, cot);
            break;

        case 4:
            inBienMaTran(maTran, hang, cot);
            break;

        case 5:
            inCheoMaTran(maTran, hang, cot);
            break;

        case 6:
            inSoNguyenTo(maTran, hang, cot);
            break;

        case 7:
            printf("Thoat chuong trinh.\n");
            exit(0);

        default:
            printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

