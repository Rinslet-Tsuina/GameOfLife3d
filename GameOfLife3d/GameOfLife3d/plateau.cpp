#include "plateau.h"

Plateau::Plateau() {
	setTailleAxes(1, 1, 1);
	isStart = false;
	isStable = false;
}
Plateau::Plateau(int tx, int ty, int tz) {
		initPlateau(tx, ty, tz);
		setIsStart(false);
		isStable = false;
}
void Plateau::setTailleAxes(int tx, int ty, int tz) {
	this->tx = tx;
	this->ty = ty;
	this->tz = tz;
	this->t = tx*ty*tz;
}
void Plateau::setIsStart(bool b) {
	isStart = b;
}
bool Plateau::getIsStart() {
	return isStart;
}
void Plateau::initPlateau(int tx, int ty, int tz){
	setTailleAxes(tx, ty, tz);
	tour = 0;
	Point pTemp;
	int a=0, b=0, c=0;
	for (int i = 0; i < tx; i++)
	{
		
		a = i;
		for (int j = 0; j < ty; j++)
		{
			
			b = j;
			for (int k = 0; k < tz; k++)
			{
				
				c = k;
				pTemp.set(a, b, c);
				pTemp.setIsMarked(false);
				
				lp.addPoint(pTemp);
			}
		}
	}
	lv.setVoisins(lp, tx, ty, tz);
}
//debut du jeu
void Plateau::startGame() {
	setIsStart(true);
}
//arret du jeu
void Plateau::stopGame(){
	setIsStart(false);
}
void Plateau::nextTurn(){
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
			if (nbVoisins < 2 )
			{
				//lp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				lpTemp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				//cout << "eteind" << endl;
			}
			if (nbVoisins>3)
			{
				//lp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				lpTemp.setNoMarkedByCoord(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
				//cout << "eteind" << endl;
			}
		}
		if (!(lp.getPointById(i).getIsMarked()))
		{//éteinde
			if (nbVoisins == 3)
			{
				//cout << "allume" << endl;
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
//mise à zero
void Plateau::clearGame(){
	if (!isStart)
	{
		for (int i = 0; i < lp.getTaille(); i++)
		{
			addNoMarked(lp.getPointById(i).getX(), lp.getPointById(i).getY(), lp.getPointById(i).getZ());
		}
		tour = 0;
	}
}

void Plateau::verifIsStable(){
	//passage au tour suivant pour la liste temporaire
	//cout <<""<< endl;
	ListePoints lpTemp ;
	for (int i = 0; i < lp.getTaille(); i++)
	{
		lpTemp.addPoint(lp.getPointById(i));
	}
	//cout << "temporaire " << lpTemp.toString() << endl;
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
		//cout << "nb voisin alive " << lpTemp.getPointById(i).toString() << " : " << nbVoisins << endl;
	}
	//cout << "temporaire Next " << lpTemp.toString() << endl;
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
		isStart = false;
		cout << "stable" << endl;
	}
	else
	{
		isStable = false;
		cout << "pas stable" << endl;
	}
}
void Plateau::inGame() {
	//voir Labyrinthe temps
	synchro(0.7);//A MODIFIER 
	//clear console
	//system("cls");//windows
	//system("clear");//linux
	if (tour > 10) {
		isStart = false;
		cout << "arret du jeu depassement etapes autorisees" << endl;
	}
	//affichage3D();
	if (isStart)
	{
		cout << "tour n'" << to_string(tour) << endl;
		nextTurn();
		tour++;
		verifIsStable();
		affichage();
		if (!isStable)
		{
			inGame();
		}
		else {
			isStart = false;
			cout << "arret du jeu" << endl;
		}
	}
}
void Plateau::addMarked(int a, int b,int c) {
	lp.setMarkedByCoord(a, b, c);
}
void Plateau::addNoMarked(int a, int b, int c) {
	lp.setNoMarkedByCoord(a, b, c);
}

