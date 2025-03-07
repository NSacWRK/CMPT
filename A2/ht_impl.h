/* ht_impl.h
 *
 * For any "private"  declarations that should not be visible to the public
 * users of the hash table, but might want to be shared across various source
 * files in the hash table implementation.
 * 
 * It is a common convention to append "_impl" to a private implementation of
 * some public interface, so we do so here.
 *
 * Author: <TODO: your name here>
 * Lab instructor: <TODO: Your lab instructor's name here>
 * Lecture instructor: <TODO: Your lecture instructor's name here>
 */


/* TODO: think of some things that should go in here! */

//the hash table needs to have key:value pair (city:postalCodes)
//here is the struct of the hash tables which decides: how we store the key, value pairs, and we can package them together. 

#ifndef HT_IMPL_H
#define HT_IMPL_H

#include <stdlib.h>
#include <string.h>

/* Define a structure for a hash table entry */
typedef struct ht_entry {
    char *key; //this has to be int 
    void *value; //change this later on 
} ht_entry;


#endif

