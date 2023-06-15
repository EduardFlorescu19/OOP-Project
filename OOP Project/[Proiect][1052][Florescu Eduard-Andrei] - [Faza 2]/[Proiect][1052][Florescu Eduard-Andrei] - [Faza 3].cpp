#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include <vector>
#include<map>
#include<list>
#include<set>
using namespace std;

class Antrenor {
	char* nume = NULL;
	int nrPersDinStaff = 0;
	int varstaStaff[100];

public:

	Antrenor()
	{
		//cout << "\nAPEL CONSTRUCTOR FARA PARAM";
		this->nume = 0;
		this->nrPersDinStaff = 0;
	}

	Antrenor(const char* nume, int nrPersDinStaff, int varstaStaff[])
	{
		//cout << "\nAPEL CONSTRUCTOR CU TOTI PARAM";
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrPersDinStaff = nrPersDinStaff;
		for (int i = 0; i < nrPersDinStaff; i++)
			this->varstaStaff[i] = varstaStaff[i];
	}

	Antrenor(const Antrenor& a)
	{
		//cout << "\nAPEL CONSTRUCTOR COPIERE";
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->nrPersDinStaff = a.nrPersDinStaff;
		for (int i = 0; i < a.nrPersDinStaff; i++)
			this->varstaStaff[i] = a.varstaStaff[i];
	}

	Antrenor& operator =(const Antrenor& a)
	{
		//cout << "\nAPEL OPERATOR EGAL";
		delete[] this->nume;
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->nrPersDinStaff = a.nrPersDinStaff;
		for (int i = 0; i < a.nrPersDinStaff; i++)
			this->varstaStaff[i] = a.varstaStaff[i];
		return *this;
	}

	friend ostream& operator<<(ostream& out, Antrenor a)
	{
		//out << "\nAPEL OPERATOR <<";
		out << "\nNUME: " << a.nume;
		out << "\nNr Pers din staff: " << a.nrPersDinStaff;
		out << "\nVarsta Staff: ";
		for (int i = 0; i < a.nrPersDinStaff; i++)
			out << a.varstaStaff[i] << " ";
		return out;
	}

	friend istream& operator>> (istream& in, Antrenor& a)
	{
		//cout << "\nAPEL OPERATOR >>";
		cout << "\nDa nume antrenor: ";
		char buffer[50];
		in.getline(buffer, 50);
		delete[] a.nume;
		a.nume = new char[strlen(buffer) + 1];
		strcpy(a.nume, buffer);
		cout << "\nDa numar pers din staff: ";
		in >> a.nrPersDinStaff;
		cout << "\nDa varste staff: ";
		for (int i = 0; i < a.nrPersDinStaff; i++)
			in >> a.varstaStaff[i];
		return in;
	}

	const char* getNume()
	{
		return this->nume;
	}

	int getNrPersDinStaff()
	{
		return this->nrPersDinStaff;
	}

	int* getVarstaStaff()
	{
		return this->varstaStaff;
	}

	void setNume(const char* nume)
	{
		delete[] this->nume;
		if (nume != NULL) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else this->nume = NULL;
	}

	void setNrPersDinStaff(int nr)
	{
		if (nr > 0)
			this->nrPersDinStaff = nr;
		else this->nrPersDinStaff = 0;
	}

	void setVarstaStaff(int* varsta, int nr)
	{
		if (nr > 0 && varsta != NULL) {
			for (int i = 0; i < nr; i++)
				this->varstaStaff[i] = varsta[i];
		}
	}

	void afisare()
	{
		cout << "\nNume Antrenor: " << this->nume;
		cout << "\nNr Persoane din staff: " << this->nrPersDinStaff;
		cout << "\nVarsta Staff: ";
		for (int i = 0; i < this->nrPersDinStaff; i++)
			cout << this->varstaStaff[i] << " ";
	}

	~Antrenor()
	{
		//cout << "\nDESTRUCTOR-Antrenor";
		delete[] this->nume;
	}

	int& operator[](int index)
	{
		//cout << "\nAPEL OPERATOR []";
		if (index >= 0 && index < this->nrPersDinStaff)
		{
			return this->varstaStaff[index];
		}
		else
		{
			throw exception();
		}
	}

	Antrenor operator+ (int x) {
		Antrenor copie = *this;
		for (int i = 0; i < copie.nrPersDinStaff; i++)
			copie.varstaStaff[copie.nrPersDinStaff] = x;
		copie.nrPersDinStaff++;
		return copie;
	}

	Antrenor& operator++() {

		for (int i = 0; i < this->nrPersDinStaff; i++) {
			this->varstaStaff[this->nrPersDinStaff] = 0;
		}

		this->nrPersDinStaff++;

		return *this;
	}

	Antrenor operator++(int)
	{
		Antrenor copie = *this;
		for (int i = 0; i < this->nrPersDinStaff; i++) {
			this->varstaStaff[this->nrPersDinStaff] = 25;
		}
		this->nrPersDinStaff++;

		return copie;
	}

	bool operator!()
	{
		if (this->nrPersDinStaff == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(Antrenor a)
	{
		return this->nrPersDinStaff >= a.nrPersDinStaff;
	}

	operator int()
	{
		return this->varstaStaff[this->nrPersDinStaff - 1];
	}

	bool operator == (Antrenor a)
	{
		return _strcmpi(this->nume, a.nume) == 0;
	}


	float calculareVarstaMedie()
	{
		float m = 0;
		if (this->nrPersDinStaff > 0) {
			for (int i = 0; i < this->nrPersDinStaff; i++)
			{
				m += this->varstaStaff[i];
			}
			m /= this->nrPersDinStaff;
		}

		return m;
	}

	friend ofstream& operator<< (ofstream& out, Antrenor sursa)
	{
	 
		out << sursa.nume << endl;
		out << sursa.nrPersDinStaff << endl;
		for (int i = 0; i < sursa.nrPersDinStaff; i++) {
			out << sursa.varstaStaff[i] << endl;
		}

		return out;
	}

	friend ifstream& operator>> (ifstream& in, Antrenor& sursa)  
	{
		
		char buffer[200];
		in.getline(buffer, 200);
		delete[] sursa.nume;  
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer); 
		in >> sursa.nrPersDinStaff;
		for (int i = 0; i < sursa.nrPersDinStaff; i++)
		{

			in >> sursa.varstaStaff[i];
		}


		return in;
	}

	void writeToFile(ofstream& out)
	{

		int lung = strlen(this->nume) + 1;
		out.write((char*)&lung, sizeof(int));
		out.write(nume, sizeof(char) * lung);

		out.write((char*)&this->nrPersDinStaff, sizeof(this->nrPersDinStaff));
		for (int i = 0; i < this->nrPersDinStaff; i++) {

			out.write((char*)&this->varstaStaff[i], sizeof(this->varstaStaff[i]));
		}

	}

	void readFromFile(ifstream& in)
	{

		int lung;
		in.read((char*)&lung, sizeof(int));
		char a[1000];
		in.read(a, lung);
		this->setNume(a);

		in.read((char*)&this->nrPersDinStaff, sizeof(this->nrPersDinStaff));
		for (int i = 0; i < this->nrPersDinStaff; i++) {
			in.read((char*)&this->varstaStaff[i], sizeof(this->varstaStaff[i]));

		}

	}

};

class Jucator {

	int nrMeciuri = 0;
	char* nume = NULL;
	int nrGoluri[100];

public:

	Jucator()
	{
		//cout << "\nAPEL CONSTRUCTOR FARA PARAM";
		this->nume = 0;
		this->nrMeciuri = 0;
	}

	Jucator(const char* nume, int nrMeciuri, int nrGoluri[])
	{
		//cout << "\nAPEL CONSTRUCTOR CU TOTI PARAM";
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrMeciuri = nrMeciuri;
		for (int i = 0; i < nrMeciuri; i++)
			this->nrGoluri[i] = nrGoluri[i];
	}

	Jucator(const Jucator& j)
	{
		//cout << "\nAPEL CONSTRUCTOR COPIERE";
		this->nume = new char[strlen(j.nume) + 1];
		strcpy(this->nume, j.nume);
		this->nrMeciuri = j.nrMeciuri;
		for (int i = 0; i < j.nrMeciuri; i++)
			this->nrGoluri[i] = j.nrGoluri[i];
	}

	Jucator& operator=(const Jucator& j)
	{
		//cout << "\nAPEL OPERATOR =";
		delete[] this->nume;
		this->nume = new char[strlen(j.nume) + 1];
		strcpy(this->nume, j.nume);
		this->nrMeciuri = j.nrMeciuri;
		for (int i = 0; i < j.nrMeciuri; i++)
			this->nrGoluri[i] = j.nrGoluri[i];
		return *this;
	}

	friend ostream& operator<<(ostream& out, Jucator j)
	{
		//out << "\nAPEL OPERATOR <<";
		out << "\nNume Jucator: " << j.nume;
		out << "\nNr Meciuri Jucate: " << j.nrMeciuri;
		out << "\nNr Goluri: ";
		for (int i = 0; i < j.nrMeciuri; i++)
			out << j.nrGoluri[i] << " ";
		return out;
	}

