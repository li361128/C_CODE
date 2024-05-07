#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW -1
#define ERROR 0
#define OK 1

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
    {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    if (!q)
    {
        exit(OVERFLOW);
    }
    q->data = e;
    q->next = NULL;
    Q->rear->next = q;
    Q->rear = q;
    return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
    {
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

QElemType GetHead(LinkQueue Q)
{
    if (Q.front != Q.rear)
    {
        return Q.front->next->data;
    }
    return -1; // ����Ϊ�գ�����һ������ֵ
}

void DestroyQueue(LinkQueue *Q)
{
    while (Q->front != NULL)
    {
        QueuePtr p = Q->front;
        Q->front = Q->front->next;
        free(p);
    }
    Q->rear = NULL;
}

int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);

    printf("����ͷ��Ԫ�أ�%d\n", GetHead(Q));

    QElemType head;
    if (DeQueue(&Q, &head))
    {
        printf("����Ԫ�أ�%d\n", head);
    }

    printf("����ͷ��Ԫ�أ�%d\n", GetHead(Q));

    DestroyQueue(&Q);

    return 0;
}






//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXQSIZE 100
//#define OVERFLOW -1
//#define ERROR 0
//#define OK 1
//
//typedef int QElemType;
//typedef int Status;
//
//// ѭ������
//typedef struct {
//    QElemType *base;
//    int front;
//    int rear;
//} SqQueue;
//
//Status InitQueue(SqQueue *Q) 
//{
//    Q->base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
//    if (!Q->base) 
//    {
//        exit(OVERFLOW);
//    }
//    Q->front = Q->rear = 0;
//    return OK;
//}
//
//int QueueLength(SqQueue Q) 
//{
//    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
//}
//
//Status EnQueue(SqQueue *Q, QElemType e) 
//{
//    if ((Q->rear + 1) % MAXQSIZE == Q->front) 
//    {
//        return ERROR; // ��������
//    }
//    Q->base[Q->rear] = e;
//    Q->rear = (Q->rear + 1) % MAXQSIZE;
//    return OK;
//}
//
//Status DeQueue(SqQueue *Q, QElemType *e) 
//{
//    if (Q->front == Q->rear) 
//    {
//        return ERROR; // ����Ϊ��
//    }
//    *e = Q->base[Q->front]; // ����ֵ
//    Q->front = (Q->front + 1) % MAXQSIZE;
//    return OK;
//}
//
//QElemType GetHead(SqQueue Q) 
//{
//    if (Q.front != Q.rear) 
//    { // ���в�Ϊ��
//        return Q.base[Q.front]; // ����ֵ
//    }
//    // ����ն���
//    return -1; // �������ʵ�ֵ
//}
//
//void DestroyQueue(SqQueue *Q) 
//{
//    free(Q->base);
//    Q->base = NULL;
//    Q->front = Q->rear = 0;
//}
//
//int main() 
//{
//    SqQueue Q;
//    InitQueue(&Q);
//    EnQueue(&Q, 1);
//    EnQueue(&Q, 2);
//    EnQueue(&Q, 3);
//
//    printf("���г���: %d\n", QueueLength(Q));
//
//    QElemType head;
//    if (DeQueue(&Q, &head)) 
//    {
//        printf("����Ԫ��: %d\n", head);
//    }
//
//    printf("���Ӻ���г���: %d\n", QueueLength(Q));
//
//    printf("����ͷ��Ԫ��: %d\n", GetHead(Q));
//
//    DestroyQueue(&Q);
//
//    return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//    char *base;
//    char *top;
//    int stackSize;
//} sqStack;
//
//void InitStack(sqStack *S)
//{
//    S->base = (char *) malloc(100*sizeof(char));
//    S->top = S->base;
//    S->stackSize = 100;
//}
//
//void Push(sqStack *s,char e)
//{
//    *(s->top ++)= e;
//}
//
//void Pop(sqStack *s,char *e)
//{
//    if(s->top == s->base)   return ;
//    *e = *(--s->top);
//}
//
//int StackLen(sqStack s)
//{
//    return s.top - s.base;
//}
//
//int main()
//{
//    sqStack s;
//    char c,e;
//
//    InitStack(&s);
//    printf("input :\n");
//    scanf("%c",&c);
//
//    while(c != '#')
//    {
//        while(c>= '0' && c <= '9')
//        {
//            printf("%c",c);
//            scanf("%c",&c);
//            if(c < '0' || c > '9')  printf(" ");
//        }
//        if(c == ')')
//        {
//            Pop(&s,&e);
//            while(e != '(')
//            {
//                printf("%c",e);
//                Pop(&s,&e);
//            }
//        }
//        else if(c == '+' || c == '-')
//        {
//            if(StackLen(s) == 0)    Push(&s,c);
//            else
//            {
//                do
//                {
//                    Pop(&s,&e);
//                    if(e == '(' )   
//					{
//                    	Push(&s,e);
//					}
//                    else            
//                    {
//                    	printf("%c",e);
//					}
//                }while(StackLen(s) && e != '(');
//               	Push(&s, c);
//            }
//        }
//        else if('*' == c || '/' == c || '(' == c)  
//        {
//        	 Push(&s,c);
//		}
//        else if('#' == c)   
//        {
//        	break;
//		}
//        else
//        {
//            printf("ERROR\n");
//            return -1;
//        }
//        scanf("%c",&c);
//    }
//    while(StackLen(s) != 0)
//    {
//        Pop(&s,&e);
//        printf("%c ",e);
//    }
//    return 0;
//}







