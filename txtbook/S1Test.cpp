#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Flower {
public: 
	Flower(){
		flowerName = "NONE";
		numPetals = 0;
		flowerPrice = 0;
	}

	void set_flowerName(string name){
		flowerName = name;
	}
	void set_numPetals(int n){
		numPetals = n;
	}
	void set_flowerPrice(float price){
		flowerPrice = price;
	}

	string get_flowerName(){
		return flowerName;
	}
	int get_numPetals(){
		return numPetals;
	}
	float get_flowerPrice(){
		return flowerPrice;
	}

private:
	string flowerName;
	int numPetals;
	float flowerPrice;
};

int main()
{
	Flower myFlower;
	myFlower.set_flowerName("Rose");
	myFlower.set_numPetals(4);
	myFlower.set_flowerPrice(11.99);

	cout << myFlower.get_flowerName() << "\n";
	cout << myFlower.get_numPetals() << "\n";
	cout << myFlower.get_flowerPrice() << "\n";

}