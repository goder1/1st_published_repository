#include <iostream>
#include <fstream>
using namespace std;

void result()
{
    string a1,a2,a3;
    ifstream fin("Output.txt");
    fin>>a1>>a2>>a3;
    cout<<a1<<"\t\t"<<a2<<"\t\t"<<a3;
}
int main()
{
    cout<<"Do you want to enter your answers or to get the previous Data? (1 or 2)?\n";
    int main_root;
    cin>>main_root;
    if(main_root == 1){
    ofstream fout("Output.txt");
    ifstream finq("Questionz.txt");
    string q1, q2, q3, a1, a2, a3;
    finq>>q1>>q2>>q3;
    cout<<"Enter your "<<q1<<", "<<q2<<", "<<q3<<endl;
    cin>>a1>>a2>>a3;
    fout<<a1<<" "<<a2<<" "<<a3;
    fout.close();
    }
    else if(main_root==2)result();
    

    return 0;
}
