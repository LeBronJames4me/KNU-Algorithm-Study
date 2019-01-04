#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

typedef struct location {
	int y;
	int x;
	location(int coord_y, int coord_x)
	{
		y = coord_y;
		x = coord_x;
	}

}location;

int** cityMap;
int** color;
int citySize;
vector<int> result;
queue<location> Q;

void BFS(int rain)
{
	int i, j;
	int blackCnt = 0;

	//�ʱ�ȭ �� ������� ����
	for (j = 0; j < citySize; j++)
	{
		for (i = 0; i < citySize; i++)
		{
			if (cityMap[j][i] <= rain)//���̰� ������ ����
			{
				color[j][i] = BLACK;
				blackCnt++;
			}
			else
				color[j][i] = WHITE;
		}
	}

	//ù ��° ������ ���� ã��
	bool find = false;
	for (j = 0; j < citySize; j++)
	{
		for (i = 0; i < citySize; i++)
		{
			if (color[j][i] == WHITE)
			{
				find = true;
				break;
			}
		}
		if (find == true)
			break;
	}
	if (find == true)
	{
		location start({ j, i });
		Q.push(start);
	}
	else //������ ���� �� �������
	{
		blackCnt = citySize * citySize;
	}

	int district = 0;

	while (blackCnt != citySize * citySize)
	{
		while (!Q.empty())
		{
			location now = Q.front();
			Q.pop();

			int dx[4] = { 1,-1,0,0 };
			int dy[4] = { 0,0,1,-1 };

			for (i = 0; i < 4; i++)
			{
				int nextY = now.y + dy[i];
				int nextX = now.x + dx[i];

				if ((nextY < citySize && nextX < citySize && nextY >= 0 && nextX >= 0) && color[nextY][nextX] == WHITE)
				{
					location next({ nextY,nextX });
					color[nextY][nextX] = GRAY;
					Q.push(next);
				}
			}

			color[now.y][now.x] = BLACK;
			blackCnt++;

		}
		district++; //�����ϳ� ã��

		if (blackCnt == citySize * citySize)
			break;

		//���� ���� ã��
		find = false;
		for (j = 0; j < citySize; j++)
		{
			for (i = 0; i < citySize; i++)
			{
				if (color[j][i] == WHITE)
				{
					find = true;
					break;
				}
				
			}
			if (find == true)
				break;
		}
		if (find == true)
		{
			location start({ j, i });
			Q.push(start);
		}
	}

	result.push_back(district);
}

int main()
{
	int highest=0;
	int i, j;

	scanf("%d", &citySize);

	cityMap = (int**)malloc(sizeof(int*)*citySize);
	color = (int**)malloc(sizeof(int*)*citySize);

	for (i = 0; i < citySize; i++)
	{
		cityMap[i] = (int*)malloc(sizeof(int)*citySize);
		color[i] = (int*)malloc(sizeof(int)*citySize);
	}

	for (j = 0; j < citySize; j++)
	{
		for (i = 0; i < citySize; i++)
		{
			scanf("%d",&cityMap[j][i]);
			if (highest < cityMap[j][i])	//���� ���� ��ġ ���س���.
			{
				highest = cityMap[j][i];
			}
		}
	}

	//�� ���� �ʴ� 0���� highest-1����.
	//starting point�� �׻� 0,0�̹Ƿ� ���� �Ķ���ͷ� �Ѱ����� �ʴ´�.
	int rain;
	for (rain = 0; rain < highest; rain++)
	{
		BFS(rain);
	}
	sort(result.begin(), result.end());
	printf("%d", result[result.size()-1]);

	system("pause");
}