	friend istream& operator>> (istream& in, Jucator& j)
	{
		//cout << "\nAPEL OPERATOR >>";
		cout << "\nDa nume jucator: ";
		char buffer[50];
		in.ignore();
		delete[] j.nume;
		in.getline(buffer, 50);
		j.nume = new char[strlen(buffer) + 1];
		strcpy(j.nume, buffer);

		cout << "\nDa numar meciuri jucate: ";
		in >> j.nrMeciuri;
		cout << "\nDa numar goluri marcate pe meci: ";
		for (int i = 0; i < j.nrMeciuri; i++)
			in >> j.nrGoluri[i];
		return in;
	}

	const char* getNume()
	{
		return this->nume;
	}

	int getNrMeciuri()
	{
		return this->nrMeciuri;
	}

	int* getnrGoluri()
	{
		return this->nrGoluri;
	}

	void setNume(const char* nume)
	{
		delete[] this->nume;
		if (nume != NULL)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else this->nume = NULL;
	}

	void setNrMeciuri(int nr)
	{
		if (nr > 0)
			this->nrMeciuri = nr;
		else this->nrMeciuri = 0;
	}

	void setNrGoluri(int* gol, int nr)
	{
		if (nr > 0 && gol != NULL) {
			for (int i = 0; i < nr; i++)
				this->nrGoluri[i] = gol[i];
		}
	}

	void afisare()
	{
		cout << "\nNume Jucator: " << this->nume;
		cout << "\nNr Meciuri Jucate: " << this->nrMeciuri;
		cout << "\nNr Goluri: ";
		for (int i = 0; i < this->nrMeciuri; i++)
			cout << this->nrGoluri[i] << " ";
	}

	~Jucator()
	{
		//cout << "\nDESTRUCTOR - Jucator";
		delete[] this->nume;
	}

	int& operator[](int index)
	{
		//cout << "\nAPEL OPERATOR []";
		if (index >= 0 && index < this->nrMeciuri)
		{
			return this->nrGoluri[index];
		}
		else
		{
			throw exception();
		}
	}

	Jucator operator+ (int x) {
		Jucator copie = *this;
		for (int i = 0; i < copie.nrMeciuri; i++)
			copie.nrGoluri[copie.nrMeciuri] = x;
		copie.nrMeciuri++;
		return copie;
	}

	Jucator& operator++() {

		for (int i = 0; i < this->nrMeciuri; i++) {
			this->nrGoluri[this->nrMeciuri] = 0;
		}

		this->nrMeciuri++;

		return *this;
	}

	Jucator operator++(int)
	{
		Jucator copie = *this;
		for (int i = 0; i < this->nrMeciuri; i++) {
			this->nrGoluri[this->nrMeciuri] = 25;
		}
		this->nrMeciuri++;

		return copie;
	}

	bool operator!()
	{
		if (this->nrMeciuri == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(Jucator j)
	{
		return this->nrMeciuri >= j.nrMeciuri;
	}

	operator int()
	{
		return this->nrGoluri[this->nrMeciuri - 1];
	}

	bool operator == (Jucator j)
	{
		return _strcmpi(this->nume, j.nume) == 0;
	}

	float calculareGoluriMedie()
	{
		float m = 0;
		if (this->nrMeciuri > 0) {
			for (int i = 0; i < this->nrMeciuri; i++)
			{
				m += this->nrGoluri[i];
			}
			m /= this->nrMeciuri;
		}

		return m;
	}

	friend ofstream& operator<< (ofstream& out, Jucator sursa)
	{

		out << sursa.nume << endl;
		out << sursa.nrMeciuri << endl;
		for (int i = 0; i < sursa.nrMeciuri; i++) {
			out << sursa.nrGoluri[i] << endl;
		}

		return out;
	}

	friend ifstream& operator>> (ifstream& in, Jucator& sursa)
	{
		
		char buffer[200];
		in.getline(buffer, 200);
		delete[] sursa.nume;
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);
		in >> sursa.nrMeciuri;
		for (int i = 0; i < sursa.nrMeciuri; i++)
		{

			in >> sursa.nrGoluri[i];
		}


		return in;
	}

	friend bool operator<(const Jucator& j1, const Jucator& j2) {
		return j1.nrMeciuri < j2.nrMeciuri;
	}

	void writeToFile(ofstream& out)
	{

		int lung = strlen(this->nume) + 1;
		out.write((char*)&lung, sizeof(int)); 
		out.write(nume, sizeof(char) * lung);

		out.write((char*)&this->nrMeciuri, sizeof(this->nrMeciuri));
		for (int i = 0; i < this->nrMeciuri; i++) {

			out.write((char*)&this->nrGoluri[i], sizeof(this->nrGoluri[i]));
		}

	}
	
	void readFromFile(ifstream& in)
	{
		
		int lung;
		in.read((char*)&lung, sizeof(int));  
		char j[1000];
		in.read(j, lung);
		this->setNume(j);

		in.read((char*)&this->nrMeciuri, sizeof(this->nrMeciuri));
		for (int i = 0; i < this->nrMeciuri; i++) {
			in.read((char*)&this->nrGoluri[i], sizeof(this->nrGoluri[i]));

		}

	}

};


class Echipa {

	const int anInfiintare;
	char* nume = NULL;
	int nrTransferuri = 0;
	int sumaIncasata[100];

public:

	Echipa() :anInfiintare(1899)
	{
		//cout << "\nAPEL CONSTRUCTOR FARA PARAM";
		this->nume = 0;
		this->nrTransferuri = 0;
	}

	Echipa(int an, const char* nume, int nrTransferuri, int sumaIncasata[]) :anInfiintare(an)
	{
		//cout << "\nAPEL CONSTRUCTOR CU TOTI PARAM";
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrTransferuri = nrTransferuri;
		for (int i = 0; i < nrTransferuri; i++)
			this->sumaIncasata[i] = sumaIncasata[i];
	}

	Echipa(const Echipa& e) :anInfiintare(e.anInfiintare)
	{
		//cout << "\nAPEL CONSTRUCTOR COPIERE";
		this->nume = new char[strlen(e.nume) + 1];
		strcpy(this->nume, e.nume);
		this->nrTransferuri = e.nrTransferuri;
		for (int i = 0; i < e.nrTransferuri; i++)
			this->sumaIncasata[i] = e.sumaIncasata[i];
	}

	Echipa& operator=(const Echipa& e)
	{
		//cout << "\nAPEL OPERATOR EGAL";
		delete[] this->nume;
		this->nume = new char[strlen(e.nume) + 1];
		strcpy(this->nume, e.nume);
		this->nrTransferuri = e.nrTransferuri;
		for (int i = 0; i < e.nrTransferuri; i++)
			this->sumaIncasata[i] = e.sumaIncasata[i];
		return *this;
	}

