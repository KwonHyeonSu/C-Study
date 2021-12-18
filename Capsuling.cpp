#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

};

class Circle
{
private:
	Point center;
	int radius;
public:
	void SetCircle(int x, int y, int r)
	{
		center.Init(x, y);
		radius = r;
	}
	void ShowCircle() const
	{
		cout << "radius : " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle Inner, Outer;
	
public:
	void Init(int inner_x, int inner_y, int inner_r, int outer_x, int outer_y, int outer_r)
	{
		Inner.SetCircle(inner_x, inner_y, inner_r);
		Outer.SetCircle(outer_x, outer_y, outer_r);
	}

	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		Inner.ShowCircle();

		cout << "Outter Circle Info..." << endl;
		Outer.ShowCircle();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
