#include <iostream>
#include <string>

using namespace std;

class Krypto
{
private:
	string Passwd;
	string Input;

	bool charCheck (string Eingabe)
	{
		// Prueft eingabe auf unerwuenschte Zeichen
		for (int i = 0; i < Eingabe.length(); ++i)
		{
			if((int)Eingabe[i]>122 || (int)Eingabe[i]<97)
			{
				return false;
			}
		}
		return true;
	}

public:
	Krypto(){};
	Krypto(string Input_, string Passwd_)
	{
		setInput(Input);
		setPasswd(Passwd);
	}
	~Krypto(){};

	// Var Zugriff
	void setInput(string Input_)
	{
		Input = Input_;
	}
	string getInput()
	{
		return Input;
	}

	void setPasswd(string Passwd_)
	{
		Passwd = Passwd_;
	}
	string getPasswd()
	{
		return Passwd;
	}

	// Algorithmen
	// Verschluesseln
	string verschluesseln (string Passwd, string Eingabe)
	{
		int j = 0;
		string Hash;

		// Ueberpruefe auf ungueltige Zeichen
		if(charCheck(Passwd) && charCheck(Eingabe))
		{
			// Gehe Zeichen fuer Zeichen durch
			for (int i = 0; i < Eingabe.length(); ++i)
			{
				// Ascii ID der Eingabe + Passwortzeichen
				int NewCharID = (int)Eingabe[i] + ((int)Passwd[j]-96);

				// Wenn Buchstabe >Z zaehle wieder von A
				if(NewCharID > 122)
				{
					NewCharID = NewCharID - 26;
				}

				// Setze Passwort zurueck
				j++;
				if(j > Passwd.length()-1)
				{
					j = 0;
				}

				// Konvertiere IDs zu Chars und kombiniere zu String
				Hash = Hash + (char)NewCharID;
			}
		}
		else
		{
			cout << "Ungueltige Zeichen enthalten.";
		}

		return Hash;
	}

	// Entschluesseln
	string entschluesseln (string Passwd, string Eingabe)
	{
		int j = 0;
		string Hash;

		// Ueberpruefe auf ungueltige Zeichen
		if(charCheck(Passwd) && charCheck(Eingabe))
		{
			for (int i = 0; i < Eingabe.length(); ++i)
			{
				// Ascii ID der Eingabe + Passwortzeichen
				int NewCharID = (int)Eingabe[i] - ((int)Passwd[j]-96);

				// Wenn Buchstabe <A zaehle von Z
				if (NewCharID < 97)
				{
					NewCharID = NewCharID + 26;
				}

				// Setze Passwort zurueck
				j++;
				if(j > Passwd.length()-1)
				{
					j = 0;
				}

				// Konvertiere IDs zu Chars und kombiniere zu String
				Hash = Hash + (char)NewCharID;
			}	
		}
		else
		{
			cout << "Ungueltige Zeichen enthalten.";
		}

		return Hash;
	}
	
};

int main()
{
	string Text;
	string Passwort;

	Krypto BeispielInstanz = Krypto();
	cout << "Texteingabe: ";
	cin >> Text;
	cout << "Passwort: ";
	cin >> Passwort;
	cout << "Verschluesselt: " << BeispielInstanz.verschluesseln(Passwort,Text) << endl;
	cout << "Entschluesselt: " << BeispielInstanz.entschluesseln(Passwort,BeispielInstanz.verschluesseln(Passwort,Text)) << endl;
	return 0;
}