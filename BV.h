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
		int* _x, * _y;
		int _k = 0;//���������� ������ � ����
		int _knodes = 0;//���������� ���������� 

		int _leftx = 1, _rightx = 0, _lefty = 1, _righty = 0;//������� �������� 
		int _dlevel = 0, _clevel = 0;
		Node* _guard;//??
		bool _isguard = false;
		bool _isroot;
		bool _isleaf;
		Node* _next;//����
		Node* _past;//��������

		Node();
		Node(int x, int y);//??
		Node(int* x, int* y);//??
		Node(Node* past);
		Node(char root);

		void sort();
		void insert(int x, int y);//������� ����� � ������
		void cut();
	};
	
	Node* _root;//������
};

