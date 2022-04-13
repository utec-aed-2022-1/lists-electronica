#ifndef DOUBLE_H
#define DOUBLE_H
#include <iostream>
#include "list.h"

using namespace std;

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    int nodes;

public:
    DoubleList() : List<T>()
    {
        head = tail = nullptr;
        nodes = 0;
    }

    ~DoubleList()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    T front()
    {
        return head->data;
    }

    T back()
    {
        return tail->data;
    }

    void push_front(T data)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;

        if (head == nullptr)
            head = tail = nuevo;
        else
        {
            nuevo->next = head;
            head->prev = nuevo;
            head = nuevo;
        }

        ++nodes;
    }

    void push_back(T data)
    {

        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;

        if (tail == nullptr)
            head = tail = nuevo;
        else
        {
            nuevo->prev = tail;
            tail->next = nuevo;
            tail = nuevo;
        }

        ++nodes;
    }

    T pop_front()
    {
        int t = head->data;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        --nodes;
        return t;
    }

    T pop_back()
    {
        int t = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        --nodes;
        return t;
    }

    T insert(T data, int pos)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;
        Node<T> *temp1 = head;
        int i = 0;
        while (i++ < pos - 1)
            temp1 = temp1->next;
        Node<T> *temp2 = temp1->next;
        temp1->next = nuevo;
        temp2->prev = nuevo;
        nuevo->prev = temp1;
        nuevo->next = temp2;
    }

    bool remove(int)
    {
        throw("sin definir");
    }

    T &operator[](int pos) // debe ser declarado en cada clase hija
    {
        Node<T> *temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        return temp->data;
    }

    bool is_empty()
    {
        if (head == nullptr)
            return true;
        return false;
    }

    int size()
    {
        return nodes;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void sort()
    {
        if (nodes <= 0)
        {
            throw("Array vacío");
        }
        else if (nodes == 1)
        {
            throw("Elemento ordenado");
        }
        else
        {
            Node<T> *temp = head;
            Node<T> *temp_a = new Node<T>;

            // loop para acceder cada elemento del array
            for (int step = 0; step < nodes; ++step)
            {
                // loop para comparar elementos del array
                for (int i = 0; i < nodes - step; ++i)
                {
                    // comparar 2 elementos adyacentes
                    if (temp->data > temp->next->data)
                    {
                        // swap si los elementos no están en el orden deseado
                        temp_a = temp;
                        temp = temp->next;
                        temp->next = temp_a;
                    }
                }
            }
        }
    }

    bool is_sorted()
    {
        // Si el array está vacío o tiene 1 elemento
        if (nodes <= 1)
            return true;

        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data < temp->next->data)
            {
                temp = temp->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    void reverse()
    {
        // Inicializar punteros
        Node<T> *current = head;
        Node<T> *prev = nullptr, *next = nullptr;

        while (current != nullptr)
        {
            // Almacenar next
            next = current->next;

            // Invertir el puntero del actual
            current->next = prev;

            // Mover los punteros hacia adelante
            prev = current;
            current = next;
        }
        head = prev;
    }

    std::string name()
    {
        return "DoubleList";
    }
};
#endif