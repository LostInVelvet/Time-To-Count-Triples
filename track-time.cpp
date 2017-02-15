#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void CreateList(int list[], const int numInts);
int CountTriples(int list[], const int numInts);
void PrintResults(int numInts, int numTriples, float timeTaken);

int main(){
  int triples;
  float timeTaken;
  clock_t start;
  clock_t end;
  
  
  srand(time(NULL));
//  srand(1);
  // A list will be created starting with 250 ints and doubling in size
  for(int numInts = 250; numInts <= 16000; numInts = numInts*2){
    int list[numInts];
    CreateList(list, numInts);
 
    
    start = clock();
    triples = CountTriples(list, numInts);
    end = clock();

    // Gets the time taken by getting the number of clocks taken by the processor
    // then dividing it by the clocks per second the processor takes
    timeTaken = (float(end-start))/CLOCKS_PER_SEC;
    
    PrintResults(numInts, triples, timeTaken);
  }

  return 0;
}



// Fills a list with a designated amount of random numbers
// Pre: The number of numbers desired is specified.
// Post: The array list[] will be filled with the designated amount of numbers.
void CreateList(int list[], const int numInts){
  for(int i = 0; i<numInts; i++){
    list[i] = rand() % 2000002 - 1000001;
  }    
}



// Counts the triples in the list
// Pre: The array list[] is filled with integers
// Post: Returns the number of triples
int CountTriples(int list[], const int numInts){
  int numTriples = 0;
//  int t = 0;		// For testing triple sum values

  for(int i = 0; i < numInts; i++){
    for(int j = i+1; j<numInts; j++){
      for(int k = j+1; k<numInts; k++){
        if(list[i] + list[j] + list[k] == 0){
          numTriples = numTriples+1;
          
          // Tests if the triples sum to 0
/*          if(t < 5)
            cout << endl << list[i] << " + " << list[j] << " + " << list[k] << " = " << (list[i] + list[j] + list[k]); 
          t++;*/
        }
      }
    }
  }
  return numTriples;
}



// Pre: the number of triples has been found and the time taken has been recorded
// Post: Size of the list, number of triples, and elapsed time is outputted to the screen
void PrintResults(int numInts, int numTriples, float timeTaken){
  cout << endl << endl
       << "Size of the list:\t" << numInts << endl
       << "Numer of triples:\t" << numTriples << endl
       << "Elapsed time:\t\t" << timeTaken << " seconds" << endl
       << endl;
  
}