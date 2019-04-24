#include <iostream> 

using namespace std;

void RightRotation(struct Node *Rotation1);
void LeftRotation(struct Node *Rotation1);
void RightLeftRotation(struct Node *Rotation1);
void LeftRightRotation(struct Node *Rotation1);
struct Node *LowerElement(struct Node *start);
void in_order_tree_walk(struct Node *start);
void UpdateIndex(struct Node *NewNode);


struct Node
{
	int value;
	int EqualityIndex;
	int LValue;
	int RValue;
	struct Node *parent;
	struct Node *lSon;
	struct Node *rSon;
};
struct Node *rootL;



//          Search            // 

struct Node *back;
int roznica, temp;

struct Node *searchNode(struct Node *start, int value)
{
	while (start != NULL)
	{
		if (start->value == value)
		{
			return start;
		}


		else if (value < start->value)
		{
			temp = value - start->value;
			if ((temp < roznica) && (temp>0))
			{
				int roznica1 = 0;
				int roznica2 = 0;
				roznica1 = value - start->value;
				roznica2 = value - back->value;
				if (((roznica2 < 0) && (roznica1>0)) || (roznica1>0) && (roznica2 > 0) && (roznica1 < roznica2))
				{
					back = start;
					roznica = temp;
				}
			}
			start = start->lSon;
		}
		else if (value > start->value)
		{
			temp = value - start->value;
			if ((temp < roznica) && (temp>0))
			{
				int roznica1 = 0;
				int roznica2 = 0;
				roznica1 = value - start->value;
				roznica2 = value - back->value;
				if (((roznica2 < 0) && (roznica1>0)) || (roznica1 > 0) && (roznica2 > 0) && (roznica1 < roznica2))
				{
					back = start;
					roznica = temp;
				}
			}
			start = start->rSon;
		}
	}
	if (start == NULL)
	{
		if (back->value > value)
			return NULL;
		else
			return back;
	}
}

int How_Much_Lower(struct Node *NewNode)
{
	int ile = 0;
	struct Node *SubTree;

	if (NewNode == rootL)
	{
		ile = NewNode->LValue + 1;
		return ile;
	}
	SubTree = NewNode;
	if (NewNode->lSon != NULL)
	{
		ile = ile + NewNode->LValue;
	}
	while (SubTree != rootL)
	{
		while ((SubTree != rootL) && (SubTree->parent->lSon == SubTree))
		{
			SubTree = SubTree->parent;
				
		}

		while ((SubTree != rootL) && (SubTree->parent->rSon == SubTree))
		{
			SubTree = SubTree->parent;
			if (SubTree->lSon != NULL)
				ile = ile + SubTree->LValue;
			ile = ile + 1;
		}
	}
	ile = ile + 1;
	return ile;
}



//          Insert       // 


