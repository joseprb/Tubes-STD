#include "multilist.h"

bool isEmptyPenulis(listPenulis L) {
	return (first(L) == nil);
}
bool isEmptyNovel(listNovel L){
	return (first(L) == nil);
}
bool isEmptyRelasi(listRelasi L){
	return (first(L) == nil);
}

void createListPenulis(listPenulis &L) {
	first(L) = nil;
}
void createListNovel(listNovel &L) {
	first(L) = nil;
}
void createListRelasi(listRelasi &L) {
	first(L) = nil;
}

addressPenulis allocatePenulis(infotypePenulis x) {
	addressPenulis P = new elmPenulis;
	info(P).idPenulis = x.idPenulis;
	info(P).namaPenulis = x.namaPenulis;
	listRelasi rel;
	createListRelasi(rel);
	info(P).Relasi = rel;
	next(P) = nil; prev(P) = nil;
	return P;
}
addressNovel allocateNovel(infotypeNovel x) {
	addressNovel P = new elmNovel;
	info(P).idNovel = x.idNovel;
	info(P).judulNovel = x.judulNovel;
	info(P).cN = 0;
	next(P) = nil; prev(P) = nil;
	return P;
}
adrRelasi allocateRelasi(addressNovel X) {
	adrRelasi P = new elmRelasi;
	P->Novel = X;
	next(P) = nil; prev(P) = nil;
	return P;
}

void deallocationPenulis(addressPenulis &P) {
	delete P;
}
void deallocationNovel(addressNovel &P) {
	delete P;
}

void addPenulis(listPenulis &L, addressPenulis P) {
	if (isEmptyPenulis(L)) {
		first(L) = P;
	} else {
		addressPenulis Q = first(L);
		while (next(Q) != nil) {
            Q = next(Q);
		}
		next(Q) = P;
		prev(P) = Q;
	}
}
void addNovel(listNovel &L, addressNovel P) {
	if (isEmptyNovel(L)) {
		first(L) = P;
	} else {
		addressNovel Q = first(L);
		while (next(Q) != nil) {
            Q = next(Q);
		}
		next(Q) = P;
		prev(P) = Q;
	}
}
void addRelation(listRelasi &L, adrRelasi P) {
	if (isEmptyRelasi(L)) {
		first(L) = P;
	} else {
		adrRelasi Q = first(L);
		while (next(Q) != nil) {
            Q = next(Q);
		}
		next(Q) = P;
		prev(P) = Q;
	}
}

void deletePenulis(listPenulis &L, addressPenulis &P) {
    addressPenulis Q, R;
    adrRelasi Rel = first(info(P).Relasi);
    while (Rel != nil) {
        info(Rel->Novel).cN = info(Rel->Novel).cN - 1;
        Rel = next(Rel);
    }
    if (P == first(L)) {
        if (next(P) == nil) {
            first(L) = nil;
        } else {
            Q = next(P);
            prev(Q) = nil;
            first(L) = Q;
            next(P) = nil;
        }
    } else {
        if (next(P) == nil) {
            Q = prev(P);
            prev(P) = nil;
            next(Q) = nil;
        } else {
            Q = prev(P);
            R = next(P);
            prev(P) = nil;
            next(P) = nil;
            next(Q) = R;
            prev(R) = Q;
        }
    }
}
void deleteNovel(listNovel &L, addressNovel &P) {
    addressNovel Q, R;
    if (P == first(L)) {
        if (next(P) == nil) {
            first(L) = nil;
        } else {
            Q = next(P);
            prev(Q) = nil;
            first(L) = Q;
            next(P) = nil;
        }
    } else {
        if (next(P) == nil) {
            Q = prev(P);
            prev(P) = nil;
            next(Q) = nil;
        } else {
            Q = prev(P);
            R = next(P);
            prev(P) = nil;
            next(P) = nil;
            next(Q) = R;
            prev(R) = Q;
        }
    }
}
void deleteRelasi(listRelasi &L, adrRelasi &P) {
    adrRelasi Q, R;
    if (P == first(L)) {
        if (next(P) == nil) {
            first(L) = nil;
        } else {
            Q = next(P);
            prev(Q) = nil;
            first(L) = Q;
            next(P) = nil;
        }
    } else {
        if (next(P) == nil) {
            Q = prev(P);
            prev(P) = nil;
            next(Q) = nil;
        } else {
            Q = prev(P);
            R = next(P);
            prev(P) = nil;
            next(P) = nil;
            next(Q) = R;
            prev(R) = Q;
        }
    }
}

