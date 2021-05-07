#include <iostream>
#include <climits>
#include <algorithm>


#define INFINITYDP 9223372036854775807;
using namespace std;

int nTubes, heightMainTube;//numero moedas, valor a ser trocado
long long int **memo;
int * heightTubes, * valueTubes;


long long int result(const int choosedTube, const int lackHeight)//moeda escolhida atualmente, valor que falta trocar
{
    if(choosedTube == nTubes && lackHeight > 0){
        return 0;
    }else if(choosedTube == nTubes && lackHeight == 0){
        return 0;
    }else if(lackHeight < 0)
        return -INFINITYDP;

    if(memo[choosedTube][lackHeight] == -1){
        //escolhe o minimo entre pegar a mesma moeda e desconta ou partir a analise para a proxima moeda
        
        long long int getValueTube = valueTubes[choosedTube] + result(choosedTube, lackHeight - heightTubes[choosedTube]);
        
        long long int notGetTube = result(choosedTube + 1, lackHeight);
        
        memo[choosedTube][lackHeight] = max(getValueTube, notGetTube);
        return memo[choosedTube][lackHeight];
    }else return memo[choosedTube][lackHeight];
}

int main()
{    
    cin >> nTubes >> heightMainTube;
    /*
    6 80 1 5 10 25 50 100
    */
    heightTubes = new int [nTubes];
    valueTubes = new int [nTubes];
    memo = new long long int * [nTubes];
    for (int i = 0; i < nTubes; i++)
    {
        cin >> heightTubes[i] >> valueTubes[i];
        memo[i] = new long long int[heightMainTube + 1];
        for (int j = 0; j < heightMainTube + 1; ++j){
            memo[i][j] = -1;
        }
    }
    
    long long int gain = result(0, heightMainTube);
    cout << gain << endl;
  
    delete [] valueTubes;
    delete [] heightTubes;
    delete [] memo;
    return EXIT_SUCCESS;
}