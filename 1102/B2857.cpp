//JUNGOL_BIGINNER_2857 : 세로읽기

#include <iostream>

using namespace std;

int main()
{
	char toy[5][20] = { NULL };
	int i, j;

	for (j = 0; j < 5; j++)
	{
		scanf("%s", &toy[j]);
	} 

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 5; j++) {
			if (toy[j][i] == NULL)
				continue;
			else
				printf("%c", toy[j][i]);
			}
		}
	return 0;
}