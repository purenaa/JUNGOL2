//JUNGOL_BIGINNER_1031 : ����

#include <stdio.h>

void search(int num);
void width();
void hight();
void cross1();
void cross2();

int BINGO[5][5] = { NULL };
int i, j;
int call[5][5];
int count = 0, finish = 0;
int speak = 0;

int count2 = 0;

int main()
{
	for (int j = 0; j < 5; j++) {					//���� �Է��� ����
		for (int i = 0; i < 5; i++) {
			scanf("%d", &BINGO[j][i]);

			/*if (BINGO[j][i] == 0)				//�Է��� ���� 0�� ��� ����ó��
				continue;*/
		}
	}

	for (int j = 0; j < 5; j++) {					//��ȸ��
		for (int i = 0; i < 5; i++) {
			scanf("%d", &call[j][i]);
		}
	}

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			finish = 0;

			search(call[j][i]);
			width();
			hight();
			cross1();
			cross2();

			printf("-----------------------\n");
			speak++;
			
			if (finish >= 3)
			{
				printf("%d", speak);
				return 0;
			}
		}
		
	}
	return 0;
}

void search(int num)
{
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 5; i++) {
			if (BINGO[j][i] == num)
				BINGO[j][i] = 0;
		}
	}

}

void width()		//����
{
	for (j = 0; j < 5; j++) {
		count = 0;
		for (i = 0; i < 5; i++) {
			if (BINGO[j][i] == 0)
			{
				count++;
			}
			if (count == 5)
			{
				finish++;
			}
		}
	}
	printf("���� : %d\n", finish);
}
	
void hight()		//����
{
	for (i = 0; i < 5; i++) {
		count = 0;
		for (j = 0; j < 5; j++) {
			if (BINGO[j][i] == 0)
			{
				count++;
			}
			if (count == 5)
			{
				finish++;
			}

		}
	}
	printf("���� : %d\n", finish);
}

void cross1()									// �밢��1: ������
{
	int i, j;
	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
	int line = 0;									// count == 5 �϶� ��������� ��

	count = 0;
	for (j = 0; j < 5; j++) {
		if (BINGO[j][j] == 0)
			count++;
		if (count == 5)
			finish++;
	}
	printf("�밢��1 : %d\n", finish);
}

void cross2()									// �밢��2: �����
{
	int i, j;
	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
	int line = 0;									// count == 5 �϶� ��������� ��

	count = 0;
	for (j = 0; j < 5; j++) {
		if (BINGO[4 - j][j] == 0)
			count++;
		if (count == 5)
			finish++;
	}
	printf("�밢��2 : %d\n", finish);
}



//#include <stdio.h>
//
//int cheolsu[5][5] = { NULL };					// ö���� �迭��
//int host[5][5] = { NULL };						// ��ȸ���� �迭��					
//
//void search(int num);							// ö���� ��ȸ�� ���ڰ� ��ġ�ϴ��� ���ϴ� �Լ�
//void width();									// ���ο��� ��ġ�� ���
//void height();									// ���ο��� ��ġ�� ���
//void cross1();									// �밢��1(������)�� �� ��ġ�� ���
//void cross2();									// �밢��2(�����)�� �� ��ġ�� ���
//
//int main()
//{
//
//	int i, j;
//	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
//	int line = 0;									// count == 5 �϶� ��������� ��
//
//	//�Է�
//	for(int j=0; j<5; j++) {						// j: ��
//		for (int i = 0; i < 5; i++) {				// i: ��
//			scanf("%d", &cheolsu[j][i]);		// ö���� �Է��� ������
//		}
//	}
//
//	for (int j = 0; j < 5; j++) {
//		for (int i = 0; i < 5; i++) {
//			scanf("%d", &host[j][i]);			// ��ȸ�ڰ� �θ� ������ ����
//		} 
//	}
//
//	for (int j = 0; j < 5; j++) {
//		for (int i = 0; i < 5; i++) {
//			line = 0;
//
//			search(host[j][i]);
//			width();
//			height();
//			cross1();
//			cross2();
//
//			if (line >= 3)
//				printf("����");
//			break;
//		}
//	}
//	return 0;
//}
//
//
//void search(int num)
//{
//	int i, j;
//	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
//	int line = 0;									// count == 5 �϶� ��������� ��
//	count = 0;
//
//	for (j = 0; j < 5; j++) {
//		for (i = 0; i < 5; i++) {
//			if (cheolsu[j][i] == num)
//				cheolsu[j][i] = 0;
//		}
//	}
//}
// 
//void width()									// ���� (���� ��)
//{
//	int i, j;
//	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
//	int line = 0;									// count == 5 �϶� ��������� ��
//
//	count = 0;
//	for (j = 0; j < 5; j++) {
//		for (i = 0; i < 5; i++) {
//			if (cheolsu[j][i] == host[j][i])
//				count++;
//			if (count == 5)
//				line++;
//		}
//	}
//}
//
//void height()									// ���� (���� ��)
//{
//	int i, j;
//	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
//	int line = 0;									// count == 5 �϶� ��������� ��
//
//	count = 0;
//	for (i = 0; i < 5; i++) {
//		for (j = 0; j < 5; j++) {
//			if (cheolsu[j][i] == host[j][i])
//				count++;
//			if (count == 5)
//				line++;
//		}
//	}
//}
//
//void cross1()									// �밢��1: ������
//{
//	int i, j;
//	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
//	int line = 0;									// count == 5 �϶� ��������� ��
//
//	count = 0;
//	for (j = 0; j < 5; j++) {
//		if (cheolsu[j][j] == 0)
//			count++;
//		if (count == 5)
//			line++;
//	}
//}
//
//void cross2()									// �밢��2: �����
//{
//	int i, j;
//	int count = 0;									// count: ��ȸ�ڰ� �θ� ���ڰ� ö���� �������� ���ڿ� ��ġ�� �� count++
//	int line = 0;									// count == 5 �϶� ��������� ��
//
//	count = 0;
//	for (j = 0; j < 5; j++) {
//		if (cheolsu[4 - j][j] == 0)
//			count++;
//		if (count == 5)
//			line++;
//	}
//}
