#include<iostream>
#include<fstream>
#include <iosfwd>
#include "header.h"
using namespace std;


//Crearea operatorilor pentru fiecare clasa in parte
//clasa Locatie

void Locatie::afisare()
{
	cout << "Numele locatiei: " << numeLocatie << " latitudinea: " << latitudine << " longitudinea: " << longitudine<<" nr locatii: "<<nrLocatii;
	cout << endl;
}

void Locatie::citire()
{
	cout << "Citeste numele locatiei: ";
	delete[] numeLocatie;
	numeLocatie = new char[50];
	cin >> numeLocatie;
	cout << "Citeste latitudinea: ";
	cin>>latitudine;
	cout << "Citeste longitudinea: ";
	cin>>longitudine;
}

void Locatie::operator=(Locatie &l)
{
	delete[] numeLocatie;
	numeLocatie = new char[strlen(l.numeLocatie) + 1];
	strcpy(numeLocatie, l.numeLocatie);
	latitudine = l.latitudine;
	longitudine = l.longitudine;
}

void Locatie::setNumeLocatie(char* loc)
{
	delete[] numeLocatie;
	numeLocatie = new char[strlen(loc)+1];
	strcpy(numeLocatie, loc);
}

void Locatie::setLatitudinea(long double lat)
{
	if (lat>=0)
		latitudine = lat;
}

void Locatie::setLongitudinea(double longi)
{
	if (longi >= 0)
		longitudine = longi;
}

char* Locatie::getNumeLocatie()
{
	return numeLocatie;
}

double Locatie::getLatitudinea()
{
	return latitudine;
}

double Locatie::getLongitudinea()
{
	return longitudine;
}

int Locatie::getNrLocatii()
{
	return nrLocatii;
}


std::ostream& operator<<(ostream& iesire, Locatie &l)
{
	iesire << "Numele locatiei: " << l.getNumeLocatie() << " latitudinea: " << l.getLatitudinea() << " longitudinea: " << l.getLongitudinea() << " nr locatii: " << Locatie::getNrLocatii();
	iesire << endl;
	return iesire;
}

std::istream& operator>>(istream& intrare, Locatie &l)
{
	cout << "Citeste numele locatiei: ";
	delete[] l.numeLocatie;
	l.numeLocatie = new char[50];
	cin >> l.numeLocatie;
	cout << "Citeste latitudinea: ";
	cin >> l.latitudine;
	cout << "Citeste longitudinea: ";
	cin >> l.longitudine;
	Locatie::nrLocatii++;	
	return intrare;
}

void Locatie::operator+(Locatie &l)
{
	latitudine = (latitudine + l.latitudine) / 2;
	longitudine = (longitudine + l.longitudine) / 2;
}

int Locatie::nrLocatii = 0;

//clasa Auto
void Auto::citire()
{
	cout << "Id: ";
	char s[50];
	strcpy(s, id);
	delete[] id;
	id = new char[50];
	cin >> id;
	if (strcmp(s, id) != 0)
		nrAuto++;
}

//clasa Auto
void Auto::afisare()
{
	cout << "Id-ul este " << getId() << " iar nr de Autoturisme este " <<getNrAuto();
	cout << endl;
}

void Auto::operator=(Auto &a)
{
	delete[] id;
	id = new char[strlen(a.id) + 1];
	strcpy(id, a.id);
}

ostream& operator<<(ostream& iesire, Auto &a)
{
	iesire << "Id-ul este " << a.getId() << " iar nr de Autoturisme este " << a.getNrAuto();
	iesire << endl;
	return iesire;
}

istream& operator>>(istream& intrare, Auto &a)
{
	cout << "Id: ";
	char s[50];
	strcpy(s,a.id);
	delete[] a.id;
	a.id = new char[50];
	cin >>a.id;
	if (strcmp(s, a.id) != 0)
		Auto::nrAuto++;
	return intrare;
}

int Auto::nrAuto = 0;

