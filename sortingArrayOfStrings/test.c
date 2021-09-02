#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// alphabetical sort, return 0 if a is first, 1 if b is first
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

int lexicographic_sort_reverse(const char* a, const char* b) {
    return (lexicographic_sort(a,b) == 1) ? 0 : 1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int unique_chars_a[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int unique_chars_b[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int sum_a = 0;
    int sum_b = 0;
    // error lines
    for(int i = 0; i < strlen(a); i++){
        unique_chars_a[(int)(a[i]-97)]++;
    }
        for(int i = 0; i < strlen(b); i++){
        unique_chars_b[(int)(b[i]-97)]++;
    }
    // end of error lines
    for(int i = 0; i < 26;i++){
        sum_a += ((unique_chars_a[i] > 0) ? 1 : 0);
        sum_b += ((unique_chars_b[i] > 0) ? 1 : 0);
    }
    if(sum_a > sum_b){
        return 1;
    } else if(sum_a < sum_b){
        return 0;
    } else{
        return lexicographic_sort(a,b);
    }
    return 0;
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) < strlen(b)){
        return 0;
    } else if(strlen(a) > strlen(b)){
        return 1;
    } else{
        return lexicographic_sort(a,b);
    }
    return 0;
}

void swap(char** arr, const int pos1, const int pos2){
    char* temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}


void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0; j--){
            if(cmp_func(arr[j],arr[j-1]) == 0){
                swap(arr, j, j-1);
            }
        }
    }
} // hello



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}