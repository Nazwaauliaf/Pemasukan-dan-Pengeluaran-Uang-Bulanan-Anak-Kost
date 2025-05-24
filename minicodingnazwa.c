#include <stdio.h>
#include <string.h>

#define MAX 100

// buat nyimpan transaksi
typedef struct {
    char tipe[10];      // masuk / keluar
    char ket[50];       // keterangan
    int jumlah;         // nominal
} Transaksi;

Transaksi data[MAX];
int total = 0;

// fungsi bantu buat hapus newline dari fgets
void trimBaris(char *s) {
    s[strcspn(s, "\n")] = 0;
}

void tambah() {
    if (total >= MAX) {
        printf("Data penuh!\n");
        return;
    }

    printf("\n>> Tambah Transaksi <<\n");
    printf("Tipe (masuk/keluar): ");
    scanf("%s", data[total].tipe);
    getchar(); // buang newline

    printf("Keterangan: ");
    fgets(data[total].ket, sizeof(data[total].ket), stdin);
    trimBaris(data[total].ket);

    printf("Jumlah: ");
    scanf("%d", &data[total].jumlah);

    total++;
    printf("Tersimpan.\n");
}

void tampil() {
    int masuk = 0, keluar = 0;

    printf("\n>> Riwayat Transaksi <<\n");

    for (int i = 0; i < total; i++) {
        printf("%d. [%s] %d - %s\n", i + 1, data[i].tipe, data[i].jumlah, data[i].ket);
        if (strcmp(data[i].tipe, "masuk") == 0)
            masuk += data[i].jumlah;
        else
            keluar += data[i].jumlah;
    }

    printf("\n--- Rangkuman ---\n");
    printf("Masuk  : %d\n", masuk);
    printf("Keluar : %d\n", keluar);
    printf("Saldo  : %d\n", masuk - keluar);
}

int main() {
    int pilih;

    while (1) {
        printf("\n====== Menu ======\n");
        printf("1. Tambah Transaksi\n");
        printf("2. Lihat Laporan\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        if (pilih == 1)
            tambah();
        else if (pilih == 2)
            tampil();
        else if (pilih == 3) {
            printf("Keluar...\n");
            break;
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