void Plateau::affichage() {
	string s = "";
	string isStartS = "";
	if (isStart)
	{
		isStartS = "start ";
	}
	else {
		isStartS = "stop";
	}
	string isStableS = "";
	if (isStable)
	{
		isStableS = "stable";
	}
	else {
		isStableS = "non stable";
	}
	s += "Plateau\n";
	s =s+ "taille axes: x"+to_string(tx)+" y "+to_string(ty)+" z "+to_string(tz);
	s = s + "\n nb points: " + to_string(t);
	s = s + "\nisStart "+isStartS+" isStable "+isStableS;
	s = s +"\n Liste des points: " + lp.toString();
	//s =s+ "\n Liste des voisins par points: " + lv.toString();
	cout << s << endl;
	
}
int Plateau::getNbVoisinAlive(int a, int b, int c) {
	int comp = 0;
	comp=lv.getVoisinByCoord(a, b, c).getNbVoisinAlive(lp);
	//cout << "getAlive " << lp.getPointByCoord(a, b, c).toString() << " nb " << to_string(comp) << endl;
	return comp;
}
void Plateau::menu() {
	cout << "Menu:" << endl;
	cout << "	-A:Ajout de points allumes/eteinds" << endl;
	cout << "	-S:Start la simulation" << endl;
	cout << "	-P:Pause" << endl;
	cout << "	-C:Clear l'allumage des points" << endl;
	cout << "	-Q:Quitter" << endl;
	string s= "";
	cin >> s;
	int choix=-1;
	if (s=="A" || s=="a")
	{
		choix = 1;
	}if (s == "S" || s == "s")
	{
		choix = 2;
	}

	if (s == "P" || s == "p")
	{
		choix = 3;
	}
	if (s == "C" || s == "c")
	{
		choix = 4;
	}
	if (s == "Q" || s == "q")
	{
		choix = 5;
	}
	switch (choix)
	{
		case 1:
			cout<<lp.toString()<<endl;
			int tempX, tempY, tempZ;
			cout << "Veuillez entrer la coordonnee en X" << endl;
			cin >> tempX;
			cout << "Veuillez entrer la coordonnee en Y" << endl;
			cin >> tempY;
			cout << "Veuillez entrer la coordonnee en Z" << endl;
			cin >> tempZ;
			if (tempX>=0 && tempX<tx && tempY >= 0 && tempY < ty && tempZ >= 0 && tempZ < tz)
			{
				if (lp.getPointByCoord(tempX, tempY, tempZ).getIsMarked()) {
					addNoMarked(tempX, tempY, tempZ);
				}
				else {
					addMarked(tempX, tempY, tempZ);
				}
			}
			break;
		case 2:
			startGame();
			cout << "debut du jeu" << endl;
			break;
		case 3:
			stopGame();
			break;
		case 4:
			clearGame();
			break;
		case 5:
			exit(0);
			break;
	}
}
void Plateau::accueil(bool isMpi) {
	{
		cout << "Bienvenue dans le jeu de la vie" << endl;
		cout << "Les regles du jeu de la vie 2d s'applique" << endl;
		bool isOk = true;
		do
		{
			isOk = true;
			cout << "Veuillez entrer un chiffre superieur a 0" << endl;
			cout << "La coordonne minimum est 1" << endl;
			cout << "Veuillez entrer la taille en X" << endl;
			cin >> tx;
			cout << "Veuillez entrer la taille en Y" << endl;
			cin >> ty;
			cout << "Veuillez entrer la taille en Z" << endl;
			cin >> tz;
			if (tx <= 0) {
				isOk = false;
				cout << "error sur l'axe X" << endl;
			}
			if (ty <= 0) {
				isOk = false;
				cout << "error sur l'axe Y" << endl;
			}
			if (tz <= 0) {
				isOk = false;
				cout << "error sur l'axe Z" << endl;
			}
		} while (!isOk);
		t = tx * ty * tz;
		initPlateau(tx,ty,tz);
		affichage();
		do
		{
			menu();
			affichage();
		} while (!isStart);
		if (!isMpi)
		{
			inGame();
		}
	}
}

int Plateau::getTaillePlateau() {
	return lp.getTaille();
}
ListePoints Plateau::getListePoints() {
	return lp;
}
ListeVoisin Plateau::getListeVoisins() {
	return lv;
}

void Plateau::synchro(double duree) {
	static clock_t jalon = clock();
	jalon = jalon + (clock_t)(duree * CLOCKS_PER_SEC);;
	while (clock() < jalon);
}