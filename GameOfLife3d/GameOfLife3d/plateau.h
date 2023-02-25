#pragma once
//#include "GL/glut.h"
#include "listePoints.h"
#include <iostream>
#include "ListeVoisin.h"
#include <time.h>

using namespace std;
class Plateau
{
	private:
		int tx, ty, tz;
		int t,tour;
		ListePoints lp;
		ListeVoisin lv;
		bool isStart;
		bool isStable;
	public:
		Plateau();
		Plateau(int tx, int ty, int tz);
		void setTailleAxes(int tx, int ty, int tz);
		void setIsStart(bool b);
		bool getIsStart();
		void addMarked(int a, int b, int c);
		void addNoMarked(int a, int b, int c);
		void initPlateau(int tx, int ty, int tz);
		void startGame();
		void stopGame();
		void nextTurn();
		void clearGame();
		void verifIsStable();
		void inGame();
		void affichage();
		int getNbVoisinAlive(int a, int b, int c);
		void menu();
		void accueil(bool isMpi);
		int getTaillePlateau();
		ListePoints getListePoints();
		ListeVoisin getListeVoisins();

		void synchro(double duree);
};

