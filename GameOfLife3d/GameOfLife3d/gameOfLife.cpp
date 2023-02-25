#include "GameOfLife.h"

GameOfLife::GameOfLife() {
    isMPI = false;
}
void GameOfLife::initGameOfLife(int nt, int rank, int len, int rc) {
    cout << "Vous les vous lancer le jeu de la vie:" << endl;
    cout << "A->sans MPI" << endl;
    cout << "B->avec MPI" << endl;
    string s = "";
    cin >> s;
    if (s == "A" || s == "a")
    {
        GOLClassique();
    }else if (s == "B" || s == "b")
    {
		GOLMPI(nt, rank, len, rc);
    }
    else {
		initGameOfLife(nt, rank, len, rc);
    }
}
void GameOfLife::GOLClassique() {
    isMPI = false;
    p.accueil(isMPI);
}

void GameOfLife::GOLMPI(int nt, int rank, int len, int rc) {
    isMPI = true;
    p.accueil(isMPI);
    //initMPI(nt,rank, len,rc);
	//turnMPI(nt,rank);
}


void GameOfLife::turnMPI(int nt, int rank)
{
    int tour = 0;
    while (p.getIsStart()) {
        p.verifIsStable();
		zeroToEveryone(nt, rank);
		everyoneToZero(nt, rank);
        tour++;
        if (tour>10)
        {
			p.setIsStart(false);
        }
    }
}

void GameOfLife::initMPI(int nt, int rank, int len, int rc)
{
	//char hostname[MPI_MAX_PROCESSOR_NAME];
    //MPI_Status status;
    //MPI_Comm_Size(MPI_COMM_WORLD,&nt);
	//MPI_Comm_Rank(MPI_COMM_WORLD,&rank);
	//MPI_Get_processor_name(hostname, &len);
}


void GameOfLife::updatePlateau(ListePoints pTemp) {
    for (int i = 0; i < pTemp.getTaille(); i++)
    {
        if (pTemp.getPointById(i).getIsMarked())
        {
            p.addMarked(pTemp.getPointById(i).getX(), pTemp.getPointById(i).getY(), pTemp.getPointById(i).getZ());
        }
        else {
            p.addNoMarked(pTemp.getPointById(i).getX(), pTemp.getPointById(i).getY(), pTemp.getPointById(i).getZ());
        }
    }
}
bool GameOfLife::verifEtatPoint(int etatP, int nbVA) {
    bool etat=etatP;
    if (etatP)
    {
        if (nbVA<2 || nbVA>3)
        {
            etat = false;
        }
    }
    else {
        if (nbVA==3)
        {
            etat = true;
        }
    }
    return etat;
}

void GameOfLife::zeroToEveryone(int nt, int rank)
{
    if (rank == 0) {
        int nbPoint = 0;
        int tab[28][3];
        int tab2[4];
		ListePoints lpTemp;
        for (int i = 0; i < p.getTaillePlateau(); i++)
        {
            lpTemp.addPoint(p.getListePoints().getPointById(i));
        }
		//tant que tous les points n'ont pas été traités
        do
        {
            
            //envoie aux processus
            for (int i = 1; i < nt; i++)
            {
                //preparation du tableau a envoyer aux processus
                tab[0][0] = p.getListePoints().getPointById(nbPoint).getX();
                tab[0][1] = p.getListePoints().getPointById(nbPoint).getY();
                tab[0][2] = p.getListePoints().getPointById(nbPoint).getZ();

                for (int i = 1; i < 28; i++)
                {
                    tab[i][0] = -1;
                    tab[i][1] = -1;
                    tab[i][2] = -1;
                }
                if (p.getListePoints().getPointById(nbPoint).getIsMarked())
                {
                    tab[27][0] = 1;
                }
                else {
                    tab[27][0] = 0;
                }
                for (int i = 0; i < p.getListeVoisins().getVoisinByCoord(tab[0][0], tab[0][1], tab[0][2]).getTaille(); i++)
                {
                    tab[i + 1][0] = p.getListeVoisins().getVoisinByCoord(tab[0][0], tab[0][1], tab[0][2]).getVoisinById(i).getX();
                    tab[i + 1][1] = p.getListeVoisins().getVoisinByCoord(tab[0][0], tab[0][1], tab[0][2]).getVoisinById(i).getY();
                    tab[i + 1][2] = p.getListeVoisins().getVoisinByCoord(tab[0][0], tab[0][1], tab[0][2]).getVoisinById(i).getZ();
                    if (!p.getListePoints().getPointByCoord(tab[i + 1][0], tab[i + 1][1], tab[i + 1][2]).getIsMarked())
                    {
                        tab[i + 1][0] = -1;
                    }
                }
                //MPI_Send(tab,3*28,MPI_INT,i,0,MPI_COMM_WORLD);
                nbPoint++;
                if (nbPoint==p.getTaillePlateau())
                {
                    i = nt + 1;
                }
            }
            if (nbPoint<p.getTaillePlateau())
            {
                for (int i = 1; i < nt; i++) {
                    //MPI_Recv(tab2,4,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                    if (tab2[3] == 1) {
                        lpTemp.setMarkedByCoord(tab2[0], tab2[1], tab2[2]);
                    }
                    if (tab2[3] == 0) {
                        lpTemp.setNoMarkedByCoord(tab2[0], tab2[1], tab2[2]);
                    }

                }
            }
        } while (nbPoint <p.getTaillePlateau());
        updatePlateau(lpTemp);
        lpTemp.clear();
        p.affichage();
    }
}

void GameOfLife::everyoneToZero(int nt, int rank)
{
    if (rank != 0) {
        int tab2[4];
        int tab[28][3];
        int nbVAlive = 0;
        //MPI_Recv(tab,3*28,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        for (int i = 1; i < 27; i++)
        {
            if (tab[i][0] != -1) {
                nbVAlive++;
            }
        }
        bool etatN = verifEtatPoint(tab[27][0], nbVAlive);
        int ietatN;
        if (etatN) { ietatN = 1; }
        else { ietatN = 0; }
        tab2[0] = tab[0][0];
        tab2[1] = tab[0][1];
        tab2[2] = tab[0][2];
        tab2[3] = ietatN;
        //MPI_Send(tab2,4,MPI_INT,0,0,MPI_COMM_WORLD);
    }
}
