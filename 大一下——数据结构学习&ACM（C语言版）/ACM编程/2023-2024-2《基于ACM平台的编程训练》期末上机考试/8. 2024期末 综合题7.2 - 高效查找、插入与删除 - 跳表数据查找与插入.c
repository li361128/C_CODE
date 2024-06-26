//========================================================
//     ������ C���԰�
//========================================================

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEVEL 4  /*����������*/
typedef struct skip_list_node
{
	int key;    /*key��Ψһ��*/
	int value; 	/*�洢������*/
	int level; 	/*��ǰ�ڵ�������*/
	/*ָ������,���ݸýڵ�����Ĳ�ͬ�����С��ͬ������
	 *next[0]��ʾ�ýڵ�ĵ�һ����һ�ڵ�ĵ�ַ
	 *next[1]��ʾ�ýڵ�ĵڶ�����һ�ڵ�ĵ�ַ
	 *next[n]��ʾ�ýڵ�ĵ�n����һ�ڵ�ĵ�ַ
	 */
	struct skip_list_node *next[];
} skip_list_node;

typedef struct skip_list
{
	int level; /*�������*/
	int num;   /*�ڵ���Ŀ*/
	struct skip_list_node *head;
} skip_list;

/**
 * ���ɱ�ڵ�.
 * 
 * ���أ�
 *  NULL:�ڴ�����ʧ��
 * !NULL:�ڵ㴴���ɹ�
 */
static skip_list_node* skip_list_node_creat(int level, int key, int value)
{
	struct skip_list_node *node = NULL;
	
	/* �ڵ�ռ��С Ϊ�ڵ����ݴ�С+ level��������ռ�õĴ�С */
	node = (skip_list_node*)malloc(sizeof(skip_list_node) + level * sizeof(skip_list_node*));
	if (node == NULL)
		return NULL;
	
	/* ��ֵ */
	node->key = key;
	node->value = value;
	node->level = level;
	int i;
    for(i=0; i<level; i++)
    {
    	 node->next[i] = NULL;
	}	
	return node;
}

/**
 * �����ʼ��.
 * ����
 * level:����������
 * ����
 * -1 :����ʧ��
 *  0 :�����ɹ�
 */
int skip_list_init(skip_list *L, int level)
{	
	L->level = level;
	L->num = 0;
    // L->head =(skip_list_node*)malloc(sizeof(skip_list_node)+(level)*sizeof(skip_list_node*));
    L->head = skip_list_node_creat(level, 0, 0);
	if (L->head == NULL)
	{
		return -1;
	}
	return 0;
}

/**
 * ��������ڵ�.
 * ���룺
 * list:����
 * key:
 * value:
 * ���� -1:����Ϊ��
 *     -2:�ռ����ʧ��
 *     -3:key�Ѿ�����
 *      0:����ɹ�
 */
