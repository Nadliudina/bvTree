#pragma once
#include<stdlib.h>
#include<iostream>

using namespace std;

class BV {
private:
	static int
		_leaffanout,//������������ ���������� ������
		_dirfanout,//������������ ���������� ������
		_condleaf,//����������� ���������� ������
		_conddir,//����������� ���������� ������
		_size[30];//��� ������� CUT,makeH1

//	int _k;//���������� ������ � ����
//	int _knodes;//���������� ���������� 
	void constimput(int leaffanout, int dirfanout);


	void cut();//������� ����, �������������� �������


public:
	void insert(int x, int y);//������� ����� � ������
	BV(int leaffanout,int dirfanout);
	~BV();

	void print_tree();//�����
	bool search(int x,int y);//����� �� �������
	
	void makeH();//������� ����, �������������� �����������


	class Node
	{
	public:
		static BV* master;
		int* _x, * _y;
		int _k ;//���������� ������ � ����
		int _knodes;//���������� ���������� 

		int _leftx , _rightx , _lefty , _righty ;//������� �������� 
		int _dlevel , _clevel ;
		Node* _guard;//??
		bool _isguard;
		bool _isroot;
		bool _isleaf;
		Node** _next;//����
		Node* _past;//��������

		Node();

		Node(Node* past);
		Node(char root);

		void sort();
		void insert(int x, int y);//������� ����� � ������
		void cut();
		void info();
		void p_info();
		void print();
		////////////////////////
		static int costil[1000];
		static int costil_count;


	};
	
	Node* _root;//������
	
};