bool insert(struct Node *NewNode)
{
	struct Node * x = rootL;
	struct Node *NewNodeParent = NULL;
	struct Node *NewNodeParentParent = NULL;


	if (rootL == NULL)
	{
		rootL = NewNode;
		return true;
	}
	else
	{
		while (x != NULL)
		{
			NewNodeParent = x;
			if (NewNode->value < x->value)
			{
				x->LValue = x->LValue + 1;
				x = x->lSon;
			}
			else
			{
				x->RValue = x->RValue +1;
				x = x->rSon;
			}
		}
		NewNode->parent = NewNodeParent;


		if (NewNode->value < NewNodeParent->value)
			NewNodeParent->lSon = NewNode;
		else
			NewNodeParent->rSon = NewNode;
	}


	if ((NewNodeParent->EqualityIndex == -1) || (NewNodeParent->EqualityIndex == 1))
	{
		NewNodeParent->EqualityIndex = 0;
		return true;
	}
	if (NewNodeParent->lSon == NewNode)
	{
		NewNodeParent->EqualityIndex = 1;
	}
	else NewNodeParent->EqualityIndex = -1;


	NewNodeParentParent = NewNodeParent->parent;
	bool checkerrr = true;
	while ((NewNodeParentParent != NULL) && (checkerrr == true))
	{
		if (NewNodeParentParent->EqualityIndex != 0)
		{
			checkerrr = false;
		}
		if ((NewNodeParentParent->lSon == NewNodeParent) && (checkerrr == true))
		{
			NewNodeParentParent->EqualityIndex = 1;
		}
		else if (checkerrr == true)
		{
			NewNodeParentParent->EqualityIndex = -1;
		}
		if (checkerrr == true)
		{
			NewNodeParent = NewNodeParentParent;
			NewNodeParentParent = NewNodeParentParent->parent;
		}
	}
	if (NewNodeParentParent == NULL)
	{
		return true;
	}
	if (NewNodeParentParent->EqualityIndex == 1)
	{
		if (NewNodeParentParent->rSon == NewNodeParent)
		{
			NewNodeParentParent->EqualityIndex = 0;
			return true;
		}
		if (NewNodeParent->EqualityIndex == -1)
		{
			LeftRightRotation(NewNodeParentParent);
		}
		else LeftRotation(NewNodeParentParent);
		return true;
	}


	else
	{
		if (NewNodeParentParent->lSon == NewNodeParent)
		{
			NewNodeParentParent->EqualityIndex = 0;
			return true;
		}
		if (NewNodeParent->EqualityIndex == 1)
		{
			RightLeftRotation(NewNodeParentParent);
		}
		else RightRotation(NewNodeParentParent);
		return true;
	}
}


struct Node *max(struct Node *p)
{
	if (p != NULL)
		while (p->rSon != NULL)
			p = p->rSon;


	return p;
}


struct Node *min(struct Node *p)
{
	if (p != NULL)
		while (p->lSon)
			p = p->lSon;
	return p;
}




// Predecessor // 


struct Node *LowerElement(struct Node *start) {
	struct Node * start_tmp;


	if (start != NULL)
	{
		if (start->lSon)
		{
			return max(start->lSon);
		}
		else
		{
			start_tmp = start->parent;
			while ((start_tmp) && (start == start_tmp->lSon))
			{
				start = start_tmp;
				start_tmp = start_tmp->parent;
			}
			return start_tmp;
		}
	}
	return start;
}


void Increase(struct Node *node, struct Node *NoNode)
{
	if (node != NULL)
	{
		if (node->lSon != NoNode)
		{
			Increase(node->lSon, NoNode);
		}
		node->LValue = node->LValue + 1;
		Increase(node->rSon, NoNode);
	}
}


void IncreaseALL(struct Node *node)
{
		IncreaseALL(node->lSon);
		node->LValue = node->LValue + 1;
		IncreaseALL(node->rSon);
}



void UpdateIndex(struct Node *NewNode)
{
	struct Node *Subbtree;
	struct Node *SubTree;
	struct Node *LowerElementt= LowerElement(NewNode);
	struct Node *NewSubTree;

	if (LowerElementt != NULL)
	{
		NewNode->LValue = LowerElementt->LValue + 1;
	}

	if (NewNode->value > rootL->value)
	{
		SubTree = NewNode;
		Subbtree = NewNode;

		while (SubTree!=rootL)
		{

				while ((SubTree->parent != NULL) && (SubTree->parent->lSon == SubTree))
				{
					SubTree = SubTree->parent;
				}
				if (SubTree == NewNode)
				{
					if(SubTree->rSon!=NULL)
					Increase(SubTree->rSon, SubTree);
				}
				else
				{
					Increase(SubTree, Subbtree);
				}
				Subbtree = SubTree;
				while ((SubTree->parent != NULL) && (SubTree->parent->rSon == SubTree))
				{
					SubTree = SubTree->parent;
				}
				Subbtree = SubTree;
		
	}
	}


	else if (NewNode->value<rootL->value)
	{
		LowerElementt = LowerElement(NewNode);
		if (LowerElementt != NULL)
		{
			NewNode->LValue = LowerElementt->LValue + 1;
		}
		SubTree = NewNode;
		Subbtree = NewNode;

		while (SubTree->parent!= NULL)
		{	
			while((SubTree->parent != NULL) && (SubTree->parent->lSon == SubTree))
			{
				SubTree = SubTree->parent;
			}
			if (SubTree == NewNode)
			{
				if (SubTree->rSon != NULL)
					IncreaseALL(SubTree->rSon);
			}
			else
			{
				Increase(SubTree, Subbtree);
			}
			Subbtree = SubTree;
			while ((SubTree->parent != NULL) && (SubTree->parent->rSon == SubTree))
			{
				SubTree = SubTree->parent;
			}
			Subbtree = SubTree;

		}


		}
	}


