#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("cin.txt");
class automat
{
    vector <pair <pair <int,int>, string> > L;
    int n,m,start;
    string F;
public:
    void read()
    {
        f>>n;
        int x,y;
        string c;
        for(int i=0; i<n; i++)
        {
            f>>x>>y>>c;
            L.push_back(make_pair(make_pair(x,y),c));
        }
        f>>start;
        f>>m;
        for(int i=0; i<m; i++)
        {
            f>>c;
            F.push_back(x);
        }
    }
    void print()
    {
        for(int i=0; i<n; i++)
            cout<<L[i].first.first<<' '<<L[i].first.second<<' '<<L[i].second<<'\n';
    }
    bool cuvantul_apartine_limbajului(string s)
    {
        string alfabet;
        for(int i=0; i<n; i++)
            alfabet.push_back(L[i].second[0]);
        for(int i=0; i<s.length(); i++)
        {
            int ok=0;
            for(int j=0; j<alfabet.length(); j++)
                if(s[i]==alfabet[j])
                    ok=1;
            if(!ok)
                return false;
        }
        return true;
    }
    bool cuvant()
    {
        string cuv;
        cin>>cuv;
        if(cuvantul_apartine_limbajului(cuv))
        {
            int nod=start;
            for(int k=0; k<(int)cuv.length(); k++)
            {
                for(int i=0; i<n; i++)
                    if(L[i].first.first==nod)
                        if(L[i].second[0]==cuv[k])
                        {
                            nod=L[i].first.second;
                            i++;
                        }
            }
            for(int i=0; i<m; i++)
                if(nod==F[i])
                    return true;
        }
        else
            cout<<"\nCUVANTUL CITIT CONTINE CARACTERE CARE NU APARTIN LIMBAJULUI! ";
        return false;
    }
};

int main()
{
    automat A;
    A.read();
    int op;
    while(1)
    {
        cout<<"Introduce 1 pentru a citi un cuvant sau 0 pentru a iesi\n";
        cin>>op;
        if(op)
        {
            cout<<"Introduce un cuvant:\n";
            if(A.cuvant())
                cout<<"Cuvantul introdus apartine limbajului\n";
            else
                cout<<"Cuvantul introdus nu apartine limbajului\n";
        }
        else
            return 0;
    }

    return 0;
}

