#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

#define INFINITYDP 9223372036854775807;
using namespace std;
long long mod = 1000000007L;
int t, m, n;
int qtLevel;
long long int **memo;

long long int result(const int chooserMinute, const int choosedLevel) //moeda escolhida atualmente, valor que falta trocar
{
    //cout << "analise minuto = " << chooserMinute << " e level = " << choosedLevel << endl;
    //casos base
    if (choosedLevel >= qtLevel || choosedLevel < 0 || chooserMinute >= t) return 0;
    if (memo[chooserMinute][choosedLevel] == -1)
    {
        //tempo sempre aumenta
        //nivel pode subir ou descer
        int possibilityDown = result(chooserMinute + 1, choosedLevel - 1);
        int possibilityUp = result(chooserMinute + 1, choosedLevel + 1);
        //extrapolou os níveis possíveis
        if (possibilityDown + possibilityUp == 0)
            memo[chooserMinute][choosedLevel] = 1;
        else
            memo[chooserMinute][choosedLevel] = (possibilityDown + possibilityUp) % mod;
        return memo[chooserMinute][choosedLevel];
    }
    else
        return memo[chooserMinute][choosedLevel];
}

int main()
{
    cin >> t >> m >> n;
    /*
    6 80 1 5 10 25 50 100
    */
    qtLevel = n - m + 1; //quantidade de níveis possíveis
    memo = new long long int *[t];
    for (int i = 0; i < t; i++)
    {
        memo[i] = new long long int[qtLevel];
        for (int j = 0; j < qtLevel; ++j)
        {
            memo[i][j] = -1;
            if(i == t - 1) memo[i][j] = 1;
        }
    }

    /*for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < qtLevel; ++j)
        {
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }*/

    long long int count = 0;
    for (int i = 0; i < qtLevel; i++)
    {
        count = (count + result(0, i)) % mod;
    }
    cout << count << endl;

    /*for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < qtLevel; ++j)
        {
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }*/

    for (int i = 0; i < t; ++i)
    {
        delete[] memo[i];
    }

    delete[] memo;
    return EXIT_SUCCESS;
}