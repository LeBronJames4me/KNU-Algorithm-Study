#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int *code)
{
	int cnt=0;
	for (int i = 1;i <= 7;i++)
	{
		if (code[i] < code[i + 1])
			cnt++;
		else if (code[i] > code[i + 1])
			cnt--;
	}

	return cnt;
}
int main()
{
	int code[10];
	//puts("1~8숫자 연속 입력");

	for (int i = 1;i<= 8;i++)
		scanf("%1d", &code[i]);

	if (check(code) == 7)
		printf("ascending\n");
	else if (check(code) == -7)
		puts("descending");
	else puts("mixed");

	return 0;
}