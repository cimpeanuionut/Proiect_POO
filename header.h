#ifndef HEADER_H
#define HEADER_H

#include<iostream>
using namespace std;

//Crearea claselor
//clasa locatie //contine numeLocatie, latitudinea, longitudinea, nrLocatii
//Legatura dintre main si classes.cpp
class Locatie
{
protected:
	char* numeLocatie;
	double latitudine;
	double longitudine;
	static int nrLocatii;
public:
	Locatie()
	{
		numeLocatie = new char[strlen("Nowhere") + 1];
		strcpy(numeLocatie, "Nowhere");
		latitudine = 0;
		longitudine = 0;
	}
	Locatie(char* num,double lat,double longi)
	{
		delete[] numeLocatie;
		numeLocatie = new char[strlen(num) + 1];
		strcpy(numeLocatie, num);
		latitudine = lat;
		longitudine = longi;
		nrLocatii++;
	}
	Locatie(Locatie &l)
	{
		delete[] numeLocatie;
		numeLocatie = new char[strlen(l.numeLocatie) + 1];
		strcpy(numeLocatie, l.numeLocatie);
		latitudine = l.latitudine;
		longitudine = l.longitudine;
		nrLocatii++;
	}
	~Locatie()
	{
		delete[] numeLocatie;
		
	}
	void citire();
	void afisare();
	void operator=(Locatie &l);
	void setNumeLocatie(char* loc);
	void setLatitudinea(long double lat);
	void setLongitudinea(double lat);
	char* getNumeLocatie();
	double getLatitudinea();
	double getLongitudinea();
	static int getNrLocatii();
	friend ostream& operator<<(ostream& iesire, Locatie &l);
	friend istream& operator>>(istream& intrare, Locatie &l);
	void operator+(Locatie &l);//media lat si l.lat si media long si l.long2
	
	
	
};

//clasa Auto //contine id si cate autoturisme
class Auto
{
protected:
	char* id;
	static int nrAuto;
public:
	Auto()
	{
		id = new char[strlen("None") + 1];
		strcpy(id, "None");
		if (strcmp(id,"None" )!=0)
			nrAuto++;
	}
	Auto(char* id)
	{
		if ((strcmp(this->id, "None") != 0)&&(strcmp(this->id,id)!=0))
			nrAuto++;
		delete[] this->id;
		this->id = new char[strlen(id) + 1];
		strcpy(this->id,id);
		
	}
	Auto(Auto &a)
	{
		if ((strcmp(id, "None") != 0) && (strcmp(id, a.id) != 0))
			nrAuto++;
		delete[] id;
		id = new char[strlen(a.id) + 1];
		strcpy(id, a.id);
	}
	~Auto()
	{
		delete[] id;
	}
	void citire();
	void afisare();
	int getNrAuto()
	{
		return nrAuto;
	}
	char* getId()
	{
		return id;
	}
	void setId(char* d)
	{
		if (strcmp(id, d) != 0)
			nrAuto++;
		delete[] id;
		id = new char[strlen(d) + 1];
		strcpy(id, d);
	}
	void operator=(Auto &a);
	friend ostream& operator<<(ostream& iesire, Auto &a);
	friend istream& operator>>(istream& intrare, Auto &a);


};

//clasa telematice // contine Auto,timpul,Locatia,viteza
class Telematice:public Auto,public Locatie
{
protected:
	double timp;
	int viteza;
	static int nrDate;
public:
	Telematice() :Auto() , Locatie()
	{
		timp = 0;
		viteza = 0;
	}
	Telematice(double timp, int viteza) :Auto(id), Locatie(numeLocatie,latitudine,longitudine)
	{
		this->timp = timp;
		this->viteza = viteza;
		nrDate++;
	}
	Telematice(Telematice &t) :Auto(t), Locatie(t)
	{
		timp = t.timp;
		viteza = t.viteza;
		nrDate++;
	}
	void afisare();
	void citire();
	double getTimp()
	{
		return timp;
	}
	int getViteza()
	{
		return viteza;
	}
	static int getNrDate()
	{
		return nrDate;
	}
	void setTimp(double x)
	{
		timp = x;
	}
	void setViteza(int x)
	{
		viteza = x;
	}
	void operator=(Telematice &t);
	friend ostream& operator<<(ostream& iesire, Telematice &t);
	friend istream& operator>>(istream& intrare, Telematice &t);
	friend ifstream& operator>>(ifstream& intrare, Telematice &t);
	friend ofstream& operator<<(ofstream& iesire, Telematice &t);
	void operator+(Telematice &t);

};

