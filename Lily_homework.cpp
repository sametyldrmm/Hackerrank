#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> lilysHomework(vector<int> arr)
{
    int size = arr.size();
    int adimSayisi = 0;

    vector<int> siraliDizi = arr;
    // BÜYÜKTEN KÜÇÜĞE SIRALAMA
    sort(siraliDizi.begin(), siraliDizi.end(), greater<int>());

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != siraliDizi[i])
        {
            swap(arr[i], arr[distance(arr.begin(), find(arr.begin(), arr.end(), siraliDizi[i]))]);
            adimSayisi++;
        }
    }

    cout << "Adim sayisi: " << adimSayisi << endl;
    return (arr);
}

int main()
{
    int n = 5;                              // Dizinin boyutu
    std::vector<int> arr = {3, 4, 2, 5, 1}; // Sıralanmamış tam sayı dizisi

    // Giriş değerlerini ekrana yazdırma (opsiyonel)
    std::cout << "Dizinin boyutu: " << n << std::endl;
    std::cout << "Dizi elemanları: ";

    // Lily'nin yapması gereken adım sayısını hesaplama
    arr = lilysHomework(arr);
    // Adım hesaplama kodu buraya gelecek

    // Sonucu ekrana yazdırma
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


// testlerin 3 tanesini geçemedik :(
// doğru cevaba bakıp hatamızı tespit ettik daha sonra dönmek adına bunu böyle bıraktık

