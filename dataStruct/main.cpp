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