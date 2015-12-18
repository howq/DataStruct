#include <stdio.h>
#include <string.h>

int table[26];

void shiftTable(char str[])
{
	int i;
	int lens = strlen(str);
	table[str[lens - 1] - 'A'] = lens;
	for (i = 0; i < lens - 1; i++)
	{
	table[str[i] - 'A'] = lens - i - 1;
	}
}

int horspoolMatch(char str[], char text[])
{
	int i, k;
	int strlens = strlen(str);
	int textlens = strlen(text);

	i = strlens - 1;
	shiftTable(str);
	while(i <= textlens - 1)
	{
		k = 0;
		while(str[strlens - 1 - k] == text[i - k] && k <= strlens - 1 )
		{
			k++; 
		}
		if (k == strlens)
		{
			return i - strlens + 1;
		}
		else
		{
			i += table[text[i] - 'A'];
		}
	}
	return -1;
}

int main()
{
int pos;
char str[102001], text[700001];

scanf("%s %s", str, text);
pos = horspoolMatch(str, text);
printf("%d\n", pos);

return 0;
}
