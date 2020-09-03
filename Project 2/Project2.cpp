#include <iostream>
#include "Source.h"
using namespace std;

/*
Andrew Skalicky
V1: Project 1, February 8, 2017
V2: Project 2, March 3, 2017

This class is the parent class for Pen, Printer, and SafeBox

*/
class Item
{

public:
	//class variables needed for and shared between
	//Pen, Printer, and SafeBox
	double height, length, width, weight, price;
	int itemId, code, color, brand, type;

	//default constructor
	Item()
	{
	}

	//destructor for item objects
	~Item()
	{
	}

	//returns the item's id
	int getItemId()
	{
		return itemId;
	}

	//getter for code variable
	int getCode()
	{
		return code;
	}

	//getter for color variable
	int getColor()
	{
		return color;
	}

	//getter for brand variable
	int getBrand()
	{
		return brand;
	}

	//getter for height variable
	double getHeight()
	{
		return height;
	}

	//getter for length variable
	double getLength()
	{
		return length;
	}

	//getter for width variable
	double getWidth()
	{
		return width;
	}

	//getter for weight variable
	double getWeight()
	{
		return weight;
	}

	//getter for price variable
	double getPrice()
	{
		return price;
	}

	//getter for type variable
	int getType()
	{
		return type;
	}

	//returns the name of a color, according to it's id number
	char* getColorName(int cid)
	{
		switch (cid)
		{
		case 1: case 8:
		{
			return "Red";
			break;
		}
		case 2:
		{
			return "Blue";
			break;
		}
		case 3:
		{
			return "Green";
			break;
		}
		case 4: case 5: case 7:
		{
			return "Black";
			break;
		}
		case 6:
		{
			return "White";
			break;
		}
		default:
		{
			return "N/A";
			break;
		}
		}
	}

	//returns an Item's brand name, according to its id
	char* getBrandName(int bid)
	{
		switch (bid)
		{
		case 1:
		{
			return "Pilot";
			break;
		}
		case 2:
		{
			return "Paper Mate";
			break;
		}
		case 3:
		{
			return "Uni-ball";
			break;
		}
		case 4:
		{
			return "Sharpie";
			break;
		}
		case 5:
		{
			return "Dell";
			break;
		}
		case 6:
		{
			return "HP";
			break;
		}
		case 7:
		{
			return "Cannon";
			break;
		}
		case 8:
		{
			return "Brother";
			break;
		}
		case 9:
		{
			return "SentrySafe";
			break;
		}
		case 10:
		{
			return "First Alert";
			break;
		}
		case 11:
		{
			return "Honeywell";
			break;
		}
		default:
		{
			return "N/A";
			break;
		}
		}
	}

	//returns an object's type, according to its id number
	char* getTypeName(int t)
	{
		switch (t)
		{
		case 1:
		{
			return "Ball Point";
			break;
		}
		case 2:
		{
			return "Roller Ball";
			break;
		}
		case 3:
		{
			return "Fountain";
			break;
		}
		case 4:
		{
			return "Calligraphy";
			break;
		}
		case 5:
		{
			return "All-In-One";
			break;
		}
		case 6:
		{
			return "Laser";
			break;
		}
		case 7:
		{
			return "Inkjet";
			break;
		}
		case 8:
		{
			return "Water Proof";
			break;
		}
		case 9:
		{
			return "Wall Mountable";
			break;
		}
		case 10:
		{
			return "Desktop";
			break;
		}
		default:
		{
			return "N/A";
			break;
		}
		}
	}

	//converts 1 or 0 into a yes or no
	char* yesOrNo(int n)
	{
		switch (n)
		{
		case 1:
		{
			return "Yes";
			break;
		}
		case 0:
		{
			return "No";
			break;
		}
		default:
		{
			return "N/A";
			break;
		}
		}
	}

	//
	friend ostream& operator << (ostream& s, Item& item)
	{
		item.display();
		return s;
	}

	//display
	void display()
	{
	}
};

/*
Andrew Skalicky
V1: Project 1, February 8, 2017
V2: Project 2, March 3, 2017

This class is a subclass of Item, for Pen objects
*/
class Pen : public Item
{

private:
	//local variables
	int packetSize;
	int assortedInk;

public:
	//default constructor
	Pen()
	{

	}

