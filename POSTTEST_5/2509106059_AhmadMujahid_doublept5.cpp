#include <iostream>
#include <iomanip>
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
    Node* prev;
};


Node* head = NULL;
Node* tail = NULL;
int n = 0;


void tambah() {
    Hewan h;

    cout << "\n ____________________\n";
    cout << "|     INPUT DATA     |\n";
    cout << "|____________________|\n";

    h.id = ++n;
    cout << "|ID     : " << h.id << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "|Nama   : ";
    getline(cin, h.nama);

    cout << "|Jenis  : ";
    getline(cin, h.jenis);

    cout << "|Harga  : ";
    cin >> h.harga;

    cout << "|____________________|\n";

    Node* baru = new Node{h, NULL, NULL};

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}


void tampilMaju() {
    if (head == NULL) {
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

    Node* temp = head;

    while (temp) {
        cout << "|"
             << setw(3)  << temp->data.id << " "
             << "|" << setw(19) << temp->data.nama
             << "|" << setw(19) << temp->data.jenis
             << "|Rp. " << setw(24) << temp->data.harga
             << "|\n";

        cout << "|____|___________________|___________________|___________________________|\n";

        temp = temp->next;
    }
}


void tampilMundur() {
    if (tail == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\nDATA HEWAN (DARI BELAKANG):\n";

    Node* temp = tail;

    while (temp) {
        cout << "ID: " << temp->data.id
             << " | " << temp->data.nama
             << " | " << temp->data.jenis
             << " | Rp." << temp->data.harga << endl;

        temp = temp->prev;
    }
}


void cariData() {
    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    int pilihan;
    cout << "\nCari berdasarkan:\n";
    cout << "1. ID\n2. Nama\nPilih: ";
    cin >> pilihan;

    Node* temp = head;
    bool ketemu = false;

    if (pilihan == 1) {
        int id;
        cout << "Masukkan ID: ";
        cin >> id;

        while (temp) {
            if (temp->data.id == id) {
                cout << "\nDATA DITEMUKAN:\n";
                cout << "ID    : " << temp->data.id << endl;
                cout << "Nama  : " << temp->data.nama << endl;
                cout << "Jenis : " << temp->data.jenis << endl;
                cout << "Harga : Rp." << temp->data.harga << endl;
                ketemu = true;
                break;
            }
            temp = temp->next;
        }
    } else {
        cin.ignore();
        string nama;
        cout << "Masukkan Nama: ";
        getline(cin, nama);

        while (temp) {
            if (temp->data.nama == nama) {
                cout << "\nDATA DITEMUKAN:\n";
                cout << "ID    : " << temp->data.id << endl;
                cout << "Nama  : " << temp->data.nama << endl;
                cout << "Jenis : " << temp->data.jenis << endl;
                cout << "Harga : Rp." << temp->data.harga << endl;
                ketemu = true;
                break;
            }
            temp = temp->next;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";
}


int main() {
    int pilih;

    do {
        cout << "\n __________________________________ \n";
        cout << "|        PAWCARE PETSHOP           |\n";
        cout << "|----------------------------------|\n";
        cout << "| 1. Tambah Data Hewan             |\n";
        cout << "| 2. Tampilkan Data (Maju)         |\n";
        cout << "| 3. Tampilkan Data (Mundur)       |\n";
        cout << "| 4. Cari Data                     |\n";
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
            case 1: tambah(); break;
            case 2: tampilMaju(); break;
            case 3: tampilMundur(); break;
            case 4: cariData(); break;
        }

    } while (pilih != 0);

    return 0;
}