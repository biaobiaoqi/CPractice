//
//  main.c
//  BBQ
//
//  Created by biaobiaoqi  on 13-4-17.
//  Copyright (c) 2013年 biaobiaoqi. All rights reserved.
//

#include <stdio.h>
const int MAXVALUE = 1001;
int a[MAXVALUE];

int main(int argc, const char * argv[])
{
    int min = MAXVALUE;
    int n, m;
    int tmp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i != n; ++i) {
        scanf("%d",&tmp);
        if (tmp < m) {
            int tmpMin = tmp < m - tmp ? tmp : m - tmp;
            if (a[m - tmp] == 1 && tmpMin < min) {
                min = tmpMin;
            }
            a[tmp] = 1;            
        }
    }
    
    if (min != MAXVALUE) printf("%d %d\n", min, m - min);
    else printf("No Solution");
    
    return 0;
}

