/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1036
 简单模拟题
 */
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace::std;

int main()
{
    int maxF = -1;
    char fName[11], fID[11], mName[11], mID[11], name[11], id[11], flag;
    int minM = 101;
    int n, score;
    
    cin >> n;
    while ( n -- ) {
        cin >> name >> flag >> id >> score;
        if (flag == 'M') {
            if (score < minM ) {
                minM = score;
                strcpy(mName, name);
                strcpy(mID, id);
            }
        }else {
            if (score > maxF) {
                maxF = score;
                strcpy(fName, name);
                strcpy(fID, id);
            }
        }
    }
    
    if (maxF != -1) cout << fName << " " << fID << endl;
    else cout << "Absent" << endl;
    
    if (minM != 101) cout << mName << " " << mID << endl;
    else cout << "Absent" << endl;
    
    if (maxF == -1 || minM == 101) cout << "NA" << endl;
    else cout << (maxF - minM)  << endl;
    
}