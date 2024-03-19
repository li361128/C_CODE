#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
#define INIT_SIZE 100
#define LISTINCREMENT 10  
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

// ����һ���յ�˳���
Status InitList_Sq(SqList *L) {
    L->elem = (int *)malloc(INIT_SIZE * sizeof(int));
    if (!L->elem) return OVERFLOW;
    L->length = 0;
    L->listsize = INIT_SIZE;
    return OK;
}

// ����һ������ n ��Ԫ�ص������б�
Status CreateList_Sq(SqList *L, int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        L->elem[i] = a[i];
    }
    L->length = n;
    return OK;
}

// ��˳��� L ���ض�λ�ò���Ԫ��
Status InsertList_Sq(SqList *L, int i, ElemType e) {    
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length >= L->listsize) return OVERFLOW; // ����Ƿ���Ҫ��չ˳���Ŀռ�
    int j;
    for (j = L->length - 1; j >= i - 1; j--) {
        L->elem[j + 1] = L->elem[j]; // ��Ԫ�غ���
    }
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}

// ��ӡ����Ԫ��
void PrintList_Sq(SqList L) {
    int i;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]); 
    }
}

int main() {
    int n, e, k;
    scanf("%d", &n);
    int i, arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    SqList sq;
    InitList_Sq(&sq);
    CreateList_Sq(&sq, arr, n);
    scanf("%d%d", &e, &k);
    InsertList_Sq(&sq, k, e);
    PrintList_Sq(sq);
    return 0;
}