	//constructs a pen object, while setting variables
	Pen(int iId, int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t, int aInk, int pSize)
	{
		//setting of variables obtained from Item
		itemId = iId;
		code = cde;
		color = col;
		brand = br;
		type = t;
		height = hght;
		length = lgth;
		width = wdth;
		weight = wght;
		price = p;

		//setting of variables local to Pen class
		assortedInk = aInk;
		packetSize = pSize;
	}

	//returns the packetSize variable
	int getPacSize()
	{
		return packetSize;
	}

	//returns the assortedInk variable
	int getAssortedInk()
	{
		return assortedInk;
	}

	//creates an ostream output for Pen objects
	friend ostream& operator << (ostream& s, Pen& pen)
	{
		pen.display();
		return s;
	}

	//outputs to console formatted Pen information
	void display()
	{
		cout << "     Item Number: " << getItemId() << " Item Type: " << "Pen\n" << "       Color: " << getColorName(color)
			<< "  Brand: " << getBrandName(brand) << "  Height: " << getHeight() << "  Length: "
			<< getLength() << "  Width: " << getWidth() << "  Weight: " << getWeight() << "  Price: "
			<< getPrice() << "  Type: " << getTypeName(type) << "  Assorted Ink: " << yesOrNo(assortedInk)
			<< "  Packet Size: " << getPacSize() << "\n" << endl;
	}
};

 /*
Andrew Skalicky
V1: Project 1, February 8, 2017
V2: Project 2, March 3, 2017

This class is a subclass of Item, for Printer objects.
*/
class Printer : public Item
{

private:
	//variables specific to Printer objects
	int trayCapacity, network;

public:
	//default constructor
	Printer()
	{

	}

	//constructs a Printer object, while assigning variables
	Printer(int iId, int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t, int nrk, int tCap)
	{
		//variables shared with all Items
		itemId = iId;
		code = cde;
		color = col;
		brand = br;
		type = t;
		height = hght;
		length = lgth;
		width = wdth;
		weight = wght;
		price = p;

		//variables specific to Printer objects
		trayCapacity = tCap;
		network = nrk;
	}

	//returns trayCapacity of Printer object
	int getTCap()
	{
		return trayCapacity;
	}

	//returns indicator of whether or not a Printer has network access
	int getNetwork()
	{
		return network;
	}

	//creates an ostream operator for Printer objects
	friend ostream& operator << (ostream& s, Printer& printer)
	{
		printer.display();
		return s;
	}

	//outputs to console formatted Printer information
	void display()
	{
		//color, brand, and type are incremented, so that their names can be identified 
		//in one method, which is located in the superclass
		cout << "     Item Number: " << getItemId() << " Item Type: " << "Printer\n" << "       Color: " << getColorName(color + 4)
			<< "  Brand: " << getBrandName(brand + 4) << "  Height: " << getHeight() << "  Length: "
			<< getLength() << "  Width: " << getWidth() << "  Weight: " << getWeight() << "  Price: "
			<< getPrice() << "  Type: " << getTypeName(type + 4) << "  Network: " << yesOrNo(network)
			<< "  Tray Capacity: " << trayCapacity << "\n" << endl;

	}
};

/*
Andrew Skalicky
V1: Project 1, February 8, 2017
V2: Project 2, March 3, 2017

This class is a subclass of Item, for SafeBox objects.
*/
class SafeBox : public Item
{

private:
	//local variables
	int electronicLock, fireResistant;

public:
	//default constructor
	SafeBox()
	{

	}

	//constructs a SafeBox object, while setting variables
	SafeBox(int iId, int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t, int fRes, int eLoc)
	{
		//setting of variables that are shared among other Item objects
		itemId = iId;
		code = cde;
		color = col;
		brand = br;
		type = t;
		height = hght;
		length = lgth;
		width = wdth;
		weight = wght;
		price = p;

		//setting of variables specific to SafeBoxes
		electronicLock = eLoc;
		fireResistant = fRes;

	}

	//returns electronicLock variable
	int getElectronicLock()
	{
		return electronicLock;
	}

	//returns fireResistant variable
	int getFireResistant()
	{
		return fireResistant;
	}

	//creates an ostream operator for SafeBox objects
	friend ostream& operator << (ostream& s, SafeBox& safeBox)
	{
		safeBox.display();
		return s;
	}

