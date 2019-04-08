// This program reads floating point data from a data file and places those
// values into the private data member called values (a floating point array)
// of the FloatList class. Those values are then printed to the screen.
// The input is done by a member function called GetList. The output 
// is done by a member function called PrintList.  The amount of data read in
// is stored in the private data member called length.  The member function
// GetList is called first so that length can be initialized to zero.

// Beatrix House
  
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// MAX_LENGTH contains the maximum length of our list
const int MAX_LENGTH = 50; 

// Declares a class that contains an array of floating point numbers
class FloatList            
{
    
    private:
        // Holds the number of elements in the array
	    int length;      
	    
	      // The array of values
    	float values[MAX_LENGTH];
	
	
    public:
        // Member function that gets data from a file
    	void getList(ifstream&);   
    	
    	// Member function that prints data from that file to the screen.
    	void printList() const;  
    	
    	// Member function that calculates and prints the average.
    	void getAverage();  
    	
    	// constructor that sets length to 0.  
    	FloatList(); 
    	
    	// destructor 
    	~FloatList();			                           
};

int main()
{
    // Defines a data file
   ifstream tempData;   

   // Fill in the code to define an object called list of the class FloatList
   FloatList list;

   cout << fixed << showpoint;
   cout << setprecision(2);

   tempData.open("temperatures.txt");

   
   // Fill in the code that calls the getList function.
   list.getList(tempData);
   
   // Fill in the code that calls the printList function.
   list.printList();
   
   // Fill in the code that computes the average.
   list.getAverage();

return 0;
}



 FloatList::FloatList()
 {
	// Fill in the code to complete this constructor that
	// sets the private data member length to 0
	length = 0;
 }

// Fill in the entire code for the  getList function
// The getList function reads the data values from a data file
// into the values array of the class FloatList
void FloatList::getList(ifstream& inputFile)
{
    float num;
    
    while (inputFile.good())
    {
        inputFile >> num;
        values[length++] = num;
    }
}

// Fill in the entire code for the  printList function
// The printList function prints to the screen the data in 
// the values array of the class FloatList
void FloatList::printList() const
{
    for (int i = 0; i < length; i++)
    {
        cout << values[i] << endl;
    }
}

// Computes the average
void FloatList::getAverage()
{
    float sum = 0;
    
    for (int i = 0; i < length; i++)
    {
        sum += values[i];
    }
    
    cout << "The average temperature is " << sum / length << endl;
}

// Fill in the code for the implementation of the destructor
FloatList::~FloatList(){};