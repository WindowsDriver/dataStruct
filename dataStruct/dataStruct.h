#pragma once
class LinkedList;
template<typename T>
class ListNode
{
private :
	int data;
	ListNode* nextData;
public:
	ListNode() :data(0), nextData(0) {}
	ListNode(T a) :data(a), nextData(0) {}
	friend class LinkedList;
};


