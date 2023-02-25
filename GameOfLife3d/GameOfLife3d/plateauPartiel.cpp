#include "plateauPartiel.h"

PlateauPartiel::PlateauPartiel()
{
	setTailleAxes(1, 1, 1,2,2,2);
	isStable = false;
}

PlateauPartiel::PlateauPartiel(int tminX, int tminY, int tminZ, int tmaxX, int tmaxY, int tmaxZ)
{
	initPlateau(tminX, tminY, tminZ, tmaxX, tmaxY, tmaxZ);
	isStable = false;
}

void PlateauPartiel::setTailleAxes(int tminX, int tminY, int tminZ, int tmaxX, int tmaxY, int tmaxZ)
{
	minX = tminX;
	minY = tminY;
	minZ = tminZ;
	maxX = tmaxX;
	maxY = tmaxY;
	maxZ = tmaxZ;
	t = (maxX - minX) * (maxY - minY) * (maxZ - minZ);
}

void PlateauPartiel::addMarked(int a, int b, int c)
{
	lp.setMarkedByCoord(a, b, c);
}

void PlateauPartiel::addNoMarked(int a, int b, int c)
{
	lp.setNoMarkedByCoord(a, b, c);
}

void PlateauPartiel::initPlateau(int tminX, int tminY, int tminZ, int tmaxX, int tmaxY, int tmaxZ)
{
	setTailleAxes(tminX, tminY, tminZ, tmaxX, tmaxY, tmaxZ);
	Point pTemp;
	int a = 0, b = 0, c = 0;
	for (int i = tminX; i < tmaxX; i++)
	{

		a = i;
		for (int j = tminY; j < tmaxY; j++)
		{

			b = j;
			for (int k = tminZ; k < tmaxZ; k++)
			{

				c = k;
				pTemp.set(a, b, c);
				pTemp.setIsMarked(false);

				lp.addPoint(pTemp);
			}
		}
	}
	lv.setVoisins(lp, minX, minY, minZ, maxX, maxY, maxZ);
}

void PlateauPartiel::nextTurn()
{
	//changement des états des points
	ListePoints lpTemp;
	for (int i = 0; i < lp.getTaille(); i++)
	{
		lpTemp.addPoint(lp.getPointById(i));
	}
	for (int i = 0; i < lp.getTaille(); i++)
	{
		Point pTemp = lp.getPointById(i);
		int nbVoisins = getNbVoisinAlive(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
		if (lp.getPointById(i).getIsMarked())
		{//allumé
			if (nbVoisins < 2)
			{
				//lp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				lpTemp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				cout << "eteind" << endl;
			}
			if (nbVoisins > 3)
			{
				//lp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				lpTemp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				cout << "eteind" << endl;
			}
		}
		if (!(lp.getPointById(i).getIsMarked()))
		{//éteinde
			if (nbVoisins == 3)
			{
				cout << "allume" << endl;
				//lp.setMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				lpTemp.setMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
			}
		}

	}
	//Update des points
	for (int i = 0; i < lp.getTaille(); i++)
	{
		if (lpTemp.getPointById(i).getIsMarked())
		{
			lp.setMarkedByCoord(lpTemp.getPointById(i).getX(), lpTemp.getPointById(i).getY(), lpTemp.getPointById(i).getZ());
		}
		else {
			lp.setNoMarkedByCoord(lpTemp.getPointById(i).getX(), lpTemp.getPointById(i).getY(), lpTemp.getPointById(i).getZ());
		}
	}
}

void PlateauPartiel::verifIsStable()
{
	//passage au tour suivant pour la liste temporaire
	cout << "" << endl;
	ListePoints lpTemp;
	for (int i = 0; i < lp.getTaille(); i++)
	{
		lpTemp.addPoint(lp.getPointById(i));
	}
	cout << "temporaire " << lpTemp.toString() << endl;
	//changement des états des points
	for (int i = 0; i < t; i++)
	{
		int nbVoisins = getNbVoisinAlive(lpTemp.getPointById(i).getX(), lpTemp.getPointById(i).getY(), lpTemp.getPointById(i).getZ());
		if (lpTemp.getPointById(i).getIsMarked())
		{//allumé
			if (nbVoisins < 2 || nbVoisins > 3)
			{
				lpTemp.setNoMarkedByCoord(lpTemp.getPointById(i).getX(), lpTemp.getPointById(i).getY(), lpTemp.getPointById(i).getZ());
			}
		}
		else
		{//éteinde
			if (nbVoisins == 3)
			{
				lpTemp.setMarkedByCoord(lpTemp.getPointById(i).getX(), lpTemp.getPointById(i).getY(), lpTemp.getPointById(i).getZ());
			}
		}
		cout << "nb voisin alive " << lpTemp.getPointById(i).toString() << " : " << nbVoisins << endl;
	}
	cout << "temporaire Next " << lpTemp.toString() << endl;
	//comparaison des deux listes
	bool compStable = true;
	for (int i = 0; i < t; i++)
	{
		if (lpTemp.getPointById(i).getIsMarked() != lp.getPointById(i).getIsMarked()) {
			compStable = false;
		}
	}
	if (compStable)
	{
		isStable = true;
		cout << "stable" << endl;
	}
	else
	{
		isStable = false;
		cout << "pas stable" << endl;
	}
}

int PlateauPartiel::getNbVoisinAlive(int a, int b, int c)
{
	int comp = 0;
	comp = lv.getVoisinByCoord(a, b, c).getNbVoisinAlive(lp);
	return comp;
}

void PlateauPartiel::addPoint(Point p)
{
	lp.addPoint(p);
}

void PlateauPartiel::addVoisin(Voisin v)
{
	lv.addVoisin(v);
}
