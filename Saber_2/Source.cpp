#include "List.h"

int main()
{
	std::string path = "D:\\Saber\\ser.txt";
	FILE* file;
	List l;
	l.Push_back("Hello");
	l.Push_back("world!");
	l.Push_back("this is the");
	l.Push_back("task");
	l.Push_back("from Saber Interactive!");
	l.Set_rand_pointers();
	file = fopen(path.c_str(), "wb");
	std::cout << std::endl << "Before serialize: " << std::endl << std::endl;
	l.Print();
	l.Serialize(file);
	fclose(file);
	file = fopen(path.c_str(), "rb");
	List p;
	p.Deserialize(file);
	std::cout << std::endl << "After deserialize: " << std::endl << std::endl;
	p.Print();
	fclose(file);
}