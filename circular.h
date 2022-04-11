#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

using namespace std;

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T>
{
private:
    Node<T> *head; // sentinel
    int nodes;

public:
    CircularList() : List<T>()
    {
        head = new Node<T>;
        head->prev = head;
        head->next = head;
        nodes = 0;
    }

    ~CircularList()
    {
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
        nuevo->next = head->next;
        nuevo->prev = head;
        head->next->prev = nuevo;
        head->next = nuevo;
        ++nodes;
    }

    void push_back(T data)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;
        nuevo->next = head;

        Node<T> *temp = head->next;
        while (temp->next != head)
            temp = temp->next;
        temp->next = nuevo;
        nuevo->prev = temp;
        head->prev = nuevo;
        ++nodes;
    }

    T pop_front()
    {
        Node<T> *temp = head->next;
        int t = temp->data;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        --nodes;
        return t;
    }

    T pop_back()
    {
        Node<T> *temp = head->next;

        while (temp->next != head)
            temp = temp->next;

        int t = temp->data;
        temp->prev->next = head;
        head = temp->prev;
        delete temp;
        return t;
    }

    T insert(T data, int pos)
    {
        Node<T> *nuevo = new Node<T>;
        nuevo->data = data;

        Node<T> *temp = head->next;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        temp->next->prev = nuevo;
        nuevo->next = temp->next;
        temp->next = nuevo;
        nuevo->prev = temp;
    }

    bool remove(int pos)
    {
        throw("sin definir");
    }

    T &operator[](int pos)
    {
        Node<T> *temp = head->next;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        return temp->data;
    }

    bool is_empty()
    {
        if (head->prev == head)
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
        return "CircularList";
    }
};

#endif