addressPenulis findPenulis(listPenulis L, int x) {
    addressPenulis Q = first(L);
    if (Q == nil) {
        return nil;
    } else {
        while ((next(Q) != nil) && (info(Q).idPenulis != x)) {
            Q = next(Q);
        }
        if (info(Q).idPenulis == x) {
            return Q;
        } else {
            return nil;
        }
    }
}
addressNovel findNovel(listNovel L, int x) {
    addressNovel Q = first(L);
    if (Q == nil) {
        return nil;
    } else {
        while ((next(Q) != nil) && (info(Q).idNovel != x)) {
            Q = next(Q);
        }
        if (info(Q).idNovel == x) {
            return Q;
        } else {
            return nil;
        }
    }
}

void printPenulis(listPenulis L) {
	if (!isEmptyPenulis(L)) {
        addressPenulis P = first(L);
        cout << " ID Penulis  |  Nama Penulis" << endl;
        while (P != nil) {
            cout << " " << info(P).idPenulis << "  |  " << info(P).namaPenulis << endl;
            P = next(P);
        }
	} else {
		cout << " Tidak ada penulis" << endl;
	}
}
void printNovel(listNovel L) {
	if (!isEmptyNovel(L)) {
        addressNovel P = first(L);
        cout << " ID Novel  |  Judul Novel" << endl;
        while (P != nil) {
            cout << " " << info(P).idNovel << "  |  " << info(P).judulNovel << endl;
            P = next(P);
        }
	} else {
		cout << " Tidak ada novel" << endl;
	}
}

void createRelation(listNovel LN, listPenulis LP, int idp, int idn) {
    addressNovel Pn = findNovel(LN, idn);
    addressPenulis Pp = findPenulis(LP, idp);
    if (Pn != nil && Pp != nil) {
        adrRelasi Pr = allocateRelasi(Pn);
        if(first(info(Pp).Relasi) == nil) {
            first(info(Pp).Relasi) = Pr;
        }
        else {
            adrRelasi Q = first(info(Pp).Relasi);
            while (next(Q) != nil) {
                Q = next(Q);
            }
            adrRelasi R = Pr;
            next(Q) = R;
            prev(R) = Q;
        }
        info(Pn).cN = info(Pn).cN + 1;
    } else {
        cout << " ID Penulis atau Novel tidak sesuai" << endl;
    }
}

void printNovelByPenulis(listPenulis LP, int idp) {
    addressPenulis Pp = findPenulis(LP, idp);
    adrRelasi P = first(info(Pp).Relasi);
    if (P != nil) {
        cout << " ID Novel  |  Judul Novel" << endl;
        while (P != nil) {
            cout << " " << info(P->Novel).idNovel << "  |  " << info(P->Novel).judulNovel << endl;
            P = next(P);
        }
    } else {
        cout << " Belum ada novel dengan penulis tsb" << endl;
    }
}

void printNovel2(listNovel LN) {
    addressNovel P = first(LN);
    int c = 0;
    while (P != nil) {
        if (info(P).cN == 2) {
            if (c == 0) cout << " ID Novel  |  Judul Novel" << endl;
            cout << " " << info(P).idNovel << "  |  " << info(P).judulNovel << endl;
            c++;
        }
        P = next(P);
    }
    if (c == 0) cout << " Tidak ada novel yang ditulis oleh 2 penulis" << endl;
}

void printPenulis2(listPenulis LP) {
    if (isEmptyPenulis(LP)) {
        cout << " Tidak ada penulis" << endl;
    } else {
        addressPenulis P = first(LP);
        addressPenulis M;
        int f = 0;
//        adrRelasi Q = first(info(P).Relasi);
//        while (Q != nil) {
//            f++;
//            Q = next(Q);
//        }
        while (P != nil) {
            adrRelasi Q = first(info(P).Relasi);
            int x = 0;
            while (Q != nil) {
                x++;
                Q = next(Q);
            }
            if (x > f) {
                M = P;
                f = x;
            }
            P = next(P);
        }
        if (f > 0) {
            cout << " Penulis yang paling banyak menulis novel adalah : " << info(M).namaPenulis << endl;
        } else {
            cout << " Belum ada penulis dengan novel terbanyak" << endl;
        }
    }
}

void printPenulisTanpaKolaborasi(listPenulis LP) {
    if (isEmptyPenulis(LP)) {
        cout << " Tidak ada penulis" << endl;
    } else {
        addressPenulis P = first(LP);
        int c = 0;
        while (P != nil) {
            bool flag = true;
            adrRelasi Q = first(info(P).Relasi);
            while (Q != nil) {
                if (info(Q->Novel).cN > 1) {
                    flag = false;
                }
                Q = next(Q);
            }
            if (flag) {
                c++;
                // cout << "ID Penulis  |  Nama Penulis" << endl;
                cout << " " << info(P).idPenulis << "  |  " << info(P).namaPenulis << endl;
            }
            P = next(P);
        }
        if (c == 0) {
            cout << " Semua penulis telah berkolaborasi" << endl;
        }
    }
}