	//outputs to console formatted SafeBox information
	void display()
	{
		//color, brand, and type are incremented, so that their names can be identified 
		//in one method, which is located in the superclass
		cout << "     Item Number: " << getItemId() << " Item Type: " << "Safe Box\n" << "      Color: " << getColorName(color + 6)
			<< " Brand: " << getBrandName(brand + 8) << " Height: " << getHeight() << " Length: "
			<< getLength() << " Width: " << getWidth() << " Weight: " << getWeight() << " Price: "
			<< getPrice() << " Type: " << getTypeName(type + 7) << " Fire Resistant: " << yesOrNo(fireResistant)
			<< " Electronic Lock: " << yesOrNo(electronicLock) << "\n" << endl;
	}
};

/*
Andrew Skalicky
V1: Project 2, March 3, 2017

This class is a containing class, that creates an array to store Item pointers.
*/
class Bag
{
protected:
	//local variables
	Item** myItems;
	int numItems, numPens, numPrinters, numSafeBoxes, found;
	double penPrice, printerPrice, safePrice;



public:
	//default constructor
	Bag()
	{
		//initializing variables
		myItems = new Item*[0];
		numItems = 0;
		numPens = 0;
		numPrinters = 0;
		numSafeBoxes = 0;
		penPrice = 0.0;
		printerPrice = 0.0;
		safePrice = 0.0;
	}

	//destructor
	~Bag()
	{
		//iterate through myItems making each space NULL
		for (int i = 0; i < numItems; ++i)
		{
			myItems[i] = NULL;
		}

		//delete the item
		delete[] myItems;
	}

	//This method adds an Item pointer to the Item pointer array, myItems
	void addItem(Item* addOn)
	{
		//constructing a dummy Item pointer array
		Item** temp = myItems;

		//make myItems a slightly larger Item pointer array
		myItems = new Item*[numItems++];

		//pass Item pointers from the dummy array to the new myItems
		for (int i = 0; i < numItems; ++i)
		{
			myItems[i] = new Item();
			myItems[i] = temp[i];
		}

		//add the new Item pointer to the end of myItems
		myItems[numItems - 1] = addOn;
	}

	//This method removes an Item pointer from myItems
	void removeItem(int remId)
	{
		//creates a new Item Pointer array
		Item** temp = new Item*[numItems];

		//make temp into a copy of myItems
		for (int i = 0; i < numItems; ++i)
		{
			temp[i] = myItems[i];
		}

		int place = 0;

		//make myItems a slightly smaller Item pointer array
		myItems = new Item*[numItems--];

		//initialize the new array
		for (int i = 0; i < numItems; ++i)
		{
			myItems[i] = new Item();
		}

		//move over items, excluding the one that is to be removes
		for (int o = 0; o < numItems + 1; ++o)
		{
			if (temp[o]->getItemId() == remId && found < 1)
			{
				found = 1;
			}
			else
			{
				myItems[place] = temp[o];
				place += 1;
			}
		}

		//delete the temp array
		delete[] temp;

	}

	//this method returns an item at a specific point in myItems
	Item* getItem(int index)
	{
		return myItems[index];
	}

	//returns the number of items
	int getNumItems()
	{
		return numItems;
	}

	//returns the number of pens
	int getNumPens()
	{
		return numPens;
	}

	//returns the number of printers
	int getNumPrinters()
	{
		return numPrinters;
	}

	//returns the number of safe boxes
	int getNumSafeBoxes()
	{
		return numSafeBoxes;
	}

	//returns the total pen price
	double getPenPrice()
	{
		return penPrice;
	}

	//returns the total printer price
	double getPrinterPrice()
	{
		return printerPrice;
	}

	//returns the total safe boxes price
	double getSafePrice()
	{
		return safePrice;
	}

	//creates an ostream operator for Bag objects
	friend ostream& operator << (ostream& s, Bag& bag)
	{
		bag.display();
		return s;
	}

