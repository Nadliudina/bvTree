#include"BV.h"

int main() {
	setlocale(LC_ALL, "Russian");
	

	int x = 100;
	BV a1(7, 4);
	
	for (int i = 0; i < 155; i++)
	{
		a1.insert(i, i);
	}

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




