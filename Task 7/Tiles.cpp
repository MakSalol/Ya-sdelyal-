#include <iostream>
#include <string>
using namespace std;

class Tiles{
public:
	string brand;
	int size_h;
	int size_w;
	int price;

	Tiles(string a, int b, int c, int d){
		brand = a;
		size_h = b;
		size_w = c;
		price = d;
	}

	void GetData(){
		cout << "brand: " << brand << endl;
		cout << "size_h: " << size_h << endl;
		cout << "size_w: " << size_w << endl;
		cout << "price: " << price << endl;

	}
};




int main(){
	Tiles tiles("abc", 2,4,5000);
	tiles.GetData();
}
