#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char *b);
void swap(char** arr, const int pos1, const int pos2);

int next_permutation(int n, char **s)
{
    int swapped;
    char **cur = malloc(11 * sizeof(char) * n);
    memcpy(cur, s, 11*sizeof(char) * n);
    swapped = find_swapped_point(n ,s); // find point we have permutated to
    if(swapped == n-1){ // completely sorted
        swap(s, n-1, n-2);
        return 1;
    }
    for(int i = swapped+1; i < n; i++){
    }
        
}

int find_swapped_point(int n, char **s){
    for(int i = 0; i < n-1; i++){
        if(lexicographic_sort(s[i], s[i+1]) == 1){
            return i;
            }
    }
    return n-1;
}


int lexicographic_sort(const char* a, const char* b) {

    //printf("Comparing a=%s, b=%s\n", a,b);
    for(int i = 0; i < (strlen(a) > strlen(b)) ? strlen(a) : strlen(b); i++){
        if(b[i] == 0){ // if we have reached the end of string b, it must come first
            return 1;
        } else if (a[i] == 0){
            return 0;
        } else if(a[i] < b[i]){
            return 0;
        } else if(a[i] > b[i]){
            return 1;
        }
    }
    return 1;
}


void swap(char** arr, const int pos1, const int pos2){
    char* temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}


int main()
{
	char **s;
	int n;	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}