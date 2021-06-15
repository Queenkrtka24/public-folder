#ifndef LIST_MENU_H_INCLUDED
#define LIST_MENU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "LIST_PARENT.h"
#include "LIST_CHILD.h"
#include "LIST_RELASI.h"

using namespace std;

void menu(int &pilihan);
void Tambahbuku(list_buku &L, address_buku P);
void Tambahpeminjam(list_peminjam &L, address_peminjam P);
void relasibuku_peminjam(list_buku Lb, list_peminjam Lp);
void hapusbuku(list_buku &L, address_buku P, address_buku hapus);
void hapus_peminjam(list_peminjam &L, address_peminjam Prec, address_peminjam &P);
void view_datapeminjam(list_buku &L, address_buku P);
void view_buku(list_peminjam &L, address_peminjam P);
void edit_peminjam(list_peminjam &L, address_peminjam P);
void edit_buku(list_buku &L, address_buku P);

#endif // LIST_MENU_H_INCLUDED
