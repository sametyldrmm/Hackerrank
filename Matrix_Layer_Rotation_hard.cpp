#include <bits/stdc++.h>

using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r)
{
    // en dış katmanı alma
    int m = matrix.size();
    int n = matrix[0].size();
    int katmanSayisi = min(m, n) / 2;
    int katman_eksiltme = 2;
    int katmanElemanSayisi = 2 * (m + n - katman_eksiltme);


    vector<int> katman;
    vector<vector<int>> katmanlar;
    for (size_t i = 0; i < katmanSayisi; i++)
    {
        katman.clear();
        for(size_t j = i; j < n - i; j++)
        {
            katman.push_back(matrix[i][j]); // üst yatay
        }
        // sağ dikey
        for(size_t j = i +1; j < m - i; j++)
        {
            katman.push_back(matrix[j][n - i - 1]);
        }
        // alt yatay
        for(size_t j = n - i -1; j > i; j--)
        {
            katman.push_back(matrix[m - i - 1][j - 1]);
        }
        // sol dikey
        for(size_t j = m - i -1; j -1 > i; j--)
        {
            katman.push_back(matrix[j - 1][i]);
        }
        katmanlar.push_back(katman);
    }


    // katmanları döndürme
    for (size_t i = 0; i < katmanlar.size(); i++)
    {
        int katmanElemanSayisi = katmanlar[i].size();
        int donmeSayisi = r % katmanElemanSayisi;
        for (size_t j = 0; j < donmeSayisi; j++)
        {
            int temp = katmanlar[i][0];
            katmanlar[i].erase(katmanlar[i].begin());
            katmanlar[i].push_back(temp);
        }
    }
    // tüm kaatmanları yazdır
    // for (size_t i = 0; i < katmanlar.size(); i++)
    // {
    //     for (size_t j = 0; j < katmanlar[i].size(); j++)
    //     {
    //         cout << katmanlar[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // dönüştürülmüş katmanları yerine yerleştirme

    for (size_t i = 0; i < katmanlar.size() ; i++)
    {
        int katmanElemanSayisi = katmanlar[i].size();
        int katmanIndex = 0;
        for(size_t j = i; j < n - i; j++)
        {
            matrix[i][j] = katmanlar[i][katmanIndex]; // üst yatay
            katmanIndex++;
        }
        // sağ dikey
        for(size_t j = i +1; j < m - i; j++)
        {
            matrix[j][n - i - 1] = katmanlar[i][katmanIndex];
            katmanIndex++;
        }
        // alt yatay
        for(size_t j = n - i -1; j > i; j--)
        {
            matrix[m - i - 1][j - 1] = katmanlar[i][katmanIndex];
            katmanIndex++;
        }
        // sol dikey
        for(size_t j = m - i -1; j -1 > i; j--)
        {
            matrix[j - 1][i] = katmanlar[i][katmanIndex];
            katmanIndex++; 
        }
    }
    // matrixi yazdırma

    for(size_t i = 0; i < m; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> abc;
    abc.push_back({1, 2, 3, 4});
    abc.push_back({5, 6, 7, 8});
    abc.push_back({9, 10, 11, 12});
    abc.push_back({13, 14, 15, 16});
    matrixRotation(abc, 1);
}
