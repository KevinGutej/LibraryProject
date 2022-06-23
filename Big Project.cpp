#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>


using namespace std;

struct book
{

    string title;
    string author;
    string premier_date;
    int number_of_pages;
    int number_of_available;
    int number_of_taken;

};

void input_error()
{
    cin.clear();
    cin.ignore();
}
void menu()
{
    cout << " [1] - Display data base " << endl;
    cout << " [2] - Display specific record " << endl;
    cout << " [3] - Enter data " << endl;
    cout << " [4] - Delete data " << endl;
    cout << " [5] - Edit data " << endl;
    cout << " [6] - Export data base to file " << endl;
    cout << " [7] - Import data base from file " << endl;
    cout << " [8] - Exit the program " << endl;
}

void space()
{
    cout << endl;
    cout << endl;
}

void line()
{
    cout << "====================================" << endl;
}

void option1(vector<book>&library)
{
    Sleep(1000);
    cout << "Displaying all data..." << endl;
    space();
    cout << "DATA BASE RECORDS: " << endl;
    Sleep(950);
    space();
    for(int i=0; i<library.size(); i++)
    {
        cout << "Record number: " << i << endl;
        line();
        space();
        Sleep(450);
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Premier date: " << library[i].premier_date << endl;
        cout << "Number of pages: " << library[i].number_of_pages << endl;
        cout << "Number of available: " << library[i].number_of_available << endl;
        cout << "Number of taken: " << library[i].number_of_taken << endl;
        space();

    }
}

void option2(vector<book>&library, int &specific_record_number)
{
    cout << "Working..." << endl;
    Sleep(800);
    cout << "[INFO] Number of all records is: " << library.size() << endl;
    space();
    Sleep(600);
    cout << "Checking if your number is valid..." << endl;
    space();
    Sleep(1250);
    for(;;)
    {

        Sleep(900);
        if(specific_record_number>=0&&specific_record_number<=library.size())break;
        cout << "Wrong number! You number is not in range of the wanted value!" << endl;
        cout << "Enter again: ";
        cin >> specific_record_number;
        space();

    }
    cout << "Data base record of your number is available!" << endl;
    space();
    Sleep(500);
    cout << "Record number: " << specific_record_number << endl;
    line();
    space();
    Sleep(650);
    cout << "Title: " << library[specific_record_number].title << endl;
    cout << "Author: " << library[specific_record_number].author << endl;
    cout << "Premier date: " << library[specific_record_number].premier_date << endl;
    cout << "Number of pages: " << library[specific_record_number].number_of_pages << endl;
    cout << "Number of available: " << library[specific_record_number].number_of_available << endl;
    cout << "Number of taken: " << library[specific_record_number].number_of_taken << endl;
    space();
    line();
    Sleep(1000);
    space();
    Sleep(1000);

}

void option6(vector<book>&library, fstream &file, string &file_name)
{
    cout << "Your data is being exported now to the file now..." << endl;
    Sleep(950);
    file.open(file_name, ios::out);
    {
        for(int i=0;i<library.size();i++)
        {
            file << "Record number: " << i << endl;
            file << "Title: " << library[i].title << endl;
            file<< "Author: " << library[i].author << endl;
            file << "Premier date: " << library[i].premier_date << endl;
            file << "Number of pages: " << library[i].number_of_pages << endl;
            file << "Number of available: " << library[i].number_of_available << endl;
            file << "Number of taken: " << library[i].number_of_taken << endl;
            file << "======================================" << endl;

        }
    file.close();
    Sleep(700);
    cout << "Work in progress..." << endl;
    Sleep(1000);
    cout << "Your data has been exported successfully" << endl;
    }


}
void option8()
{
    cout << "Exiting the library program..." << endl;
    Sleep(900);
    space();
    system("pause");
    Sleep(900);
    exit(0);
    space();

}
int main()
{
    vector<book>library(3);
    fstream file;
    string file_name;
    library[0]={"Harry Potter","J.K.Rowling","18/01/2002",700,1200,800};
    library[1]={"Lord of The Rings: The Fellowship of The Ring","J.R.R.Tolkien","12/05/1990",100,1500,33};
    library[2]={"The Dairy of the Wimpy","Jeff Kinney","05/12/2007",120,30,0};
    //cout << "Title is: " << library[0].title << endl;
    int menu_choice_number, specific_record_number; // for switch-case funtionality & for option2 functionality
    for(;;)
    {
        cout << "WELCOME IN LIBRARY PROGRAM!" << endl;
        space();
        line();
        menu();
        line();
        space();
        cout << "PLEASE CHOOSE A OPTION FROM 1 TO 7" << endl;
        Sleep(950);
        cout << "Your choice: ";
        cin >> menu_choice_number; // for switch-case funtionality
        Sleep(650);
        cout << "You have chosen option number: " << menu_choice_number << endl;
        Sleep(450);
        cout << "Executing..." << endl;
        Sleep(1050);
        switch(menu_choice_number)
        {
                case 1:
                {
                    option1(library);
                    space();
                }
                    break;

                case 2:
                {
                    space();
                    cout << "Enter specific record number: ";
                    cin >> specific_record_number;
                    option2(library,specific_record_number);
                }
                    break;

                case 3:
                {
                    space();
                }
                    break;

                case 4:
                {
                    space();
                }
                    break;

                case 5:
                {
                    cout << "WORKING IN PROGRESS.SOON" << endl;
                    space();
                }
                    break;

                case 6:
                {
                    cout << "Please enter the name of the file" << endl;
                    input_error();
                    getline(cin, file_name);
                    option6(library, file, file_name);
                    space();
                }
                    break;

                case 7:
                {
                    cout << "WORKING IN PROGRESS.SOON" << endl;
                    space();
                }
                    break;

                case 8:
                {
                    space();
                    option8();
                }
                    break;

        }
    }
}
