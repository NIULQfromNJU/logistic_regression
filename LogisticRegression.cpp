//
//
//
#include <iostream>
#include <vector>
#include <cmath>

#include "LogisticRegression.h"
#include "DataMatrix.h"

LogisticRegression::LogisticRegression(){}

LogisticRegression::LogisticRegression(DataMatrix<double> ddata, std::vector<double> iinit, double aalpha):
    data(ddata), init(iinit), alpha(aalpha), nrows(ddata.getRows()), ncols(ddata.getCols()){
    if(init.size() != (ncols-1))
        std::cerr<<"Error!"<<std::endl;
}

void LogisticRegression::fit(){
    std::vector<double> cur = init;
    DataMatrix<double> points(0,ncols-1);
    
    //
    points.add(cur);

    double tol = 1e-9;
    double val;
    double gradients[ncols-1];
    unsigned int t = 0;
    double loss = 0;
    
    //compute gradients
    do{
    	loss = 0;
        for(size_t k=0; k<(ncols-1); k++){
            for(size_t i=0; i<nrows; i++){
		double prob = 1/(1+exp(-(cur[0]*data(i,1) + cur[1]*data(i,2))));
		if(data(i,0)==1){
		    loss += prob;
		}
		else{
		    loss += (1-prob);
		}
                gradients[k] += (((1/(1+exp(-(cur[0]*data(i,1)+cur[1]*data(i,2))))) - data(i,0))*data(i,k+1));
            }
        }

	//std::cout<<"gradients: "<<gradients[0]<<std::endl;
	//std::cout<<"cur loss: "<<-loss<<std::endl;
    
        cur.clear();
    
        //compute new point
        for(size_t i=0; i<(ncols-1); i++){
            val = points(t,i) - (alpha*gradients[i]);
            cur.push_back(val);
            gradients[i] = 0;
        }
    
        points.add(cur);
        t++;
    }while(std::abs(points(t,0)-points(t-1,0)) > tol);

    for(size_t i=0; i<points.getCols(); i++){
        std::cout<<points.last().at(i)<<std::endl;
    }

}
