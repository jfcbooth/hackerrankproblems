#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[k-1][m-1][n-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[k-1][m-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char* get_word(char* text, int word_len){
    char* temp = malloc(sizeof(char)*word_len+1);
    strncpy(temp, text, word_len+1);
    temp[word_len] = '\0';
    //printf("Temp = %s\n", temp);
    return temp;
}

char** get_sentence(char** sentence, int num_words){
    char** temp = malloc(sizeof(char*)*num_words+1);
    memcpy(temp, sentence, sizeof(char*)*num_words+1);
    return temp;
}

char*** get_paragraph(char*** paragraph, int num_sentences){
    char*** temp = malloc(sizeof(char**)*num_sentences+1);
    memcpy(temp, paragraph, sizeof(char**)*num_sentences+1);
    return temp;
}


char**** get_document(char* text){
    int word_len = 0;
    int num_paragraphs = 0;
    int num_sentences = 0;
    int num_words = 0;
    char**** doc = malloc(sizeof(char***)); // pointer for the doc
    char*** paragraph = malloc(sizeof(char**)); // pointer to point to the paragraphs
    char** sentence = malloc(sizeof(char*)); // made up of words
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == ' '){
            sentence = realloc(sentence, sizeof(char*)*(num_words+2));
            sentence[num_words++] = get_word(&text[i-word_len], word_len);
            sentence[num_words] = NULL;
            word_len = 0;
        } else if(text[i] == '.'){
            sentence = realloc(sentence, sizeof(char*)*(num_words+2));
            sentence[num_words++] = get_word(&text[i-word_len], word_len);
            sentence[num_words] = NULL;
            word_len = 0;
            paragraph = realloc(paragraph, sizeof(char**)*num_sentences+2);
            paragraph[num_sentences++] = get_sentence(sentence, num_words);
            paragraph[num_sentences] = NULL;
            num_words = 0;
        } else if(text[i] == '\n' || text[i] == '\0'){
            doc = realloc(doc, sizeof(char***)*num_paragraphs+2);
            doc[num_paragraphs++] = get_paragraph(paragraph, num_sentences);
            doc[num_paragraphs] = NULL;
            num_sentences = 0;
        } else{
            word_len++;
        }
    }

    //char(*)[10])paragraph[];
    // for(int i = 0; paragraph[i]; i++){
    //     for(int j = 0; paragraph[i][j]; j++){
    //         printf("%s ", paragraph[i][j]);
    //     }
    //    printf("\n");
    // }
    // for(int i = 0; paragraph[i] != '\0'; i++){
    //     for(int j = 0; paragraph[i][j] != '\0'; j++){
    //         printf("%s\n", paragraph[i][j]);

    //     }
    // }
}

// char**** get_document(char* text) {
// 	char**** doc = malloc(sizeof(char***)); // pointer for the doc
// 	char*** paragraph = malloc(sizeof(char**)); // pointer to point to the paragraphs
// 	char** sentence = malloc(sizeof(char*)); // made up of words
// 	char* word = malloc(sizeof(char)*1000);

// 	int num_paragraphs = 0;
// 	int num_sentences = 0;
// 	int num_words = 0;
// 	int num_chars = 0;
// 	for(int i = 0; i < strlen(text); i++){
// 		if(text[i] == ' '){ // end of word
//             strncpy(word, &text[i-num_chars], num_chars);
//             word[num_chars] = '\0';
//             sentence = realloc(sentence, sizeof(char*)*num_words+1); // add space for new word
//             sentence[num_words] = malloc(sizeof(char)*num_chars+1);
//             memcpy(sentence[num_words], word, (num_chars+1)*sizeof(char));
//             num_words++;
//             num_chars = 0;
//         } else if(text[i] == '.'){
//             memcpy(paragraph[num_sentences], sentence, sizeof(char**)*num_sentences+1);
//             num_sentences++;
//             num_words = 0;
// 		// } else if(text[i] == '\n'){
//         //     memcpy(doc[num_paragraphs], paragraph, sizeof(char**)*num_paragraphs+1);
//         //     num_paragraphs++;
//         //     num_sentences = 0;
// 		} else{
//             num_chars++;
//         }

// 	}


	// int num_paragraphs = 0;
	// for(int i = 0; i < strlen(text)+1; i++){
	// 	num_paragraphs+=(text[i] == '\n' || text[i] == '\0') ? 1 : 0;
	// }
	// char**** docs = malloc(sizeof(char****)*num_paragraphs); // allocate space for 2 pointers


	// for(int i = 0; i < num_paragraphs; i++){
	// 	docs[i] = malloc(sizeof(char***)); // allocate space for a pointer to each paragraph
	// }

// }


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}