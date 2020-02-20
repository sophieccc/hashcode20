#include <iostream>
using namespace std;

int main() {
    int libs[2];
    int scansPerDay[] = {2,1};
    int signUp[] = {2,3};
    int days = 7;
    double avgScore = 3.5;
    double avgScan = 1.5;
    int libBooks[2][5] = {{4,3,2,1,1}, {5,3,2,0}};
    for(int i=0; i < 2; i++) {
        int numberOfBooks = (days-signUp[i]) * scansPerDay[i];
        int ourBooks[numberOfBooks];
        int points = 0;
        for(int j= 0; j< numberOfBooks; j++) {
            ourBooks[j] = libBooks[i][j];
            points+= ourBooks[j];
            libBooks[i][j] = 0;
        }
        points*=scansPerDay[i];
        points -= (avgScore * avgScan) * signUp[i];
        libs[i] = points;
        days = days - signUp[i];
        for (int k= 0; k < numberOfBooks; k++) {
            int currentBook = ourBooks[k];
            for(int m = 0; m < 2; m++) {
                for(int n = 0; n < 5; n++) {
                    if(libBooks[m][n] == currentBook) {
                        libBooks[m][n] = 0;
                    }
                }
            }
        }
    }
    for(int n = 0; n < 2; n++) {
        cout << libs[n] << "\n";
    }
}