#include <stdio.h>
#include <stdlib.h>

struct BSTTreeNode
{
    int value;
    struct BSTTreeNode *l;
    struct BSTTreeNode *r;
};
struct BSTTreeNode *head = NULL;

struct BSTTreeNode*NODE(int item, struct BSTTreeNode *l, struct BSTTreeNode *r)
{
    struct BSTTreeNode *t = malloc(sizeof *t);
    t->value = item;
    t->l = l; t->r = r;
    return t;
}
struct BSTTreeNode *insert_node(struct BSTTreeNode *t, int value)
{
    if (t==NULL) return NODE(value, NULL, NULL);
    if      (value < t->value)
    t->l = insert_node(t->l, value);
    else if (value > t->value)
    t->r = insert_node(t->r, value);
    return t;
}
void treetodoublelist(struct BSTTreeNode *t)
{
    static struct BSTTreeNode *pcurrent = NULL;
    t->l = pcurrent;
    if (NULL == pcurrent)
    head = t;
    else
    pcurrent->r = t;
    pcurrent = t;
}
void in_ord(struct BSTTreeNode *t)
{
    if (t==NULL) return;
    in_ord(t->l);
    treetodoublelist(t);
    in_ord(t->r);
}
void in_ord_show(struct BSTTreeNode *t)
{
    if (t==NULL) return;
    in_ord_show(t->l);
    printf("%d\n", t->value);
    in_ord_show(t->r);
}
void show_list(struct BSTTreeNode *h)
{
    struct BSTTreeNode *p;
    if (h == NULL) return;
    for (p = h; p != NULL; p = p->r)
    printf("%d\n", p->value);
    
}
int main(int argc, char *argv[])
{
    struct BSTTreeNode *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 6);
    root = insert_node(root, 14);
    root = insert_node(root, 4);
    root = insert_node(root, 8);
    root = insert_node(root, 12);
    root = insert_node(root, 16);
    //中序打印排序树
    in_ord_show(root);
    //排序树转换为双向链表
    in_ord(root);
    //遍历双向链表
    show_list(head);
    return 0;
}