//clasa Engine
class Engine:public Auto
{
protected:
	char* typeEngine;
	int ccEngine;
	int speed;
	int avgSpeed;
	int avgSpeedUrban;
	int avgConsum;
	int avgConsumUrban;
	static int nrTypeGasoline;
	static int nrTypeDiesel;
	static int nrTypeHybrid;
public:
	Engine() :Auto()
	{
		typeEngine = new char[strlen("Empty") + 1];
		strcpy(typeEngine, "Empty");
		ccEngine = 0;
		speed = 0;
		avgSpeed = 0;
		avgSpeedUrban = 0;
		avgConsum = 0;
		avgConsumUrban = 0;
		if (strcmp(typeEngine, "gasoline") == 0)
			nrTypeGasoline++;
		if (strcmp(typeEngine, "diesel") == 0)
			nrTypeDiesel++;
		if (strcmp(typeEngine, "hybrid") == 0)
			nrTypeHybrid++;
	}
	Engine(char* typeEngine, int ccEngine, int speed, int avgSpeed, int avgSpeedUrban, int avgConsum, int avgConsumUrban) :Auto(id)
	{
		delete[] this->typeEngine;
		this->typeEngine = new char[strlen(typeEngine) + 1];
		strcpy(this->typeEngine, typeEngine);
		this->ccEngine = ccEngine;
		this->speed = speed;
		this->avgSpeed = avgSpeed;
		this->avgSpeedUrban = avgSpeedUrban;
		this->avgConsum = avgConsum;
		this->avgConsumUrban = avgConsumUrban;
		if (strcmp(typeEngine, "gasoline") == 0)
			nrTypeGasoline++;
		if (strcmp(typeEngine, "diesel") == 0)
			nrTypeDiesel++;
		if (strcmp(typeEngine, "hybrid") == 0)
			nrTypeHybrid++;
	}
	Engine(Engine &e) :Auto(e)
	{
		delete[] this->typeEngine;
		this->typeEngine = new char[strlen(e.typeEngine) + 1];
		strcpy(this->typeEngine, e.typeEngine);
		this->ccEngine = e.ccEngine;
		this->speed = e.speed;
		this->avgSpeed = e.avgSpeed;
		this->avgSpeedUrban = e.avgSpeedUrban;
		this->avgConsum = e.avgConsum;
		this->avgConsumUrban = e.avgConsumUrban;
		if (strcmp(typeEngine, "gasoline") == 0)
			nrTypeGasoline++;
		if (strcmp(typeEngine, "diesel") == 0)
			nrTypeDiesel++;
		if (strcmp(typeEngine, "hybrid") == 0)
			nrTypeHybrid++;
	}
	~Engine()
	{
		delete[] typeEngine;
	}

	void afisare();

	char* getTypeEngine()
	{
		return typeEngine;
	}
	void setTypeEngine(char* x)
	{
		if (strcmp(typeEngine, "gasoline") == 0)
			nrTypeGasoline--;
		if (strcmp(typeEngine, "diesel") == 0)
			nrTypeDiesel--;
		if (strcmp(typeEngine, "hybrid") == 0)
			nrTypeHybrid--;
		delete[] typeEngine;
		typeEngine = new char[strlen(x) + 1];
		strcpy(typeEngine, x);
	}
	int getCCEngine()
	{
		return ccEngine;
	}
	void setCCEngine(int x)
	{
		ccEngine = x;
	}
	int getSpeed()
	{
		return speed;
	}
	void setSpeed(int x)
	{
		speed = x;
	}
	int getAvgSpeed()
	{
		return avgSpeed;
	}
	void setAvgSpeed(int x)
	{
		avgSpeed = x;
	}
	int getAvgSpeedUrban()
	{
		return avgSpeedUrban;
	}
	void setAvgSpeedUrban(int x)
	{
		avgSpeedUrban = x;
	}
	int getAvgConsum()
	{
		return avgConsum;
	}
	void setAvgConsum(int x)
	{
		avgConsum = x;
	}
	int getAvgConsumUrban()
	{
		return avgConsumUrban;
	}
	void setAvgConsumUrban(int x)
	{
		avgConsumUrban = x;
	}
	static int getNrGasoline()
	{
		return nrTypeGasoline;
	}
	static int getNrDiesel()
	{
		return nrTypeDiesel;
	}
	static int getNrHybrid()
	{
		return nrTypeHybrid;
	}
	void citire();
	void operator=(Engine &e);
	friend ostream& operator<<(ostream& iesire, Engine &e);
	friend istream& operator>>(istream& intrare, Engine &e);
	friend ofstream& operator<<(ofstream& iesire, Engine &e);
	friend ifstream& operator>>(ifstream& intrare, Engine &e);
	void operator+(Engine &e);
	
};

