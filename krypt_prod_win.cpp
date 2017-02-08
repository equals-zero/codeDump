#include <iostream>
#include <string>

using namespace std;

bool CharCheck (string Eingabe)
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

string Verschluesseln (string Passwd, string Eingabe)
{
	int j = 0;
	string Hash;

	// Ueberpruefe auf ungueltige Zeichen
	if(CharCheck(Passwd) && CharCheck(Eingabe))
	{
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

string Entschluesseln (string Passwd, string Eingabe)
{
	int j = 0;
	string Hash;

	// Ueberpruefe auf ungueltige Zeichen
	if(CharCheck(Passwd) && CharCheck(Eingabe))
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

int main(int argc, char const *argv[])
{
	string Passwd = "abc";
	string Eingabe = "meineeingabe";

	cout << Verschluesseln(Passwd,Eingabe) << endl << endl;
	cout << Entschluesseln(Passwd,Verschluesseln(Passwd,Eingabe)) << endl;

	return 0;
}