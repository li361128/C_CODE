#include <stdio.h>

#include <string.h>

#include <stdlib.h>


#define STACK_INIT_SIZE    20     /*�洢�ռ�ĳ�ʼ������*/

#define STACK_INCREMENT    10     /*�洢�ռ�ķ�������*/

//#define CHAR_MAX 127

#define DBL_MAX 100

#define ERROR 0

#define OK 1


/*����ջ�ṹ�嶨�壬Ҫ��

����ջ��ָ�룬ջ��ָ��͵�ǰ����Ĵ洢����*/

typedef struct
{

    double *Dbase;

    double *Dtop;

    int Dstacksize;

} DataStack;


/*�������ṹ�嶨�壬Ҫ�����ջ��ָ�룬ջ��ָ��͵�ǰ����Ĵ洢����*/

typedef struct
{

    char *Obase;

    char *Otop;

    int Ostacksize;

} OpStack;


/*��̬��ά���ȼ����飺static char OperationPreceder[7][7]   

���������������������������������=���������ȼ�*/

static char OperationPreceder[7][7] =

        {{'>', '>', '<', '<', '<', '>', '>'},

         {'>', '>', '<', '<', '<', '>', '>'},

         {'>', '>', '>', '>', '<', '>', '>'},

         {'>', '>', '>', '>', '<', '>', '>'},

         {'<', '<', '<', '<', '<', '=', 'x'},

         {'>', '>', '>', '>', 'x', '>', '>'},

         {'<', '<', '<', '<', '<', 'x', '='}

        };


/*�����ӿڶ���Ϊ��int TransOPtoCD(char op_temp)   

* ���������������x   

* ������򼰷���ֵ����������ת��Ϊ�������ȼ���̬������꣬�����أ�   

* ��������ǣ�����������������������=���򷵻أ�1*/

int TransOPtoCD(char op_temp)
{

    switch (op_temp)
    {

        case '+':
            return (0);

        case '-':
            return (1);

        case '*':
            return (2);

        case '/':
            return (3);

        case '(':
            return (4);

        case ')':
            return (5);

        case '=':
            return (6);

        default:
            return (-1);  /*��������������������㡢���š��Ⱥ�ʱ�����أ�1*/

    }


}


/*�����ӿڶ���Ϊ��char Precede(char op1, char op2)   

* ������������бȽϵ������op1��op2��   

* ������򼰷���ֵ����op1��op2ת��Ϊ��ά����OperationPreceder�����꣬���Ҹ�����洢�ķ��ţ�����Ϊ����ֵ�����   

* ����޷��ҵ������򷵻�0*/

char Precede(char op1, char op2)
{

    int x, y;

    x = y = -1;

    x = TransOPtoCD(op1);

    y = TransOPtoCD(op2);

    if (x != -1 && y != -1)
    {

        //    printf("%c\n", OperationPreceder[x][y]);       

        return OperationPreceder[x][y];

    } else

        return 0;

}


/*�����ӿڶ���Ϊ��int checkch (char c)   

* ������������ʽ�ַ�c��   

* ������򼰷���ֵ���ж��ַ�c�����ֻ��ǲ�������   

* ���c�����ַ���1�������С���㷵��2����������������3������Ϊ��Ч�ַ����أ�1��   

* ���裺���ʽ�е�������������Ϊ����*/

int checkch(char c)
{

    if (c >= '0' && c <= '9')

        return 1;

    if (c == '.')

        return 2;

    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=')

        return 3;

    else

        return 0;

}


/*�����ӿڶ���Ϊ��double Operate(double x,double y, char op)��   

* ���������������x����������y��������op��   

* ������򼰷���ֵ������x op y���㣬������������Ĭ�Ϸ���0.0*/

double Operate(double x, double y, char op)
{

    switch (op)
    {

        case '+':

            return x + y;

        case '-':

            return x - y;

        case '*':

            return x * y;

        case '/':

            if (y != 0)

                return x / y;

            else

                printf("The divisor cannot be 0!\n");

            exit(-1);

        default:

            break;

    }

    return 0.0;

}


