#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct Library {
  long id;
  double score;
  long numBooks;
  long scansPerDay;
  long signUpDays;
  vector<long> books;
};

// A utility function to swap two elements 
void swap(long* a, long* b) 
{ 
    long t = *a; 
    *a = *b; 
    *b = t; 
} 

long partition (long bookOrder[], long bookScore[], long low, long high) 
{ 
    long pivot = bookOrder[bookScore[high]];    // pivot 
    long i = (low - 1);  // Index of smaller element 
  
    for (long j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (bookOrder[bookScore[j]] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&bookOrder[i], &bookOrder[j]); 
        } 
    } 
    swap(&bookOrder[i + 1], &bookOrder[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 bookOrder[] --> bookOrderay to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(long bookOrder[], long bookScore[], long low, long high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, bookOrder[p] is now 
           at right place */
        long pi = partition(bookOrder, bookScore, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(bookOrder, bookScore, low, pi - 1); 
        quickSort(bookOrder, bookScore, pi + 1, high); 
    } 
} 



int main() {
  long totalBooks;
  long totalLibraries;
  long totalDays;
  map<long, Library> libraryList;
  
  ifstream file("a_example.txt");
  
  //Read in file data
  file >> totalBooks >> totalLibraries >> totalDays;
  
  long bookScores[totalBooks];
  long bookOrder[totalBooks];
  
  for(long i = 0; i < totalBooks; i++) {
    file >> bookScores[i];
    bookOrder[i] = i;
  }
  
  quickSort(bookOrder, bookScores, 0, totalBooks-1);
  
  for(long i = 0; i < totalLibraries; i++) {
    Library lib;
    file >> lib.numBooks;
    file >> lib.signUpDays;
    file >> lib.scansPerDay;
    for(long i = 0; i < lib.numBooks; i++) {
      long bookId;
      file >> bookId;
      lib.books.push_back(bookId);
    }
    libraryList.insert(make_pair(i, lib));
  }
  
    
}