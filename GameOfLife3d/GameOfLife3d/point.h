#pragma once
#include <string>

using namespace std;
class Point
{
	private:
		int x, y, z;
		bool isMarked;
	public:
		
		void set(int a, int b, int c);
		void setIsMarked(bool bo);
		bool getIsMarked();
		int getX();
		int getY();
		int getZ();

		string toString();

};

