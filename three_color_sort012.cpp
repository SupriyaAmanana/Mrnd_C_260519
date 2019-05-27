#include<stdio.h>
#include<stdlib.h>

void Display(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int * three_color_sort(int *a, int n)
{
	int first = 0, last = n - 1, mid = 0;
	while (a[first] == 0)
		first++;
	while (a[last] == 2)
		last--;
	mid = first;
	while(mid<last)
	{
		if (a[mid] == 0)
		{
			a[mid++] = a[first];
			a[first++] = 0;
		}
		else if (a[mid] == 2)
		{
			a[mid++] = a[last];
			a[last--] = 2;
		}
		else
			mid++;
		if (a[first] == 2)
		{
			a[first] = a[last];
			a[last--] = 2;
		}
		else if (a[last] == 0)
		{
			a[last] = a[first];
			a[first++] = 0;
		}
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
	a=three_color_sort(a, n);
	Display(a, n);
	system("pause");
}