/*����ջ��ʼ���������壬Ҫ��   

* �����ӿڶ���Ϊ��int InitDataStack(DataStack *DS)   

* �������������ջDS   

* ������򼰷���ֵ�����ڴ��������STACK_INIT_SIZE�����Ϳռ䣬��ջ��ָ����ջ��ָ�붼ָ���ʼ��ַ����Dstacksize��ֵSTACK_INIT_SIZE   

* ��ʼ���ɹ�����1�����򷵻�0.*/

int InitDataStack(DataStack *DS)
{


    //����ע��, ���ú�����������
    DS->Dbase = (double*)malloc(sizeof(double));
    if(!DS->Dbase)	return ERROR;
    DS->Dtop = DS->Dbase;
	DS->Dstacksize =  STACK_INIT_SIZE;
	return OK;
	
	
}


/* ����ջ��ջ�������壬Ҫ��   

* �����ӿڶ���Ϊ��int PushDataStack(DataStack *DS,int e)   

* �������������������ջDS����������e��   

* ������򼰷���ֵ����ջ��ָ��λ�ô洢e������ջ��ָ��λ�ú��ƣ�����1��   

�������ջ�����ڻ�������ջ���磬���ش���0����*/

int PushDataStack(DataStack *DS, double e)
{
	if(!DS->Dbase)	return ERROR;//����ջ������
	if(DS->Dtop - DS->Dbase >= DS->Dstacksize)
	{//��ջ����,���·����ڴ� 
		DS->Dbase = (double*)realloc(DS->Dbase,(DS->Dstacksize +STACK_INCREMENT ) * sizeof(double));
		if(!DS->Dbase)	return ERROR;
		DS->Dtop = DS->Dbase + DS->Dstacksize;
		DS->Dstacksize += STACK_INCREMENT;
	}
	*(DS->Dtop++) = e;
	return OK;
   // ����ע��, ���ú�����������


}


/*����ջ��ջ�������壬Ҫ��   

* �����ӿڶ���Ϊ��int PopDataStack(DataStack *DS, int *e)   

* �������������ջDS, �������ָ�����e��   

* ������򼰷���ֵ����ջ��ָ���1�����õ�ַ�洢�ı���������e������1��   

�������ջ�����ڻ�����ջΪ�գ�����0��*/

int PopDataStack(DataStack *DS, double *e)
{

    //����ע��, ���ú�����������
    if(!DS->Dbase)	return ERROR;
    *e = *--DS->Dtop;
	return OK; 

}


/*����ջ�鿴ջ��Ԫ�غ������壬Ҫ��   

* �����ӿڶ���Ϊ��int GetDataTop(DataStack *DS)   

* �������������ջDS, ��¼ջ��Ԫ�ر���e��   

* ������򼰷���ֵ���������ջ�����ڻ�����ջΪ�գ�����DBL_MAX; ���򣬷���ջ��Ԫ�ء�*/

double GetDataTop(DataStack *DS)
{


    //����ע��, ���ú�����������
	if(!DS->Dbase)	return DBL_MAX;
	return *(DS->Dtop - 1);
	
}


/*����ջ���ٺ������壬Ҫ��   

* �����ӿڶ���Ϊ��int DestroyDataStack(DataStack *DS   

* �������������ջDS   

* ������򼰷���ֵ���ͷ�ջ��ָ����ָ�ռ䣬��������ջ��ջ�׺�ջ��ָ���ÿգ�����ջDstacksize��Ϊ0����󷵻�1*/

int DestroyDataStack(DataStack *DS)
{

    //����ע��, ���ú�����������
    free(DS->Dbase);
	DS->Dbase = NULL;
	DS->Dtop = NULL;
	DS->Dstacksize = 0;
	if(DS->Dbase)	return ERROR;
	return OK;

}


