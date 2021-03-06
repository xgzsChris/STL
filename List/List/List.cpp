//链表

#include<iostream>
#include<list>
#include <algorithm>  //使用STL中的算法需要包含此头文件
using namespace std;

class A
{
private:
	int n;
public:
	A(int n_) { n = n_; }
	friend bool operator < (const A & a1, const A & a2);
	friend bool operator ==(const A & a1, const A & a2);
	friend ostream & operator <<(ostream & o, const A & a);
};
bool operator < (const A & a1, const A & a2)
{
	return a1.n < a2.n;
}
bool operator ==(const A & a1, const A & a2)
{
	return a1.n == a2.n;
}
ostream & operator <<(ostream & o, const A & a)
{
	o << a.n;
	return o;
}
template<class T>
void print(T first, T last)
{
	for (; first != last; first++)
		cout << *first << " ";
	cout << endl;
}
int main()
{
	A a[5] = { 1,3,3,4,2 };
	A b[7] = { 10,30,20,30,30,40,40 };
	cout << 5 / 2 << endl;
	list<A> lst1(a, a + 5), lst2(b, b + 7);
	lst1.sort();                      //内部是快排
	cout << "1)";
	print(lst1.begin(), lst1.end());
	lst1.remove(2);                  //删除所有和A(2)相等的元素
	cout << "2)";
	print(lst1.begin(), lst1.end());
	lst2.pop_front();                //删除第一个元素
	cout << "3)"; 
	print(lst2.begin(), lst2.end());
	lst2.unique();                   //删除所有和前一个元素相等的元素
	cout << "4)"; 
	print(lst2.begin(), lst2.end());
	lst2.sort();
	lst2.unique();                   //形成集合
	cout << "5)";
	print(lst2.begin(), lst2.end());
	lst1.merge(lst2);                //合并lst2到lst1并清空lst2
	cout << "6)"; 
	print(lst1.begin(), lst1.end());
	cout << "7)"; 
	print(lst2.begin(), lst2.end());
	lst1.reverse();                  //颠倒lst1
	cout << "8)";
	print(lst1.begin(), lst1.end());
	lst2.insert(lst2.begin(), a + 1, a + 4);  //在lst2中插入三个元素
	//print(lst2.begin(),lst2.end());
	list <A>::iterator p1, p2, p3;
	p1 = find(lst1.begin(), lst1.end(), 30);  //InputIterator find (InputIterator first, InputIterator last, const T& val);	其中，first 和 last 为输入迭代器，[first, last) 用于指定该函数的查找范围；val 为要查找的目标元素。
	p2 = find(lst2.begin(), lst2.end(), 3);
	p3 = find(lst2.begin(), lst2.end(), 4);
	lst1.splice(p1, lst2, p2, p3);   //将[p2, p3)插入p1之前，并从 lst2 中删除[p2,p3)
	cout << "9)"; 
	print(lst1.begin(), lst1.end()); 
	cout << "10)"; 
	print(lst2.begin(), lst2.end());
	system("pause");
    return 0;
}

