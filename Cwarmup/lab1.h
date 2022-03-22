//
//  lab1.h
//  lab1
//
//  Created by YANG QI on 1/20/22.
//

#ifndef lab1_h
#define lab1_h

#include <stdio.h>
void sort(unsigned long array[],int n);
unsigned long byte_sort (unsigned long arg);
unsigned long nibble_sort (unsigned long arg);
struct elt *name_list (void);
void print_list(struct elt* head);
void free_list(struct elt* head);
void draw_me (void);
void xyzTests();


#endif /* lab1_h */
