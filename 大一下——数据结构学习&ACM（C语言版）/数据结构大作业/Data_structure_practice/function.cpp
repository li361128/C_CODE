//
/**
  * @file           : function.cpp
  * @author         : lct2023
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/2
  */
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <malloc.h>
#include <fstream>
#include <ctime>
#include <iomanip>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define FALSE -1
#define TRUE 1

using namespace std;

typedef int Status;

//��������ö���࣬����һ��������
enum Week{
    Mon = 1, Tues = 2, Wed = 3, Thurs = 4, Fri = 5, Sat = 6, Sun = 7
};

//�˿ͽڵ�
typedef struct CustomerNode
{
    char name[10];//�ͻ�����
    int clientTickets;//�ͻ���Ʊ��
    char identification[20];//�ͻ����֤����
    int rank;//��λ�ȼ�
    CustomerNode *next;
} CustomerNode, *CusLinkList;

//�򲹶����еĽڵ�
typedef struct WaitPassenger
{
    char name[10];//����
    char identification[20]; //���֤
    int preTickets;//Ԥ����Ʊ��
    struct WaitPassenger *next;
} WaitQNode, *PWait;

//�򲹶���
typedef struct Queue
{
    PWait front;//�Ⱥ��油�ͻ��������ͷָ��
    PWait rear;//�Ⱥ��油�ͻ��������βָ��
} LinkQueue;

//��װ�˿͵������Ͷ�Ʊ�������֤
//���ں򲹿ͻ�����ʱ�ѹؼ��ַ���
typedef struct NameAndNumAndID
{
    char name[10];//����
    char identification[20]; //���֤����
    int num;//��Ʊ��
} NameAndNumAndID;

//����ڵ�
typedef struct Flight
{
    char startPoint[20];//���վ��
    char destination[20];//�յ�վ��
    char flightCodeID[20];//����ID���൱��������
    char planeNum[20];//�ɻ���
    char day[20];//�������ڣ����ڼ���
    int totalTickets;//��Ա����(��Ʊ��)
    int left;//����Ʊ��
    int leftEconomicTicket; //����Ʊʣ����
    int leftBusinessTicket; //����Ʊʣ����
    Flight *next;
    CusLinkList cusLinkList;//��Ա������ָ���Ա���������ͷָ��
    LinkQueue waitQueue1;//���òպ򲹣��Ⱥ��油�Ŀͻ�������ָ��һ������
    LinkQueue waitQueue2;//����պ򲹣��Ⱥ��油�Ŀͻ�������ָ��һ������

} Flight, FlightNode, *PFlight;

//����ȫ��ָ�����pFlight�����������ͷָ��
Flight *pFlight;

//�����������
Flight flight1[5] = {
        {"����", "֣��", "A1", "K1250", "������", 12, 12, 6},
        {"����", "��ͷ", "B2", "L6525", "������", 12, 12, 6},
        {"����", "�׸�", "C3", "K1010", "������", 12, 12, 6},
        {"����", "����", "D4", "L6333", "���ڶ�", 12, 12, 6},
        {"����", "��", "E5", "K1210", "������", 12, 12, 6},
//        {"��ͷ", "����", "F6", "K9857", "������", 12, 12, 6}
};

// ð�������������պ���ID��С��������
void bubbleSort_PFlight(PFlight *head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // �������Ϊ�ջ���ֻ��һ���ڵ㣬����Ҫ����
    }

    Flight *end = NULL; // ���ڱ���Ѿ��ź���Ĳ���

    while (end != *head) { // ���ѭ���������������
        Flight **prev = head; // ǰһ���ڵ��ָ���ָ��
        Flight *current = *head; // ��ǰ�ڵ�ָ��
        Flight *nextNode = current->next; // ��һ���ڵ�ָ��

        while (current->next != end) { // �ڲ�ѭ������һ��������ð�ݹ���
            nextNode = current->next;
            if (strcmp(current->flightCodeID, nextNode->flightCodeID) > 0) { // �Ƚϵ�ǰ�ڵ����һ���ڵ�ĺ���ID
                // �����ڵ��λ��
                *prev = nextNode;
                current->next = nextNode->next;
                nextNode->next = current;

                // ����ָ��
                Flight *temp = current;
                current = nextNode;
                nextNode = temp;
            }

            // ����ָ�룬������һ�αȽ�
            prev = &current->next;
            current = nextNode;
        }

        // �������ź���Ĳ���
        end = current;
    }
}


