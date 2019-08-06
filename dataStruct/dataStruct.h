#pragma once
class LinkedList; //这里声明一下为了声明LinkedNode为ListNode 的友元类


class ListNode
{
private :
	int m_Data;
	ListNode* nextData;
public:
	ListNode() :m_Data(0), nextData(NULL) {}
	ListNode(int a) :m_Data(a), nextData(NULL) {}
	friend class LinkedList;
};

class LinkedList
{
private:
	ListNode* m_pFirstData;

public:
	LinkedList(ListNode* listNode_)
	{
		m_pFirstData = new ListNode();
		m_pFirstData->m_Data = listNode_->m_Data;
		m_pFirstData->nextData = listNode_->nextData;

	}

	void printData();
	void pushDataFront(int data);
	void pushDataBack(int data);
	void deteteData(int data);
	void clearData();
	void Reverse();

	~LinkedList()
	{
		delete m_pFirstData;
		m_pFirstData = NULL;
	}

};

void LinkedList::printData()
{
	if (m_pFirstData == NULL)
	{
		std::cout << "ListNode is Empty " << std::endl;
		return;
	}

	ListNode* currentData = new ListNode;
	while (currentData != NULL)
	{
		//因为linkedNode 为ListNode的友元类，所以在LinkedNode内能访问到ListNode的私有变量
		std::cout << currentData->m_Data << " " << std::endl;
		currentData = currentData->nextData;
	}

}

void LinkedList::pushDataFront(int data)
{
}

