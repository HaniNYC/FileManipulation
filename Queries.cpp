#include <iostream>
#include "Queries.h"

using namespace std;

Queries::Queries(arrayOfCells csvData)// takes a user choice and calls other functions to execute
{
      int column_index;
      cout << "What type do you want to find?" << endl
           << "(0) Diagnostic query" << endl// search a muscle name for location pain
           //<<"(1) Finding muscles associated with one origin  // not included, but easy to construct
           //<<"(2)Finding all muscles of one type              //not included, but easy to construct
           << "(3) Strengthen query" << endl//search location(3)
           << "(4) Action query" << endl;// search action (4)//double substrings search

      cin >> column_index;
      nodeOfFunctions(column_index, csvData);
}
/*        ============================================================                               */
 void Queries::nodeOfFunctions(int x,arrayOfCells csvData)// pass the vector<vector<string>> to the proper function
 {
      if(x==0)
             {
                   functionDiagnostic( csvData);
             }
              else if (x==3) 
              { 
                   functionStringthen(csvData);
              }
              else if (x==4)
              {
                   cout<< "Please Enter an Action and a Body Part or Area(ie:flex neck, or close jaw,... "<<endl;
                   string ActionPart;/// we can use to_lower to convert any upper case words// but it is not requierd in this assigment
                   cin>> ActionPart;
                   functionAction(csvData);                 
              }
              else 
              {
                   cout<<"Error .";
                   
              }
 }  
 /*                 ======================================                               */
void Queries::functionAction(arrayOfCells csvData)
{
           int counter=1;
           string  searchThisAction;// to get the search statement from user
           string   actionVerb;   // will be assigned the first substring(the action)
           string   organType;    // will be assigned the second substring (the body part)        
           getline(cin,searchThisAction );
           /* Now, we will seperate the string entered into to substrings, the first ends by the space sign,
           and the second will begin at the char after space..assigning each word to a differnt substrings*/
           actionVerb=searchThisAction.substr( 0, searchThisAction.find_first_of( " \t" ) ) ;
           organType=searchThisAction.substr(searchThisAction.find_first_of( " \t" )+1 )  ;
          /* now we will search for those two subwords in the column 4(Actions), both must be exist at the same cell 
           in order to be valid. I am using (found-find method) two times in nested if.
           if both substring exist at the same cell then we cout cell[i][0]  where column 0 coressponds to muscles names.
           or object name or any other data  */
           for (size_t i=0; i<csvData.size(); ++i)
            {       
                    unsigned found =csvData[i][4].find(actionVerb);
                    if (found!=std::string::npos)  
                      {                               
                         found =csvData[i][4] .find(organType);
                          if (found!=std::string::npos)
                            { 
                              counter++,                          
                              name= csvData[i][0];                                             
                              cout<<"the "<<name<<" muscle is involved "<<endl;         
                            }      
                       }                                                                    
            }
            if(counter==1)   // if counter has not change, then nothing found.
            {
             cout<<" NotFound."<<endl;             
            }
}
/*              =====================================================================                            */
 void  Queries::functionDiagnostic(arrayOfCells csvData)// user input muscle name, then search for match in col [0],if found ;cout location +pain
 {
         int counter=1; 
         cout << "What is the muscle name ? " << std::endl;
         string muscleName;
         int column_index=0;
         cin >> muscleName;

        for(size_t i = 0; i < csvData.size(); ++i)////
           {
             if(csvData[i][column_index] == muscleName)///if search successes finding the word
             {  
                  counter++;
                  type= csvData[i][column_index+2];    // assign needed values to an object in the class 
                  location=origin=csvData[i][column_index+3];  
                  cout<< "possible "<< type <<" "<<location<<" pain . ";                   
             }                 
           } 
          if (counter==1)
          {  
                 cout<<"Not Found. ";
          }
}
/*         =================================================                                 */

 void Queries::functionStringthen(arrayOfCells csvData)// strengthen a location, search for corresponding muscles to strengthen an area
  {
     
         cout << "What area do you like to strengthen ? " << std::endl;
         string locationName;
         int column_index=3;
         int counter=1;
         cin >> locationName;
         cout<<"work on the following muscles : ";
         for(size_t i = 0; i < csvData.size(); ++i)
           {
             if(csvData[i][column_index] == locationName)
             {    
                  counter++;                     
                  name=csvData[i][column_index-3]; // assign object name a value  from vector
                  cout<< name<<",";                   
             }                                         
           }  
         if(counter==1)
           {
                  cout<<" Not Found . "<<endl;
           }
}  
////////////////////////////////////////////////End//////////////////////////////////////////////////////////////////////////////
