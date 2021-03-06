// Map

#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<char, int> mp;
	mp['c'] = 20;
	mp['c'] = 30;
	cout << mp['c'] << endl;
	mp['m'] = 20;
	mp['r'] = 30;
	mp['a'] = 40;
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << endl;              //自动从小到大排序，内部由红黑树实现
	map<char, int>::iterator it = mp.find('a');
	cout << it->first << " " << it->second << endl;
	mp.erase(it);
	system("pause");
    return 0;
}

