#include "BV.h"

int BV::_leaffanout;
int BV::_dirfanout;
int BV::_condleaf;
int BV::_conddir;
int BV::_size[30];



BV::BV(int leaffanout, int dirfanout)
{
	constimput( leaffanout,  dirfanout);
	_root = new Node('r');

//	_next = NULL; _past = NULL;
//	_knodes = -1; _leftx = -1; _rightx = -1; _lefty = -1; _righty = -1, _k = 0;
//	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
//	_clevel = 0; _dlevel = 0;
}



BV::~BV()
{

}


void BV::imput(int* x,int *y, int k)
{
	//cout << "\n IMPUT " << this << " _k = " << k;
	//if (k < 1)
	//{
	//	//		return;//??
	//}
	//_k = k;
	//if (_x == nullptr)
	//{
	//	cout << "\nx==NULL " << _x;
	//	_x = new int[_k]; _y = new int[_k];
	//}
	//else
	//{
	//	cout << "\nx!=NULL " << _x[0];
	//		delete[] _x;
	//		delete[] _y;
	//		_x = new int[_k];	_y = new int[_k];
	//}
	//for (int i = 0; i < _k; i++)
	//{
	//	_x[i] = *(x + i);
	//	_y[i] = *(y + i);
	//}
	//sort();
	//// TYT 
	//cut();
	//_leftx = _x[0]; _rightx = _x[_k - 1];
	//_lefty = _y[0]; _righty = _y[_k - 1];//??
}

void  BV::cut()
{
	//cout << "\n CUT   " << this << " _k = " << _k;
	//if ((_k > _leaffanout) && (_knodes <= 1))// ?
	//{
	//	int newd = _dirfanout;
	//	while ((_k - newd) / (newd + 1) < _condleaf)
	//	{
	//		newd--;
	//	}
	//	if (newd < _conddir)
	//	{
	//		newd = _conddir;
	//	}
	//	int size[30];
	//	for (int i = 0; i < 30; i++)
	//	{
	//		size[i] = -1;//размеры массивов ключей
	//	}

	//	_knodes = newd + 1;
	//	cout << "\n _knodes =" << _knodes;
	//	int newl = (_k - _knodes + 1) / (_knodes);
	//	while (newl < _condleaf)
	//	{
	//		_knodes--;
	//		newl = (_k - _knodes + 1) / (_knodes);
	//	}		cout << "\n _new knodes =" << _knodes << " newl=" << newl;
	//	for (int i = 0; i < _knodes; i++)
	//	{
	//		size[i] = newl;
	//	}
	//	if (newl * _knodes != (_k - newd))//!!!!  (newd + 1)
	//	{
	//		for (int i = 0; i < (_k - newd) - (newl * _knodes); i++)//!!!!  (newd + 1)
	//		{
	//			size[i]  ++;
	//		}
	//	}
	//	cout << "\nnewd= " << newd;
	//	for (int i = 0; i < _knodes; i++)
	//	{
	//		cout << "\nsize[" << i << "]= " << size[i];
	//	}cout << endl << "__________" << this<<endl;

	//	int siz = 0;
	//	int* thisdirdatex = new int[newd];
	//	int* thisdirdatey= new int[newd];
	//	
	//	int temp;
	//	if ((_past->_knodes == 1) || (_past->_knodes == -1))//_knodes !!!!!!!!????
	//	{
	//		BV* next;
	//		next = new BV[_knodes]; int ii = 0;
	//		for (ii = 0; (ii < _knodes) ; ii++)//&& (size[ii] != -1)
	//		{
	//			next[ii]._past = _past;//?? this 
	//			cout << "\ninitiator " << this << " _knodes=" << _knodes;
	//			for (int j = 0; j < _knodes; j++)
	//			{
	//				cout << endl << " cutsize[" << j << "]" << size[j];
	//			}
	//			cout << endl << " Xsize[" << ii << "]" << size[ii];
	//			temp = size[ii];
	//			next[ii].imput(_x + siz, _y + siz, temp); siz += size[ii];
	//			thisdirdatex[ii] = _x[siz];	thisdirdatey[ii] = _y[siz];	siz++;
	//		} //cout << "\nsiz " << siz << " newd = " << newd;

	//		while (siz < _k - 1)//!!??
	//		{
	//			thisdirdatex[ii] = _x[siz];// cout << "\thisdirdate[" <<ii<<"] ="<< thisdirdate[ii]; 
	//			thisdirdatey[ii] = _y[siz];
	//			ii++; siz++;
	//			//	cout << "\nsiz++ " << siz;
	//		}

	//		delete[]_x;
	//		delete[]_y;
	//		_x = new int[newd];
	//		_y = new int[newd];
	//		for (int i = 0; i < newd; i++)
	//		{
	//			_x[i] = thisdirdatex[i];
	//			_y[i] = thisdirdatey[i];
	//		}
	//		_k = newd;
	//		//_past->_knodes = _knodes;//!!!!!!!!!!!
	//		/*_past->_next = next;*/
	//		this->_next = next;
	//	}
	//	else
	//	{
	//		cout << "\nelse\nelse\nelse\nelse";
	//		////узел не один в массиве _next
	//		//BV* next1;
	//		//cout << "\n_past->_knodes " << _past->_knodes;
	//		//_past->_knodes += _knodes - 1;
	//		//cout << "\n_past->_knodes " << _past->_knodes;
	//		//next1 = new BV[_past->_knodes];

	//		//for (int i = 0; i < _past->_knodes; i++)
	//		//{
	//		//	next1[i]._past = _past;
	//		//}
	//		//int e = 0;
	//		//while (&_past->_next[e] != this)
	//		//{
	//		//	e++;
	//		//}
	//		//for (int i = 0; i < e; i++)
	//		//{
	//		//	next1[i].imput(_past->_next[i]._data, _past->_next[i]._k);
	//		//	_past->_next[i].~BV();
	//		//}
	//		//siz = 0;
	//		//for (int i = e; i < e + _knodes; i++)
	//		//{
	//		//	next1[i].imput(_data + siz, size[i - e]); siz += size[i - e];
	//		//}
	//		//for (int i = e + _knodes; i < _past->_knodes; i++)//создание отдельных узлов
	//		//{
	//		//	next1[i].imput(_past->_next[i]._data, _past->_next[i]._k);
	//		//	_past->_next[i].~BV();
	//		//}
	//		//_past->_next = next1;
	//		//_past->_leftboard = _past->_next[0]._data[0];
	//		//_past->_rightboard = _past->_next[_past->_knodes - 1]._data[_past->_next[_past->_knodes - 1]._k - 1];
	//	}

	////	//	_past->_k = 0;
	////	//	this->~BV();
	//}

	//else
	//{
	//	cout << "\n else " << " _knodes= " << _knodes;
	//	if ((_k > _dirfanout) && (_knodes > 1))
	//	{
	//		cout << "\n cut 2 ";
	//	}
	//}
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

