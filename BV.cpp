#include "BV.h"

int BV::_leaffanout;
int BV::_dirfanout;
int BV::_condleaf;
int BV::_conddir;
int BV::_size[30];
BV* BV::Node::master;


BV::BV(int leaffanout, int dirfanout)
{
	constimput( leaffanout,  dirfanout);
	_root = new Node('r');
	if (BV::Node::master==nullptr)
	{
		BV::Node::master = this;
	}
}

BV::~BV()
{

}

void BV::print_tree()
{
	cout << "___PRINT___" << endl << "______________________________" << endl;
	cout << " Master = " << _root << endl;
	_root->print();
}

void BV::setboards_all()
{
	cout << "___setboards_all___" << endl << "______________________________" << endl;
	_root->setboards();
}

bool BV::search(int x, int y)
{
	return _root->search(x, y);
}

bool BV::del(int x, int y)
{
	return _root->del(x, y);
}

void BV::constimput(int leaffanout, int dirfanout)
{
	_leaffanout = leaffanout;
	_dirfanout = dirfanout;
	_condleaf = _leaffanout / 3;
	_conddir = _dirfanout / 3;
	if (_condleaf * 3 != leaffanout) { _condleaf++; }
	if (_conddir * 3 != dirfanout) { _conddir++; }
	cout << " leaffanout = " << leaffanout << endl;
	cout << "  dirfanout = " << dirfanout << endl;
	cout << "   condleaf = " << _condleaf<<endl;
	cout << "    conddir = " << _conddir<<endl;
}

void BV::insert(int x, int y)
{
	//cout << "		   ROOT  " << _root << endl << "	 ROOT knodes " << _root->_knodes << endl << "	   	  ROOT k " << _root->_k << endl;
	_root->insert(x, y);
}


//
//void BV::insert(int x)
//{
//	cout << "\n INSERT ";
//	if (this)
//	{
//		if (((_k <_dirfanout)&&(_next!=nullptr))||((_k < _leaffanout) && (_next == nullptr))) 
//		{
//			int* data; data = new int[_k + 1];
//			if (x <= _data[0])
//			{
//				for (int i = _k; i > 0; i--)
//				{
//					data[i] = _data[i - 1];
//				}
//				data[0] = x;
//				if (_k + 1 <= _leaffanout)
//					_leftboard = x;
//			}
//			else if ((x > _data[0]) && (x < _data[_k - 1]))
//			{
//				//cout << "\nS2 ";
//				for (int i = 1; i < _k - 1; i++)
//				{
//					if ((x >= _data[i]) && (x <= _data[i + 1]))
//					{
//						for (int j = i + 1; j < _k; j++)
//						{
//							data[j + 1] = _data[j];
//						}
//						data[i + 1] = x;
//					}
//				}
//			}
//			else if (x >= _data[_k - 1])
//			{
//				for (int i = 0; i < _k; i++)
//				{
//					data[i] = _data[i];
//				}
//				data[_k] = x;
//				if (_k + 1 <= _leaffanout)
//					_rightboard = x;
//			}
//			_k++;	 delete(_data); _data = data;
//			if (_k > _leaffanout)
//			{
//				//соответствие условиям
//				cut();
//				makeH2();
//			}
//		}
//		else
//			if (_next != NULL)
//			{
//				//рекурсивная вставка по границам
//				if ((x <= _next[0]._leftboard))
//				{
//					(_next)->insert(x); return;
//				}
//				else if (x >= _next[_knodes - 1]._rightboard)
//				{
//					(_next + _knodes - 1)->insert(x); return;
//				}
//				else
//					for (int i = 1; i < _knodes - 1; i++)
//					{
//						if ((x > _next[i]._leftboard) && (x < _next[i + 1]._rightboard))
//						{
//							(_next + i)->insert(x); return;
//						}
//					}
//			}
//	}
//}
//
//