/*����ջ��ʼ���������壬Ҫ��   

* �����ӿڶ���Ϊ��int InitOpStack(OpStack *OS)   

* �������������ջOS   

* ������򼰷���ֵ�����ڴ��������STACK_INIT_SIZE�����Ϳռ䣬��ջ��ָ����ջ��ָ�붼ָ���ʼ��ַ����Dstacksize��ֵSTACK_INIT_SIZE   

* ��ʼ���ɹ�����1�����򷵻�0.*/

int InitOpStack(OpStack *OS)
{

    //����ע��, ���ú�����������
    OS->Obase = (char*)malloc(sizeof(char));
    if(!OS->Obase)	return ERROR;
    OS->Otop = OS->Obase;
    OS->Ostacksize = STACK_INIT_SIZE;
    return OK;

}


/* ����ջ��ջ�������壬Ҫ��   

* �����ӿڶ���Ϊ��int PushOpStack(OpStack *OS,int e)   

* �������������������ջDS���������e��   

* ������򼰷���ֵ����ջ��ָ��λ�ô洢e������ջ��ָ��λ�ú��ƣ�����1��   

�������ջ�����ڻ��߷���ջ���磬����0��*/

int PushOpStack(OpStack *OS, char e)
{


//    ����ע��, ���ú�����������
	if(!OS->Obase)	return OK;
	if(OS->Otop - OS->Obase >= OS->Ostacksize)	
	{
		OS->Obase = (char*)realloc(OS->Obase,(OS->Ostacksize + STACK_INCREMENT)*sizeof(char));
		
	}
	*OS->Otop++ = e;
}


/* ����ջ��ջ�������壬Ҫ��   

* �����ӿڶ���Ϊ��int PopOpStack(OpStack *OS, int *e)   

* �������������ջDS, �������ָ�����e��   

* ������򼰷���ֵ����ջ��ָ���1�����õ�ַ�洢�ı���������e������1��   

�������ջ�����ڻ����ջΪ�գ�����0��*/

int PopOpStack(OpStack *OS, char *e)
{

    //����ע��, ���ú�����������
    if(!OS->Obase)	return ERROR;
    *e = *--OS->Otop;
    return OK;

}


/* ����ջ�鿴ջ��Ԫ�غ������壬Ҫ��   

* �����ӿڶ���Ϊ��char GetOpTop(OpStack *OS)   

* �������������ջDS, ��¼ջ��Ԫ�ر���e��   

* ������򼰷���ֵ���������ջ�����ڻ�����ջΪ�գ�����CHAR_MAX; ���򣬷���ջ��Ԫ�ء�*/

char GetOpTop(OpStack *OS)
{


    //����ע��, ���ú�����������
	if(!OS->Obase)	return ERROR;
	return *(OS->Otop - 1);

}


/* ����ջ���ٺ������壬Ҫ��   

* �����ӿڶ���Ϊ��int DestroyOpStack(OpStack *OS)   

* �������������ջDS   

* ������򼰷���ֵ���ͷ�ջ��ָ����ָ�ռ䣬��������ջ��ջ�׺�ջ��ָ���ÿգ�����ջDstacksize��Ϊ0����󷵻�1*/

int DestroyOpStack(OpStack *OS)
{

    //����ע��, ���ú�����������
	free(OS->Obase);
	OS->Obase = NULL;
	OS->Otop = NULL;
	OS->Ostacksize = 0;
	if(OS->Obase)	return ERROR;
	return OK; 

}


