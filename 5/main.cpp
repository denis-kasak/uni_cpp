#include <iostream>
#include <vector>
#include "Messwert.h"
#include "Exceptions.h"
using namespace std;

void addBlitz(int, vector<Messwert *> &);
void addTemp(int, vector<Messwert *> &);
vector<Temp *> getTemps(vector<Messwert *>);
vector<Blitz *> getBlitzs(vector<Messwert *>);
float getAvgTemp(vector<Temp *>);
float getSumBlitz(vector<Blitz *>);
void printAll(vector<Messwert *>);
void printTemp(vector<Temp *>);
void printBlitz(vector<Blitz *>);
bool compareTime(Messwert *, Messwert *);
void deleteBlitz(int, vector<Messwert *> &, vector<Blitz *> &);
void deleteTemp(int, vector<Messwert *> &, vector<Temp *> &);
Blitz *getBlitz(int, vector<Blitz *>);
Temp *getTemp(int, vector<Temp *>);

int main()
{
    int stop = 0;
    vector<Messwert *> vecM;

    for (int t = 1; true; t++)
    {
        sort(vecM.begin(), vecM.end(), compareTime);

        cout << "Blitzanzahl(1), Durchschnittstemperatur(2), beides(3) oder nichts(4) messen? ";
        int auswahl;
        cin >> auswahl;

        switch (auswahl)
        {
        case 1:
            addBlitz(t, vecM);
            break;
        case 2:
            addTemp(t, vecM);
            break;
        case 3:
            addBlitz(t, vecM);
            addTemp(t, vecM);
            break;
        case 4:
            break;
        }
        vector<Temp *> vecT = getTemps(vecM);
        vector<Blitz *> vecB = getBlitzs(vecM);

        printAll(vecM);
        cout << endl;
        printBlitz(vecB);
        cout << endl;
        printTemp(vecT);
        cout << endl;

        cout << "Anzahl Blitze seit Tag 1: " << getSumBlitz(vecB) << endl;
        cout << "Durchschnittstemperatur seit Tag 1: " << getAvgTemp(vecT) << endl;

        cout << endl;

        while (true)
        {
            try
            {
                cout << "Sollen Messwerte geändert werden(1/0)? ";
                int input;
                cin >> input;
                if (input == 0)
                {
                    break;
                }
                cout << "Soll ein Messwert für Blitze(1) oder Temperaturen(2) geändert werden? ";
                int type;
                cin >> type;
                if (type != 1 && type != 2)
                {
                    throw new ValueError(type);
                }
                cout << "Von welchem Tag soll der Messwert geändert werden? ";
                int day;
                cin >> day;
                cout << "Soll die Zeit(1) oder der Messwert geändert (2) oder der Wert gelöscht werden(3)? ";
                int par;
                cin >> par;
                float val;
                if (par == 1 || par == 2)
                {
                    cout << "Neuen Wert eingeben: ";
                    cin >> val;
                }
                switch (type)
                {
                case 1: // Blitz ändern
                    switch (par)
                    {
                    case 1: // Blitz Time ändern
                        getBlitz(day, vecB)->t.set(val);
                        break;
                    case 2: // Blitz Wert ändern
                        getBlitz(day, vecB)->set(val);
                        break;
                    case 3: // Blitz löschen
                        deleteBlitz(day, vecM, vecB);
                        break;
                    }
                    break;
                case 2: // Temp ändern
                    switch (par)
                    {
                    case 1: // Temp Time ändern
                        getTemp(day, vecT)->t.set(val);
                        break;
                    case 2: // Temp Wert ändern
                        getTemp(day, vecT)->t.set(val);
                        break;
                    case 3: // Temp löschen
                        deleteTemp(day, vecM, vecT);
                        break;
                    }
                    break;
                }
                sort(vecM.begin(), vecM.end(), compareTime);
                printAll(vecM);
                cout << endl;
                printBlitz(vecB);
                cout << endl;
                printTemp(vecT);
                cout << endl;
            }
            catch (ValueError* e)
            {
                cout<<e->getError()<<endl;
            }
        }
    }
}

