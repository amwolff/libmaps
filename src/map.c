#include <stdlib.h>
#include "avl.h"
#include "libmaps/libmaps.h"

static int success = 0;

map make_map_int_int() {
    return make_avl();
}

int *lookup(map m, int key) {
    struct avl_node *n = avl_search(m->root, key);
    if (n == NULL) {
        return NULL;
    }
    return &n->data;
}

int *insert(map m, int key, int data) {
    struct avl_node *n = make_avl_node(key, data);
    if (n == NULL) {
        return NULL;
    }

    m->root = avl_insert(m->root, n);

    return &success;
}

void delete(map m, int key) {
    m->root = avl_delete(m->root, key);
}
