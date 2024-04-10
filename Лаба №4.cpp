#include <iostream> 
#include <string>  

class Figure { // Базовий клас "Фігура"
protected:
    double width;   
    double height;  

public: // Публічний інтерфейс
    Figure(double width, double height)  // Конструктор з параметрами
        : width(width), height(height) {}

    double getWidth() const { return width; }  // Метод для отримання ширини
    double getHeight() const { return height; } // Метод для отримання висоти

    // Додаємо будь-які необхідні методи базового класу
};

class Rectangle : public Figure { // Похідний клас "Прямокутник"
private:
    std::string color; // Колір

public: // Публічний інтерфейс
    Rectangle(double width, double height, const std::string& color)  // Конструктор з параметрами
        : Figure(width, height), color(color) {}

    double area() const { // Метод для обчислення площі
        return getWidth() * getHeight();
    }

    std::string getColor() const { return color; } // Метод для отримання кольору

    void displayColor() const { // Метод для виведення кольору
        std::cout << "Color: " << color << std::endl;
    }

    // Додаємо будь-які додаткові методи похідного класу
};

int main() { // Основна функція
    Rectangle rect(5, 6, "red"); // Створюємо екземпляр класу Rectangle
    std::cout << "Rectangle arrea: " << rect.area() << std::endl; // Виводимо площу
    rect.displayColor(); // Виводимо колір
    return 0;
}