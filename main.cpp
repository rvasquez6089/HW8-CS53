//Programmer: Ryan Vasquez
//Date, November 4th, 2013
//Class: CS53 section f
//Description: This is main driver file for the program that creates moes fable
#include <iostream>
#include <string>
#include "wordfunctions.h"
#include <fstream>
using namespace std;




int main()
{
    srand(time(NULL));
    char moral[BIGSIZE];
    char originalchar1[SIZE] = {' '};
    char originalchar2[SIZE] = {' '};
    char newchar1[SIZE] = {' '};
    char newchar2[SIZE] = {' '};
    bool newfable = 0;
    ifstream in;
    cout<<"So, Moe, are you ready to create a fable?(1 for yes, 0 for no): ";
    cin>>newfable;
    ofstream ofs;
    ofs.open(FILEOUTPUT);
    while(newfable)
    {
      in.open(FABLE[rand()%5].c_str());
      check_stream(in);

      getmainword(originalchar1, originalchar2, in);
      get_new_subjects(newchar1, newchar2);
      output_title(newchar1, newchar2, ofs);
      output_newstory(originalchar1, originalchar2, newchar1, newchar2,
              ofs, in);
      get_moral(moral);
      output_moral(moral, ofs);
      ofs<<"\n\n\n\n";
      in.close();
      cout<<"So, Moe, are you ready to create another fable?";
      cin>>newfable;
    }
    ofs.close();

    return 0;
}
