#pragma once
#include<iostream>
using namespace std;
template<typename T>
class CNode
{
private:
	struct stNode
	{
		T data;
		stNode* next;
		stNode* previous;
	} * p, * head, * r, * pNewPointer, * tail;
	int nNodeCount;
	
public:
	CNode()
	{
		/**p = NULL;
		*head = NULL;
		*r = NULL;
		*pNewPointer = NULL;
		*tail = NULL;*/
		 nNodeCount = 0;
	}
	void Add(int nItem);
	void DisplayAscendingOder(int nNodeCount);
	void DisplayDescendingOder(int nNodeCount);
	void FindSublist(CNode<int>& list2, int list1Size, int list2Size);
};

template<typename T>
inline void CNode<T>::Add(int nItem)
{
	pNewPointer = new stNode;
	pNewPointer->data = nItem;
	pNewPointer->next = NULL;
	pNewPointer->previous = NULL;
	if (nNodeCount == 0)
	{
		tail = pNewPointer;
		head = pNewPointer;
		p = head;
		p->next = head;
		p->previous = head;
		nNodeCount++;
	}
	else if (nNodeCount==1)
	{
		p = head;
		r = p;
		if (pNewPointer->data < p->data)
		{
			pNewPointer->next = p;
			p->previous = pNewPointer;
			head = pNewPointer;
			p->next = pNewPointer;
			pNewPointer->previous = p;
			tail = p;
		}
		else if (pNewPointer->data > p->data)
		{
			p->next = pNewPointer;
			pNewPointer->previous = p;
			pNewPointer->next = head;
			p->previous = pNewPointer;

		}
		nNodeCount++;
	}
	else
	{
		p = head;
		r = p;
		if (pNewPointer->data < p->data)
		{
			pNewPointer->next = p;
			p->previous = pNewPointer;
			head = pNewPointer;
			do
			{
				p = p->next;
			} while (p->next != r);

			tail = p;
			p->next = pNewPointer;
			pNewPointer->previous = p;
		}
		else if (pNewPointer->data > p->data)
		{
			while (p->next != head && pNewPointer->data>p->data)
			{
				r = p;
				p = p->next;
				if (p->next == head && (pNewPointer->data < p->data))
				{
					p->next = pNewPointer;
					pNewPointer->previous = p;
					pNewPointer->next = head;
					tail = pNewPointer;
					head->previous = pNewPointer;
					break;
				}
				else if (pNewPointer->data < p->data)
				{
					r->next = pNewPointer;
					pNewPointer->previous = r;
					pNewPointer->next = p;
					p->previous = pNewPointer;
				}
				if (p->next != head)
				{
					do
					{
						p = p->next;
					} while (p->next != head);
				}
				tail = p;
				break;
			}

		}
	}

	
}

template<typename T>
inline void CNode<T>::DisplayAscendingOder(int nNodeCount)
{
	stNode* t = head;
	int nCount = 0;
	cout << "Ascending Oder : ";
	while (nCount < nNodeCount)
	{
		cout << t->data << "\t";
		t = t->next;
		nCount++;
	}
	cout << endl;
}

template<typename T>
inline void CNode<T>::DisplayDescendingOder(int nNodeCount)
{
	stNode* t = tail;
	int nCount = 0;
	cout << "Decending Oder : ";
	while (nCount < nNodeCount)
	{
		cout << t->data << "\t";
		t = t->previous;
		nCount++;
	}
	cout << endl;
}

template<typename T>
inline void CNode<T>::FindSublist(CNode<int>& list2, int nlist1Size, int nlist2Size)
{
	stNode* second = list2.head;
	stNode* first = head;
	int nCount = 0,nSecondCount=0,nFlag=0;
	if (first == NULL && second == NULL)
	{
		cout << "Both List is Empty";
	}
	if (first == NULL || (first != NULL && second == NULL))
	{
		cout << "One List is Empty";
	}
	for (int i = 0; i < nlist1Size; i++)
	{
		for (int j = 0; j < nlist1Size; j++)
		{
			if (first->data == second->data)
			{
				cout << "sub list \n";
				//cout << first->data;
				nFlag++;

				//break;
			}
			second = second->next;
		}
		first = first->next;
	}
	if (nFlag == 0)
	{
		cout << "sub list is not found\n";
	}
	
	
}