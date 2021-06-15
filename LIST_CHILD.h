#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;
#define next(P) (P)->next
#define info(P) (P)->info
#define first(L) ((L).first)
#define prev(P) (P)->prev
#define last(L) ((L).last)

struct peminjam{
    string namaMhs;
    string idcard;
};
typedef struct elm_peminjam *address_peminjam;
struct elm_peminjam{
    peminjam info;
    address_peminjam next;
    address_peminjam prev;
};

struct list_peminjam{
    address_peminjam first;
    address_peminjam last;
};

void createList_peminjam(list_peminjam &L);
address_peminjam alokasi_peminjam(peminjam X);
void insertLast_peminjam(list_peminjam &L, address_peminjam P);
void deleteFirst_peminjam(list_peminjam &L, address_peminjam &P);
void deleteLast_peminjam(list_peminjam &L, address_peminjam &P);
void deleteAfter_peminjam(list_peminjam &L,address_peminjam Prec, address_peminjam &P);
address_peminjam find_peminjam(list_peminjam L, string X);
void print_peminjam(list_peminjam L);
void delete_peminjam(list_peminjam &L , address_peminjam Prec, address_peminjam &P);
void view_peminjam(list_peminjam L);

#endif // LIST_CHILD_H_INCLUDED