//clasa telematice
void Telematice::afisare()
{
	cout << "Id: " << Auto::id << endl << "Timpul curent: " << fixed << getTimp() << endl << "Latitudinea: " << Locatie::latitudine << endl;
	cout << "Longitudinea: " << Locatie::longitudine << endl << "Viteza: " << getViteza() << endl;
	
}

void Telematice::citire()
{
	cout << "Id: ";
	char s[50];
	strcpy(s, id);
	delete[] id;
	id = new char[50];
	cin >> id;
	if ((strcmp(id, "None") != 0) && (strcmp(id, s) != 0))
		nrAuto++;
	
	cout << "Timpul: ";
	cin >> timp;
	cout << "Latitudinea: ";
	cin >> latitudine;
	cout << "Longitudinea: ";
	cin >> longitudine;
	cout << "Viteza: ";
	cin >> viteza;
	nrDate++;
}

void Telematice::operator=(Telematice &t)
{
	if ((strcmp(id, "None") != 0) && (strcmp(id, t.id) != 0))
		nrAuto++;
	delete[] id;
	id = new char[strlen(t.id) + 1];
	strcpy(id, t.id);
	timp = t.timp;
	latitudine = t.latitudine;
	longitudine = t.longitudine;
	viteza = t.viteza;
	nrDate++;
}

ostream& operator<<(ostream& iesire, Telematice &t)
{
	iesire << "Id: " << t.Auto::id << endl << "Timpul curent: " << fixed << t.getTimp() << endl << "Latitudinea: " << t.Locatie::latitudine << endl;
	iesire << "Longitudinea: " << t.Locatie::longitudine << endl << "Viteza: " << t.getViteza() << endl;
	return iesire;
}

ofstream& operator<<(ofstream& iesire, Telematice &t)
{
	iesire << "Id: " << t.Auto::id << endl << "Timpul curent: " << fixed << t.getTimp() << endl << "Latitudinea: " << t.Locatie::latitudine << endl;
	iesire << "Longitudinea: " << t.Locatie::longitudine << endl << "Viteza: " << t.getViteza() << endl;
	return iesire;
}
istream& operator>>(istream& intrare, Telematice &t)
{
	cout << "Id: ";
	char s[50];
	strcpy(s, t.id);
	delete[] t.id;
	t.id = new char[50];
	intrare >> t.id;
	if ((strcmp(t.id, "None") != 0) && (strcmp(t.id, s) != 0))
		Auto::nrAuto++;

	cout << "Timpul: ";
	intrare >> t.timp;
	cout << "Latitudinea: ";
	intrare >> t.latitudine;
	cout << "Longitudinea: ";
	intrare >> t.longitudine;
	cout << "Viteza: ";
	intrare >> t.viteza;
	Telematice::nrDate++;
	return intrare;
}

ifstream& operator>>(ifstream& intrare, Telematice &t)
{
	char s[50];
	strcpy(s, t.id);
	delete[] t.id;
	t.id = new char[50];
	intrare >> t.id;
	if ((strcmp(t.id, "None") != 0) && (strcmp(t.id, s) != 0))
		Auto::nrAuto++;

	intrare >> t.timp;
	intrare >> t.latitudine;
	intrare >> t.longitudine;
	intrare >> t.viteza;
	Telematice::nrDate++;
	return intrare;
}

void Telematice::operator+(Telematice &t)
{
	timp = (timp + t.timp) / 2;
	viteza = (viteza + t.viteza) / 2;
}

int Telematice::nrDate = 0;

//clasa Engine

void Engine::afisare()
{
	cout <<"Id: "<<Auto::getId()<<endl<<"Type: " << getTypeEngine() << endl << "speed: " << getSpeed() << endl << "cc engine: " << getCCEngine() << endl;
	cout<< "avg consum urban: " << getAvgConsumUrban() << endl << "avg speed urban: " << getAvgSpeedUrban() << endl;
	cout << "avg consum: " << getAvgConsum() << endl << "avg speed: " << getAvgSpeed() << endl;
	
}

