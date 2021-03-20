#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);                 //BST의 생성 및 초기화

BSTData BSTGetNodeData(BTreeNode* bst);                 //노드에 저장된 데이터 반환

void BSTInsert(BTreeNode** pRoot, BSTData data);        //BST를 대상으로 데이터 저장(노드의 생성과정 포함)

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);   //BST를 대상으로 데이터 탐색

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void BSTShowAll(BTreeNode* bst);

#endif