/**
  *  @function   InitFlight
  *  @brief      ��ʼ����pFlightΪͷ���Ŀպ�������,¼�뺽����Ϣ�����Ӻ���󽫺�������������
*/
void InitFlight()
{
    pFlight = (Flight *) malloc(sizeof(Flight));//����ͷ���Ŀռ�
    if (pFlight == NULL) exit(0);
    pFlight->next = NULL;//��ͷ���h��ָ������Ϊ��
}

/**
 * @brief ��ʼ���Ѷ�Ʊ�˿�ָ������
 * @param cusLinkList �����г�Ա�����ͷָ��
 * @return ����ִ��״̬
 */
Status InitCusLinkList(CusLinkList &cusLinkList)
{
    CusLinkList q = cusLinkList;
    cusLinkList = (CustomerNode *) malloc(sizeof(CustomerNode));
    cusLinkList->next = NULL;
}

/**
 * @brief ��ʼ����ͷ����������
 * @param q ���ӵ�ͷ���
 */
Status InitQueue(LinkQueue &q)
{
    WaitQNode *p;
    p = (WaitQNode *) malloc(sizeof(WaitQNode));
    if (p == NULL) {
        printf("�ڴ治��\n");
        return ERROR;
    }

    p->next = NULL;
    q.front = q.rear = p;
    return OK;

}

/**
 * @brief ��flight1��6��������ͷ���뷨���뵽pFlight��������
 * @param flight1 �������������������
 * @return ���ز����Ƿ�ɹ�
 */
Status Create(PFlight flight1)
{
    Flight *p = pFlight, *q;
    for (int i = 0; i < 5; i++) {
        q = (Flight *) malloc(sizeof(Flight));
        if (q == NULL)
            return ERROR;
        strcpy(q->startPoint, flight1[i].startPoint);
        strcpy(q->destination, flight1[i].destination);
        strcpy(q->flightCodeID, flight1[i].flightCodeID);
        strcpy(q->planeNum, flight1[i].planeNum);
        strcpy(q->day, flight1[i].day);
        q->totalTickets = flight1[i].totalTickets;
        q->left = flight1[i].totalTickets;
        q->leftEconomicTicket = flight1[i].leftEconomicTicket;
        q->leftBusinessTicket = flight1[i].totalTickets - flight1[i].leftEconomicTicket;
        //��ʼ���˿�����
        InitCusLinkList(q->cusLinkList);

        InitQueue(q->waitQueue1);
        InitQueue(q->waitQueue2);

        q->next = p->next;
        p->next = q;

    }
    return OK;

}

/**
 * @brief ���Ӻ���ʱ�������ڵĸ���������1��������һ��7���������գ�
 * @param day1 ��������1-7�е�һ��
 * @param day ��������������Է��ػ�ȥ����������ڱ���
 * @return ���ز���״̬�������Ƿ�Ϸ�
 */
Status IputDay(int day1, char *day)
{
    switch (day1) {
        case Mon:
            strcpy(day, "����һ");
            break;
        case Tues:
            strcpy(day, "���ڶ�");
            break;
        case Wed:
            strcpy(day, "������");
            break;
        case Thurs:
            strcpy(day, "������");
            break;
        case Fri:
            strcpy(day, "������");
            break;
        case Sat:
            strcpy(day, "������");
            break;
        case Sun:
            strcpy(day, "������");
            break;
        default:
            return ERROR;
    }
    return OK;
}


/**
 * @brief ���뺽��ʱ�������࣬��ֹ����ID�ظ�������ID�൱��������
 * @param flight �����ͷ���
 * @param flightCodeID  ��Ҫ���б������Һ����
 * @return  �����Ƿ��ظ�
 */
Status TraverseFlight(Flight *flight, char *flightCodeID)
{
    Flight *p = flight;
    while (p != NULL)
    {
        //���к���ID�ظ�ʱ�򣬷���ERROR��
        if (!strcmp(flightCodeID, p->flightCodeID))
        {
            return ERROR;
        }

        p = p->next;
    }
    //����ĺ���ID���ظ�
    return OK;

}


