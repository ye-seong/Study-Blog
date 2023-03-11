#include <stdio.h>

/*
Call by value: 외부 함수의 값을 들고와 안에서 값을 바꾸면 외부 함수의 값은 변하지 않음
(인자로 받은 값을 복사하여 처리를 한다)
Call by reference: 외부 함수의 값을 그대로 들고과 값을 바꾸면 같이 바뀜
(인자로 받은 값의 주소를 참조하여 직접 값에 영향을 준다)
간단히 말해 값을 복사를 하여 처리를 하느냐, 아니면 직접 참조를 하느냐 차이다.
*/

//함수선언
void Add(int* _pStack, int _stackSize, ref int* _pIndex, int _data);
void Print(int* _pStack, int _stackSize, int* _pIndex);

void main() 
{
	//Stack: First in Last out, 데이터 들어온 순서로 쌓았다가 맨 위부터 끄집어 냄

	int stack[5] = { 0 };

	//배열 요소의 갯수 구하기
	//stack 배열의 크기는 20byte, stack[0]의 크기는 4byte 이므로 20에서 4를 나누면 5가 나온다.
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

//함수정의
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

