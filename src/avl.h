#ifndef AVL_H
#define AVL_H

struct avl {
    struct avl_node *root;
};

struct avl_node {
    int key, data, height;
    struct avl_node *left, *right;
};

struct avl *make_avl();

struct avl_node *avl_delete(struct avl_node *r, int key);

struct avl_node *avl_insert(struct avl_node *r, struct avl_node *n);

struct avl_node *avl_search(struct avl_node *r, int key);

struct avl_node *make_avl_node(int key, int data);

void avl_clear(struct avl_node *r);

void avl_traversal_LNR(struct avl_node *n);

void avl_traversal_LRN(struct avl_node *n);

void avl_traversal_NLR(struct avl_node *n);

void avl_traversal_custom(struct avl_node *r, int print_distance);

#endif //AVL_H
