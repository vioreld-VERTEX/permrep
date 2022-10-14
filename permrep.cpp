//#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//ifstream in("permrep.in");
//ofstream out("permrep.out");

int n, f[20], v[20];
char s[20];

void type()
{
	int i;

	for (i = 0; i < n; i++)
	{
		cout << s[v[i]];
	}

	cout << '\n';
}

void bkt(int k)
{
	if (k == n + 1)
	{
		type();
		return;
	}

	int i;

	for (i = 0; i < n; i++)
	{
		if (f[i] == 0)
		{
			v[k] = i;
			f[i] = 1;
			bkt(k + 1);
			f[i] = 0;
		}
	}
}


int main()
{
	cin >> s;

	n = strlen(s);

	sort(s, s + n);

	for (int i = 1; i < n; i++)
	{
		if ((char)s[i] == (char)s[i - 1])
		{
			strcpy_y(s + i, s + i + 1);
		}
	}

	bkt(1);

	return 0;
}