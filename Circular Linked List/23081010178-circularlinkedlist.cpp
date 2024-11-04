#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahAkhir(node **head);
void tambahTengah(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node **head);
void sumData(node **head);
void tranverse(node *head);

//========================================================

int main() {
    node *head;
    char pilih;

    head = NULL;
    do {
        system("cls");
        printf("Masukkan pilihan: \n");
        printf("\n1. tambah data di awal\n");
        printf("2. tambah data di akhir list\n");
        printf("3. tambah data di tengah list\n");
        printf("4. hapus data di awal list\n");
        printf("5. hapus data di tengah list\n");
        printf("6. hapus data di akhir list\n");
        printf("7. mencari data di tengah list\n");
        printf("8. jumlahkan isi list\n");
        printf("9. cetak isi list\n");
        printf("\nMASUKKAN PILIHAN (masukkan q untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &pilih);

        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahAkhir(&head);
        else if (pilih == '3')
            tambahTengah(&head);
        else if (pilih == '4')
            hapusAwal(&head);
        else if (pilih == '5')
            hapusTengah(&head);
        else if (pilih == '6')
            hapusAkhir(&head);
        else if (pilih == '7')
            cariData(&head);
        else if (pilih == '8')
            sumData(&head);
        else if (pilih == '9') {
            tranverse(head);
            getch();
        } else if (pilih != 'q') {
            printf("\nMasukkan opsi yang tertera! (Tekan ENTER untuk lanjut)\n");
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

//=============== MENAMBAHKAN DATA DI AWAL LIST ========================

void tambahAwal(node **head) {
    int bil;
    node *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            pNew->next = pNew;
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            pNew->next = *head;
            pLast->next = pNew;
            *head = pNew;
        }
    } else {
        printf("\nalokasi memori gagal");
        getch();
    }
}

//=============== MENAMBAHKAN DATA DI AKHIR LIST ========================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pLast;
    system("cls");
    printf("masukkan bilangan: ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            pNew->next = pNew;
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            pLast->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("\nalokasi memori gagal");
        getch();
    }
}

//=============== MENAMBAHKAN DATA DI TENGAH LIST ========================

void tambahTengah(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    do {
        if (pCur->data == pos) {
            pNew = (node *)malloc(sizeof(node));
            if (pNew != NULL) {
                pNew->data = bil;
                pNew->next = pCur->next;
                pCur->next = pNew;
            } else {
                printf("\nalokasi memori gagal");
                getch();
            }
            return;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    printf("\nData %d tidak ditemukan.\n", pos);
    getch();
}

//=============== MENGHAPUS DATA DI AWAL LIST ========================

void hapusAwal(node **head) {
    node *pTemp, *pLast;

    if (*head == NULL) {
        printf("List kosong.\n");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        pTemp = *head;
        pLast = *head;
        while (pLast->next != *head) {
            pLast = pLast->next;
        }
        *head = (*head)->next;
        pLast->next = *head;
        free(pTemp);
        printf("Data pertama berhasil dihapus.\n");
    }
    getch();
}

//=============== MENGHAPUS DATA DI TENGAH LIST ========================

void hapusTengah(node **head) {
    int bil;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan data yang ingin dihapus: ");
    scanf("%d", &bil);

    pCur = *head;
    pPrev = NULL;

    do {
        if (pCur->data == bil) {
            if (pPrev == NULL) {
                hapusAwal(head);
            } else {
                pPrev->next = pCur->next;
                free(pCur);
                printf("Data berhasil dihapus.\n");
            }
            getch();
            return;
        }
        pPrev = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Data tidak ditemukan.\n");
    getch();
}

//=============== MENGHAPUS DATA DI AKHIR LIST ========================

void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong.\n");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        pCur = *head;
        pPrev = NULL;

        while (pCur->next != *head) {
            pPrev = pCur;
            pCur = pCur->next;
        }

        pPrev->next = *head;
        free(pCur);
        printf("Data terakhir berhasil dihapus.\n");
    }
    getch();
}

//=============== MENCARI DATA ========================

void cariData(node **head) {
    int bil;
    node *pCur;
    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &bil);

    pCur = *head;
    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di dalam list.\n", bil);
            getch();
            return;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Data %d tidak ditemukan.\n", bil);
    getch();
}

//=============== MENJUMLAHKAN DATA ========================

void sumData(node **head) {
    int sum = 0;
    node *pCur = *head;

    if (*head == NULL) {
        printf("List kosong.\n");
    } else {
        do {
            sum += pCur->data;
            pCur = pCur->next;
        } while (pCur != *head);
    }

    printf("Jumlah total data di dalam list: %d\n", sum);
    getch();
}

//=============== MENAMPILKAN DATA ========================

void tranverse(node *head) {
    node *pWalker;

    system("cls");

    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }

    pWalker = head;
    do {
        printf("%d", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != head) {
            printf(" -> ");
        }
    } while (pWalker != head);
    printf("\n");
}

