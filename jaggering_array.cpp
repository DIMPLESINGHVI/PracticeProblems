// A jagged array is an array of arrays such that member arrays can be of different sizes, 
// in 2D array terms for each row we can have a variable number of columns. 
//These types of arrays are also known as Jagged arrays. 

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n; //enter the size of the row of the 2D array
    
    int** arr = new int* [n]; // creation of 2D array 
    int* size = new int[n]; // creation of the size array for variable length of the columns
    for(int i=0;i<n;i++)
    {
        cin>>size[i];      //input values for size
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[size[i]];    //creation of a 2D array with variable length of the columns for each row
    }

    for (int i=0;i<n;i++)
    {
        for(int j=0;j<size[i];j++)
        {
            cin>> arr[i][j];                   //input values
        }
    }
    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<size[i];j++)
        {
            cout<< arr[i][j]<<" ";            // display values
        }
        cout<<"\n";
    }
    
    return 0;
}


// input : n=3
// size[] : {2,3,4}
// O/P : 1 2
//       3 4 5
//       6 7 8 9
