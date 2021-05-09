#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int n;//numero de colunas
int * memo;//altura de piramide maxima gerada por cada coluna
int * heightColumn;//altura maxima de uma coluna

int main()
{
    cin >> n;
    memo = new  int[n];
    memo[0] = memo[n-1] = 1;//primeira e últimas colunas podem apenas gerar uma piramide de tamanho 1
    heightColumn = new int[n];
        
    for (int j = 0; j < n; ++j){
        cin >> heightColumn[j];
    }

    int maxHeight = 1;
    //ignora 0 porque com certeza ela é triangulo de tamanho 1
    for (int j = 1; j < n - 1; ++j)
    {   
        /*
            Para construir um triângulo de tamanho 2, precisa-se de um de tamanho 1 em cada lado
            Para construir um triângulo de tamanho 3, precisa-se de um de tamanho 2 em cada lado
            assim sucessivamente. memo guarda o tamanho maximo do triângulo na posição j
        */
        int minTriangleAdjacent = min(memo[j - 1], heightColumn[j + 1]);
        if(heightColumn[j] > minTriangleAdjacent){
            memo[j] = minTriangleAdjacent + 1;
        }else memo[j] = heightColumn[j];
    }


    for (int j = n - 2; j > 0; --j)
    {   
        /*
            Para construir um triângulo de tamanho 2, precisa-se de um de tamanho 1 em cada lado
            Para construir um triângulo de tamanho 3, precisa-se de um de tamanho 2 em cada lado
            assim sucessivamente. memo guarda o tamanho maximo do triângulo na posição j
        */
        int minTriangleAdjacent = min(memo[j - 1], memo[j + 1]);
        
        if(heightColumn[j] > minTriangleAdjacent){
            memo[j] = minTriangleAdjacent + 1;
        }else memo[j] = heightColumn[j];

        if(memo[j] > maxHeight)
            maxHeight = memo[j];
    }

    cout << maxHeight << endl;


    delete[] memo;
    return EXIT_SUCCESS;
}