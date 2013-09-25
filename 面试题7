#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> s1, s2;
int main()
{
	freopen("G:\in.txt", "r", stdin);
	int n, value;
	cin >> n;
	while (n -- ){
		string op;
		cin >> op;
		if (op[1] == 'U') {
			cin >> value;
			s1.push(value);
		}else {
			if (s2.empty()) {
				while(!s1.empty()) {
					value = s1.top();
					s1.pop();
					s2.push(value);
				}
			}
			if (s2.empty()) {
				cout << -1 << endl;
			}else {
				value = s2.top();
				s2.pop();
				cout << value << endl;
			}
		}
	}
	fclose(stdin);
	return 0;
}
