#include "LIST_MENU.h"

void menu(int &pilihan){
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"       +===================================================================+"<<endl;
    cout<<"       |     *******  PILIH MENU YANG INGIN ANDA TAMPILKAN *******         |"<<endl;
    cout<<"       |                          PERPUSTAKAAN                             |"<<endl;
    cout<<"       +===================================================================+"<<endl;
    cout<<""<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  1  |      PENAMBAHAN BUKU                                        |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  2  |      PENAMBAHAN PEMINJAM                                    |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  3  |      PENENTUAN RELASI BUKU DAN PEMINJAMAN                   |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  4  |      MENGHAPUS DATA BUKU TERTENTU                           |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  5  |      MENGHAPUS DATA PEMINJAM TERTENTU                       |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  6  |      MENAMPILKAN DATA KESELURUHAN PEMINJAM                  |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  7  |      MENAMPILKAN DATA BUKU YANG DIPINJAM                    |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  8  |      MENAMPILKAN DATA PEMINJAM YANG MEMINJAM BUKU TERTENTU  |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  9  |      MENAMPILKAN DATA BUKU YANG PALING FAVORIT DAN TIDAK    |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"       |  10 |      KELUAR                                                 |"<<endl;
    cout<<"       +=====+=============================================================+"<<endl;
    cout<<"\n PILIH MENU : ";
    cin>>pilihan;
}
void Tambahbuku(list_buku &L, address_buku P){
    buku X;

    cout<<"Masukan Judul Buku : ";
    cin>>X.judul;
    cout<<"Masukan Nomor Buku : ";
    cin>>X.nobuku;
    P = find_buku(L, X.nobuku);
    if(P==NULL){
        insertLast_buku(L, alokasi_buku(X));
    }else{
        cout<<"Judul Buku telah Terdaftar"<<endl;
    }
    cout<<""<<endl;
    print_bukuSaja(L);

}

void Tambahpeminjam(list_peminjam &L, address_peminjam P){
    peminjam X;

    cout<<"Masukan Nama Peminjam : ";
    cin>>X.namaMhs;
    cout<<"Masukan Id Card : ";
    cin>>X.idcard;
    P = find_peminjam(L, X.idcard);
    if(P==NULL){
        insertLast_peminjam(L, alokasi_peminjam(X));
    }else{
        cout<<"Mahasiswa dengan Nama tersebut sudah meminjam "<<endl;
    }
    cout<<""<<endl;
    print_peminjam(L);

}

void relasibuku_peminjam(list_buku Lb, list_peminjam Lp){
    buku X;
    peminjam Y;
    address_buku Pb;
    address_peminjam Pp;
    address_relasi PR;

    cout<<"Masukan Judul Buku : ";
    cin>>X.judul;
    cout<<"Masukan Nomor Buku : ";
    cin>>X.nobuku;
    cout<<""<<endl;

    cout<<"Masukan Nama Peminjam : ";
    cin>>Y.namaMhs;
    cout<<"Masukan Id Card Peminjam : ";
    cin>>Y.idcard;
    cout<<""<<endl;

    Pb = find_buku(Lb, X.nobuku);
    Pp = find_peminjam(Lp, Y.idcard);
    if(Pb != NULL && Pp !=NULL){
        PR = alokasi_r(Pp);
        insertLast_r(buku(Pb), PR);
    }else{
        cout<<"Judul/Nama Peminjam tersebut tidak terdaftar "<<endl;
    }
    cout<<""<<endl;
    print_buku(Lb);
}

void hapusbuku(list_buku &L, address_buku P, address_buku hapus){
    buku X;

    cout<<"Masukan Judul Buku yang akan dihapus : "<<endl;
    cin>>X.judul;
    cout<<"Masukan Nomor Buku yang akan dihapus : "<<endl;
    cin>>X.nobuku;

    hapus = find_buku(L, X.nobuku);
    if(P!=NULL){
        cout<<"Judul Buku sudah terhapus "<<endl;
        delete_buku(L, hapus, P);
        print_bukuSaja(L);
    }else{
        cout<<"Judul Buku tersebut tidak terdaftar "<<endl;
    }
}

void hapus_peminjam(list_peminjam &L, address_peminjam Prec, address_peminjam &P){
    peminjam X;

    cout<<"Masukan Nama Peminjam yang akan dihapus : ";
    cin>>X.namaMhs;
    cout<<"Masukan Id Card Peminjam : ";
    cin>>X.idcard;

    P = find_peminjam(L, X.idcard);
    if(P!=NULL){
        cout<<"Peminjam sudah dihapus "<<endl;
        delete_peminjam(L, P, Prec);
        print_peminjam(L);
    }else{
        cout<<"Peminjam tersebut tidak ditemukan "<<endl;
    }
}

void view_datapeminjam(list_buku &L, address_buku P){
    buku X;

    cout<<"Masukan Nomor Buku : ";
    cin>>X.nobuku;

    P = find_buku(L, X.nobuku);
    if(P!=NULL){
        print_r(buku(P));
    }
}

void view_buku(list_peminjam &L, address_peminjam P){
    peminjam X;
    list_buku Lb;

    cout<<"Masukan Nama Peminjam : ";
    cin>>X.namaMhs;
    cout<<"Masukan ID Card Peminjam : ";
    cin>>X.idcard;

    P = find_peminjam(L, X.idcard);
    if(P!=NULL){

    }
}

void edit_peminjam(list_peminjam &L, address_peminjam P){
    peminjam pmj, newPmj;

    cout<<"Masukan Nama Peminjam yang akan di edit : ";
    cin>>pmj.namaMhs;
    cout<<"Masukan Id Card Peminjam : ";
    cin>>pmj.idcard;
    cout<<""<<endl;

    P = find_peminjam(L, pmj.idcard);
    if(P!=NULL){
        cout<<"Masukan Nama Peminjam Baru : ";
        cin>>newPmj.namaMhs;
        cout<<"Masukan Id Card Peminjam : ";
        cin>>newPmj.idcard;
        info(P) = newPmj;
    }else{
        cout<<"Peminjam tersebut tidak ditemukan "<<endl;
    }

}
void edit_buku(list_buku &L, address_buku P){
    buku book, newbook;

    cout<<"Masukan Judul Buku yang akan di edit : ";
    cin>>book.judul;
    cout<<"Masukan Nomor Buku : ";
    cin>>book.nobuku;
    cout<<""<<endl;

    P = find_buku(L, book.nobuku);
    if(P!=NULL){
        cout<<"Masukan Judul Buku Baru : ";
        cin>>newbook.judul;
        cout<<"Masukan Nomor Buku : ";
        cin>>newbook.nobuku;
        info(P) = newbook;
    }
}



