#include <iostream>
#include <iomanip>
using namespace std;

struct JenisAlat {
    string kategoriAlat;
};

struct DataAlatKebun {
    int idAlat;
    string namaAlat;
    int jumlahAlat;
    JenisAlat jenisAlat;
};

struct DataUser {
    string username;
    string password;
};

DataAlatKebun daftarAlat[100];
DataUser daftarUser[100];

int totalDataAlat = 0;
int totalUser = 0;
int idAlatOtomatis = 1;

int registerUser() {

    cout << "\n=== REGISTER USER ===\n";

    cout << "Masukkan Username : ";
    getline(cin, daftarUser[totalUser].username);

    cout << "Masukkan Password : ";
    getline(cin, daftarUser[totalUser].password);

    totalUser++;

    cout << "Register berhasil!\n";

    return 0;
}

string loginPengguna() {

    string inputUsername;
    string inputPassword;

    cout << "\n=== LOGIN ===\n";

    cout << "Username : ";
    getline(cin, inputUsername);

    cout << "Password : ";
    getline(cin, inputPassword);

    if(inputUsername == "asoy" && inputPassword == "129") {
        return "admin";
    }

    for(int i = 0; i < totalUser; i++) {

        if(daftarUser[i].username == inputUsername &&
           daftarUser[i].password == inputPassword) {

            return "user";
        }
    }

    return "gagal";
}

int tambahAlat() {

    cout << "\n=== TAMBAH ALAT KEBUN ===\n";

    daftarAlat[totalDataAlat].idAlat = idAlatOtomatis++;

    cout << "Nama Alat : ";
    getline(cin, daftarAlat[totalDataAlat].namaAlat);

    cout << "Jumlah Alat : ";
    cin >> daftarAlat[totalDataAlat].jumlahAlat;
    cin.ignore();

    cout << "Jenis Alat (mesin/manual) : ";
    getline(cin, daftarAlat[totalDataAlat].jenisAlat.kategoriAlat);

    totalDataAlat++;

    cout << "Data alat berhasil ditambahkan.\n";

    return 0;
}

int lihatAlat() {

    cout << "\n=== DATA INVENTORY ALAT KEBUN ===\n";
    cout << "------------------------------------------------------------\n";

    cout << left << setw(5) << "ID"
         << setw(25) << "Nama Alat"
         << setw(10) << "Jumlah"
         << setw(10) << "Jenis" << endl;

    cout << "------------------------------------------------------------\n";

    for(int i = 0; i < totalDataAlat; i++) {

        cout << left << setw(5) << daftarAlat[i].idAlat
             << setw(25) << daftarAlat[i].namaAlat
             << setw(10) << daftarAlat[i].jumlahAlat
             << setw(10) << daftarAlat[i].jenisAlat.kategoriAlat
             << endl;
    }

    cout << "------------------------------------------------------------\n";

    return 0;
}

int ubahAlat() {

    int idDicari;

    cout << "Masukkan ID alat yang ingin diubah : ";
    cin >> idDicari;
    cin.ignore();

    for(int i = 0; i < totalDataAlat; i++) {

        if(daftarAlat[i].idAlat == idDicari) {

            cout << "Nama alat baru : ";
            getline(cin, daftarAlat[i].namaAlat);

            cout << "Jumlah alat baru : ";
            cin >> daftarAlat[i].jumlahAlat;
            cin.ignore();

            cout << "Jenis alat baru (mesin/manual) : ";
            getline(cin, daftarAlat[i].jenisAlat.kategoriAlat);

            cout << "Data berhasil diubah.\n";
            return 0;
        }
    }

    cout << "ID tidak ditemukan.\n";

    return 0;
}

int hapusAlat() {

    int idDicari;

    cout << "Masukkan ID alat yang ingin dihapus : ";
    cin >> idDicari;
    cin.ignore();

    for(int i = 0; i < totalDataAlat; i++) {

        if(daftarAlat[i].idAlat == idDicari) {

            for(int posisi = i; posisi < totalDataAlat - 1; posisi++) {
                daftarAlat[posisi] = daftarAlat[posisi + 1];
            }

            totalDataAlat--;

            cout << "Data berhasil dihapus.\n";
            return 0;
        }
    }

    cout << "ID tidak ditemukan.\n";

    return 0;
}

int main() {

    int menuAwal;

    while(true) {

        cout << "\n=== SISTEM INVENTORY ALAT KEBUN ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "Pilih : ";
        cin >> menuAwal;
        cin.ignore();

        if(menuAwal == 1) {
            registerUser();
        }

        else if(menuAwal == 2) {

            int percobaanLogin = 0;
            string rolePengguna = "gagal";

            while(percobaanLogin < 3) {

                rolePengguna = loginPengguna();

                if(rolePengguna != "gagal") {
                    break;
                }

                percobaanLogin++;

                if(percobaanLogin == 3) {
                    cout << "Login gagal 3 kali. Program berhenti.\n";
                    return 0;
                }

                cout << "Login salah! Sisa percobaan: "
                     << 3 - percobaanLogin << endl;
            }

            if(rolePengguna == "admin") {

                int menuAdmin;

                do {

                    cout << "\n=== MENU ADMIN ===\n";
                    cout << "1. Tambah Alat\n";
                    cout << "2. Lihat Alat\n";
                    cout << "3. Ubah Alat\n";
                    cout << "4. Hapus Alat\n";
                    cout << "5. Logout\n";
                    cout << "Pilih : ";
                    cin >> menuAdmin;
                    cin.ignore();

                    if(menuAdmin == 1) tambahAlat();
                    else if(menuAdmin == 2) lihatAlat();
                    else if(menuAdmin == 3) ubahAlat();
                    else if(menuAdmin == 4) hapusAlat();

                } while(menuAdmin != 5);
            }

            else if(rolePengguna == "user") {

                int menuUser;

                do {

                    cout << "\n=== MENU USER ===\n";
                    cout << "1. Lihat Data Alat\n";
                    cout << "2. Logout\n";
                    cout << "Pilih : ";
                    cin >> menuUser;
                    cin.ignore();

                    if(menuUser == 1) lihatAlat();

                } while(menuUser != 2);
            }
        }
    }

    return 0;
}