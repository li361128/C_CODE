#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

bool isMatch(char *str1, char *str2) {
    // �������ַ�����Ϊ��ʱ��������ƥ���
    if (*str1 == '\0' && *str2 == '\0')
        return TRUE;
    
    // ������һ���ַ���Ϊ��ʱ����һ����Ϊ�գ����ǲ�ƥ��
    if (*str1 == '\0' || *str2 == '\0')
        return FALSE;

    // �����ǰ�ַ�ƥ������� '?'��������Ƚ���һ���ַ�
    if (*str1 == *str2 || *str2 == '?')
        return isMatch(str1 + 1, str2 + 1);

    // ������� '*'����ݹ�س������п��ܵ����
    if (*str2 == '*') {
        // �� '*' ������Ӵ���Ϊģʽ��
        char *pattern = str2 + 1;
        
		while(*pattern == '*')	
		{
			pattern ++; 
			str1++;
		}
		       
		if(*pattern == '\0')	return TRUE;
		
		while(*pattern == '?')
		{
			pattern++;
        	str1++;
        	
        	// �������ַ�����Ϊ��ʱ��������ƥ���
   			if (*str1 == '\0' && *pattern == '\0')
        		return TRUE;
        		
        	// ������һ���ַ���Ϊ��ʱ����һ����Ϊ�գ����ǲ�ƥ��
    		if (*str1 == '\0' || *str2 == '\0')
        		return FALSE;
		}
		

		
        // �� str1 �в������п��ܵ�ƥ��
        while (*str1 != '\0') {
            if (isMatch(str1, pattern))
                return TRUE;
            str1++;
        }

        // ����� str1 ��û���ҵ�ƥ�䣬�򷵻� FALSE
        return FALSE;
    }

    // �����ǰ�ַ���ƥ�䣬�Ҳ���ͨ�������˵����ƥ��
    return FALSE;
}


int main() {
    char str1[1000], str2[1000];

    // ��ȡ�����ַ������� '#' ����
    scanf("%[^#]#", str1);
    getchar();  // ��ȡ���������з�
    scanf("%[^#]#", str2);
    
//    puts(str1);
//	puts(str2); 
    
    // ����ƥ�亯������ƥ��
    if (isMatch(str2, str1)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}



//#include <stdio.h>
//#include<string.h>
//#include <stdbool.h>
//
//#define MAXSTRLEN 100
//#define TRUE 1
//#define FALSE 0
//#define ERROR -1
//#define OK 1
//
//typedef char SString[MAXSTRLEN + 1];
//
////bool isMatch(char* s, char* p) {
////    int m = strlen(s),j;
////    int n = strlen(p),i;
////    int dp[m + 1][n + 1];
////    memset(dp, 0, sizeof(dp));
////    dp[0][0] = true;
////    for (i = 1; i <= n; ++i) {
////        if (p[i - 1] == '*') {
////            dp[0][i] = true;
////        } else {
////            break;
////        }
////    }
////    for (i = 1; i <= m; ++i) {
////        for (j = 1; j <= n; ++j) {
////            if (p[j - 1] == '*') {
////                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
////            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
////                dp[i][j] = dp[i - 1][j - 1];
////            }
////        }
////    }
////    return dp[m][n];
////}
//
//void SStringAssign(SString S,char*str)
//{
//	int i = 1,len = 0;
//	for(;str[len] != '\0';len ++)
//	for(;str[i - 1] != '\0';i ++)
//	{
//		S[i] = str[i - 1];
//	}
//	S[0] = len;
//	S[len + 1] = '\0'; 
//}
//
//int Index(char* s,char* t,int pos)
//{
//	SString S,T;
//	SStringAssign(S,s);
//	SStringAssign(T,t);
//    if(pos >= 1 && pos <= S[0])
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
//}
//
//bool isMatch(char *str1,char *str2)
//{	
//	int len_1 = strlen(str1);
//	int len_2 = strlen(str2);
//	int i = 0,j = 0,k = 0;
//	for(i = 0;i <len_2;i ++)
//	{
//		for(j = 0;j < len_1;j ++)
//		{
//			if(str1[i] == str2[j] || str2[j] == '?')	continue;
//			else if(str2[j] == '*')
//			{
//				char substr[1000];
//				for(k = 1;( str2[j + k] == '*' || str2[j + k] == '?') && str2[j + k] != '\0';k ++)
//				{
//					substr[k - 1] = str2[j + k];
//				}	
//				int pos = i;
//				while(pos < len_1)
//				{
//					pos = Index(str1,substr,pos);
//					if(pos == 0)	retrun FALSE;
//					else 
//					{
//						
//					}
//				}
//			}
//		}
//	}
//} 
//
//int main() {
//    char str1[1000], str2[1000];
//
//    // ��ȡ�����ַ������� '#' ����
//    scanf("%[^#]#", str1);
//    getchar();
//    scanf(" %[^#]#", str2);
//    
//    //putchar(ch);
//	
////	scanf("%s",str1);
////	scanf("%s",str2);
//	//puts(str1);
//	//puts(str2); 
//	
//    // ����ƥ�亯������ƥ��
//    if (isMatch(str1, str2)) {
//        printf("yes\n");
//    } else {
//        printf("no\n");
//    }
//
//    return 0;
//}

