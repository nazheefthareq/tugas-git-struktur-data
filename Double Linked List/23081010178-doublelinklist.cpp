#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *pRight;
    struct node *pLeft;
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
        pNew->pRight = *head;
        pNew->pLeft = NULL;

        if (*head != NULL) {
            (*head)->pLeft = pNew;
        }
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
        pNew->pRight = NULL;
        pNew->pLeft = NULL;
        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->pRight != NULL) {
                pCur = pCur->pRight;
            }
            pCur->pRight = pNew;
            pNew->pLeft = pCur;
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
        pCur = pCur->pRight;
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
        pNew->pRight = pCur->pRight;
        pNew->pLeft = pCur;

        if (pCur->pRight != NULL) {
            pCur->pRight->pLeft = pNew;
        }
        pCur->pRight = pNew;
    }
}

//=============== MENGHAPUS DATA DI AWAL LIST ========================

void hapusAwal(node **head) {
    node *pTemp;
    if (*head == NULL) {
        printf("List kosong.\n");
    } else {
        pTemp = *head;
        *head = (*head)->pRight;
        if (*head != NULL) {
            (*head)->pLeft = NULL;
        }
        free(pTemp);
        printf("Data pertama berhasil dihapus.\n");
    }
    getch();
}


//=============== MENGHAPUS DATA DI TENGAH LIST ========================

void hapusTengah(node **head) {
    int bil;
    node *pCur;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan data yang ingin dihapus: ");
    scanf("%d", &bil);

    pCur = *head;

    while (pCur != NULL && pCur->data != bil) {
        pCur = pCur->pRight;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan.\n");
    } else {
        if (pCur->pLeft != NULL) {
            pCur->pLeft->pRight = pCur->pRight;
        } else {
            *head = pCur->pRight;
        }

        if (pCur->pRight != NULL) {
            pCur->pRight->pLeft = pCur->pLeft;
        }

        free(pCur);
        printf("Data berhasil dihapus.\n");
    }
    getch();
}

//=============== MENGHAPUS DATA DI AKHIR LIST ========================

void hapusAkhir(node **head) {
    node *pCur;

    if (*head == NULL) {
        printf("List kosong.\n");
    } else {
        pCur = *head;

        while (pCur->pRight != NULL) {
            pCur = pCur->pRight;
        }

        if (pCur->pLeft != NULL) {
            pCur->pLeft->pRight = NULL;
        } else {
            *head = NULL;
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
        pCur = pCur->pRight;
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
        pCur = pCur->pRight;
    }

    printf("Jumlah total data di dalam list: %d\n", sum);
    getch();
}

//=============== MENAMPILKAN DATA ========================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;
    if (pWalker == NULL) {
        printf("List kosong.\n");
        return;
    }
    printf("NULL <-> %d", pWalker->data);

    pWalker = pWalker->pRight;

    while (pWalker != NULL) {
        printf(" <-> %d", pWalker->data);
        pWalker = pWalker->pRight;
    }
    printf(" <-> NULL\n");
}
