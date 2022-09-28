#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

void change_questions()
{
    ofstream fout("Questionz.txt");
    cout<<"Enter questions which you want to answer in the future (to end your list enter 0):\n";
    string s;
    for(cin>>s;s!="0";cin>>s)
    {
        fout<<s<<" ";
    }
    fout<<"STOP";
    fout.close();
    ofstream aout("Output.txt");
    s="";
    aout<<s;
}
void result(int total)
{
    string a1,a2,a3;
    vector<string> quest;
    int n,r=0,k=0;
    ifstream qin("Questionz.txt");
    string q;
    for(qin>>q;q!="STOP";qin>>q)
    {
        k+=2+q.length();
        quest.push_back(q);
    }
    qin.close();
    ifstream fin("Output.txt");
    fin>>n;
    string spop;
    map<string,int> pop;

    int amount = (total-k)/quest.size();
    for(int i = 0; i < quest.size();i++)
    {
        cout<<quest[i]<<": ";
        for(int j = 0; j < amount;j++)cout<<" ";
    }
    cout<<endl;
    for(int i = 0;i<n;i++)
    {
        vector<string> answers;
        string ans;
        for(int j = 0;j<quest.size();j++)
        {
            fin>>ans;answers.push_back(ans);
        }
        pop[answers[answers.size()-1]]++;
        for(int j = 0; j < answers.size();j++)
        {
            if(quest[j].length()+amount>=answers[j].length())
            {
                cout<<answers[j];
                for(int m = 0; m <= quest[j].length()+amount-answers[j].length();m++)cout<<" ";
            }
            else
            {
                cout<<answers[j].substr(0,quest[j].length()-3+amount)<<"... ";
            }
            cout<<" ";
        }
        cout<<endl;
    }
    for(auto [first, second] : pop)
    {
        if(second>r){r=second;spop=first;}
    }
    cout<<"The most popular answer for the last question is *"<<spop<<"*"<<endl;

}
int main()
{
    cout<<"Do you want to enter your answers, to get the previous Data or to change questions in question-list? (1, 2 or 3)?\n";
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
    else if(main_root==2)
    {
        int k = 0;
        ifstream qin("Questionz.txt");
        string q;
        for(qin>>q;q!="STOP";qin>>q)
        {
            k+=2+q.length();
        }
        cout<<"Enter width of the table you want to see (not less than "<<k<<"):\n";
        int total;cin>>total;
            result(total);
    }
    else if(main_root == 3)change_questions();
    else cout<<"-_-";
    return 0;
}
