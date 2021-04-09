#include "BV.h"

BV::Node::Node()
{
	_isroot = false; 
	_isleaf=false;
	_next = NULL; _past = NULL;
	_knodes = 0; _leftx = 0; _rightx = 0; _lefty = 0; _righty = 0, _k = 0;
	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
	_clevel = 0; _dlevel = 0;
}


BV::Node::Node(char root)
{
	_isroot = true;
	_isleaf = true;
	_next = NULL; _past = NULL;
	_knodes = 0; _leftx = 0; _rightx = 0; _lefty = 0; _righty = 0, _k = 0;
	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
	_clevel = 0; _dlevel = 0;
}

BV::Node::Node(Node* past)
{
	_isroot = false;
	_isleaf = false;
	_next = NULL; _past = past;
	_knodes = 0; _leftx = 0; _rightx = 0; _lefty = 0; _righty = 0, _k = 0;
	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
	_clevel = 0; _dlevel = 0;
}


void BV::Node::sort()
{
	cout << "sort\n";
	if (_k>0)
	{
		_leftx = _x[0];
		_rightx = _x[0];
		_lefty = _y[0];
		_righty = _y[0];
	}
	for (int i = 0; i < _k; i++)
	{
		if		 (_leftx > _x[i])
		{	_leftx = _x[i];	    }
		else if (_rightx < _x[i])
		{	_rightx = _x[i];	}
		if       (_lefty > _y[i])
		{	_lefty = _y[i];		}
		else if (_righty < _y[i])
		{	_righty = _y[i];	}
	}
	int center_x, center_y;
	center_x = (_leftx + _rightx) / 2;
	center_y = (_lefty + _righty) / 2;

	double l,l1 ;//!!!

	int c;
	for (int i = 0; i < _k; i++)
	{
		l = sqrt((_x[i] - center_x) ^ 2 + (_y[i] - center_y) ^ 2);
		for (int j = 0; j < _k; j++)
		{
			l1 = sqrt((_x[j] - center_x) ^ 2 + (_y[j] - center_y) ^ 2);
			if ((l < l1) || ((l == l1) && ((_x[i] < _x[j]) || ((_x[i] == _x[j]) && (_y[i] < _y[j])))))
			{
				c = _x[i];
				_x[i] = _x[j];
				_x[j] = c;

				c = _y[i];
				_y[i] = _y[j];
				_y[j] = c;
			}
		}
	}
	//for (int i = 0; i < _k; i++)
	//	cout << " " << _x[i] << ":" << _y[i];
	//cout << endl;
}

