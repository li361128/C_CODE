#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;

// �����˿��ƽṹ

typedef struct {
    char suit[10];   //��ɫ�� "Hearts", "Diamonds", "Clubs", "Spades"
    char face[10];   //��ֵ�� "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" 
} Card, QElemType, SElemType;


typedef struct Lnode{
	SElemType data;
	struct Lnode *next;
	
}LNode,*LinkList;

typedef struct{
	LinkList Head;
	int length;
	
}LinkStack;

Status InitLinkStack(LinkStack *S)
{
	S->Head = (LinkList)malloc(sizeof(LNode));
	if(!S->Head)
		return ERROR;
	
	S->Head->next = NULL;
	S->length = 0;
	
	return OK;
} 


Status StackEmpty(LinkStack S)
{
	return (S.Head->next == NULL);
	
}

Status Push(LinkStack *S, SElemType e)
{
	LinkList p;
	
	p = (LinkList)malloc(sizeof(LNode));
	if(!p)
		return ERROR;
	
	p->data = e;
	p->next = S->Head->next;
	S->Head->next = p;
	S->length++;
	
	return OK;
	
}

Status GetTop(LinkStack S, SElemType *e)
{
	if(!S.Head->next )
		return ERROR;
	
	*e = S.Head->next->data;
	
	return OK;
	
}

Status Pop(LinkStack *S, SElemType *e)
{
	
	LinkList p;
	
	p = S->Head->next;
	
	if(!p)
		return ERROR;

	*e = p->data;
	
	S->Head->next = p->next;
	free(p);
	
	S->length--;
	
	return OK;
	
}

int StackLength(LinkStack S)
{
	return S.length;
	
}


#define MAXQSIZE  10   //�����г���
typedef struct {
   QElemType *base;   //��ʼ���Ķ�̬����洢�ռ�
   int  front;                    //ͷָ��   
   int  rear;                     //βָ��
}SqQueue;  


char suits[4][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char faces[13][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

Status InitQueue (SqQueue *Q){
   //����һ���ն���Q
   Q->base=(QElemType *) malloc(MAXQSIZE *sizeof(QElemType)); 
   if(!Q->base) return ERROR;
   Q->front=Q->rear=0;
   return OK;
}//InitQueue

Status QueueEmpty (SqQueue Q){
    return (Q.front==Q.rear);                             
}// QueueEmpty

Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear+1)%MAXQSIZE==Q->front)  return ERROR;//������
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
     return OK;
}//EnQueue

Status DeQueue (SqQueue *Q,QElemType *e){
   if(Q->front==Q->rear) return ERROR;
   *e=Q->base[Q->front];
   Q->front=(Q->front+1)%MAXQSIZE;
   return OK;
}//DeQueue

Status QueueTraverse(SqQueue Q,void(*vi)(QElemType))
{ /* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi().һ��viʧ��,�����ʧ�� */
   int i;
   i=Q.front;
   while(i!=Q.rear)
   {
     vi(*(Q.base+i));
     i=(i+1)%MAXQSIZE;
   }
   printf("\n");
   return OK;
}

/* prepare card */
void prepare_card(LinkStack *S, char suit, int face)
{
  
//***��ȫ����****  
	if(face > 13 || face < 1 || suit != 'H' || suit != 'D' || suit != 'C' || suit != 'S' )
	{
		printf("Illegal suit input");
		exit(-1);
		 }	 
	
  
  
}
/* expand cards */
void expand_card(SqQueue *Q)
{

//***��ȫ����****


}
/* shuffle cards */
void shuffle_card(SqQueue *Q, int num){

    int i;
    QElemType e;
    for(i=0; i<num; i++){
        DeQueue(Q, &e);
        EnQueue(Q, e);
    }

}

/* insert first k cards into bottom after pos  */
void insert_card(SqQueue *Q, int k, int pos)
{

//***��ȫ����****


}


// print card
void printCard(Card card) {
    if(card.face[1]=='0')
        printf("[%c-%c%c]", card.suit[0], card.face[0], card.face[1]);
    else
        printf("[%c-%c]", card.suit[0], card.face[0]);
}

int main() {
    int i;
    char suit;  /* �洢�˿˻�ɫ������ĸ  */
    int face;  /* �洢�˿��Ƶķ�ֵ, ��ֵΪ1~13 */
    int pos; /* �洢��3�����������ƺ��� */
    int name; /* �������� */
    int gender;  /* �洢�ӵ�������������1 ��Ů�� 2 */
    Card card, secret;

    SqQueue Q; /* �洢�˿��ƶ� */
    LinkStack S;
    InitQueue(&Q);
    InitLinkStack(&S);
/* 1. �ó�4���˿��Ʋ��������˳�� */
/* ������������ֺͻ�ɫ��ȡ4���ƣ���ɵ�1�� */
    // printf("Please input 4 card suit and face (example: H-3):\n");
    for(i=0; i<4; i++) {
        /* ˳������4���˿��ƵĻ�ɫ�ͷ�ֵ�ͣ���ɫ�ں�;��ֵ��ǰ */
        scanf("%c-%d", &suit, &face);
        getchar();
        prepare_card(&S, suit, face);
    }

    for(i=0; i<4; i++){
        Pop(&S, &card);
        EnQueue(&Q, card);
    }
    printf("After 1-step process:\n");
    QueueTraverse(Q, printCard);
/* 2. ˺���˿����ص�����һ�� */    
    expand_card(&Q);
    printf("After 2-step process:\n");
    QueueTraverse(Q, printCard);

/* 3.������������ѭ���˿�n�Σ�*/
    // printf("Please input the length of your name: ");
    scanf("%d", &name);
    shuffle_card(&Q, name);
    printf("After 3-step process:\n");
    QueueTraverse(Q, printCard);
/* 4. ���������3���˿����������������˿����м䣻 */
    // printf("Please input the 1-st insert position(3<k<n): ");
    scanf("%d", &pos);
    insert_card(&Q, 3, pos);
    printf("After 4-step process:\n");
    QueueTraverse(Q, printCard);
/* 5.����������˿�����Ϊ�յױ��������� */ 
    DeQueue(&Q, &secret);
    printf("After 5-step process:\n");
    QueueTraverse(Q, printCard);
/* 6.���������3���˿����������������˿����м䣻 */    
    // printf("Please input the 2nd insert position(3<k<n): ");
    scanf("%d", &pos);
    insert_card(&Q, 3, pos);
    printf("After 6-step process:\n");
    QueueTraverse(Q, printCard);
/* 7. ������������Ů��������������˿����ӳ�ȥ1�Ż���2�ţ� */
    // printf("Please input your gender(male:1, fename:2): ");
    scanf("%d", &gender);
    DeQueue(&Q, &card);
    if(gender==2)
        DeQueue(&Q, &card);
    printf("After 7-step process:\n");
    QueueTraverse(Q, printCard);
/* 8. ����֤�漣��ʱ�̡������˿���ѭ��7�� */
    shuffle_card(&Q, 7);
    printf("After 8-step process:\n");
    QueueTraverse(Q, printCard);
/* 9. �����������������ն���ȥ����ѭ��һ�ζ���һ�� */
    while((Q.rear-Q.front+MAXQSIZE)%MAXQSIZE != 1){
        shuffle_card(&Q, 1);
        DeQueue(&Q, &card);
        // QueueTraverse(Q, printCard);
    }

    DeQueue(&Q, &card);
    printf("Final 9-step process:\n");
    printCard(card);
    printf("\n");
    printf("Secrete card:\n");
    printCard(secret);
    printf("\n");
    return 0;
}

