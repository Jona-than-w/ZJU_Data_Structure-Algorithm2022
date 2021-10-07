#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rand_matrix(Matrix<int> &mat)
{
    for(int i = 0; i < mat.row(); i++)
        for(int j = 0; j < mat.column(); j++)
            mat.element(i, j) = rand() & 63;
}

void rand_matrix_double(Matrix<double> &mat)
{
    for(int i = 0; i < mat.row(); i++)
        for(int j = 0; j < mat.column(); j++)
            mat.element(i, j) = (double)(rand() & 32767) / 255;
}

int main()
{
  
    Matrix<double> mat0(5, 5);
    cout << "CREATE Matrix<double> mat0" << endl;
    rand_matrix_double(mat0);
    cout << " random mat0" << endl;
    cout << mat0 << endl;

    Matrix<int> mat1(7, 8);
    cout << "CREATE Matrix<int> mat1" << endl;
    cout << mat1 << endl;

    Matrix<int> mat2(10, 10);
    cout << "CREATE Matrix<int> mat2" << endl;
    cout << mat2 << endl;

    cout << "TEST1 is_square():" << endl;
    cout << "#mat1.is_square(): " << mat1.is_square() << endl;
    cout << "#mat2.is_square(): " << mat2.is_square() << endl;
    cout << endl;

    cout << " random mat1" << endl;
    rand_matrix(mat1);
    cout << mat1 << endl;

    Matrix<int> mat3(8, 5);
    cout << "CREATE Matrix<int> mat3" << endl;
    rand_matrix(mat3);
    cout << " random mat3" << endl;
    cout << mat3 << endl;

    cout << "TEST2 operator * " << endl;
    cout << "MULTIPLY mat1 and mat3, result:" << endl;
    Matrix<int> mat4 = mat1 * mat3;
    cout << mat4 << endl;

    RowVector<int> rowvec1(8);
    cout << "CREATE RowVector rowvec1" << endl;
    rand_matrix(rowvec1);
    cout << " random rowvec1" << endl;
    cout << rowvec1 << endl;

    RowVector<int> rowvec2(8);
    cout << "CREATE RowVector rowvec2" << endl;
    rand_matrix(rowvec2);
    cout << " random rowvec2" << endl;
    cout << rowvec2 << endl;

    cout << "TEST operator * (RowVector, RowVector):" << endl;
    cout << "MULTIPLY rowvec1 and rowvec2, you get an integer:" << endl;
    cout << rowvec1 * rowvec2 << endl << endl;

    ColVector<int> colvec1(8);
    cout << "CREATE ColVector colvec1" << endl;
    rand_matrix(colvec1);
    cout << " random  colvec1" << endl;
    cout << colvec1 << endl;

    ColVector<int> colvec2(8);
    cout << "CREATE ColVector colvec2" << endl;
    rand_matrix(colvec2);
    cout << " random colvec2" << endl;
    cout << colvec2 << endl;

    cout << "TEST operator * (ColVector, ColVector):" << endl;
    cout << "MULTIPLY colvec1 and colvec2, you got an integer:" << endl;
    cout << colvec1 * colvec2 << endl << endl;

    cout << "TEST operator * (RowVector, ColVector):" << endl;
    cout << "MULTIPLY rowvec1 and colvec1, you got an integer:" << endl;
    cout << rowvec1 * colvec1 << endl << endl;

    cout << "TEST operator * (ColVector, RowVector):" << endl;
    cout << "MULTIPLY colvec1 and rowvec1, you got an matrix5:" << endl;
    Matrix<int> mat5 = colvec1 * rowvec1;
    cout << mat5 << endl;

  
    return 0;
}
