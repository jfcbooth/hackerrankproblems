#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define DEBUG

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void swap(triangle* tr, int pos1, int pos2){
    triangle temp = tr[pos1];
    tr[pos1] = tr[pos2];
    tr[pos2] = temp;
}

double tri_size(triangle tri){
    double p = ((tri.a + tri.b + tri.c)/2.0);
    return sqrt((p*(p-tri.a)*(p-tri.b)*(p-tri.c)));
}

int cmp_tris(triangle t1, triangle t2){
    return (tri_size(t1) > tri_size(t2) ? 1 : 0);
}

void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(cmp_tris(tr[j],tr[j-1]) == 0){
                swap(tr, j, j-1);
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		#ifdef DEBUG
			printf("%d %d %d %f\n", tr[i].a, tr[i].b, tr[i].c, tri_size(tr[i]));
		#else
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
		#endif
	}
	return 0;
}