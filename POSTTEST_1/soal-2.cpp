#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];
    int indeksIPKTertinggi = 0;

    cout << "Input Data Mahasiswa" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);

        cout << "NIM  : ";
        getline(cin, mhs[i].nim);

        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore(); 
    }

    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[indeksIPKTertinggi].ipk) {
            indeksIPKTertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK Tertinggi" << endl;
    cout << "Nama : " << mhs[indeksIPKTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksIPKTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksIPKTertinggi].ipk << endl;

    return 0;
}