#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxKODE 10

// struktur untuk data kamar
typedef struct Kamar {
    char kode[maxKODE];  // batas string kode 10
    int harga;
    int kategori;  // 0 EKONOMI, 1 VIP
    struct Kamar *next;
} Kamar;

// pemanggilan fungsi-fungsi
Kamar *buatKamar(char *kode, int harga, int kategori);
void tambahKamar(Kamar **head, char *kode, int harga, int kategori);
void tampilkanKamar(Kamar *head);
Kamar *cariKamar(Kamar *head, char *kode);
void urutkanKode(Kamar **head);
void urutkanTermurah(Kamar **head);
void urutkanTermahal(Kamar **head);
void tampilkanKategori(Kamar *head, int kategori);
void editKamar(Kamar *head, char *kode, int harga, int kategori);
void hapusKamar(Kamar **head, char *kode);
int clearScreen();

// fungsi utama
int main() {
    Kamar *head = NULL;
    int pilihan, harga, angka, kategori;
    char kode[maxKODE];
    Kamar *kamar;
    int kamarBaruDitemukan = 0;

    // menambahkan beberapa kamar default secara acak
    tambahKamar(&head, "Kamar-03", 1800000, 1);
    tambahKamar(&head, "Kamar-10", 400000, 0);
    tambahKamar(&head, "Kamar-15", 200000, 0);
    tambahKamar(&head, "Kamar-01", 1800000, 1);
    tambahKamar(&head, "Kamar-08", 400000, 0);

    do {
        system("cls");
        printf(" |\\_____________________________________________/|\n");
        printf(" |>  _  _ _  _ ___     _  _ ____ ___ ____ _     <|\n");
        printf(" |>  |  | |\\ | |__]    |__| |  |  |  |___ |     <|\n");
        printf(" |>  |__| | \\| |       |  | |__|  |  |___ |___  <|\n");
        printf(" \\_______________________________________________/\n\n");

        printf("[]===============================================[]\n");
        printf(" | NO | Menu                                     |\n");
        printf(" |----|------------------------------------------|\n");
        printf(" | 1  | Tampilkan list kamar hotel               |\n");
        printf(" | 2  | Cari kamar hotel                         |\n");
        printf(" | 3  | List kamar berdasarkan nomor             |\n");
        printf(" | 4  | List kamar berdasarkan harga             |\n");
        printf(" | 5  | Filter kategori                          |\n");
        printf(" | 6  | Input kamar baru                         |\n");
        printf(" | 7  | Edit kamar                               |\n");
        printf(" | 8  | Hapus kamar                              |\n");
        printf(" |----|------------------------------------------|\n");
        printf(" | 9  | Keluar Program                           |\n");
        printf("[]===============================================[]\n");
        printf(" ~~> Pilihan: ");
        scanf("%d", &pilihan);

        system("cls");
        switch (pilihan) {
            case 1:
                system("cls");
                tampilkanKamar(head);
                clearScreen();
                break;

            case 2:
                printf(" |_> Masukkan kode kamar: \n");
                printf(" |_> Kamar-");
                scanf("%d", &angka);
                snprintf(kode, sizeof(kode), "Kamar-%02d", angka);
                kamar = cariKamar(head, kode);

                system("cls");
                if (kamar != NULL) {
                    if (kamar != NULL) {
                        printf("[]== Informasi Kamar ============[]\n");
                        printf(" | > Kamar    : %s\t |\n", kamar->kode);
                        printf(" | > Harga    : %d\t\t |\n", kamar->harga);
                        if (kamar->kategori) {
                            printf(" | > Kategori : VIP              |\n");
                        } else {
                            printf(" | > Kategori : EKONOMI          |\n");
                        }
                        printf("[]-------------------------------[]\n");
                    }
                } else {
                    system("cls");
                    printf("[ Kamar dengan kode-%02d tidak ditemukan ]\n", angka);
                }

                clearScreen();
                break;

            case 3:
                urutkanKode(&head);
                tampilkanKamar(head);
                clearScreen();
                break;

            case 4:
                printf("[]--------------- Menu ------------------[]\n");
                printf(" | 1 | Urutkan dari harga yang termurah  |\n");
                printf(" | 2 | Urutkan dari harga yang termahal  |\n");
                printf("[]---------------------------------------[]\n");
                printf(" ~~> Pilihan: ");
                scanf("%d", &pilihan);

                system("cls");
                switch (pilihan) {
                    case 1:
                        urutkanTermurah(&head);
                        break;
                    case 2:
                        urutkanTermahal(&head);
                        break;
                    default:
                        printf("Pilihan tidak valid.\n");
                        break;
                }
                tampilkanKamar(head);
                clearScreen();
                break;

            case 5:
                printf("[]------------ Menu ------------[]\n");
                printf(" | 1 | Tampilkan kamar VIP      |\n");
                printf(" | 2 | Tampilkan kamar Ekonomi  |\n");
                printf("[]------------------------------[]\n");
                printf(" ~~> Pilihan: ");
                scanf("%d", &pilihan);

                system("cls");
                switch (pilihan) {
                    case 1:
                        tampilkanKategori(head, 1);
                        break;
                    case 2:
                        tampilkanKategori(head, 0);
                        break;
                    default:
                        printf("[ Pilihan tidak valid ]");
                        break;
                }
                clearScreen();
                break;

            case 6:
                do {
                    kamarBaruDitemukan = 0;
                    printf(" |_> Masukkan kode kamar: \n");
                    printf(" |_> Kamar-");
                    scanf("%d", &angka);
                    snprintf(kode, sizeof(kode), "Kamar-%02d", angka);
                    if (cariKamar(head, kode) != NULL) {
                        printf("\n[ Kamar sudah ada, silahkan pilih nomor lain ]");
                        getch();
                        system("cls");
                    } else {
                        kamarBaruDitemukan = 1;
                    }
                } while (!kamarBaruDitemukan);

                printf(" |\n");
                printf(" |_> Masukkan harga kamar: ");
                scanf("%d", &harga);

                // cek harga, jika diatas 1 juta, maka kategori VIP (1)
                kategori = 0;
                if (harga >= 1000000) {
                    kategori = 1;
                }

                tambahKamar(&head, kode, harga, kategori);
                clearScreen();
                break;

            case 7:
                printf(" |_> Masukkan kode kamar yang akan di edit: \n");
                printf(" |_> Kamar-");
                scanf("%d", &angka);
                snprintf(kode, sizeof(kode), "Kamar-%02d", angka);

                kamar = cariKamar(head, kode);
                if (kamar != NULL) {
                    printf(" |_> Masukkan harga baru: ");
                    scanf("%d", &harga);

                    // cek harga, jika diatas 1 juta, maka kategori VIP (1)
                    kategori = 0;
                    if (harga >= 1000000) {
                        kategori = 1;
                    }

                    editKamar(head, kode, harga, kategori);
                } else {
                    printf("[ Kamar dengan kode-%02d tidak ditemukan ]\n", angka);
                }
                clearScreen();
                break;

            case 8:
                printf(" |_> Masukkan kode kamar yang akan dihapus: \n");
                printf(" |_> Kamar-");
                scanf("%d", &angka);
                snprintf(kode, sizeof(kode), "Kamar-%02d", angka);

                hapusKamar(&head, kode);
                clearScreen();
                break;

            case 9:
                printf("[ TERIMAKASIH TELAH MENGGUNAKAN PROGRAM ]");
                getch();
                break;

            default:
                printf("[ Pilihan tidak valid ]");
                getch();
        }
    } while (pilihan != 9);

    return 0;
}

