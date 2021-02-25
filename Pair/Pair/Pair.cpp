//Pair

#include<iostream>
#include<string>
#include<map>      //或#include<utility>
using namespace std;

int main()
{
	pair<string, int> p;
	p.first = "haha";
	p.second = 5;
	p = make_pair("xixi",55);
	cout << p.first << " " << p.second << endl;
	pair<int, int> p1(5, 10), p2(5, 15), p3(10, 5);
	if (p1 < p3)
		cout << "p1 < p3" << endl;
	if (p1 <= p3)
		cout << "p1 <= p3" << endl;
	if (p1 < p2)
		cout << "p1 < p2" << endl;
	map<string, int> mp;
	mp.insert(make_pair("heihei", 5));
	mp.insert(pair<string, int>("haha", 10));
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << endl;
	system("pause");
    return 0;
}

