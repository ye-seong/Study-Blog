#include <stdio.h>
#include <limits.h>

#define ERROR_CODE INT_MIN
#define DATA_TYPE int
typedef int DATA; //int를 DATA로 바꾸겠다!

/*
Call by value: 외부 함수의 값을 들고와 안에서 값을 바꾸면 외부 함수의 값은 변하지 않음
(인자로 받은 값을 복사하여 처리를 한다)
Call by reference: 외부 함수의 값을 그대로 들고과 값을 바꾸면 같이 바뀜
(인자로 받은 값의 주소를 참조하여 직접 값에 영향을 준다)
간단히 말해 값을 복사를 하여 처리를 하느냐, 아니면 직접 참조를 하느냐 차이다.

컴파일오류: 작성하는 도중에 오류
런타임오류: 실행하는 도중에 오류
*/

//함수선언
void Push(int* _pStack, int _stackSize, int* _pIndex, int _data);		//void Push(스텍 배열, 스텍 크기, 현재 인덱스, 삽입 할 데이터)
int Pop(const int* const _pStack, int* const _pIndex);
void Print(const int* const _pStack, int _stackSize, int* _pIndex);

/////////////////////////////////////////////////////////////////////////////////
#define TRUE 1
#define FALSE 0
int CheckStackOverflow(int _stackSize, int _index);
/////////////////////////////////////////////////////////////////////////////////


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

//함수정의
void Push(int* _pStack, int _stackSize, int* _pIndex, int _data)
{
	//예외처리: 문제가 발생할 수도 있으니 미리 막아둠
	//반환이란 다 쓴 것을 돌려준다는 의미로 쓰임. C#은 자동으로 반환되나 C는 되지않아 잘못하면 데이터누수가 일어날수도 있음.
	if (_pStack == NULL) return;
	if (_pIndex == NULL) return;

	/*
	주석을 달아봤자 보지 않으니까, 해당 문제를 일으킬만한 코드를 짠다면
	아예 컴파일오류가 생기게끔 한다.

	const: 포인터 변수 앞에 있다면 값을 변경하지 못하고 해당 변수를 상수로 취급,
		   뒤에 있으면 변수의 값은 변경할 수 있으나 변수가 가리키는 주소값은 변경 불가능

	아래 포인터변수 p의 주소값을 _pStack 주소값으로 변경하는 것 (*p = 10;)과
	p의 주소값을 10으로 변경하는 것 (p = _pStack;)을 막기위해서
	
	const int* const p = &i;
	
	로 작성해야된다.
	*/

	int i = 0;		//변수 i 생성
	int* p = &i;	//p의 주소는 i의 주소
	p = _pStack;	//p를 _pStack 주소로 변경
	*p = 10;		//p주소를 10으로 설정

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