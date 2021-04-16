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
		_size[30];//для функций CUT,makeH1

	void constimput(int leaffanout, int dirfanout);

 public:
	void insert(int x, int y);//вставка ключа в дерево
	BV(int leaffanout,int dirfanout);
	~BV();

	void print_tree();//вывод
	bool search(int x, int y);//поиск по зачению
	bool del(int x, int y);//поиск по зачению

	class Node
	{
	public:
		static BV* master;
		int* _x, * _y;
		int _k ;//количество ключей в узле
		int _knodes;//количество указателей 

		int _leftx , _rightx , _lefty , _righty ;//границы значений 
		int _dlevel , _clevel ;
		Node* _guard;//??
		bool _isguard;
		bool _isroot;
		bool _isleaf;
		Node** _next;//дети
		Node* _past;//родитель

		Node();
		Node(Node* past);
		Node(char root);

		void sort();
		void insert(int x, int y);//вставка ключа в дерево
		void cut();
		void info();
		void p_info();
		void print();
		bool search(int x, int y);
		void setboards();
		void setboards_up();
		bool del(int x, int y);
		void cut_del();

	};
	void setboards_all();
	Node* _root;//корень
	
};

