#include"BV.h"

int main() {
	setlocale(LC_ALL, "Russian");
	
	//int m1[1000];	int m2[1000];
	int x = 100;
	BV a1(7, 4);
	for (int i = 0; i < x; i++)
	{
	//	m1[i] = i + 1; m2[i] = -i + x;
	}
	for (int i = 0; i < 10; i++)
	{
		a1.insert(i, -i);
	}
	//a1._root->makeH();
	a1.print_tree();
	cout << endl;
	int count = 0;
	//for (int i = 0; i < x; i++)
	//{
	//	if (a1.search(m1[i],m2[i]) )
	//	{
	//		count++;
	//	}
	//}
	cout << "\n C = " << count;
	return 0;
}




