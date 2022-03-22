//
//  lab1.c
//  lab1
//
//  Created by YANG QI on 1/20/22.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "lab1.h"

/*********************************************************************
 *
 * These C functions use patterns and functionality often found in
 * operating system code. Your job is to implement them. Write some test
 * cases for each function ( stick them in a funciton called it xyzTests() or similar)
 * call your abcTests(), etc functions in main().
 *
 * Write your own tests for each function you are testing, then share/combine
 * tests with a classmate.  Try to come up with tests that will break people's code!
 * Easy tests don't catch many bugs!
 *
 * You may not use any global variables in your solution
 *
 *
 * You must compile in C mode (not C++).  If you compile from the commandline
 * run clang, not clang++. Submit your solution files on Canvas.
 *
 *********************************************************************/

/*
 this is a helper function for byte_sort
 */
void sort(unsigned long array[],int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j){
            if (array[i] > array[j]) {
                unsigned long item;
                item = array[i];
                array[i] = array[j];
                array[j] = item;
            }
        }
    }
}

/*********************************************************************
 *
 * byte_sort()
 *
 * specification: byte_sort() treats its argument as a sequence of
 * 8 bytes, and returns a new unsigned long integer containing the
 * same bytes, sorted numerically, with the smaller-valued bytes in
 * the lower-order byte positions of the return value
 *
 * EXAMPLE: byte_sort (0x0403deadbeef0201) returns 0xefdebead04030201
 * Ah, the joys of using bitwise operators!
 *
 * Hint: you may want to write helper functions for these two functions
 *
 *********************************************************************/

unsigned long byte_sort (unsigned long arg)
{
    unsigned long bytes[8];
    for (int i = 0 ; i < 8; i++){
        bytes[i] = arg & 0xff;
        arg = arg >> 8;
       // printf("The char is %lx:\n",bytes[i]);
    }
      sort( bytes,8);

    unsigned long ans = 0;
    for (int j = 0; j < 8;j++){
        //printf("bytes %lx:\n",bytes[j]);
        ans = ans | (bytes[j] << 8*j);
       // printf("ans %lx:\n",ans);
    }

    return ans;

}

/*********************************************************************
 *
 * nibble_sort()
 *
 * specification: nibble_sort() treats its argument as a sequence of 16 4-bit
 * numbers, and returns a new unsigned long integer containing the same nibbles,
 * sorted numerically, with smaller-valued nibbles towards the "small end" of
 * the unsigned long value that you return
 *
 * the fact that nibbles and hex digits correspond should make it easy to
 * verify that your code is working correctly
 *
 * EXAMPLE: nibble_sort (0x0403deadbeef0201) returns 0xfeeeddba43210000
 *
 *********************************************************************/

unsigned long nibble_sort (unsigned long arg)
{
    unsigned long bits[16];
    for (int i = 16 ; i > 0; i--){
        bits[16-i] = (arg >> 4*(i-1)) & 0x0f;
        //printf("The char is %x:\n",bits[16-i]);
    }

    sort(bits,16);

    unsigned long ans = 0;
    for (int j = 0; j < 16;j++){
        ans = ans | (bits[j] << 4*j);
        //printf("The sorted bits are %x:\n",bits[j]);
    }

    return ans;

}

/*********************************************************************
 *
 * name_list()
 *
 * specification: allocate and return a pointer to a linked list of
 * struct elts
 *
 * - the first element in the list should contain in its "val" field the first
 *   letter of your first name; the second element the second letter, etc.;
 *
 * - the last element of the linked list should contain in its "val" field
 *   the last letter of your first name and its "link" field should be a null
 *   pointer
 *
 * - each element must be dynamically allocated using a malloc() call
 * Note, that since we're using C, not C++ you can't use new/delete!
 * The analog to delete is the free() function
 *
 * - if any call to malloc() fails, your function must return NULL and must also
 *   free any heap memory that has been allocated so far; that is, it must not
 *   leak memory when allocation fails
 *
 *
 * Implement print_list and free_list which should do what you expect.
 * Printing or freeing a nullptr should do nothing
 * Note: free_list might be useful for error handling for name_list...
 *********************************************************************/

struct elt {
  char val;
  struct elt *link;
};

struct elt * newElt(char val){
    struct elt * Elt = (struct elt *) malloc(sizeof(struct elt));
    Elt -> val = val;
    Elt -> link = NULL;

    return Elt;
}

//void free_list(struct elt* head); /*so you can call free_list in name_list if you'd like*/
struct elt *name_list (void)
{
    //struct elt * elt =(struct elt *) malloc(4 * sizeof(struct elt));

    struct elt * first = newElt('y');
    struct elt * second = newElt('a');
    struct elt * third = newElt('n');
    struct elt * forth = newElt('g');

    struct elt * head = first;
    first ->link = second;
    second ->link = third;
    third -> link = forth;

    return head;

}

void print_list(struct elt* head){
        while(head != NULL){
            printf("%c ->", head->val);
            head = head->link;
        }
        printf("NULL\n");
        free_list(head);
}

void free_list(struct elt* head){
    if (head != NULL){
        free(head);
        free(head->link);
    }
}


/*********************************************************************
 *
 * draw_me()
 *
 * this function creates a file called me.txt which contains an ASCII-art
 * picture of you (it does not need to be very big).
 *
 * Use the C stdlib functions: fopen, fclose, fprintf, etc which live in stdio.h
 * don't use C++ iostreams
 *
 *
 *********************************************************************/

void draw_me (void)
{
    char *filename = "me.txt";
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
    }
    int MAX_LEN = 128;
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);

    fclose(fptr);
}

void xyzTests(){
    unsigned long arg1 = 0x0403deadbeef0201;
    unsigned long arg2 = 0x0403deadbeef0201;
    printf("byte_sort test:\n");
    printf("The result is %lx\n", byte_sort(arg1));
    printf("***********************************************\n");
    printf("nibble_sort test:\n");
    printf("The result is %lx\n", nibble_sort(arg2));
    printf("***********************************************\n");
    printf("Myname list is :\n");
    print_list(name_list());

    printf("***********************************************\n");
    printf("The draw_me result is:\n");
    draw_me();
}
