/**
 * A simple implementation of flood fill using a matrix and hash map
 *
 * @author Arsalan Azmi
 * @version 1.0, 12th April 2019
 */

#include <iostream>
#include <string>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;


int main()
{
	//using an unordered_map hash map (C++11)
    unordered_map<string, int> counter;

    //initialized a vector of all colors/elements
    vector<string> colors = {"Red", "Blue", "Green"};

    //initialize the hash map by making count/value of all colors/keys as 1
    for (int i = 0; i < 3; ++i){ 
    	counter[colors.at(i)] = 1;
    }

    //the 2D grid
    vector<vector<string>> boxes = {{"Red", "Red", "Blue", "Red"}, 
                                 {"Red", "Blue", "Green", "Blue"},
                                 {"Red", "Red", "Green", "Green"}};
    
    //aterate through each element in the grid
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
        	//an iterator to find the key-value from our hash map
        	unordered_map<string, int>::iterator iter = counter.find(boxes[i][j]);
            
            //if the element is not the in the last row
            if(j<3){
            	//compare the element right-next to it
                if(boxes[i][j] == boxes[i][j+1]){
                	//increment counter
                	iter->second = iter->second+1; 
                }
            }

            //if the element is not in the last column
            if(i<2){
            	//compare the element below it
                if(boxes[i+1][j] == boxes[i][j]){
                	//increment counter
                	iter->second = iter->second+1;
                }
            }
        }
    }


    int maxAdjacentPairs = 0;
    string maxElement = "";
    
    //loop through all color key-value pairs and set the max values respectively
    for(int i = 0; i < 3; i++){
    	//iterate through each color/element in the string and find the key-value pair from the hash map
    	tr1::unordered_map<string, int>::iterator iter = counter.find(colors.at(i));
        
        //if key value is greater than the maxAdjacentPairs till now
        if(maxAdjacentPairs < iter->second){
            maxAdjacentPairs = iter->second;
            maxElement = iter->first;
        }
        cout << "Element "<<iter->first<<" has adjacent pairs (including itself) "<< iter->second;
        cout << "\n";
    }

    cout << "The max element is " << maxElement << " with adjacent pairs "<<maxAdjacentPairs;
    cout << "\n";
}

