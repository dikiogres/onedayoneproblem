#include <iostream>   
#include <string.h>   

using namespace std;

int main()
{
	char str[1001], pass[10001];
	int i, j, cur, n, m, sum[10001], record[27], dp[1001][10001];
	bool flag;
	while (scanf("%s%s", str + 1, pass + 1) != EOF)
	{
		n = strlen(str + 1);
		m = strlen(pass + 1);
		sum[0] = 0;
		for (i = 0; i < 26; i++) record[i] = 0;
		for (i = 1; i <= m; i++) record[pass[i] - 'a']++;
		for (i = 1; i <= n; i++) if (str[i] >= 'a') record[str[i] - 'a']--;
		for (i = 0; i < 26; i++) if (record[i] < 0) break;
		if (i < 26)
		{
			printf("-1\n");
			continue;
		}
		for (i = 1; i <= m; i++) sum[i] = pass[i] - 'a' + 1 + sum[i - 1];
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++) dp[i][j] = 10000000;

		for (i = 0; i <= m; i++)
		{
			if (i > 0 && (str[1] == '?' || str[1] == pass[i])) dp[1][i] = sum[i] - sum[i - 1];
			else if (str[1] == '*') dp[1][i] = 0;
		}
		for (i = 2; i <= n; i++)
		{
			flag = 0;
			if (str[i] == '*')
			{
				cur = 10000000;
				if (dp[i - 1][0] == 0)
				{
					flag = 1;
					dp[i][0] = 0;
					cur = 0;
				}
				for (j = 1; j <= m; j++)
				{
					if (dp[i - 1][j] - sum[j] < cur) cur = dp[i - 1][j] - sum[j];
					if (sum[j] + cur<dp[i][j])
					{
						dp[i][j] = sum[j] + cur;
						flag = 1;
					}
				}
			}
			else
			{
				for (j = 1; j <= m; j++)
				{
					if (dp[i - 1][j - 1] == 10000000) continue;
					if (str[i] == '?' || str[i] == pass[j])
					{
						if (dp[i][j]>dp[i - 1][j - 1] + pass[j] - 'a' + 1)
						{
							dp[i][j] = dp[i - 1][j - 1] + pass[j] - 'a' + 1;
							flag = 1;
						}
					}
				}
			}
			if (!flag) break;
		}
		if (i <= n)
		{
			printf("-1\n");
			continue;
		}
		cur = 100000000;
		for (i = 0; i <= m; i++) if (cur > dp[n][i]) cur = dp[n][i];
		if (cur == 100000000) printf("-1\n");
		else printf("%d\n", cur);
	}
	return 0;
}