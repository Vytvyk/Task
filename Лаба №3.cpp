#include <iostream>
#include <cstring>

const int MAX_SIZE = 100; // Максимальна довжина рядка
const int MAX_ARRAY_SIZE = 50; // Максимальна кількість рядків у масиві

class FixedLengthStringArray {
private:
    char array[MAX_ARRAY_SIZE][MAX_SIZE];
    int length;

public:
    FixedLengthStringArray() {
        length = 0;
    }

    // Додавання рядка до масиву
    void addString(const char* str) {
        if (length < MAX_ARRAY_SIZE) {
            strncpy_s(array[length], str, _TRUNCATE);
            length++;
        }
        else {
            std::cerr << "The array is full. Unable to add row." << std::endl;
        }
    }

    // Отримання рядка за індексом
    const char* getString(int index) const {
        if (index >= 0 && index < length) {
            return array[index];
        }
        else {
            std::cerr << "Invalid index." << std::endl;
            return nullptr;
        }
    }

    // Отримання кількості рядків у масиві
    int getSize() const {
        return length;
    }

    // Друк (вивід на екран) всіх рядків масиву
    void printArray() const {
        for (int i = 0; i < length; ++i) {
            std::cout << array[i] << std::endl;
        }
    }

    // Зчеплення двох масивів
    FixedLengthStringArray concatenate(const FixedLengthStringArray& other) const {
        FixedLengthStringArray result;
        for (int i = 0; i < length; ++i) {
            result.addString(array[i]);
        }
        for (int i = 0; i < other.getSize(); ++i) {
            result.addString(other.getString(i));
        }
        return result;
    }

    // Злиття двох масивів з виключенням повторюваних елементів
    FixedLengthStringArray merge(const FixedLengthStringArray& other) const {
        FixedLengthStringArray result = *this;
        for (int i = 0; i < other.getSize(); ++i) {
            const char* str = other.getString(i);
            bool duplicate = false;
            for (int j = 0; j < result.getSize(); ++j) {
                if (strcmp(result.getString(j), str) == 0) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                result.addString(str);
            }
        }
        return result;
    }
};

int main() {
    FixedLengthStringArray array1;
    array1.addString("Hello");
    array1.addString("World");

    FixedLengthStringArray array2;
    array2.addString("Nose");
    array2.addString("Face");

    std::cout << "Array 1:" << std::endl;
    array1.printArray();

    std::cout << "Array 2:" << std::endl;
    array2.printArray();

    FixedLengthStringArray concatenatedArray = array1.concatenate(array2);
    std::cout << "Concatenated Array:" << std::endl;
    concatenatedArray.printArray();

    FixedLengthStringArray mergedArray = array1.merge(array2);
    std::cout << "Merged Array:" << std::endl;
    mergedArray.printArray();

    return 0;
}
