#include <iostream>
#include <clocale>

int main()
{
    std::setlocale(LC_ALL, "rus");

    int n;
    std::cout << "Введите размерность квадратной матрицы (3 <= n <= 9): ";
    std::cin >> n;

    if (n < 3 || n > 9) {
        std::cout << "Ошибка. Размер должен быть в диапазоне [3, 9]." << std::endl;
        return 1;
    }

    int matrix[10][10];

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int target = 0;
    for (int j = 0; j < n; j++) {
        target += matrix[0][j];
    }

    bool masquare = true;

    for (int i = 0; i < n && masquare; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        if (sum != target) {
            masquare = false;
        }
    }

    for (int j = 0; j < n && masquare; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        if (sum != target) {
            masquare = false;
        }
    }

    int d1 = 0;
    for (int i = 0; i < n; i++) {
        d1 += matrix[i][i];
    }
    if (d1 != target) {
        masquare = false;
    }

    int d2 = 0;
    for (int i = 0; i < n; i++) {
        d2 += matrix[i][n - 1 - i];
    }
    if (d2 != target) {
        masquare = false;
    }

    if (masquare) {
        std::cout << "Да" << std::endl;
    } else {
        std::cout << "Нет" << std::endl;
    }

    return 0;
}