/**
  * @brief ���µĺ�������뵽���������У�
  * @return ���ز����Ƿ�ɹ�
  */
Status InsertFlight()
{
    FlightNode *q;//����qΪ�����ӵĺ������ָ����β�
    Flight *p = pFlight;
    int mark = 1;

    while (mark != 0) {
        q = (FlightNode *) malloc(sizeof(FlightNode));
        if (q == NULL)
            return ERROR;

        printf("\t\t������������������\n");
        printf("\t\t�����뺽��ID\n");
        scanf("%s", q->flightCodeID);
        Status status = TraverseFlight(pFlight, q->flightCodeID);
        if (status == ERROR) {
            printf("�ú���ID�Ѿ����ڣ����������뺽��ID\n");
            continue;
        }
        printf("\t\t���������վ��\n");
        scanf("%s", q->startPoint);
        printf("\t\t�������յ�վ��\n");
        scanf("%s", q->destination);
        printf("\t\t������ɻ���\n");
        scanf("%s", q->planeNum);
        printf("\t\t�������������(1��������һ,2�������ڶ�.....7����������)\n");
        int day1;
        scanf("%d", &day1);
        while (ERROR == IputDay(day1, q->day)) {
            printf("������Ϸ�����(1-7)\n");
            scanf("%d", &day1);
        };

        printf("\t\t������˿Ͷ���\n");
        scanf("%d", &q->totalTickets);
        q->left = q->totalTickets;

        printf("\t\t�����뾭��Ʊ��Ŀ��ͬʱҲ����������Ʊ����Ŀ��\n");
        scanf("%d", &q->leftEconomicTicket);
        //����Ʊ��Ŀ = ��Ʊ��Ŀ - ����Ʊ��Ŀ
        q->leftBusinessTicket = q->totalTickets - q->leftEconomicTicket;
        InitCusLinkList(q->cusLinkList);
        //��ʼ��
        InitQueue(q->waitQueue1);
        InitQueue(q->waitQueue2);

        q->next = p->next;
        p->next = q;

        printf("\t\t�Ƿ����¼�뺽����Ϣ���������ּ�����0��ʾֹͣ����\n");
        printf("\t\t�����룺");
        scanf("%d", &mark);
    }
    return OK;
}

/**
  *  @function   SetUp
  *  @brief      �˵���ʼ��
*/
void SetUp()
{
	cout << endl << endl;
	std::cout << "          ##       /        ## ###### /       ####    ####      /         /      ######" << std::endl;  
    std::cout << "           ##     ///      ##  #      /       #       #  #     / /       / /     #     " << std::endl;  
    std::cout << "            ##   /// //   ##   #####  /       #       #  #    /   /     /   /    ##### " << std::endl;  
    std::cout << "             ## //   //  ##    #      /       #       #  #   /     /   /     /   #     " << std::endl;  
    std::cout << "              ///      ///     #      /       #       #  #  /       ///       /  #     " << std::endl;  
    std::cout << "               /        /      ###### ######  ####    #### /         /         / ######" << std::endl;  
  
    cout << endl << endl << endl;
    cout << "                     �������������� Airplane Servervice System ���������������" << endl;
    cout << endl;
    cout << "                              ����������������������������������������������������������������������������\n";
    cout << "                              ��      ��ӭʹ�ú��տ��˶�Ʊϵͳ      ��\n";
    cout << "                              ����������������������������������������������������������������������������\n";
    cout << "                              �� 1.¼�뺽����Ϣ    5.��Ʊ&��Ʊ      ��\n";
    cout << "                              ����������������������������������������������������������������������������\n";
    cout << "                              �� 2.���غ�������    6.��ѯ�ÿ���Ϣ   ��\n";
    cout << "                              ����������������������������������������������������������������������������\n";
    cout << "                              �� 3.��������¼    7.���溽����Ϣ   ��\n";
    cout << "                              ����������������������������������������������������������������������������\n";
    cout << "                              �� 4.��ѯ������Ϣ    0.�˳�ϵͳ       ��\n";
    cout << "                              ����������������������������������������������������������������������������\n";
}

