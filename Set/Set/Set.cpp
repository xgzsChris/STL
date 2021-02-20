// Set集合，内部自动有序且不含重复元素

#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> st;
	st.insert(3);
	st.insert(5);
	st.insert(2);
	st.insert(3);
	for (set<int>::iterator it=st.begin();it!=st.end();it++)
		cout << *it << " ";
	cout << endl;
	set<int>::iterator it = st.find(2);
	cout << *it;
	system("pause");
    return 0;
}

