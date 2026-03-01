#include <iostream>
using namespace std;

int main() {

    string nama, password;
    int percobaan = 0;

    cout << "====================================\n";
    cout << "     PROGRAM KONVERSI PANJANG       \n";
    cout << "====================================\n\n";

    while (percobaan < 3) {

        cout << "=== LOGIN ===" << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "Password: ";
        cin >> password;

        if (nama == "asoy" && password == "129") {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login salah!\n";
            percobaan++;
        }
    }
    if (percobaan == 3) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilih;
    string input;
    double nilai;

    do {
        cout << "\n=== MENU KONVERSI ===" << endl;
        cout << "1. Meter ke KiloMeter dan CentiMeter" << endl;
        cout << "2. KiloMeter ke Meter dan CentiMeter" << endl;
        cout << "3. CentiMeter ke Meter dan KiloMeter" << endl;
        cout << "4. Keluar" << endl;
        cout << "=====================" << endl;
        cout << "Pilih Menu (1-4): \n";
        cin >> pilih;

        if (pilih < 1 || pilih > 4) {
            cout << "Pilihannya Tidak Valid Kakak! Silahkan Pilih 1-4.\n";
            continue;
        }

        if (pilih >= 1 && pilih <= 3) {

            cout << "Masukkan Nilai Panjang: ";
            cin >> input;

            cout << "\n===== HASIL KONVERSI =====\n";

            for (int i = 0; i < input.length(); i++) {
                if (input[i] == ',')
                    input[i] = '.';
            }

            nilai = stod(input);

            if (pilih == 1){
                cout << nilai << " Meter = "
                     << nilai/1000 << " KiloMeter\n";
                cout << nilai << " Meter = " 
                     << nilai*100 << " CentiMeter\n";
            }

            if (pilih == 2){
                cout << nilai << " KiloMeter = "
                     << nilai*1000 << " Meter\n";
                cout << nilai << " KiloMeter "
                     << nilai*100000 << " CentiMeter\n";
            }

            if (pilih == 3){
                cout << nilai << " CentiMeter = "
                     << nilai/100 << " Meter\n";
                cout << nilai << " CentiMeter = "
                     << nilai/100000 << " KiloMeter\n";
            }

            cout << "===========================\n";
        }

    } while (pilih != 4);

    cout << "Program selesai.\n";

    return 0;
}