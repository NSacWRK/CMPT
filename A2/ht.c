/* ht.c
 *
 * Implements a hashtable.
 *
 * Author: Naval
 * Lecture Instructor: Ardy
 */

 #include "ht.h"      /* Import the public hashtable header. */
 #include "ht_impl.h" /* Also import the private header, just for us! */
 #include <stdlib.h>  // For malloc(), free(), calloc()
 #include <stdio.h>   // For printf()
 #include <string.h>  // For strdup()
 #include "ht_main.c"
 
 #define INITIAL_SIZE 10  // Starting size of the hash table
 
 /* Define the hashtable structure */
struct ht {
    int size;        // Total number of available slots
    int count;       // Number of elements stored
    ht_entry **entries; // Array of pointers to hash table entries
};

/* Creates an empty hashtable */
hashtable ht_create(void) {
    hashtable ht = malloc(sizeof(struct ht));
    if (!ht) return NULL;  // Memory allocation failed

    ht->size = INITIAL_SIZE;
    ht->count = 0;

    // Allocate memory for the array of hash table entries
    ht->entries = calloc(ht->size, sizeof(ht_entry *));
    if (!ht->entries) {
        free(ht);
        return NULL;
    }

    return ht;
}

/* Frees all memory associated with the hashtable */
void ht_free(hashtable ht) {
    if (!ht) return;

    for (int i = 0; i < ht->size; i++) {
        if (ht->entries[i]) {
            free(ht->entries[i]->key);
            free(ht->entries[i]->value);
            free(ht->entries[i]);
        }
    }

    free(ht->entries);
    free(ht);
}

// Function to get the hashtable capacity 
int ht_get_capacity(hashtable ht) {
    return ht ? ht->size : -1; // Return -1 if NULL
}

// Function to get the number of elements 
int ht_get_count(hashtable ht) {
    return ht ? ht->count : -1; // Return -1 if NULL
}