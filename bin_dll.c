#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct node {
    struct node *left;
    struct node *right;
};

struct node *
convert_util_bin_dll(struct node *root) {
    if(root->left == NULL && root->right == NULL) {
        return root;
    }     
   
    if(root != NULL) {
        root->left = convert_bin_dll(root->left); 
        if(root->left) {
            root->left->right = root;
        }
        root->right = convert_bin_dll(root->right);
        if(root->right) {
            root->right->prev = root;
        }
        return root->right;
    } 
    return NULL;
}  

struct node *
tree_minimum(struct node *root) {
    if(root) {
        while(root->left != NULL) {
            root = root->left;
        }
    }

    return root;
}

void 
convert_bin_dll(struct node *root, struct node **list) {
   (*list) = (tree_minimum)(root); 
   (void) convert_util_bin_dll(root);
}    

