// Komponnuvalnik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>


class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};


class Leaf : public Component {
public:
    Leaf(int value) : value(value) {}

    void operation() const override {
        std::cout << "Leaf: " << value << std::endl;
    }

private:
    int value;
};


class Composite : public Component {
public:
    void addComponent(Component* component) {
        components.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite: ";
        for (const auto& component : components) {
            component->operation();
        }
    }

private:
    std::vector<Component*> components;
};

int main() {

    Leaf leaf1(1);
    Leaf leaf2(2);
    Leaf leaf3(3);


    Composite composite;
    composite.addComponent(&leaf1);
    composite.addComponent(&leaf2);

  
    Composite biggerComposite;
    biggerComposite.addComponent(&composite);
    biggerComposite.addComponent(&leaf3);

   
    leaf1.operation();  
    composite.operation();  
    biggerComposite.operation();  

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
