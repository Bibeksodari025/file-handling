/* write a class student with rollnumber ,name ,address,marks as member variable .use member function to
write the records of 3 student in binary files and another functions to read records from the file wap to
search a specific records of student of student using roll number as key user input;*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class student
{
    char name[20];
    int roll;
    char address[20];
    float marks;

public:
    void input()
    {
        cout <<endl << "enter the name " << endl;
        // cin >> name;
        cin.ignore();
        cin.getline(name, 20);
        cout<<"enter the roll"<< endl;
        cin>>roll;
        cout<<"enter the address:"<< endl;
        cin.ignore();
        cin.getline(address, 20);
        cout<<"enter the marks:"<< endl;
        cin>>marks;
    }
    void display()
    {
        cout << "name=" << name<<endl;
        cout << "roll=" << roll<<endl;
        cout << "adress=" << address<<endl;
        cout << "marks=" << marks<<endl;
    }
    int getroll()
    {
        return roll;
    }
int check(int r)
{
    if (r =this -> roll)
        return 1;
    else
        return 0;
}
};
void writerecords()
{
    student s[3];
    fstream fout;
    fout.open("student.txt", ios::out | ios::app | ios::binary);
    cout << "enter the info of 3 stydent for writing in binary file:";
    for (int i = 0; i < 3; i++)
    {
        s[i].input();
       // fout.write(reinterpret_cast<char *>&s[i], sizeof(s[i]));
        fout.write((char *)&s[i],sizeof(s[i])); 
    }
    fout.close();
}
void readrecords()
{
    student s;
    ifstream fin;
    fin.open("student.txt", ios::in | ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.display();
    }
    fin.close();
}
void searchSpecific() {
    student s;
    ifstream fin("student.txt", ios::in | ios::binary); // Ensure you're using the correct file name
    // if (!fin) 
    // {
    //     cerr << "Error opening file for reading." << endl;
    //     return;
    // }

    int roll;
    bool found = false;
    
    cout << "Enter the roll number of the student to search: ";
    cin >> roll;

    while (fin.read(reinterpret_cast<char*>(&s), sizeof(s))) 
    {
        if (s.check(roll)) {
            s.display();            
            found = true;
            break;
        }
        fin.seekg(sizeof(s),ios::cur);
    }

    if (!found) {
        cout << "Record not found." << endl;
    }

    fin.close();
}

int main()
{
    int n;
    do
    {
        system("cls");
        cout << "1.addrecords:" << endl;
        cout << "2.displayrecords:" << endl;
        cout << "3.display specific records:" << endl;
        cout << "4.exits:" <<endl<<endl;
        cout<<"enter the choice:"<<endl;
        // cin.ignore();
        cin >> n;
        switch (n)
        {
        case 1:
            writerecords();
            cin.ignore();
            
            break;
        case 2:
            system("cls");
            readrecords();
            getch();
            
            break;
        case 3:
            searchSpecific();
            cin.ignore();
            cin.get();
            break;
        case 4:
            exit(0);
        default:
            cout << "the choice you enterde is not founds:";
        }
    }while(n!=4);
    return 0;
}