// ---- fungsi-fungsi yang akan dipanggil ----

// membuat kamar baru
Kamar *buatKamar(char *kode, int harga, int kategori) {
    Kamar *kamarBaru = (Kamar *)malloc(sizeof(Kamar));
    strcpy(kamarBaru->kode, kode);
    kamarBaru->harga = harga;
    kamarBaru->kategori = kategori;
    kamarBaru->next = NULL;
    return kamarBaru;
}

// menambahkan kamar ke linked list
void tambahKamar(Kamar **head, char *kode, int harga, int kategori) {
    Kamar *kamarBaru = buatKamar(kode, harga, kategori);
    kamarBaru->next = *head;
    *head = kamarBaru;
}

// menampilkan daftar kamar
void tampilkanKamar(Kamar *head) {
    Kamar *temp = head;
    printf("[]===============================================[]\n");
    printf(" | Kategori | Kode          | Harga              |\n");
    printf(" |----------|---------------|--------------------|\n");

    while (temp != NULL) {
        if (temp->kategori) {
            printf(" | VIP      | %s      | %d \t\t |\n", temp->kode, temp->harga);
        } else {
            printf(" | EKONOMI  | %s      | %d \t\t |\n", temp->kode, temp->harga);
        }

        temp = temp->next;
    }

    printf("[]===============================================[]\n");
}

