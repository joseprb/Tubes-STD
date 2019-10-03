#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>

#define nil NULL
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

using namespace std;

typedef struct elmRelasi *adrRelasi;
struct listRelasi {
    adrRelasi first;
};

typedef struct infotypePenulis {
    int idPenulis;
    listRelasi Relasi;
    string namaPenulis;
};
typedef struct infotypeNovel {
    int idNovel, cN;
    string judulNovel;
};

typedef struct elmPenulis *addressPenulis;
typedef struct elmNovel *addressNovel;

struct elmPenulis {
    infotypePenulis info;
    addressPenulis prev, next;
};
struct elmNovel {
    infotypeNovel info;
    addressNovel prev, next;
};
struct elmRelasi {
    addressNovel Novel;
    adrRelasi next, prev;
};
struct listPenulis {
    addressPenulis first;
};
struct listNovel {
    addressNovel first;
};

bool isEmptyPenulis(listPenulis L);
bool isEmptyNovel(listNovel L);

void createListPenulis(listPenulis &L);
void createListNovel(listNovel &L);
void createListRelasi(listRelasi &L);

addressPenulis allocatePenulis(infotypePenulis x);
addressNovel allocateNovel(infotypeNovel x);

void deallocationPenulis(addressPenulis &P);
void deallocationNovel(addressNovel &P);

void addPenulis(listPenulis &L, addressPenulis P);
void addNovel(listNovel &L, addressNovel P);

void deletePenulis(listPenulis &L, addressPenulis &P);
void deleteNovel(listNovel &L, addressNovel &P);

addressPenulis findPenulis(listPenulis L, int x);
addressNovel findNovel(listNovel L, int x);

void printPenulis(listPenulis L);
void printNovel(listNovel L);
void printNovelByPenulis(listPenulis LP, int idp);
void printNovel2(listNovel LN);
void printPenulis2(listPenulis LP);
void printPenulisTanpaKolaborasi(listPenulis LP);

void createRelation(listNovel LN, listPenulis LP, int idp, int idn);

#endif // MULTILIST_H_INCLUDED
