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
        scanf("%c", &pilih);
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
        }
    } while (pilih != 'q');

    return 0;
}

//=============== MENAMBAHKAN DATA DI AWAL LIST ========================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;
        pNew->next = *head;
        *head = pNew;
    } else {
        printf("\nalokasi memori gagal");
        getch();
    }
}

//=============== MENAMBAHKAN DATA DI AKHIR LIST ========================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;
    system("cls");
    printf("masukkan bilangan: ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;
        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
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
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nmasukkan node sesuai data yang ada!");
        getch();
    } else if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = NULL;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//=============== MENGHAPUS DATA DI AWAL LIST ========================

void hapusAwal(node **head) {
    node *pTemp;
    if (*head == NULL) {
        printf("List kosong.\n");
    } else {
        pTemp = *head;
        *head = (*head)->next;
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

    while (pCur != NULL && pCur->data != bil) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan.\n");
    } else {
        if (pPrev == NULL) {
            *head = pCur->next;
        } else {
            pPrev->next = pCur->next;
        }
        free(pCur);
        printf("Data berhasil dihapus.\n");
    }
    getch();
}

//=============== MENGHAPUS DATA DI AKHIR LIST ========================

void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong.\n");
    } else {
        pCur = *head;
        pPrev = NULL;

        while (pCur->next != NULL) {
            pPrev = pCur;
            pCur = pCur->next;
        }

        if (pPrev == NULL) {
            *head = NULL;
        } else {
            pPrev->next = NULL;
        }

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
    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di dalam list.\n", bil);
            getch();
            return;
        }
        pCur = pCur->next;
    }
    printf("Data %d tidak ditemukan.\n", bil);
    getch();
}

//=============== MENJUMLAHKAN DATA ========================

void sumData(node **head) {
    int sum = 0;
    node *pCur = *head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Jumlah total data di dalam list: %d\n", sum);
    getch();
}

//=============== MENAMPILKAN DATA ========================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL) {
        printf("%d", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}

