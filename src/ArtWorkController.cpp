/*
 * mycontroller.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: jayee
 */
#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;

#include "ArtWork.hpp"
void printInventory(ArtWork stock[]);
void menu(ArtWork stock[]);
void remove(ArtWork stock[]);
void move(ArtWork stock[]);

#define MAX_STOCK 50;
int main() {
	setbuf(stdout, NULL);
	cout << "welcome to my class program with c++ for Art Gallery implementing "
			"MVC pattern. Jayeeta Banerjee." << "\n";
	ArtWork* p;
	ArtWork stock[25] = { { "A.Jones", "oil", "north hall", "100A" }, {
			"B.Smith", "watercolor", "south hall", "101B" }, { "S.Lee", "oil",
			"east hall", "102S" }, { "P.Sen", "acrylic", "west hall", "103P" },
			{ "R.Steves", "glass", "south hall", "104R" }, { }

	};

	ArtWork art { "T.Ray", "pencil", "east hall", "105T" };
	ArtWork art1 { "M.Ron", "watercolor", "west hall", "106M" };
	ArtWork art2 { "D.Sam", "pencil", "east hall", "107D" };
	ArtWork art3 { "T.Jones", "oil", "north hall", "108T" };
	ArtWork art4 { "O.Ray", "oil", "east hall", "109O" };
	stock[5] = art;
	stock[6] = art1;
	stock[7] = art2;
	stock[8] = art3;
	stock[9] = art4;
	//int n = 10;
	printInventory(stock);
	p = &art;
	cout << "\n";

	cout << p->getArtist() << "--" << p->getMedia() << "--" << p->getLocation()
			<< "--" << p->getRefNo() << endl;

	/*for (int k = 0; k < 10; k++) {

		p = &stock[n];
		p->read();
		stock[n++];
		p->printArt();

	}*/

	printInventory(stock);

	menu(stock);

	return 0;
}
void printInventory(ArtWork stock[]) {

	cout << "printing the inventory" << "\n";
	cout << "----------------------------------------------------------------"
			"---" << "\n";

	cout << setw(9) << "artist" << setw(9) << "| " << setw(9) << "media"
			<< setw(10) << " |  " << setw(11) << "location" << setw(9)
			<< "  |  " << setw(9) << "ref no" << "\n";
	cout << "-----------------------------------------------------------------"
			"---" << "\n";

	for (int i = 0; i < 25; i++) {

		cout<<"***"<<stock[i].getArtist();


		stock[i].printArt();
	}
}

void menu(ArtWork stock[]){

	int i = 0;

	cout<<"1 - Print "<<endl;
	cout<<"2 - Remove "<<endl;
	cout<<"3 - Move "<<endl;
	cout<<"0 - Exit "<<endl;

	cin>>i;

	if (i == 0) {
		cout << "Good Bye.." << endl;
		exit(0);
	} else if (i == 1) {
		printInventory (stock);
		menu(stock);
	} else if (i == 2) {
		remove (stock);

	} else if (i == 3) {
		move (stock);
	} else {
		cout << "Invalid Option! Try Again" << endl;
		menu(stock);
	}
}

void remove(ArtWork stock[]){

		string refNumber;
		cout << "\nEnter reference number to remove:\n";
		getline(cin, refNumber);
		refNumber.pop_back();

		for (int k = 0; k < 10; k++) {

			if (refNumber.compare(stock[k].getRefNo()) == 0) {
				cout << stock[k].getRefNo() << endl;
				cout << "*** Removing...****" << endl;
				cout << stock[k].getArtist() << endl;
				stock[k].removeArt(stock[k]);
			}
		}

		menu(stock);
}

void move(ArtWork stock[]){

	 	 string location;
	 	 string refNumber;
		cout << "\nEnter reference number to move:\n";
		getline(cin, refNumber);
		refNumber.pop_back();
		cout << "\nEnter location to move:\n";
		getline(cin, location);
		location.pop_back();

		for (int k = 0; k < 10; k++) {

			if (refNumber.compare(stock[k].getRefNo()) == 0) {
				cout << stock[k].getRefNo() << endl;
				cout << "*** Moving...****" << endl;
				cout << stock[k].getArtist() << endl;
				stock[k].moveArt(location);
				break;
			}
		}


}
