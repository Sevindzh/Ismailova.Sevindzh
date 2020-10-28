/* #include <iostream>
using namespace std;

int main()
{
	cout << "Hello World!\n" << endl;

	int ch;
	cin >> ch;
	cout << 10 / ch << endl;
} */

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    if (argc > 1)
    {
        if (argc > 2)
        {
            cout << "Какое имя по счёту вы хотите приветствовать\n";
            int n;
            cin >> n;
            cout << "Hello, " << argv[n];
        }
        else
        {
            cout << "Hello, " << argv[1];
        }
    }
    else
    {
        ofstream fout;
        fout.open("Error.txt");
        fout << "Ошибка: Имя не задано";
        fout.close();
    }
}
