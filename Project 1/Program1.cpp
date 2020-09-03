#include <iostream>
using namespace std;
/*
	Andrew Skalicky
	Program 1
	February 8, 2017

	This class is the parent class for Pen, Printer, and SafeBox

*/
class Item
{

public:
	//class variables needed for and shared between
	//Pen, Printer, and SafeBox
	double height, length, width, weight, price;
	int code, color, brand, type;

	//default constructor
	Item()
	{

	}

	//constructor where all variables are taken and assigned to local variable
	Item(int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t)
	{
		code = cde;
		color = col;
		brand = br;
		type = t;
		height = hght;
		length = lgth;
		width = wdth;
		weight = wght;
		price = p;
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

};

/*
		Andrew Skalicky
		Program 1
		February 8, 2017

		This class is a subclass of Item, for Pen objects
*/

class Pen : public Item
{
public:
	//default constructor
	Pen()
	{

	}

	//constructs a pen object, while setting variables
	Pen(int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t, int aInk, int pSize)
	{
		//setting of variables obtained from Item
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

	//outputs to console formatted Pen information
	void display()
	{
		cout << "Item: " << "Pen\n" << "  Color: " << getColorName(color)
			<< "  Brand: " << getBrandName(brand) << "  Height: " << getHeight() << "  Length: "
			<< getLength() << "  Width: " << getWidth() << "  Weight: " << getWeight() << "  Price: "
			<< getPrice() << "  Type: " << getTypeName(type) << "  Assorted Ink: " << yesOrNo(assortedInk)
			<< "  Packet Size: " << getPacSize() << "\n" << endl;
	}

private:
	//local variables
	int packetSize;
	int assortedInk;
};

/*
	Andrew Skalicky
	Program 1
	February 8, 2017

	This class is a subclass of Item, for Printer objects.
*/
class Printer : public Item
{

public:
	//default constructor
	Printer()
	{

	}

	//constructs a Printer object, while assigning variables
	Printer(int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t, int nrk, int tCap)
	{
		//variables shared with all Items
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

	//outputs to console formatted Printer information
	void display()
	{
		//color, brand, and type are incremented, so that their names can be identified 
		//in one method, which is located in the superclass
		cout << "Item: " << "Printer\n" << "  Color: " << getColorName(color + 4)
			<< "  Brand: " << getBrandName(brand + 4) << "  Height: " << getHeight() << "  Length: "
			<< getLength() << "  Width: " << getWidth() << "  Weight: " << getWeight() << "  Price: "
			<< getPrice() << "  Type: " << getTypeName(type + 4) << "  Network: " << yesOrNo(network)
			<< "  Tray Capacity: " << trayCapacity << "\n" << endl;

	}

private:
	//variables specific to Printer objects
	int trayCapacity, network;
};

/*
	Andrew Skalicky
	Program 1
	February 8, 2017

	This class is a subclass of Item, for SafeBox objects.
*/
class SafeBox : public Item
{

public:
	//default constructor
	SafeBox()
	{

	}

	//constructs a SafeBox object, while setting variables
	SafeBox(int cde, int col, int br, double hght, double lgth, double wdth, double wght, double p, int t, int fRes, int eLoc)
	{
		//setting of variables that are shared among other Item objects
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

	//outputs to console formatted SafeBox information
	void display()
	{
		//color, brand, and type are incremented, so that their names can be identified 
		//in one method, which is located in the superclass
		cout << "Item: " << "Safe Box\n" << " Color: " << getColorName(color + 6)
			<< " Brand: " << getBrandName(brand + 8) << " Height: " << getHeight() << " Length: "
			<< getLength() << " Width: " << getWidth() << " Weight: " << getWeight() << " Price: "
			<< getPrice() << " Type: " << getTypeName(type + 7) << " Fire Resistant: " << yesOrNo(fireResistant)
			<< " Electronic Lock: " << yesOrNo(electronicLock) << "\n" << endl;
	}

private:
	//local variables
	int electronicLock, fireResistant;
};

