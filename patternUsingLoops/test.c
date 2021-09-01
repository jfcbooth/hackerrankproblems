#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int width = (n*2)-1;
    int height = width;
    int half_height = floor(height/2);
    int half_width = floor(width/2);
    int distance_from_edge = 0;
    int add_to_i = 0;
    for(int i = 0; i < height; i++){
        if(i > half_height){
            add_to_i+=-2;
        }
        int last_value = n;
        for(int j = 0; j < width; j++){
            printf("%d ", last_value);
            if(j < i+add_to_i){ // first half, left side
                last_value --;
            } else if(j+i+1+add_to_i>=width){ //first half, right side
                last_value++;
            }
        }
    printf("\n");

    }
        
    return 0;
}
