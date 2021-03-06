//Multiset 插入一个数，删除一个数都能够在O(logn)的时间内完成，而且能时刻保证序列中的数是有序的，而且序列中可以存在重复的数

#include<iostream>                                // For standard streams
#include <iomanip>                                // For stream manipulators
#include <string>                                 // For string class
#include <sstream>                                // For istringstream
#include <algorithm>                              // For replace_if() & for_each()
#include <set>                                    // For map container
#include <iterator>                               // For advance()
#include <cctype>                                 // For isalpha()
using namespace std;

int main()
{
	int x;
	cin >> x;
	multiset<int> ms1;
	while (x!=0)
	{
		ms1.insert(x);
		cin >> x;
	}
	while (!ms1.empty())
	{
		multiset<int>::iterator c = ms1.begin();
		cout << *c << " ";
		ms1.erase(c);
	}
	cout << endl;
	//分析单词出现次数
	//在输入过程中移除了输入中的非字母字符。单词是由 foreach 从 istringstream 对象的文本中提取的，然后把它们传给了一个 lambda 表达式，这个表达式是 for_each() 的最后一个参数，用来创建 multiset 容器中的元素。
	//从 text 中获取的每个单词都被单独保存，因为一般来说，容器中会出现重复的元素。for 循环遍历 multiset 容器 words 中的迭代器，从指向第一个元素的开始迭代器开始。容器中的元素是有序的，因而相等的元素位置是连续的。通过调用容器的成员函数 count()，可以获取和它的参数 iter 所指向元素相等的元素的个数。
	//每次循环迭代结束后，iter 被设为 upper_bound() 返回的值，它指向一个不同于当前元素的元素。如果不存在这样的元素，upper_bound() 会返回容器的结束迭代器，循环就此结束。
	cout << "Enter some text and enter * to end:" << endl;
	string text_in{};
	getline(cin, text_in, '*');
	// Replace non-alphabetic characters by a space
	replace_if(begin(text_in), end(text_in), [](const char& ch) { return !isalpha(ch); }, ' ');
	istringstream text(text_in);             // Text input string as a stream
	istream_iterator<string> begin(text);    // Stream iterator
	istream_iterator<string> end;            // End stream iterator
	multiset<string> words;                  // Container to store words
	size_t max_len{};                            // Maximum word length
	// Get the words, store in the container, and find maximum length
	for_each(begin, end, [&max_len, &words](const string& word) {
		words.emplace(word);
		max_len = std::max(max_len, word.length());
	});
	size_t per_line{ 4 },                           // Outputs per line
		count{};                               // No. of words output
	for (auto iter = std::begin(words); iter != std::end(words); iter = words.upper_bound(*iter))
	{
		cout << left << setw(max_len + 1) << *iter << setw(3) << right << words.count(*iter) << "  ";
		if (++count % per_line == 0)
			cout << endl;
	}
	cout << std::endl;
	system("pause");
    return 0;
}

