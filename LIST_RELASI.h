#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
using namespace std;
#include "LIST_CHILD.h"

#define next(P) (P)->next
#define info(P) (P)->info
#define first(L) ((L).first)

typedef struct elm_relasi *address_relasi;

struct elm_relasi{
    address_relasi next;
    address_peminjam info;
};

struct list_relasi{
    address_relasi first;
};

void createList_r(list_relasi &L);
address_relasi alokasi_r(address_peminjam X);
void insertFirst_r(list_relasi &L, address_relasi P);
void insertLast_r(list_relasi &L, address_relasi P);
void insertAfter_r(list_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst_r(list_relasi &L, address_relasi &P);
void deleteLast_r(list_relasi &L, address_relasi &P);
void deleteAfter_r(list_relasi &L, address_relasi Prec, address_relasi &P);
address_relasi find_r(list_relasi L, address_peminjam X);
void print_r(list_relasi L);
void print_relasi_peminjaman(list_relasi L);

#endif // LIST_RELASI_H_INCLUDED
