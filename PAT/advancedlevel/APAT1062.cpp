#include<stdio.h>
#include<stdlib.h>

/*
 qsort的应用。注意理清楚比较的条件关系。
 */
int L, H, N;
struct person {
    long long id;
    int v, t, sum, l;
} ps[100005];

int compare (void const *a, void const *b)
{
    person *aa = (person *)a;
    person *bb = (person *)b;
    if (aa->l == bb->l) {
        if (aa->sum == bb->sum) {
            if (aa->v == bb->v) {
                return  aa->id - bb->id;
            }
            return bb->v - aa->v;
        }
        return bb->sum - aa->sum;
    }
    return aa->l - bb->l;
}

int main()
{
	scanf("%d %d %d", &N, &L, &H);
    int index = 0;
    for (int i = 0; i != N; i ++) {
        scanf("%lld %d %d", &ps[index].id, &ps[index].v, &ps[index].t);
        if (ps[index].v >= L && ps[index].t >= L) {
            ps[index].sum = ps[index].v + ps[index].t;
            if ( ps[index].v >= H && ps[index].t >= H)
                ps[index].l = 1;
            else if (ps[index].v >= H)
                ps[index].l = 2;
            else if (ps[index].v >= ps[index].t)
                ps[index].l = 3;
            else
                ps[index].l = 4;
            
            index ++;
        }
    }
    
    qsort(ps, index, sizeof(person), compare);
    printf("%d\n", index);
    for (int i = 0; i != index; i ++) {
        printf("%lld %d %d\n", ps[i].id, ps[i].v, ps[i].t);
    }
    
    return 0;
}