#include <stdio.h>

/*void SomethingFunc(); //낙타법: 단어가 시작할때마다 대문자를 씀, 보편적으로 많이 쓰임
void something_func(); //뱀법: 모두 소문자이고 단어가 끊기면 언더바를 씀, 쉬프트를 쓰지 않아도 돼서 비교적 편리

&변수: 해당 변수의 주소를 들고옴*/

void main()
{
	/*int arr[3] = {0}; //arr의 모든 배열을 0으로 초기화, 쓰레기값으로 남기지 않기 위함*/

	int arr[3] = { 1,2,3 };
	printf("arr Size: %d byte\n", sizeof(arr)); //배열의 크기이다
	printf("arr Addresss: %p\n", arr); //배열의 주소 (첫번째 요소의 주소와 같다)

	//배열의 이름 = 배열의 첫번째 요소의 주소

	for (int i = 0; i < 3; i++)
	{
		printf("arr[%d]: %d(%p)\n", i, arr[i], &arr[i]);
	}

	/*
	결과값은
		arr Size: 12 byte
		arr[0]: 1(0137F83C)
		arr[1]: 2(0137F840)
		arr[2]: 3(0137F844)

		괄호는 배열의 주소값이다. 맨 끝의 값을 보면 배열이 얼마나의 크기를 넘겨뛰는지 알 수 있다.
		1의 주소값은 0137F83C이고 2의 주소값은 0137F840이므로 D,E,F,0의 값, 즉 4를 건너뛴다.
		int 값의 크기인 4를 건너뛰는 것을 볼 수 있다.
		ps.16진수이므로 A,B,C,D,E,F,0,1,2,3,4,5,6,7,8,9 순서이다.
	*/

	printf("=============================================================\n");

	printf("arr + 0: %p\n", arr + 0);
	printf("arr + 1: %p\n", arr + 1);

	printf("=============================================================\n");

	//메모리의 주소값을 저장하는 변수 Pointer
	int* dest = arr;
	printf("dest: %d\n", *(dest + 1));

	printf("=============================================================\n");

	//변수형이 무엇이든 Pointer은 무조건 4byte 크기이다.
	printf("int* Size: %d byte\n", sizeof(int*));
	printf("char* Size: %d byte\n", sizeof(char*));
	printf("double* Size: %d byte\n", sizeof(double*));

	printf("=============================================================\n");

	//str 문자의 배열 중 두 번째인 'e'를 출력
	char* str = "Test";
	printf("%c\n", str[1]);

	printf("=============================================================\n");

	//2차원 배열을 만들자
	int arr2D[2][3] = {
		{11,12,13},
		{21,22,23}
	};
	printf("arr2D Address: %p\n", arr2D);
	for (int row = 0; row < 2; ++row) 
	{
		for (int col = 0; col < 3; ++col)
		{
			printf("arr2D[%d][%d]: %d (%p)\n", row, col, arr2D[row][col], &arr2D[row][col]);
		}
	}

	/*
	결과값은
	
	arr2D[0][0]: 11 (0059FC70)
	arr2D[0][1]: 12 (0059FC74)
	arr2D[0][2]: 13 (0059FC78)
	arr2D[1][0]: 21 (0059FC7C)
	arr2D[1][1]: 22 (0059FC80)
	arr2D[1][2]: 23 (0059FC84)
	
	주소값이 4byte씩 건너뛰는 것을 보면 행이 2와 열이 3인 직사각형의 형태로 배열이 있는것이 아니라
	2차원 배열 또한 한줄로 쭉 줄서 있는 형태라고 이해할 수 가 있다.
	그러므로
	
	*/

	int arr2Dtest[2][3] = {
		11, 12, 13,
		21, 22, 23
	};

	/*도 arr2D와 같다.*/

	printf("=============================================================\n");

	printf("arr2D + 0: %p\n", arr2D + 0);
	printf("arr2D + 0: %p\n", arr2D + 1);
	printf("*(arr2D + 0) + 1: %p\n", *(arr2D + 0) + 1);
	printf("*(*(arr2D + 0) + 1): %d\n", *(*(arr2D + 0) + 1));

	printf("=============================================================\n");

	int makeArr1D[6] = { 11, 12, 13, 21, 22, 23 };
	int* arr0 = &makeArr1D[0];
	int* arr3 = &makeArr1D[3];
	int* makeArr2D[2] = { arr0, arr3 };
	int** destArr2D = makeArr2D;
	printf("arr0: %p\n", arr0);
	printf("arr3: %p\n", arr3);
	printf("*(destArr2D + 0): %p\n", *(destArr2D + 0));
	printf("*(destArr2D + 1): %p\n", *(destArr2D + 1));
	printf("destArr2D[0]: %p\n", destArr2D[0]);
	printf("destArr2D[1]: %p\n", destArr2D[1]);

	printf("destArr2D[0][1]: %d\n", (destArr2D[0])[1]);

	printf("=============================================================\n");

	
}
