#include <iostream>

using namespace std;

class Produkt {
	
	string nazwa;
	float cena;

public:

    Produkt(){}
	Produkt(string n, float c) {
		nazwa = n;
		cena = c;

	}
	string get_nazwa() {
		return nazwa;
	}
	float get_cena() {
		return cena;
	}

	void set_cena(float c) {
		cena = c;
	}
	void set_nazwa(string s) {
		nazwa = s;
	}
};
int main() {
	Produkt produkty[10];
	string n; float c;
	cout << "Witaj w programie!\n";
	for (int i = 0; i < 10; i++) {
		cout << "Podaj nazwe " << i+1 << " produktu: ";
		cin >> n;
		cout << "Podaj cene " << i+1 << " produktu: ";
		cin >> c;
		produkty[i].set_cena(c);
		produkty[i].set_nazwa(n);
	}

        for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            if (produkty[j].get_cena()>produkty[j+1].get_cena())
            {
                swap(produkty[j], produkty[j+1]);
            }
        }
    }

	for (int i = 0; i < 10; i++) {
		cout << "Produkt nr " << i + 1 << ": " << produkty[i].get_nazwa() << " | cena : " << produkty[i].get_cena() << endl;
	}


	return 0;
}