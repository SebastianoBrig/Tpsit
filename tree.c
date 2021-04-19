#include <stdio.h>
#include <stdlib.h>

typedef struct Stree_node{
    int key;
    int val;
    struct Stree_node *left;
    struct Stree_node *right;

}tree_node;

void insert(tree_node **tree, tree_node *new_node){
    if (*tree==NULL){
        *tree=new_node;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else {
        if (new_node->key<(*tree)->key){
            insert(&(*tree)->left, new_node);
        }
        else if(new_node->key>(*tree)->key){
            insert(&(*tree)->right,new_node);
        }
        else {
            printf("chiave duplicata\n");
        }
    }
}

void in_order_view(tree_node *tree){
    if (tree!=NULL){
        in_order_view(tree->left);
        printf("Key %d, Value &d\n", tree->key, tree->val);
        in_order_view(tree->right);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
