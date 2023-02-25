#include "point.h"


void Point::set(int a, int b, int c) {
	x = a;
	y = b;
	z = c;
}
void Point::setIsMarked(bool bo)
{
	isMarked = bo;
}

bool Point::getIsMarked()
{
	return isMarked;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

int Point::getZ()
{
	return z;
}



string Point::toString() {
	{
		string s = "";
		string isMarkedS = "";
		if (isMarked)
		{
			isMarkedS = "marquer";
		}
		else {
			isMarkedS = "non marquer";
		}
		s += "Point-> ";
		s = s + "x : " + to_string(x) + " | y : " + to_string(y) + " | z : " + to_string(z) + " | isMarked : " + isMarkedS;

		return s;
	}
}