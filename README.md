# libmaps
Associative maps built on top of the AVL tree for C programming language.

This super-simple library has no unit tests (I would discourage from using it in serious use) and supports only int-int maps (see example). This could be changed to any type (preferably void pointers), but for now I'm leaving this the way it is.

And it should be blazingly fast.

## Example
```
#include <stdlib.h>
#include <stdio.h>
#include "libmaps/libmaps.h"

int main() {
    map numbers = make_map_int_int();
    if (numbers == NULL) {
        return 1;
    }

    int *check;
    check = insert(numbers, 1, 4370483);
    if (check == NULL) {
        return 1;
    }
    check = insert(numbers, 2, 5501881);
    if (check == NULL) {
        return 1;
    }
    check = insert(numbers, 3, 7824519);
    if (check == NULL) {
        return 1;
    }

    int *number = lookup(numbers, 3);
    if (number == NULL) {
        return 1;
    }
    printf("(29) %d: %d\n", 3, *number);

    delete(numbers, 2);

    number = lookup(numbers, 2);
    if (number == NULL) {
        printf("(35) Number of ID 2 not found!\n");
    }

    return 0;
}
```

Output:
```
(29) 3: 7824519
(35) Number of ID 2 not found!
```