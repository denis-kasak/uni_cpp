#include <string>
#include <sstream>
#include <iomanip>

#include "Matrix.h"

// ----------------------------------------------------------------------------

Matrix33 Matrix33::zeros()
{
    return Matrix33(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// ----------------------------------------------------------------------------

Matrix33 Matrix33::ones()
{
    return Matrix33(1, 1, 1, 1, 1, 1, 1, 1, 1);
}

// ----------------------------------------------------------------------------

Matrix33::Matrix33(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33)
{
    m_matrix[0][0] = m11;
    m_matrix[0][1] = m12;
    m_matrix[0][2] = m13;
    m_matrix[1][0] = m21;
    m_matrix[1][1] = m22;
    m_matrix[1][2] = m23;
    m_matrix[2][0] = m31;
    m_matrix[2][1] = m32;
    m_matrix[2][2] = m33;
}

// ----------------------------------------------------------------------------

std::string Matrix33::toString() const
{
    std::stringstream s;
    s << "----------------------------\n";
    s << "| " << std::setw(6) << m_matrix[0][0];
    s << " | " << std::setw(6) << m_matrix[0][1];
    s << " | " << std::setw(6) << m_matrix[0][2] << " |";
    s << "\n----------------------------\n";
    s << "| " << std::setw(6) << m_matrix[1][0];
    s << " | " << std::setw(6) << m_matrix[1][1];
    s << " | " << std::setw(6) << m_matrix[1][2] << " |";
    s << "\n----------------------------\n";
    s << "| " << std::setw(6) << m_matrix[2][0];
    s << " | " << std::setw(6) << m_matrix[2][1];
    s << " | " << std::setw(6) << m_matrix[2][2] << " |";
    s << "\n----------------------------\n";

    return s.str();
}

double &Matrix33::get(int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
    {
        throw IndexException();
    }
    else
    {
        return m_matrix[row][col];
    }
}

// ----------------------------------------------------------------------------

Matrix33 Matrix33::operator+(Matrix33 m)
{
    double m11, m12, m13, m21, m22, m23, m31, m32, m33;

    m11 = this->get(0, 0) + m.get(0, 0);
    m12 = this->get(0, 1) + m.get(0, 1);
    m13 = this->get(0, 2) + m.get(0, 2);
    m21 = this->get(1, 0) + m.get(1, 0);
    m22 = this->get(1, 1) + m.get(1, 1);
    m23 = this->get(1, 2) + m.get(1, 2);
    m31 = this->get(2, 0) + m.get(2, 0);
    m32 = this->get(2, 1) + m.get(2, 1);
    m33 = this->get(2, 2) + m.get(2, 2);

    return Matrix33(m11, m12, m13, m21, m22, m23, m31, m32, m33);
}

Matrix33 Matrix33::operator*(Matrix33 m)
{
    double mat[3][3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
            {
                mat[i][j] += this->get(i, k) * m.get(k, j);
            }

    return Matrix33(
        mat[0][0], mat[0][1], mat[0][2],
        mat[1][0], mat[1][1], mat[1][2],
        mat[2][0], mat[2][1], mat[2][2]);
}

Matrix33 Matrix33::operator*(double n)
{
    double mat[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = this->get(i, j) * n;
        }
    }

    return Matrix33(
        mat[0][0], mat[0][1], mat[0][2],
        mat[1][0], mat[1][1], mat[1][2],
        mat[2][0], mat[2][1], mat[2][2]);
}

Matrix33 Matrix33::operator+=(Matrix33 m)
{
    double mat[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->get(i, j) = this->get(i, j) + m.get(i, j);
            mat[i][j] = this->get(i, j);
        }
    }
    return Matrix33(
        mat[0][0], mat[0][1], mat[0][2],
        mat[1][0], mat[1][1], mat[1][2],
        mat[2][0], mat[2][1], mat[2][2]);
}

Matrix33::operator double()
{
    double x, y, z, d;

    x = ((this->get(1, 1) * this->get(2, 2)) - (this->get(2, 1) * this->get(1, 2)));
    y = ((this->get(1, 0) * this->get(2, 2)) - (this->get(2, 0) * this->get(1, 2)));
    z = ((this->get(1, 0) * this->get(2, 1)) - (this->get(2, 0) * this->get(1, 1)));

    return ((this->get(0, 0) * x) - (this->get(0, 1) * y) + (this->get(0, 2) * z));
}

Matrix33 operator*(double n, Matrix33 m)
{
    double mat[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = m.get(i, j) * n;
        }
    }

    return Matrix33(
        mat[0][0], mat[0][1], mat[0][2],
        mat[1][0], mat[1][1], mat[1][2],
        mat[2][0], mat[2][1], mat[2][2]);
}