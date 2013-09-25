#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
	bool hash[256] = {0};
	string s;
	getline(cin, s);

	char ch;
	while((ch = getchar()) != '\n'){
		hash[ch] = 1;
	}

	int size = s.size();
	for (int i = 0 ; i!= size; ++i )
		if (!hash[s[i]])
			printf("%c",s[i]);

	getchar();
}
