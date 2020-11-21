#include <iostream>

using namespace std;


//cau truc du lieu cho 1 diem
struct Point
{
	int x;
	int y;
};


//thuat toan counterclockwise
//=0 thang hang
//<0 nguoc chieu kiem dong ho
//>0 chieu kim dong ho

int CWW(Point a, Point b, Point c)
{
	int val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

	if (val == 0)
	{
		return 0;
	}
	cout << val << endl;
	return (val > 0) ? 1 : 2;
}


bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && 
		q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && 
		q.y >= min(p.y, r.y))
	{
		return true;
	}

	return false;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = CWW(p1, q1, p2);
	int o2 = CWW(p1, q1, q2);
	int o3 = CWW(p2, q2, p1);
	int o4 = CWW(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
	{
		return true;
	}

	if (o1 == 0 && onSegment(p1, p2, q1))
	{
		return true;
	}

	if (o2 == 0 && onSegment(p1, q2, q1))
	{
		return true;
	}

	if (o3 == 0 && onSegment(p2, p1, q2))
	{
		return true;
	}

	if (o4 == 0 && onSegment(p2, q1, q2))
	{
		return true;
	}

	return false;
}

void main()
{
	Point p1;
	Point q1;
	Point p2;
	Point q2;

	p1.x = 1; p1.y = 1;
	q1.x = 2; q1.y = 3;
	p2.x = 3; p2.y = 2;
	q2.x = 4; q2.y = 2;

	int test = CWW(q1, p2, p1);

	cout << "test: "<<test << endl;

	bool b = doIntersect(p1, q1, p2, q2);

	if (b == true)
	{
		cout << "co cat nhau" << endl;
	}
	else
	{
		cout << "ko cat nhau" << endl;
	}
}