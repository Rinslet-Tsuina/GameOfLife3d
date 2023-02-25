#pragma once
#include "listePoints.h"
#include <iostream>
#include "ListeVoisin.h"
using namespace std;

class PlateauPartiel
{
private:
	int minX, minY, minZ, maxX, maxY, maxZ;
	int t;
	ListePoints lp;
	ListeVoisin lv;
	bool isStable;
public:
	PlateauPartiel();
	PlateauPartiel(int tminX, int tminY, int tminZ, int tmaxX, int tmaxY, int tmaxZ);
	void setTailleAxes(int tminX, int tminY, int tminZ, int tmaxX, int tmaxY, int tmaxZ);
	void addMarked(int a, int b, int c);
	void addNoMarked(int a, int b, int c);
	void initPlateau(int tminX, int tminY, int tminZ, int tmaxX, int tmaxY, int tmaxZ);
	void nextTurn();
	void verifIsStable();
	int getNbVoisinAlive(int a, int b, int c);
	void addPoint(Point p);
	void addVoisin(Voisin v);
};