//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//typedef struct
//{
//	double *base;
//	double *top;
//	int stackSize;
//}sqStack;
//
//void InitStack(sqStack *s)
//{
//	s->base = (double *)malloc(100*sizeof(double));
//	s->top = s->base;
//	s->stackSize = 100;
//}
//
//void Push(sqStack *s, double e)
//{
//	*(s->top) = e;
//	s->top++;
//}
//
//void Pop(sqStack *s, double *e)
//{
//	s->top = s->top-1;
//	*e = *(s->top);
//}
//
//int main(void)
//{
//	char c;
//	double d, e, f, g;
//	char str[100];
//	int i = 0;
//	
//	sqStack s;
//	InitStack(&s);
//	
//	printf("input: \n");
//	scanf("%c", &c);
//	while(c != '#' )
//	{
//		while(isdigit(c) || c=='.')
//		{
//			str[i++] = c;
//			str[i] = '\0';
//			scanf("%c", &c);
//			if(c == ' ')
//			{
//				d = atof(str);
//				Push(&s, d);
//				i = 0;
//				break;
//			}
//		}
//		switch(c)
//		{
//			case '+':
//				Pop(&s, &e);
//				Pop(&s, &f);
//				g = f+e;
//				Push(&s, g);
//				break;
//			case '-':
//				Pop(&s, &e);
//				Pop(&s, &f);
//				g = f-e;
//				Push(&s, g);
//				break;
//			case '*':
//				Pop(&s, &e);
//				Pop(&s, &f);
//				g = f*e;
//				Push(&s, g);
//				break;
//			case '/':
//				Pop(&s, &e);
//				Pop(&s, &f);
//				if(e != 0)
//				{
//					g = f/e;
//					Push(&s, g);
//					break;
//				}
//				else
//				{
//					printf("error!\n");
//					break;
//				}
//	 
//		}
//		scanf("%c", &c);
//	}
//	
//	Pop(&s, &d);
//	printf("Result is: %f\n", d);
//	return 0;
//}














