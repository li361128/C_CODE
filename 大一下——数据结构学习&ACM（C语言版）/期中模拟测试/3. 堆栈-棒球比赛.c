#include <stdio.h>  

#include <stdlib.h>  

#include <malloc.h>

 

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

 

typedef int SElemType;  

typedef int Status;

 

typedef struct L_node{

     SElemType     data;  //data field

     struct L_node  *next;   //pointer field

}LNode, *LinkList;

 

typedef struct{

   LinkList  Head;  //head pointer

   int  length;  //length

}LinkStack;

 

//========================================== 

// initialization of linked list based stack

//=========================================== 

Status InitStack(LinkStack &S){



}

 

//========================================

//Test empty stack

//========================================

Status StackEmpty (LinkStack S){



}

 

//===============================================

// Get the length of a stack

//==============================================

int StackLength (LinkStack S){



                            

}

 

//=====================================

// Get top item of a stack

//====================================

Status GetTop(LinkStack S, SElemType &e){



}

 

//===================================================

// Delete an item from the stack

//====================================================

Status Pop(LinkStack &S, SElemType &e){



}

 

//======================================

// Insert an item into the stack

//=======================================

Status Push(LinkStack &S, SElemType e){



}

 

//======================================

// Print the elements in a stack

//=======================================

void PrintStack (LinkStack S){

 



}

//=========================

// �����ֵ��sΪ�ַ������飬nSizeΪ����ĳ���

//========================

int CalPoints(char **s,  int nSize)

{





} 



int main()  

{  





 } 
