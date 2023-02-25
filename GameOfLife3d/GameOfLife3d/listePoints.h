#pragma once
#include "point.h"
#include <vector>
#include <string>
using namespace std;
class ListePoints
{
	private:
		vector<Point> ps;
		int taille;
	public:
		ListePoints();
		void addPoint(Point p);
		Point getPointByCoord(int x, int y, int z);
		int getTaille();
		Point getPointById(int ind);
		void setMarkedByCoord(int a, int b, int c);
		void setNoMarkedByCoord(int a, int b, int c);
		string toString();
		void clear();
};

