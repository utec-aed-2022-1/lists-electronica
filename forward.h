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
        return "ForwardList";
    }
};

#endif