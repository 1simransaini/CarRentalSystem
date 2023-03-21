/*
	Concepts in the program
	
	-> concept of class and object
	-> class inheritance
	-> if else statements
	-> file handling
	-> while statements
	-> setwidth
	-> sleep function
*/

//CAR RENTAL SYSTEM IN C++ PROGRAMMING LANGUAGE
#include <iostream>  //input/output
#include <fstream>		//file
#include <unistd.h>   //sleep
#include <iomanip>  //setting width
#include <ctime>	//time

using namespace std;

// customer class
class Customer 
{
	protected:
		string customer_Name; 
	    int car_model;
	    int car_Number;
        int no_of_cars;
};

//Rent class
// inhereted class from customer class
class Rent : public Customer 
{
	private:
		// additional integer variables defined
		int numberOfDays;
		int rent_Fee;
		char str[200];		//A character array in which to store the data with Maximum number of characters to extract.
	public:	
		Rent();
		void welcome();
		void fileReader(char carFile[20]);
		void data();
		void invoiceAmount();	//Computes 
		void invoiceRecord();  //Prints the invoice 		
};

Rent::Rent(){
	numberOfDays = 0;
	rent_Fee = 0;
}

void Rent::welcome(){
	ofstream O;
	O.open("welcome.txt");
	O<<"    _________    ____       ____  _______   ___________    __       _______  _____________________  ___\n   / ____/   |  / __ \\     / __ \\/ ____/ | / /_  __/   |  / /      / ___/\\ \\/ / ___/_  __/ ____/  |/  /\n  / /   / /| | / /_/ /    / /_/ / __/ /  |/ / / / / /| | / /       \\__ \\  \\  /\\__ \\ / / / __/ / /|_/ /\n / /___/ ___ |/ _, _/    / _, _/ /___/ /|  / / / / ___ |/ /___    ___/ /  / /___/ // / / /___/ /  / / \n \\____/_/  |_/_/ |_|    /_/ |_/_____/_/ |_/ /_/ /_/  |_/_____/   /____/  /_//____//_/ /_____/_/  /_/ \n  \n\n\t\t\t\t\t\t\t\t\t\t\t\t-PRESENTED BY\n \t\t\t\t\t\t\t\t\t\t\t\t-SIMRAN (2116314)\n \t\t\t\t\t\t\t\t\t\t\t\t-SIMRAN SAINI (2116315)\n \t\t\t\t\t\t\t\t\t\t\t\t-SRISHTI MITTAL (2116323)	";
	O.close();						
	ifstream inputFile("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353
	if(!inputFile) {
		cout << "Cannot open input file.\n";
	}
	char str[1000];
	while(inputFile) {
		inputFile.getline(str, 1000);  // delim defaults to '\n' cp
		if(inputFile) 
			cout << str << endl;
  	}
  	inputFile.close();
	sleep(1);
	cout<<"\nStarting the program please wait....."<<endl;
	sleep(1);
	cout<<"\nloading up files....."<<endl;
}
		
void Rent::fileReader(char carFile[20]){
	ifstream inputFile;
	inputFile.open(carFile); //displaying details of model A
	if(!inputFile){
		cout << "Error in printing file. File not found!" << endl;
	}
	while(inputFile) {
		inputFile.getline(str, 200);  
		if(inputFile) 
			cout << str << endl;
		}
}	
void Rent::data(){
	cout << "\n\n\t\t\t\tPlease Enter your Name: "; 	//taking data from the user
  	cin >> customer_Name;
	cout<<endl;
		label2:
        do{
            //giving user a choice to select among three different models
            cout << "\t\t\t\t__________________________________________________________________"<<endl;
            cout << "\t\t\t\tChoose a Car from the options below. \n ";
            cout <<	"\t\t\t\tChoose a number corresponding to the car you want to Select." << endl; 
            cout << "\t\t\t\t__________________________________________________________________"<<endl;
            cout << "\t\t\t\t1. Toyota 2021."<<endl;
            cout << "\t\t\t\t2. Hyundai 2019."<<endl;
            cout << "\t\t\t\t3. Ford 2020."<<endl;
            cout << endl;
            cout << "\t\t\t\t__________________________________________________________________"<<endl;
            cout << "\n\t\t\t\tChoose: ";
            cin >> car_model;
            cout << endl;
			ofstream O;
			ifstream I1,I2,I3;
            switch(car_model){
                case 1:
                    cout<<"You have choosed Toyota model 2021\n"<<endl;
                    O.open("Toyota.txt");
					O<<"Specifications:\n\n40 kWh and 60 kWh\nRange					EPA: 139 mi 224 km	EPA: 210 mi 340 km\n	Max. power, motor			382 hp 285 kW		382 hp 285 kW\nMax. power, battery			235 hp 175 kW		302 hp 225 kW \n\n";
					O.close();
					I1.open("Toyota.txt");
					if(!I1) {
						cout << "Cannot open input file.\n";
					}
					char s1[1000];
					while(I1) {
						I1.getline(s1, 1000);  // delim defaults to '\n' cp
						if(I1) 
							cout << s1 << endl;
					}
					I1.close();
                    sleep(2);
                    break;
                case 2:
                    cout<<"You have choosed Hyundai model 2019\n"<<endl;
                    O.open("Hyundai.txt");
					O<<"Specifications:\n\n80 kWh and 90 kWh\nRange					EPA: 139 mi 224 km	EPA: 210 mi 340 km 	\nMax. power, motor			302 hp 285 kW		562 hp 285 kW\nMax. power, battery			265 hp 175 kW		902 hp 225 kW \n\n";
					O.close();
					I2.open("Hyundai.txt");
					if(!I2) {
						cout << "Cannot open input file.\n";
					}
					char s2[1000];
					while(I2) {
						I2.getline(s2, 1000);  // delim defaults to '\n' cp
						if(I2) 
							cout << s2 << endl;
					}
					I2.close();
                    sleep(2);
                    break;	
                case 3:
                    cout<<"You have choosed Ford model 2020\n"<<endl;
                    O.open("Ford.txt");
					O<<"Specifications:\n\n50 kWh and 80 kWh\nRange					EPA: 139 mi 224 km	EPA: 210 mi 340 km 	\nMax. power, motor			682 hp 285 kW		682 hp 285 kW\nMax. power, battery			935 hp 175 kW		802 hp 225 kW \n\n";
					O.close();
					I3.open("Ford.txt");
					if(!I3) {
						cout << "Cannot open input file.\n";
					}
					char s3[1000];
					while(I3) {
						I3.getline(s3, 1000);  // delim defaults to '\n' cp
						if(I3) 
							cout << s3 << endl;
					}
					I3.close();
                    sleep(2);
                    break;  			
                default:
                    cout<<"Invaild Car Model. Please try again!"<<endl;
            }
			char ch;
			cout<<"\n\nDo you want to proceed with this car?(Y/N): ";
			cin>>ch;
			if(ch=='N') goto label2;
        }while(car_model < 1 && car_model > 3);
	cout<<"________________________________________________________________________________________________\n"<<endl;
  	cout << "Please provide following information:"<<endl; 
	    	
	//getting data from user related to rental service
	int lb = 3674, ub = 9999;
    car_Number=(rand() % (ub - lb + 1)) + lb;
	cout<<"Number of days you wish to rent the car : ";
	cin >> numberOfDays;
	cout<<endl;
}

void Rent::invoiceAmount(){
	sleep(1);
	cout<<"Calculating rent. Please wait......"<<endl;
	sleep(2);
	if(car_model == 1)
		rent_Fee = numberOfDays*150;
	if(car_model == 2)
		rent_Fee = numberOfDays*160;
	if(car_model == 3)
		rent_Fee = numberOfDays*175;
}
	   
void Rent::invoiceRecord(){
	time_t now  = time(0);		//getting local time 
	char *date = ctime(&now); 	//Converting toa string 
	cout << setw(80) << date << endl;
	cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<"#1001"<<" |"<<endl;  //can be automatically generated
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<customer_Name<<" |"<<endl;
	cout << "\t\t	| Car Model  "<<"					|"<< setw(10) <<car_model<<" |"<<endl;     //car model
	cout << "\t\t	| Car No.  "<<"					|"<< setw(10) <<car_Number<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<numberOfDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rent_Fee<<" |"<<endl;
	cout << "\t\t	| Caution Money  "<<"				|"<< setw(10) <<"0"<<" |"<<endl;      //Can be calculated 
	cout << "\t\t	| Advanced  "<<"					|"<< setw(10) <<"0"<<" |"<<endl;		//Can be calculated 
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << rent_Fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signature."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
	cout << "\t\t	***********************************************************\n\n" << endl;

	system("PAUSE");
}

int main(){

	//Object created for rent class and further member functions are called.
	system("CLS");
	Rent rent; 
	rent.welcome();
	label:
	rent.data();
	rent.invoiceAmount();
	rent.invoiceRecord();
	char ch;
	cout<<"Do you want more cars on rent?(Y/N) : ";
	cin>>ch;
	if(ch=='Y') goto label;
	ofstream O;
	O.open("thanks.txt");
	O<<" ________  __                            __              __      __                         __  __\n/        |/  |                          /  |            /  \\    /  |                       /  |/  |\n$$$$$$$$/ $$ |____    ______   _______  $$ |   __       $$  \\  /$$/______   __    __       $$ |$$ |\n   $$ |   $$      \\  /      \\ /       \\ $$ |  /  |       $$  \\/$$//      \\ /  |  /  |      $$ |$$ |\n   $$ |   $$$$$$$  | $$$$$$  |$$$$$$$  |$$ |_/$$/         $$  $$//$$$$$$  |$$ |  $$ |      $$ |$$ |\n   $$ |   $$ |  $$ | /    $$ |$$ |  $$ |$$   $$<           $$$$/ $$ |  $$ |$$ |  $$ |      $$/ $$/ \n   $$ |   $$ |  $$ |/$$$$$$$ |$$ |  $$ |$$$$$$  \\           $$ | $$ \\__$$ |$$ \\__$$ |       __  __ \n   $$ |   $$ |  $$ |$$    $$ |$$ |  $$ |$$ | $$  |          $$ | $$    $$/ $$    $$/       /  |/  |\n   $$/    $$/   $$/  $$$$$$$/ $$/   $$/ $$/   $$/           $$/   $$$$$$/   $$$$$$/        $$/ $$/ \n\n";
	O.close();
	ifstream inputFile("thanks.txt");
	if(!inputFile) {
		cout << "Cannot open input file.\n";
	}
	char str[1000];
	while(inputFile) {
		inputFile.getline(str, 1000);  // delim defaults to '\n' cp
		if(inputFile) 
			cout << str << endl;
  	}
  	inputFile.close();
	return 0;
}