//          LRot            // 


void LeftRotation(struct Node *Rotation1)
{
	struct Node *Rotation2 = Rotation1->lSon;
	struct Node *ParentR1 = Rotation1->parent;

	Rotation1->lSon = Rotation2->rSon;
	Rotation1->LValue = Rotation2->RValue;

	if (Rotation2->rSon != NULL)
	{
		Rotation1->lSon->parent = Rotation1;
	}
	else Rotation1->lSon = NULL;

	Rotation2->rSon = Rotation1;
	Rotation2->RValue = Rotation1->RValue + Rotation1->LValue +1;

	Rotation2->parent = ParentR1;

	Rotation1->parent = Rotation2;

	if (ParentR1 == NULL)
		rootL = Rotation2;
	else
	{
		if (ParentR1->lSon == Rotation1)
		{
			ParentR1->lSon = Rotation2;
		}
		else ParentR1->rSon = Rotation2;
	}


	if (Rotation2->EqualityIndex == 1)
	{
		Rotation2->EqualityIndex = 0;
		Rotation1->EqualityIndex = 0;
	}
	else if (Rotation2->EqualityIndex == 2)
	{
		Rotation2->EqualityIndex = 1;
		Rotation1->EqualityIndex = -1;
	}
}


//              RRot           // 


void RightRotation(struct Node *Rotation1)
{
	struct Node *Rotation2 = Rotation1->rSon;
	struct Node *ParentR1 = Rotation1->parent;

	Rotation1->rSon = Rotation2->lSon;
	Rotation1->RValue = Rotation2->LValue;

	if (Rotation2->lSon != NULL)
	{
		Rotation1->rSon->parent = Rotation1;
	}
	else Rotation1->rSon = NULL;

	Rotation2->lSon = Rotation1;
	Rotation2->LValue = Rotation1->RValue + Rotation1->LValue +1;

	Rotation2->parent = ParentR1;
	Rotation1->parent = Rotation2;


	if (ParentR1 == NULL)
		rootL = Rotation2;
	else
	{
		if (ParentR1->lSon == Rotation1)
		{
			ParentR1->lSon = Rotation2;
		}
		else ParentR1->rSon = Rotation2;
	}


	if (Rotation2->EqualityIndex == -1)
	{
		Rotation1->EqualityIndex = 0;
		Rotation2->EqualityIndex = 0;
	}
	else
	{
		Rotation1->EqualityIndex = -1;
		Rotation2->EqualityIndex = 1;
	}
}


//          RLRot           // 
void RightLeftRotation(struct Node *Rotation1)
{
	struct Node * Rotation2 = Rotation1->rSon;
	struct Node * Rotation3 = Rotation2->lSon;
	struct Node * ParentR1 = Rotation1->parent;


	Rotation2->lSon = Rotation3->rSon;
	Rotation2->LValue = Rotation3->RValue;

	if (Rotation2->lSon != NULL)
	{
		Rotation2->lSon->parent = Rotation2;
	}


	Rotation1->rSon = Rotation3->lSon;
	Rotation1->RValue = Rotation3->LValue;

	if (Rotation1->rSon != NULL)
	{
		Rotation1->rSon->parent = Rotation1;
	}


	Rotation3->rSon = Rotation2;
	Rotation3->RValue = Rotation3->RValue + Rotation2->RValue + 1;

	Rotation3->lSon = Rotation1;
	Rotation3->LValue = Rotation1->LValue + Rotation3->LValue + 1;

	Rotation3->parent = ParentR1;
	Rotation2->parent = Rotation3;
	Rotation1->parent = Rotation3;


	if (ParentR1 == NULL)
	{
		rootL = Rotation3;
	}
	else
	{
		if (ParentR1->lSon == Rotation1)
		{
			ParentR1->lSon = Rotation3;
		}
		else ParentR1->rSon = Rotation3;
	}
	if (Rotation3->EqualityIndex == -1)
	{
		Rotation1->EqualityIndex = 1;
	}
	else
	{
		Rotation1->EqualityIndex = 0;
	}
	if (Rotation3->EqualityIndex == 1)
	{
		Rotation2->EqualityIndex = -1;
	}
	else
	{
		Rotation2->EqualityIndex = 0;
	}
	Rotation3->EqualityIndex = 0;
}


