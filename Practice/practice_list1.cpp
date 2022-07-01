#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1; // empty list
    l1.push_back(10);
    l1.push_back(20);

    list<int> l2{10, 20, 30, 40};

    l2.splice(l2.end(), l1); // l1의 모든 원소가 이동 -> l1의 원소 전부 사라짐
    l2.sort();               // 10,10,20,20,30,40
    l2.unique();             // 10,20,30,40

    for (auto a : l2)
    {
        cout << a << "\n";
    }
}