int main()
{

    OpStack OPTR = {0};      /*�����ջ*/

    DataStack OPND = {0};    /*������ջ*/

    char op = 0;             /*��ǰ�����*/

    double value = 0.0;        /*�����ַ�����Ͻ��*/

    double b = 0.0;         /*��ǰ����Ĳ�����*/

    double a = 0.0;         /*��ǰ����ı�������*/

    char expression[1001] = {0};          /*���ʽ���棬���ʽ���Ȳ�����1000���ַ�*/

    int i = 0;                            /*���ʽ����ĵ�ǰ��ȡλ��*/



    /*����ջ��ʼ���������壬Ҫ��   

    * �����ӿڶ���Ϊ��int InitDataStack(DataStack *DS)   

    * �������������ջDS   

    * ������򼰷���ֵ�����ڴ��������STACK_INIT_SIZE�����Ϳռ䣬��ջ��ָ����ջ��ָ�붼ָ���ʼ��ַ����Dstacksize��ֵSTACK_INIT_SIZE   

    * ��ʼ���ɹ�����1�����򷵻�0.*/

    if (InitDataStack(&OPND) == 0)
    {

        printf("InitDataStack Wrong\n");

        return 1;

    }



    /*����ջ��ʼ���������壬Ҫ��   

    * �����ӿڶ���Ϊ��int InitOpStack(OpStack *OS)   

    * �������������ջOS   

    * ������򼰷���ֵ�����ڴ��������STACK_INIT_SIZE�����Ϳռ䣬��ջ��ָ����ջ��ָ�붼ָ���ʼ��ַ����Dstacksize��ֵSTACK_INIT_SIZE   

    * ��ʼ���ɹ�����1�����򷵻�0.*/

    if (InitOpStack(&OPTR) == 0)
    {

        printf("InitOpStack Wrong\n");

        return 1;

    }



    /*����ջջ��ѹ��'��'*/

    PushOpStack(&OPTR, '=');

    /*��ʾ������ʽ���ԵȺŽ���*/

    printf("Please input the expression:\n");

    /*�ӱ�׼�����ñ��ʽ��������expression*/

    gets(expression);

    /*�������룺���û���©��ʱ��ʾ*/

    if (expression[strlen(expression) - 1] != '=')
    {

        printf("Error: Please make sure the expression is ended with '='!");

        return 0;

    }


    while (i < strlen(expression) - 1 || GetOpTop(&OPTR) != '=')
    {

        //������Ч����       

        if (checkch(expression[i]) == 0)
        {

            printf("Error: Invalid Input!");

            return 0;

        }

        //�����ʽ��ǰ�ַ�������ʱ����λ���벢���       

        if (checkch(expression[i]) == 1)
        {

            while (checkch(expression[i]) == 1)
            {

                value = 10 * value + expression[i] - '0';

                i++;

            }

            /*������ʽ��ǰ�ַ���С����С���������ִ������С����֮ǰ���������*/

            if (checkch(expression[i]) == 2)
            {

                int r = 10;

                i++;

                while (checkch(expression[i]) == 1)
                {

                    value += (double) (expression[i] - '0') / r;

                    r = 10 * r;

                    i++;

                }

            }

            //����ѹ������ջOPND        

            PushDataStack(&OPND, value);

            value = 0.0;

        }



        /*������ʽ��ǰ�ַ��������������Ҫ�жϵ�ǰ����������ջջ������������ȼ�*/

        if (checkch(expression[i]) == 3)
        {


            switch (Precede(GetOpTop(&OPTR), expression[i]))
            {

                /*�������ջջ������������ȼ� < ���ʽ��ǰ�ַ����򽫱��ʽ��ǰ�ַ�ѹ�����ջ*/

                case '<':

                    PushOpStack(&OPTR, expression[i]);

                    i++;

                    break;

                    /*�������ջջ������������ȼ� = ���ʽ��ǰ�ַ���ɾȥ��ջ������*/

                case '=':

                    PopOpStack(&OPTR, &op);

                    i++;

                    break;

                    /*�������ջջ������������ȼ� > ���ʽ��ǰ�ַ��������ջ���������ʽ*/

                case '>':

                    PopOpStack(&OPTR, &op);

                    PopDataStack(&OPND, &b);

                    PopDataStack(&OPND, &a);

                    PushDataStack(&OPND, Operate(a, b, op));  /*������������ջ*/

                    break;

                default:

                    break;

            }

        }

    }

    /*��ӡ���ʽ������*/

    printf("The result is:%.2f\n", GetDataTop(&OPND));

    /*�����ͷ�����ջ�ͷ���ջ�Ŀռ�*/

    DestroyDataStack(&OPND);

    DestroyOpStack(&OPTR);

    return 0;

} 
