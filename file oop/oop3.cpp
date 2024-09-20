
//  wap to store the details of a book (id,author,prics) in a file and display the store information of file;
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class book
{
    int id;
    char author[30];
    float price;

public:
    void input()
    {
        cout << "enter the id , author name and price of book: " << endl;
        cin >> id >> author >> price;
    }
    void display()
    {
        cout << "id=" << id << endl;
        cout << "author=" << author << endl;
        cout << "price=" << price << endl;
    }
};
void addrecord()
{
    fstream fin;
    book b;
    fin.open("book.txt", ios::app | ios::out | ios::binary);
    cout << "enter the book record for writting into binary file:";
    b.input();
    fin.write((char *)&b, sizeof(b));
    fin.close();
}
void displayrecords()
{
    fstream fout;
    book b;
    fout.open("book.txt", ios::in | ios::binary);
    while (fout.read((char *)&b, sizeof(b)))
    {
        b.display();
    }
    fout.close();
}
int main()
{
    int n;
    //  while(1)
    do{
    cout << "1.addrecord:" << endl;
    cout << "2.displayrecord:" << endl;
    cout << "3.exit" << endl;
    cout << "ënter the choice:";
    cin >> n;
    switch (n)
    {
    case 1:
        addrecord();
        break;
    case 2:
        displayrecords();
        break;
    case 3:
        exit(0);
    default:
        cout << "the choice you entered is wroungs:";
    }
    }while(1);
    return 0;
}