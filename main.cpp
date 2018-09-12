#include<iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include "header.h"
using namespace std;

void main()
{
	
	

	cout << "             ---------GREEN DRIVING--------          "<<endl<<endl;

	Auto a1;
	Engine e1;
	Geofence g1;
	Locatie l1;
	Telematice t1;

	int ok = 0, mod,timpul=0,vitezaM=0,nr,valid=0;
	double sumaDistanta=0;
	
	
	cout << "Pass 1: deschidere fisiere" << endl;
		cout << endl << "Nota*: daca selectati 1 puteti schimba minim un fisier," << endl;
		cout << "iar celelalte le introduceti cu numele din fisierul sursa al proiectului." << endl;
		cout << "Ex: Auto: auto.txt, Geofence: nume_nou.txt, Telematics: telematics.txt" << endl<<endl;
		cout<<"Introduceti 0 daca vreti sa deschdeti fisierele existente sau 1 pentru fisiere noi: ";
		cin >> ok;
		//ok este variabila pentru a citi fisierul initial sau a creea un fisier nou
		// ok=0 fisier initial, ok=1 fisier nou


		// Deschiderea fisierelor,pasul 1
		if (ok != 0 && ok != 1)
			while (ok != 0 && ok != 1)  //Verifica daca ok este 0 sau 1
			{
				system("cls");  //cls sterge tot ce a fost afisat
				cout << "Error" << endl;
				cout << "Pas 1: deschidere fisiere" << endl << "Introduceti 0 daca vreti sa deschdeti fisierele existente sau 1 pentru fisiere noi: ";
				cin >> ok;
			}

		
		
		ifstream au("auto.txt");//citire Engine
		ofstream g("afisare_fisier.txt", ios_base::out);
		ifstream geo("geofence.txt");//citire Geofence
		ifstream tele("telematics.txt");//citire Telematice

		char s1[50],s2[50],s3[50];
		if (ok == 1)
		{
			cout << "Numele fisierului Auto: "; cin >> s1;
			cout << "Numele fisierului Geofence: "; cin >> s2;
			cout << "Numele fisierului Telematics: "; cin >> s3;
		}
		system("cls");
		cout << "             ---------GREEN DRIVING--------          " << endl << endl;
		ifstream au1(s1);//citire Engine
		ifstream geo1(s2);//citire Geofence
		ifstream tele1(s3);//citire Engine
		
		cout << "0-afisare date pe ecran" << endl;
		cout << "1-afisare date in fisier" << endl;
		cin >> mod;
		//mod este variabila pentru afisare in fisier sau afisare pe ecran, mod=0 afisare pe ecran, mod=1 afisare in fisier

		while (mod != 0 && mod != 1) //verifica daca variabila mod este 0 sau este 1
		{
			system("cls");
			cout << "             ---------GREEN DRIVING--------          " << endl << endl;
			cout << "Error"<<endl;
			cout << "0-afisare date pe ecran" << endl;
			cout << "1-afisare date in fisier" << endl;
			cin >> mod;
		}
		
		int k = 0,x;
				while (k == 0)
		{
			system("cls");
			cout << "             ---------GREEN DRIVING--------          " << endl << endl;
			cout << "Pas 2: Afisare date" << endl<<endl;
			cout << "1-Afisare date Auto"<<endl;
			cout << "2-Afisare date Telematice" << endl;
			cout << "3-Afisare date Geofence" << endl;			
			cout << "0-Iesire pas" << endl;
			cout << "Selecteaza 0,1,2 sau 3: ";
			cin >> x;
			//x este variabila in functie de care afisam un fisier

			//Afisare date din fisiere ,pasul 2

			if (x != 0 && x != 1&&x!=2&&x!=3)
				while (x != 0 && x != 1 && x != 2 && x != 3) //Verifica daca x este 0,1 ,2,3 si in caz contrat in citeste pe x pana devine 0,1,2 sau 3
				{
					system("cls");
					cout << "             ---------GREEN DRIVING--------          " << endl << endl;
					cout << "Error" << endl;
					getch();
					cout << "Pas 2: Afisare date" << endl<<endl;
					cout << "1-Afisare date Auto" << endl;
					cout << "2-Afisare date Telematice" << endl;
					cout << "3-Afisare date Geofence" << endl;
					cout << "0-Iesire pas" << endl;
					cout << "Selecteaza 0,1,2 sau 3: ";
					cin >> x;
				}

			if (x == 1)
			{
				system("cls");
				cout << "             ---------GREEN DRIVING--------          " << endl << endl;
				cout << endl << "Date Auto" << endl << endl;
			}
			if (x == 1 && ok == 0 && mod == 0)
			{
				au.seekg(0);  //repozitionare in fisier
				while (!au.eof())
				{
					au >> e1;
					cout << e1;
				}
			}
			if (x == 1 && ok == 0 && mod == 1)
			{
				au.seekg(0);
				while (!au.eof())
				{
					au >> e1;
					g << e1;
				}
				
			}
			if (x == 1 && ok == 1 && mod == 0)
			{
				au1.seekg(0);
				while (!au1.eof())
				{
					au1 >> e1;
					cout << e1;
				}
				
			}
			if (x == 1 && ok == 1 && mod == 1)
			{
				au1.seekg(0);
				while (!au1.eof())
				{
					au1 >> e1;
					g << e1;
				}
				
			}

			if (x == 2)
			{
				system("cls");
				cout << "             ---------GREEN DRIVING--------          " << endl << endl;
				cout << endl << "Date Telematice" << endl << endl;
			}
			if (x == 2 && ok == 0 && mod == 0)
			{
				tele.seekg(0);
				while (!tele.eof())
				{
					tele >> t1;
				}
				cout << "Prea mare dimensiunea fisierului pt a fii afisat.alegeti optiunea pentu afisare in fisier.";
				
				
			}
			if (x == 2 && ok == 0 && mod == 1)
			{
				tele.seekg(0);
				while (!tele.eof())
				{
					tele >> t1;
					g << t1;
				}
				
			}
			if (x == 2 && ok == 1 && mod == 0)
			{
				tele1.seekg(0);
				while (!tele1.eof())
				{
					tele1 >> t1;
					cout << t1;
				}
				
			}
			if (x == 2 && ok == 1 && mod == 1)
			{
				tele1.seekg(0);
				while (!tele1.eof())
				{
					tele1 >> t1;
					g << t1;
				}
				
			}

			if (x == 3)
			{
				system("cls");
				cout << "             ---------GREEN DRIVING--------          " << endl << endl;
				cout << endl << "Date Geofence" << endl << endl;
			}
			
			if (x == 3 && ok == 0 && mod == 0)
			{
				geo.clear();
				geo.seekg(0);
				geo >> g1;
				while ((strcmp(g1.getTypeZona(), "circle") == 0 || strcmp(g1.getTypeZona(), "rectangle") == 0))
				{
					cout << g1;
					geo >> g1;
				}
			}
			if (x == 3 && ok == 0 && mod == 1 )
			{
				geo.clear();
				geo.seekg(0);
				geo >> g1;
				while ((strcmp(g1.getTypeZona(), "circle") == 0 || strcmp(g1.getTypeZona(), "rectangle") == 0))
				{
					g << g1;
					geo >> g1;
				}
			}
			if (x == 3 && ok == 1 && mod == 0 )
			{
				geo1.clear();
				geo1.seekg(0);
				geo1 >> g1;
				while ((strcmp(g1.getTypeZona(), "circle") == 0 || strcmp(g1.getTypeZona(), "rectangle") == 0))
				{
					cout << g1;
					geo1 >> g1;
				}
			}
			if (x == 3 && ok == 1 && mod == 1)
			{
				geo1.clear();
				geo1.seekg(0);
				geo1 >> g1;
				while ((strcmp(g1.getTypeZona(), "circle") == 0 || strcmp(g1.getTypeZona(), "rectangle") == 0))
				{
					cout << g1;
					geo1 >> g1;
				}
			}

			getch();


			if (x == 0)
				k = 1;


		}

		system("cls");
		cout << "             ---------GREEN DRIVING--------          " << endl << endl;
		cout << "Pasul 3: Rapoarte " << endl;

		
		Telematice t2;
		au.clear();
		au.seekg(0);
		au >> e1;

		au1.clear();
		au1.seekg(0);
		au1 >> e1;
		// Afisare rapoarte,pasul 3
		if (ok == 0)
		{
			tele.clear();
			tele.seekg(0);
			tele >> t1;
			tele >> t2;	
			vitezaM = vitezaM + t1.getViteza() + t2.getViteza();
			nr=2;
			timpul = timpul + t1.getTimp() / 3600000000000 + t2.getTimp() / 3600000000000;
			while (!tele.eof())
			{
				while (strcmp(t2.getId(), t1.getId()) == 0)
				{
					sumaDistanta = sumaDistanta + sqrtf((t2.getLatitudinea() - t1.getLatitudinea())*(t2.getLatitudinea() - t1.getLatitudinea()) + (t2.getLongitudinea() - t1.getLongitudinea())*(t2.getLongitudinea() - t1.getLongitudinea()));
					t1 = t2;
					tele >> t2;
					vitezaM = vitezaM + t2.getViteza();
					nr++;
					timpul = timpul + t1.getTimp() / 1000000000;
					
				}
				
				cout << "Distanta parcursa de " << t1.getId() << " este de " << sumaDistanta << " km." << endl;
				cout << "Viteza medie cu care a mers " <<t1.getId()<<" este de "<<vitezaM/nr<<endl;
				cout << "Cantitatea de combustibil consumat de " << t1.getId() << " este de " << sumaDistanta/100*e1.getAvgConsum()<<" litrii."<<endl;
				cout << "Timpul in care " << t1.getId() << " a terminat traseul este de " << timpul/8640000 <<" ore."<< endl;
				sumaDistanta = 0;
				t1 = t2;
				tele >> t2;
				au >> e1;
				nr = 0;
				vitezaM = 0;
			}
				
		}
		if (ok == 1)
		{
			tele1.clear();
			tele1.seekg(0);
			tele1 >> t1;
			tele1 >> t2;
			vitezaM = vitezaM + t1.getViteza() + t2.getViteza();
			nr = 2;
			timpul = timpul + t1.getTimp() / 3600000000000 + t2.getTimp() / 3600000000000;
			while (!tele1.eof())
			{
				while (strcmp(t2.getId(), t1.getId()) == 0)
				{
					sumaDistanta = sumaDistanta + sqrtf((t2.getLatitudinea() - t1.getLatitudinea())*(t2.getLatitudinea() - t1.getLatitudinea()) + (t2.getLongitudinea() - t1.getLongitudinea())*(t2.getLongitudinea() - t1.getLongitudinea()));
					t1 = t2;
					tele1 >> t2;
					vitezaM = vitezaM + t2.getViteza();
					nr++;
					timpul = timpul + t1.getTimp() / 1000000000;

				}
				
				cout << "Distanta parcursa de " << t1.getId() << " este de " << sumaDistanta << " km." << endl;
				cout << "Viteza medie cu care a mers " << t1.getId() << " este de " << vitezaM / nr << endl;
				cout << "Cantitatea de combustibil consumat de " << t1.getId() << " este de " << sumaDistanta / 100 * e1.getAvgConsum() << " litrii." << endl;
				cout << "Timpul in care " << t1.getId() << " a terminat traseul este de " << timpul / 8640000 << " ore." << endl;
				cout << endl;
				sumaDistanta = 0;
				t1 = t2;
				tele1 >> t2;
				au1 >> e1;
				nr = 0;
				vitezaM = 0;
			}
		}
			
		getch();

		system("cls");
		cout << "             ---------GREEN DRIVING--------          " << endl << endl;
		cout << "Pasul 4: Zone Geofence " << endl<<endl;

		double c, c1, b, b1, x1, y;

		geo.clear(); //elibereaza bufferul
		geo.seekg(0); // repozitioneaza fisierul


		//Afisare timpul de intrare si timpul de iesire dintr-o anumita zona din geofence,pasul 4

		if (ok == 0)
		{
			while (!geo.eof())
			{
				geo >> g1;
				if (strcmp(g1.getTypeZona(), "rectangle") == 0) //pentru dreptunghi fisier initial
				{
					tele.clear();
					tele.seekg(0);
					c = g1.getLat1();
					c1 = g1.getLong1();
					b = g1.getLat2();
					b1 = g1.getLong2();
					while (!tele.eof())
					{
						tele >> t1;
						x1 = t1.getLatitudinea();
						y = t1.getLongitudinea();
						if (x1 <= c&&x1 >= b&&y <= b1&&y >= c1)
						{
							cout << "Vehiculul " << t1.getId() << " intara in zona geofence " << g1.getTypeZona() << " la timpul " << fixed << t1.getTimp() / 1000000000;
							tele >> t1;
							x1 = t1.getLatitudinea();
							y = t1.getLongitudinea();


							while (!tele.eof() && (x1 <= c&&x1 >= b&&y <= b1&&y >= c1))
							{
								tele >> t1;
								x1 = t1.getLatitudinea();
								y = t1.getLongitudinea();
							}
							cout << " si iese la timpul " << fixed << t1.getTimp() / 1000000000 << endl;
						}
					}
				}
				if (strcmp(g1.getTypeZona(), "circle") == 0) // pentru cerc fisier initial
				{
					tele.clear();
					tele.seekg(0);
					c = g1.getLat1() + g1.getRadius() / 100;
					c1 = g1.getLong1() - g1.getRadius() / 100;
					b = g1.getLat1() - g1.getRadius() / 100;
					b1 = g1.getLong1() + g1.getRadius() / 100;
					while (!tele.eof())  // citeste pana se termina fisierul
					{
						tele >> t1;
						x1 = t1.getLatitudinea();
						y = t1.getLongitudinea();
						if (x1 <= c&&x1 >= b&&y <= b1&&y >= c1)
						{
							cout << "Vehiculul " << t1.getId() << " intara in zona geofence " << g1.getTypeZona() << " la timpul " << fixed << t1.getTimp() / 1000000000;
							tele >> t1;
							x1 = t1.getLatitudinea();
							y = t1.getLongitudinea();


							while (!tele.eof() && (x1 <= c&&x1 >= b&&y <= b1&&y >= c1))
							{
								tele >> t1;
								x1 = t1.getLatitudinea();
								y = t1.getLongitudinea();
							}
							cout << " si iese la timpul " << fixed << t1.getTimp() / 1000000000 << endl;
						}
					}
				}
			}//end of while(!geo.eof())

		}//end of if(ok==0)
		
		geo1.clear();
		geo1.seekg(0);

		if (ok == 1)
		{
			while (!geo1.eof())
			{
				geo1 >> g1;
				if (strcmp(g1.getTypeZona(), "rectangle") == 0) //pentru dreptunghi fisier nou
				{
					tele1.clear();
					tele1.seekg(0);
					c = g1.getLat1();
					c1 = g1.getLong1();
					b = g1.getLat2();
					b1 = g1.getLong2();
					while (!tele1.eof())  //citeste pana se termina fisierul
					{
						tele1 >> t1;
						x1 = t1.getLatitudinea();
						y = t1.getLongitudinea();
						if (x1 <= c&&x1 >= b&&y <= b1&&y >= c1)
						{
							cout << "Vehiculul " << t1.getId() << " intara in zona geofence " << g1.getTypeZona() << " la timpul " << fixed << t1.getTimp() / 1000000000;
							tele1 >> t1;
							x1 = t1.getLatitudinea();
							y = t1.getLongitudinea();


							while (!tele1.eof() && (x1 <= c&&x1 >= b&&y <= b1&&y >= c1))
							{
								tele1 >> t1;
								x1 = t1.getLatitudinea();
								y = t1.getLongitudinea();
							}
							cout << " si iese la timpul " << fixed << t1.getTimp() / 1000000000 << endl;
						}
					}
				}
				if (strcmp(g1.getTypeZona(), "circle") == 0)  //pentru cerc fisier nou
				{
					tele1.clear();
					tele1.seekg(0);
					c = g1.getLat1() + g1.getRadius() / 100;
					c1 = g1.getLong1() - g1.getRadius() / 100;
					b = g1.getLat1() - g1.getRadius() / 100;
					b1 = g1.getLong1() + g1.getRadius() / 100;
					while (!tele1.eof())
					{
						tele1 >> t1;
						x1 = t1.getLatitudinea();
						y = t1.getLongitudinea();
						if (x1 <= c&&x1 >= b&&y <= b1&&y >= c1)
						{
							cout << "Vehiculul " << t1.getId() << " intara in zona geofence " << g1.getTypeZona() << " la timpul " << fixed << t1.getTimp() / 1000000000;
							tele1 >> t1;
							x1 = t1.getLatitudinea();
							y = t1.getLongitudinea();


							while (!tele1.eof() && (x1 <= c&&x1 >= b&&y <= b1&&y >= c1))
							{
								tele1 >> t1;
								x1 = t1.getLatitudinea();
								y = t1.getLongitudinea();
							}
							cout << " si iese la timpul " << fixed << t1.getTimp() / 1000000000 << endl;
						}
					}
				}
			}//end of while(!geo1.eof())

		}//end of if(ok==1)

		au.close();
		au1.close();
		geo.close();
		geo1.close();
		tele.close();
		tele1.close();

		getch();
}