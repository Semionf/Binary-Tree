#include <stdio.h>
#include <stdlib.h>


typedef struct Leaf {
	int val;
	struct Leaf* Parent;
	struct Leaf* Right;
	struct Leaf* Left;
}TLeaf;
void AddLeaf(TLeaf*, int);
void PrintTreeInOrder(TLeaf*);
void PrintTreeDecending(TLeaf*);
static TLeaf* Root = NULL;
void freeTree();

int main()
{
	AddLeaf(NULL, 3);
	AddLeaf(NULL, 5);
	AddLeaf(NULL, 2);
	AddLeaf(NULL, 10);
	AddLeaf(NULL, 1);
	AddLeaf(NULL, 17);
	AddLeaf(NULL, 16);
	AddLeaf(NULL, 105);
	AddLeaf(NULL, 100);
	printf("In - Order Tree:\n");
	PrintTreeInOrder(Root);
	printf("Decending Tree: \n");
	PrintTreeDecending(Root);
	freeTree(Root);
}

void AddLeaf(TLeaf* curr, int val)
{
	TLeaf Leaf;
	Leaf.val = val;
	if (Root == NULL)
	{
		TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
		newLeaf->val = val;
		newLeaf->Right = NULL;
		newLeaf->Left = NULL;
		Root = newLeaf;
	}
	else {
		if (curr == NULL)
		{
			curr = Root;
		}
		if (Leaf.val > curr->val)
		{
			if (curr->Right == NULL)
			{
				TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
				newLeaf->val = val;
				newLeaf->Right = NULL;
				newLeaf->Left = NULL;
				curr->Right = newLeaf;
				newLeaf->Parent = curr;
			}
			else
			{
				AddLeaf(curr->Right, val);
			}
		}
		else
		{
			if (curr->Left == NULL)
			{
				TLeaf* newLeaf = (TLeaf*)malloc(sizeof(TLeaf));
				newLeaf->val = val;
				newLeaf->Right = NULL;
				newLeaf->Left = NULL;
				curr->Left = newLeaf;
				newLeaf->Parent = curr;
			}
			else
			{
				AddLeaf(curr->Left, val);
			}
		}
	}
}

void PrintTreeDecending(TLeaf* curr)
{
	if (curr == NULL)
	{
		return;
	}
	if (curr->Right)
	{
		PrintTreeDecending(curr->Right);
	}
	printf("%d\n", curr->val);
	if (curr->Left)
	{
		PrintTreeDecending(curr->Left);
	}
}


void PrintTreeInOrder(TLeaf* curr)
{
	if (curr == NULL)
	{
		return;
	}
	if (curr->Left)
	{
		PrintTreeInOrder(curr->Left);
	}
	printf("%d\n", curr->val);
	if (curr->Right)
	{
		PrintTreeInOrder(curr->Right);
	}
}

void freeTree(TLeaf* curr)
{
	if (curr == NULL)
	{
		return;
	}
	if (curr->Left)
	{
		PrintTreeInOrder(curr->Left);
	}
	if (curr->Right)
	{
		PrintTreeInOrder(curr->Right);
	}
	free(curr);
}