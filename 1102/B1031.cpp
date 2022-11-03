//JUNGOL_BIGINNER_1031 : 빙고

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
	for (int j = 0; j < 5; j++) {					//내가 입력한 빙고
		for (int i = 0; i < 5; i++) {
			scanf("%d", &BINGO[j][i]);

			/*if (BINGO[j][i] == 0)				//입력한 값이 0일 경우 예외처리
				continue;*/
		}
	}

	for (int j = 0; j < 5; j++) {					//사회자
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

void width()		//가로
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
	printf("가로 : %d\n", finish);
}
	
void hight()		//세로
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
	printf("세로 : %d\n", finish);
}

void cross1()									// 대각선1: 우하향
{
	int i, j;
	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
	int line = 0;									// count == 5 일때 만들어지는 줄

	count = 0;
	for (j = 0; j < 5; j++) {
		if (BINGO[j][j] == 0)
			count++;
		if (count == 5)
			finish++;
	}
	printf("대각선1 : %d\n", finish);
}

void cross2()									// 대각선2: 우상향
{
	int i, j;
	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
	int line = 0;									// count == 5 일때 만들어지는 줄

	count = 0;
	for (j = 0; j < 5; j++) {
		if (BINGO[4 - j][j] == 0)
			count++;
		if (count == 5)
			finish++;
	}
	printf("대각선2 : %d\n", finish);
}



//#include <stdio.h>
//
//int cheolsu[5][5] = { NULL };					// 철수의 배열판
//int host[5][5] = { NULL };						// 사회자의 배열판					
//
//void search(int num);							// 철수와 사회자 숫자가 일치하는지 비교하는 함수
//void width();									// 가로에서 일치할 경우
//void height();									// 세로에서 일치할 경우
//void cross1();									// 대각선1(우하향)일 때 일치할 경우
//void cross2();									// 대각선2(우상향)일 때 일치할 경우
//
//int main()
//{
//
//	int i, j;
//	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
//	int line = 0;									// count == 5 일때 만들어지는 줄
//
//	//입력
//	for(int j=0; j<5; j++) {						// j: 행
//		for (int i = 0; i < 5; i++) {				// i: 열
//			scanf("%d", &cheolsu[j][i]);		// 철수가 입력한 빙고판
//		}
//	}
//
//	for (int j = 0; j < 5; j++) {
//		for (int i = 0; i < 5; i++) {
//			scanf("%d", &host[j][i]);			// 사회자가 부른 빙고판 순서
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
//				printf("빙고");
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
//	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
//	int line = 0;									// count == 5 일때 만들어지는 줄
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
//void width()									// 가로 (열을 비교)
//{
//	int i, j;
//	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
//	int line = 0;									// count == 5 일때 만들어지는 줄
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
//void height()									// 세로 (행을 비교)
//{
//	int i, j;
//	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
//	int line = 0;									// count == 5 일때 만들어지는 줄
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
//void cross1()									// 대각선1: 우하향
//{
//	int i, j;
//	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
//	int line = 0;									// count == 5 일때 만들어지는 줄
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
//void cross2()									// 대각선2: 우상향
//{
//	int i, j;
//	int count = 0;									// count: 사회자가 부른 숫자가 철수의 빙고판의 숫자와 일치할 때 count++
//	int line = 0;									// count == 5 일때 만들어지는 줄
//
//	count = 0;
//	for (j = 0; j < 5; j++) {
//		if (cheolsu[4 - j][j] == 0)
//			count++;
//		if (count == 5)
//			line++;
//	}
//}
