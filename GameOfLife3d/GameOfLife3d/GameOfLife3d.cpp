// GameOfLife3d.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//visual studio 2022
//openGL
//TISSERAND Orlane

//A MODIFIER
//MPI LINUX

#include <iostream>
#include <new>
#include <math.h>
#include <vector>
#include "GameOfLife.h"

using namespace std;

int main(int argc, char** argv)
{
	//MPI_Init(&argc, &argv);
	int nt, rank, len, rc;
	nt = 0; rank = 0; len = 0; rc = 0;
	//char hostname[MPI_MAX_PROCESSOR_NAME];
	//MPI_Status status;
	//MPI_Comm_Size(MPI_COMM_WORLD,&nt);
	//MPI_Comm_Rank(MPI_COMM_WORLD,&rank);
	//MPI_Get_processor_name(hostname, &len);
	GameOfLife gol;
	gol.initGameOfLife(nt, rank, len, rc);
	gol.turnMPI(nt,rank);
	//MPI_Finalize();
	return 0;
}