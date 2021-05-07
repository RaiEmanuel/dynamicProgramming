#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

int **stateMatrix;
int *weightObject, *valueObject;

int knaspsack(const int choosedElement, const int n, const int choosedWeight)
{
    //cout << "analisando " << choosedElement << " e " << choosedWeight << endl;
    if (choosedWeight < 0 )
        return INT_MIN;
    else if(choosedElement >= n)
        return 0;
    if (stateMatrix[choosedElement][choosedWeight] == -1)
    {
        int get = valueObject[choosedElement] + knaspsack(choosedElement + 1, n, choosedWeight - weightObject[choosedElement]);
        int notGet = knaspsack(choosedElement + 1, n, choosedWeight);
        stateMatrix[choosedElement][choosedWeight] = max(get, notGet);
        //cout << "return= " << stateMatrix[choosedElement][choosedWeight] << endl;
        return stateMatrix[choosedElement][choosedWeight];
    }
    else
    {
        //cout << "return= " << stateMatrix[choosedElement][choosedWeight] << endl;
        return stateMatrix[choosedElement][choosedWeight];
    }
}

int main()
{
    //solution accepted by spoj
    //https://www.spoj.com/problems/KNAPSACK/
    int n, totalWeight;
    
    //cout << "Digiteo o peso maximo da mochila: ";
    cin >> totalWeight;
    //cout << "Digite a quantidade de objetos: ";
    cin >> n;
    weightObject = new int[n],
        valueObject = new int[n];

    //matriz de estados
    stateMatrix = new int *[n];

    for (int i = 0; i < n; ++i)
    {
        //cout << "Digite o peso do objeto [" << i << "]: ";
        cin >> weightObject[i];
        //cout << "Digite o valor do objeto [" << i << "]: ";
        cin >> valueObject[i];
        stateMatrix[i] = new int[totalWeight + 1];
        //-1 significa que o elemento não foi calculado ainda
        for (int j = 0; j < totalWeight + 1; ++j)
        {

            if (j == 0)
            {
                //cout << i << " e " << j << " = 0" << endl;
                stateMatrix[i][j] = 0;
            }
            else
            {
                //cout << i << " e " << j << " = -1" << endl;
                stateMatrix[i][j] = -1;
            }
            
        }
    }

    //cout << "...";
    int maxValue = knaspsack(0, n, totalWeight);
    cout << maxValue << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < totalWeight + 1; ++j)
        {
            //cout << stateMatrix[i][j] << '\t';
        }
            //cout << endl;
    }

    

    delete[] weightObject;
    delete[] valueObject;
    return EXIT_SUCCESS;
}