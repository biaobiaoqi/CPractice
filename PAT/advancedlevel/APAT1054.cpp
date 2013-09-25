#include <stdio.h>

int main()
{
    int n,m;
    int color = 0;
	int cad = 0;
	int count = 0;
    
	scanf("%d%d",&n, &m);
	int c = n*m;
	
	for (int i = 0; i != c; ++i){
		scanf("%d",&color);
		if (count == 0)
			cad = color;
		else if (cad == color)
			++ count;
		else
			-- count;
	}

	printf("%d\n", cad);

    return 0;
}