// mencari kamar berdasarkan kode
Kamar *cariKamar(Kamar *head, char *kode) {
    Kamar *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->kode, kode) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// mengurutkan kamar berdasarkan kode (bubble sort)
void urutkanKode(Kamar **head) {
    if (*head == NULL) return;

    Kamar *i, *j;
    char tempKode[maxKODE];
    int tempHarga, tempkategori;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->kode, j->kode) > 0) {
                strcpy(tempKode, i->kode);
                strcpy(i->kode, j->kode);
                strcpy(j->kode, tempKode);

                tempHarga = i->harga;
                i->harga = j->harga;
                j->harga = tempHarga;

                tempkategori = i->kategori;
                i->kategori = j->kategori;
                j->kategori = tempkategori;
            }
        }
    }
}

// mengurutkan kamar berdasarkan harga termurah (bubble sort)
void urutkanTermurah(Kamar **head) {
    if (*head == NULL) return;

    Kamar *i, *j;
    char tempKode[maxKODE];
    int tempHarga, tempkategori;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->harga > j->harga) {
                strcpy(tempKode, i->kode);
                strcpy(i->kode, j->kode);
                strcpy(j->kode, tempKode);

                tempHarga = i->harga;
                i->harga = j->harga;
                j->harga = tempHarga;

                tempkategori = i->kategori;
                i->kategori = j->kategori;
                j->kategori = tempkategori;
            }
        }
    }
}

// mengurutkan kamar berdasarkan harga termahal (bubble sort)
void urutkanTermahal(Kamar **head) {
    if (*head == NULL) return;

    Kamar *i, *j;
    char tempKode[maxKODE];
    int tempHarga, tempkategori;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->harga < j->harga) {
                strcpy(tempKode, i->kode);
                strcpy(i->kode, j->kode);
                strcpy(j->kode, tempKode);

                tempHarga = i->harga;
                i->harga = j->harga;
                j->harga = tempHarga;

                tempkategori = i->kategori;
                i->kategori = j->kategori;
                j->kategori = tempkategori;
            }
        }
    }
}

// tampilkan kategori EKONOMI atau VIP
void tampilkanKategori(Kamar *head, int kategori) {
    Kamar *temp = head;

    if (kategori == 1) {
        printf("  __________~!!\\ ----   VIP  ---- /!!~___________\n");
    } else {
        printf("  __________~!!\\ ---  EKONOMI  --- /!!~__________\n");
    }

    printf("[]===============================================[]\n");
    printf(" | Kategori | Kode          | Harga              |\n");
    printf(" |----------|---------------|--------------------|\n");

    while (temp != NULL) {
        if (temp->kategori == kategori) {
            if (temp->kategori) {
                printf(" | VIP      | %s      | %d \t\t |\n", temp->kode, temp->harga);
            } else {
                printf(" | EKONOMI  | %s      | %d \t\t |\n", temp->kode, temp->harga);
            }
        }
        temp = temp->next;
    }

    printf("[]===============================================[]\n");
}

// edit data kamar
void editKamar(Kamar *head, char *kode, int harga, int kategori) {
    Kamar *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->kode, kode) == 0) {
            temp->harga = harga;
            temp->kategori = kategori;
            system("cls");
            printf("[ Data kamar berhasil diubah ]\n");
            return;
        }
        temp = temp->next;
    }
    system("cls");
    printf("[ Kamar dengan kode %s tidak ditemukan ]\n", kode);
}

// hapus data kamar
void hapusKamar(Kamar **head, char *kode) {
    Kamar *temp = *head;
    Kamar *prev = NULL;

    // cek apakah kamar yang akan dihapus adalah kamar pertama
    if (temp != NULL && strcmp(temp->kode, kode) == 0) {
        *head = temp->next;
        free(temp);
        system("cls");
        printf("[ Kamar dengan kode %s berhasil dihapus ]\n", kode);
        return;
    }

    // cari kamar yang akan dihapus
    while (temp != NULL && strcmp(temp->kode, kode) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        system("cls");
        printf("[ Kamar dengan kode %s tidak ditemukan ]\n", kode);
        return;
    }

    // Hapus kamar
    prev->next = temp->next;
    free(temp);
    system("cls");
    printf("[ Kamar dengan kode %s berhasil dihapus ]\n", kode);
}

// tekan enter dan clear terminal
int clearScreen() {
    printf("\n[ Ketik Enter Untuk Kembali ]");
    getch();
    system("cls");
    fflush(stdin);
}