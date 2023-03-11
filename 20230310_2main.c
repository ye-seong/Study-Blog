#include <stdio.h>

/*
Call by value: �ܺ� �Լ��� ���� ���� �ȿ��� ���� �ٲٸ� �ܺ� �Լ��� ���� ������ ����
(���ڷ� ���� ���� �����Ͽ� ó���� �Ѵ�)
Call by reference: �ܺ� �Լ��� ���� �״�� ���� ���� �ٲٸ� ���� �ٲ�
(���ڷ� ���� ���� �ּҸ� �����Ͽ� ���� ���� ������ �ش�)
������ ���� ���� ���縦 �Ͽ� ó���� �ϴ���, �ƴϸ� ���� ������ �ϴ��� ���̴�.
*/

//�Լ�����
void Add(int* _pStack, int _stackSize, ref int* _pIndex, int _data);
void Print(int* _pStack, int _stackSize, int* _pIndex);

void main() 
{
	//Stack: First in Last out, ������ ���� ������ �׾Ҵٰ� �� ������ ������ ��

	int stack[5] = { 0 };

	//�迭 ����� ���� ���ϱ�
	//stack �迭�� ũ��� 20byte, stack[0]�� ũ��� 4byte �̹Ƿ� 20���� 4�� ������ 5�� ���´�.
	int stackSize = sizeof(stack) / sizeof(stack[0]);
	int index = 0;

	/*if (index < 5)
	{
		stack[index] = 5;
		++index;
	}
	*/

	Add(stack, stackSize, &index, 5);
	Print(stack, stackSize, index);
	Add(stack, stackSize, &index, 3);
	Print(stack, stackSize, index);
}

//�Լ�����
void Add(int* _pStack, int _stackSize, ref int* _pIndex, int _data) 
{
	if (*_pIndex < _stackSize) 
	{
		_pStackp(*_pIndex);
		++(*_pIndex);
	}
}

void Print(int* _stack, int _stackSize, int _index) 
{
	if (_index == 0)
	{
		printf("Stack is empty!\n");
		return;
	}

	for (int i = 0; i < _index; ++i)
	{
		printf("%d - ", _stack[i]);
	}
	printf("(%d)\n", _index);
}

