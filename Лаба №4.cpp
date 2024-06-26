#include <iostream> 
#include <string>  

class Figure { // ������� ���� "Գ����"
protected:
    double width;   
    double height;  

public: // �������� ���������
    Figure(double width, double height)  // ����������� � �����������
        : width(width), height(height) {}

    double getWidth() const { return width; }  // ����� ��� ��������� ������
    double getHeight() const { return height; } // ����� ��� ��������� ������

    // ������ ����-�� ��������� ������ �������� �����
};

class Rectangle : public Figure { // �������� ���� "�����������"
private:
    std::string color; // ����

public: // �������� ���������
    Rectangle(double width, double height, const std::string& color)  // ����������� � �����������
        : Figure(width, height), color(color) {}

    double area() const { // ����� ��� ���������� �����
        return getWidth() * getHeight();
    }

    std::string getColor() const { return color; } // ����� ��� ��������� �������

    void displayColor() const { // ����� ��� ��������� �������
        std::cout << "Color: " << color << std::endl;
    }

    // ������ ����-�� �������� ������ ��������� �����
};

int main() { // ������� �������
    Rectangle rect(5, 6, "red"); // ��������� ��������� ����� Rectangle
    std::cout << "Rectangle arrea: " << rect.area() << std::endl; // �������� �����
    rect.displayColor(); // �������� ����
    return 0;
}