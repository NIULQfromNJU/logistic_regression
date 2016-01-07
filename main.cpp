#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "LogisticRegression.cpp"
#include "DataMatrix.cpp"

const int NROWS = 1000;
const int NCOLS = 3;

int main(){
    std::string lineA;
    std::ifstream fileIN;
    int rowA = 0;
    int colA = 0;
    double val;
   
    DataMatrix<double> data(NROWS, NCOLS);

    fileIN.open("data_logistic.txt");
   
    if(fileIN.fail()){
        std::cerr<<"Cannot open \n"<<std::endl;
        exit(1);
    }

    while(fileIN.good()){
        while(getline(fileIN, lineA)){
            std::istringstream streamA(lineA);
    	    colA = 0;
 	    while(streamA >> val){
  	   	data(rowA, colA) = val;
		colA++;
	    }
	    rowA++;
    	}
    }

    double vv[2] = {2., 3.};
    std::vector<double> inits(&vv[0], &vv[0]+2);

    double alpha = 0.005;
 
    LogisticRegression logisticModel(data, inits, alpha);
 
    logisticModel.fit();
 
    std::cout<<"Work!"<<std::endl;

    return 0;
}
