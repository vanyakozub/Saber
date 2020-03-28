#include "List.h"

int main()
{
	std::string path = "D:\\Saber\\ser.txt";
	//path = path.c_str();
	std::cout << path << std::endl;
	FILE* file;
	List l;
	l.Push_back("Hello");
	l.Push_back("world!");
	l.Push_back("I will");
	l.Push_back("work");
	l.Push_back("at Saber Interactive!");
	//l.Pop_front();
	//l.Pop_front();
	l.Set_rand_pointers();
#pragma warning(suppress : 4996)
	file = fopen(path.c_str(), "wb");
	
	l.Print();
	l.Serialize(file);
	fclose(file);
#pragma warning(suppress : 4996)
	file = fopen(path.c_str(), "rb");
	List p;
	p.Deserialize(file);
	p.Print();
	fclose(file);
}