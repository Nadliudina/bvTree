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
		if (_k <= _leaffanout)
		{
			return;
		}
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
			int center_x, center_y;		double li1,li2, l1,l2;
			center_x = (_next[0]._leftx + _next[0]._rightx) / 2;
			center_y = (_next[0]._lefty + _next[0]._righty) / 2;
			l1 = sqrt((_x[0] - center_x) ^ 2 + (_y[0] - center_y) ^ 2);
			li1 = sqrt((x - center_x) ^ 2 + (y - center_y) ^ 2);
			center_x = (_next[_knodes-1]._leftx + _next[_knodes - 1]._rightx) / 2;
			center_y = (_next[_knodes - 1]._lefty + _next[_knodes - 1]._righty) / 2;
			l2 = sqrt((_x[_knodes - 1] - center_x) ^ 2 + (_y[_knodes - 1] - center_y) ^ 2);
			li2 = sqrt((x - center_x) ^ 2 + (y - center_y) ^ 2);
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












BV::Node::Node(int x, int y)
{
}

BV::Node::Node(int *x, int *y)
{
}

BV::Node::Node(Node *past)
{
}
