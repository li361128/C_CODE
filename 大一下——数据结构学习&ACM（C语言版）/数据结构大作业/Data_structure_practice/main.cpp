//
/**
  ******************************************************************************
  * @file           : function_declaration.h
  * @author         : lct2023
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/2
  ******************************************************************************
  */
//

#include "function_declaration.h"


int main()
{
    //��ʼ��pFlight��pFlightΪȫ�ֱ�����
    InitFlight();
    //��flight1�е����ݴ�����ʼ�����������溬���ĸ��ڵ�
    Create(flight1);

   while(1)
   {
   	   fflush(stdin); // ��ձ�׼���뻺����
       SetUp();//�˵���ʼ��
       cout << "����������ѡ��0~7��:" << endl;
       int select;
       scanf("%d", &select);
       fflush(stdin); // ��ձ�׼���뻺����
       system("CLS");
       switch (select)
       {
           case 1:
               cout << "1.¼�뺽����Ϣ "<< endl;
               if(OK == InsertFlight())
                   cout <<"¼�뺽����Ϣ�ɹ�"<< endl;
               break;
           case 2:
               cout << "2.���غ������� "<< endl;
               PrintFilghtlist(pFlight);
               break;
           case 3:
               cout << "3.��������¼ "<< endl;
               if (OK == DeleteFlight()) 
			   {
                   printf("ɾ���ɹ�\n");
               } 
			   else 
			   {
                   printf("û��������࣬ɾ��ʧ�ܣ�\n");
               }
               break;
           case 4:
               cout << "4.��ѯ���� "<< endl;
               SearchFlight();
               break;
           case 5:
               cout << "5.��Ʊ&��Ʊ "<< endl;
               int choice5;
               printf("����������ѡ��1��ʾ��Ʊ��������ʾ��Ʊ\n");
			   scanf("%d",&choice5);
			   
			   if(choice5 == 1)	BookTickets();
			   else 	ReturnTicket();
               
               break;
           case 6:
               cout << "6.��ѯ�ÿ���Ϣ "<< endl;
               Visit_Passenger_Information(pFlight);
               break;
           case 7:
                cout << "7.���溽����Ϣ "<< endl;
                if(OK ==  Log_Flight_Information(pFlight))
                {
                    cout << "���溽����Ϣ�ɹ���" << endl;
                }
                else
                {
                   cout << "���溽����Ϣʧ�ܣ�"<< endl;
                }
                break;
           case 0:
               GoodbyeFace();
               exit(0);
           default:
               cout << "����������������룡"<< endl;
               break;
       }
       system("PAUSE");
       system("CLS");
   }
    return 0;
}
