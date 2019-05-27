#include<stdio.h>
#include<stdlib.h>

void Display(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);
}

int * sort_by_count(int *a,int n)
{
	int count = 0,i;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
			count++;
	}
	for (i = 0; i < n - count; i++)
		a[i] = 0;
	for (; i < n; i++)
		a[i] = 1;
	return a;
}

int * sort_by_sum(int *a, int n)
{
	int sum = 0,i;
	for (int i = 0; i < n; i++)
		sum = sum + a[i];
	for (i = 0; i < n - sum; i++)
		a[i] = 0;
	for (; i < n; i++)
		a[i] = 1;
	return a;
}

int * sort_by_swap(int *a, int n)
{
	int first = 0, last = n - 1;
	while (first<last)
	{
		if (a[first] == 1 && a[last] == 0)
		{
			int temp = a[first];
			a[first] = a[last];
			a[last] = temp;
			first++;
			last--;
		}
		if (a[first] == 0)
			first++;
		if (a[last] == 1)
			last--;
	}
	return a;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	a=sort_by_count(a,n);
	Display(a, n);
	sort_by_sum(a,n);
	Display(a, n);
	sort_by_swap(a,n);
	Display(a, n);
	system("pause");
}