	/*
		Andrew Skalicky
		Program 1
		February 8, 2017

		This is the main method of the program, where operations start and end.
	*/
int main()
{
	//construct bag, which is an array of Item pointers
	Item* Bag[256];
	Pen* onePen;
	Printer* onePrinter;
	SafeBox* oneSafeBox;

	onePen = new Pen();
	onePrinter = new Printer();
	oneSafeBox = new SafeBox();

	//construction of all variables needed to save data
	char command[8];
	int quantity, code, color, brand, type, variable1, variable2;
	int numPens = 0, numPrinters = 0, numSafeBoxes = 0, bagCount = 0, numItems = 0;
	double height, length, width, weight, price;
	double penPrice = 0, printerPrice = 0, safeBoxPrice = 0;

	//initialize all spaces in the bag
	for (int o = 0; o < 256; ++o)
	{
		Bag[o] = NULL;
	}

	// other local variables     
	while (!cin.eof())
		// while end of line is not reached    
	{
		//read a line and set variables
		cin >> command >> quantity >> code >> color >> brand >> height >> length
			>> width >> weight >> price >> type >> variable1 >> variable2;

		//output initial data
		cout << command << " " << quantity << " " << code << " " << color << " "
			<< brand << " " << height << " " << length << " " << width << " " << weight
			<< " " << price << " " << type << " " << variable1 << " " << variable2 << endl;

		//Based on code create the appropriate object and store it in the bag
		for (int x = 0; x < quantity; ++x)
		{
			//Constructs object based on object code
			switch (code)
			{
			case 1:
			{
				//Construct pen object to put in bag
				Bag[bagCount] = new Pen(code, color, brand, height, length, width, weight, price, type, variable1, variable2);

				//increment number of pens and add new price to current total of prices
				numPens += 1;
				penPrice += price;
				break;
			}

			case 2:
			{
				//Construct printer object to put in bag
				Bag[bagCount] = new Printer(code, color, brand, height, length, width, weight, price, type, variable1, variable2);

				//increment number of printer and add new price to current total of prices
				numPrinters += 1;
				printerPrice += price;
				break;
			}

			case 3:
			{
				//Construct safe box object to put in bag
				Bag[bagCount] = new SafeBox(code, color, brand, height, length, width, weight, price, type, variable1, variable2);

				//increment number of safe boxes and add new price to current total of prices
				numSafeBoxes += 1;
				safeBoxPrice += price;
				break;
			}
			//else don't make object
			default:
			{
				break;
			}

			}
			//increment number of objects in the bag
			bagCount += 1;
		}
	}

	//add empty line
	cout << "" << endl;

	// Print objects in bag, using their individual display functions
	for (int i = 0; i < bagCount; ++i)
	{
		switch ((*Bag[i]).getCode())
		{
			case 1:
			{//Pens
				(static_cast<Pen*>(Bag[i]))->display();
				break;
			}
			case 2:
			{//Printers
				(static_cast<Printer*>(Bag[i]))->display();
				break;
			}
			case 3:
			{//Safe Box
				(static_cast<SafeBox*>(Bag[i]))->display();
				break;
			}
			default:
			{
				cout << "I do not recognize this Item in the Bag" << endl;
				break;
			}
		}
	}
		// Summary of all Statistics
		cout << "" << endl;
		cout << "Total Number of Items: " << bagCount << endl;
		cout << "" << endl;
		cout << "Number of Pens: " << numPens << endl;
		cout << "Total Price of Pens: " << penPrice << endl;
		cout << "" << endl;
		cout << "Number of Printers: " << numPrinters << endl;
		cout << "Total Price of Printers: " << printerPrice << endl;
		cout << "" << endl;
		cout << "Number of Safe Boxes: " << numSafeBoxes << endl;
		cout << "Total Price of Safe Boxes: " << safeBoxPrice << endl;

		return 0;
	}
