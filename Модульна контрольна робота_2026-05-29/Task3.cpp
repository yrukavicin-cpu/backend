#include <iostream>
#include <vector>

template <typename T>
class Array2DCopy {
private:
    int rows;
    int cols;
    T** data;

    void allocate() {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

public:
    Array2DCopy(int r, int c) : rows(r), cols(c) {
        allocate();
    }

    Array2DCopy(const Array2DCopy<T>& other) : rows(other.rows), cols(other.cols) {
        allocate();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Array2DCopy<T>& operator=(const Array2DCopy<T>& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        allocate();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    ~Array2DCopy() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    T* operator[](int index) {
        return data[index];
    }

    const T* operator[](int index) const {
        return data[index];
    }

    Array2DCopy<T> copyRows() const {
        Array2DCopy<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j];
            }
        }
        return result;
    }

    Array2DCopy<T> copyCols() const {
        Array2DCopy<T> result(rows, cols);
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                result[i][j] = data[i][j];
            }
        }
        return result;
    }

    std::vector<T> copyRow(int rowIndex) const {
        std::vector<T> result;
        for (int j = 0; j < cols; ++j) {
            result.push_back(data[rowIndex][j]);
        }
        return result;
    }

    std::vector<T> copyCol(int colIndex) const {
        std::vector<T> result;
        for (int i = 0; i < rows; ++i) {
            result.push_back(data[i][colIndex]);
        }
        return result;
    }

    std::vector<T> copyMainDiagonal() const {
        std::vector<T> result;
        int limit = rows < cols ? rows : cols;
        for (int i = 0; i < limit; ++i) {
            result.push_back(data[i][i]);
        }
        return result;
    }

    template <typename U>
    friend std::istream& operator>>(std::istream& in, Array2DCopy<U>& arr);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Array2DCopy<U>& arr);
};

template <typename U>
std::istream& operator>>(std::istream& in, Array2DCopy<U>& arr) {
    for (int i = 0; i < arr.rows; ++i) {
        for (int j = 0; j < arr.cols; ++j) {
            in >> arr.data[i][j];
        }
    }
    return in;
}

template <typename U>
std::ostream& operator<<(std::ostream& out, const Array2DCopy<U>& arr) {
    for (int i = 0; i < arr.rows; ++i) {
        for (int j = 0; j < arr.cols; ++j) {
            out << arr.data[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

template <typename T>
void printVector(const std::vector<T>& values) {
    for (const T& value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    Array2DCopy<int> arr(3, 3);

    std::cout << "Enter 9 numbers for matrix 3x3:\n";
    std::cin >> arr;

    std::cout << "\nOriginal matrix:\n" << arr;

    Array2DCopy<int> rowCopy = arr.copyRows();
    std::cout << "\nCopy by rows:\n" << rowCopy;

    Array2DCopy<int> colCopy = arr.copyCols();
    std::cout << "\nCopy by columns:\n" << colCopy;

    std::cout << "\nSelected row 1:\n";
    printVector(arr.copyRow(1));

    std::cout << "Selected column 2:\n";
    printVector(arr.copyCol(2));

    std::cout << "Main diagonal:\n";
    printVector(arr.copyMainDiagonal());

    return 0;
}
