#include <iostream>
#include <vector>
#include "Kreis.h"
#include "Rechteck.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	vector<Graf *> vecG;

	while (true)
	{
		cout << "Kreis(1) oder Rechteck(2) erstellen?" << endl;
		int input;
		cin >> input;
		Graf *g;
		float x, y, r;
		float x1, y1, x2, y2;
		switch (input)
		{
		case 1: // Kreis
			cout << "Mittelpunkt x=";
			cin >> x;
			cout << endl;
			cout << "Mittelpunkt y=";
			cin >> y;
			cout << endl;
			cout << "Radius r=";
			cin >> r;
			try
			{
				g = new Kreis(x, y, r);
				vecG.push_back(g);
			}
			catch (ValueError *e)
			{
				cout << e->getError()<<endl;
			}
			break;
		case 2: // Rechteck
			cout << "Ecke 1 x=";
			cin >> x1;
			cout << endl;
			cout << "Ecke 1 y=";
			cin >> y1;
			cout << endl;
			cout << "Ecke 2 x=";
			cin >> x2;
			cout << endl;
			cout << "Ecke 2 y=";
			cin >> y2;
			cout << endl;
			g = new Rechteck(x1, y1, x2, y2);
			vecG.push_back(g);
			break;
		}
		vector<Kreis *> vecK;
		vector<Rechteck *> vecR;
		for (Graf *g : vecG)
		{
			if (typeid(*g) == typeid(Kreis))
			{
				vecK.push_back(dynamic_cast<Kreis *>(g));
			}
			else if (typeid(*g) == typeid(Rechteck))
			{
				vecR.push_back(dynamic_cast<Rechteck *>(g));
			}
		}
		float areaK = 0;
		for (int i = 0; i < vecK.size(); i++)
		{
			areaK += vecK.at(i)->getArea();
			cout << "Kreis " << i << ": " << vecK.at(i)->toString() << endl;
		}
		if (vecK.size() > 0)
		{
			cout << "Gesamtfläche der Kreise=" << areaK << endl;
		}

		float areaR = 0;
		for (int i = 0; i < vecR.size(); i++)
		{
			areaR += vecR.at(i)->getArea();
			cout << "Rechteck " << i << ": " << vecR.at(i)->toString() << endl;
		}
		if (vecR.size() > 0)
		{
			cout << "Gesamtfläche der Rechtecke=" << areaR << endl;
		}
		cout << "Kreis(1), Rechteck(2) ändern oder nichts machen(3)?" << endl;
		cin >> input;
		int gNum;
		try
		{
			switch (input)
			{
			case 1:
				cout << "Welcher Kreis?" << endl;
				cin >> gNum;
				if (gNum < 0 || gNum > vecK.size())
				{
					throw new IndexError();
				}
				cout << "X(1), Y(2), Radius(3) ändern oder Kreis löschen (4) ?" << endl;
				cin >> input;
				float a;
				if (input < 4)
				{
					cout << "Neuer Wert=";
					cin >> a;
				}
				switch (input)
				{
				case 1:
					vecK.at(gNum)->setCenter(a, vecK.at(gNum)->getCenter().y);
				case 2:
					vecK.at(gNum)->setCenter(vecK.at(gNum)->getCenter().x, a);
				case 3:
					vecK.at(gNum)->setRadius(a);
				case 4:
					for (int i = 0; i < vecG.size(); i++)
					{
						if (vecK.at(gNum) == vecG.at(i))
						{
							vecG.erase(vecG.begin() + i);
							delete vecK.at(gNum);
						}
					}
				}
				break;
			case 2:
				cout << "Welches Rechteck?" << endl;
				cin >> gNum;
				if (gNum < 0 || gNum > vecR.size())
				{
					throw new IndexError();
				}
				cout << "X1(1), Y1(2), X2(3), Y2(4) oder Rechteck löschen(5)?" << endl;
				cin >> input;
				if (input < 5)
				{
					cout << "Neuer Wert=";
					cin >> a;
				}
				switch (input)
				{
				case 1:
					vecR.at(gNum)->setCorner1(a, vecR.at(gNum)->getCorners().c1.y);
				case 2:
					vecR.at(gNum)->setCorner1(vecR.at(gNum)->getCorners().c1.x, a);
				case 3:
					vecR.at(gNum)->setCorner2(a, vecR.at(gNum)->getCorners().c2.y);
				case 4:
					vecR.at(gNum)->setCorner1(vecR.at(gNum)->getCorners().c2.x, a);
				case 5:
					for (int i = 0; i < vecG.size(); i++)
					{
						if (vecR.at(gNum) == vecG.at(i))
						{
							vecG.erase(vecG.begin() + i);
							delete vecR.at(gNum);
						}
					}
				}
				break;
			}
		}
		catch (IndexError *e)
		{
			cout << e->getError()<<endl;
		}
	}
	return 0;
}