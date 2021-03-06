//Queue队列，Priority_queue优先队列，底层用堆实现

#include<iostream>
#include<string>
#include<queue>
using namespace  std;

class fruit
{
public:
	string name;
	int price;
	friend bool operator < (fruit f1, fruit f2)
	{
		return f1.price > f2.price;
	}
};

class cmp
{
public:
	bool operator () (fruit f1, fruit f2)
	{
		return f1.price > f2.price;
	}
};

int main()
{
	queue<int> q;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2; //第二个参数承载底层heap的容器，如果第一个参数是double或char，也相应的改，第三个参数less<int>表示数字大的优先级大，greater<int>表示数字小的优先级大
	for (int i = 1; i <= 5; i++)
		q.push(i);
	cout << q.front() << " " << q.back() << endl;
	for (int i = 1; i <= 3; i++)
		q.pop();
	if (q.empty())
		cout << "Empty" << endl;
	else
		cout << "Not Empty" << endl;
	cout << q.size() << " " << q.front() << endl;
	pq1.push(3);
	pq1.push(4);
	pq1.push(5);
	cout << pq1.top() << endl;
	pq2.push(3);
	pq2.push(4);
	pq2.push(1);
	cout << pq2.top() << endl;
	priority_queue<fruit> pq3;
	priority_queue<fruit, vector<fruit>, cmp> pq4;   //与sort的cmp函数类似
	fruit f1, f2, f3;
	f1.name = "桃子";
	f1.price = 3;
	f2.name = "梨子";
	f2.price = 4;
	f3.name = "苹果";
	f3.price = 1;
	pq3.push(f1);
	pq3.push(f2);
	pq3.push(f3);
	cout << pq3.top().name << " " << pq3.top().price << endl;
	pq4.push(f1);
	pq4.push(f2);
	pq4.push(f3);
	cout << pq4.top().name << " " << pq4.top().price << endl;
	system("pause");
    return 0;
}

