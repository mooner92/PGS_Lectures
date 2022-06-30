#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    int count;
    Node *header;
    Node *trailer;

public:
    DoublyLinkedList()
    {
        count = 0;
        header = new Node{0, nullptr, nullptr};
        trailer = new Node{0, nullptr, nullptr};
        header->next = trailer;
        trailer->prev = header;
    }
    ~DoublyLinkedList()
    {
        while (!empty())
        {
            pop_front();
        }
        delete header;
        delete trailer;
    }
    void insert(Node *p, int val)
    {
        Node *new_node = new Node{val, p->prev, p};
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void push_front(int val)
    {
        insert(header->next, val);
    }
    void push_back(int val)
    {
        insert(trailer, val);
    }
    void erase(Node *p)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }
    void pop_front()
    {
        if (!empty())
            erase(header->next);
    }
    void pop_back()
    {
        if (!empty())
            erase(trailer->prev);
    }
    bool empty()
    {
        return count == 0;
    }
    int size()
    {
        return count;
    }
    void print_all()
    {
        Node *curr = header->next;
        while (curr != trailer)
        {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    void print_reverse()
    {
        Node *curr = trailer->prev;
        while (curr != header)
        {
            cout << curr->data << ", ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.print_all();
    ll.print_reverse();

    // ll: header -> 10 -> 20 -> 30 -> trailer

    ll.pop_front();
    ll.pop_back();
    ll.print_all();

    ll.push_front(100);
    ll.push_back(400);
    ll.print_all();
}