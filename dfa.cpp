#include <bits/stdc++.h>

using namespace std;

int main()
{   int x,y, max = 0, stare_f[50], str, q, starecrt = 0, ok, choice;
    string cuvant;
    string cond;
    string dfa[50][50];
    string drum;
    drum += std::to_string(starecrt);
    for (int i=0; i<50; i++)
        for (int j=0; j<50; j++)
            dfa[i][j]='*';
    for (int i=1; i<=50; i++)
        stare_f[i] = -1;
    ifstream f("intrare.in");
    f>>q;
    while (q!=0){
        f>>str;
        stare_f[str]=str;
        q--;
    }
    while (f>>x){
        f>>y;
        f>>cond;
        dfa[x][y] = cond;
        if (x > max)
            max = x;
        if (y > max)
            max = y;
    }

    for (int i=0; i<max+1; i++){
        for(int j=0; j<max+1; j++)
        cout<<dfa[i][j]<<" ";
        cout<<"\n";
    }

    while(1){
        cout<<"1. Introducere cuvant.\n";
        cout<<"2. Iesire.\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nIntroduceti cuvantul: ";
                cin>>cuvant;
                for (int i=0; i<cuvant.length(); i++){
                    ok = 0;
                    for (int j=0; j<max+1; j++){
                        if (dfa[starecrt][j].length() == 1 ){
                            if (dfa[starecrt][j] == (string (1, cuvant[i]))){
                                starecrt = j;
                                drum.append("->");
                            drum.append(std::to_string(starecrt));
                                ok = 1;
                                break;
                            }
                        }
                        if (dfa[starecrt][j].length() > 1){
                            for (int k=0; k<dfa[starecrt][j].length(); k+=2){
                                if (dfa[starecrt][j][k] == cuvant[i]){
                                    starecrt = j;
                                    drum.append("->");
                                    drum.append(std::to_string(starecrt));
                                    ok = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (ok == 0){
                        cout<<"Cuvantul nu este acceptat\n";
                        break;
                    }
                }
                if (ok == 1){
                    for (int i=0; i<max+1; i++){
                        ok = 0;
                        if (starecrt == stare_f[i]){
                            cout<<"Cuvant acceptat\n";
                            cout<<drum<<"\n";
                            ok = 1;
                            break;
                        }

                    }
                    if (ok == 0)
                        cout<<"Cuvant nu este acceptat\n";
                }
                starecrt = 0;
                drum = std::to_string(starecrt);
                break;
            case 2:
                exit(0);
                break;
        }
    }

    return 0;
}