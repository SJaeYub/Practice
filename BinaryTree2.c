#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode* MakeBTreeNode(void) {
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode* bt) {
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data) {
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    if(main->left != NULL) {
        free(main->left);                                   //이미 존재한다면 없애버리기!
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    if(main->right != NULL) {
        free(main->right);                                  //서브트리 노드가 한개만 존재한다면 상관없지만 그 밑으로 또다른 서브트리들이 존재한다면 일일이 free 해줘야한다!
    }

    main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
    if(bt == NULL) {
        return;
    }

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
    if(bt == NULL) {
        return;
    }

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
    if(bt == NULL) {
        return;
    }

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}