/**
 * @brief ��ѯģ�� ��ӡinfo����Ļ�����Ϣ
 * @param info ����������Ϣ 
 */
void Display_flight_Infomation(Flight *info)
{
    //printf("���վ��\t�յ�վ��\t����ID\t�ɻ���\t��������\t��Ա����\t��Ʊ��\t����Ʊʣ����\t����Ʊʣ����\n");
    printf("%8s\t%8s\t%3s\t%s\t%4s\t\t%3d\t%10d\t%10d\t%10d\n", info->startPoint, info->destination, info->flightCodeID,
           info->planeNum, info->day,
           info->totalTickets, info->left, info->leftEconomicTicket, info->leftBusinessTicket);
}


Status Log_Flight_Information(Flight *pflight) {
    fstream ifs;
    // ׷��д�룬��ԭ�������ϼ���ios::app
    ifs.open("������Ϣ��¼��־.txt", ios::out | ios::app);

    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return ERROR;
    }

    // ��ȡ��ǰʱ��
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // ��ʽ��ʱ����Ϣ
    char timeStr[50];
    snprintf(timeStr, sizeof(timeStr), "%04d-%02d-%02d %02d:%02d:%02d",
             1900 + ltm->tm_year,
             1 + ltm->tm_mon,
             ltm->tm_mday,
             ltm->tm_hour,
             ltm->tm_min,
             ltm->tm_sec);

    // ��������д�������
    ifs << "���������Ϣ��" << endl;
    ifs << "����ʱ��: " << timeStr << endl;
    ifs << left << setw(12) << "���վ" << setw(12) << "�յ�վ" << setw(10) << "����ID"
        << setw(10) << "�ɻ���" << setw(10) << "��������" << setw(12) << "��Ա����"
        << setw(8) << "��Ʊ��" << setw(12) << "����Ʊ����" << setw(14) << "����Ʊ����" << endl;

    Flight *info = pflight->next;

    bubbleSort_PFlight(&info);
    while (info) {
        ifs << left << setw(16) << info->startPoint
            << setw(14) << info->destination
            << setw(12) << info->flightCodeID
            << setw(12) << info->planeNum
            << setw(12) << info->day
            << setw(14) << info->totalTickets
            << setw(16) << info->left
            << setw(18) << info->leftEconomicTicket
            << setw(16) << info->leftBusinessTicket << endl;
        info = info->next;
    }

    ifs.close();
    return OK;
}


/**
 * @brief ��ѯģ��, ��ӡȫ��������Ϣ
 * @param pflight ������Ǻ��������ͷָ��
 */
void PrintFilghtlist(Flight *pflight)
{
    Flight *p;
    //��ͷ����ͷָ�룬���Դ���һ��ָ�뻹�Ǳ���

    p = pflight->next;
    system("cls");

    // �������������
    bubbleSort_PFlight(&p);

    printf("���վ��\t�յ�վ��\t����ID\t�ɻ���\t��������\t��Ա����\t��Ʊ��\t����Ʊʣ����\t����Ʊʣ����\n");
    while (p != NULL) {
        //����Display_flight_Infomation������ӡ��ÿ������ڵ����Ϣ
        Display_flight_Infomation(p);
        p = p->next;
    }
    printf("\n\n");
}

/**
  * @brief ɾ���ڵ�
  * @return ���ز����Ƿ�ɹ�
  */
Status DeleteFlight() {
    char flightCodeID[20];
    printf("������һ������ID\n");
    scanf("%s", flightCodeID);
    PFlight pre = pFlight;
    PFlight p = pre->next;

    while (p != NULL) {
        if (!strcmp(flightCodeID, p->flightCodeID)) {
            pre->next = p->next;
            free(p);
            return OK;
        }
        pre = p;
        p = p->next;
    }
    return ERROR;
}

/**
 *@brief ���ݿͻ��������㣬�յ�վ�����������Ϣ
 */
