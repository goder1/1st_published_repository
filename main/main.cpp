#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

void result()
{
    string a1,a2,a3;
    int n,r=0;
    ifstream fin("Output.txt");
    fin>>n;
    string spop;
    map<string,int> pop;
    cout<<"Pet_name:\tfavourite_tv_series:\tstreet_name:\n";
    for(int i = 0;i<n*3;)
    {
    fin>>a1>>a2>>a3;
    pop[a3]++;
    cout<<a1<<"\t\t"<<a2<<"\t\t"<<a3<<endl;
    i+=3;
    }
    for (auto [first, second] : pop)
    {
    if(second>r){r=second;spop=first;}
    }
    cout<<"The most popular answer for the third question is *"<<spop<<"*"<<endl;

}
int main()
{
    cout<<"Do you want to enter your answers or to get the previous Data? (1 or 2)?\n";
    int main_root;
    cin>>main_root;
    if(main_root==1){
    ifstream fin("Output.txt");
    ifstream finq("Questionz.txt");
    int n;
    fin>>n;
    vector<string> ss(n*3);
    for(int i = 0;i<n*3;i++)fin>>ss[i];
    n++;
    fin.close();
    ofstream fout("Output.txt");
    string q1, q2, q3, a1, a2, a3;
    finq>>q1>>q2>>q3;
    cout<<"Enter your "<<q1<<", "<<q2<<", "<<q3<<endl;
    cin>>a1>>a2>>a3;
    fout<<n<<" ";
    for(int i = 0;i<(n-1)*3;i++){fout<<ss[i]<<" ";if(i%3==0&&i!=0)fout<<endl;}
    fout<<a1<<" "<<a2<<" "<<a3<<endl;
    fout.close();
    }
    else if(main_root==2)result();
    else cout<<"-_-";

    return 0;
}
