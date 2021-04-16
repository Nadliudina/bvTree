#include"BV.h"

#define x 212

int main() {
	setlocale(LC_ALL, "Russian");

	BV a1(7, 4);
	int mx[x], my[x];
	for (int i = 0; i < x; i++)
	{
		mx[i] = rand() % 100;
		my[i] = rand() % 100;
		
		a1.insert(mx[i], my[i]);
	}

	a1.setboards_all();
	
	cout << endl;
	int count = 0;
	for (int i = 0; i < x; i++)
	{
//		a1.del(mx[i], my[i]);
	}	
	a1.setboards_all();
	for (int i = 0; i < x; i++)
	{
		if (a1.search(mx[i], my[i]))
		{
			count++;
			cout << mx[i] << " " << my[i] << " OK "<< endl;
		}
		else
		{
			cout << mx[i] << " " << my[i] << " __ " << endl;
		}
	}
	a1.print_tree();
	cout << "\n SEARCH = " << count;
	return 0;
}




