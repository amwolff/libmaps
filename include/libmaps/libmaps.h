#ifndef LIBMAPS_H
#define LIBMAPS_H

typedef struct avl *map;

map make_map_int_int();

int *lookup(map m, int key);

int *insert(map m, int key, int data);

void delete(map m, int key);

#endif LIBMAPS_H