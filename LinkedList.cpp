////Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
////Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted.

#pragma once
#include<iostream>
//#include "DoublyLinkedList.cpp"
#include"Node.h"


using namespace std;
int main() 
{
    CNode <int>list1;
    CNode<int>list2;
    int size1,size2,item;
    cout << "Enter Total number of Node in First Linked List";
    cin >> size1;
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter item  " << i + 1 << " : ";
        cin >> item;
        list1.Add(item);
    }
    list1.DisplayAscendingOder(size1);
    list1.DisplayDescendingOder(size1);
    cout << "Enter Total number of Node in First Linked List";
    cin >> size2;
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter item  " << i + 1 << " : ";
        cin >> item;
        list2.Add(item);
    }
    list2.DisplayAscendingOder(size2);
    list2.DisplayDescendingOder(size2);



    list1.FindSublist(list2, size1, size2);
    /*CDoublyLinkedList<int> list1;
    CDoublyLinkedList<int> list2;
    

    cout << "Enter Total number of item to inserted in First Linked List";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter item  " << i + 1 << " : ";
        cin >> item;
        list1.Add(item);
    }
    list1.displayAll();*/
    /*cout << "Enter Total number of item to inserted in Second Linked List";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter item  " << i + 1 << " : ";
        cin >> item;
        list2.Add(item);
    }
    list2.displayAll();

    list1.sorted();
    list1.displayAll();

    list2.sorted();
    list2.displayAll();


    list1.FindSubList(list2);*/
    return 0;
}


