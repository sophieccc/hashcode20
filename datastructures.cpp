#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Library {
  long id;
  double score;
  long numBooks;
  long scansPerDay;
  long signUpDays;
  vector<long> books;
};

int main() {
  long totalBooks;
  long totalLibraries;
  long totalDays;
  
  ifstream file("a_example.txt");
  
  //Read in file data
  file >> totalBooks >> totalLibraries >> totalDays;
  
  long bookScores[totalBooks];
  long bookOrder[totalBooks];
  
  for(int i = 0; i < totalBooks; i++) {
    file >> bookScores[i];
    bookOrder[i] = i;
  }
  
    
}