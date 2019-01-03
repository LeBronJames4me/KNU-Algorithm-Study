#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)

using namespace std;

typedef struct location{
	int y;
	int x;
}location;

int main()
{
	int city;
	int m;
	int i, j;

	scanf("%d %d", &city, &m);

	vector<vector<int>> citymap(city, vector<int>(city, 0));
	vector<location> chickenLocation;
	vector<location> houseLocation;

	for (j = 0; j < city; j++)
	{
		for (i = 0; i < city; i++)
		{
			scanf("%d", &citymap[i][j]);
			if (citymap[i][j] == 1)//����ġ
			{
				houseLocation.push_back({ j,i });
			}
			if (citymap[i][j] == 2) //ġŲ����ġ
			{
				chickenLocation.push_back({ j,i });
			}
		}
	}
	//������ ġŲ�� �� M����ŭ �̾�, ������ ���·� ���� Ȯ���غ� ��

	vector<int> combination;
	for (i = 0; i < m; i++)//M����ŭ �̾ƾ��Ѵ�.
	{
		combination.push_back(1);
	}
	for (i = 0; i < chickenLocation.size() - m; i++)
	{
		combination.push_back(0);
	}

	sort(combination.begin(), combination.end());
	vector<location> chosenM;
	vector<int> result;
	do {
		for (i = 0; i < combination.size(); i++)
		{
			if (combination[i] == 1)
			{
				chosenM.push_back(chickenLocation[i]);
			}
		}
		//M�� �̾���
		//�� ������ M���� ġŲ���Ÿ������� ����ϰ�, ������ �ּڰ��� ���Ѵ�.
		int min = 9999;
		int sum = 0;
		for (i = 0; i < houseLocation.size(); i++)
		{
			for (j = 0; j < chosenM.size(); j++)
			{
				if (abs(houseLocation[i].y - chosenM[j].y) + abs(houseLocation[i].x - chosenM[j].x) < min)
					min = abs(houseLocation[i].y - chosenM[j].y) + abs(houseLocation[i].x - chosenM[j].x);
			}
			//i��° ������ ���� ����� ġŲ�� �Ÿ� ã��. 
			sum += min;
			min = 9999;
		}
		//��� ������ ����� ġŲ���Ÿ� �� ã��
		result.push_back(sum);
		chosenM.clear();

	} while (next_permutation(combination.begin(), combination.end()));

	sort(result.begin(), result.end());

	printf("%d", result[0]);
	system("pause");
}