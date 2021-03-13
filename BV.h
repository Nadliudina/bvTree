#pragma once
#include<stdlib.h>
#include<iostream>

using namespace std;

class BV {
private:
	static int
		_leaffanout,//максимальное количество ключей
		_dirfanout,//максимальное количество ключей
		_condleaf,//минимальное количество ключей
		_conddir,//минимальное количество ключей
		_size[30];//дл€ функций CUT,makeH1

	int _k;//количество ключей в узле
	int _knodes;//количество указателей 
	void constimput(int leaffanout, int dirfanout);


	void imput(int* x, int* y, int k);//ввод значений в узел
	void cut();//деление узла, переполненного ключами
	bool makeH1();//деление узла, переполненного указател€ми
	void makeH2();//деление узла, переполненного указател€ми

public:
	void insert(int x, int y);//вставка ключа в дерево
	BV(int leaffanout,int dirfanout);
	~BV();

	void print_tree();//вывод
	bool search(int x,int y);//поиск по зачению
	
	void makeH();//деление узла, переполненного указател€ми


	class Node
	{
	public:
		int* _x, * _y;
		int _k = 0;//количество ключей в узле
		int _knodes = 0;//количество указателей 

		int _leftx = 1, _rightx = 0, _lefty = 1, _righty = 0;//границы значений 
		int _dlevel = 0, _clevel = 0;
		Node* _guard;//??
		bool _isguard = false;
		bool _isroot;
		bool _isleaf;
		Node* _next;//дети
		Node* _past;//родитель

		Node();
		Node(int x, int y);//??
		Node(int* x, int* y);//??
		Node(Node* past);
		Node(char root);

		void sort();
		void insert(int x, int y);//вставка ключа в дерево
	};
	
	Node* _root;//корень
};

