#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <stdio.h>
#include "LIST_CHILD.h"
#include "LIST_PARENT.h"
#include "LIST_RELASI.h"
#include "LIST_MENU.h"
using namespace std;

int main()
{
    list_buku Lb;
    list_peminjam Lp;
    list_relasi LR;
    int pilihan;
    address_buku Pb;
    address_buku hapus;
    address_peminjam Pp;
    address_peminjam del;

    createList_buku(Lb);
    createList_peminjam(Lp);

    menu(pilihan);
    system("PAUSE");
    system("CLS");
    while(pilihan!=9){
        switch(pilihan){
        case 1:
            Tambahbuku(Lb, Pb);
            break;
        case 2:
            Tambahpeminjam(Lp, Pp);
            break;
        case 3:
            relasibuku_peminjam(Lb,Lp);
            break;
        case 4:
            hapusbuku(Lb, hapus, Pb);
            break;
        case 5:
            hapus_peminjam(Lp, del, Pp);
            break;
        case 6:
            view_datapeminjam(Lb, Pb);
            break;
        case 7:
            print_buku(Lb);
            break;
        case 9:
//            jumlah_peminjam_sedikit(Lp, LR);
            Jumlah_peminjam(Lb, LR);
            break;
        }
        system("PAUSE");
        system("CLS");
        menu(pilihan);
    }

    return 0;
}
