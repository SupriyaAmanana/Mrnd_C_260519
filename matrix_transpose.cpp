#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **a;
	int m, n;
	printf("Enter m and n");
	scanf("%d%d", &m, &n);
	a = (int **)malloc(sizeof(int *)*m);
	for (int i = 0; i < m; i++)
		a[i] = (int *)malloc(sizeof(int)*n);

	int **aTr;
	aTr = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
		aTr[i] = (int *)malloc(sizeof(int)*m);


	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			aTr[j][i] = a[i][j];

	printf("TRANSPOSE OF A MATRIX\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", aTr[i][j]);
		}
		printf("\n");
	}
	system("pause");
}