//          LRRot           // 
void LeftRightRotation(struct Node *Rotation1)
{
	Node *Rotation2 = Rotation1->lSon;
	Node *Rotation3 = Rotation2->rSon;
	Node *ParentR1 = Rotation1->parent;


	Rotation2->rSon = Rotation3->lSon;
	Rotation2->RValue = Rotation3->LValue;

	if (Rotation2->rSon!=NULL)
	{
		Rotation2->rSon->parent = Rotation2;
	}

	Rotation1->lSon = Rotation3->rSon;
	Rotation1->LValue = Rotation3->RValue;

	if (Rotation1->lSon!=NULL)
	{
		Rotation1->lSon->parent = Rotation1;
	}


	Rotation3->rSon = Rotation1;
	Rotation3->RValue = Rotation1->RValue + Rotation1->LValue + 1;

	Rotation3->lSon = Rotation2;
	Rotation3->LValue = Rotation2->LValue + Rotation2->RValue + 1;
	
	Rotation2->parent = Rotation3;
	Rotation3->parent = ParentR1;
	Rotation1->parent = Rotation3;


	if (ParentR1)
	{
		if (ParentR1->lSon == Rotation1)
		{
			ParentR1->lSon = Rotation3;
		}
		else ParentR1->rSon = Rotation3;
	}
	else rootL = Rotation3;


	if (Rotation3->EqualityIndex == 1)
	{
		Rotation1->EqualityIndex = -1;
	}
	else Rotation1->EqualityIndex = 0;
	if (Rotation3->EqualityIndex == -1)
	{
		Rotation2->EqualityIndex = 1;
	}
	else Rotation2->EqualityIndex = 0;


	Rotation3->EqualityIndex = 0;
}


int How_Much = 0;
struct Node *ReturnedNode;
struct Node *Poprzednikk;
int NumberOfElementsToSearch;




int main()
{
	int ile, Nvalue, NumberToSearch;
	rootL = NULL;


	cin >> ile;
	for (int i = 0; i<ile; i++)
	{
		int NumberOfElements;
		cin >> NumberOfElements;
		for (int j = 0; j<NumberOfElements; j++)
		{
			cin >> Nvalue;
			struct Node *newNode = new Node;
			newNode->value = Nvalue;
			newNode->EqualityIndex = 0;
			newNode->LValue = 0;
			newNode->RValue = 0;
			newNode->lSon = NULL;
			newNode->rSon = NULL;
			newNode->parent = NULL;
			insert(newNode);
		}
		cin >> NumberOfElementsToSearch;
		for (int j = 0; j<NumberOfElementsToSearch; j++)
		{
			ReturnedNode = NULL;
			Poprzednikk = NULL;
			roznica = 2147483647;
			back = rootL;
			cin >> NumberToSearch;
			if (rootL != NULL)
			{
				ReturnedNode = searchNode(rootL, NumberToSearch);
				if (ReturnedNode != NULL)
				{
					How_Much = How_Much_Lower(ReturnedNode);
					if (ReturnedNode->value == NumberToSearch)
					{
						cout << "T," << How_Much << " ";
					}
					else cout << "N," << How_Much << " ";
				}
				else cout << "N,0 ";
			}
			else cout << "N,0 ";
		}
		cout << endl;
	}
	return 0;
}
