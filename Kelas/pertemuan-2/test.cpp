#include <iostream>
using namespace std;
// // buah[4] = "Rambutan";
// // for (int i = 0; i < 5; i +) {
// // cout << buah[i] << endl;
// // }
// // cout << buah[0] << endl;
// // cout << angka[2] << endl;
// // cout << endl;
// // // For each perulangan
// // for (string x : buah) {
// // cout << x << endl;
// // }

// // int angka[5] = {10, 20, 30, 40, 50};
// // / sizeof(angka) = 20 bytes (5 elemen × 4 bytes per int)
// // / sizeof(angka[0]) = 4 bytes (1 elemen int)
// // int panjang = sizeof(angka) / sizeof(angka[0]);
// // cout << "Panjang array: " << panjang << endl;

// int main() {
// int panjang = 0; / Jumlah data mahasiswa saat ini
// string mahasiswa[MAX_MAHASISWA]; / Array 1 dimensi
// int pilihan, index;
// do {
// cout << "\n = MENU PROGRAM DATA MAHASISWA =" << endl;
// cout << "1. Tampilkan Mahasiswa" << endl;
// cout << "2. Tambah Mahasiswa" << endl;
// cout << "3. Ubah Mahasiswa" << endl;
// cout << "4. Hapus Mahasiswa" << endl;
// cout << "5. Keluar" << endl;
// cout << "Pilihan: ";
// cin >> pilihan;
// switch (pilihan) {
//     case 1: / READ
// break;
// case 2: / CREATE
// break;
// case 3: / UPDATE
// break;
// case 4: / DELETE
// break;
// case 5:
// cout << "Program selesai." << endl;
// break;
// default:
// cout << "Pilihan tidak valid." << endl;
// }
// } while (pilihan = 5);
// return 0;
// }

// if (panjang << MAX_MAHASISWA) {
// cout << "Masukkan nama mahasiswa: ";
// cin.ignore();
// getline(cin, mahasiswa[panjang]);
// panjang +;
// }

// int main() {
//     string nama;
//     string namadua;
//     cout << "masukkan nama pertama anda" << endl;
//     cin >> nama;
//     cout << "masukkan nama kedua anda" << endl;
//     cin.ignore();
//     getline(cin, namadua);
//     cout << "nama pertama anda adalah: " << nama << endl;
//     cout << "nama kedua anda adalah: " << namadua << endl;
//     return 0;
// }

// int matriks[3][3] = {

// {1, 2, 3}, // Baris ke-0
// {4, 5, 6}, // Baris ke-1
// {7, 8, 9} // Baris ke-2

// };
// // Mengakses elemen
// cout << matriks[0][1] << endl;
// cout << matriks[2][0] << endl;
// // Menampilkan seluruh matriks dengan nested loop
// for (int i = 0; i < 3; i++) { // Loop baris
// for (int j = 0; j < 3; j++) { //Loop kolom
// cout << matriks[i][j] << " ";
// }
// cout << endl;
// }
// for (auto &baris : matriks) { // Iterasi setiap baris (array 1D)
// for (auto &elemen : baris) { // Iterasi setiap elemen dalam baris
// cout << elemen << " ";
// }
// cout << endl;
// }

int main() {
int nilai[3][2][2] = {
{ {80, 85}, {75, 90} }, // Kelas A
{ {88, 92}, {70, 78} }, // Kelas B
{ {82, 87}, {78, 80} }
};
cout << " = DATA NILAI MAHASISWA =\n\n";
for (int k = 0; k < 3; k++) {
cout << "Kelas " << char('A' + k) << endl;
for (int m = 0; m < 3; m++) {
cout << " Mahasiswa " << m + 1 << endl;
cout << " UTS : " << nilai[k][m][0] << endl;
cout << " UAS : " << nilai[k][m][1] << endl;
}
cout << endl;
}
return 0;
}