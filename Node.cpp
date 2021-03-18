#include "BV.h"

BV::Node::Node()
{
	_isroot = false; 
	_isleaf=false;
	_next = NULL; _past = NULL;
	_knodes = -1; _leftx = -1; _rightx = -1; _lefty = -1; _righty = -1, _k = 0;
	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
	_clevel = 0; _dlevel = 0;
}


BV::Node::Node(char root)
{
	_isroot = true;
	_isleaf = true;
	_next = NULL; _past = NULL;
	_knodes = -1; _leftx = -1; _rightx = -1; _lefty = -1; _righty = -1, _k = 0;
	_x = nullptr, _y = nullptr; _guard = nullptr; _isguard = NULL;
	_clevel = 0; _dlevel = 0;
}

void BV::Node::sort()
{
	cout << "\nsort";
	_leftx = _x[0];
	_rightx = _x[0];
	_lefty = _y[0];
	_righty = _y[0];

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
	for (int i = 0; i < _k; i++)
	{
		cout << " " << _x[i] << ":" << _y[i];
	}
}

void BV::Node::insert(int x, int y)
{
	if (_isleaf == true)
	{
		cout << "insert " << x << " " << y << endl;
		int* newx = new int[_k + 1];
		int* newy = new int[_k + 1];
		for (int i = 0; i < _k; i++)
		{
			newx[i] = _x[i];
			newy[i] = _y[i];
		}
		newx[_k] = x;
		delete _x;
		_x = newx;
		newy[_k] = y;
		delete _y;
		_y = newy;
		sort();
		_k++;
		if (_k==1)
		{
			_leftx = x; _rightx = x; _lefty = y; _righty = y;
		}
		else //??
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
			cout << " MNOGA k= " << _k<<"| "<<x << " " << y << endl;
		//	cut();//!!!
		}
	}
	else
	{
		bool ok = false;
		for (int i = 0; i < _knodes; i++)
		{
			if ((x < _next[i]._rightx) && (x > _next[i]._leftx)&& (y < _next[i]._righty) && (y > _next[i]._lefty))
			{
				_next[i].insert(x, y); ok = true; break;
			}
		}
		if (ok==false)
		{
			double center_x, center_y;		double li1,li2, l1,l2;
			center_x = ((double)_next[0]._leftx + (double)_next[0]._rightx) / 2;
			center_y = ((double)_next[0]._lefty + (double)_next[0]._righty) / 2;
			l1 = sqrt(pow((double)_x[0] - center_x,2.0) + pow((double)_y[0] - center_y,2.0));
			li1 = sqrt(pow((double)x - center_x,2.0) + pow((double)y - center_y,2.0));
			center_x = ((double)_next[_knodes-1]._leftx + (double)_next[_knodes - 1]._rightx) / 2;
			center_y = ((double)_next[_knodes - 1]._lefty + (double)_next[_knodes - 1]._righty) / 2;
			l2 = sqrt(pow((double)_x[_knodes - 1] - center_x, 2.0)  + pow((double)_y[_knodes - 1] - center_y, 2.0) );
			li2 = sqrt(pow((double)x - center_x, 2.0) + pow((double)y - center_y, 2.0) );
			if (abs(li1-l1)<=abs(li2-l2))
			{
				_next[0].insert(x, y); 
			}
			else
			{
				_next[_knodes - 1].insert(x, y);
			}
		}
	}
}

void BV::Node::cut()
{
	int new_knodes ;
	Node* parts;

	if (_isleaf == true)
	{
		if (_isroot==true)
		{
			//!!!
		}
		new_knodes = _k / _condleaf;
		parts = new Node[new_knodes];
		int new_k = _k / _condleaf;
		for (int i = 0; i < new_knodes; i++)
		{
			parts[i]._past = _past;
			parts[i]._k = new_k;
		}
		for (int i = 0; new_k * _condleaf + i < _k; i++)
		{
			parts[i]._k++;
		}
		Node* newpast = new Node[_past->_knodes - 1 + new_knodes];
		int ii;
		for (ii = 0;&_past->_next[ii]!=this ; ii++)//ii<_knodes
		{
			newpast[ii] = _past->_next[ii];
		}
		for (int i = 0; i < new_knodes; i++)
		{
			newpast[ii + i] = parts[i];
		}
		for (int i = ii+new_knodes; i < _past->_knodes+new_knodes; i++)
		{
			newpast[i] = _past->_next[i-new_knodes];//??
		}
		
		for (int i = 0; i < new_knodes; i++)
		{
			for (int j = 0,ii = 0; j < parts[i]._k; j++,ii++)
			{
				parts[i]._x[j] = _x[ii];
				parts[i]._y[j] = _y[ii];
			}
		}
		_past->cut();
		delete this;
	}
	else
	{
		if (_isroot == true)
		{
			//!!!
		}
		new_knodes = _knodes / _conddir;
		parts = new Node[new_knodes];
		int new_k = _k / _conddir;
		for (int i = 0; i < new_knodes; i++)
		{
			parts[i]._past = _past;
			parts[i]._knodes = new_k;
		}
		for (int i = 0; new_k * _conddir + i < _knodes; i++)
		{
			parts[i]._knodes++;
		}
	}
}












BV::Node::Node(int x, int y)
{
}

BV::Node::Node(int *x, int *y)
{
}

BV::Node::Node(Node *past)
{
}
