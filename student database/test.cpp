//test.cpp
#include "dbgen.cpp"
#include "RBTree.h"
#include <iostream>
#include <vector>

using namespace std;

int main2()
{
    extern Student stdb;
    // создаем указатели на номера и фио, пихаем в вектор и поиск должен работать хз
    // деревья должны быть отдельные


    vector<int> nums{ 10,40,30,60,90,70,20,50,80,100};
    RBTree<int> tree;
    for (auto num : nums)
        tree.insert(num);
    tree.preOrder();
    cout << endl;
    tree.inOrder();
    cout << endl;
    tree.postOrder();
    cout << endl;
    cout << "Find node with key 30: \n";
    cout << endl<<tree.search(30)->key<<endl;
    cout << "Remove node with key 100 \n";
    tree.preOrder();
    cout << endl;
    cout << "\nRed and Black details: \n";
    tree.print();
    cin.get();
    return 0;
}