	friend istream& operator>> (istream& in, Echipa& e)
	{
		//cout << "\nAPEL OPERATOR >>";
		cout << "\nDa nume echipa: ";
		char buffer[200];
		in.ignore();
		in.getline(buffer, 199);
		delete[] e.nume;
		e.nume = new char[strlen(buffer) + 1];
		strcpy(e.nume, buffer);
		cout << "\nDa numar transferuri: ";
		in >> e.nrTransferuri;
		cout << "\nDa suma incasata pe transfer: ";
		for (int i = 0; i < e.nrTransferuri; i++)
			in >> e.sumaIncasata[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, Echipa e)
	{

		//out << "\nAPEL OPERATOR <<";
		out << "\nNume Echipa: " << e.nume;
		out << "\nAn infiintare: " << e.anInfiintare;
		out << "\nNr Transferuri: " << e.nrTransferuri;
		out << "\nSuma incasata: ";
		for (int i = 0; i < e.nrTransferuri; i++)
			cout << e.sumaIncasata[i] << " ";
		return out;
	}

	int getanInfiintare()
	{
		return this->anInfiintare;
	}

	const char* getNume()
	{
		return this->nume;
	}

	int getNrTransf()
	{
		return this->nrTransferuri;
	}

	int* getSumaIncasata()
	{
		return this->sumaIncasata;
	}

	void setNume(const char* nume)
	{
		delete[] this->nume;
		if (nume != NULL) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else this->nume = NULL;
	}

	void setNrTransferuri(int nr)
	{
		if (nr > 0)
			this->nrTransferuri = nr;
		else this->nrTransferuri = 0;
	}

	void setSumaIncasata(int* sume, int nr)
	{
		if (nr > 0 && sume != NULL) {
			for (int i = 0; i < nr; i++)
				this->sumaIncasata[i] = sume[i];
		}
	}

	void afisare()
	{

		cout << "\nNume Echipa: " << this->nume;
		cout << "\nAn infiintare: " << this->anInfiintare;
		cout << "\nNr Transferuri: " << this->nrTransferuri;
		cout << "\nSuma incasata: ";
		for (int i = 0; i < this->nrTransferuri; i++)
			cout << this->sumaIncasata[i] << " ";
	}

	~Echipa()
	{
		//cout << "\nDESTRUCTOR - Echipa";
		delete[] this->nume;
	}

	int& operator[](int index)
	{
		//cout << "\nAPEL OPERATOR []";
		if (index >= 0 && index < this->nrTransferuri)
		{
			return this->sumaIncasata[index];
		}
		else
		{
			throw exception();
		}
	}

	Echipa operator+ (int x) {
		Echipa copie = *this;
		for (int i = 0; i < copie.nrTransferuri; i++)
			copie.sumaIncasata[copie.nrTransferuri] = x;
		copie.nrTransferuri++;
		return copie;
	}

	Echipa& operator++() {

		for (int i = 0; i < this->nrTransferuri; i++) {
			this->sumaIncasata[this->nrTransferuri] = 0;
		}

		this->nrTransferuri++;

		return *this;
	}

	Echipa operator++(int)
	{
		Echipa copie = *this;
		for (int i = 0; i < this->nrTransferuri; i++) {
			this->sumaIncasata[this->nrTransferuri] = 25;
		}
		this->nrTransferuri++;

		return copie;
	}

	bool operator!()
	{
		if (this->nrTransferuri == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(Echipa e)
	{
		return this->nrTransferuri >= e.nrTransferuri;
	}

	operator int()
	{
		return this->sumaIncasata[this->nrTransferuri - 1];
	}

	bool operator == (Echipa e)
	{
		return _strcmpi(this->nume, e.nume) == 0;
	}

	float calculareSumaMedie()
	{
		float m = 0;
		if (this->nrTransferuri > 0) {
			for (int i = 0; i < this->nrTransferuri; i++)
			{
				m += this->sumaIncasata[i];
			}
			m /= this->nrTransferuri;
		}

		return m;
	}

	friend ofstream& operator<< (ofstream& out, Echipa sursa)
	{

		out << sursa.nume << endl;
		out << sursa.nrTransferuri << endl;
		for (int i = 0; i < sursa.nrTransferuri; i++) {
			out << sursa.sumaIncasata[i] << endl;
		}

		return out;
	}

	friend ifstream& operator>> (ifstream& in, Echipa& sursa)
	{

		char buffer[200];
		in.getline(buffer, 200);
		delete[] sursa.nume;
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);
		in >> sursa.nrTransferuri;
		for (int i = 0; i < sursa.nrTransferuri; i++)
		{

			in >> sursa.sumaIncasata[i];
		}


		return in;
	}

	void writeToFile(ofstream& out)
	{

		int lung = strlen(this->nume) + 1;
		out.write((char*)&lung, sizeof(int));
		out.write(nume, sizeof(char) * lung);

		out.write((char*)&this->nrTransferuri, sizeof(this->nrTransferuri));
		for (int i = 0; i < this->nrTransferuri; i++) {

			out.write((char*)&this->sumaIncasata[i], sizeof(this->sumaIncasata[i]));
		}

	}

	void readFromFile(ifstream& in)
	{

		int lung;
		in.read((char*)&lung, sizeof(int));
		char e[1000];
		in.read(e, lung);
		this->setNume(e);

		in.read((char*)&this->nrTransferuri, sizeof(this->nrTransferuri));
		for (int i = 0; i < this->nrTransferuri; i++) {
			in.read((char*)&this->sumaIncasata[i], sizeof(this->sumaIncasata[i]));

		}

	}
};


class Campionat {

	char* numeCampionat = NULL;
	int nrEchipe = 0;
	int victoriiPeSezon[100];
public:

	Campionat()
	{
		//cout << "\nAPEL CONSTRUCTOR FARA PARAM";
		this->numeCampionat = 0;
		this->nrEchipe = 0;
	}

	Campionat(const char* numeCampionat, int nrEchipe, int victoriiPeSezon[])
	{
		//cout << "\nAPEL CONSTRUCTOR CU TOTI PARAM";
		this->numeCampionat = new char[strlen(numeCampionat) + 1];
		strcpy(this->numeCampionat, numeCampionat);
		this->nrEchipe = nrEchipe;
		for (int i = 0; i < nrEchipe; i++)
			this->victoriiPeSezon[i] = victoriiPeSezon[i];
	}

	Campionat(const Campionat& c)
	{
		//cout << "\nAPEL CONSTRUCTOR COPIERE";
		this->numeCampionat = new char[strlen(c.numeCampionat) + 1];
		strcpy(this->numeCampionat, c.numeCampionat);
		this->nrEchipe = c.nrEchipe;
		for (int i = 0; i < c.nrEchipe; i++)
			this->victoriiPeSezon[i] = c.victoriiPeSezon[i];
	}

	Campionat& operator =(const Campionat& c)
	{
		//cout << "\nAPEL OPERATOR =";
		delete[] this->numeCampionat;
		this->numeCampionat = new char[strlen(c.numeCampionat) + 1];
		strcpy(this->numeCampionat, c.numeCampionat);
		this->nrEchipe = c.nrEchipe;
		for (int i = 0; i < c.nrEchipe; i++)
			this->victoriiPeSezon[i] = c.victoriiPeSezon[i];
		return *this;
	}

	friend ostream& operator <<(ostream& out, Campionat c)
	{
		//out << "\nAPEL OPERATOR <<";
		out << "\nNume Campionat: " << c.numeCampionat;
		out << "\nNr Echipe: " << c.nrEchipe;
		out << "\nVictorii pe sezon: ";
		for (int i = 0; i < c.nrEchipe; i++)
			out << c.victoriiPeSezon[i] << " ";
		return out;
	}

	friend istream& operator>> (istream& in, Campionat& c)
	{
		//cout << "\nAPEL OPERATOR >>";
		cout << "\nDa nume campionat: ";
		char buffer[200];
		in.ignore();
		in.getline(buffer, 199);
		delete[] c.numeCampionat;
		c.numeCampionat = new char[strlen(buffer) + 1];
		strcpy(c.numeCampionat, buffer);
		cout << "\nDa numar echipe: ";
		in >> c.nrEchipe;
		cout << "\nDa numar victorii pe sez: ";
		for (int i = 0; i < c.nrEchipe; i++)
			in >> c.victoriiPeSezon[i];
		return in;
	}

	const char* getNume()
	{
		return this->numeCampionat;
	}

	int getNrEchipe()
	{
		return this->nrEchipe;
	}

	int* getVicPeSez()
	{
		return this->victoriiPeSezon;
	}

	void setNume(const char* nume)
	{
		delete[] this->numeCampionat;
		if (nume != NULL) {
			this->numeCampionat = new char[strlen(nume) + 1];
			strcpy(this->numeCampionat, nume);
		}
		else this->numeCampionat = NULL;
	}

	void setNrEchipe(int nr)
	{
		if (nr > 0)
			this->nrEchipe = nr;
		else this->nrEchipe = 0;
	}

	void setVicPeSez(int* vic, int nr)
	{
		if (nr > 0 && vic != NULL) {
			for (int i = 0; i < nr; i++)
				this->victoriiPeSezon[i] = vic[i];
		}
	}

	void afisare()
	{
		cout << "\nNume Campionat: " << this->numeCampionat;
		cout << "\nNr Echipe: " << this->nrEchipe;
		cout << "\nVictorii pe sezon: ";
		for (int i = 0; i < this->nrEchipe; i++)
			cout << this->victoriiPeSezon[i] << " ";
	}

	~Campionat()
	{
		//cout << "\nDESTRUCTOR - CAMPIONAT";
		delete[] this->numeCampionat;
	}

	int& operator[](int index)
	{
		//cout << "\nAPEL OPERATOR []";
		if (index >= 0 && index < this->nrEchipe)
		{
			return this->victoriiPeSezon[index];
		}
		else
		{
			throw exception();
		}
	}

	Campionat operator+ (int x) {
		Campionat copie = *this;
		for (int i = 0; i < copie.nrEchipe; i++)
			copie.victoriiPeSezon[copie.nrEchipe] = x;
		copie.nrEchipe++;
		return copie;
	}

	Campionat& operator++() {

		for (int i = 0; i < this->nrEchipe; i++) {
			this->victoriiPeSezon[this->nrEchipe] = 0;
		}

		this->nrEchipe++;

		return *this;
	}

	Campionat operator++(int)
	{
		Campionat copie = *this;
		for (int i = 0; i < this->nrEchipe; i++) {
			this->victoriiPeSezon[this->nrEchipe] = 25;
		}
		this->nrEchipe++;

		return copie;
	}

	bool operator!()
	{
		if (this->nrEchipe == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(Campionat c)
	{
		return this->nrEchipe >= c.nrEchipe;
	}

	operator int()
	{
		return this->victoriiPeSezon[this->nrEchipe - 1];
	}

	bool operator == (Campionat c)
	{
		return _strcmpi(this->numeCampionat, c.numeCampionat) == 0;
	}

	float calculareMedieVictorii()
	{
		float m = 0;
		if (this->nrEchipe > 0) {
			for (int i = 0; i < this->nrEchipe; i++)
			{
				m += this->victoriiPeSezon[i];
			}
			m /= this->nrEchipe;
		}

		return m;
	}

	friend ofstream& operator<< (ofstream& out, Campionat sursa)
	{

		out << sursa.numeCampionat << endl;
		out << sursa.nrEchipe << endl;
		for (int i = 0; i < sursa.nrEchipe; i++) {
			out << sursa.victoriiPeSezon[i] << endl;
		}

		return out;
	}

	friend ifstream& operator>> (ifstream& in, Campionat& sursa)
	{

		char buffer[200];
		in.getline(buffer, 200);
		delete[] sursa.numeCampionat;
		sursa.numeCampionat = new char[strlen(buffer) + 1];
		strcpy(sursa.numeCampionat, buffer);
		in >> sursa.nrEchipe;
		for (int i = 0; i < sursa.nrEchipe; i++)
		{

			in >> sursa.victoriiPeSezon[i];
		}


		return in;
	}

	void writeToFile(ofstream& out)
	{

		int lung = strlen(this->numeCampionat) + 1;
		out.write((char*)&lung, sizeof(int));
		out.write(numeCampionat, sizeof(char) * lung);

		out.write((char*)&this->nrEchipe, sizeof(this->nrEchipe));
		for (int i = 0; i < this->nrEchipe; i++) {

			out.write((char*)&this->victoriiPeSezon[i], sizeof(this->victoriiPeSezon[i]));
		}

	}

	void readFromFile(ifstream& in)
	{

		int lung;
		in.read((char*)&lung, sizeof(int));
		char c[1000];
		in.read(c, lung);
		this->setNume(c);

		in.read((char*)&this->nrEchipe, sizeof(this->nrEchipe));
		for (int i = 0; i < this->nrEchipe; i++) {
			in.read((char*)&this->victoriiPeSezon[i], sizeof(this->victoriiPeSezon[i]));

		}

	}

};

class EchipaNationala {

	string numeNationala = "Anonim";
	int nrEchipamente = 0;
	static int nrVictorii;
	int* pretEchipamente = NULL;

public:

	EchipaNationala()
	{
		//cout << "\nAPEL CONSTRUCTOR FARA PARAM";
		this->numeNationala = "Anonim";
		this->nrEchipamente = 0;
	}

	EchipaNationala(string numeNationala, int nrEchipamente, int* pretEchipamente)
	{
		//cout << "\nAPEL CONSTRUCTOR CU TOTI PARAM";
		nrVictorii++;
		delete[] this->pretEchipamente;
		this->numeNationala = numeNationala;
		this->nrEchipamente = nrEchipamente;
		this->pretEchipamente = new int[nrEchipamente];
		for (int i = 0; i < nrEchipamente; i++)
			this->pretEchipamente[i] = pretEchipamente[i];
	}

	EchipaNationala(const EchipaNationala& en)
	{
		nrVictorii++;
		//cout << "\nAPEL CONSTRUCTOR COPIERE";
		this->numeNationala = en.numeNationala;
		this->nrEchipamente = en.nrEchipamente;
		this->pretEchipamente = new int[en.nrEchipamente];
		for (int i = 0; i < en.nrEchipamente; i++)
			this->pretEchipamente[i] = en.pretEchipamente[i];
	}

	EchipaNationala& operator =(const EchipaNationala& en)
	{
		//cout << "\nAPEL OPERATOR =";
		nrVictorii++;
		delete[] this->pretEchipamente;
		this->numeNationala = en.numeNationala;
		this->nrEchipamente = en.nrEchipamente;
		this->pretEchipamente = new int[en.nrEchipamente];
		for (int i = 0; i < en.nrEchipamente; i++)
			this->pretEchipamente[i] = en.pretEchipamente[i];
		return *this;
	}

	friend ostream& operator<<(ostream& out, EchipaNationala en)
	{
		//out << "\nAPEL OPERATOR <<";
		out << "\nNume Nationala: " << en.numeNationala;
		out << "\nNr Echipamente: " << en.nrEchipamente;
		out << "\nNr Victorii: " << en.nrVictorii;
		out << "\nPret Echipamente: ";
		for (int i = 0; i < en.nrEchipamente; i++)
			out << en.pretEchipamente[i] << " ";
		return out;
	}

	friend istream& operator>> (istream& in, EchipaNationala& en)
	{
		//cout << "\nAPEL OPERATOR >>";
		cout << "\nDa nume nationala: ";
		in >> en.numeNationala;
		in.ignore();
		cout << "\nDa numar echipamente: ";
		in >> en.nrEchipamente;
		delete[] en.pretEchipamente;
		en.pretEchipamente = new int[en.nrEchipamente];
		cout << "\nDa pret echipamente: ";
		for (int i = 0; i < en.nrEchipamente; i++)
			in >> en.pretEchipamente[i];
		return in;
	}

	string getNume()
	{
		return this->numeNationala;
	}

	int getNrEch()
	{
		return this->nrEchipamente;
	}

	static int getNrVic()
	{
		return EchipaNationala::nrVictorii;
	}

	int* getPretEch()
	{
		return this->pretEchipamente;
	}

	void setNume(string nume)
	{
		if (nume != "Anonim")
		{
			this->numeNationala = nume;
		}
		else this->numeNationala = "Anonim";
	}

	void setNrEch(int nr)
	{
		if (nr > 0)
		{
			this->nrEchipamente = nr;
		}
		else this->nrEchipamente = 0;
	}

	void setPretEch(int* pret, int nr)
	{
		delete[] this->pretEchipamente;
		if (pret != NULL)
		{
			this->pretEchipamente = new int[nr];
			for (int i = 0; i < nr; i++)
				this->pretEchipamente[i] = pret[i];
		}
	}

	void afisare()
	{
		cout << "\nNume Nationala: " << this->numeNationala;
		cout << "\nNr Echipamente: " << this->nrEchipamente;
		cout << "\nNr Victorii: " << this->nrVictorii;
		cout << "\nPret Echipamente: ";
		for (int i = 0; i < this->nrEchipamente; i++)
			cout << this->pretEchipamente[i] << " ";
	}

	~EchipaNationala()
	{
		//cout << "\nDESTRUCTOR - Echipa Nationala";
		nrVictorii--;
		delete[] this->pretEchipamente;
	}

	int& operator[](int index)
	{
		//cout << "\nAPEL OPERATOR []";
		if (index >= 0 && index < this->nrEchipamente)
		{
			return this->pretEchipamente[index];
		}
		else
		{
			throw exception();
		}
	}

	EchipaNationala operator+ (int x) {
		EchipaNationala copie = *this;
		int* v;
		v = new int[copie.nrEchipamente + 1];
		for (int i = 0; i < copie.nrEchipamente; i++)
		{
			v[i] = copie.pretEchipamente[i];
		}

		v[copie.nrEchipamente] = x;
		delete[] copie.pretEchipamente;
		copie.pretEchipamente = v;
		copie.nrEchipamente++;
		return copie;
	}

	EchipaNationala& operator++() {

		int* v = new int[this->nrEchipamente + 1];
		for (int i = 0; i < this->nrEchipamente; i++) {
			v[i] = this->pretEchipamente[i];
		}
		v[this->nrEchipamente] = 125;
		delete[] this->pretEchipamente;

		this->pretEchipamente = v;
		this->nrEchipamente++;

		return *this;
	}

	EchipaNationala operator++(int)
	{
		EchipaNationala copie = *this;


		int* v = new int[this->nrEchipamente + 1];
		for (int i = 0; i < this->nrEchipamente; i++) {
			v[i] = this->pretEchipamente[i];
		}
		v[this->nrEchipamente] = 350;
		delete[] this->pretEchipamente;

		this->pretEchipamente = v;
		this->nrEchipamente++;

		return copie;
	}

	bool operator!()
	{
		if (this->nrEchipamente == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(EchipaNationala en)
	{
		return this->nrEchipamente >= en.nrEchipamente;
	}

	operator int()
	{
		return this->pretEchipamente[this->nrEchipamente - 1];
	}

	bool operator == (EchipaNationala en)
	{
		return this->nrEchipamente == en.nrEchipamente;
	}

	float calcularePretMediu()
	{
		float m = 0;
		if (this->nrEchipamente > 0) {
			for (int i = 0; i < this->nrEchipamente; i++)
			{
				m += this->pretEchipamente[i];
			}
			m /= this->nrEchipamente;
		}

		return m;
	}

	friend ofstream& operator<< (ofstream& out, EchipaNationala sursa)
	{

		out << sursa.numeNationala << endl;
		out << sursa.nrEchipamente << endl;
		for (int i = 0; i < sursa.nrEchipamente; i++) {
			out << sursa.pretEchipamente[i] << endl;
		}

		return out;
	}

	friend ifstream& operator>> (ifstream& in, EchipaNationala& sursa)
	{

		in >> sursa.numeNationala;
		in >> sursa.nrEchipamente;
		delete[] sursa.pretEchipamente;
		sursa.pretEchipamente = new int[sursa.nrEchipamente];
		for (int i = 0; i < sursa.nrEchipamente; i++)
		{

			in >> sursa.pretEchipamente[i];
		}


		return in;
	}

	void writeToFile(ofstream& o)
	{

		
		int lungime2 = strlen(this->numeNationala.c_str()) + 1;
		o.write((char*)&lungime2, sizeof(int));  
		o.write(this->numeNationala.c_str(), sizeof(char) * lungime2);
		
		o.write((char*)&this->nrEchipamente, sizeof(this->nrEchipamente));
		for (int i = 0; i < this->nrEchipamente; i++) {

			o.write((char*)&this->pretEchipamente[i], sizeof(this->pretEchipamente[i]));
		}

	}

	void readFromFile(ifstream& in)
	{
		
		int lungime2;
		in.read((char*)&lungime2, sizeof(int)); 
		char s1[2300];
		in.read(s1, lungime2);
		this->numeNationala = s1;

		in.read((char*)&this->nrEchipamente, sizeof(this->nrEchipamente));
		delete[]  this->pretEchipamente;
		this->pretEchipamente = new int[this->nrEchipamente];
		for (int i = 0; i < this->nrEchipamente; i++) {
			in.read((char*)&this->pretEchipamente[i], sizeof(this->pretEchipamente[i]));

		}
	}
};

int EchipaNationala::nrVictorii = 0;

class OpFisier {

public:
	
	void writeToFile(ofstream& fout, Jucator sursa) {

		sursa.writeToFile(fout);

	}

	void readFromFile(ifstream& fin, Jucator& sursa) {

		sursa.readFromFile(fin);

	}
};

class Meniu {
public:
	static void MeniuPrincipal() {
		cout << "\n1)Afiseaza Jucator curent: " ;
		cout << "\n2)Da Jucator nou: ";
		//cout << "\n3)Salveaza date.";
		cout << "\n0)Iesire.";
		cout << "\nAlege optiune:";
	}
};

class Rapoarte1 {
public:
	static void Raport1() {
		cout << "\n1)Afiseaza Nume Jucator: ";
		cout << "\n2)Afiseaza nr meciuri jucate de jucator: ";
		cout << "\n3)Salveaza date.";
		cout << "\n0)Iesire.";
		cout << "\nAlege optiune:";
	}
};

class Rapoarte2 {
public:
	static void Raport2() {
		cout << "\n1)Afiseaza Nume Echipa: ";
		cout << "\n2)Afiseaza nr transferuri: ";
		cout << "\n3)Salveaza date.";
		cout << "\n0)Iesire.";
		cout << "\nAlege optiune:";
	}
};


class Rapoarte3 {
public:
	static void Raport3() {
		cout << "\n1)Afiseaza Nume Campionat: ";
		cout << "\n2)Afiseaza nr echipe: ";
		cout << "\n3)Salveaza date.";
		cout << "\n0)Iesire.";
		cout << "\nAlege optiune:";
	}
};

struct Fotbal {
public:
	Fotbal(string numeAntrenor, string numeJucator, string numeEchipa, int meciuriJucate, string numeCampionat)
	{
		NumeAntrenor = numeAntrenor;
		NumeJucator = numeJucator;
		NumeEchipa = numeEchipa;
		MeciuriJucate=meciuriJucate;
		NumeCampionat = numeCampionat;
	}

	void afisare() {
		cout << "  Nume Antrenor: " << NumeAntrenor << endl;
		cout << "  Nume Jucator: " << NumeJucator << endl;
		cout << "  Nume Echipa: " << NumeEchipa << endl;
		cout << "  Numar meciuri jucate: " << MeciuriJucate << endl;
		cout << " Nume Campionat: " << NumeCampionat << endl;
		cout << endl;
	}

	string NumeAntrenor;
	string NumeJucator;
	string NumeEchipa;
	int MeciuriJucate;
	string NumeCampionat;
	
};

void afisareFotbal(vector<Fotbal>& fotbal)
{
	for (auto fotbal1 : fotbal) {
		fotbal1.afisare();
	}
}

class ListaTransferuri
{
	string echipa = "Anonim";
	Jucator** listaJucatori = NULL;
	int nrJucatori = 0;
public:
	ListaTransferuri() {}
	ListaTransferuri(string echipa, Jucator** listaJucatori, int nrJucatori)
	{
		this->echipa = echipa;
		if (listaJucatori != NULL && nrJucatori > 0)
		{
			this->nrJucatori = nrJucatori;
			this->listaJucatori = new Jucator* [this->nrJucatori];
			for (int i = 0; i < this->nrJucatori; i++)
			{
				
				this->listaJucatori[i] = new Jucator(*listaJucatori[i]);
				
			}
		}

	}
	ListaTransferuri(const ListaTransferuri& w)
	{
		this->echipa = w.echipa;
		if (w.listaJucatori != NULL && w.nrJucatori > 0)
		{
			this->nrJucatori = w.nrJucatori;
			this->listaJucatori = new Jucator * [this->nrJucatori];
			for (int i = 0; i < this->nrJucatori; i++)
			{
				
				this->listaJucatori[i] = new Jucator(*w.listaJucatori[i]);
				
			}
		}

	}
	ListaTransferuri& operator=(const ListaTransferuri& w)
	{
		if (this != &w)
		{
			for (int i = 0; i < this->nrJucatori; i++)
				delete this->listaJucatori[i];
			delete[] this->listaJucatori;

			this->echipa = w.echipa;
			if (w.listaJucatori != NULL && w.nrJucatori > 0)
			{
				this->nrJucatori = w.nrJucatori;
				this->listaJucatori = new Jucator * [this->nrJucatori];
				for (int i = 0; i < this->nrJucatori; i++)
				{
					
					this->listaJucatori[i] = new Jucator(*w.listaJucatori[i]);
					
				}
			}
			else
			{
				this->listaJucatori = NULL;
				this->nrJucatori = 0;
			}

		}
		return*this;
	}
	friend ostream& operator<<(ostream& out, const ListaTransferuri& w)
	{
		out << "\nEchipa: " << w.echipa;
		out << "\nNr. Jucatori: " << w.nrJucatori;
		for (int i = 0; i < w.nrJucatori; i++)
		{
			out << "\nJucator " << i << ": ";
			out << *w.listaJucatori[i];
		}
		return out;
	}
	friend istream& operator>>(istream& in, ListaTransferuri& w)
	{
		for (int i = 0; i < w.nrJucatori; i++)
			delete w.listaJucatori[i];
		delete[] w.listaJucatori;
		cout << "\nechipa: ";
		in >> w.echipa;
		cout << "\nNr. Jucatori:";
		in >> w.nrJucatori;

		if (w.nrJucatori > 0)
		{
			w.listaJucatori = new Jucator * [w.nrJucatori];
			for (int i = 0; i < w.nrJucatori; i++)
			{
				w.listaJucatori[i] = new Jucator();
				in >> *w.listaJucatori[i];

			}
		}
		else
		{
			w.nrJucatori = 0;
			w.listaJucatori = NULL;

		}
		return in;
	}
	~ListaTransferuri()
	{
		for (int i = 0; i < this->nrJucatori; i++)
			delete this->listaJucatori[i];
		delete[] this->listaJucatori;
	}
};

class Secund : public Antrenor {

	bool areLicenta=0;
	int nrMeciuriAntrenate=0;

public:
	Secund(){}
	
	Secund(const char* nume, int nrPersDinStaff, int varstaStaff[], bool areLicenta, int nrMeciuriAntrenate) :Antrenor(nume, nrPersDinStaff, varstaStaff)
	{
		this->areLicenta = areLicenta;
		this->nrMeciuriAntrenate = nrMeciuriAntrenate;
	}

	Secund(Antrenor a, bool areLicenta, int nrMeciuriAntrenate) :Antrenor(a)
	{
		this->areLicenta = areLicenta;
		this->nrMeciuriAntrenate = nrMeciuriAntrenate;
	}

	Secund(const Secund& s) : Antrenor(s)
	{
		this->areLicenta = s.areLicenta;
		this->nrMeciuriAntrenate = s.nrMeciuriAntrenate;
	}

	Secund& operator=(const Secund& s)
	{
		if (this != &s)
		{
			this->Antrenor::operator=(s);
			this->areLicenta = areLicenta;
			this->nrMeciuriAntrenate = nrMeciuriAntrenate;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Secund& s)
	{
		out << (Antrenor)s;
		out << "\nLicenta: " << s.areLicenta;
		out << "\nNr Meciuri Antrenate: " << s.nrMeciuriAntrenate;
		return out;
	}

	~Secund(){}
};

class Rezerva : public Jucator {

	bool eProfesionist = 0;
	int nrAccidentari = 0;

public:
	Rezerva() {}

	Rezerva(const char* nume, int nrMeciuri, int nrGoluri[],bool eProfesionist, int nrAccidentari) :Jucator(nume, nrMeciuri, nrGoluri)
	{
		this->eProfesionist = eProfesionist;
		this->nrAccidentari = nrAccidentari;
	}

	Rezerva(Jucator a, bool eProfesionist, int nrAccidentari) :Jucator(a)
	{
		this->eProfesionist = eProfesionist;
		this->nrAccidentari = nrAccidentari;
	}

	Rezerva(const Rezerva& s) : Jucator(s)
	{
		this->eProfesionist = s.eProfesionist;
		this->nrAccidentari = s.nrAccidentari;
	}

	Rezerva& operator=(const Rezerva& s)
	{
		if (this != &s)
		{
			this->Jucator::operator=(s);
			this->eProfesionist = eProfesionist;
			this->nrAccidentari = nrAccidentari;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Rezerva& s)
	{
		out << (Jucator)s;
		out << "\nProfesionist: " << s.eProfesionist;
		out << "\nNr Accidentari: " << s.nrAccidentari;
		return out;
	}

	~Rezerva() {}


};

class IFile {
public:
	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;
};

class Junior : public IFile
{
	string nume = "Anonim";
	float salariu;
	float OreMunca;

public:
	void writeToFile(fstream& f)
	{
		int lungime = this->nume.length() + 1;
		f.write((char*)&lungime, sizeof(int));
		f.write(this->nume.data(), lungime * sizeof(char));

		f.write((char*)&this->salariu, sizeof(float));
		f.write((char*)&this->OreMunca, sizeof(float));
	}

	void readFromFile(fstream& f)
	{
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->nume = buffer;
		delete[] buffer;

		f.read((char*)&this->salariu, sizeof(float));
		f.read((char*)&this->OreMunca, sizeof(float));

	}

	Junior(){}
	Junior(string nume, float salariu, float OreMunca)
	{
		this->nume = nume;
		this->salariu = salariu;
		this->OreMunca = OreMunca;
	}
	Junior(const Junior& j)
	{
		this->nume = j.nume;
		this->salariu = j.salariu;
		this->OreMunca = j.OreMunca;
	}
	Junior& operator=(const Junior& j)
	{
		this->nume = j.nume;
		this->salariu = j.salariu;
		this->OreMunca = j.OreMunca;
		return *this;
	}
	~Junior(){}
	
	friend ostream& operator<<(ostream& out, const Junior& j)
	{
		out << "\nNume: " << j.nume;
		out << "\nSalariu: " << j.salariu;
		out << "\nOre de munca: " << j.OreMunca;
		return out;
	}

	virtual float calculSalariu()
	{
		return this->salariu;
	}

	virtual float calculOreMunca()
	{
		return this->OreMunca;
	}
};

enum Pozitie{Portar=1, Fundas=2, Mijlocas=3, Atacant=4};

class CopilDeMingi : public Junior
{
	Pozitie pozitie = Pozitie::Portar;
	int nrMeciuriJucate = 0;
	int nrOreScoala = 0;
	
public:
	CopilDeMingi() {}
	CopilDeMingi(string n, float s,float om, Pozitie p, int nr, int os) :Junior(n, s,om)
	{
		this->pozitie = p;
		this->nrMeciuriJucate = nr;
		this->nrOreScoala = os;
	
	}
	CopilDeMingi(const CopilDeMingi& cp) : Junior(cp)
	{
		this->pozitie = cp.pozitie;
		this->nrMeciuriJucate = cp.nrMeciuriJucate;
		this->nrOreScoala = cp.nrOreScoala;
	}

	CopilDeMingi& operator=(const CopilDeMingi& cp)
	{
		Junior::operator=(cp);
		this->pozitie = cp.pozitie;
		this->nrMeciuriJucate = cp.nrMeciuriJucate;
		this->nrOreScoala = nrOreScoala;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const CopilDeMingi& cp)
	{
		out << (Junior)cp;
		out << "\nPozitie: " << cp.pozitie;
		out << "\nNr de meciuri jucate: " << cp.nrMeciuriJucate;
		out << "\nNr de ore de scoala: " << cp.nrOreScoala;
		return out;
	}

	~CopilDeMingi(){}

	float calculSalariu()
	{
		return Junior::calculSalariu() + this->nrMeciuriJucate * 70;
	}

	float calculOreMunca()
	{
		return Junior::calculOreMunca() + this->nrOreScoala;
	}
};

template<class TIP>
class FotbalColectie
{
	int nrObiecte = 0;
	TIP* listaObiecte = NULL;

public:
	FotbalColectie() {	}
	FotbalColectie(int nrObiecte, TIP* listaObiecte) {
		this->nrObiecte = nrObiecte;
		this->listaObiecte = new TIP[this->nrObiecte];
		for (int i = 0; i < nrObiecte; i++)
			this->listaObiecte[i] = listaObiecte[i];
	}

	FotbalColectie(const FotbalColectie& c)
	{
		this->nrObiecte = c.nrObiecte;
		this->listaObiecte = new TIP[this->nrObiecte];
		for (int i = 0; i < c.nrObiecte; i++)
			this->listaObiecte[i] = c.listaObiecte[i];
	}

	FotbalColectie& operator=(const FotbalColectie& c) {
		if (this != &c) {
			delete[]this->listaObiecte;
			this->nrObiecte = c.nrObiecte;
			this->listaObiecte = new TIP[this->nrObiecte];
			for (int i = 0; i < c.nrObiecte; i++)
				this->listaObiecte[i] = c.listaObiecte[i];
		}
		return *this;
	}

	~FotbalColectie() {
		delete[]this->listaObiecte;
	}

	friend ostream& operator<<(ostream& out, const FotbalColectie& c) {
		out << "\nNr obiecte: " << c.nrObiecte;
		out << "\nLista obiecte: ";
		for (int i = 0; i < c.nrObiecte; i++)
			out << c.listaObiecte[i] << " ";
		return out;
	}
};


int main()
{
	Antrenor a;
	Jucator j;
	Campionat c;
	EchipaNationala en;
	Echipa e;
	Antrenor a1("Dan Petrescu", 3, new int[3] {55, 62, 49});
	Jucator j1("Leo Messi", 3, new int[3] {30, 25, 20});
	Campionat c1("Superliga 1", 3, new int[3] {10, 14, 20});
	EchipaNationala en1("Romania", 3, new int[3] {150, 200, 150});
	Echipa e1(1947, "Steaua Bucuresti", 3, new int[3] {10, 20, 30});
	Antrenor a3("Gigi Multescu", 2, new int[2] {55, 62});
	Jucator j3("Gheorghe Hagi", 4, new int[4] {30, 25, 20, 15});
	Campionat c3("Premier League", 2, new int[2] {10, 14});
	EchipaNationala en3("Cosmin Contra", 3, new int[3] {150, 200, 150});
	Echipa e3(1964, "Otelul Galati", 4, new int[4] {10, 20, 30, 15});
	a.setNume("Marius Sumudica");
	cout << "\n" << a.getNume() << endl;

	for (int i = 0; i < a1.getNrPersDinStaff(); i++)
		cout << " " << a1.getVarstaStaff()[i];
	cout << endl;
	a1.setVarstaStaff(new int[3] {40, 50, 60}, a1.getNrPersDinStaff());
	for (int i = 0; i < a1.getNrPersDinStaff(); i++)
		cout << " " << a1.getVarstaStaff()[i];
	j1.setNume("Cristiano Ronalodo");
	cout << "\n" << j1.getNume();
	j1.setNrMeciuri(2);
	cout << "\n" << j1.getNrMeciuri() << endl;
	j1.setNrGoluri(new int[2] {40, 50}, j1.getNrMeciuri());
	for (int i = 0; i < j1.getNrMeciuri(); i++)
		cout << " " << j1.getnrGoluri()[i];
	e1.setNume("Barcelona");
	cout << "\n" << e1.getNume();
	e1.setNrTransferuri(3);
	cout << "\n" << e1.getNrTransf() << endl;
	e1.setSumaIncasata(new int[3] {40, 50, 55}, e1.getNrTransf());
	for (int i = 0; i < e1.getNrTransf(); i++)
		cout << " " << e1.getSumaIncasata()[i];
	c1.setNume("Bundesliga");
	cout << "\n" << c1.getNume();
	c1.setNrEchipe(3);
	cout << "\n" << c1.getNrEchipe() << endl;
	c1.setVicPeSez(new int[3] {30, 40, 55}, c1.getNrEchipe());
	for (int i = 0; i < c1.getNrEchipe(); i++)
		cout << " " << c1.getVicPeSez()[i];
	en1.setNume("Bulgaria");
	cout << "\n" << en1.getNume();
	en1.setNrEch(2);
	cout << "\n" << en1.getNrEch();
	cout << "\n" << en1.getNrVic() << endl;
	en1.setPretEch(new int[2] {30, 40}, en1.getNrEch());
	for (int i = 0; i < en1.getNrEch(); i++)
		cout << " " << en1.getPretEch()[i];
	a.afisare();

	a1.afisare();
	j1.afisare();
	c1.afisare();
	en1.afisare();
	e1.afisare();
	Echipa e4(e1);
	Antrenor a4(a1);
	Campionat c4(c1);
	EchipaNationala en4(en1);
	Jucator j4(j1);
	Antrenor a2;
	Jucator j2;
	Echipa e2;
	Campionat c2;
	EchipaNationala en2;
	a2 = a1;
	a2.afisare();

	j2 = j1;
	j2.afisare();

	c2 = c1;
	c2.afisare();

	e2 = e1;
	e2.afisare();

	en2 = en1;
	en2.afisare();
	Antrenor a5;
	Jucator j5;
	Echipa e5;
	Campionat c5;
	EchipaNationala en5;
	cin >> a5;
	cout << a5;
	cout << endl;
	cin >> j5;
	cout << j5;
	cin >> e5;
	cout << e5;
	cin >> c5;
	cout << c5;
	cin >> en5;
	cout << en5;
	int varsta = a1[0];
	cout << "\nVarsta: " << varsta;
	a1[1] = 35;
	a1.afisare();
	int goluri = j1[0];
	cout << "\nNr Goluri: " << goluri;
	j1[1] = 35;
	j1.afisare();
	int sume = e1[0];
	cout << "\nSuma incasate: " << sume;
	e1[1] = 20;
	e1.afisare();
	int vic = c1[0];
	cout << "\nVictorii: " << vic;
	c1[1] = 10;
	c1.afisare();
	int pret = en1[0];
	cout << "\nPret Echipa: " << pret;
	en1[1] = 100;
	en1.afisare();
	cout << a1 + 20;
	cout << j1 + 20;
	cout << e1 + 3;
	cout << c1 + 3;
	cout << en1 + 300;
	++a1;
	a1++;
	a1.afisare();
	++j1;
	j1++;
	j1.afisare();
	++e1;
	e1++;
	e1.afisare();
	++c1;
	c1++;
	c1.afisare();
	++en1;
	en1++;
	en1.afisare();
	if (!a1) {

		cout << "\na1 nu are persoane in staff";
	}
	else
	{
		cout << "\na1 are pers in staff";
	}

	if (!j)
	{
		cout << "\nj nu are meciuri jucate";
	}
	else
	{
		cout << "\nj are meciuri jucate";
	}

	if (!e)
	{
		cout << "\ne nu are transferuri facute";
	}
	else
	{
		cout << "\ne are transferuri facute";
	}

	if (!c1)
	{
		cout << "\nc1 nu are echipe";
	}
	else
	{
		cout << "\nc1 are echipe";
	}

	if (!en1)
	{
		cout << "\nen1 nu are echipamente";
	}
	else
	{
		cout << "\nen1 are echipamente";
	}

	if (a1 >= a3)
	{
		cout << "\nA1 are mai multe persoane in staff decat A3";
	}
	else
	{
		cout << "\nInvers";
	}

	if (j1 >= j3)
	{
		cout << "\nJ1 are mai multe meciuri jucate decat J3";
	}
	else
	{
		cout << "\nInvers";
	}

	if (e1 >= e3)
	{
		cout << "\nE1 are mai multe transferuri facute decat E3";
	}
	else
	{
		cout << "\nInvers";
	}


	if (c1 >= c3)
	{
		cout << "\nC1 are mai multe echipe decat C3";
	}
	else
	{
		cout << "\nInvers";
	}


	if (en1 >= en3)
	{
		cout << "\nEN1 are mai multe echipamente decat EN3";
	}
	else
	{
		cout << "\nInvers";
	}
	int varsta1 = a3;
	cout << "\nVarsta curenta: " << varsta1;
	int goluri1 = j3;
	cout << "\nGoluri curente: " << goluri1;
	int suma1 = e3;
	cout << "\nSuma curenta: " << suma1;
	int victorii1 = c3;
	cout << "\nVictorii curente: " << victorii1;
	int pret1 = en3;
	cout << "\nPret curent: " << pret1;

	if (a1 == a3) {
		cout << "\nAntrenorii au acelasi nume ";
	}
	else {
		cout << "\nAntrenorii nu au acelasi nume ";
	}

	if (j1 == j3) {
		cout << "\nJucatorii au acelasi nume ";
	}
	else {
		cout << "\nJucatorii nu au acelasi nume ";
	}

	if (e1 == e3) {
		cout << "\nEchipele au acelasi nume ";
	}
	else {
		cout << "\nEchipele nu au acelasi nume ";
	}

	if (c1 == c3) {
		cout << "\nCampionatele au acelasi nume ";
	}
	else {
		cout << "\nCampionatele nu au acelasi nume ";
	}

	if (en1 == en3) {
		cout << "\nEchipele au acelasi nr de echipamente";
	}
	else {
		cout << "\nEchipele nu au acelasi nr de echipamente ";
	}

	cout << "\nASta este media varstelor: " << a3.calculareVarstaMedie() << endl;
	cout << "\nASta este media golurilor: " << j3.calculareGoluriMedie() << endl;
	cout << "\nASta este media sumelor: " << e3.calculareSumaMedie() << endl;
	cout << "\nASta este media victoriilor pe sez: " << c3.calculareMedieVictorii() << endl;
	cout << "\nASta este media preturilor: " << en3.calcularePretMediu() << endl;

	ofstream fout;
	fout.open("Antrenor1.txt", ofstream::out);
	if (fout.is_open()) 
	{
	
		fout << a1;
		fout.close();
	}

	Antrenor a6;
	ifstream fin;
	fin.open("Antrenor1.txt", ifstream::in);
	if (fin.is_open()) {
		fin >> a6;
		cout << a6;
		fin.close();
	}

	ofstream fout1;
	fout1.open("Jucator1.txt", ofstream::out);
	if (fout1.is_open())
	{

		fout1 << j1;
		fout1.close();
	}

	Jucator j6;
	ifstream fin1;
	fin1.open("Jucator1.txt", ifstream::in);
	if (fin1.is_open()) {
		fin1 >> j6;
		cout << j6;
		fin1.close();
	}

	ofstream fout2;
	fout2.open("Echipa1.txt", ofstream::out);
	if (fout2.is_open())
	{

		fout2 << e1;
		fout2.close();
	}

	Echipa e6;
	ifstream fin2;
	fin2.open("Echipa1.txt", ifstream::in);
	if (fin2.is_open()) {
		fin2 >> e6;
		cout << e6;
		fin2.close();
	}

	ofstream fout3;
	fout3.open("Campionat1.txt", ofstream::out);
	if (fout3.is_open())
	{

		fout3 << c1;
		fout3.close();
	}

	Campionat c6;
	ifstream fin3;
	fin3.open("Campionat1.txt", ifstream::in);
	if (fin3.is_open()) {
		fin3 >> c6;
		cout << c6;
		fin3.close();
	}

	ofstream fout4;
	fout4.open("EchipaNationala1.txt", ofstream::out);
	if (fout4.is_open())
	{

		fout4 << en1;
		fout4.close();
	}

	EchipaNationala en6;
	ifstream fin4;
	fin4.open("EchipaNationala1.txt", ifstream::in);
	if (fin4.is_open()) {
		fin4 >> en6;
		cout << en6;
		fin4.close();
	}

	ofstream fout5;
	fout5.open("Jucator2.bin", ofstream::binary);
	if (fout5.is_open()) {
		j1.writeToFile(fout5);
		fout5.close();
	}
	
	Jucator j7;
	ifstream fin5;
	fin5.open("Jucator2.bin", ifstream::binary);
	if (fin5.is_open()) {
		j7.readFromFile(fin5);
		fin5.close();
	}
	
	cout << j7;

	ofstream fout6;
	fout6.open("Antrenor2.bin", ofstream::binary);
	if (fout6.is_open()) {
		a1.writeToFile(fout6);
		fout6.close();
	}

	Antrenor a7;
	ifstream fin6;
	fin6.open("Antrenor2.bin", ifstream::binary);
	if (fin6.is_open()) {
		a7.readFromFile(fin6);
		fin6.close();
	}

	cout << a7;

	ofstream fout7;
	fout7.open("Echipa2.bin", ofstream::binary);
	if (fout7.is_open()) {
		e1.writeToFile(fout7);
		fout7.close();
	}

	Echipa e7;
	ifstream fin7;
	fin7.open("Echipa2.bin", ifstream::binary);
	if (fin7.is_open()) {
		e7.readFromFile(fin7);
		fin7.close();
	}

	cout << e7;


	ofstream fout8;
	fout8.open("Campionat2.bin", ofstream::binary);
	if (fout8.is_open()) {
		c1.writeToFile(fout8);
		fout8.close();
	}

	Campionat c7;
	ifstream fin8;
	fin8.open("Campionat2.bin", ifstream::binary);
	if (fin8.is_open()) {
		c7.readFromFile(fin8);
		fin8.close();
	}

	cout << c7;

	ofstream fout9;
	fout9.open("EchipaNationala2.bin", ofstream::binary);
	if (fout9.is_open()) {
		en1.writeToFile(fout9);
		fout9.close();
	}

	EchipaNationala en7;
	ifstream fin9;
	fin9.open("EchipaNationala2.bin", ifstream::binary);
	if (fin9.is_open()) {
		en7.readFromFile(fin9);
		fin9.close();
	}

	cout << en7;

	OpFisier opfisier;
	Jucator j10("Leo Messi", 3, new int[3] {30, 25, 20});
	ifstream finbin;
	finbin.open("jucator3.bin", ifstream::binary);
	if (finbin.is_open()) {
	opfisier.readFromFile(finbin, j10);
	finbin.close();
}

	bool startMeniuActivat = true;
	while (startMeniuActivat) {
	int option;
	Meniu::MeniuPrincipal();
	cin >> option;
	switch (option) 
	{
	case 0: {
		startMeniuActivat = false;
		system("cls");
		cout << "\nAplicatie inchisa" << endl;
		break;
	}
	case 1: {
		
		system("cls");
		cout << j10;
		break;
	}
	case 2: {
		
		system("cls");
		cin >> j10;

		break;
	}
	/*case 3: {
		
		system("cls");
		ofstream foutbin1;
		foutbin1.open("jucator3.bin", ofstream::binary);
		if (foutbin1.is_open()) {
			opfisier.writeToFile(foutbin1, j10);
		}
		foutbin1.close();
		cout << "\nFisier salvat";
		break;
	}*/

	default: {
		
		system("cls");
		cout << "\nOptiune invalida" << endl << endl;
		break;
	}
	
	}
}

	bool raport = true;
	while (raport) {
		int option1;
		Rapoarte1::Raport1();
		cin >> option1;
		switch (option1)
		{
		case 0: {
			raport = false;
			system("cls");
			cout << "\nAplicatia inchisa" << endl;
			break;
		}
		case 1: {

			system("cls");
			cout << "\n" << j1.getNume();
			break;
		}
		case 2: {

			system("cls");
			cout << "\n" << j1.getNrMeciuri() << endl;
			break;
			
		}
		case 3: {

			system("cls");
			ofstream fouttxt1;
			fouttxt1.open("raport1.txt");
			if (fouttxt1.is_open()) {
				fouttxt1 << "\n" << j1.getNume() << "\n" << j1.getNrMeciuri() << endl;
			}
			fouttxt1.close();
			cout << "\nFisier salvat";
			break;
		}

		default: {

			system("cls");
			cout << "\nOptiune invalida" << endl << endl;
			break;
		}

		}
	}

	bool raport1 = true;
	while (raport1) {
		int option2;
		Rapoarte2::Raport2();
		cin >> option2;
		switch (option2)
		{
		case 0: {
			raport1 = false;
			system("cls");
			cout << "\nAplicatia a fost inchisa" << endl;
			break;
		}
		case 1: {

			system("cls");
			cout << "\n" << e1.getNume();
			break;
		}
		case 2: {

			system("cls");
			cout << "\n" << e1.getNrTransf() << endl;
			break;

		}
		case 3: {

			system("cls");
			ofstream fouttxt2;
			fouttxt2.open("raport2.txt");
			if (fouttxt2.is_open()) {
				fouttxt2 << "\n" << e1.getNume() << "\n" << e1.getNrTransf() << endl;
			}
			fouttxt2.close();
			cout << "\nFisier salvat";
			break;
		}

		default: {

			system("cls");
			cout << "\nOptiune invalida" << endl << endl;
			break;
		}

		}
	}

	bool raport2 = true;
	while (raport2) {
		int option3;
		Rapoarte3::Raport3();
		cin >> option3;
		switch (option3)
		{
		case 0: {
			raport2 = false;
			system("cls");
			cout << "\nAplicatia a fost inchisa" << endl;
			break;
		}
		case 1: {

			system("cls");
			cout << "\n" << c1.getNume();
			break;
		}
		case 2: {

			system("cls");
			cout << "\n" << c1.getNrEchipe() << endl;
			break;

		}
		case 3: {

			system("cls");
			ofstream fouttxt3;
			fouttxt3.open("raport3.txt");
			if (fouttxt3.is_open()) {
				fouttxt3 << "\n" << c1.getNume() << "\n" << c1.getNrEchipe() << endl;
			}
			fouttxt3.close();
			cout << "\nFisier salvat";
			break;
		}

		default: {

			system("cls");
			cout << "\nOptiune invalida" << endl << endl;
			break;
		}

		}
	}
	
	ifstream inputFile;
	inputFile.open("Fotbal.csv");
	string line = "";

	vector<Fotbal> fotbal;
	while (getline(inputFile, line))
	{
		stringstream inputString(line);

		//NumeAntrenor, NumeJucator, NumeEchipa, MeciuriJucate, NumeCampionat
		string numeAntrenor;
		string numeJucator;
		string numeEchipa;
		int meciuriJucate;
		string numeCampionat;
		string tempString;

		getline(inputString, numeAntrenor, ',');
		getline(inputString, numeJucator, ',');
		getline(inputString, numeEchipa, ',');
		
		getline(inputString, tempString, ',');
		meciuriJucate = atoi(tempString.c_str());

		getline(inputString, numeCampionat);

		Fotbal fotbal1(numeAntrenor, numeJucator, numeEchipa, meciuriJucate, numeCampionat);
		fotbal.push_back(fotbal1);
		line = "";
	}

	afisareFotbal(fotbal);

	
	Jucator* listaTransferuri[2] = { &j1,&j3};
	ListaTransferuri l1("Steaua", listaTransferuri, 2);
	cout << l1;
	
	Secund s1;
	Secund s2("Dan Petrescu", 3, new int[3] {55, 62, 49}, 1, 200);
	Antrenor ant("Marius Croitoru", 3, new int[3] {50, 60, 44});
	Secund s3(ant, 1,200);
	Secund s4 = s3;
	s3 = s4;
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\";
	cout << s3;
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\";

	Rezerva r1;
	Rezerva r2("Andrei Dumiter", 3, new int[3] {3, 2, 5}, 1, 3);
	Jucator juc("Marco Reus", 3, new int[3] {10, 16, 24});
	Rezerva r3(juc, 1, 3);
	Rezerva r4 = r3;
	r3 = r4;
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\";
	cout << r3;
	cout << "\n\\\\\\\\\\\\\\\\\\\\\\";

	CopilDeMingi cdm1;
	Junior jun1("Tavi", 700, 10);
	CopilDeMingi cdm2("Gigel", 600,10, Pozitie::Mijlocas, 10,30);
	CopilDeMingi cdm3 = cdm2;
	Junior jun2;
	jun2 = cdm3;

	Junior listaJuniori[] = { jun1,cdm2,cdm3 };
	for (int i = 0; i < 3; i++)
		cout << listaJuniori[i];

	Junior* juni = new Junior("Tavi", 700,10);
	CopilDeMingi* cdmi = new CopilDeMingi("Gigel", 600,10, Pozitie::Mijlocas, 10,30);

	cout << "\nSalariu junior: " << juni->calculSalariu();
	cout << "\nSalariu copil de mingi: " << cdmi->calculSalariu();
	cout << "\nOre de munca junior: " << juni->calculOreMunca();
	cout << "\nOre de munca copil de mingi: " << cdmi->calculOreMunca();

	juni = cdmi;

	cout << "\nSalariu junior(fost copil de mingi): " << juni->calculSalariu();
	cout << "\nOre de munca junior(fost copil de mingi): " << juni->calculOreMunca();

	IFile* if1;

	if1 = &cdm1;

	fstream fouT("fisier.txt", ios::out | ios::binary);
	jun1.writeToFile(fouT);
	fouT.close();
	fstream fiN("fisier.txt", ios::in | ios::binary);
	Junior junnou;
	junnou.readFromFile(fiN);
	cout << junnou;

	Jucator vJ[] = { j1,j3 };
	FotbalColectie<Jucator> cJ(2, vJ);
	cout << cJ;

	cout << "\n-----------STL VECTOR------------" << endl;
	vector<int> v1;
	v1.push_back(a1.getNrPersDinStaff());
	v1.push_back(j1.getNrMeciuri());
	v1.push_back(e1.getNrTransf());
	v1.push_back(c1.getNrEchipe());
	v1.push_back(en1.getNrEch());

	vector<int>::iterator it1;
	for (it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1 << " ";
	}

	cout << "\n------------STL LIST-------------\n";
	list<float> l2;
	l2.push_back(a1.getNrPersDinStaff());
	l2.push_front(j1.getNrMeciuri());
	l2.push_back(e1.getNrTransf());
	l2.push_back(c1.getNrEchipe());
	l2.push_back(en1.getNrEch());

	list<float>::reverse_iterator it2;
	for (it2 = l2.rbegin(); it2 != l2.rend(); it2++)
		cout << *it2 << " ";

	cout << "\n--------------STL SET--------------\n";
	
	set<Jucator>sJ3;
	sJ3.insert(j1);
	sJ3.insert(j3);
	
	set<Jucator>::iterator itJ3;
	for (itJ3 = sJ3.begin(); itJ3 != sJ3.end(); itJ3++)
	{
		cout << *itJ3 << " ";
	}

	cout << "\n------------STL MAP-----------\n";
	map<int, string>m3;
	
	m3[a1.getNrPersDinStaff()] = a1.getNume();
	m3[a3.getNrPersDinStaff()] = a3.getNume();
	m3[j3.getNrMeciuri()] = j3.getNume();
	

	map<int, string>::iterator it3;

	for (it3 = m3.begin(); it3 != m3.end(); it3++)
		cout << it3->first << " " << it3->second << endl;

	return 0;
}