#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

void change_questions()
{
    ofstream fout("Questionz.txt");
    cout<<"Enter questions which you want to answer in the future (to end your list enter 0):\n";
    string s="";
    vector<string> questions;
    while(s != "0")
    {
        getline(cin,s);
        questions.push_back(s);
    }
    for(int i = 0;i<questions.size()-1;i++)
    {
        swap(questions[i],questions[i+1]);
    }
    questions.pop_back();
    for(int i = 0; i < questions.size(); i++)
    {
        fout << questions[i] << endl;
    }
    fout.close();
    ofstream aout("Output.txt");
    s="0";
    aout<<s;

}
void result(int total)
{
    vector<string> quest;
    int n,r=0,k=0;
    ifstream qin("Questionz.txt");
    string q="";
    for(getline(qin, q); q != "0"; getline(qin, q))
    {
        k += 2 + q.length();
        quest.push_back(q);
    }
    qin.close();
    ifstream fin("Output.txt");
    fin >> n;
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
        //fin>>ans;
        int start = 0;
        for(int j = 0;j<quest.size();j++)
        {
            getline(fin,ans);
            if(start == 0){ans=ans.substr(2,ans.length()-2);start=1;}
            answers.push_back(ans);
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
    if(main_root == 1){
    ifstream finq("Questionz.txt");
    vector<string> questions;
    string question="";
    while(question != "0")
    {
     getline(finq,question);
     questions.push_back(question);
    }
    questions.pop_back();
    /*for(int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }*/



    finq.close();
    ifstream fin("Output.txt");
    int n;
    fin>>n;
    vector<string> answers1 (n*questions.size());
    for(int i = 0;i<n*questions.size();i++)getline(fin,answers1[i]);
    n++;
    fin.close();



    vector<string> answers2;
    ofstream fout("Output.txt");
    string answer = "";
    int stoper = 0;
    string stop = "";
    for(int i = 0;stop != "stop";i++)
    {
        if(stoper)
        {
            if(questions[i-1]!="0")
            cout<<questions[i-1]<<endl;
            else stop = "stop";
        }
        if(stop != "stop")
        {
        getline(cin,answer);
        answers2.push_back(answer);
        stoper = 1;
        }
    }
    for(int i = 0;i<answers2.size()-1;i++)
    {
        swap(answers2[i],answers2[i+1]);
    }
    answers2.pop_back();
    /*
    cout<<answers2.size()<<endl;
    for(int i = 0;i<answers2.size();i++)
    {
        cout<<answers2[i]<<endl;
    }
    fout<<0;*/


    fout<<n<<" ";
    for(int i = 0;i<answers1.size();i++)
    {
        fout<<answers1[i]<<"\n";
    }
    for(int i = 0;i<answers2.size();i++)
    {
        fout<<answers2[i]<<"\n";
    }
    fout.close();
    }
    else if(main_root==2)
    {
        int k = 0;
        ifstream qin("Questionz.txt");
        string q;
        for(getline(qin,q); q != "0"; getline(qin,q))
        {
            k += 2 + q.length();
        }
        cout<<"Enter width of the table you want to see (not less than "<<k<<"):\n";
        int total;
        cin>>total;
        result(total);
    }
    else if(main_root == 3)change_questions();
    else cout<<"-_-";
    return 0;
}
