#pragma once
#include <string>
#include <vector>
#include "voisin.h"
#include "listePoints.h"
#include <iostream>
using namespace std;
class ListeVoisin
{
private:
	vector<Voisin> v;
public:
	int getTaille();
	Voisin getVoisinById(int i);
	Voisin getVoisinByCoord(int a, int b, int c);
	void setVoisins(ListePoints lp, int baX, int baY, int baZ);
	void setVoisins(ListePoints lp, int minX, int minY, int minZ,int maxX,int maxY, int maxZ);
	void addVoisin(Voisin voi);
	void addVoisin(Point p,int id, int baX, int baY, int baZ);
	string toString();
};