void SearchFlight() {
    char startPonit[10];
    char destination[10];
    int flag = 0;
    system("cls");
    printf("���������վ��:");
    scanf("%s", startPonit);
    printf("�������յ�վ��:");
    scanf("%s", destination);
    struct Flight *p;
    p = pFlight->next;
    printf("���վ��\t�յ�վ��\t����ID\t�ɻ���\t��������\t��Ա����\t��Ʊ��\t����Ʊʣ����\t����Ʊʣ����\n");

    while (p != NULL) {
        if ((strcmp(startPonit, p->startPoint) == 0) && (strcmp(destination, p->destination) == 0) ) {
            flag = 1;
            Display_flight_Infomation(p);
        }
        p = p->next;
    }
    printf("\n\n");

    if (flag == 0)
        printf("�Բ��𣬸ú���δ�ҵ�! \n");

}

/**
 * @brief ��ӣ������ŶӵȺ�Ŀͻ�������
 * @param q ��ͷ����������
 * @param name  �Ⱥ�ͻ�������
 * @param amount    �Ⱥ�ͻ������Ʊ������
 * @param identification    �Ⱥ�ͻ������֤��
 * @return  ���سɹ���Ӻ�ĵȺ�ͻ�����ͷ���
 */
LinkQueue Appendqueue(LinkQueue &q, char name[], int amount, char identification[])
{
    PWait new1;
    new1 = (PWait) malloc(sizeof(WaitQNode));
    strcpy(new1->name, name);
    strcpy(new1->identification, identification);
    new1->preTickets = amount;
    new1->next = NULL;

    q.rear->next = new1;
    q.rear = new1;

    return q;
}


/**
 * @brief �����Լ�����ĺ���ID��ѯ����ָ����ʽ����
 * @return  ����ָ��
 */
Flight *find()
{
    char number[10];
    int i = 0;
    int loop;

    printf("�����뺽��ID: ");
    scanf("%s", number);

    //ͷ������һ���ڵ㿪ʼ����
    Flight *p = pFlight->next;

    while (p != NULL) {
        if (!strcmp(number, p->flightCodeID))
            return p;

        p = p->next;
    }
    return NULL;
}

/**
 * ��Ʊ�ɹ�֮�󣬽��˿���Ϣ���뵽��Ӧ����Ķ���Ա�������У�����
 * @param head �˿�������ͷָ��
 * @param amount �ó˿Ͷ�Ʊ������
 * @param name �˿͵�����
 * @param rank ��Ʊ�ĵȼ�
 * @return  �˿�����ͷָ��
 */
CusLinkList insertlink(CusLinkList &head, int amount, char name[], char identification[], int rank)
{
    //��Ա�������½ڵ�new1
    CusLinkList new1;
    new1 = (CustomerNode *) malloc(sizeof(CustomerNode));
    if (new1 == NULL)
    {
        printf("\n�ڴ治��\n");
        return NULL;
    }
    //������˿���Ϣ��ֵ��new1�ڵ�
    strcpy(new1->name, name);
    strcpy(new1->identification, identification);
    new1->clientTickets = amount;
    new1->rank = rank;

    //ͷ���뷨�����Ա������
    new1->next = head->next;
    head->next = new1;

    return head;
}

/**
 * @brief ���p�ڵ�ĺ�����Ϣ
 * @param p ����ڵ�
 */
void FlightInfo(Flight *p) {
    printf("���վ��\t�յ�վ��\t����ID\t�ɻ���\t��������\t��Ա����\t��Ʊ��\t����Ʊʣ��\t����Ʊʣ��\n");
    Display_flight_Infomation(p);
    printf("\n\n");

}

/**
 * @brief �����Ƿ���ͬһ·�ߵĺ���
 * @param destination   Ŀ�ĵ�
 * @param pflight ԭ���࣬�����жϺ����ѵ��ĺ����Ƿ�һ��
 * @return �Ҳ����ͷ���FALSE�����򷵻�TRUE
 */
Status RecommendFlight(char startPoint[], char destination[], Flight *pflight) {
    //��Ǳ������Ƿ��ҵ�ͬһ·�ߵĺ���
    int flag = 0;
    system("cls");
    struct Flight *p;
    p = pFlight->next;
    printf("Ѱ��ͬһ·�ߵĺ���\n");
    printf("���վ��\t�յ�վ��\t����ID\t�ɻ���\t��������\t��Ա����\t��Ʊ��\t����Ʊʣ����\t����Ʊʣ����\n");

    while (p != NULL)
    {
        //·����ͬ���Ҳ���ͬһ�����࣬���flag = 1����ʾ�ҵ�
        if (strcmp(destination, p->destination) == 0 && strcmp(startPoint, p->startPoint) == 0 && p != pflight) {
            flag = 1;
            Display_flight_Infomation(p);
        }
        p = p->next;

    }
    printf("\n\n");

    //û����ͬ·�ߵĺ���
    if (flag == 0)
        return FALSE;
    return TRUE;
}