	//outputs to console information about objects in myItems
	void display()
	{
		//iterates of objects in myItems
		for (int i = 0; i < numItems; ++i)
		{
			//checks what type of object the current iteration is
			switch (myItems[i]->getCode())
			{
			case 1:
				cout << *(static_cast<Pen*>(myItems[i])) << endl;
				numPens++;
				penPrice += myItems[i]->getPrice();
				break;
			case 2:
				cout << *(static_cast<Printer*>(myItems[i])) << endl;
				numPrinters++;
				printerPrice += myItems[i]->getPrice();
				break;
			case 3:
				cout << *(static_cast<SafeBox*>(myItems[i])) << endl;
				numSafeBoxes++;
				safePrice += myItems[i]->getPrice();
				break;
			default:
				cout << "UNREADABLE ITEM" << endl;
				break;
			}

		}
		//outputs totals for current user
		cout << "Totals for User:\n" << " Number of Items: " << getNumItems() << "\n Number of Pens: " << getNumPens() 
			<< "\n Total Price of Pens: $" << getPenPrice() << "\n Number of Printers: " << getNumPrinters() 
			<< "\n Total Price of Printers: $" << getPrinterPrice() << "\n Number of Safe Boxes: " << getNumSafeBoxes() 
			<< "\n Total Price of Safe Boxes: $" << getSafePrice() << "\n Total: $" << (getSafePrice() + getPrinterPrice() + getPenPrice()) << endl;
	}
	
};

/*
Andrew Skalicky
V1: Project 1, February 8, 2017
V2: Project 2, March 3, 2017

This is the main method of the program, where operations start and end.
*/
int main()
{

	int users[50];
	int numUsers = 0;

	Bag* userBag[50];
	Pen* onePen;
	Printer* onePrinter;
	SafeBox* oneSafeBox;

	onePen = new Pen();
	onePrinter = new Printer();
	oneSafeBox = new SafeBox();

	//construction of all variables needed to save data
	char command[8];
	int userLoc = 0;
	int userId, itemId, quantity, code, color, brand, type, variable1, variable2;
	int numPens = 0, numPrinters = 0, numSafeBoxes = 0, numItems = 0;
	double height, length, width, weight, price;
	double penPrice = 0.0, printerPrice = 0.0, safeBoxPrice = 0.0;


	for (int i = 0; i < 50; ++i)
	{
		userBag[i] = new Bag();
		users[i] = 0;
	}

	// other local variables     
	while (!cin.eof())
		// while end of line is not reached    
	{
		for (int i = 0; i < 8; ++i)
		{
			command[i] = '\0';
		}

		cin >> command >> userId >> itemId;

		if ((command[0] == 'D') == 1)
		{
			numItems--;
			for (int i = 0; i < numUsers; ++i)
			{
				if (users[i] == userId)
				{
					userLoc = i;
					break;
				}
			}

			cout << command << " " << userId << " " << itemId << endl;



			userBag[userLoc]->removeItem(itemId);
		}

		else
		{
			if (numUsers == 0)
			{
				++numUsers;
				users[0] = userId;
			}

			for (int i = 0; i < numUsers + 1; ++i)
			{
				if (users[i] == userId)
				{
					userLoc = i;
					break;
				}
				else if (users[i] == 0)
				{
					++numUsers;
					userLoc = i;
					users[i] = userId;
					break;
				}
			}

			cin >> quantity >> code >> color >> brand >> height >> length
				>> width >> weight >> price >> type >> variable1 >> variable2;

			//output initial data
			cout << command << " " << userId << " " << itemId << " " << quantity << " " << code << " " << color << " "
				<< brand << " " << height << " " << length << " " << width << " " << weight
				<< " " << price << " " << type << " " << variable1 << " " << variable2 << endl;

			//Based on code create the appropriate object and store it in the bag
			for (int x = 0; x < quantity; ++x)
			{
				numItems++;
				//Constructs object based on object code
				switch (code)
				{
				case 1:
				{
					//Construct pen object to put in bag
					userBag[userLoc]->addItem(new Pen(itemId, code, color, brand, height, length, width, weight, price, type, variable1, variable2));
					numPens++;
					penPrice += price;
					break;
				}

				case 2:
				{
					//Construct printer object to put in bag
					userBag[userLoc]->addItem(new Printer(itemId, code, color, brand, height, length, width, weight, price, type, variable1, variable2));
					numPrinters++;
					printerPrice += price;
					break;
				}

				case 3:
				{
					//Construct safe box object to put in bag
					userBag[userLoc]->addItem(new SafeBox(itemId, code, color, brand, height, length, width, weight, price, type, variable1, variable2));
					numSafeBoxes++;
					safeBoxPrice += price;
					break;
				}
				//else don't make object
				default:
				{
					break;
				}

				}

			}

		}

	}

	//add empty line
	cout << "" << endl;

	// Print objects in bag, using their individual display functions
	for (int i = 0; i < numUsers; ++i)
	{
		cout << "User: " << users[i] << "'s Items:" << endl;
		cout << *userBag[i] << endl;
	}

	return 0;
};