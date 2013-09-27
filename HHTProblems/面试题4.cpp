#include <stdio.h>
#include <vector>
using namespace std;
vector<char> v;

int main()
{
	freopen("G:\in.txt", "r", stdin);
	char ch;
	int length = 0;
	int whiteSpaceLength = 0;
	while(scanf("%c", &ch)!= EOF){
		v.push_back(ch);
		++ length;
		if (ch == ' ') {
			++ whiteSpaceLength;
		}
	}
	v.push_back('\0');
	++length;
	v.resize(length + whiteSpaceLength*2);
	
	int originalIndex = length - 1;
	int newIndex = length + whiteSpaceLength*2 - 1;
	while (originalIndex >= 0 && originalIndex < newIndex) {
		if (v[originalIndex] == ' ') {
			v[newIndex --] = '0';
			v[newIndex --] = '2';
			v[newIndex --] = '%';
		}else {
			v[newIndex --] = v[originalIndex];
		}
		-- originalIndex;
	}
	
	newIndex = 0;
	while(v[newIndex]){
		printf("%c",v[newIndex++]);	
	}	
	return 0;
}
