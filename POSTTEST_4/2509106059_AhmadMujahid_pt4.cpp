#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

struct Node {
    Hewan data;
    Node* next;
};

int n = 0;

// DATA 
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

    if (n == 0) {
    cout << "Data kosong!\n";
    return;
    }
        
    cout << "\n__________________________________________________________________________\n";
    cout << "|                           DATA HEWAN PAWCARE                           |\n";
    cout << "|________________________________________________________________________|\n";

    cout << left
         << setw(5)  << "|ID"
         << setw(20) << "|Nama"
         << setw(20) << "|Jenis"
         << setw(28) << "|Harga"
         << "|" << endl;

    cout << "|----|-------------------|-------------------|---------------------------|\n";

    for (int i = 0; i < n; i++) {
        cout << "|"
             << setw(3)  << (data + i)->id << " "
             << "|" << setw(19) << (data + i)->nama
             << "|" << setw(19) << (data + i)->jenis
             << "|Rp. " << setw(24) << (data + i)->harga
             << "|\n";

         cout << "|____|___________________|___________________|___________________________|\n";
    }
}

// QUEUE 
Node* depan = NULL;
Node* belakang = NULL;

void masukAntri(Hewan h) {
    Node* baru = new Node{h, NULL};

    if (depan == NULL)
        depan = belakang = baru;
    else {
        belakang->next = baru;
        belakang = baru;
    }

    cout << ">> " << h.nama << " masuk antrian\n";
}

Hewan panggil() {
    Hewan kosong{ -1 };

    if (depan == NULL) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Node* temp = depan;
    Hewan h = temp->data;

    depan = depan->next;
    if (depan == NULL) belakang = NULL;

    delete temp;

    cout << ">> Memanggil: " << h.nama << " (ID: " << h.id << ")\n";
    return h;
}

void tampilAntri() {
    if (depan == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n ______________________\n";
    cout << "|      ANTRIAN        |\n";
    cout << "|_____________________|\n";

    Node* temp = depan;
    while (temp) {
        cout << "|ID: " << temp->data.id << " | " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// STACK
Node* top = NULL;

void tambahRiwayat(Hewan h) {
    Node* baru = new Node{h, top};
    top = baru;

    cout << ">> Masuk riwayat: " << h.nama << endl;
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n ______________________\n";
    cout << "|       RIWAYAT       |\n";
    cout << "|_____________________|\n";

    Node* temp = top;
    while (temp) {
        cout << "|ID: " << temp->data.id << " | " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// PEEK 
void lihatDepan() {
    if (depan)
        cout << "Depan antrian: " << depan->data.nama << endl;
    else
        cout << "Antrian kosong\n";
}

void lihatAkhir() {
    if (top)
        cout << "Terakhir di riwayat: " << top->data.nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// POP
Hewan pop() {
    Hewan kosong{-1};

    if (top == NULL) {
        cout << "Riwayat kosong!\n";
        return kosong;
    }

    Node* temp = top;
    Hewan h = temp->data;

    top = top->next;
    delete temp;

    cout << ">> Menghapus riwayat: " << h.nama << endl;
    return h;
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
        cout << "| 7. Masuk Antrian                 |\n";
        cout << "| 8. Panggil Pasien                |\n";
        cout << "| 9. Lihat Antrian                 |\n";
        cout << "|10. Lihat Riwayat                 |\n";
        cout << "|11. Peek                          |\n";
        cout << "|12. Pop Riwayat                   |\n";
        cout << "| 0. Keluar                        |\n";
        cout << "|__________________________________|\n";
        cout << "Pilih menu: ";
        if (!(cin >> pilih)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid!\n";
            continue;
        }

        switch (pilih) {
            case 1: tambah(p); break;
            case 2: tampil(p); break;

            case 7: {
                int id;
                cout << "Masukkan ID hewan: ";
                cin >> id;

                if (id > 0 && id <= n)
                    masukAntri(*(p + (id - 1)));
                else
                    cout << "ID tidak valid!\n";
                break;
            }

            case 8: {
                Hewan h = panggil();
                if (h.id != -1)
                    tambahRiwayat(h);
                break;
            }

            case 9: tampilAntri(); break;
            case 10: tampilRiwayat(); break;

            case 11:
                lihatDepan();
                lihatAkhir();
                break;
            case 12: pop(); break;

        }

    } while (pilih != 0);

    return 0;
}