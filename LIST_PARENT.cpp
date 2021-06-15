#include "LIST_PARENT.h"

void createList_buku(list_buku &L){
    first(L) = NULL;
    last(L) = NULL;
}
address_buku alokasi_buku(buku X){
    address_buku P = new elm_buku;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    createList_r(buku(P));
    return P;
}
void insertLast_buku(list_buku &L, address_buku P){
    if(first(L)== NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}
void deleteFirst_buku(list_buku &L, address_buku &P){
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
void deleteLast_buku(list_buku &L, address_buku &P){
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
void deleteAfter_buku(list_buku &L, address_buku Prec, address_buku &P){
    if(first(L)!=NULL){
        if(Prec!=NULL){
            if(next(Prec)==last(L)){
                deleteLast_buku(L, P);
            }else if (Prec==first(L)){
                deleteFirst_buku(L, P);
            }else{
                P = next(Prec);
                next(Prec) = next(P);
                prev(next(P)) = Prec;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}
address_buku find_buku(list_buku L, string X){
    address_buku P = first(L);
    while(P!= NULL &&  info(P).nobuku!= X){
        P = next(P);
    }
    if(P==NULL){
        return NULL;
    }else{
        return P;
    }
}
void delete_buku(list_buku &L, address_buku Prec, address_buku &P){
    if(first(L)!=NULL){
        if(Prec!= NULL){
            if(Prec==first(L)){
                deleteFirst_buku(L, P);
            }else if(Prec == last(L)){
                deleteLast_buku(L, P);
            }else{
                P = Prec;
                address_buku Q = prev(P);
                next(Q) = next(P);
                prev(next(P))= Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}
void print_buku(list_buku L){
    address_buku P = first(L);
    if(first(L)!=NULL){
        while(P!=NULL){
            cout<<"Judul Buku   : "<<info(P).judul<<endl;
            cout<<"Nomor Buku   : "<<info(P).nobuku<<endl;
            print_r(buku(P));
            P = next(P);
        }
    }else{
        cout<<"Tidak ditemukan judul tersebut"<<endl;
    }
}
void print_bukuSaja(list_buku L){
    address_buku P = first(L);
    if(first(L)!= NULL){
        while(P!=NULL){
            cout<<"Judul Buku   : "<<info(P).judul<<endl;
            cout<<"Nomor Buku   : "<<info(P).nobuku<<endl;
            cout<<""<<endl;
            P = next(P);
        }
    }
}
void Jumlah_peminjam(list_buku L, list_relasi R){
    int n;
    int A[20];
    address_buku P;
    if(first(L)==NULL){
        cout<<"Kosong "<<endl;
    }else{
        P = first(L);
        n = 0;
        int i;
        i = 0;
        while(P!=NULL){
            address_relasi Q = first(buku(P));
            while(Q!=NULL){
                n = n+1;
                Q = next(Q);
            }
            A[i] = n;
            i++;
            n=0;
            P = next(P);
        }
        int j;
        j=0;
        int counter = 0;
        n = A[j];
        while(j<i){
            if(A[j]>=n){
                n=A[j];;
                counter = j;
            }
            j++;
        }
        P = first(L);
        for(j=0 ; j< counter;j++){
            P = next(P);
            j++;
        }
        cout<<"buku favorit"<<info(P).judul<<endl;
    }
}
void jumlah_peminjam_sedikit(list_buku L, list_relasi R){
    int n;
    int A[20];
    address_buku P;
    if(first(L)==NULL){
        cout<<"Kosong "<<endl;
    }else{
        P = first(L);
        n=0;
        int i;
        i = 0;

        while(P!=NULL){
            address_relasi Q = first(buku(P));
            while(Q!=NULL){
                n = n+1;
                Q = next(Q);
            }
            A[i] = n;
            i++;
            n=0;
            P = next(P);
        }
        int j;
        j=0;
        int counter = 0;
        n = A[j];
        while(j<i){
            if(A[j]<=n){
                n=A[j];;
                counter = j;
            }
            j++;
        }
        P = first(L);
        for(j=0 ; j< counter;j++){
            P = next(P);
            j++;
        }
        cout<<"peminjaman sedikit "<<info(P).judul <<endl;
    }
}
