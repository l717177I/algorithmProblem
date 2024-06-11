#include <stdio.h>
#include <string.h>
#define MAX 10
char s[MAX + 2], str[MAX + 2];
char comp[3628800 + 2][MAX + 2];
int visited[MAX + 2];
int len = 0, sol = 0, wp = 0;

int lucky(void)
{
	char t = str[0];
	for (int i = 1; i < len; i++)
	{
		if (t == str[i]) return 0;
		t = str[i];
	}
	return 1;
}

int isTrue(void)
{
	for (int i = 0; i < wp; i++)
	{
		if (wp <= 1) break;
		if (!strcmp(comp[i], str)) return 0;	// 중복이면 짤
	}
	return 1;
}

void debug(void)
{
	for (int i = 0; i < len; i++) printf("%c", str[i]);
	printf("\n");
}

void dfs(int cnt)
{
	if (cnt == len - 1)
	{
		if (lucky() && isTrue())
		{
			debug();
			strcpy(comp[wp++], str);
			sol++;
		}
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if (visited[i]) continue;
		str[cnt] = s[i];
		visited[i] = 1;
		dfs(cnt + 1);
		str[cnt] = '\0';
		visited[i] = 0;
	}
}

int main(void)
{
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++) printf("%c", s[i]);
	printf(", len = %d\n", len);
	dfs(0);
	printf("%d\n", sol);
	return 0;
}
