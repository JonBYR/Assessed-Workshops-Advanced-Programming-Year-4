#include <iostream>

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    // Constructor
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int* [r];
        for (int i = 0; i < r; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Method to get value at row and col
    int get(int row, int col) const {
        return data[row][col];
    }
    int getRows() const
    {
        return rows;
    }
    int getCols() const {
        return cols;
    }
    // Method to set value at row and col
    void set(int row, int col, int value) {
        data[row][col] = value;
    }

    // Method to add two matrices
    Matrix add(const Matrix& other) {
        Matrix addedMat(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
            {
                int addedValue = data[i][j] + other.get(i, j);
                addedMat.set(i, j, addedValue);
            }
        }
        return addedMat;
    }

    // Method to multiply two matrices
    Matrix multiply(const Matrix& other)
    {
        
            Matrix multiMat(rows, other.getCols());
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < other.getCols(); j++)
                {
                    multiMat.set(i, j, 0);
                    for (int k = 0; k < other.getCols(); k++) 
                    {
                        int currentResult = multiMat.get(i, j);
                        int result = (data[i][k] * other.get(k, j)) + currentResult;
                        multiMat.set(i, j, result);
                    }
                }
            }
            return multiMat;
        
    }

    // Method to display the matrix
    void display() {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Input dimensions for Matrix A
    std::cout << "Enter dimensions of Matrix A (rows, cols): " << std::endl;
    int arows;
    int brows;
    int acols;
    int bcols;
    std::cin >> arows;
    std::cin >> acols;
    Matrix A(arows, acols);
    for (int i = 0; i < arows; i++) 
    {
        for (int j = 0; j < acols; j++) 
        {
            std::cout << "Element(" << (i + 1) << "," << (j + 1) << "):";
            int val;
            std::cin >> val;
            A.set(i, j, val);
        }
    }
    // Create Matrix A with the given dimensions
    std::cout << "Enter dimensions of Matrix B (rows, cols): " << std::endl;
    std::cin >> brows;
    std::cin >> bcols;
    Matrix B(brows, bcols);
    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcols; j++)
        {
            std::cout << "Element(" << (i + 1) << "," << (j + 1) << "):";
            int val;
            std::cin >> val;
            B.set(i, j, val);
        }
    }
    A.display();
    B.display();
    // Perform matrix addition and display the result
    Matrix C = A.add(B);
    C.display();
    Matrix D = A.multiply(B);
    D.display();
    // Perform matrix multiplication and display the result

    return 0;
}