//class Geofence
class Geofence
{
protected:
	char* typeZona;
	char* restriction;
	double lat1;
	double long1;
	double lat2;
	double long2;
	double radius;
	static int nrZone;
public:
	Geofence()
	{
		typeZona = new char[strlen("None") + 1];
		strcpy(typeZona, "None");
		restriction = new char[strlen("None") + 1];
		strcpy(restriction, "None");
		lat1 = 0; lat2 = 0;
		long1 = 0; long2 = 0;
		radius = 0;
	}
	Geofence(char* typeZona, char* restriction, double lat1, double long1, double lat2, double long2, double radius)
	{
		delete[] typeZona;
		this->typeZona = new char[strlen(typeZona) + 1];
		strcpy(this->typeZona, typeZona);
		delete[] restriction;
		this->restriction = new char[strlen(restriction) + 1];
		strcpy(this->restriction, restriction);
		this->lat1 =lat1; this->lat2 = lat2;
		this->long1 = long1; this->long2 = long2;
		this->radius = radius;
		if (strcmp(typeZona, "circle") == 0 || strcmp(typeZona, "rectangle") == 0)
			nrZone++;
	}
	Geofence(Geofence &g)
	{
		delete[] typeZona;
		typeZona = new char[strlen(g.typeZona) + 1];
		strcpy(typeZona, g.typeZona);
		delete[] restriction;
		restriction = new char[strlen(g.restriction) + 1];
		strcpy(restriction, g.restriction);
		lat1 = g.lat1; lat2 = g.lat2;
		long1 = g.long1; long2 = g.long2;
		radius = g.radius;
		if (strcmp(typeZona, "circle") == 0 || strcmp(typeZona, "rectangle") == 0)
			nrZone++;
	}
	~Geofence()
	{
		delete[] typeZona;
		delete[] restriction;
	}

	void afisare();
	void citire();

	char* getTypeZona()
	{
		return typeZona;
	}
	char* getRestriction()
	{
		return restriction;
	}
	double getLat1()
	{
		return lat1;
	}
	double getLat2()
	{
		return lat2;
	}
	double getLong1()
	{
		return long1;
	}
	double getLong2()
	{
		return long2;
	}
	double getRadius()
	{
		return radius;
	}
	static int getNrZone()
	{
		return nrZone;
	}
	void setTypeZone(char* x)
	{
		delete[] typeZona;
		typeZona = new char[strlen(x) + 1];
		strcpy(typeZona, x);
	}
	void setRestriction(char* x)
	{
		delete[] restriction;
		restriction = new char[strlen(x) + 1];
		strcpy(restriction, x);
	}
	void setLat1(double x)
	{
		lat1 = x;
	}
	void setLat2(double x)
	{
		lat2 = x;
	}
	void setLong1(double x)
	{
		long1 = x;
	}
	void setLong2(double x)
	{
		long2 = x;
	}
	void setRadius(double x)
	{
		radius= x;
	}

	void operator=(Geofence &g);

	friend ostream& operator<<(ostream& iesire, Geofence &g);
	friend istream& operator>>(istream& intrare, Geofence &g);
	friend ofstream& operator<<(ofstream& iesire, Geofence &g);
	friend ifstream& operator>>(ifstream& intrare, Geofence &g);
	void operator+(Geofence &g);

};

#endif