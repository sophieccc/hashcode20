#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

struct Library {
  long id;
  double score;
  long numBooks;
  long scansPerDay;
  long signUpDays;
  vector<long> books;
  vector<long> scannedBooks;
  bool used;
  int sum;
};

long averageScore = 0;
long averageScansPerDay = 0;
vector<long> usedLibraries;

void printArray(long a[], int l) {
    for(int i=0; i<l; i++) {
        cout << a[i] << endl;
    }
    cout << endl;
}

int getMaxIndex(long bookScores[], int below, int n) {
    int res = -1;
    int max = -1;
    for(int i=0; i < n; i++) {
        if(bookScores[i] > max && bookScores[i] < below) {
            max = bookScores[i];
            res = i;
        }
    }
    return res;
}

void sortOrder(long bookOrder[], long bookScores[], int n) {
    int max = INT_MAX;
    for(int i=0; i<n; i++) {
        bookOrder[i] = getMaxIndex(bookScores, max, n);
        max = bookScores[bookOrder[i]];
    }
}

//calculating the score for each library 
void calcLibraryScore(Library & l, long days, long bookScores[], long bookOrder[], long totalBooks) {
  l.scannedBooks.clear();
  long maxBooks = (days - l.signUpDays) * (l.scansPerDay);
  long count = 0;
  double sum = 0;
  for(int i = 0; i < l.numBooks && count < maxBooks; i++) {
    if(bookScores[bookOrder[i]]!=-1) {
      long temp = l.books.at(i);
      l.scannedBooks.push_back(temp);
      count++;
      sum += bookScores[bookOrder[i]];
    }
  }
  sum *= l.scansPerDay;
  sum -= averageScore * averageScansPerDay * l.signUpDays;
  l.score = sum;
}

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
  
  ifstream file("eee.txt");
  ofstream outputFile;
  outputFile.open("output6.txt");
  
  //Read in file data
  file >> totalBooks >> totalLibraries >> totalDays;
  
  long bookScores[totalBooks];
  long bookOrder[totalBooks];
  
  for(long i = 0; i < totalBooks; i++) {
    file >> bookScores[i];
    averageScore += bookScores[i];
    bookOrder[i] = i;
  }
  
  //find average score of books
  averageScore /= totalBooks;
  
  
  //add data into a library object and then add library to a hashmap
  for(long i = 0; i < totalLibraries; i++) {
    Library lib;
    file >> lib.numBooks;
    file >> lib.signUpDays;
    file >> lib.scansPerDay;
    averageScansPerDay += lib.scansPerDay;
    lib.used = false;
    for(long i = 0; i < lib.numBooks; i++) {
      long bookId;
      file >> bookId;
      lib.books.push_back(bookId);
    }
    lib.sum = 0;
    libraryList.insert(make_pair(i, lib));
  }
  
  averageScansPerDay /= totalLibraries;
  
  long usedLibraryCounter;

  //sort the books by their score
  //quickSort(bookOrder, bookScores, 0, totalBooks-1);
  /*printArray(bookOrder, totalBooks);
    cout << "first try done" << endl;
  sortOrder(bookOrder, bookScores, totalBooks);
  printArray(bookOrder, totalBooks);
    cout << "second try done" << endl;*/
  //calculates max scores based on library scores
  
for(int h = 0; h < totalBooks; h++) {
    int count = 0;
    long maxBooks = (totalDays - libraryList[h].signUpDays) * (libraryList[h].scansPerDay);
    for(int m = 0; m < libraryList[h].numBooks && count < maxBooks; m++) {
    long temp = libraryList[h].books[m];
    libraryList[h].scannedBooks.push_back(temp);
    libraryList[h].sum += bookScores[temp];
    count++;
    }
}

  for(long i = 0; totalDays > 0 && i < totalLibraries; i++) {
    if(libraryList[i].signUpDays > 100 || libraryList[i].scansPerDay < 2) {
      continue;
    }
    //calculate the score for each library
    /*for(int j = 0; j < totalLibraries && i < 1; j++) {
      if( !libraryList[j].used) {
          cout << "calculating lib score " << j << endl;
      calcLibraryScore(libraryList[j], totalDays, bookScores, bookOrder, totalBooks);
      }
    }*/


  /* double maxScore = INT_MIN;
    long index = -1;
    for(long k = 0; k < totalLibraries; k++) {
      if(!libraryList[k].used && libraryList[k].score > maxScore) {
        maxScore = libraryList[k].score;
        index = k;
      }
    }
    cout << "try " << i << endl;
    cout << "biggest score is  " << maxScore << " from lib " << index << endl;
    if(index!=-1) {
    usedLibraries.push_back(index);
    libraryList[index].used = true;
    usedLibraryCounter++;
    }
    else {
      break;
    }*/




    usedLibraries.push_back(i);
    libraryList[i].used = true;
    usedLibraryCounter++;
    
    totalDays = totalDays - libraryList[i].signUpDays;
  }
  outputFile << usedLibraryCounter << endl;
  for(long i = 0; i < usedLibraryCounter; i++) {
    outputFile << usedLibraries[i] << " " << libraryList[usedLibraries[i]].scannedBooks.size() << endl;
    for(long j = 0; j < libraryList[usedLibraries[i]].scannedBooks.size(); j++) {
      outputFile << libraryList[usedLibraries[i]].scannedBooks[j] << " ";
    }
    outputFile << endl;
  }
  
    
}