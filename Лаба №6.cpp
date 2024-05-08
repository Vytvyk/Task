#include <iostream>
#include <vector>
#include <algorithm>

class Set {
private:
    std::vector<int> elements;

public:
    // ����������� �� ������������
    Set() {}

    // ����������� ��ﳿ
    Set(const Set& other) : elements(other.elements) {}

    // ��������� �������� �� �������
    void addElement(int element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            elements.push_back(element);
        }
    }

    // г����� �� �������� �������� �� ����� ��������
    Set difference(const Set& other) const {
        Set diffSet(*this);
        for (auto it = other.elements.begin(); it != other.elements.end(); ++it) {
            diffSet.elements.erase(std::remove(diffSet.elements.begin(), diffSet.elements.end(), *it), diffSet.elements.end());
        }
        return diffSet;
    }

    // �������� ��������� (==)
    bool operator==(const Set& other) const {
        return elements == other.elements;
    }

    // �������� ��������� (!=)
    bool operator!=(const Set& other) const {
        return !(*this == other);
    }

    // ������������ �������
    int operator[](int index) const {
        return elements[index];
    }

    // ������������ ������� � �����
    friend std::ostream& operator<<(std::ostream& os, const Set& set) {
        os << "{";
        for (size_t i = 0; i < set.elements.size(); ++i) {
            os << set.elements[i];
            if (i != set.elements.size() - 1) {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }
};

int main() {
    Set set1;
    set1.addElement(1);
    set1.addElement(2);
    set1.addElement(3);

    Set set2;
    set2.addElement(2);
    set2.addElement(3);
    set2.addElement(4);

    Set diffSet = set1.difference(set2);

    std::cout << "Set 1: " << set1 << std::endl;
    std::cout << "Set 2: " << set2 << std::endl;
    std::cout << "Difference: " << diffSet << std::endl;

    return 0;
}
