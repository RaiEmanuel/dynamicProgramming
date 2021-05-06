#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    int * array = new int[n];
    
    for(int i = 0; i < n; ++i){
        cout << "Digite o numero ["<<i<<"]: ";
        cin >> array[i];
    }
    int max = array[0];
    for(int i = 1; i < n; ++i){
        int maxIth = std::max(array[i - 1] + array[i], array[i]);
        array[i] = maxIth;
        if(max < maxIth)
            max = maxIth;
    }
    cout << "Maior soma contigua = " << max << endl;
    delete [] array;
    return EXIT_SUCCESS;
}