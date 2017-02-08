#include <string>
#include <iostream>

using namespace std;

class Fahrzeug
{
private:
	string Akz;
	string Esnr;
	string Pnr;

public:
	// Standardt Konstruktor, überladen
	Fahrzeug()
	{
	}

	Fahrzeug (string kAkz, string kEsnr, string kPnr)
	{
		setAkz(kAkz);
		setEsnr(kEsnr);
		setPnr(kPnr);
	}

	~Fahrzeug(){
	}

	// get/set Amtliches Kennzeichen
	string getAkz () 
	{
		return Akz;
	}
	void setAkz (string kAkz)
	{
		Akz = kAkz;
	}
	// get/set Schadstoffklasse
	string getEsnr ()
	{
		return Esnr;
	}
	void setEsnr (string kEsnr)
	{
		Esnr = kEsnr;
	}
	// get/set Perso Nummer
	string getPnr()
	{
		return Pnr;
	}
	void setPnr(string kPnr)
	{
		Pnr = kPnr;
	}
};

class Halter {
private:
	string Nn,Vn,Gd,Pnr;
public:
	Halter()
	{
	}
	Halter(string Nn_, string Vn_, string Gd_, string Pnr_)
	{
		Nn = Nn_;
		Vn = Vn_;
		Gd = Gd_;
		Pnr = Pnr_;
	}
	string getNn()
	{
		return Nn;
	}
	void setNn(string Nn_)
	{
		Nn = Nn_;
	}

	string getVn()
	{
		return Vn;
	}
	void setVn(string Vn_)
	{
		Vn = Vn_;
	}

	string getGd()
	{
		return Gd;
	}
	void setGd(string Gd_)
	{
		Gd = Gd_;
	}

	string getPnr()
	{
		return Pnr;
	}
	void setPnr(string Pnr_)
	{
		Pnr = Pnr_;
	}
};

int main()
{
	// Anzahl der Instanzen
	int fzAnzahl = 4;	// Anzahl Fahrzeuge	
	int fhAnzahl = 2;	// Anzahl Fahrzeughalter

	// Array mit Instanzen
	Fahrzeug* FzArray = new Fahrzeug[fzAnzahl];		// Fahrzeuge
	Halter* FhArray = new Halter[fhAnzahl];			// Fahrzeughalter

	// Beispielwerte Hardcoded
	// Fahrzeuge
	FzArray[0].setAkz("AK-XX-11");
	FzArray[0].setEsnr("1100");
	FzArray[0].setPnr("123123123");

	FzArray[1].setAkz("NR-YY-99");
	FzArray[1].setEsnr("9999");
	FzArray[1].setPnr("101010111");

	FzArray[2].setAkz("B-AA-1000");
	FzArray[2].setEsnr("1337");
	FzArray[2].setPnr("123123123");

	FzArray[3].setAkz("M-BL-65");
	FzArray[3].setEsnr("8888");
	FzArray[3].setPnr("222222222");

	// Halter
	FhArray[0].setVn("Karl");
	FhArray[0].setNn("Karlsson");
	FhArray[0].setGd("12.01.1950");
	FhArray[0].setPnr("123123123");

	FhArray[1].setVn("Peter");
	FhArray[1].setNn("Petersson");
	FhArray[1].setGd("12.01.1962");
	FhArray[1].setPnr("222222222");

	cout << "Fahrzeughalter + Kfz. Kennzeichen";

	// Erste Schleife - Durchlaufen aller Fahrzeughalter
	for (int i = 0; i < fhAnzahl; ++i)
	{
		cout << endl << FhArray[i].getVn() << " " << FhArray[i].getNn() << endl;

		// Zweite Schleife - Durchlaufe alle Fahrzeuge
		for (int x = 0; x < fzAnzahl; ++x)
		{
			// Vergleiche Perso Nummer
			if (FhArray[i].getPnr()==FzArray[x].getPnr())
			{
				cout << FzArray[x].getAkz() << " ";
			}
		}
	}
	
	delete[] FzArray;	// Lösche Arrays aus Speicher
	delete[] FhArray;

	cout << endl << "Durchgelaufen." << endl;

	return 0;
}