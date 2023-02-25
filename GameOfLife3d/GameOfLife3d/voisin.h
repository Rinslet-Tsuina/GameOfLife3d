#pragma once
#include <string>
#include <vector>
#include "point.h"
#include "listePoints.h"
#include <iostream>
using namespace std;
class Voisin
{
private:
	vector<Point> v;
	Point pbase;
	int idPoint;
public:
	Point getPbase();
	int getTaille();
	void addVoisin(Point p);
	Point getVoisinById(int i);
	Point getVoisinByCoord(int a,int b,int c);
	bool isVoisinExist(int a, int b, int c);
	void setVoisins(int baX, int baY, int baZ);
	void setVoisins(int minX, int minY, int minZ,int maxX, int maxY, int maxZ);
	void setPbase(Point p);
	void setIdPoint(int idP);
	void setMarkedByCoord(int a, int b, int c);
	string toString();
	int getNbVoisinAlive(ListePoints lp);
};

