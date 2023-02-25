#pragma once
#include <iostream>
//#include "mpi.h"
#include "plateau.h"
using namespace std;
class GameOfLife
{
private:
	Plateau p;
	bool isMPI;
public:
	GameOfLife();
	void initGameOfLife(int nt, int rank, int len, int rc);
	void GOLClassique();
	void GOLMPI(int nt, int rank, int len, int rc);
	void turnMPI(int nt, int rank);
	void initMPI(int nt, int rank, int len, int rc);
	void updatePlateau(ListePoints pTemp);
	bool verifEtatPoint(int etatP,int nbVA);
	void zeroToEveryone(int nt, int rank);
	void everyoneToZero(int nt, int rank);
};
