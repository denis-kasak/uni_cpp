#ifndef Matrix3
#define Matrix3

#include <string>

class Matrix33
{
public:
    // Static Class-Functions
    static Matrix33 zeros();
    static Matrix33 ones();

    // Construction
    Matrix33(double m11, double m12, double m13,
             double m21, double m22, double m23,
             double m31, double m32, double m33);

    double &get(int row, int col);

    std::string toString() const;
    Matrix33 operator+(Matrix33 m);
    Matrix33 operator*(Matrix33 m);
    Matrix33 operator*(double n);
    Matrix33 &operator+=(Matrix33 m);
    friend Matrix33 operator*(double, Matrix33);
    operator double();

private:
    double m_matrix[3][3];
};

class IndexException
{
public:
    std::string getError() const
    {
        return "Zugriff auf einen Index außerhalb der Matrizen-Zeilen/Spalten versucht.";
    }
};
#endif