/**
 * @brief ��Ʊģ��
 */
void BookTickets()
{
    while(1)
    {
        struct Flight *info;
        int amount = 1, rank;
        int tickets; // ʣ�������Ʊ��Ŀ���߾���Ʊ��Ŀ
        char name[10];
        char identification[20];
        int success = 0;

        system("cls");

        while (1)
        {
            // ���ò��Һ��ຯ�������ظ� info
            info = find();
            if (info != NULL)
            {
                break;
            }
            printf("û���������, ����������\n");
        }

        printf("����ȷ��������Ʊ�Ĳ�λ�ȼ���1�����òգ�������������գ�:");
        scanf("%d", &rank);
        if (rank == 1)
        {
            tickets = info->leftEconomicTicket;
        } else
        {
            tickets = info->leftBusinessTicket;
        }

        while (1) {
            printf("����ȷ�����㶩Ʊ����Ҫ������:");
            scanf("%d", &amount);
            if (amount > 0) {
                break;
            }
            printf("������������Ϸ�������������\n");
        }

        if (amount <= tickets)
        {
            printf("��������������:");
            scanf("%s", name);
            printf("�������������֤����:");
            scanf("%s", identification);
            CusLinkList head = info->cusLinkList;
            // ��Ʊ�ɹ��������Ա��������
            insertlink(head, amount, name, identification, rank);
	        for (int i = 0; i < amount; i++) {
	            printf("%s ����λ����: %d\n", name, info->totalTickets - info->left + i + 1);
	        }
            info->left -= amount;


            if (rank == 1)
            {
                info->leftEconomicTicket -= amount;
            } else
            {
                info->leftBusinessTicket -= amount;
            }

            printf("\nף����;��죡��ӭ�ٴι���\n");
            success = 1;
        }
        else
        {
            printf("�õȼ���Ʊ���㣬��Ʊʧ�ܣ�����Ϊ�ú���˿���Ϣ, ϣ�������Ķ�Ʊ��������\n");
            FlightInfo(info);
        }

        while (!success)
        {
            printf("�Ƿ�ı䶩Ʊ�ƻ���Y/N\n");
            char r;
            getchar(); // ���������
            r = getchar();
            if (r == 'Y' || r == 'y')
            {
                // �ı�ƻ�������ѡ�񺽰�
                BookTickets();
                return;
            } else
            {
                printf("\n�Ѿ�û�и����Ʊ������Ҫ�ŶӵȺ���?(Y/N)\n");
                getchar(); // ���������
                r = getchar();
                if (r == 'Y' || r == 'y')
                {
                    // ���ı�ƻ����ŶӺ�Ʊ
                    printf("\n�����������������ŶӶ�Ʊ�ͻ���:");
                    scanf("%s", name);
                    printf("\n�������������֤���ŶӶ�Ʊ�ͻ���:");
                    scanf("%s", identification);
                    if (rank == 1)
                    {
                        // ���뾭�ò��ŶӶ���
                        info->waitQueue1 = Appendqueue(info->waitQueue1, name, amount, identification);
                    } else
                    {
                        // ����������ŶӶ���
                        info->waitQueue2 = Appendqueue(info->waitQueue2, name, amount, identification);
                    }
                    printf("\n�Ŷӳɹ�!\n");
                    success = 1;
                } else
                {
                    printf("\n��ѡ���Ŷӣ�ллʹ�ã�\n");
                    success = 1;
                }
            }
        }
        printf("�Ƿ������Ʊ��Y/N\n");
        char choice;
        cin>>choice;
        if(choice == 'N' || choice == 'n')
        {
            return;
        }
    }
}


