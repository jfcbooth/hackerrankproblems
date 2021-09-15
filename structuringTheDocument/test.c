#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

void reallocate(struct word* word, int size){
    struct word *temp = malloc(sizeof(struct word));
    temp = realloc(word->data, size);
    if(temp == NULL){
        printf("allocation error\n");
        exit(1);
    } else{
        word = temp;
    }
}

struct word get_word(char *text, int size){
    //reallocate(word, size+1);
    struct word word;
    word.data = malloc(sizeof(char *)*(size+1));
    strncpy(word.data, text, size);
    word.data[size] = '\0';
    return word;
}

// struct sentence get_sentence(){

// }

int find_sentence_size(struct sentence s){
    int size = 0;
    for(int i = 0; i < s.word_count; i++){
        size+=(sizeof(char)*strlen(s.data[i].data));
    }
    return size;
}

struct sentence get_sentence(struct sentence sentence){
    struct sentence s;
    memcpy(s.data, sentence.data, find_sentence_size(sentence));
    s.word_count = sentence.word_count;
    return s;
}

struct document get_document(char* text) {
    struct document doc;
    doc.paragraph_count = 0;

    struct paragraph paragraph;
    paragraph.sentence_count = 0;
    doc.data = malloc(sizeof(struct paragraph*)); // get enough space for 1 pointer to a paragraph

    struct sentence sentence;
    sentence.word_count = 0;
    paragraph.data =  malloc(sizeof(struct sentence*)); // get enough space for 1 pointer to a sentence


    int word_len = 0;
    void* ptr;
    for(int i = 0; i < strlen(text)+1; i++){
       switch(text[i]){
            // case '\n':
            // case '\0':
            case '.':
                sentence.data = realloc(sentence.data, sizeof(struct word*)*(sentence.word_count+1)); // add space in the sentence for X pointers to X words
                sentence.data[sentence.word_count] = get_word(&text[i-word_len], word_len); // copy the word to the pointer
                sentence.word_count++;
                word_len = 0;

                paragraph.data = realloc(paragraph.data, sizeof(struct sentence)*(paragraph.sentence_count+1)); // add space for X pointers to X sentences
                paragraph.data[paragraph.sentence_count] = get_sentence(sentence);
                //memcpy(&paragraph.data[paragraph.sentence_count], &sentence, find_sentence_size(sentence)); // copy current sentence into paragraph by value
                //memcpy(&paragraph->data[paragraph->sentence_count], sentence, sizeof(struct)); 
                paragraph.sentence_count++;

                //printf("Copied %s\n", paragraph->data->data->data);
                sentence.word_count = 0; // reset the sentence
                break;
            case ' ':
                sentence.data = realloc(sentence.data, sizeof(struct word*)*(sentence.word_count+1)); // add space in the sentence for X pointers to X words
                sentence.data[sentence.word_count] = get_word(&text[i-word_len], word_len); // copy the word to the pointer
                sentence.word_count++;
                word_len = 0;
                break;
            default:
                word_len++;
                break;
       }
   }
    //printf("%s\n", sentence.data[0].data);
    for(int j = 0; j < paragraph.sentence_count; j++){
        for(int i = 0; i < paragraph.data[j].word_count; i++){
            printf("%s ", paragraph.data[j].data[i].data);
        }
        printf("\n");
    }
    // for(int i = 0; i < sentence.word_count; i++){
    //     printf("%s\n", sentence.data[i].data);
    // }
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {

}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 

}

struct paragraph kth_paragraph(struct document Doc, int k) {

}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);
    free(text);
    // int q;
    // scanf("%d", &q);

    // while (q--) {
    //     int type;
    //     scanf("%d", &type);

    //     if (type == 3){
    //         int k, m, n;
    //         scanf("%d %d %d", &k, &m, &n);
    //         struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
    //         print_word(w);
    //     }

    //     else if (type == 2) {
    //         int k, m;
    //         scanf("%d %d", &k, &m);
    //         struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
    //         print_sentence(sen);
    //     }

    //     else{
    //         int k;
    //         scanf("%d", &k);
    //         struct paragraph para = kth_paragraph(Doc, k);
    //         print_paragraph(para);
    //     }
    //     printf("\n");
    // }     
}