#include "LIST_CHILD.h"

void createList_peminjam(list_peminjam &L){
    first(L) = NULL;
    last(L) = NULL;
}
address_peminjam alokasi_peminjam(peminjam X){
    address_peminjam P = new elm_peminjam;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLast_peminjam(list_peminjam &L, address_peminjam P){
    if(first(L)== NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst_peminjam(list_peminjam &L, address_peminjam &P){
    P = first(L);
    if(first(L)==NULL){
        cout<<"list kosong"<<endl;
    }else if (first(L)==last(L)){
        first(L) = NULL;
        last(L)= NULL;
    }else{
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}
void deleteLast_peminjam(list_peminjam &L, address_peminjam &P){
    if(first(L)==NULL){
        cout<<"List kosong "<<endl;
    }else if(first(L)==last(L)){
        P = first(L);

        first(L) = NULL;
        last(L) = NULL;

        delete P;
    }else{
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfter_peminjam(list_peminjam &L,address_peminjam Prec, address_peminjam &P){

    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}
address_peminjam find_peminjam(list_peminjam L, string X){
    address_peminjam P = first(L);
    while(P!=NULL && info(P).idcard!=X ){
        P = next(P);
    }
    if(P!= NULL){
        return P;
    }else{
        return NULL;
    }
}
void print_peminjam(list_peminjam L){
    address_peminjam P = first(L);
    if(first(L)!= NULL){
        while(P!=NULL){
            cout<< "Nama Peminjam   : "<<info(P).namaMhs<<endl;
            cout<< "Id Card : "<<info(P).idcard<<endl;
            cout<<""<<endl;
            P = next(P);
        }
    }
}
void delete_peminjam(list_peminjam &L,address_peminjam Prec, address_peminjam &P){
    if(first(L)!=NULL){
        if(Prec!= NULL){
            if(Prec==first(L)){
                deleteFirst_peminjam(L, P);
            }else if(Prec == last(L)){
                deleteLast_peminjam(L, P);
            }else{
                P = Prec;
                address_peminjam Q = prev(P);
                next(Q) = next(P);
                prev(next(P))= Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}
