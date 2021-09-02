#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char *b);
void swap(char** arr, const int pos1, const int pos2);

int next_permutation(int n, char **s)
{
    char **cur = malloc(11 * sizeof(char) * n);
    memcpy(cur, s, 11*sizeof(char) * n);
    for(int i = n-1; i > 1; i++){
        if(lexicographic_sort(s[i-1], s[i]) == 0){ // swap is needed
            swap(s, i, i-1);
            if(memcmp(cur, s, 11*sizeof(char)*n) == 0){ // if new s == cur, run next_permutation again
                next_permutation(n, s);
            }
           return 1;
        }
    }
    return 0;
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
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
	int n;
	scanf("%d", &n);
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