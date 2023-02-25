#include "listePoints.h"
ListePoints::ListePoints() {
	taille = 0;
}

void ListePoints::addPoint(Point p) {
	ps.push_back(p);
	taille = ps.size();
}
Point ListePoints::getPointByCoord(int x, int y, int z) {
	Point p = ps[0];
    for (int i = 0; i < taille; i++)
    {
		p = ps[i];
		if (p.getX()==x && p.getY()==y && p.getZ()==z)
		{
			i = taille + 9;
		}
    }
	if (p.getX()!=ps[0].getX()&& p.getY() != ps[0].getY()&& p.getZ() != ps[0].getZ())
	{
		if (p.getX() != x && p.getY() != y && p.getZ() != z)
		{
			p.set(-1, -1, -1);
		}
	}
    return p;
}
void ListePoints::setMarkedByCoord(int a, int b, int c) {
	for (int i = 0; i < taille; i++)
	{
		if (ps[i].getX() == a && ps[i].getY() == b && ps[i].getZ() == c)
		{
			ps[i].setIsMarked(true);
		}
	}
	getPointByCoord(a, b, c).setIsMarked(true);
}
void ListePoints::setNoMarkedByCoord(int a, int b, int c) {
	for (int i = 0; i < taille; i++)
	{
		if (ps[i].getX() == a && ps[i].getY() == b && ps[i].getZ() == c)
		{
			ps[i].setIsMarked(false);
		}
	}
	getPointByCoord(a, b, c).setIsMarked(false);
}
Point ListePoints::getPointById(int ind) {
	Point p = ps[ind];
	return p;
}
int ListePoints::getTaille() {
	return taille;
}

string ListePoints::toString() {
	string s = "";
	s += "liste des points\n";
	for (int i = 0; i < taille; i++)
	{
		s = s + ps[i].toString() + "\n";
	}
	return s;
}
void ListePoints::clear() {
	ps.clear();
	taille = 0;
}