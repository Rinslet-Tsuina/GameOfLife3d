#include "voisin.h"

void Voisin::setVoisins(int baX, int baY, int baZ)
{
	setVoisins(0, 0, 0, baX, baY, baZ);
	/*v.clear();
	Point temp;
	int x = pbase.getX();
	int y = pbase.getY();
	int z = pbase.getZ();
	temp.setIsMarked(false);
	//6 voisin collé au point de base
	temp.set(x - 1, y , z );
	if (!(temp.getX() <  0 || temp.getX() >= baX))
	{
		if (!(temp.getY() <  0 || temp.getY() >= baY)) {
			if (!(temp.getZ()<0 || temp.getZ()>=baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y , z);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y - 1, z );
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x , y + 1, z );
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x , y , z - 1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y , z + 1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même z que le point de base
	temp.set(x - 1, y - 1, z );
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y + 1, z);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y - 1, z);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y + 1, z );
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même x que le point de base
	temp.set(x , y - 1, z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x , y - 1, z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y + 1, z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x , y + 1, z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même y que le point de base
	temp.set(x - 1, y , z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y , z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y , z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y , z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même x=xPb-1
	temp.set(x - 1, y - 1, z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y - 1, z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y + 1, z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y + 1, z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même x=xPb+1
	temp.set(x + 1, y - 1, z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y - 1, z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y + 1, z-1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y + 1, z+1);
	if (!(temp.getX() < 0 || temp.getX() >= baX))
	{
		if (!(temp.getY() < 0 || temp.getY() >= baY)) {
			if (!(temp.getZ() < 0 || temp.getZ() >= baZ))
			{
				v.push_back(temp);
			}
		}
	}

	if (getTaille()>26)
	{
		cout << "error" << endl;
	}*/
}
void Voisin::setVoisins(int minX, int minY, int minZ, int maxX, int maxY, int maxZ)
{
	v.clear();
	Point temp;
	int x = pbase.getX();
	int y = pbase.getY();
	int z = pbase.getZ();
	temp.setIsMarked(false);
	//6 voisin collé au point de base
	temp.set(x - 1, y, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y - 1, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y + 1, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même z que le point de base
	temp.set(x - 1, y - 1, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y + 1, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y - 1, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y + 1, z);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même x que le point de base
	temp.set(x, y - 1, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y - 1, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y + 1, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x, y + 1, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même y que le point de base
	temp.set(x - 1, y, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même x=xPb-1
	temp.set(x - 1, y - 1, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y - 1, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y + 1, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x - 1, y + 1, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	//4 cube ayant le même x=xPb+1
	temp.set(x + 1, y - 1, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y - 1, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y + 1, z - 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}
	temp.set(x + 1, y + 1, z + 1);
	if (!(temp.getX() < minX || temp.getX() >= maxX))
	{
		if (!(temp.getY() < minY || temp.getY() >= maxY)) {
			if (!(temp.getZ() < minZ || temp.getZ() >= maxZ))
			{
				v.push_back(temp);
			}
		}
	}

	if (getTaille() > 26)
	{
		cout << "error" << endl;
	}
}
int Voisin::getTaille() {
	return (int)v.size();
}
Point Voisin::getVoisinById(int i) {
	return v[i];
}
string Voisin::toString()
{
	string s = "";
	s += "Point :";
	s += pbase.toString();
	s += "\n";
	s += "Voisins :";
	s += "\n";
	s += to_string(v.size());
	s += "\n";
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i].toString();
		s += "\n";
	}
	return s;
}
Point Voisin::getPbase() {
	return pbase;
}
void Voisin::setPbase(Point p) {
	pbase = p;
}
void Voisin::setIdPoint(int idP) {
	idPoint = idP;
}
void Voisin::setMarkedByCoord(int a, int b, int c) {
	if (isVoisinExist(a,b,c))
	{
		getVoisinByCoord(a, b, c).setIsMarked(true);
	}
}
Point Voisin::getVoisinByCoord(int a, int b, int c) {
	int ind = -1;
	for (int i = 0; i < getTaille(); i++)
	{
		if (v[i].getX() == a && v[i].getY() == b && v[i].getZ() == c) {
			ind = i;
			i = i + getTaille();
		}
	}
	return v[ind];
}
bool Voisin::isVoisinExist(int a, int b, int c) {
	int ind = -1;
	for (int i = 0; i < getTaille(); i++)
	{
		if (v[i].getX() == a && v[i].getY() == b && v[i].getZ() == c) {
			i = i + getTaille();
			ind = i;
		}
	}
	if (ind == -1) {
		return false;
	}
	else {
		return true;
	}
}
void Voisin::addVoisin(Point p)
{
	v.push_back(p);
}
int Voisin::getNbVoisinAlive(ListePoints lp) {
	int comp = 0;
	for (int i = 0; i < getTaille(); i++)
	{
		if (lp.getPointByCoord(v[i].getX(),v[i].getY(),v[i].getZ()).getIsMarked())
		{
			comp++;
		}
	}
	return comp;
}