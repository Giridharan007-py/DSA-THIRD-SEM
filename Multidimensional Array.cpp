#include <iostream>
using namespace std;

class Matrix
{
private:
    int row, col;
    int a[10][10];

public:
    void createMatrix();
    void displayMatrix();
    void addMatrix(Matrix);
    void multiplyMatrix(Matrix);
    void diagonalSum();
    void transpose();
    void checkSymmetric();
};

// Create Matrix
void Matrix::createMatrix()
{
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
}

// Display Matrix
void Matrix::displayMatrix()
{
    cout << "\nMatrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

// Add Two Matrices
void Matrix::addMatrix(Matrix m2)
{
    if (row != m2.row || col != m2.col)
    {
        cout << "Addition not possible.\n";
        return;
    }

    cout << "\nSum Matrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] + m2.a[i][j] << "\t";
        }
        cout << endl;
    }
}

// Multiply Two Matrices
void Matrix::multiplyMatrix(Matrix m2)
{
    if (col != m2.row)
    {
        cout << "Multiplication not possible.\n";
        return;
    }

    int result[10][10];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < m2.col; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                result[i][j] += a[i][k] * m2.a[k][j];
            }
        }
    }

    cout << "\nProduct Matrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < m2.col; j++)
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

// Sum of Leading and Right Diagonal
void Matrix::diagonalSum()
{
    if (row != col)
    {
        cout << "Diagonal exists only for square matrix.\n";
        return;
    }

    int left = 0, right = 0;

    for (int i = 0; i < row; i++)
    {
        left += a[i][i];
        right += a[i][row - 1 - i];
    }

    cout << "Leading Diagonal Sum = " << left << endl;
    cout << "Right Diagonal Sum = " << right << endl;
}

// Transpose
void Matrix::transpose()
{
    cout << "\nTranspose Matrix:\n";

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << a[j][i] << "\t";
        }
        cout << endl;
    }
}

// Check Symmetric
void Matrix::checkSymmetric()
{
    if (row != col)
    {
        cout << "Not a Symmetric Matrix.\n";
        return;
    }

    bool symmetric = true;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] != a[j][i])
            {
                symmetric = false;
                break;
            }
        }
    }

    if (symmetric)
        cout << "Matrix is Symmetric.\n";
    else
        cout << "Matrix is Not Symmetric.\n";
}

// Main Function
int main()
{
    Matrix m1, m2;
    int choice;

    do
    {
        cout << "\n      MATRIX ADT MENU      \n";
        cout << "1. Create Matrix 1\n";
        cout << "2. Create Matrix 2\n";
        cout << "3. Display Matrix 1\n";
        cout << "4. Display Matrix 2\n";
        cout << "5. Add Matrices\n";
        cout << "6. Multiply Matrices\n";
        cout << "7. Diagonal Sum (Matrix 1)\n";
        cout << "8. Transpose (Matrix 1)\n";
        cout << "9. Check Symmetric (Matrix 1)\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            m1.createMatrix();
            break;

        case 2:
            m2.createMatrix();
            break;

        case 3:
            m1.displayMatrix();
            break;

        case 4:
            m2.displayMatrix();
            break;

        case 5:
            m1.addMatrix(m2);
            break;

        case 6:
            m1.multiplyMatrix(m2);
            break;

        case 7:
            m1.diagonalSum();
            break;

        case 8:
            m1.transpose();
            break;

        case 9:
            m1.checkSymmetric();
            break;

        case 10:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 10);

    return 0;
}
