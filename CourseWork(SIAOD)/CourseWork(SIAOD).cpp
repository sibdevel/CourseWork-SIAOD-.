//4 2 3 4 3
#include <iostream>
#include <cstdlib>
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

void PrintHeader()
{
    cout << "Full name"
        << "\t\t\t\t" << "Street"
        << "\t\t" << "House number"
        << "\t" << "Apartment number"
        << "\t" << "Date of settle"
        << endl;
    cout << endl;
}

void PrintBody(record*& pl, int& page)
{
    for (int i = page * 20; i < page * 20 + 20; i++)
    {
        cout << i + 1 << ". "
            << pl[i].fullname
            << "\t" << pl[i].street
            << "\t" << pl[i].numberHouse
            << "\t\t"
            << pl[i].numberApartment
            << "\t\t"
            << pl[i].dateSettle << endl;
    }
}

void PrintMenu(record*& pl, int& page, int& choise);

void SlideFirstPage(record*& pl, int& page, int& choise)
{
    while (true)
    {
        system("cls");
        page = 0;
        PrintHeader();
        PrintBody(pl, page);
        PrintMenu(pl, page, choise);
    }
}

void SlideLastPage(record*& pl, int& page, int& choise)
{
    while (true)
    {
        system("cls");
        page = 199;
        PrintHeader();
        PrintBody(pl, page);
        PrintMenu(pl, page, choise);
    }
}

void FunkMenu(record*& pl, int& page, int& choise)
{
    switch (choise)
    {
    case 1:
        while (true)
        {
            system("cls");
            page++;
            PrintHeader();
            PrintBody(pl, page);
            PrintMenu(pl, page, choise);
        }
    case 2: SlideFirstPage(pl, page, choise);
    case 3: SlideLastPage(pl, page, choise);
    case 4: exit(1);
    }

}

void PrintMenu(record*& pl, int& page, int& choise)
{
    cout << "Menu: " << "|<1>:Next page| \t"
         << "|<2>:First page| \t" 
         << "|<3>:Last page| \t" 
         << "|<4>:Close program| \t" 
         << "|<5>:Sort|\t" << endl;
    cin >> choise;
    cout << endl;
    if (choise >= 1 && choise <= 5)
    {
        FunkMenu(pl, page, choise);
    }
    else
    {
        cout << "ERROR: invalid value" << endl;
        PrintMenu(pl, choise, choise);
    }
}

int main()
{
    system("color 2");
    record* pl = new record[4000];

    int choise = 0;
    int page = 0;

    ifstream database("testBase4.dat", ios::binary);

    if (database.is_open())
    {
        cout << "Database is open!" << endl;
        cout << endl;
    }
    else if (!database)
    {
        cout << "Database is not open" << endl;
        return 1;
    }

    for (int i = 0; !database.read((char*)&pl[i], sizeof(record)).eof(); i++);

    while (true)
    {
        system("cls");
        PrintHeader();
        PrintBody(pl, page);
        PrintMenu(pl, page, choise);
    }

    database.close();
    return 0;
}

