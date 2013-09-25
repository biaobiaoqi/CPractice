#include<stdio.h>
#include<stdlib.h>
#include<cctype>
#include<string.h>
/*
 一道坑题，题意比较难完全弄清楚，特别是第一个和第二个值的选取判定。梳理如下：
 在第1，2个字符串中，按位比较，找到第一个相同的字符，满足属于[A, G]（大小写敏感）；再找到之后的属于[0, 9] 或者[A, N]（大小写敏感）的字符。最后在第3，4个字符串的比较中，找到第一个相同的字字母。
 */
char s1[61], s2[61], s3[61], s4[61];
char h[7][4] = { {"MON"}, {"TUE"}, {"WED"}, {"THU"}, {"FRI"}, {"SAT"}, {"SUN"}};

int main()
{
	scanf("%s%s%s%s",s1,s2,s3,s4);
	int day = -1, hour = -1, min = -1;
    
    for (int i = 0; s1[i] != 0 && s2[i] != 0; i ++) {
        if (s1[i] == s2[i]) {
            char ch = s1[i];
            if (ch <= 'G' && ch >= 'A' && day == -1) {
                day = ch - 'A';
            }else if (day != -1 ) {
                if (ch <= 'N' && ch >= 'A') {
                    hour = 10 + ch - 'A';
                    break;
                }else if (isdigit(ch)) {
                    hour = ch - '0';
                    break;
                }
            }
        }
    }
    
    for (int i = 0; s3[i] != 0 && s4[i] != 0; i ++) {
		if( s3[i] == s4[i] && isalpha(s3[i])){
			min = i;
			break;
            //	printf("min: %d\n", min);
		}
	}
    
    printf("%s %02d:%02d",h[day],hour,min);
    return 0;
}