void BV::Node::insert(int x, int y)
{
	if (_isleaf == true)
	{
		cout << "insert " << x << " " << y << endl;
		int* newx = new int[_k + 1] {0};
		int* newy = new int[_k + 1]{ 0 };
		for (int i = 0; i < _k; i++)
		{
			newx[i] = _x[i];
			newy[i] = _y[i];
		}
		newx[_k] = x;
		if(_x!=nullptr)
		delete[] _x;
		_x = newx;
		newy[_k] = y;
		if (_y != nullptr)
		delete[] _y;
		_y = newy;
		sort();
		_k++;
		if (_k==1)
		{
			_leftx = x; _rightx = x; _lefty = y; _righty = y;
		}
		else 
		{
			if (_leftx > x)
				_leftx = x;
			if (_rightx < x)
				_rightx = x;
			if (_lefty > y)
				_lefty = y;
			if (_righty < y)
				_righty = y;
		}
		if (_k <= _leaffanout)
		{	return; }
		else
		{
		//	cout << " MNOGA k= " << _k<<"| "<<x << " " << y << endl;
			cut();//!!!
		}
	}
	else
	{
		if (_knodes==0)
		{
			cout << "AHTUNG!!!" << endl; cout << "AHTUNG!!!" << endl; 
			cout << "AHTUNG!!!" << endl; cout << "AHTUNG!!!" << endl;
		}
		bool ok = false;
		for (int i = 0; i < _knodes; i++)
		{
		//	cout << "I = " << i << endl;
		//	cout << " |" << _next[i]->_isleaf << " |" << _next[i]->_isguard << " |" << _next[i]->_isroot <<"| |"<<_next[i] <<endl;
		//	cout << "	_next[i]->_knodes    " << _next[i]->_knodes << endl;
		//	cout << "	_next[i]->_k    " << _next[i]->_k << endl;
		//	_next[i]->_rightx * 7;
		//	cout << "	_next[i]->_rightx &7 " << _next[i]->_rightx << endl;
			if ((x < _next[i]->_rightx) && (x > _next[i]->_leftx)&& (y < _next[i]->_righty) && (y > _next[i]->_lefty))
			{
				_next[i]->insert(x, y); 
				ok = true; break;
			}
		}
		if (ok==false)
		{

			double center_x, center_y;		double li1,li2;
			center_x = ((double)_next[0]->_leftx + (double)_next[0]->_rightx) / 2;
			center_y = ((double)_next[0]->_lefty + (double)_next[0]->_righty) / 2;
		//	l1 = sqrt(pow((double)_x[0] - center_x,2.0) + pow((double)_y[0] - center_y,2.0));//!!!
			li1 = sqrt(pow((double)x - center_x,2.0) + pow((double)y - center_y,2.0));
			center_x = ((double)_next[_knodes-1]->_leftx + (double)_next[_knodes - 1]->_rightx) / 2;
			center_y = ((double)_next[_knodes - 1]->_lefty + (double)_next[_knodes - 1]->_righty) / 2;
		//	l2 = sqrt(pow((double)_x[_knodes - 1] - center_x, 2.0)  + pow((double)_y[_knodes - 1] - center_y, 2.0) );
			li2 = sqrt(pow((double)x - center_x, 2.0) + pow((double)y - center_y, 2.0) );
			if (abs(li1 ) <= abs(li2 ))//	if (abs(li1 - l1) <= abs(li2 - l2))
			{
				_next[0]->insert(x, y); 
			}
			else
			{
				_next[_knodes - 1]->insert(x, y);
			}
		}
	}
}

