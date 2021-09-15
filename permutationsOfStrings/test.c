#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char *b);
void swap(char** arr, const int pos1, const int pos2);

void reverse(char **s, int start, int end){
    char *temp;
    while(start<end){
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    return;
}

int next_permutation(int n, char **s) // n = 3
{
    // find k
    int k = n-2; // k = 1
    while((lexicographic_sort(s[k], s[k+1]) == 1)){
        if(k == 0){
            return 0; // no permutation exists
        }
        k--;
    }
    // find i
    int i = n-1;
    while((lexicographic_sort(s[k], s[i]) == 1) && (i > k)){
        i--;
    }
    // swap the two
    swap(s, k, i);
    //printf("%d %d\n", k+1, n-1);
    // reverse the remaining
    reverse(s, k+1, n-1);
    //printf("here\n");
    return 1;
        
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