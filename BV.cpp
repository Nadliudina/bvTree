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
//	_next = NULL; _past = NULL;
//	_knodes = -1; _leftx = -1; _rightx = -1; _lefty = -1; _righty = -1, _k = 0;
//	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
//	_clevel = 0; _dlevel = 0;
}



BV::~BV()
{

}



void BV::print_tree()
{
	//cout << "\n\nPRINT_!________";
	//if (this)
	//{
	//	cout << "\n_knodes     " << _knodes;
	//	cout << "\n adr        " << this;
	//	cout << "\n past       " << _past;
	//	cout << "\n next       " << _next;
	//	for (int j = 0; j < _k; j++)
	//	{
	//		cout << "\n |x= " << _x[j];
	//		cout << "\n |y= " << _y[j] << endl;
	//	}
	//	cout << "\n___________________";

	//	if (_next != NULL)
	//		for (int i = 0; i < _knodes; i++)
	//		{
	//			{
	//				cout << "\nnext " << i << ": ";
	//				cout << "\nnext_k     " << _next[i]._k;
	//			}
	//			(_next + i)->print_tree();
	//		}
	//}
}

bool BV::search(int x, int y)
{
	////рекурсивный поиск
	//if (this)
	//{
	//	//cout << "\n_knodes     " << _knodes;
	//	//cout << "\n adr        " << this;
	//	//cout << "\n past       " << _past;
	//	//cout << "\n next       " << _next;
	//	for (int i = 0; i < _k; i++)
	//	{
	//		if ((x == _x[i]) && (y == _y[i]))
	//		{
	//			cout << "\n success search " << x << ":" << y;
	//			return true;
	//		}
	//	}
	//	if (_next != NULL)
	//	{
	//		for (int i = 0; i < _knodes; i++)//_knodes
	//		{

	//			if ((x < _x[i]))
	//			{
	//				//	if ((_next + i)->search(x)) { return true; }
	//			}

	//			if ((_next + i)->search(x, y)) { return true; }
	//		}
	//	/*	if ((x > _data[_knodes])&& (_next + _knodes - 1)->search(x, y))
	//		{
	//			 return true; 
	//		}*/
	//	}
	//}
	//{
	//	//cout << "\n unsuccess search " << x;
	//	return false;
	//}

	return false;
}





//void BV::makeH()
//{
//	bool f;
//	do
//	{
//		f = makeH1();
//	} while (f);
//}
//
//bool BV::makeH1()
//{
//	system("pause");
//	//аналогично cut при переполнении узла указателями делит его
//	if (this)
//		if (_knodes > _dirfanout)
//		{
//			cout << "\n _knodes>_dirfanout " << _knodes << "<" << _dirfanout;
//			for (int i = 0; i < 30; i++)
//			{
//				_size[i] = -1;
//			}
//			int nextd, knodes;
//			nextd = _knodes / _dirfanout; knodes = 1;
//			if (nextd * _dirfanout < _knodes)
//			{
//				nextd++;
//			}
//			while (knodes * nextd <= _knodes)
//			{
//				knodes++;
//			}knodes--;
//
//			_size[nextd] = -nextd * knodes + _knodes;//остаток
//			cout << "\n остаток " << _size[nextd];
//
//			for (int i = 0; i < nextd; i++)
//			{
//				_size[i] = knodes;
//			}
//			for (int i = 0; i < _size[nextd]; i++)
//			{
//				_size[i]++;
//			}
//
//			BV* next;
//			int siz = 0;
//			next = new BV[nextd];
//			for (int i = 0; i < nextd; i++)
//			{
//				next[i]._past = this;
//				next[i]._next = &_next[siz];
//				next[i]._knodes = _size[i];
//				for (int j = 0; j < _size[i]; j++)
//				{
//					next[i]._next[j] = _next[siz];
//					next[i]._next[j]._past = &next[i];
//					siz++;
//				}
//			}
//			next->_past->_knodes = nextd;
//			_next = next;
//			for (int i = 0; i < _knodes; i++)
//			{
//	//			_next[i]._leftboard = _next[i]._next->_leftboard;
//		//		_next[i]._rightboard = _next[i]._next[_next[i]._knodes - 1]._rightboard;
//			}
//			return true;//были созданы узлы
//		}
//
//	return false;//не были созданы узлы
//}
//
//void BV::makeH2()
//{
//	bool f;
//	do
//	{
//		f = _past->makeH1();
//	} while (f);
//	if (_past)
//		_past->makeH2();
//}

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
	//BV::Node::master->_root->insert(x, y);
	cout << "		   ROOT  " << _root << endl;
	cout << "	 ROOT knodes " << _root->_knodes << endl;
	cout << "	   	  ROOT k " << _root->_k << endl;
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










