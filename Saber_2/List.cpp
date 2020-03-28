#include "List.h"

List::List()
{
	this->count = 0;
	this->head = new ListNode();
	this->tail = head;
	
}

List::~List()
{
	ListNode* tmp = head;
	while(tmp->next!= NULL)
	{
		tmp = tmp->next;
		delete tmp->prev;
	}
	delete tmp;
}

void List::Push_back(std::string value)
{
	
	if(count == 0)
	{
		head->data = value;
		head->next = NULL;
		head->prev = NULL;
		head->rand = NULL;
		count++;
		return;
	}
	ListNode* tmp = tail;
	tmp->next = new ListNode();
	tmp->next->prev = tmp;
	tmp->next->data = value; 	
	count++;
	tail = tmp->next;
	
}

std::string List::Pop_front()
{
	if (count > 0)
	{
		ListNode* tmp = head;
		tmp->next->prev = NULL;
		head = tmp->next;
		std::string data = tmp->data;
		delete tmp;
		count--;
		return  data;
	}
}

ListNode* List::Get_rand_node(int num)
{
	ListNode* tmp = head;
	for (int i = 0; i < num; i++)
	{
		tmp = tmp->next;
	}
	return tmp;
}

void List::Set_rand_pointers()
{
	ListNode* tmp = head;
	for (int i = 0; i < count; i++)
	{		
		tmp->rand = Get_rand_node(rand() % count);
		tmp = tmp->next;
	}
}

void List::Deserialize_rand_pointers(int* arr)
{
	ListNode* tmp = head;
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == -1)
			tmp->rand = NULL;
		else
		{
			tmp->rand = Get_rand_node(arr[i]);
		}
		tmp = tmp->next;
	}
}

int List::Get_num_by_node(ListNode* node)
{
	if (node == NULL)
	{
		return -1;
	}
	ListNode* tmp = head;
	for (int i = 0; i < count; i++)
	{
		if (tmp == node) {
			return i;
		}
		tmp = tmp->next;
	}
	return -1;
}

void List::Serialize(FILE* file)
{
	fwrite(&this->count, sizeof(int), 1, file);
	int num_of_rand = 0;
	ListNode* tmp = head;
	for(int i = 0; i < count; i++)
	{
		num_of_rand = Get_num_by_node(tmp->rand);
		int data_length = tmp->data.length();
		fwrite(&num_of_rand, sizeof(int), 1, file);
		fwrite(&data_length, sizeof(int), 1, file);
		fwrite(tmp->data.c_str(),sizeof(char), tmp->data.length(),file);
		tmp = tmp->next;	
	}
}

void List::Deserialize(FILE* file)
{
	int amount = 0;
	fread(&amount, sizeof(int), 1, file);
	int* rand = new int[amount];
	char* str;
	for (int i = 0; i < amount; i++)
	{
		int data_length;
		fread(&rand[i], sizeof(int), 1, file);
		fread(&data_length, sizeof(int), 1, file);
		str = new char[data_length];
		fread(str, sizeof(char), data_length, file);
		std::string cur(str);
		cur.resize(data_length);
		Push_back(cur);
	}
	Deserialize_rand_pointers(rand);
}

void List::Print()
{
	ListNode* tmp = head;
	while (tmp!=NULL)
	{
		std::cout << tmp->data << std::endl;
		if(tmp->rand!= NULL)
		std::cout << "Rand pointer is refers to node with data: "  << tmp->rand->data << std::endl;
		tmp = tmp->next;
	}	
}
