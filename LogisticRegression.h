//
//Created by nlq
//

#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

#include <vector>
#include "DataMatrix.h"

class LogisticRegression{
private:
    DataMatrix<double> data;
    std::vector<double> init;
    double alpha;
    unsigned int nrows;
    unsigned int ncols;

public:
    LogisticRegression();
    LogisticRegression(DataMatrix<double> data, std::vector<double> init, double alpha);

    void fit();

};

#endif //LOGISTICREGRESSION_H    
