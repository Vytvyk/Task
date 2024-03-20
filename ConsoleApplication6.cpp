#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Перевіряємо всі чотиризначні натуральні числа
    for (int i = 1000; i <= 9999; i++) {
        // Знаходимо суму цифр числа
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }

        // Якщо куб суми цифр дорівнює числу, то виводимо його на екран
        if (pow(sum, 3) == i) {
            cout << i << endl;
            return 0;
        }
    }

    // Якщо жодного числа не знайдено, то виводимо повідомлення про це
    cout << "this number does not exist" << endl;
    
    return 0;
}