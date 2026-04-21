#include <iostream>
#include <iomanip>
using namespace std;

struct JenisAlat{
    string kategori;
};

struct Alat{
    int id;
    string nama;
    int jumlah;
    JenisAlat jenis;
};

struct User{
    string username;
    string password;
};

typedef Alat* ptrAlat;

Alat daftarAlat[100];
User daftarUser[100];

int totalAlat = 0;
int totalUser = 0;
int idOtomatis = 1;

void garis(){
    cout << "============================================================\n";
}

void judulMenu(string judul){
    cout << "\n";
    garis();
    cout << "                     " << judul << endl;
    garis();
}

void tampil(ptrAlat data, int n){
    if(n == 0) return;

    tampil(data, n-1);

    cout << left
         << setw(5) << (data+n-1)->id
         << setw(20) << (data+n-1)->nama
         << setw(10) << (data+n-1)->jumlah
         << setw(15) << (data+n-1)->jenis.kategori
         << endl;
}

void lihatAlat(ptrAlat data, int jumlah){
    if(jumlah == 0){
        cout << "\nData alat masih kosong.\n";
        return;
    }

    judulMenu("DATA INVENTORY ALAT");

    cout << left
         << setw(5) << "ID"
         << setw(20) << "Nama Alat"
         << setw(10) << "Jumlah"
         << setw(15) << "Jenis"
         << endl;

    cout << "------------------------------------------------------------\n";

    tampil(data, jumlah);

    garis();
}

void sortNamaAsc(ptrAlat data, int jumlah){
    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){
            if((data+j)->nama > (data+j+1)->nama){
                Alat temp = *(data+j);
                *(data+j) = *(data+j+1);
                *(data+j+1) = temp;
            }
        }
    }
}

void sortJumlahDesc(ptrAlat data, int jumlah){
    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){
            if((data+j)->jumlah < (data+j+1)->jumlah){
                Alat temp = *(data+j);
                *(data+j) = *(data+j+1);
                *(data+j+1) = temp;
            }
        }
    }
}

void quickSort(ptrAlat data, int low, int high){
    int i = low, j = high;
    int pivot = (data + (low + high)/2)->id;

    while(i <= j){
        while((data+i)->id < pivot) i++;
        while((data+j)->id > pivot) j--;

        if(i <= j){
            Alat temp = *(data+i);
            *(data+i) = *(data+j);
            *(data+j) = temp;
            i++;
            j--;
        }
    }

    if(low < j) quickSort(data, low, j);
    if(i < high) quickSort(data, i, high);
}

void sortIdAsc(ptrAlat data, int jumlah){
    quickSort(data, 0, jumlah-1);
}

