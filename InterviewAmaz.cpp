#include <iostream>

struct Node
{
    int val;
    Node* next;
    Node(int value) { val = value, next = NULL;}
};

Node* CreateList(int numbers[], int size)
{
    Node* pList = NULL;
    Node* pNode = NULL;
    for (int i = 0; i < size; i++)
    {
        if (i == 0) // assign a head pointer
            pList = pNode = new Node(numbers[i]);
        else
        {
            pNode->next = new Node(numbers[i]);
			pNode = pNode->next;
        }
    }

    return pList;
}

void DeleteList(Node* pList)
{
	Node* p = pList;
    printf("Deleting list:  ");
	while (p != NULL)
	{
        printf("%d. ", p->val);
		p = p->next;
	}
	printf("\n");

}
void PrintList(const char* pszMsg, Node* pList)
{
    printf(pszMsg);
    Node *p = pList;
    while (p != NULL)
    {
        printf(" % d ->", p->val);
        if (p->next == NULL)
            printf(" END");
        p = p->next;
    }
    printf("\n");
}



Node* ReverseList(Node* pList)
{
    Node* pCur = pList;
    Node* pNext = NULL;
    Node* pPrev = NULL;
    while (pCur != NULL)
    {
        pNext = pCur->next;
        pCur->next = pPrev;

		pPrev = pCur;
        pCur = pNext;
    }
    return pPrev;

}

void MixList(Node* pStart)
{
    // Count all nodes
    Node* p = pStart;
    int size = 0;
    while (p!=NULL)
    {
        p = p->next;
        size++;
    }

    // Find pointer to second half
	int iSteps = size/2 + size%2;
    int i = iSteps;
    p = pStart;
    while (i-->0)
    {
        p = p->next;
    }

    // Reverse second half
    Node* p2ndHalf = ReverseList(p);

	// Mix the list
    Node* p1 = pStart;
    Node* p2 = p2ndHalf;
    while (p1 != NULL && p2 != NULL)
    {
        Node* p1Next = p1->next;
        Node* p2Next = p2->next;

        p2->next = p1->next;
        p1->next = p2;

        p1 = p1Next;
        p2 = p2Next;
    }

    p1->next = NULL;


}


int main()
{
    int nums[] = { 1,2,3,4,5};
    // also works int nums[] = { 1,2,3,4,5, 6 };
    Node* pList = CreateList(nums, sizeof nums/ sizeof nums[0]);
	PrintList("Original list:", pList);
    MixList(pList);
	PrintList("Mixed list:   ", pList);

    DeleteList(pList);
}


// =================
// Output with 5 nodes
///
// Original list : 1 ->  2 ->  3 ->  4 ->  5->END
// Mixed list : 1 ->  5 ->  2 ->  4 ->  3->END
// Deleting list : 1. 5. 2. 4. 3.

// Output with 6 nodes
//
// Original list : 1 ->  2 ->  3 ->  4 ->  5 ->  6->END
// Mixed list : 1 ->  6 ->  2 ->  5 ->  3 ->  4->END
// Deleting list : 1. 6. 2. 5. 3. 4.

// Output with 3 nodes
//
// Original list : 1 ->  2 ->  3->END
// Mixed list : 1 ->  3 ->  2->END
// Deleting list : 1. 3. 2.



