
/* Hani Aboudeshisha
 HW 1 CSCI  235    Date: 2/12/2013                          main.cpp*/ 

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
#include "Queries.cpp"



void readCSV(istream &input, vector< vector<string> > &output);// definition line: 35

int main()
{      
     char again='y';
     do {                              // a while loop for many entries as needed
        
        ifstream in("muscles.csv");                 // read the file
        if(!in.is_open())
        {
                cout << "File not found!\n";
                return 1;
        }
          
        arrayOfCells csvData;                 // construct the vectore of 2D
        readCSV(in, csvData);                 // read the stream & assign data to a 2D vector of vectors of strings   
        Queries queries(csvData);             // class uses the vector to assign values to variables and search for a query and cout results
        cout<<"do you like to try again?(y/n)";
        cin>>again;
        }while (again=='y' || again=='Y') ;
        
//system ("pause");
return 0;
}
//__________________________________________________________________________________//
void readCSV(istream &input, vector< vector<string> > &output)/// takes astream input and assigns values to vector<vector<string>>
{

       string raw, cell;
          //  vector< vector<string> > arrayOfCells;  // the 2D array///  so arrayOfCells is a vector of vectors that contain strings
       vector<string> v;                // vector of strings values 
        // read every line from the stream
        while ( getline(input,raw) )    // get next line(raw) in file
       {
          v.clear();              
          stringstream ss(raw);
      
          while (getline(ss,cell,','))  // break line into comma delimitted cells
           {
            v.push_back(cell);  // add each cell  to (vector v) ---> vector<string>
           }

          output.push_back(v);  /* add victors of strings to vector of victors<string>//*now the data stord into two dimensional vector
                                    and the data can be accessed by using ArrayOfCells[raw][col or cell]   */
       }
}
//__________________________________________________________________________________//
