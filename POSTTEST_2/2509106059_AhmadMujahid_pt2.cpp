#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

// g++ -o p 2509106059_AhmadMujahid_pt2.cpp

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

int n = 0;

void tukar(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambah(Hewan*& data) {
    if (n >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\n ____________________\n";
    cout << "|     INPUT DATA     |\n";
    cout << "|____________________|\n";

    (data + n)->id = n + 1;
    cout << "|ID     : " << (data + n)->id << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "|Nama   : ";
    getline(cin, (data + n)->nama);

    cout << "|Jenis  : ";
    getline(cin, (data + n)->jenis);

    cout << "|Harga  : ";
    cin >> (data + n)->harga;

    cout << "|____________________|\n";

    n++;
}

void tampil(Hewan* data) {

    cout << "\n__________________________________________________________________________\n";
    cout << "|                                                                        |\n";
    cout << "|                           DATA HEWAN PAWCARE                           |\n";
    cout << "|________________________________________________________________________|\n";

    cout << left
         << setw(5)  << "|ID"
         << setw(20) << "|Nama"
         << setw(20) << "|Jenis"
         << setw(28) << "|Harga"
         << "|"
         << endl;

    cout << "|----|-------------------|-------------------|---------------------------|\n";
    
    for (int i = 0; i < n; i++) {
        cout << "|"
             << setw(3)  << (data + i)->id << " "
             << "|" << setw(19) << (data + i)->nama
             << "|" << setw(19) << (data + i)->jenis
             << "|Rp. " << setw(24) << (data + i)->harga
             << "|\n";
    }

    cout << "|____|___________________|___________________|___________________________|\n";
}

void urutID(Hewan* data) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((data + j)->id > (data + j + 1)->id) {
                tukar(data + j, data + j + 1);
            }
        }
    }
}

void cariNama(Hewan* data) {
    string cari;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nMasukkan nama: ";
    getline(cin, cari);

    bool ketemu = false;

    cout << "\n ________________________________________\n";
    cout << "|    PROSES PENCARIAN (Linear Search)   |\n";
    cout << "|_______________________________________|\n";

    for (int i = 0; i < n; i++) {
        cout << "Iterasi " << i+1
             << " | Bandingkan dengan: "
             << (data + i)->nama << endl;

        if ((data + i)->nama == cari) {
            cout << ">> DITEMUKAN di index " << i << endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << ">> Tidak ditemukan\n";
    }
}

void cariID(Hewan* data) {

    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n(Data diurutkan berdasarkan ID...)\n";
    urutID(data);

    int x;
    cout << "Masukkan ID: ";
    cin >> x;

    int f2 = 0;
    int f1 = 1;
    int f = f2 + f1;

    while (f < n) {
        f2 = f1;
        f1 = f;
        f = f2 + f1;
    }

    int offset = -1;

    cout << "\n ___________________________________________\n";
    cout << "|   PROSES PNCARIAN ( Fibonacci Search )   |\n";
    cout << "|__________________________________________|\n";

    while (f > 1) {
        int i = min(offset + f2, n - 1);

        cout << "Cek index " << i
             << " | ID = " << (data + i)->id << endl;

        if ((data + i)->id < x) {
            cout << "-> Geser kanan\n";
            f = f1;
            f1 = f2;
            f2 = f - f1;
            offset = i;
        }
        else if ((data + i)->id > x) {
            cout << "<- Geser kiri\n";
            f = f2;
            f1 = f1 - f2;
            f2 = f - f1;
        }
        else {
            cout << ">> DITEMUKAN di index " << i << endl;
            return;
        }
    }

    if (f1 && (data + offset + 1)->id == x) {
        cout << ">> DITEMUKAN di index " << offset + 1 << endl;
        return;
    }

    cout << ">> Tidak ditemukan\n";
}

void urutNama(Hewan* data) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((data + j)->nama > (data + j + 1)->nama) {
                tukar(data + j, data + j + 1);
            }
        }
    }
    cout << ">> Berhasil urut nama\n";
}

void urutHarga(Hewan* data) {
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;

        for (int j = i + 1; j < n; j++) {
            if ((data + j)->harga < (data + idxMin)->harga) {
                idxMin = j;
            }
        }

        tukar(data + i, data + idxMin);
    }
    cout << ">> Berhasil urut harga\n";
}

int main() {
    Hewan arr[100];
    Hewan* p = arr;

    int pilih;

    do {
        cout << "\n __________________________________ \n";
        cout << "|        PAWCARE PETSHOP           |\n";
        cout << "|----------------------------------|\n";
        cout << "| 1. Tambah Data Hewan             |\n";
        cout << "| 2. Tampilkan Data Hewan          |\n";
        cout << "| 3. Cari Hewan berdasarkan Nama   |\n";
        cout << "| 4. Cari Hewan berdasarkan ID     |\n";
        cout << "| 5. Urutkan berdasarkan Nama      |\n";
        cout << "| 6. Urutkan berdasarkan Harga     |\n";
        cout << "| 0. Keluar                        |\n";
        cout << "|__________________________________|\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambah(p); break;
            case 2: tampil(p); break;
            case 3: cariNama(p); break;
            case 4: cariID(p); break;
            case 5: urutNama(p); break;
            case 6: urutHarga(p); break;
        }

    } while (pilih != 0);

    return 0;
}