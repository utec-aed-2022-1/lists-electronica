#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

using namespace std;

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T>
{
private:
    Node<T> *head;
    int nodes;

public:
    ForwardList() : List<T>()
    {
        head = nullptr;
        nodes = 0;
    }

    ~ForwardList()
    {
        // TODO
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
        if (head == nullptr)
        {
            throw("Lista Vacía");
        }
        else
        {
            Node<T> *temp = new Node<T>;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void push_front(T data)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;
        nuevo->next = head;
        head = nuevo;
        ++nodes;
    }

    void push_back(T data)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;
        nuevo->next = nullptr;

        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = nuevo;
        ++nodes;
    }

    T pop_front()
    {
        Node<T> *temp = head;
        head = head->next;
        int t = temp->data;
        delete temp;
        --nodes;
        return t;
    }

    T pop_back()
    {
        Node<T> *temp = head;
        for (int i = 0; i < nodes - 1; i++)
            temp = temp->next;
        int t = temp->data;
        delete temp->next;
        temp->next = nullptr;
        --nodes;
        return t;
    }

    T insert(T data, int pos)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;

        Node<T> *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        nuevo->next = temp->next;
        temp->next = nuevo;
    }

    bool remove(int pos)
    {
        throw("sin definir");
    }

    T &operator[](int pos)
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
        return "ForwardList";
    }
};

#endif