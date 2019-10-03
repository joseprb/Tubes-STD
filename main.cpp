#include "multilist.h"

int tPenulis = 0;
int tNovel = 0;

void mainmenu(listPenulis &LP, listNovel &LN) {
    int m;
    do {
        cout << endl;
        cout << "         MENU" << endl;
        cout << " ____________________" << endl << endl;
        cout << " 1. Tambah Penulis" << endl;
        cout << " 2. Tambah Novel" << endl;
        cout << " 3. Hapus Penulis" << endl;
        cout << " 4. Hapus Novel" << endl;
        cout << " 5. Tampil Penulis" << endl;
        cout << " 6. Tampil Novel" << endl;
        cout << " 7. Tambah Relasi" << endl;
        cout << " 8. Tampil Novel berdasarkan Penulis tertentu" << endl;
        cout << " 9. Tampil Novel yang ditulis oleh 2 Penulis" << endl;
        cout << " 10. Tampil Penulis yang paling banyak menulis novel" << endl;
        cout << " 11. Tampil penulis yang tidak pernah menampilkan kolaborasi" << endl;
        cout << " 0. Keluar" << endl << endl;
        cout << " Pilih menu : ";
        cin >> m;
        cout << endl;
        switch(m){
        case 1 : {
            addressPenulis P;
            infotypePenulis x;
            string ip, np;
            cout << " Masukkan Nama Penulis : ";
            cin >> np;
            //cout << setfill('0') << setw(3) << calculatePenulis(LP);
            x.namaPenulis = np;
            x.idPenulis = tPenulis + 1;
            P = allocatePenulis(x);
            addPenulis(LP, P);
            tPenulis++;
            break;
        }
        case 2 :{
            addressNovel P;
            infotypeNovel x;
            string in, jn;
            cout << " Masukkan Judul Novel : ";
            cin >> jn;
            x.judulNovel = jn;
            x.idNovel = tNovel + 1;
            P = allocateNovel(x);
            addNovel(LN, P);
            tNovel++;
            break;
        }
        case 3 :{
            printPenulis(LP);
            int x;
            if (!isEmptyPenulis(LP)) {
                cout << " Masukkan ID Penulis yang ingin dihapus : ";
                cin >> x;
                addressPenulis P;
                P = findPenulis(LP, x);
                if (P != nil) {
                    deletePenulis(LP, P);
                    cout << " Penulis berhasil dihapus" << endl;
                } else {
                    cout << " Penulis tidak ditemukan" << endl;
                }
            }
            break;
        }
        case 4 :{
            printNovel(LN);
            int x;
            if (!isEmptyNovel(LN)) {
                cout << " Masukkan ID Novel yang ingin dihapus : ";
                cin >> x;
                addressNovel P;
                P = findNovel(LN, x);
                if (P != nil) {
                    deleteNovel(LN, P);
                    cout << " Novel berhasil dihapus" << endl;
                } else {
                    cout << " Novel tidak ditemukan" << endl;
                }
            }
            break;
        }
        case 5 :
            printPenulis(LP);
            break;
        case 6 :
            printNovel(LN);
            break;
        case 7 :
            if (isEmptyPenulis(LP) || isEmptyNovel(LN)) {
                cout << " Penulis atau novel masih kosong" << endl;
            } else {
                int idp, idn;
                cout << " Pilih penulis : " << endl;
                printPenulis(LP);
                cout << " Masukkan ID Penulis : ";
                cin >> idp;
                cout << " Pilih novel: " << endl;
                printNovel(LN);
                cout << " Masukkan ID Novel : ";
                cin >> idn;
                createRelation(LN, LP, idp, idn);
            }
            break;
        case 8 :
            if (isEmptyPenulis(LP) || isEmptyNovel(LN)) {
                cout << " Penulis atau novel masih kosong" << endl;
            } else {
                int idp, idn;
                cout << " Pilih penulis : " << endl;
                printPenulis(LP);
                cout << " Masukkan ID Penulis : ";
                cin >> idp;
                printNovelByPenulis(LP, idp);

            }
            break;
        case 9 : {
            printNovel2(LN);
            break;
        }
        case 10 : {
            printPenulis2(LP);
            break;
        }
        case 11 : {
            printPenulisTanpaKolaborasi(LP);
            break;
        }
        case 0 : break;
        default : break;
        }
    } while(m != 0);
}

int main()
{

	listPenulis LP;
	listNovel LN;

    createListPenulis(LP);
    createListNovel(LN);

	mainmenu(LP, LN);

    return 0;
}
