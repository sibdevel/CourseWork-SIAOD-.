//4 2 3 4 3
#include <iostream>
#include <fstream>
using namespace std;

struct record
{
    char fullname[32];
    char street[18];
    short int numberHouse;
    short int numberApartment;
    char dateSettle[10];

};

int main()
{
    system("color 2");
    record* pl = new record[4000];
    setlocale(LC_CTYPE, "Russian");
    ifstream database("testBase4.dat", ios::binary);

    if (!database) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    if (database.is_open()) {
        cout << "Удалось открыть файл!" << endl;
        cout << endl;
        cout << "ФИО гражданина" << "\t\t\t" << "Название улицы" << "\t\t" << "Номер дома" << "\t" << "Номер квартиры" << "\t" << "Дата поселения" << endl;
        cout << endl;
        for (int i = 0; !database.read((char*)&pl[i], sizeof(record)).eof(); i++) {
            cout << pl[i].fullname << "\t" << pl[i].street << "\t" << pl[i].numberHouse << "\t\t" <<
                pl[i].numberApartment << "\t\t" << pl[i].dateSettle << endl;
        }
    }

    database.close();
    return 0;
}

