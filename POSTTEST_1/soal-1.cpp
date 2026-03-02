#include <iostream>
using namespace std;

int FindMin(int data[], int jumlah, int &indeksMinimum) {
    int nilaiMinimum = data[0];   
    indeksMinimum = 0;            

    for (int i = 1; i < jumlah; i++) {
        if (data[i] < nilaiMinimum) {
            nilaiMinimum = data[i];
            indeksMinimum = i;
        }
    }

    return nilaiMinimum;
}

int main() {
    int data[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int jumlah = 8;
    int indeksMinimum;

    int hasilMinimum = FindMin(data, jumlah, indeksMinimum);

    cout << "Nilai minimum  : " << hasilMinimum << endl;
    cout << "Indeks minimum : " << indeksMinimum << endl;

    return 0;
}

/*

Hasil Analisis 

Tabel Cost
 ______________________________________________________
| Pseudocode                      | Cost | Tmin | Tmax |
|_________________________________|______|______|______|
| procedure FindMin               | C1   | 1    | 1    |
| nilaiMinimum ← data[0]          | C2   | 1    | 1    |
| for i ← 1 to jumlah − 1         | C3   | n    | n    |
| if data[i] < nilaiMinimum       | C4   | n-1  | n-1  |
| nilaiMinimum ← data[i]          | C5   | 0    | n-1  |
| end if                          | C6   | n-1  | n-1  |
| end for                         | C7   | n    | n    |
| return nilaiMinimum             | C8   | 1    | 1    |
| end procedure                   | C9   | 1    | 1    |
|_________________________________|______|______|______|
| Total waktu (Tn)                       | O(n) | O(n) |
|________________________________________|______|______|

BEST CASE:
Terjadi ketika elemen pertama sudah merupakan nilai minimum,
sehingga baris C5 tidak dijalankan.

Tmin(n) = C1 + C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8 + C9
        = 1 + 1 + n + (n-1) + 0 + (n-1) + n + 1 + 1
        = 4n + 2
        = O(n)


WORST CASE:
Terjadi ketika setiap elemen lebih kecil dari sebelumnya,
sehingga baris C5 dijalankan sebanyak (n-1) kali.

Tmax(n) = C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8 + C9
        = 1 + 1 + n + (n-1) + (n-1) + (n-1) + n + 1 + 1
        = 5n + 1
        = O(n)


KESIMPULAN:
Best Case  = O(n)
Worst Case = O(n)

Algoritma termasuk Linear Time Complexity
karena hanya menggunakan satu loop, kalau satu **** itu ....

Intinya, O(n) ini mengecek semua array satu per satu
*/