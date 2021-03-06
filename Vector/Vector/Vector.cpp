//容器vector

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	for (int i = 1; i <= 5; i++)
		v1.push_back(i);         //向尾部添加元素
	vector<int>::iterator it = v1.begin();
	for (int i = 0; i < 5; i++)
	{
		cout << *(it + i) << " ";     //用迭代器遍历vector
	}
	cout << endl;
	v1.pop_back();              //删除尾元素
	cout << "size:" << v1.size() << endl;
	v1.insert(v1.begin() + 2, -1);
	for (int i = 0; i < v1.size(); i++)
	{
		cout << *(it + i) << " ";     //用迭代器遍历vector
	}
	cout << endl;
	v1.erase(v1.begin() + 2);          //删除v1[2]
	v1.erase(v1.begin() + 2, v1.begin() + 4);     //删除v1[2]、v1[3]
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	v1.clear();           //清空
	system("pause");
    return 0;
}

