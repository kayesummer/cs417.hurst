//
// File:	multidvec.cpp
// Author:	Adam.Lewis@athens.edu
// Purpose:
// Demo use of vectors to build multi-d array
//

#include <iostream>
#include <vector>

using namespace std;

main()
{
   vector< vector< vector<int> > > vI3Matrix(2, vector< vector<int> > (3, vector<int>(4,0)) );

   for(int kk=0; kk<4; kk++)
   {
      for(int jj=0; jj<3; jj++)
      {
         for(int ii=0; ii<2; ii++)
         {
            cout << vI3Matrix[ii][jj][kk] << endl;
         }
      }
   }
}