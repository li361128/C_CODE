#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char SElemType;

// ��������ջ�ڵ�ṹ
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

// ��������
Status InitStack(LinkStack *S);
Status StackEmpty(LinkStack S);
Status Push(LinkStack *S, char ch);
Status Pop(LinkStack *S, char *ch);
Status GetTop(LinkStack S, char *e);
Status match(char element_l, char element_r);

// ��ʼ������ջ
Status InitStack(LinkStack *S) {
    (*S) = (LinkStack)malloc(sizeof(StackNode));
    if (!(*S))
        return ERROR;
    (*S)->next = NULL;
    return OK;
}

// �ж�ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S) {
    return S->next == NULL ? TRUE : FALSE;
}

// Ԫ����ջ
Status Push(LinkStack *S, char ch) {
    LinkStack s = (LinkStack)malloc(sizeof(StackNode));
    if (!s)
        return ERROR;
    s->data = ch;
    s->next = (*S)->next;
    (*S)->next = s;
    return OK;
}

// Ԫ�س�ջ
Status Pop(LinkStack *S, char *ch) {
    if (StackEmpty(*S))
        return ERROR;
    LinkStack p = (*S)->next;
    *ch = p->data;
    (*S)->next = p->next;
    free(p);
    return OK;
}

// ��ȡջ��Ԫ��
Status GetTop(LinkStack S, char *e) {
    if (StackEmpty(S))
        return ERROR;
    *e = S->next->data;
    return OK;
}

// ������������Ƿ�ƥ��
Status match(char element_l, char element_r) {
    if (element_l == '(') {
        return (element_r == ')') ? TRUE : FALSE;
    } else if (element_l == '[') {
        return (element_r == ']') ? TRUE : FALSE;
    } else if (element_l == '{') {
        return (element_r == '}') ? TRUE : FALSE;
    } else {
        exit(0);
    }
}

int main() {
	//SetConsoleOutputCP(65001);
    LinkStack S;
    char e;
    int length = 0,i;
    char str[MAXSIZE];

    InitStack(&S);
    scanf("%s", str); // ����һ������
    length = strlen(str);

    for (i = 0; i < length; i++) {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                Push(&S, str[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (StackEmpty(S)) {
                    printf("�����Ŷ���\n");
                    exit(0);
                } else {
                    GetTop(S, &e);
                    if (match(e, str[i])) {
                        Pop(&S, &e);
                    } else {
                        printf("�������Ų�ƥ��\n");
                        exit(0);
                    }
                }
                break;
            default:
                exit(0);
        }
    }

    if (StackEmpty(S)) {
        printf("����ƥ��\n");
    } else {
        printf("�����Ŷ���\n");
    }

    return 0;
}

