/*http://pat.zju.edu.cn/contests/pat-a-practise/1022
 简单模拟题，

 1.map映射的使用有一个讨巧的方式：常规的，对于1-5的查询情况，得设定两层的映射，即map<queryClass, map<char *, priorityqueue>>，
 实际上，完全可以用一层map<char *, priorityqueue>来实现，其中char*字符串做好1-5的标记即可。
 2.priority_queue使用priority_queue<string, vector<string>, greater<string>> 可以将基本数据类型转换为最小堆。
*/
#include<map>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	map<string, priority_queue<string, vector<string>, greater<string>>> map;

	cin >> n;
	getchar();
	string id, title, author, keywords, publisher, year;
	for (int i = 0; i != n; ++ i) {
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		getline(cin, keywords);
		getline(cin, publisher);
		getline(cin, year);
		int si = 0;
		while ((si =  keywords.find(" ")) != -1) {
			map["3: " + keywords.substr(0, si)].push(id);
			keywords = keywords.substr(si + 1, keywords.length() - si);
		}
		if (keywords != "")
			map["3: " + keywords].push(id);
		map["1: " + title].push(id);
		map["2: " + author].push(id);
		map["4: " + publisher].push(id);
		map["5: " + year].push(id);
	}

	cin >> n;
	getchar();
	string query;
	while( --n >= 0 ){
		getline(cin, query);
		cout << query << endl;
		if (map.count(query) != 0) {
			while(!map[query].empty()){
				cout << map[query].top() << endl;
				map[query].pop();
			}
		} else cout << "Not Found" << endl;
	}
}
