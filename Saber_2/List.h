#ifndef LIST_H
#define List_H

#include <iostream>
#include <string>
struct ListNode {
    ListNode* prev;
    ListNode* next;
    ListNode* rand; // ��������� �� ������������ ������� ������� ������ ���� NULL
    std::string     data;
};
class List
{    
public:
    List();
    ~List();
    void Push_back(std::string value);
    std::string Pop_front();
    ListNode* Get_rand_node(int num);
    void Set_rand_pointers();
    void Deserialize_rand_pointers(int* arr);
    int Get_num_by_node(ListNode* node);
    void Serialize(FILE* file);  // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
    void Deserialize(FILE* file);  // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))
    void Print();
private:
    ListNode* head;
    ListNode* tail;
    int       count;
};

#endif

