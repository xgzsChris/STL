// Union-find Set并查集，A和B是好朋友，B和C是好朋友，则A和C也是好朋友,输入n表示人的个数，m表示好朋友的组数，其中人的编号为1~n

#include<iostream>
using namespace std;

int father[100];         //存放父亲结点
int isRoot[100];         //记录每个节点是否作为某个集合的根结点

int findFather(int x)     //查找x所在集合的根结点
{
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a])       //路径压缩
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b)       //合并a和b所在的集合
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[faA] = faB;
}
void init(int n)               //初始化father[i]为i，且flag[i]为0
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = 0;
	}
}
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;        //输入两个好朋友的关系
		Union(a, b);
	}
	for (int i = 1; i <= n; i++)
		isRoot[findFather(i)]++;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] != 0)
			ans++;
	}
	cout << ans << endl;
	int x, y;
	cin >> x >> y;
	if (findFather(x) == findFather(y))
		cout << "Yse" << endl;
	else
		cout << "No" << endl;
	system("pause");
    return 0;
}

