#include<fstream>
#include<string>
#include<iostream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int f;
    cout << "введите чиcло, которое соответствует операции, которую вы хотите выполнить\n 1.поучаствовать в опросе\n 2.посмотреть сохраненный результат\n 3.удалить содержимое файла с ответами\n";
    cin >> f;
    if (f == 1)
    {
       ofstream fout("mainfile.txt", ios_base::app);
       ifstream fin ("questions.txt");
        string a, b, c, d;
        while (getline(fin, d))
        {
            cout << d << endl;
            cin >> a;
            fout << a << "\n";
        }
        fin.close();
        fout.close();
    }
    else if (f == 2)
    {
        string d, f, p = "", k = "";
        int n = 0;
        ifstream fiin("questions.txt");
        while (getline(fiin, f))
        {
            n++;
            p += f.size();
            cout << "   " << f << "   ";
        }
        cout << endl;
        ifstream fin("mainfile.txt");
        getline(fin, d);
        while (d.size())
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = (p[i] - d.size())/2 + 3; j > 0; j--)
                    cout << " ";
                cout << d;
                for(int j = p[i] - (p[i] - d.size())/2 + 3 - d.size(); j > 0; j--)
                    cout << " ";
                getline(fin, d);
            }
            cout << endl;
        }
    fin.close();
    fiin.close();
    }
    else if (f == 3)
    {
        ofstream fout("mainfile.txt", ios_base::trunc);
        fout.close();
    }
    else
    {
        cout << "не то число)";
    }
    return 0;

}