int skip_list_insert(struct skip_list *list, int level, int key, int value)
{
	struct skip_list_node **update = NULL; /*��������ÿ��ָ�룬��Ų���λ�õ�ǰ������ڵ�*/ 
	struct skip_list_node *cur = NULL;
	struct skip_list_node *prev = NULL;
	struct skip_list_node *insert = NULL;
	int i = 0;
	
	if (list == NULL || level <0 || level > MAX_LEVEL)
		return -1;
	
	/*����update�ռ����ڱ���ÿ��ĵ�����λ��ǰ���ڵ�*/
	update = (skip_list_node **)malloc(list->head->level * sizeof(struct skip_list_node *));
	if (update == NULL)
		return -2;
	
	/*����ѯ,���Ҳ���λ�õ�ǰ������ڵ�����
	 *update[0] ��ŵ�һ��Ĳ���λ��ǰ���ڵ㣬update[0]->next[0]��ʾ����λ�õ�ǰ���ڵ����һ�ڵ�(update[0]->next[0])�ĵ�һ������ֵ
	 *update[1] ��ŵڶ���Ĳ���λ��ǰ���ڵ㣬update[1]->next[1]��ʾ����λ�õ�ǰ���ڵ����һ�ڵ�(update[1]->next[0])�ĵڶ�������ֵ
	 *update[n] ��ŵ�һ��Ĳ���λ��ǰ���ڵ㣬update[n]->next[n]��ʾ����λ�õ�ǰ���ڵ����һ�ڵ�(update[n]->next[0])�ĵ�n������ֵ
	 */
	prev = list->head; /*�ӵ�һ���ڵ㿪ʼ�����ϲ㿪ʼ��*/
	i = list->level - 1;
	for(; i>=0; i--)
	{
		/* ����ÿ���ڵ����һ���ڵ㲻Ϊ�� && �¸��ڵ��keyС��Ҫ�����key */
		while ( ((cur = prev->next[i]) != NULL) && (cur->key < key) )
		{
			prev = cur; /* ����ƶ� */
		}
		update[i] = prev; /* ����Ҫ����ڵ��ǰ���ڵ� */
	}
	
	/* ��ǰkey�Ѿ�����,���ش��� */
	if ((cur != NULL) && (cur->key == key))
	{
		return -3;
	}
	
	/*������ǰ�ڵ�*/
	insert = skip_list_node_creat(level, key, value);
	/*���������������,���²���ڵ��ǰ���ڵ�,ǰ���Ѿ����µ���[0] - [(list->level-1)]*/
	if (level > list->level)
	{
		for (i=list->level; i<level; i++)
		{
			update[i] = list->head;/*�ⲿ��Ϊ��������������,����ǰ���ڵ�Ĭ��Ϊͷ���*/
		}
		list->level = level;/*��������������������*/
	}
	
	/*�����½ڵ��ָ��*/
	for (i=0; i<level; i++)
	{
		insert->next[i] = update[i]->next[i];
		update[i]->next[i] = insert;
	}
	
	/*�ڵ���Ŀ��1*/
	list->num++;
	
	return 0;
}

/**
 * ��ѯ��ǰkey�Ƿ���������,���ڷ��ز�ѯ��value��ֵ.
 * 
 * list:����
 * key: ��ѯ��key
 * value:��ѯ������
 * ����ֵ -1:����Ϊ�� �� ����ڵ�����Ϊ0
 *         -3:key������
 *          0:���ҳɹ�
 */
int skip_list_search(skip_list *list, int key, int *value)
{
	
	//�����벹ȫ����

	struct skip_list_node *cur = NULL;
	struct skip_list_node *prev = NULL;

	int i = 0;
	
	if (list == NULL || list->num == 0)
		return -1;
	
	prev = list->head; /*�ӵ�һ���ڵ㿪ʼ�����ϲ㿪ʼ��*/
	i = list->level - 1;
	for(; i>=0; i--)
	{
		/* ����ÿ���ڵ����һ���ڵ㲻Ϊ�� && �¸��ڵ��keyС��Ҫ�����key */
		while ( ((cur = prev->next[i]) != NULL) && (cur->key < key) )
		{
			prev = cur; /* ����ƶ� */
		}
	}
	 if (cur->key == key)
	{
		*value = cur->value;
		return 0;
	}
	
	return -3;
}

/* ��ӡlevel������Ԫ�� */
void display(skip_list *list, int level)
{
    skip_list_node *cur;
    if (list == NULL && list->num == 0)
        return;
    if (level<0 || level > list->level)
        return;
    cur = list->head->next[level];
    while(cur)
    {
        printf("%d:%d\n", cur->key, cur->value);
        cur = cur->next[level];
    }
}

int main()
{
    skip_list list;
    int key;
    int value;
    int level;
    int i;
    
    skip_list_init(&list, MAX_LEVEL);
    scanf("%d%d%d", &level, &key, &value);
    while(level>0 || level>MAX_LEVEL)
    {
        skip_list_insert(&list, level, key, value);
        scanf("%d%d%d", &level, &key, &value);
    }
    printf("the number of nodes is %d\n", list.num);
    for(i=0; i<MAX_LEVEL; i++)
    {
        printf("the node of level %d\n", i);
        display(&list, i);
    }
    scanf("%d", &key);
    int res = skip_list_search(&list, key, &value);
    if(res == -1)
        printf("skip list is empty\n");
    else if(res == -3)
        printf("key not found\n");
    else
        printf("key found %d:%d\n", key, value);

    return 0;
}
