#include <stdio.h>
#include <limits.h>

#define ERROR_CODE INT_MIN
#define DATA_TYPE int
typedef int DATA; //int�� DATA�� �ٲٰڴ�!

/*
Call by value: �ܺ� �Լ��� ���� ���� �ȿ��� ���� �ٲٸ� �ܺ� �Լ��� ���� ������ ����
(���ڷ� ���� ���� �����Ͽ� ó���� �Ѵ�)
Call by reference: �ܺ� �Լ��� ���� �״�� ���� ���� �ٲٸ� ���� �ٲ�
(���ڷ� ���� ���� �ּҸ� �����Ͽ� ���� ���� ������ �ش�)
������ ���� ���� ���縦 �Ͽ� ó���� �ϴ���, �ƴϸ� ���� ������ �ϴ��� ���̴�.

�����Ͽ���: �ۼ��ϴ� ���߿� ����
��Ÿ�ӿ���: �����ϴ� ���߿� ����
*/

//�Լ�����
void Push(int* _pStack, int _stackSize, int* _pIndex, int _data);		//void Push(���� �迭, ���� ũ��, ���� �ε���, ���� �� ������)
int Pop(const int* const _pStack, int* const _pIndex);
void Print(const int* const _pStack, int _stackSize, int* _pIndex);

/////////////////////////////////////////////////////////////////////////////////
#define TRUE 1
#define FALSE 0
int CheckStackOverflow(int _stackSize, int _index);
/////////////////////////////////////////////////////////////////////////////////


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

	//Push, Pop
	int pop = Pop(stack, &index);
	if (pop == ERROR_CODE) printf("Error!!\n");
	printf("pop: %d\n", pop);

	for (int i = 0; i < 10; ++i)
		Push(stack, stackSize, &index, i + 1);
	Print(stack, stackSize, index);

	printf("Pop: %d\n", Pop(stack, &index));
	Print(stack, stackSize, index);
}

//�Լ�����
void Push(int* _pStack, int _stackSize, int* _pIndex, int _data)
{
	//����ó��: ������ �߻��� ���� ������ �̸� ���Ƶ�
	//��ȯ�̶� �� �� ���� �����شٴ� �ǹ̷� ����. C#�� �ڵ����� ��ȯ�ǳ� C�� �����ʾ� �߸��ϸ� �����ʹ����� �Ͼ���� ����.
	if (_pStack == NULL) return;
	if (_pIndex == NULL) return;

	/*
	�ּ��� �޾ƺ��� ���� �����ϱ�, �ش� ������ ����ų���� �ڵ带 §�ٸ�
	�ƿ� �����Ͽ����� ����Բ� �Ѵ�.

	const: ������ ���� �տ� �ִٸ� ���� �������� ���ϰ� �ش� ������ ����� ���,
		   �ڿ� ������ ������ ���� ������ �� ������ ������ ����Ű�� �ּҰ��� ���� �Ұ���

	�Ʒ� �����ͺ��� p�� �ּҰ��� _pStack �ּҰ����� �����ϴ� �� (*p = 10;)��
	p�� �ּҰ��� 10���� �����ϴ� �� (p = _pStack;)�� �������ؼ�
	
	const int* const p = &i;
	
	�� �ۼ��ؾߵȴ�.
	*/

	int i = 0;		//���� i ����
	int* p = &i;	//p�� �ּҴ� i�� �ּ�
	p = _pStack;	//p�� _pStack �ּҷ� ����
	*p = 10;		//p�ּҸ� 10���� ����

	//if (*_pIndex < _stackSize) 
	if (!CheckStackOverflow(_stackSize, *_pIndex))
	{
		_pStack[*_pIndex] = _data;
		++(*_pIndex);
	}
}

int Pop(const int* const _pStack, int* const _pIndex)
{
	if (_pStack == NULL || _pIndex == NULL)
		return ERROR_CODE;

	if (*_pStack == 0) return ERROR_CODE;

	int returnValue = _pStack[*_pIndex - 1];
	--(*_pIndex);
	return returnValue;
}

void Print(const int* const _pStack, int _stackSize, int* _pIndex)
{
	if (_pIndex == 0)
	{
		printf("Stack is empty!\n");
		return;
	}

	for (int i = 0; i < _pIndex; ++i)
	{
		printf("%d - ", _pStack[i]);
	}
	printf("(%d)\n", _pIndex);
}

int CheckStackOverflow(int _stackSize, int _index)
{
	return (_index >= _stackSize) ? TRUE : FALSE;
}