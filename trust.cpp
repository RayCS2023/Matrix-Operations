#include <iostream>
#include <cmath>
#include "trust.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::cerr;
using std::ifstream;
using std::stoi;


int main(int, char*[]) {
	  int numNodes;
      string thisChar;
      int current_row = 0;
      //Get number of nodes and set it to numNodes
      cin >> thisChar;
      numNodes = stoi(thisChar);
  
  
      cout << "Number of Nodes: " << numNodes << endl;
  
  
      //Initialize square array of size numNodes to 0
      bool** trust_array = new bool*[numNodes];
      for(int i = 0; i < numNodes; ++i){
          trust_array[i] = new bool[numNodes];
      }
  
  
      for (int i = 0; i < numNodes; i++)
          for (int j = 0; j < numNodes; j++)
              trust_array[i][j] = 0;
      /*
       *For output testing
       *
       for (int row = 0; row <= numNodes - 1; row++){
       for (int col = 0; col <= numNodes - 1; col++){
       cout << trust_array[row][col];
       
       }
       cout << endl;
       }
       */
  
  
      //Make a first run checker
       cin >> current_row;
  
      //While the program can still a string from the input file, keep looping
      while (cin >> thisChar){
          if (thisChar == "0"){
              cin >> thisChar;
              if (thisChar != "0"){
                  current_row = stoi(thisChar);
                      //cout << current_row << endl;
              }
  
          } else {
              trust_array[current_row - 1][stoi(thisChar) - 1] = 1;
          }
  
      }
     arrprint (trust_array,numNodes);
  
  
  
      //--------Now make the Array Reflexive-----------------//
      make_reflexsive(trust_array, numNodes);
  
      //Output of array after setting all diagonal elements to boolean 1
      arrprint (trust_array,numNodes);
  
      //---------------------------------------------------//
      make_transitive(trust_array, numNodes);
  
      arrprint (trust_array,numNodes);
  
      print_result(trust_array, numNodes);
 
    cout << "complete";
    return 0;
}


void arrprint(bool **trust_array,int numNodes){
    cout << "Resulting Array: " << endl;
    for (int row = 0; row <= numNodes - 1; row++){
        for (int col = 0; col <= numNodes - 1; col++){
            cout << trust_array[row][col];

        }
        cout << endl;
    }
}

void make_reflexsive(bool **trust_array,int numNodes){
    for (int row = 1; row <= numNodes ; row++){
        int col = row;

        trust_array[row-1][col-1] = 1;
    }
}


void make_transitive(bool **trust_array,int numNodes){
	for (int k = 1; k <= numNodes; k++){
		for(int row = 1; row <= numNodes; row++){
			for(int col = 1; col <= numNodes; col++){
				if(trust_array[row-1][k-1] == 1 && trust_array[k-1][col-1] == 1){
					trust_array[row-1][col-1] = 1;
				}
			}
		}
	}
}

void print_result(bool **trust_array, int numNodes){	
	int nodefound[numNodes];		
	
	for(int row = 1; row <= numNodes; row++){
		if (nodefound[row-1] != 1){
			cout << "{" << row;
			for (int nextrow = row + 1; nextrow <= numNodes; nextrow++){
				bool equlvalent = true;
				for(int col = 1; col <= numNodes; col++){
					if(trust_array[row-1][col-1] != trust_array[nextrow-1][col-1]){
						equlvalent = false;
					}
				}
				if(equlvalent == true){
					cout << "," << nextrow;
					nodefound[nextrow - 1] = 1;						
				}	
			}
			cout << "}" << endl;
		}
	}
}