void cariById(ptrAlat data, int jumlah){
    int id;
    cout << "\nMasukkan ID yang dicari: ";
    cin >> id;
    cin.ignore();

    bool ditemukan = false;

    for(int i = 0; i < jumlah; i++){
        if((data+i)->id == id){
            judulMenu("HASIL PENCARIAN (ID)");

            cout << left
                 << setw(5) << "ID"
                 << setw(20) << "Nama"
                 << setw(10) << "Jumlah"
                 << setw(15) << "Jenis" << endl;

            cout << "------------------------------------------------------------\n";

            cout << setw(5) << (data+i)->id
                 << setw(20) << (data+i)->nama
                 << setw(10) << (data+i)->jumlah
                 << setw(15) << (data+i)->jenis.kategori
                 << endl;

            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "\nData dengan ID tersebut tidak ditemukan.\n";
    }
}

void cariByNama(ptrAlat data, int jumlah){
    string keyword;
    cout << "\nMasukkan nama alat yang dicari: ";
    getline(cin, keyword);

    bool ditemukan = false;

    judulMenu("HASIL PENCARIAN (NAMA ALAT)");

    cout << left
         << setw(5) << "ID"
         << setw(20) << "Nama"
         << setw(10) << "Jumlah"
         << setw(15) << "Jenis" << endl;

    cout << "------------------------------------------------------------\n";

    for(int i = 0; i < jumlah; i++){
        if((data+i)->nama.find(keyword) != string::npos ||
           (data+i)->jenis.kategori.find(keyword) != string::npos){

            cout << setw(5) << (data+i)->id
                 << setw(20) << (data+i)->nama
                 << setw(10) << (data+i)->jumlah
                 << setw(15) << (data+i)->jenis.kategori
                 << endl;

            ditemukan = true;
        }
    }

    if(!ditemukan){
        cout << "\nData tidak ditemukan.\n";
    }
}

void registerUser(User dataUser[], int &jumlahUser){
    judulMenu("REGISTER USER");

    cout << left << setw(15) << "Nama" << ": ";
    getline(cin, dataUser[jumlahUser].username);

    cout << left << setw(15) << "Password" << ": ";
    getline(cin, dataUser[jumlahUser].password);

    jumlahUser++;

    cout << "\nRegister berhasil!\n";
}

string login(User dataUser[], int jumlahUser){
    string username, password;

    judulMenu("LOGIN");

    cout << left << setw(15) << "Nama" << ": ";
    getline(cin, username);

    cout << left << setw(15) << "Password" << ": ";
    getline(cin, password);

    if(username == "asoy" && password == "129")
        return "admin";

    for(int i=0;i<jumlahUser;i++){
        if(dataUser[i].username == username &&
           dataUser[i].password == password){
            return "user";
        }
    }

    return "gagal";
}

void tambahAlat(ptrAlat data, int *jumlah){
    judulMenu("TAMBAH ALAT");

    (data + *jumlah)->id = idOtomatis++;

    cout << left << setw(15) << "Nama Alat" << ": ";
    getline(cin, (data + *jumlah)->nama);

    cout << left << setw(15) << "Jumlah" << ": ";
    cin >> (data + *jumlah)->jumlah;
    cin.ignore();

    int pilihJenis;
    cout << "\n1. Mesin\n2. Manual\nPilih : ";
    cin >> pilihJenis;
    cin.ignore();

    if(pilihJenis == 1)
        (data + *jumlah)->jenis.kategori = "Mesin";
    else
        (data + *jumlah)->jenis.kategori = "Manual";

    (*jumlah)++;

    cout << "\nData berhasil ditambahkan.\n";
}

void ubahAlat(ptrAlat data, int jumlah){
    lihatAlat(data, jumlah);

    int id;
    cout << "\nMasukkan ID : ";
    cin >> id;
    cin.ignore();

    for(int i=0;i<jumlah;i++){
        if((data+i)->id == id){

            cout << "Nama baru : ";
            getline(cin, (data+i)->nama);

            cout << "Jumlah baru : ";
            cin >> (data+i)->jumlah;
            cin.ignore();

            int pilih;
            cout << "1. Mesin\n2. Manual\nPilih : ";
            cin >> pilih;
            cin.ignore();

            if(pilih == 1)
                (data+i)->jenis.kategori = "Mesin";
            else
                (data+i)->jenis.kategori = "Manual";

            cout << "\nData berhasil diubah.\n";
            return;
        }
    }

    cout << "ID tidak ditemukan.\n";
}

void hapusAlat(ptrAlat data, int *jumlah){
    lihatAlat(data, *jumlah);

    int id;
    cout << "\nMasukkan ID : ";
    cin >> id;
    cin.ignore();

    for(int i=0;i<*jumlah;i++){
        if((data+i)->id == id){

            for(int j=i;j<*jumlah-1;j++){
                *(data+j) = *(data+j+1);
            }

            (*jumlah)--;

            cout << "\nData berhasil dihapus.\n";
            return;
        }
    }

    cout << "ID tidak ditemukan.\n";
}

void beliAlat(ptrAlat data, int jumlah){
    lihatAlat(data, jumlah);

    int id, beli;

    cout << "\nMasukkan ID : ";
    cin >> id;

    cout << "Jumlah beli : ";
    cin >> beli;

    for(int i=0;i<jumlah;i++){
        if((data+i)->id == id){

            if((data+i)->jumlah >= beli){
                (data+i)->jumlah -= beli;
                cout << "\nPembelian berhasil.\n";
            }
            else{
                cout << "\nStok tidak cukup.\n";
            }
            return;
        }
    }

    cout << "ID tidak ditemukan.\n";
}

int main(){
    int menu;

    while(true){
        judulMenu("SISTEM INVENTORY ALAT KEBUN");

        cout << "1. Register\n2. Login\n3. Keluar\n";

        garis();
        cout << "Pilih Menu : ";
        cin >> menu;
        cin.ignore();

        if(menu == 1){
            registerUser(daftarUser, totalUser);
        }

        else if(menu == 2){
            int percobaan = 0;
            string role;

            while(percobaan < 3){
                role = login(daftarUser, totalUser);

                if(role == "admin" || role == "user"){
                    break;
                }
                else{
                    cout << "\nLogin gagal ke-" << percobaan+1 << endl;
                    percobaan++;
                }
            }

            if(percobaan == 3){
                cout << "\nGagal login 3x. Program berhenti.\n";
                break;
            }

            if(role == "admin"){
                int pilih;
                do{
                    judulMenu("MENU ADMIN");

                    cout << "1. Tambah\n2. Lihat\n3. Ubah\n4. Hapus\n5. Sorting\n6. Searching\n7. Keluar\n";

                    garis();
                    cout << "Pilih : ";
                    cin >> pilih;
                    cin.ignore();

                    if(pilih==1) tambahAlat(daftarAlat, &totalAlat);
                    else if(pilih==2) lihatAlat(daftarAlat, totalAlat);
                    else if(pilih==3) ubahAlat(daftarAlat, totalAlat);
                    else if(pilih==4) hapusAlat(daftarAlat, &totalAlat);
                    else if(pilih==5){
                        if(totalAlat == 0){
                            cout << "\nData kosong, tidak bisa sorting!\n";
                        }
                        else{
                        int s;
                        cout << "\n1. Sort Nama (A-Z)\n";
                        cout << "2. Sort Jumlah (Terbesar)\n";
                        cout << "3. Sort ID (Terkecil)\n";
                        cout << "Pilih : ";
                        cin >> s;
                        cin.ignore();

                        if(s==1){ sortNamaAsc(daftarAlat, totalAlat); lihatAlat(daftarAlat, totalAlat);
                        cout << "\nData berhasil diurutkan.\n";
                        }
                        else if(s==2){ sortJumlahDesc(daftarAlat, totalAlat); lihatAlat(daftarAlat, totalAlat);
                        cout << "\nData berhasil diurutkan.\n";
                        }
                        else if(s==3){ sortIdAsc(daftarAlat, totalAlat); lihatAlat(daftarAlat, totalAlat);
                        cout << "\nData berhasil diurutkan.\n";
                        }
                        else{
                        cout << "\npilihan sorting tidak valid.\n";
                    }
                }
            }
                    else if(pilih==6){
                        if(totalAlat == 0){
                            cout << "\nData kosong\n";
                        }
                        int pilihCari;
                        cout << "\n1. Cari berdasarkan ID\n";
                        cout << "2. Cari berdasarkan Nama alat\n";
                        cout << "Pilih : ";
                        cin >> pilihCari;
                        cin.ignore();

                        if(pilihCari == 1){
                            cariById(daftarAlat, totalAlat);
                        }
                        else if(pilihCari == 2){
                            cariByNama(daftarAlat, totalAlat);
                        }
                        else{
                            cout << "\nPilihan searching tidak valid\n";
                    }
                }

                }while(pilih!=7);
            }

            else if(role == "user"){
                int pilih;
                do{
                    judulMenu("MENU USER");

                    cout << "1. Lihat\n2. Beli\n3. Keluar\n";

                    garis();
                    cout << "Pilih : ";
                    cin >> pilih;
                    cin.ignore();

                    if(pilih==1) lihatAlat(daftarAlat, totalAlat);
                    else if(pilih==2) beliAlat(daftarAlat, totalAlat);

                }while(pilih!=3);
            }
        }

        else if(menu == 3){
            cout << "\nProgram selesai.\n";
            break;
        }
    }
}