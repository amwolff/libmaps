#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct avl *make_avl() {
    struct avl *t = malloc(sizeof(struct avl));
    if (t == NULL) {
        return t;
    }

    t->root = NULL;

    return t;
}

int avl_height(struct avl_node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

struct avl_node *avl_rotate_left(struct avl_node *n) {
    struct avl_node *x = n->right;
    struct avl_node *st = x->left;


    x->left = n;
    n->right = st;

    n->height = 1 + max(avl_height(n->left), avl_height(n->right));
    x->height = 1 + max(avl_height(x->left), avl_height(x->right));
    return x;
}

struct avl_node *avl_rotate_right(struct avl_node *n) {
    struct avl_node *x = n->left;
    struct avl_node *st = x->right;

    x->right = n;
    n->left = st;

    n->height = 1 + max(avl_height(n->left), avl_height(n->right));
    x->height = 1 + max(avl_height(x->left), avl_height(x->right));
    return x;
}

int avl_node_balance(struct avl_node *n) {
    if (n == NULL) {
        return 0;
    }
    return avl_height(n->left) - avl_height(n->right);
}

struct avl_node *avl_search_min(struct avl_node *n) {
    struct avl_node *x = n;
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

struct avl_node *avl_delete(struct avl_node *r, int key) {
    if (r == NULL) {
        return r;
    }

    if (key < r->key) {
        r->left = avl_delete(r->left, key);
    } else if (key > r->key) {
        r->right = avl_delete(r->right, key);
    } else {
        if (r->left == NULL) {
            struct avl_node *x = r->right;
            free(r);
            return x;
        } else if (r->right == NULL) {
            struct avl_node *x = r->left;
            free(r);
            return x;
        }

        struct avl_node *x = avl_search_min(r->right);

        r->key = x->key;
        r->data = x->data;

        r->right = avl_delete(r->right, x->key);
    }

    r->height = 1 + max(avl_height(r->left), avl_height(r->right));

    int balance = avl_node_balance(r);
    if (balance > 1 && avl_node_balance(r->left) >= 0) {
        return avl_rotate_right(r);
    } else if (balance > 1 && avl_node_balance(r->left) < 0) {
        r->left = avl_rotate_left(r->left);
        return avl_rotate_right(r);
    } else if (balance < -1 && avl_node_balance(r->right) <= 0) {
        return avl_rotate_left(r);
    } else if (balance < -1 && avl_node_balance(r->right) > 0) {
        r->right = avl_rotate_right(r->right);
        return avl_rotate_left(r);
    }

    return r;
}

struct avl_node *avl_insert(struct avl_node *r, struct avl_node *n) {
    if (r == NULL) {
        return n;
    }

    if (n->key < r->key) {
        r->left = avl_insert(r->left, n);
    } else if (n->key > r->key) {
        r->right = avl_insert(r->right, n);
    } else {
        return r;
    }

    r->height = 1 + max(avl_height(r->left), avl_height(r->right));

    int balance = avl_node_balance(r);
    if (balance > 1 && n->key < r->left->key) {
        return avl_rotate_right(r);
    } else if (balance > 1 && n->key > r->left->key) {
        r->left = avl_rotate_left(r->left);
        return avl_rotate_right(r);
    } else if (balance < -1 && n->key > r->right->key) {
        return avl_rotate_left(r);
    } else if (balance < -1 && n->key < r->right->key) {
        r->right = avl_rotate_right(r->right);
        return avl_rotate_left(r);
    }

    return r;
}

struct avl_node *avl_search(struct avl_node *r, int key) {
    if (r == NULL || r->key == key) {
        return r;
    } else if (key < r->key) {
        return avl_search(r->left, key);
    }
    return avl_search(r->right, key);
}

struct avl_node *make_avl_node(int key, int data) {
    struct avl_node *n = malloc(sizeof(struct avl_node));
    if (n == NULL) {
        return n;
    }

    n->key = key;
    n->data = data;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void avl_clear(struct avl_node *r) {
    if (r == NULL) {
        return;
    }
    avl_clear(r->left);
    avl_clear(r->right);
    free(r);
}

void avl_traversal_LNR(struct avl_node *n) {
    if (n == NULL) {
        return;
    }
    avl_traversal_LNR(n->left);
    printf("%d\n", n->key);
    avl_traversal_LNR(n->right);
}

void avl_traversal_LRN(struct avl_node *n) {
    if (n == NULL) {
        return;
    }
    avl_traversal_LRN(n->left);
    avl_traversal_LRN(n->right);
    printf("%d\n", n->key);
}

void avl_traversal_NLR(struct avl_node *n) {
    if (n == NULL) {
        return;
    }
    printf("%d\n", n->key);
    avl_traversal_NLR(n->left);
    avl_traversal_NLR(n->right);
}

void avl_traversal_custom(struct avl_node *r, int print_distance) {
    if (r == NULL) {
        return;
    }

    print_distance += 10;

    avl_traversal_custom(r->right, print_distance);

    printf("\n");
    for (int i = 10; i < print_distance; i++) {
        printf(" ");
    }
    printf("%d\n", r->key);

    avl_traversal_custom(r->left, print_distance);
}