#include <iostream>
#include <memory>
#include "arrayStruct.h"
#include "dataStruct.h"

struct stu
{
	int data;
	int height;
};

int main()
{
	stu* testStu = new stu();
	testStu->data = 123;
	testStu->height = 234;
	stu* des = new stu();

	int size =  sizeof(stu);
	int ERRORCODE = memcpy_s(des, size, testStu, size);
	delete testStu;
	testStu = NULL;


	ListNode* listNode = new ListNode(123);
	LinkedList linkedList(listNode);
	linkedList.insertData(234, 0);
	linkedList.insertData(34, 0);
	linkedList.insertData(4, 0);
	linkedList.pushDataFront(888);
	linkedList.pushDataBack(456);
	linkedList.printData();
	if (ERRORCODE == 0)
	{
		std::cout << "student " << des->data << " " << des->height << std::endl;
		delete des;
		des = NULL;
		exit(EXIT_SUCCESS);
	}
	else {
		exit(EXIT_FAILURE);
	}
}