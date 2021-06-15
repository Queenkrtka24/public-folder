#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include "LIST_CHILD.h"
#include "LIST_RELASI.h"
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
#define buku(P) (P)->buku
#define pinjam(P) (P)->pinjam

using namespace std;

struct buku{
    string nobuku;
    string judul;
};
typedef struct elm_buku *address_buku;
struct elm_buku{
    buku info;
    address_buku next;
    address_buku prev;
    list_relasi buku;
    list_peminjam pinjam;
};
struct list_buku{
    address_buku first;
    address_buku last;
};

void createList_buku(list_buku &L);
address_buku alokasi_buku(buku X);
void insertLast_buku(list_buku &L, address_buku P);
void deleteFirst_buku(list_buku &L, address_buku &P);
void deleteLast_buku(list_buku &L, address_buku &P);
void deleteAfter_buku(list_buku &L, address_buku Prec, address_buku &P);
address_buku find_buku(list_buku L, string X);
void delete_buku(list_buku &L, address_buku Prec, address_buku &P);
void print_buku(list_buku L);
void print_bukuSaja(list_buku L);
void Jumlah_peminjam(list_buku L, list_relasi R);
void jumlah_peminjam_sedikit(list_buku L, list_relasi R);

#endif // LIST_PARENT_H_INCLUDED
