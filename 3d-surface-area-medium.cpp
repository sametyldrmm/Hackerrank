#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int surfaceArea(vector<vector<int>> A) {
    int R = A.size();
    int C = A[0].size();

    int front = 0;
    int back = 0;
    int left = 0;
    int right = 0;
    int bottom_top = 2 * R * C;

    int ara_toplam_yatay = 0;
    int ara_toplam_dikey = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (j == 0) {
                front += A[i][j];
            }
            if (j == C - 1) {
                back += A[i][j];
            }
            if (i == 0) {
                right += A[i][j];
            }
            if (i == R - 1) {
                left += A[i][j];
            }
            if (j != C - 1) {
                ara_toplam_yatay += abs(A[i][j] - A[i][j + 1]);
            }
            if (i != R - 1) {
                ara_toplam_dikey += abs(A[i][j] - A[i + 1][j]);
            }
        }
    }

    int alan = bottom_top + front + back + left + right + ara_toplam_yatay + ara_toplam_dikey;
    cout << alan << endl;
    return alan;
}


int main() {
    int R = 5; // Satır sayısı
    int C = 4; // Sütun sayısı

    std::vector<std::vector<int>> A = {
        {1, 3, 4, 2},
        {2, 2, 3, 1},
        {1, 2, 4, 3},
        {2, 3, 4, 1},
        {2, 2, 2, 2}
    };
    surfaceArea(A);
    // Yüzey alanını hesaplama ve sonucu yazdırma

    return 0;
}
