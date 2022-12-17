#include <iostream>
#include <fstream>

using namespace std;

void encrypt(string& text, int key)
{
    char* pointer = &text[0];
    while(*pointer != '\0'){
        if(*pointer != '\n')
            *pointer = *pointer+key;

        pointer++;
    }
}

void writeFile()
{
    int key;
    string filename;

    cout << "Filename: ";
    cin >> filename;

    cout << "Enter the key: ";
    cin >> key;

    cout << "Type your text\nEnter 'q' to quit\n" << endl;
    ofstream file_out(filename);

    cin.ignore();
    string text;


    while(getline(cin, text) && text != "q")
    {
        encrypt(text, key);
        file_out << text << endl;
    }
    file_out.close();
}

void readFile()
{
    int key;
    string filename;

    cout << "Filename: ";
    cin >> filename;

    cout << "Enter the key: ";
    cin >> key;

    ifstream file_in(filename);
    char c = file_in.get();

    cout << "\n\n" << endl;

    while(file_in.good())
    {
        if(c != '\n')
            cout << (char)(c-key);
        else
            cout << c;

        c = file_in.get();
    }
    file_in.close();
}

int main()
{
    int x;

    do{
        cout << "\n\nWhat do you want?" << endl;
        cout << "1) Create new file" << endl;
        cout << "2) Read file" << endl;
        cout << "3) Exit" << endl;
        cout << "-> ";
        cin >> x;

        switch(x)
        {
        case 1:
            cout << "\n\t\tCreating a file\n" << endl;
            writeFile();
            break;
        case 2:
            cout << "\n\t\tReading file\n" << endl;
            readFile();
            break;
        case 3:
            break;
        default:
            cout << "\n\t\tUnknown option\n" << endl;
            break;
        }
    }
    while(x != 3);

    return 0;
}