//#include <stdio.h>
//#include <stdlib.h>
//
//#define ERROR 0
//#define OK 1
//
//typedef int ElemType;
//typedef int Status;
//
//typedef struct DuLNode
//{
//    ElemType data;          // ������
//    struct DuLNode* prior;  // ָ��ֱ��ǰ��
//    struct DuLNode* next;   // ָ��ֱ�Ӻ��
//} DuLNode, * DuLinkList;
//
//Status GetElem_DuL(DuLinkList L, int i, ElemType* e)
//{
//    int j;
//    DuLinkList p;
//    p = L->next; // pָ���һ�����
//    j = 1;
//    while (p && j < i)
//    {
//        p = p->next;
//        ++j;
//    }
//    if (!p || j > i)
//        return ERROR; // ��i��Ԫ�ز�����
//    *e = p->data;     // ȡ��i��Ԫ�ص�����
//    return OK;
//}
//
//Status ListInsert_DuL(DuLinkList* L, int i, ElemType e)
//{
//    DuLinkList p, s;
//    if (i < 1) // ���λ�ò��Ϸ�
//        return ERROR;
//    
//    s = (DuLinkList)malloc(sizeof(DuLNode));
//    if (!s)
//        exit(EXIT_FAILURE); // �ڴ����ʧ�ܣ��˳�����
//    s->data = e;
//    
//    if (i == 1 || !(*L)->next) { // �ڵ�һ��λ�ò����������Ϊ��ʱ
//        s->next = (*L)->next;
//        if ((*L)->next) // �������Ϊ��
//            (*L)->next->prior = s;
//        s->prior = *L;
//        (*L)->next = s;
//        return OK;
//    }
//    
//    p = (*L)->next;
//    while (--i && p) p = p->next; // �ҵ��� i-1 ���ڵ�
//    if (!p) // ���λ�ó���������
//        return ERROR;
//    
//    s->next = p->next;
//    s->next->prior = s;
//    s->prior = p;
//    p->next = s;
//    return OK;
//}
//
//
//Status ListDelete_DuL(DuLinkList* L, int i)
//{
//    DuLinkList p, q;
//    int j = 1;
//    p = *L; // �� p ָ��ͷ�ڵ�
//    while (p->next && j < i)
//    {
//        p = p->next;
//        ++j;
//    }
//    if (!p->next || j > i)
//        return ERROR; // ��i��Ԫ�ز�����
//    q = p->next;
//    p->next = q->next;
//    if (q->next) // ��� q ����һ���ڵ㲻Ϊ��
//        q->next->prior = p;
//    free(q);
//    return OK;
//}
//
//
//
//int main()
//{
//    DuLinkList L;
//    L = (DuLinkList)malloc(sizeof(DuLNode));
//    if (!L)
//        exit(EXIT_FAILURE); // �ڴ����ʧ�ܣ��˳�����
//    L->next = NULL;
//    ElemType e;
//    if (ListInsert_DuL(&L, 1, 10) == OK)
//        printf("Insert successful!\n");
//    if (GetElem_DuL(L, 1, &e) == OK)
//        printf("The first element is: %d\n", e);
//    if (ListDelete_DuL(&L, 1) == OK)
//        printf("Delete successful!\n");
//    system("pause");
//    return 0;
//}










//
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node,*pNode;
//
//pNode Creat_linkList()
//{
//	Node* L;
//	L = (Node*)malloc(sizeof(Node));
//	L->next = NULL;
//	return L;
//}
//
//void Gen_linkList(pNode L)
//{
//	Node* r;
//	r = L;
//	int i = 0; 
//	for (i = 0; i < 6; i++)
//	{
//		Node* p;
//		p = (Node*)malloc(sizeof(Node));
//		p->data = i;
//		p->next = NULL;
//		r->next = p;
//		r = p;
//	}
//}
//
//void Print_linklist(pNode L)
//{
//	Node* p;
//	for (p = L->next; p != NULL; p = p->next)
//	{
//		printf("%d ", p->data);
//	}
//}
//
//int main()
//{
//	Node *L;
//	L = Creat_linkList();
//	Gen_linkList(L);
//	Print_linklist(L);
//	return 0;
//}	