void deleteBlitz(int time, vector<Messwert *> &vecM, vector<Blitz *> &vecB)
{
    for (int i = 0; i < vecB.size(); i++)
    {
        Blitz *b = vecB.at(i);

        if (b->t.get() == time)
        {
            vecB.erase(vecB.begin() + i);

            for (int j = 0; j < vecM.size(); j++)
            {
                if (vecM.at(i) == b)
                {
                    vecM.erase(vecM.begin() + i);
                    delete b;
                    return;
                }
            }
        }
    }
}

void deleteTemp(int time, vector<Messwert *> &vecM, vector<Temp *> &vecT)
{
    for (int i = 0; i < vecT.size(); i++)
    {
        Temp *t = vecT.at(i);

        if (t->t.get() == time)
        {
            vecT.erase(vecT.begin() + i);

            for (int j = 0; j < vecM.size(); j++)
            {
                if (vecM.at(i) == t)
                {
                    vecM.erase(vecM.begin() + i);
                    delete t;
                    return;
                }
            }
        }
    }
}

Blitz *getBlitz(int time, vector<Blitz *> vecB)
{
    for (Blitz *b : vecB)
    {
        if (b->t.get() == time)
        {
            return b;
        }
    }
}

Temp *getTemp(int time, vector<Temp *> vecT)
{
    for (Temp *t : vecT)
    {
        if (t->t.get() == time)
        {
            return t;
        }
    }
}

bool compareTime(Messwert *mp1, Messwert *mp2)
{
    Messwert m1 = *mp1;
    Messwert m2 = *mp2;
    return m1.t.get() < m2.t.get();
}

void addBlitz(int t, vector<Messwert *> &vecM)
{
    cout << "Blitzanzahl für Tag " << t << " eingeben: ";
    int num;
    cin >> num;
    Messwert *m;
    m = new Blitz(num, t);
    vecM.push_back(m);
}

void addTemp(int t, vector<Messwert *> &vecM)
{
    cout << "Durchschnittstemperatur für Tag " << t << " eingeben: ";
    float temp;
    cin >> temp;
    Messwert *m;
    m = new Temp(temp, t);
    vecM.push_back(m);
}

vector<Temp *> getTemps(vector<Messwert *> vecM)
{
    vector<Temp *> vecT;

    for (Messwert *m : vecM)
    {
        if (typeid(*m) == typeid(Temp))
        {
            vecT.push_back(dynamic_cast<Temp *>(m));
        }
    }
    return vecT;
}

vector<Blitz *> getBlitzs(vector<Messwert *> vecM)
{
    vector<Blitz *> vecB;

    for (Messwert *m : vecM)
    {
        if (typeid(*m) == typeid(Blitz))
        {
            vecB.push_back(dynamic_cast<Blitz *>(m));
        }
    }
    return vecB;
}

float getAvgTemp(vector<Temp *> vecT)
{
    float sum = 0;
    for (Temp *t : vecT)
    {
        sum += t->get();
    }
    return sum / vecT.size();
}

float getSumBlitz(vector<Blitz *> vecB)
{
    int sum = 0;
    for (Blitz *b : vecB)
    {
        sum += b->get();
    }
    return sum;
}

void printAll(vector<Messwert *> vecM)
{
    cout << "Alle Messwerte in Reihenfolge:" << endl;

    for (Messwert *m : vecM)
    {
        cout << m->toString() << endl;
    }
}

void printTemp(vector<Temp *> vecT)
{
    cout << "Alle Durschnittstemperaturen in Reihenfolge:" << endl;
    for (Temp *t : vecT)
    {
        cout << t->toString() << endl;
    }
}

void printBlitz(vector<Blitz *> vecB)
{
    cout << "Alle Blitzwerte in Reihenfolge:" << endl;
    for (Blitz *b : vecB)
    {
        cout << b->toString() << endl;
    }
}