/**
 * @param Q   QΪ�򲹶�Ʊ�ͻ��Ķ���
 * @param NameAndNumAndIDAndID �򲹿ͻ��������Ͷ�Ʊ��Ŀ������ʱ���������͹ؼ��ֺ����֤����
 * @return
 */
Status QueueDelete(LinkQueue &q, NameAndNumAndID &NameAndNumAndID)
{
    WaitQNode *p;
    p = q.front->next;
    //��ͷ����������frontָ���rearָ�����ʱ���൱�ڶ���Ϊ�գ�û��Ԫ�س���
    if (q.front == q.rear)
    {
        return ERROR;
    }
    //����
    q.front->next = p->next;
    //���ӵ���ʱ��rear = front
    if (q.front->next == NULL)
    {
        q.rear = q.front;
    }

    //���س���Ԫ�صĹؼ���Ϣ�������򲹿ͻ��������Ͷ�Ʊ��
    NameAndNumAndID.num = p->preTickets;
    strcpy(NameAndNumAndID.name, p->name);
    strcpy(NameAndNumAndID.identification, p->identification);
    free(p);

    return OK;
}


/**
 * @brief ��Ʊ����ģ��
 */
void ReturnTicket()
{
    struct Flight *info;
    int rank;
    CustomerNode *p1, *p2, *head;
    char cusname[10];
    char identification[20];
    system("cls");

    // ���Һ���
    while (1)
    {
        info = find();
        if (info != NULL)
        {
            break;
        }
        printf("û���������, ����������\n");
    }

    head = info->cusLinkList;
    p1 = head->next;
    printf("�������������: ");
    scanf("%s", cusname);
    printf("������������֤����: ");
    scanf("%s", identification);

    // �����ͻ��Ƿ�Ʊ
    p2 = head;
    while (p1 != NULL)
    {
        if ((strcmp(cusname, p1->name) == 0) && (strcmp(identification, p1->identification) == 0))
        {
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if (p1 == NULL)
    {
        printf("�Բ�����û�ж���Ʊ�����������֤����Ӧ\n");
        return;
    }
    else
    {
        // ��Ʊ�ɹ�
        rank = p1->rank;
        p2->next = p1->next;
        info->left += p1->clientTickets;
        if (rank == 1)
        {
            info->leftEconomicTicket += p1->clientTickets;
        }
        else
        {
            info->leftBusinessTicket += p1->clientTickets;
        }
        printf("%s  �ɹ���Ʊ��\n", p1->name);
        free(p1);
    }

    LinkQueue queue1 = info->waitQueue1;
    LinkQueue queue2 = info->waitQueue2;
    NameAndNumAndID nameAndNumAndID = {0, 0};

    if (rank == 1)
    {
        //cout<<"�о��ò���Ʊ��ѯ�ʾ��ò��ŶӵĿͻ�" <<endl;
        // �о��ò���Ʊ��ѯ�ʾ��ò��ŶӵĿͻ�
        while (queue1.front->next != NULL && queue1.front->next->preTickets <= info->leftEconomicTicket) {
            // �Ӻ򲹿ͻ������У����ӿͻ��������Ͷ�Ʊ����NameAndNumAndID����
            QueueDelete(info->waitQueue1, nameAndNumAndID);
            int y;
            printf("�о��ò�Ʊʣ�� , �𾴵�%s ��\n", nameAndNumAndID.name);
            printf("�Ƿ�ȷ�϶�Ʊ��1ȷ�϶�Ʊ�� �������־ܾ���Ʊ��\n");
            scanf("%d", &y);

            if (y == 1)
            {
                // �ŶӶ�Ʊ�ɹ�
                for (int i = 0; i < nameAndNumAndID.num; i++)
                {
                    printf("�ŶӶ�Ʊ�ɹ�  %s ����λ����:%d\n", nameAndNumAndID.name, (info->left) - i);
                }
                // ʣ��Ʊ����
                info->left -= nameAndNumAndID.num;
                info->leftEconomicTicket -= nameAndNumAndID.num;
                // ��Ա������������ŶӶ�Ʊ�ɹ��Ŀͻ�
                info->cusLinkList = insertlink(info->cusLinkList, nameAndNumAndID.num, nameAndNumAndID.name,
                                               nameAndNumAndID.identification, rank);
            }
        }
    }
    else
    {
        //cout<<"������տͻ���Ʊ��ѯ��������ŶӵĿͻ�" <<endl;
        // ������տͻ���Ʊ��ѯ��������ŶӵĿͻ�
        while (queue2.front->next != NULL && queue2.front->next->preTickets <= info->leftBusinessTicket)
        {
            // �Ӻ򲹿ͻ������У����ӿͻ��������Ͷ�Ʊ����NameAndNumAndID����
            QueueDelete(info->waitQueue2, nameAndNumAndID);
            int y;
            printf("�������Ʊʣ�� , �𾴵�%s ��\n", nameAndNumAndID.name);
            printf("�Ƿ�ȷ�϶�Ʊ��1ȷ�϶�Ʊ�� �������־ܾ���Ʊ��\n");
            scanf("%d", &y);

            if (y == 1)
            {
                // �ŶӶ�Ʊ�ɹ�
                for (int i = 0; i < nameAndNumAndID.num; i++) {
                    printf("�ŶӶ�Ʊ�ɹ�  %s ����λ����:%d\n", nameAndNumAndID.name, (info->left) - i);
                }
                // ʣ��Ʊ����
                info->left -= nameAndNumAndID.num;
                info->leftBusinessTicket -= nameAndNumAndID.num;
                // ��Ա������������ŶӶ�Ʊ�ɹ��Ŀͻ�
                info->cusLinkList = insertlink(info->cusLinkList, nameAndNumAndID.num, nameAndNumAndID.name,
                                               nameAndNumAndID.identification, rank);
            }
        }
    }
}


// ð�������������տͻ�������С��������
void bubbleSort_CusLinkList(CusLinkList head) {
    if (head == NULL || head->next == NULL) {
        return; // �������Ϊ�ջ���ֻ��ͷ�ڵ㣬����Ҫ����
    }

    CustomerNode *end = NULL; // ���ڱ���Ѿ��ź���Ĳ���

    while (end != head->next) { // ���ѭ���������������
        CustomerNode *prev = head; // ǰһ���ڵ�ָ�룬��ʼΪͷ�ڵ�
        CustomerNode *current = head->next; // ��ǰ�ڵ�ָ��
        CustomerNode *nextNode = current->next; // ��һ���ڵ�ָ��

        while (nextNode != end) { // �ڲ�ѭ������һ��������ð�ݹ���
            if (strcmp(current->name, nextNode->name) > 0) { // �Ƚϵ�ǰ�ڵ����һ���ڵ������
                // �����ڵ��λ��
                prev->next = nextNode;
                current->next = nextNode->next;
                nextNode->next = current;

                // ����ָ��
                CustomerNode *temp = current;
                current = nextNode;
                nextNode = temp;
            }

            // ����ָ�룬������һ�αȽ�
            prev = current;
            current = nextNode;
            nextNode = nextNode->next;
        }

        // �������ź���Ĳ���
        end = current;
    }
}


Status Visit_Passenger_Information(Flight *pflight)
{
    Flight *info = pflight->next;
    while (1)
    {
        // ���ò��Һ��ຯ�������ظ� info
        info = find();
        if (info != NULL)
        {
            break;
        }
        printf("û���������, ����������\n");
    }

    CusLinkList head = info->cusLinkList->next;
    bubbleSort_CusLinkList(head);

    printf("�ͻ�����\t�ͻ���Ʊ��\t���֤����\t����ID\t��λ�ȼ�\t��������\t���վ��\t�յ�վ��\n");
    while(head)
    {
        printf("%8s\t%8d\t%s\t%10s\t%6d\t   %11s\t   %9s\t     %8s\n", head->name, head->clientTickets, head->identification,
               info->flightCodeID, head->rank ,info->day ,info->startPoint,info->destination);
        head = head->next;
    }
    return OK;
}


/**
 * @brief �˳�����ģ�����
 */
void GoodbyeFace()
{
    system("cls");
    printf("\n");
    printf("\n");
    printf("             ---------------------------------------------\n");
    printf("             |            ��лʹ�ú��պ��ඩƱϵͳ        |\n");
    printf("             |                                           |\n");
    printf("             |                    GoodBye��               \n");
    printf("             --------------------------------------------\n");

}

