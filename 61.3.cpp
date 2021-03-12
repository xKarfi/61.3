#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class file
{
	public:
		ifstream fIn;
		ofstream fOut;

		file();
		~file();
};

file::file(){
	fIn.open("bledne.txt");
	fOut.open("wynik3.txt");
}

file::~file(){
	fIn.close();
	fOut.close();
}

class ciagi{
	
	private:
		file f;
		vector <int> ciag;
		vector <int> zle;
		vector <int> r;
		
		
	public:
		void zaladuj();
		void wypisz();

};

void ciagi::zaladuj()
{
	int dlugosc, num, true_r;
	
	while(!f.fIn.eof())
	{
		
		f.fIn>>dlugosc;
		for(int i = 0;i<dlugosc;i++)
		{
			f.fIn>>num;
			ciag.push_back(num);
			
		}
		for(int i = 0;i<4;i++){
			r.push_back(ciag[i+1]-ciag[i]);
		}
		if(r[0]==r[1]){
			true_r = r[0];
		} else if(r[1]==r[2])
		{
			true_r = r[1];
		} else if(r[2]==r[3])
		{
			true_r = r[2];
		} else if(r[3]==r[0])
		{
			true_r = r[3];
		}

		for(int i = 0;i<dlugosc;i++)
		{
			if(ciag[i] + true_r != ciag[i+1])
			{
				zle.push_back(ciag[i+1]);
				break;
			}
		}
		ciag.clear();
		r.clear();
	}
	
	
}

void ciagi::wypisz()
{
	for(int i = 0;i<zle.size()-1;i++){
		f.fOut<<i+1<<": "<<zle[i]<<endl;
	}
}

int main(int argc, char** argv) 
{
	ciagi c;
	c.zaladuj();
	c.wypisz();
	
	return 0;
}
