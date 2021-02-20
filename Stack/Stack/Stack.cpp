#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> s)
{
	cout << "当前堆栈为：" << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();            //弹出栈首元素
	}
	cout << endl;
}

int main()
{
	stack<int> s;
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	s.push(55);
	print(s);
	cout << "size：" << s.size() << endl;
	cout << "top：" << s.top() << endl;
	system("pause");
    return 0;
}

