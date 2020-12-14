#include <stdio.h>
int divisione_array(int *src, int divisore, int lunghezza, int *resto);

int main()
{
	int v[3] = { 1,2,3 };
	int resto[3];
	divisione_array(v, 3, 3, resto);
	for (int i = 0; i < 3; ++i)
		printf("%d", v[i]);
}