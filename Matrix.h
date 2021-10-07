#include <iostream>
#include <cstddef>
#include <cassert>

#ifndef MATRIX_H
#define MATRIX_H

template <class T> class Matrix
{
    private:
        int n_row, n_col;
        T* matrix_elements;

    public:
        Matrix(int n, int m)
        {
            n_row = n , n_col = m;
            matrix_elements = (n_row == 0 || n_col == 0) ? nullptr : (new T [n_row * n_col]);
        };
        Matrix(int n) {Matrix(n, n);};
        Matrix() {Matrix(0);};
        ~Matrix();
        int row();
        int column();
        T& element (const int &, const int &);
        bool is_square();
        Matrix<T> operator * (Matrix<T> &);
};

template <class T> class ColVector: public Matrix<T>
{
    public:
        ColVector(int n): Matrix<T>(n, 1) {};
        int size();
        T& element (const int &);
        T operator * (ColVector<T> &);
        using Matrix<T>::operator *;
};

template <class T> class RowVector: public Matrix<T>
{
    public:
        RowVector(int n): Matrix<T>(1, n) {};
        int size();
        T& element (const int &);
        T operator * (RowVector<T> &);
        T operator * (ColVector<T> &);
};

template <class T> Matrix<T>::~Matrix()
{
    delete matrix_elements;
    matrix_elements = nullptr;
    n_row = n_col = 0;
}

template <class T> int Matrix<T>:: row()
{
    return n_row;
}

template <class T> int Matrix<T>:: column()
{
    return n_col;
}

template <class T> T& Matrix<T>::element(const int &i, const int &j)
{
    assert(i < n_row && j < n_col);
    return matrix_elements[i * n_col + j];
}

template <class T> bool Matrix<T>:: is_square()
{
    return n_row == n_col;
}

template <class T> Matrix<T> Matrix<T>::operator * (Matrix<T> &b)
{
    assert(n_col == b.row());
    Matrix<T> res(n_row, b.column());

    for(int i = 0; i < res.row(); i++)
        for(int j = 0; j < res.column(); j++)
        {
            res.element(i, j) = 0;
            for(int k = 0; k < n_col; k++)
                res.element(i, j) += element(i, k) * b.element(k, j); 
        }
    
    return res;
}

template <class T> int RowVector<T>:: size()
{
    return Matrix<T>::column();
}

template <class T> T& RowVector<T>::element (const int &x)
{
    return Matrix<T>::element(0, x);
}

template <class T> T RowVector<T>::operator * (RowVector<T> &b)
{
    assert(size() == b.size());
    T res = 0;
    for(int i = 0; i < size(); i++)
        res += element(i) * b.element(i);
    return res;
}

template <class T> T RowVector<T>::operator * (ColVector<T> &b)
{
    assert(size() == b.size());
    T res = 0;
    for(int i = 0; i < size(); i++)
        res += element(i) * b.element(i);
    return res;
}

template <class T> int ColVector<T>:: size()
{
    return Matrix<T>::row();
}

template <class T> T& ColVector<T>::element (const int &x)
{
    return Matrix<T>::element(x, 0);
}

template <class T> T ColVector<T>::operator * (ColVector<T> &b)
{
    assert(size() == b.size());
    T res = 0;
    for(int i = 0; i < size(); i++)
        res += element(i) * b.element(i);
    return res;
}

template <class T> std::ostream& operator << (std::ostream& out, Matrix<T>& a)
{
    out << "Matrix { " << std::endl;
    out << "    n_row = " << a.row() << ", n_col = " << a.column() << std::endl;
    if(a.row() && a.column())
    {
        for(int i = 0; i < a.row(); i++)
        {
            out << "    " << a.element(i, 0);
            for(int j = 1; j < a.column(); j++)
                out << " ," << a.element(i, j);
            out << std::endl;
        }
    }
    out << "}" << std::endl;
    return out;
}



#endif
