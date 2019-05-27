#include<stdio.h>
#include<stdlib.h>

int* rotate(int **a,int *b,int k,int i,int j,int m,int n)
{
	
	if (m == n && m == 1)
	{
		b[k] = a[0][0];
		return b;
	}

	if (m == 2 && n == 1)
	{
		b[k++] = a[0][0];
		b[k] = a[1][0];
		return b;
	}

	if (m == 1 && n == 2)
	{
		b[k++] = a[0][0];
		b[k] = a[0][1];
		return b;
	}
	int initial_row = i, initial_col = j;
	for (; j < n; j++)
		b[k++] = a[i][j];

	j--; i++;
	for (; i < m; i++)
		b[k++] = a[i][j];

	i--; j--;
	for (; j >= initial_col; j--)
		b[k++] = a[i][j];

	j++; i--;
	for (; i >= initial_row+1; i--)
		b[k++] = a[i][j];

	
	b = rotate(a, b, k, initial_row + 1, initial_col + 1, m - 1, n - 1);
	return b;
}

int* rotate_iteration(int **a, int *b, int k, int i, int j, int m, int n)
{
	while (true)
	{
		if (m == n && m == 1)
		{
			b[k] = a[0][0];
			return b;
		}

		if (m == 2 && n == 1)
		{
			b[k++] = a[0][0];
			b[k] = a[1][0];
			return b;
		}

		if (m == 1 && n == 2)
		{
			b[k++] = a[0][0];
			b[k] = a[0][1];
			return b;
		}
		int initial_row = i, initial_col = j;
		for (; j < n; j++)
			b[k++] = a[i][j];

		j--; i++;
		for (; i < m; i++)
			b[k++] = a[i][j];

		i--; j--;
		for (; j >= initial_col; j--)
			b[k++] = a[i][j];

		j++; i--;
		for (; i >= initial_row + 1; i--)
			b[k++] = a[i][j];

		initial_row++;
		initial_col++;
		m--;
		n--;
	}
	return b;
}


int main()
{
	int **a;
	int m, n;
	printf("Enter m and n");
	scanf("%d%d", &m, &n);
	a = (int **)malloc(sizeof(int *)*m);
	for (int i = 0; i < m; i++)
		a[i] = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int *b = (int *)malloc(sizeof(int)*m*n);
	b=rotate(a,b,0,0,0,m,n);
	for (int i = 0; i < m*n; i++)
		printf("%d", b[i]);


	int *b_iter = (int *)malloc(sizeof(int)*m*n);
	b_iter = rotate_iteration(a, b_iter, 0, 0, 0, m, n);
	for (int i = 0; i < m*n; i++)
		printf("%d", b_iter[i]);

	system("pause");
}