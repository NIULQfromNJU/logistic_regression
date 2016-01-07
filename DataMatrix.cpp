//
//Created by nlq
//

#include <vector>
#include "DataMatrix.h"

template <typename T>
DataMatrix<T>::DataMatrix(){
    mat.resize(1);
    mat[0].resize(1);
}

template <typename T>
DataMatrix<T>::DataMatrix(unsigned int _nrows, unsigned int _ncols){
    mat.resize(_nrows);
    for(size_t i=0; i<mat.size(); i++){
        mat[i].resize(_ncols);
    }
    nrows = _nrows;
    ncols = _ncols;
}

template <typename T>
unsigned int DataMatrix<T>::getCols() const{
    return ncols;
}

template <typename T>
unsigned int DataMatrix<T>::getRows() const{
    return nrows;
}

template <typename T>
void DataMatrix<T>::add(const std::vector<T> &vec){
    mat.push_back(vec);
    nrows++;
}

template <typename T>
T& DataMatrix<T>::operator()(const unsigned & _nrow, const unsigned & _ncol){
    return mat[_nrow][_ncol];
}

template <typename T>
unsigned int DataMatrix<T>::Size(){
    return mat.size();
}

template <typename T>
std::vector<T> DataMatrix<T>::last(){
    return mat[nrows-1];
}