void Engine::citire()
{
	cout << "Id: ";
	char s[50];
	strcpy(s, id);
	delete[] this->id;
	id = new char[50];
	cin >> id;
	if ((strcmp(id, "None") != 0) && (strcmp(id, s) != 0))
		nrAuto++;

	cout << "Type Engine(gasoline,diesel sau hybrid): ";
	delete[] typeEngine;
	typeEngine = new char[50];
	cin >> typeEngine;
	cout << "Speed: "; cin >> speed;
	cout  << "CC Engine: "; cin >> ccEngine;
	cout << "Avg consum urban: "; cin >> avgConsumUrban;
	cout << "Avg speed urban: "; cin >> avgSpeedUrban;
	cout << "Avg consum: "; cin >> avgConsum;
	cout  << "Avg speed: "; cin >> avgSpeed;

	if (strcmp(typeEngine, "gasoline") == 0)
		Engine::nrTypeGasoline++;
	if (strcmp(typeEngine, "diesel") == 0)
		Engine::nrTypeDiesel++;
	if (strcmp(typeEngine, "hybrid") == 0)
		Engine::nrTypeHybrid++;
}

void Engine::operator=(Engine &e)
{
	delete[] id;
	id = new char[strlen(e.id)+1];
	strcpy(id, e.id);

	if (strcmp(typeEngine, "gasoline") == 0)
		nrTypeGasoline--;
	if (strcmp(typeEngine, "diesel") == 0)
		nrTypeDiesel--;
	if (strcmp(typeEngine, "hybrid") == 0)
		nrTypeHybrid--;
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

ostream& operator<<(ostream& iesire, Engine &e)
{
	iesire << "Id: " << e.Auto::getId() << endl<< "Type: " << e.getTypeEngine() << endl << "speed: " << e.getSpeed() << endl << "cc engine: " << e.getCCEngine() << endl;
	iesire << "avg consum urban: " << e.getAvgConsumUrban() << endl << "avg speed urban: " << e.getAvgSpeedUrban() << endl;
	iesire << "avg consum: " << e.getAvgConsum() << endl << "avg speed: " << e.getAvgSpeed() << endl;
	return iesire;
}

ofstream& operator<<(ofstream& iesire, Engine &e)
{
	iesire<<  e.Auto::getId() << endl <<  e.getTypeEngine() << endl << e.getSpeed() << endl << e.getCCEngine() << endl;
	iesire << e.getAvgConsumUrban() << endl << e.getAvgSpeedUrban() << endl;
	iesire << e.getAvgConsum() << endl << e.getAvgSpeed() << endl;
	return iesire;
}


istream& operator>>(istream& intrare, Engine &e)
{
	cout << "Id: ";
	char s[50];
	strcpy(s, e.id);
	delete[] e.id;
	e.id = new char[50];
	intrare >> e.id;
	if ((strcmp(e.id, "None") != 0) && (strcmp(e.id, s) != 0))
		Auto::nrAuto++;

	cout << "Type Engine: ";
	delete[] e.typeEngine;
	e.typeEngine = new char[50];
	intrare >> e.typeEngine;
	cout << "Speed: ";
	intrare >> e.speed;
	cout << "CC Engine: ";
	intrare >> e.ccEngine;
	cout << "Avg Consum Urban: ";
	intrare >> e.avgConsumUrban;
	cout << "Avg speed urban: ";
	intrare >> e.avgSpeedUrban;
	cout << "Avg Consum: ";
	intrare >> e.avgConsum;
	cout << "Avg speed: ";
	intrare >> e.avgSpeed;
	
	if (strcmp(e.typeEngine, "gasoline") == 0)
		Engine::nrTypeGasoline++;
	if (strcmp(e.typeEngine, "diesel") == 0)
		Engine::nrTypeDiesel++;
	if (strcmp(e.typeEngine, "hybrid") == 0)
		Engine::nrTypeHybrid++;
	return intrare;
}




ifstream& operator>>(ifstream& intrare, Engine &e)
{
	
	char s[50];
	strcpy(s, e.id);
	delete[] e.id;
	e.id = new char[50];
	intrare >> e.id;
	if ((strcmp(e.id, "None") != 0) && (strcmp(e.id, s) != 0))
		Auto::nrAuto++;

	delete[] e.typeEngine;
	e.typeEngine = new char[50];
	intrare >> e.typeEngine;
	intrare >> e.speed;
	intrare >> e.ccEngine;
	intrare >> e.avgConsumUrban;
	intrare >> e.avgSpeedUrban;
	intrare >> e.avgConsum;
	intrare >> e.avgSpeed;

	if (strcmp(e.typeEngine, "gasoline") == 0)
		Engine::nrTypeGasoline++;
	if (strcmp(e.typeEngine, "diesel") == 0)
		Engine::nrTypeDiesel++;
	if (strcmp(e.typeEngine, "hybrid") == 0)
		Engine::nrTypeHybrid++;
	return intrare;
}

void Engine::operator+(Engine &e)
{
	ccEngine = (ccEngine + e.ccEngine) / 2;
	speed = (speed + e.speed) / 2;
	avgSpeed = (avgSpeed + e.avgSpeed) / 2;
	avgSpeedUrban = (avgSpeedUrban + e.avgSpeedUrban) / 2;
	avgConsum = (avgConsum + e.avgConsum) / 2;
	avgConsumUrban = (avgConsumUrban + e.avgConsumUrban) / 2;
}


int Engine::nrTypeGasoline = 0;
int Engine::nrTypeDiesel = 0;
int Engine::nrTypeHybrid = 0;

//clasa Geofence

void Geofence::afisare()
{
	cout << "Tipul zonei: " << getTypeZona() <<endl<< "Restrictia: " << getRestriction()<<endl;
	if (strcmp(getTypeZona(), "circle") == 0)
		cout << "Centrul de coordonate: lat:" << getLat1() << " long: " << getLong1() << endl;
	if (strcmp(getTypeZona(), "rectangle") == 0)
	{
		cout << "Coordonate: colt. stanga sus: lat:" << getLat1() << " long: " << getLong1() << endl;
		cout << "Coordonate: colt. dreapta jos: lat:" << getLat2() << " long: " << getLong2() << endl;
	}
	if (strcmp(getTypeZona(), "rectangle") != 0 && strcmp(getTypeZona(), "circle") != 0)
		cout << "Tipul zonei necorespunzator."<<endl;
	cout << "Aria: " << getRadius()<<endl;
	cout << "Nr Zone: " << getNrZone()<<endl;
}

void Geofence::citire()
{
	cout << "Tipul zonei(circle sau rectangle): ";
	delete[] typeZona;
	typeZona = new char[50];
	cin >> typeZona;
	cout << "Resttrictia(red sau green): ";
	delete[] restriction;
	restriction = new char[50];
	cin >> restriction;

	if (strcmp(getTypeZona(), "circle") == 0)
	{
		cout << "Latitudinea: ";
		cin >> lat1;
		cout << "Longitudinea: ";
		cin >> long1;

	}
	if (strcmp(getTypeZona(), "rectangle") == 0)
	{
		cout << "Latitudinea stanga sus: ";
		cin >> lat1;
		cout << "Longitudinea stanga sus: ";
		cin >> long1;
		cout << "Latitudinea dreapta jos: ";
		cin >> lat2;
		cout << "Longitudinea dreapta jos: ";
		cin >> long2;
	}

	cout << "Aria: ";
	cin >> radius;

	if (strcmp(typeZona, "circle") == 0 || strcmp(typeZona, "rectangle") == 0)
		nrZone++;
}

void Geofence::operator=(Geofence &g)
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

ostream& operator<<(ostream& iesire, Geofence &g)
{
	iesire << "Tipul zonei: " << g.getTypeZona() << endl << "Restrictia: " << g.getRestriction() << endl;
	if (strcmp(g.getTypeZona(), "circle") == 0)
		iesire << "Centrul de coordonate: lat:" << g.getLat1() << " long: " << g.getLong1() << endl;
	if (strcmp(g.getTypeZona(), "rectangle") == 0)
	{
		iesire << "Coordonate: colt. stanga sus: lat:" << g.getLat1() << " long: " << g.getLong1() << endl;
		iesire << "Coordonate: colt. dreapta jos: lat:" << g.getLat2() << " long: " << g.getLong2() << endl;
	}
	if (strcmp(g.getTypeZona(), "rectangle") != 0 && strcmp(g.getTypeZona(), "circle") != 0)
		iesire << "Tipul zonei necorespunzator." << endl;
	iesire << "Aria: " << g.getRadius() << endl;
	return iesire;
}

ofstream& operator<<(ofstream& iesire, Geofence &g)
{
	iesire << "Tipul zonei: " << g.getTypeZona() << endl << "Restrictia: " << g.getRestriction() << endl;
	if (strcmp(g.getTypeZona(), "circle") == 0)
		iesire << "Centrul de coordonate: lat:" << g.getLat1() << " long: " << g.getLong1() << endl;
	if (strcmp(g.getTypeZona(), "rectangle") == 0)
	{
		iesire << "Coordonate: colt. stanga sus: lat:" << g.getLat1() << " long: " << g.getLong1() << endl;
		iesire << "Coordonate: colt. dreapta jos: lat:" << g.getLat2() << " long: " << g.getLong2() << endl;
	}
	if (strcmp(g.getTypeZona(), "rectangle") != 0 && strcmp(g.getTypeZona(), "circle") != 0)
		iesire << "Tipul zonei necorespunzator." << endl;
	iesire << "Aria: " << g.getRadius() << endl;
	return iesire;
}

istream& operator>>(istream& intrare, Geofence &g)
{
	cout << "Tipul zonei(circle sau rectangle): ";
	delete[] g.typeZona;
	g.typeZona = new char[50];
	intrare >> g.typeZona;
	cout << "Restrictia(red sau green): ";
	delete[] g.restriction;
	g.restriction = new char[50];
	intrare >> g.restriction;

	if (strcmp(g.getTypeZona(), "circle") == 0)
	{
		cout << "Latitudinea: ";
		intrare >> g.lat1;
		cout << "Longitudinea: ";
		intrare >> g.long1;

	}
	if (strcmp(g.getTypeZona(), "rectangle") == 0)
	{
		cout << "Latitudinea stanga sus: ";
		intrare >> g.lat1;
		cout << "Longitudinea stanga sus: ";
		intrare >> g.long1;
		cout << "Latitudinea dreapta jos: ";
		intrare >> g.lat2;
		cout << "Longitudinea dreapta jos: ";
		intrare >> g.long2;
	}

	cout << "Aria: ";
	intrare>> g.radius;

	if (strcmp(g.typeZona, "circle") == 0 || strcmp(g.typeZona, "rectangle") == 0)
		Geofence::nrZone++;
	
	return intrare;
}

ifstream& operator>>(ifstream& intrare, Geofence &g)
{
	delete[] g.typeZona;
	g.typeZona = new char[50];
	intrare >> g.typeZona;
	delete[] g.restriction;
	g.restriction = new char[50];
	intrare >> g.restriction;

	if (strcmp(g.getTypeZona(), "circle") == 0)
	{
		intrare >> g.lat1;
		intrare >> g.long1;

	}
	if (strcmp(g.getTypeZona(), "rectangle") == 0)
	{
		
		intrare >> g.lat1;
		intrare >> g.long1;
		intrare >> g.lat2;
		intrare >> g.long2;
	}

	
	intrare >> g.radius;

	if (strcmp(g.typeZona, "circle") == 0 || strcmp(g.typeZona, "rectangle") == 0)
		Geofence::nrZone++;
	intrare.ignore();
	return intrare;
}

void Geofence::operator+(Geofence &g)
{
	lat1 = (lat1 + g.lat1) / 2;
	lat2 = (lat2 + g.lat2) / 2;
	long1 = (long1 + g.long1) / 2;
	long2 = (long2 + g.long2);
	radius = (radius + g.radius);
}

int Geofence::nrZone = 0;