#include <bits/stdc++.h>
using namespace std;

void search(string& pat, stinr & txt)
{
    int M = pat.size();
    int N = text.size();

    for (int i = 0; i <= N - M; i++) 
    {
        int j;

        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j== M) 
            cout << "Pattern found at index " << i << endl;
    }
}
int main()
{
    string text;
    string pat;
    cin>>tex;
    cin>>pat
    search(pat, txt);
    return 0;
}