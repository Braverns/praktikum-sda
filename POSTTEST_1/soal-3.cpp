#include <iostream>
using namespace std;


void reverseArray(int* arr, int n) {
    int* awal = arr;                
    int* akhir = arr + n - 1;  

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;    
        akhir--;   
    }
}

int main() {

    int A[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Sebelum: \n";
    cout << "__________________________________\n";
    cout << "Index\tNilai  \t   Alamat   \n";
    cout << "__________________________________\n";
    for (int i = 0; i < n; i++) {
        cout << i << "     \t"
             << *(A + i) << "     \t"
             << (A + i) << endl;
    }

    reverseArray(A, n);

    cout << "\nSesudah: \n";
    cout << "__________________________________\n";
    cout << "Index\tNilai  \t   Alamat   \n";
    cout << "__________________________________\n";

    for (int i = 0; i < n; i++) {
        cout << i << "     \t"
             << *(A + i) << "     \t"
             << (A + i) << endl;
    }

    return 0;
}