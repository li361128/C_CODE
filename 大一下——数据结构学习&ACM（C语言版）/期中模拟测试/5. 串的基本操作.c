#include "stdio.h"

#include "string.h"

#define Main_str_len 10

#define Sub_str_len 5

typedef unsigned char SString[Main_str_len+1];

int StrAssign(SString T,char *chars)

{

       //ѧ����������
		int i = 1;
	   for(;chars[i - 1] != '\0';i ++)
	   {
	   		T[i] = chars[i - 1];
		} 
		T[0] = i - 1;
		T[i] = '\0'; 
		return 1;
}

int MySubStrIndex(SString T, SString sub, int pos)

{
	
//	if(pos >= 1 && pos <= S[0])
//    {
//        int i = pos;
//        int j = 1;
//        while(i <= S[0] && j <= T[0])
//        {
//            if(S[i] == T[j])
//            {
//                ++i;++j;
//            }
//            else
//            {
//                i = i - j + 2;
//                j = 1;
//            }
//        }
//        if(j > T[0])    return i - T[0];//���� ��pos �ľ���
//        else return 0;
//    }
//    else return 0;

       //ѧ����������
       if(pos < 1 || pos >T[0])	return 0;
       int i = pos;
       int j = 1;
       while(i <= T[0] && j <= sub[0])
       {
       		if(T[i] == sub[j])
       		{
       			i ++;
       			j++;
			}
			else
			{
				i = i - j + 2;
				j = 1;
			}
	   }
	   if(j > sub[0])	return i - sub[0];
    	else return 0;

}

int MyStrInsert(SString T, int pos, SString sub)

{

       //ѧ����������
       int i = 0;
       for(i = 0;i < T[0] - pos + 1;i ++)
       {
       		T[T[0] + sub[0] - i] = T[T[0] - i];
	   }
       for(i = 0;i < sub[0];i ++)
       {
       		T[pos + i + 1] = sub[i + 1];
	   }
	   T[0] += sub[0];
	   T[T[0] + sub[0] + 1] = '\0';
	   return 1;

}

int StrDelete(SString T,int pos,int len)

{

       //�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ���ѧ������
       int i = 0;
       for(;i < T[0] - len;i ++ )
       {
       		T[i + pos] = T[i + pos + len ];
	   }
	   T[T[0] - len + 1] = '\0';
	   T[0] = T[0] - len;
	   return 1;

}

int StrEmpty(SString T)

{

       if(T[0]==0)

       {

              return 1;

       }

       return 0;

}

int StrLength(SString T)

{

       return T[0];

}

int Replace(SString T,SString S,SString V)

{   

   // ��V�滻����T�г��ֵ�������S��ȵĲ��ص����Ӵ�

   int i=1;  // �Ӵ�S�ĵ�һ���ַ�����Ҵ�T

   if(StrEmpty(T))

          return 0; // T�ǿմ�

   do{

               i = MySubStrIndex(T,S,i); // ���iΪ����һ��i֮���ҵ����Ӵ�T��λ��

               if(i)

               {

                 // ��S�д��ڴ�T

                 StrDelete(T,i,StrLength(S)); // ɾ���ô�T

                 MyStrInsert(T,i,V);  // ��ԭ��T��λ�ò��봮V

                 i+=StrLength(V); // �ڲ���Ĵ�V����������Ҵ�T

               }

   }while(i);

   return 1;

}

int StrCompare(SString T,SString S)

{

       //ѧ����������
       int i = 1;
       for(;i <= T[0] && i <= S[0];i ++)
       {
       		if(T[i] != S[i])	return T[i] - S[i];
	   }
	   return T[0] - S[0];

}

int main()

{

       int i;

       int res;

       int index;

       int pos;

       int len;

       int delpos;

       SString T={0};

       SString S={0};

       SString V={0};

       char input1[Main_str_len];

       char input2[Sub_str_len];

       char input3[Sub_str_len];

       printf("�����������Ӵ�\n");

       scanf("%s %s %s",input1,input2,input3);

       StrAssign(T,input1);

       StrAssign(S,input2);

       StrAssign(V,input3);     

       res=StrCompare(T,S);

       if(res>0)

       {

              printf("T������S��");

       }

       else if(res<0)

       {

              printf("T��С��S��");

 

       }else if(res==0)

       {

              printf("T������S��");

       }

       printf("\n");

       index=MySubStrIndex(T,S,1);

       printf("�Ӵ��������е�λ����:%d\n",index);

       scanf("%d",&pos);

       MyStrInsert(T,pos,S);

       printf("��ӡ�����Ӵ����Ԫ��\n");    

       for(i=1;i<=T[0];i++)

       {

              printf("%c ",T[i]);

       }

       printf("\n");

       printf("����ɾ��Ԫ�ص�λ�úͳ���\n");

       scanf("%d %d",&delpos,&len);

       StrDelete(T,delpos,len);

       printf("ɾ�����Ԫ��Ϊ\n");

       for(i=1;i<=T[0];i++)

       {

              printf("%c ",T[i]);

       }

       printf("\n");

       printf("�������е��Ӵ�S��ȫ���滻ΪV\n");

       Replace(T,S,V);

       for(i=1;i<=T[0];i++)

       {

              printf("%c ",T[i]);

       }

       printf("\n");

       return 1;

}
