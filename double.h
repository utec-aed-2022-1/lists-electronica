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
        // TODO
        delete this;
    }

    T front()
    {
        throw("sin definir");
    }

    T back()
    {
        throw("sin definir");
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
        throw("sin definir");
    }

    void sort()
    {
        throw("sin definir");
    }

    bool is_sorted()
    {
        throw("sin definir");
    }

    void reverse()
    {
        throw("sin definir");
    }

    std::string name()
    {
        return "DoubleList";
    }
};
#endif