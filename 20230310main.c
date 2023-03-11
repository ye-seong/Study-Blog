#include <stdio.h>

/*void SomethingFunc(); //��Ÿ��: �ܾ �����Ҷ����� �빮�ڸ� ��, ���������� ���� ����
void something_func(); //���: ��� �ҹ����̰� �ܾ ����� ����ٸ� ��, ����Ʈ�� ���� �ʾƵ� �ż� ���� ��

&����: �ش� ������ �ּҸ� ����*/

void main()
{
	/*int arr[3] = {0}; //arr�� ��� �迭�� 0���� �ʱ�ȭ, �����Ⱚ���� ������ �ʱ� ����*/

	int arr[3] = { 1,2,3 };
	printf("arr Size: %d byte\n", sizeof(arr)); //�迭�� ũ���̴�
	printf("arr Addresss: %p\n", arr); //�迭�� �ּ� (ù��° ����� �ּҿ� ����)

	//�迭�� �̸� = �迭�� ù��° ����� �ּ�

	for (int i = 0; i < 3; i++)
	{
		printf("arr[%d]: %d(%p)\n", i, arr[i], &arr[i]);
	}

	/*
	�������
		arr Size: 12 byte
		arr[0]: 1(0137F83C)
		arr[1]: 2(0137F840)
		arr[2]: 3(0137F844)

		��ȣ�� �迭�� �ּҰ��̴�. �� ���� ���� ���� �迭�� �󸶳��� ũ�⸦ �Ѱܶٴ��� �� �� �ִ�.
		1�� �ּҰ��� 0137F83C�̰� 2�� �ּҰ��� 0137F840�̹Ƿ� D,E,F,0�� ��, �� 4�� �ǳʶڴ�.
		int ���� ũ���� 4�� �ǳʶٴ� ���� �� �� �ִ�.
		ps.16�����̹Ƿ� A,B,C,D,E,F,0,1,2,3,4,5,6,7,8,9 �����̴�.
	*/

	printf("=============================================================\n");

	printf("arr + 0: %p\n", arr + 0);
	printf("arr + 1: %p\n", arr + 1);

	printf("=============================================================\n");

	//�޸��� �ּҰ��� �����ϴ� ���� Pointer
	int* dest = arr;
	printf("dest: %d\n", *(dest + 1));

	printf("=============================================================\n");

	//�������� �����̵� Pointer�� ������ 4byte ũ���̴�.
	printf("int* Size: %d byte\n", sizeof(int*));
	printf("char* Size: %d byte\n", sizeof(char*));
	printf("double* Size: %d byte\n", sizeof(double*));

	printf("=============================================================\n");

	//str ������ �迭 �� �� ��°�� 'e'�� ���
	char* str = "Test";
	printf("%c\n", str[1]);

	printf("=============================================================\n");

	//2���� �迭�� ������
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
	�������
	
	arr2D[0][0]: 11 (0059FC70)
	arr2D[0][1]: 12 (0059FC74)
	arr2D[0][2]: 13 (0059FC78)
	arr2D[1][0]: 21 (0059FC7C)
	arr2D[1][1]: 22 (0059FC80)
	arr2D[1][2]: 23 (0059FC84)
	
	�ּҰ��� 4byte�� �ǳʶٴ� ���� ���� ���� 2�� ���� 3�� ���簢���� ���·� �迭�� �ִ°��� �ƴ϶�
	2���� �迭 ���� ���ٷ� �� �ټ� �ִ� ���¶�� ������ �� �� �ִ�.
	�׷��Ƿ�
	
	*/

	int arr2Dtest[2][3] = {
		11, 12, 13,
		21, 22, 23
	};

	/*�� arr2D�� ����.*/

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
