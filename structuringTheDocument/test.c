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

struct word get_word(char* text, int word_len){
    struct word word;
    word.data = malloc(sizeof(char)*word_len+1);
    strncpy(word.data, text, word_len);
    word.data[word_len] = '\0';
    return word;
}

struct sentence get_sentence(struct sentence sentence){
    struct sentence s;
    s.data = malloc(sizeof(struct word*)*(sentence.word_count+1));
    memcpy(s.data, sentence.data, sizeof(struct word*)*(sentence.word_count+1));
    //s.data = sentence.data;
    s.word_count = sentence.word_count;
    return s;
}

struct document get_document(char* text) {
    struct sentence sentence;
    sentence.data = malloc(sizeof(struct word*));
    sentence.word_count = 0;
    struct paragraph paragraph;
    paragraph.data = malloc(sizeof(struct sentence*));
    paragraph.sentence_count = 0;
    struct document doc;
    doc.data = malloc(sizeof(struct paragraph*));
    doc.paragraph_count = 0;

    int word_len = 0;
    for(int i = 0; i < strlen(text)+1; i++){
        switch(text[i]){
            case ' ':
                sentence.data = realloc(sentence.data, sizeof(struct word)*(sentence.word_count+1));
                sentence.data[sentence.word_count] = get_word(&text[i-word_len], word_len);
                sentence.word_count++;
                word_len = 0;
                break;
            case '.':
                sentence.data = realloc(sentence.data, sizeof(struct word)*(sentence.word_count+1));
                sentence.data[sentence.word_count] = get_word(&text[i-word_len], word_len);
                sentence.word_count++;
                word_len = 0;
                paragraph.data = realloc(paragraph.data, sizeof(struct sentence*)*paragraph.sentence_count+1);
                paragraph.data[paragraph.sentence_count] = get_sentence(sentence);
                paragraph.sentence_count++;
                sentence.word_count = 0;
                break;
            // case '\n':
            // case '\0':
            //     break;
            default:
                word_len++;
                break;
        }
    }
    // for(int i = 0; i < paragraph.sentence_count; i++){
    //     for(int j = 0; j < paragraph.data[i].word_count; j++){
    //         printf("%s\n", paragraph.data[i].data[j].data);
    //     }
    // }

    for(int i = 0; i < sentence.word_count; i++){
        printf("%s\n", sentence.data[i].data);
    }

    for(int i = 0; i < sentence.word_count; i++){
        free(sentence.data[i].data);
    }
    free(sentence.data);
    free(paragraph.data);
    free(doc.data);

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