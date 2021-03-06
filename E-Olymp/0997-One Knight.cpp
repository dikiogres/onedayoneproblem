#include <iostream>
#include <vector>

using namespace std;

int n;
bool d[100][100];
vector<pair<int, pair<int, int>>> v;

void add(int a, int b, int c)
{
	if (1 <= a && a <= n && 1 <= b && b <= n && !d[a][b])
	{
		d[a][b] = true;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
}

int main()
{
	pair<int, int> x, y;
	cin >> n >> x.first >> x.second >> y.first >> y.second;
	v.push_back(make_pair(0, x));
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second == y)
		{
			cout << v[i].first << endl;
			return 0;
		}
		add(v[i].second.first + 1, v[i].second.second + 2, v[i].first + 1);
		add(v[i].second.first + 2, v[i].second.second + 1, v[i].first + 1);
		add(v[i].second.first - 1, v[i].second.second - 2, v[i].first + 1);
		add(v[i].second.first - 2, v[i].second.second - 1, v[i].first + 1);
		add(v[i].second.first + 1, v[i].second.second - 2, v[i].first + 1);
		add(v[i].second.first - 2, v[i].second.second + 1, v[i].first + 1);
		add(v[i].second.first - 1, v[i].second.second + 2, v[i].first + 1);
		add(v[i].second.first + 2, v[i].second.second - 1, v[i].first + 1);
	}
}