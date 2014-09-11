

/* Hani Aboudeshisha
 HW 1 CSCI  235    Date: 2/12/2013               Queries.h*/ 

/*DESCRIPTION:  
            the program reads CSV file and ask the user to choose between three quries :
                - Action query : return muscle responsible for an action.. user can just enter a part of words like" compr abd" instead of
                  "compresses abdomen". If action is not found,it cout that and asks if you need to try again.
                - Strengthen query: returns muscle(s) you need to work on
                - Diagnostic query: returns possible area pain related to  a muscle .
                + After you done, you will be offered to try another search */
/* METHODOLOGY: 
                This program will get information from a CSV "comma seperated values" file 
and  will assign it to typedefined vector<vector<string>> as a 2D vector of vectors represnting a table with cells each cell 
represented by Vector[raw][column] and contains only one string- this done by a global function that reads the stream and populates the 2D vec-.
#A class " Queriers" contains strings for names,actions,types,origins and locations and four public functions and a constructor.
Assigning data to variables in the class will be done through three functions representing the three possible queries
and they will be passed the variable througth an assigning function that is called by the constructor  
//constructor creats an object, calls the assigning function which then calls the proper function to assign values to variables 
in the class of that object.//
#Searching is done across one column and multiple raws.In query "Action", I have used (find-found) technique two times to search 
for both words (strings)in one cell. To find just a part of a string,I've used {string.find(substr)} method. 
ie; if user enter " comp abd " it will return true for "compresses abdomen"  
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>


using namespace std;
//---------------------------///

typedef vector< vector<string> > arrayOfCells;     // defining a class of vector of vectors of strings representing the cells in the csv file

class Queries       ///  class contains the private data and four public functions and one constructor
{                           
public:
     Queries(arrayOfCells csvData);     //                
     void  nodeOfFunctions(int x,arrayOfCells csvData);// will assign your query to the proper function
     void  functionDiagnostic(arrayOfCells csvData);  // will cout the possible pain in an area caused by a muscle      
     void  functionStringthen(arrayOfCells csvData);  // will cout the muscl(s) need to practice on to strengthen an area
     void  functionAction(arrayOfCells csvData);      // eill cout the muscle (s) responsible for an action.
     
private:
     string name;
     string origin;
     string location;
     string action;
     string type;
};
