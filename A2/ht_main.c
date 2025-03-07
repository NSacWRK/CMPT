#include <stdio.h>
#include "ht.h"

extern int ht_get_capacity(hashtable ht);
extern int ht_get_count(hashtable ht);

int main() {
    hashtable ht = ht_create();
    if (!ht) {
        printf("Failed to create hashtable\n");
        return 1;
    }

    printf("Hashtable created successfully!\n");
    printf("Total capacity of the hashtable: %d\n", ht_get_capacity(ht));
    printf("Current number of elements in the hashtable: %d\n", ht_get_count(ht));

    ht_free(ht);
    printf("Hashtable freed successfully!\n");

    return 0;
}