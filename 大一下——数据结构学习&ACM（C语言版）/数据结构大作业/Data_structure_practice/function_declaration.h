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
#include "function.cpp"

/**
  *  @function   SetUp
  *  @brief      �˵���ʼ��
*/
void SetUp();


/**
 * ��ѯģ�� ��ӡinfo����Ļ�����Ϣ
 * @param info
 */
void Display(Flight *info);


 /**
   *  @function   InitFlight
   *  @brief      ��ʼ����pFlightΪͷ���Ŀպ�������,¼�뺽����Ϣ�����Ӻ���󽫺�������������
 */
void InitFlight();


/**
 * @brief ��ʼ���Ѷ�Ʊ�˿�ָ������
 * @param cusLinkList �����г�Ա�����ͷָ��
 * @return ����ִ��״̬
 */
Status InitCusLinkList(CusLinkList &cusLinkList);


/**
 * @brief ��ʼ����ͷ����������
 * @param q ���ӵ�ͷ���
 */
Status InitQueue(LinkQueue &q);


/**
 * @brief ��flight1��6��������ͷ���뷨���뵽pFlight��������
 * @param flight1 �������������������
 * @return ���ز����Ƿ�ɹ�
 */
Status Create(PFlight flight1);


/**
 * @brief ���Ӻ���ʱ�������ڵĸ���������1��������һ��7���������գ�
 * @param day1 ��������1-7�е�һ��
 * @param day ��������������Է��ػ�ȥ����������ڱ���
 * @return ���ز���״̬�������Ƿ�Ϸ�
 */
Status IputDay(int day1, char day[]);


/**
 * @brief ���뺽��ʱ�������࣬��ֹ����ID�ظ�������ID�൱��������
 * @param flight �����ͷ���
 * @param flightCodeID  ��Ҫ���б������Һ����
 * @return  �����Ƿ��ظ�
 */
Status TraverseFlight(Flight *flight, char flightCodeID[]);


/**
  * @brief ���µĺ�������뵽���������У�
  * @return ���ز����Ƿ�ɹ�
  */
Status InsertFlight();


/**
 * @brief ��ѯģ��, ��ӡȫ��������Ϣ
 * @param pflight ������Ǻ��������ͷָ��
 */
void PrintFilghtlist(Flight *pflight);


/**
  * @brief ɾ���ڵ�
  * @return ���ز����Ƿ�ɹ�
  */
Status DeleteFlight();


/**
 *@brief ���ݿͻ��������㣬�յ�վ�����������Ϣ
 */
void SearchFlight();


/**
 * @brief ��ӣ������ŶӵȺ�Ŀͻ�������
 * @param q ��ͷ����������
 * @param name  �Ⱥ�ͻ�������
 * @param amount    �Ⱥ�ͻ������Ʊ������
 * @param identification    �Ⱥ�ͻ������֤��
 * @return  ���سɹ���Ӻ�ĵȺ�ͻ�����ͷ���
 */
LinkQueue Appendqueue(LinkQueue &q, char name[], int amount, char identification[]);


/**
 * @brief �����Լ�����ĺ���ID��ѯ����ָ����ʽ����
 * @return  ����ָ��
 */
Flight *find();


/**
 * ��Ʊ�ɹ�֮�󣬽��˿���Ϣ���뵽��Ӧ����Ķ���Ա�������У�����
 * @param head �˿�������ͷָ��
 * @param amount �ó˿Ͷ�Ʊ������
 * @param name �˿͵�����
 * @param rank ��Ʊ�ĵȼ�
 * @return  �˿�����ͷָ��
 */
CusLinkList insertlink(CusLinkList &head, int amount, char name[], char identification[], int rank);


/**
 * @brief ���p�ڵ�ĺ�����Ϣ
 * @param p ����ڵ�
 */
void FlightInfo(Flight *p);


/**
 * @brief �����Ƿ���ͬһ·�ߵĺ���
 * @param destination   Ŀ�ĵ�
 * @param pflight ԭ���࣬�����жϺ����ѵ��ĺ����Ƿ�һ��
 * @return �Ҳ����ͷ���FALSE�����򷵻�TRUE
 */
Status RecommendFlight(char startPoint[], char destination[], Flight *pflight);


/**
 * @brief ��Ʊģ��
 */
void BookTickets();


/**
 * @param Q   QΪ�򲹶�Ʊ�ͻ��Ķ���
 * @param NameAndNumAndIDAndID �򲹿ͻ��������Ͷ�Ʊ��Ŀ������ʱ���������͹ؼ��ֺ����֤����
 * @return
 */
Status QueueDelete(LinkQueue &q, NameAndNumAndID &NameAndNumAndID);


/**
 * @brief ��Ʊ����ģ��
 */
void ReturnTicket();


/**
  *  @function   Log_Flight_Information
  *  @brief      ��������Ϣ����ļ�"������Ϣ��¼��־.txt"
  *  @param      pflight ����ͷָ��
  *  @return     ����ִ��״̬
*/
Status Log_Flight_Information(Flight *pflight);

/**
  *  @function   Visit_Passenger_Information
  *  @brief      �����ÿ���Ϣ
  *  @param      pflight ����ͷָ��
  *  @return     ����ִ��״̬
*/
Status Visit_Passenger_Information(Flight *pflight);


/**
 * @brief �˳�����ģ�����
 */
void GoodbyeFace();


#ifndef DATA_STRUCTURE_PRACTICE_FUNCTION_DECLARATION_H
#define DATA_STRUCTURE_PRACTICE_FUNCTION_DECLARATION_H

#endif //DATA_STRUCTURE_PRACTICE_FUNCTION_DECLARATION_H
