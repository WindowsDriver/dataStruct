#pragma once
#include <memory>
#include <sstream>
class LinkedList; //��������һ��Ϊ������LinkedNodeΪListNode ����Ԫ��


class ListNode
{
private :
	int m_Data;
	ListNode* nextData;
public:
	ListNode() :m_Data(0), nextData(NULL) {}
	ListNode(const int element_) :m_Data(element_), nextData(NULL) {}
	ListNode(const int element_, ListNode* next)
	{
		//this->nextData = next;
		this->m_Data = element_;
		int size = sizeof(ListNode);
		memcpy_s((ListNode*)nextData, size, (ListNode*) next, size);
	}

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
	void insertData(const int& data, int index);
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
		//��ΪlinkedNode ΪListNode����Ԫ�࣬������LinkedNode���ܷ��ʵ�ListNode��˽�б���
		std::cout << currentData->m_Data << " " << std::endl;
		currentData = currentData->nextData;
	}

}

void LinkedList::pushDataFront(int data)
{
	m_pFirstData = new ListNode(data, m_pFirstData);
}

void LinkedList::insertData(const int& data, int index)
{
	if (index < 0)
	{
		std::ostringstream oss;
		oss << "index " << index;
	}
	else {
		if (index == 0)
		{
			//������ͷ��������
			m_pFirstData = new ListNode(data, m_pFirstData);
		}
		else {
			ListNode* _pListData = m_pFirstData;
			for (int i = 0; i < index - 1; i++)
			{
				_pListData = m_pFirstData->nextData;
			}

			//��_pListData֮���������
			_pListData->nextData = new ListNode(data, _pListData->nextData);
		}
	}
	
}

