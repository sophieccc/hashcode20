#include <iostream>
using namespace std;

int numberOfUsedLibraries = 0;

int main() {
    int libs[2];
    int usedLibraries[sizeof(libs)/sizeof(*libs)];
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
        if(points==0) {
            libs[i] = INT_MIN;
            break;
        }
        points*=scansPerDay[i];
        points -= (avgScore * avgScan) * signUp[i];
        libs[i] = points;
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
    days = 7;
    for(int i = 0; i < sizeof(libs)/sizeof(*libs) && days>0; i++) {
        int currLibScore = -10000;
        int index = -1;
        for(int j=0; j < sizeof(libs)/sizeof(*libs); j++) {
            if (libs[j]  > currLibScore) {
                currLibScore = libs[j];
                index = j;
            }
        }
        libs[index] = -10000;
        usedLibraries[i] = index;
        days -= signUp[index];
        numberOfUsedLibraries++;
    }

    cout << numberOfUsedLibraries << endl;
    for(int i=0; i < numberOfUsedLibraries; i++) {
        cout << usedLibraries[i] << " ";
    }
    cout << endl;
}