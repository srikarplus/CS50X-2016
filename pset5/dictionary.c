/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

node* head[26]; 
int total = 0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check( char* word)
{
   
    for(int i=0;i<46 && (*(word+i) != '\0');i++){
        
        word[i] = tolower(word[i]);
        
    }
    int hashcode = hash(word[0]);
    int rtn = checker(head[hashcode],word);
    if(rtn == 0)    return true;
    else return false;
    
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* fp = fopen(dictionary,"r");
    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    // node* head[26];    
    char buffer[46];
    while(fscanf(fp,"%s",buffer) == 1){
        
        for(int i=0;i<46 && (*(buffer+i) != '\0');i++){
        
        buffer[i] = tolower(buffer[i]);
        
    }
        
        
       total++; 
       if(feof(fp)) return true;
       
       
       int hashcode = hash(buffer[0]);
       push(&head[hashcode],buffer);
    }
    if(feof(fp))
        return true;

    
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return total;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i=0;i<26;i++){
        node* cursor = head[i];
        while(cursor != NULL){
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }head[i] = NULL;
    }
    int freecount = 0;
    for(int i=0;i<26;i++){
        if(head[i] == NULL) freecount++;
    }
    if(freecount == 26) return true;
    else    return false;
}


int hash(char ch){
    int ans = (int)ch - 97;
    return ans;
}

void push(node** head,char* naam){
    node* temp = malloc(sizeof(node));
    strcpy(temp->value, naam);
    
    temp->next = *head;
    *head = temp;
   
    return;
}


//returns 0 if the word is found else returns 1

int checker(node* head,const char* naam){
    int rtn = 1;
    while(head != NULL){
        rtn = strcmp(head->value,naam);
        if(rtn == 0)    return rtn;
        head = head->next;
    }
    return rtn;
}