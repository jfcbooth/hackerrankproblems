#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// alphabetical sort
int lexicographic_sort(const char* a, const char* b) {
    for(int i = 0; i < strlen(a); i++){
        if(b[i] == 0){
            return 1;
        } else if(a[i] < b[i]){
            return 0;
        }
    }
    return 1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
}

int sort_by_length(const char* a, const char* b) {

}

void swap(char** arr, const int pos1, const int pos2){
    char* temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}


void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0; j--){
            printf("cmp: %d\n", cmp_func(arr[j],arr[j-1]));
            if(cmp_func(arr[j],arr[j-1]) == 1){
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

    // string_sort(arr, n, lexicographic_sort_reverse);
    // for(int i = 0; i < n; i++)
    //     printf("%s\n", arr[i]); 
    // printf("\n");

    // string_sort(arr, n, sort_by_length);
    // for(int i = 0; i < n; i++)
    //     printf("%s\n", arr[i]);    
    // printf("\n");

    // string_sort(arr, n, sort_by_number_of_distinct_characters);
    // for(int i = 0; i < n; i++)
    //     printf("%s\n", arr[i]); 
    // printf("\n");
}