void BV::Node::cut()//new_next parts new_knodes
{
	int new_knodes,new_k ;
	Node* parts,  **new_next;
	if (_isleaf == true)
	{
		if (_k <= _leaffanout)
			return; 	cout << "CUT_1" << endl;
		new_knodes = _k / _condleaf;
		if (_isroot==true)
		{
			_past = new Node();
			_past->_isroot = true;
			_isroot = false;
			_past->_knodes = 1;
			_past->_next = new Node*[1];
			_past->_next[0] = this;//??
			master->_root = _past;
 
		}
		
	
		parts = new Node[new_knodes];
		new_k = _k / new_knodes;
		
		for (int i = 0; i < new_knodes; i++)
		{
			parts[i]._past = _past;
			parts[i]._k = new_k;
			
		}
	//	cout << "new_knodes " << new_knodes << endl; cout << "k " << _k << endl; cout << "new_k" << new_k << endl;
		for (int i = 0; new_k * new_knodes + i < _k; i++)
		{
			parts[i]._k++; cout << "++" << endl;
		}
		cout << "_past->_knodes                  " << _past->_knodes << endl;
		cout << "_past->_knodes - 1 + new_knodes " << _past->_knodes - 1 + new_knodes << endl;
		new_next = new Node*[_past->_knodes - 1 + new_knodes];//дочерние узлы
		int ii,ii1;
		for (ii = 0;_past->_next[ii]!=this ; ii++)
		{
			new_next[ii] = _past->_next[ii];
			cout << ii <<"______"<< endl;
		}
		ii1 = ii;
		for (int i = 0; i < new_knodes; i++,ii++)
		{
			new_next[ii] = &parts[i];
		}
		for (int i = ii1; i< _past->_knodes; i++, ii++)
		{
			new_next[ii] = _past->_next[i];//??			cout << i << "_ ";
		}
		ii = 0;
		int temp;
		for (int i = 0; i < new_knodes; i++)
		{
			parts[i]._isleaf = true;
			temp= parts[i]._k; parts[i]._k=0;
			for (int j = 0; j <temp; j++)
			{
				parts[i].insert(_x[j + ii], _y[j + ii]);
			}
			ii += parts[i]._k;
		}
		delete _past->_next;
		_past->_next = new Node * [new_knodes + _past->_knodes - 1];
		for (int i = 0; i < new_knodes+_past->_knodes-1; i++)
		{
			_past->_next[i] = new_next[i];
		}
		_past->_knodes +=  - 1 + new_knodes;
				
		_past->cut();
//		delete this;
	}
	else
	{
		if (_knodes <= _dirfanout)
			return;  	cout << "CUT_2" << endl;
		if (_isroot == true)
		{
			_past = new Node();
			_past->_isroot = true;
			_isroot = false;
			_past->_knodes = 1;
			_past->_next = new Node * [1];
			_past->_next[0] = this;
			master->_root = _past;
		}
		new_knodes = _knodes / _conddir;//this распадается на new_knodes
	
		parts = new Node[new_knodes];
		new_k = _knodes/new_knodes;
		while (new_k * _conddir < _knodes/new_k)
			new_k++;
		for (int i = 0; i < new_knodes; i++)
		{
			parts[i]._past = _past;
			parts[i]._knodes = new_k;
		}
		cout << " new_k * new_knodes = " << new_k << " * " << new_knodes << " = " << new_k * new_knodes << endl;
		for (int i = 0; new_k * new_knodes + i < _knodes; i++)
		{
			parts[i]._knodes++; cout << i << "_ ";
			if (i>=new_knodes)
			{
				cout << " ALARM ";
			}
		}cout << endl;

		new_next = new Node*[_past->_knodes - 1 + new_knodes];//дочерние узлы
		int ii,ii1;
		for (int i = 0; i < _past->_knodes; i++)
		{
			cout <<"XXX "<< _past->_next[i] << endl;
		}
		for (ii = 0; _past->_next[ii] != this; ii++)
		{
			new_next[ii] = _past->_next[ii]; cout << ii << " _ii_ ";
		}
		ii1 = ii;
		for (int i = 0; i < new_knodes; i++,ii++)
		{
			new_next[ii] = &parts[i];
		}
		for (int i = ii1; i < _past->_knodes; i++, ii++)
		{
			new_next[ii] = _past->_next[i];
		}
		ii = 0;

		for (int i = 0; i < new_knodes; i++)///////////////////////////////////////////////////////
		{
			parts[i]._next = new Node * [parts[i]._knodes];
			for (int j = 0; j < parts[i]._knodes; j++)
			{
				parts[i]._next[j] = _next[ ii ];//!!!
				_next[ii]->_past = &parts[i];
				ii++;
			}
		}
		delete _past->_next;
		_past->_next = new Node * [new_knodes + _past->_knodes - 1];
		for (int i = 0; i < new_knodes + _past->_knodes - 1; i++)
		{
			_past->_next[i] = new_next[i];
		}
		_past->_knodes += - 1 + new_knodes;
		_past->cut();
	//	delete this;
		///////
	}
}

void BV::Node::info()
{
	cout <<endl<<"___INFO___"<<endl<< "_isroot = " << _isroot << endl
		<<	"_isleaf = " << _isleaf << endl
		<<  "   This = " << this << endl
	//	<<  "  _next = " << _next << endl
		<<  "  _past = " << _past << endl
		<<  " Master = " << master->_root << endl
		<<  "_knodes = " << _knodes << endl
		<<	"     _k = " << _k << endl;

}




