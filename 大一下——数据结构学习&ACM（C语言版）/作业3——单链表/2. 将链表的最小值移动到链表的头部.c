#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

// Definition of a node structure for a singly linked list
typedef struct L_node 
{
    ElemType data;           // Data field
    struct L_node *next;     // Pointer field
} LNode, *LinkedList;

//===========================================
// Initialize a singly linked list L with a head node
//===========================================
Status InitList_L(LinkedList *L)
{
    *L = (LNode*)malloc(sizeof(LNode));
    if (!(*L))     return ERROR;
    (*L)->next = NULL;
    return OK;
}

//===========================================
// Create a singly linked list L with a head node, and with n elements
//===========================================
Status CreateList_L(LinkedList *L, ElemType a[], int n)
{
    if (n <= 0)    return ERROR;
    LNode *r = *L;  // r points to the head node
    int j = 0;
    for (; j < n; j++)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));  // Create a new node
        if (!p)   return ERROR; 
        p->data = a[j];  // Assign data to the new node
        p->next = NULL;  // Set next pointer to NULL

        r->next = p;     // Link the new node to the list
        r = p;           // Move r to the newly added node
    }
    return OK;
}

//===========================================
// Find the minimum value in an array
//===========================================
int find_Min(int arr[], int n)
{
    int min = arr[0], i = 1;
    for (; i < n; i++)
    {
        if (arr[i] < min)     min = arr[i];
    }
    return min;
}

//===========================================
// Move the node containing the minimum value to the head of the linked list
//===========================================
void MoveMinNode_L(LinkedList L, ElemType minval)
{
    // �������Ϊ�ջ���������Ч���������
    if (!L || !L->next)   return;
        
    // ���ڸ�����Сֵ�ڵ�ǰ��Ľڵ�
    LNode *prev = NULL;

    // ���������ָ��
    LNode *cur = L->next;

    // Ѱ�Ұ�����Сֵ�Ľڵ�
    while (cur && cur->data != minval)
    {
        prev = cur;
        cur = cur->next;
    }

    // ����Ҳ�����Сֵ������Сֵ�Ѿ�������ͷ���������ƶ�
    if (!cur || cur == L->next)    return;

    // ��������Сֵ�Ľڵ�ӵ�ǰλ�÷������
    prev->next = cur->next;

    // ������Ľڵ���뵽����ͷ��
    cur->next = L->next;
    L->next = cur;
}

//void MoveMinNode_L(LinkedList L, ElemType minval)
//
//{
//	if(!L->next) return;
//	LNode* r = L;
//	while(r && r->next->data != minval)	r = r->next;//�ҵ�minval��ǰһ����� 
	//�����ڽ���һ��ɾ������ 
//	LNode* p = r->next;
//	r->next = p->next;
// 	free(p);
	//���ƽ���һ��������� 
// 	LNode *s = L;
//	LNode*q;
//	q = (LNode*)malloc(sizeof(LNode));
//	q->data = minval;
//	q->next = s->next;
//	s->next = q;
//}


//===========================================
// Print the elements in a linked list
//===========================================
void LinkedListPrint(LinkedList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int i; 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = find_Min(arr, n);
    //printf("Minimum value: %d\n", min);
    printf("%d\n",min);

    LinkedList L;
    if (InitList_L(&L) == ERROR)
    {
        printf("Error: Failed to initialize the list.\n");
        return 1;
    }

    if (CreateList_L(&L, arr, n) == ERROR)
    {
        printf("Error: Failed to create the list.\n");
        return 1;
    }

    MoveMinNode_L(L, min);
    //printf("List after moving the minimum value to the head: ");
    LinkedListPrint(L);

    return 0;
}

