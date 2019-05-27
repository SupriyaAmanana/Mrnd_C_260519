#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void compress(char *str)
{
	int i, m = 0, j = 0, l = 0, k = 0, count, c = 0, len = 0;
	char s;
	for (i = 0; str[j]; i = i + count)
	{
		s = str[j];
		count = 0;
		for (; str[i] == str[j]; j++)
			count++;
		if (count > 1)
		{
			str[m] = s;
			c = count;
			l = count;
			while (c > 0)
			{
				c = c / 10;
				len++;
			}
			k = len;
			while (len>0)
			{
				str[m + len] = (char)(count % 10 + 48);
				count = count / 10;
				len--;
			}
			m = m + k + 1;
			count = l;
		}
		if (count == 1)
			str[m++] = s;
	}
	str[m] = '\0';
}
void main()
{
	int n;
	scanf("%d", &n);
	char *str = (char *)malloc(sizeof(char) * n);
	printf("ENTER A string ");
	scanf("%s", str);
	compress(str);
	printf("%s\n", str);
	_getch();
}