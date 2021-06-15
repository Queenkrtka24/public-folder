#include "LIST_RELASI.h"

void createList_r(list_relasi &L){
    first(L) = NULL;
}
address_relasi alokasi_r(address_peminjam X){
    address_relasi P = new elm_relasi;
    info(P) = X;
    next(P) = NULL;
    return P;
}
void insertFirst_r(list_relasi &L, address_relasi P){
    if(first(L)==NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertLast_r(list_relasi &L, address_relasi P){
    address_relasi Q = first(L);
    if(first(L)==NULL){
        insertFirst_r(L, P);
    }else{
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void insertAfter_r(list_relasi &L, address_relasi Prec, address_relasi P){
    if(Prec != NULL){
        if(first(L)==NULL){
            insertFirst_r(L, P);
        }else if (next(Prec)==NULL){
            insertLast_r(L, P);
        }else{
            next(P) = next(Prec);
            next(Prec) = P;
        }

    }
}
void deleteFirst_r(list_relasi &L, address_relasi &P){
    if(first(L)!= NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;

        delete P;
    }else{
        cout<<"list kosong "<<endl;
    }
}
void deleteLast_r(list_relasi &L, address_relasi &P){
    address_relasi Q = first(L);
    if(first(L)==NULL){
        cout<<"list kosong "<<endl;
    }else{
        if(next(first(L))==NULL){
            P = first(L);
            first(L) = NULL;
        }else{
            while(next(next(Q))!= NULL){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }
}
void deleteAfter_r(list_relasi &L, address_relasi Prec, address_relasi &P){
    if(first(L)==NULL){
        cout<<"list kosong "<<endl;
    }else{
        if(Prec != NULL){
            if(next(first(L))==NULL){
                P = first(L);
                first(L) = NULL;
            }else{
                P = next(Prec);
                next(Prec) = next(P);
                next(P) = NULL;
            }
        }
    }
}

address_relasi find_r(list_relasi L, address_peminjam X){
    address_relasi P = first(L);
    while(P!=NULL && info(P) != X ){
        P = next(P);
    }
    if(P!=NULL){
        return P;
    }

}

void print_r(list_relasi L){
    address_relasi P = first(L);
    if(first(L)!=NULL){
        while(P!=NULL){
            cout<<" Peminjam Buku"<<endl;
                    cout<<" --> "<<"Nama Mahasiswa    : "<<info(info(P)).namaMhs<<endl;
                    cout<<"   "<<"Id Card             : "<<info(info(P)).idcard<<endl;
                    cout<<""<<endl;
            P = next(P);

        }
    }
}
