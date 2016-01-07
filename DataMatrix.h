//
//Created by niuliqiang on 2016.1.7
//

#ifndef DATAMATRIX_H
#define DATAMATRIX_H

#include <vector>

template<typename T>

class DataMatrix{
private:
    unsigned int nrows;
    unsigned int ncols;
    std::vector<std::vector<T>> mat;
public:
    DataMatrix();
    DataMatrix(unsigned int _nrows, unsigned int _ncols);

    unsigned int getCols() const;
    unsigned int getRows() const;

    void add(const std::vector<T>& vec):

    T& operator()(const unsigned& _nows, const unsigned& _ncol);

    unsigned int Size();

   std::vector<T> last();

};

#endif //DATAMATRIX_H
