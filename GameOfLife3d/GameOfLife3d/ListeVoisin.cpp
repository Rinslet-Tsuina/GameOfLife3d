#include "ListeVoisin.h"



void ListeVoisin::setVoisins(ListePoints lp, int baX, int baY, int baZ)
{
	Voisin voi;
	for (int i = 0; i < lp.getTaille(); i++)
	{
		voi.setPbase(lp.getPointById(i));
		voi.setIdPoint(i);
		voi.setVoisins(baX,baY,baZ);
		v.push_back(voi);
	}
}
void ListeVoisin::setVoisins(ListePoints lp, int minX, int minY, int minZ, int maxX, int maxY, int maxZ)
{
	Voisin voi;
	for (int i = 0; i < lp.getTaille(); i++)
	{
		voi.setPbase(lp.getPointById(i));
		voi.setIdPoint(i);
		voi.setVoisins(minX, minY, minZ, maxX, maxY, maxZ);
		v.push_back(voi);
	}
	
}
int ListeVoisin::getTaille() {
	return (int)v.size();
}
Voisin ListeVoisin::getVoisinById(int i) {
	return v[i];
}
Voisin ListeVoisin::getVoisinByCoord(int a, int b, int c) {
	Voisin vTemp;
	for (int i = 0; i < getTaille(); i++)
	{
		if (v[i].getPbase().getX() == a && v[i].getPbase().getY() == b && v[i].getPbase().getZ() == c)
		{
			vTemp = v[i];
		}
	}
	return vTemp;
}
void ListeVoisin::addVoisin(Voisin voi) {
	v.push_back(voi);
}
void ListeVoisin::addVoisin(Point p,int id,int baX,int baY, int baZ) {
	Voisin temp;
	temp.setPbase(p);
	temp.setVoisins(baX, baY, baZ);
}

string ListeVoisin::toString()
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i].toString();
		s += "\n";
	}
	return s;
}
