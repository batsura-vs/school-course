/*  СТЕК  ---------------------------------------------------------------------

    В данном файле описывается классическая структура данных -- Стек (Stack).
    
    Приведённая реализация стека подразумевается динамическое выделение памяти
    (при добавлении элемента) и динамическое её освобождение при необходимости
    (при удалении), по этой причине для описания стека используются указатели

---------------------------------------------------------------------------  */

#include <iostream>

using namespace std;


/*  ---------------------------------------------------------------------------
    Класс записи (Node) используется как обёртка
    для представления хранимых в стеке (Stack) данных
---------------------------------------------------------------------------  */
struct Node {
    
    int value;      // значение записи
    Node* prev;     // указатель на предыдущую запись

    /*  -----------------------------------------------------------------------
        Конструктор записи.
        Принимает в качестве аргумента значение для оборачивания,
        указатель на предыдущую запись является нулевым
    -----------------------------------------------------------------------  */
    Node(int _value) {
        value = _value;
        prev = nullptr;
    }

};


/*  ---------------------------------------------------------------------------
    Динамическая реализация класс стека (Stack)
---------------------------------------------------------------------------  */
struct Stack {
    
    Node* top;      // указатель на вершину стека


    /*  -----------------------------------------------------------------------
        Конструктор стека.
        Указатели на вершину стека -- нулевой указатель 
        (стек пуст при создании)
    -----------------------------------------------------------------------  */
    Stack() {
        top = nullptr;
    }

    /*  -----------------------------------------------------------------------
        Метод добавления нового значения в стек.
        Значение оборачивается в запись 
        и добавляется в качестве вершины стека
    -----------------------------------------------------------------------  */
    void push(int _value) {
        Node* new_elem = new Node(_value);
        new_elem->prev = top;
        top = new_elem;
    }

    /*  -----------------------------------------------------------------------
        Метод извлечения элемента из стека
    -----------------------------------------------------------------------  */
    int pop() {
        int result = top->value;
        Node* old_elem = top;
        top = top->prev;
        delete old_elem;
        return result;
    }

    /*  -----------------------------------------------------------------------
        Метод проверки на пустоту.
        Если указатель на вершину -- нулевой указатель, то стек пуст
    -----------------------------------------------------------------------  */
    bool empty() {
        return top == nullptr;
    }

};


int main() {

    // ниже представлена проверка роботоспособности 
    // описанных выше сущностей

    int n;
    cin >> n;

    Stack st = Stack();
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        st.push(tmp);
    }

    while (!st.empty()) {
        cout << st.pop() << ' ';
    }
    cout << '\n';

    return 0;
}

