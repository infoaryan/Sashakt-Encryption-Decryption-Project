#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>

using namespace std;

// Sashakt : Local system Encryption and Decryption software using c++

//Developed in C++14 environment

//Developed by : Dechan Dolker (195052) Aryan Verma(195011) Aviral(195023)  

//OBJECTIVE :  This is a encryption and decryption software designed using c++,
//capable of encrypting and decrypting single lines and also huge text. It works on
//substitution Cipher techniques - Caesar Cipher algorithm. It can directly take the 
//text or file name and perform the given operation.

//Input - encryption and decryption using caesar cipher algorithm
//Output - jshw~uynts%fsi%ijhw~uynts%zxnsl%hfjxfw%hnumjw%fqltwnymr

// Encryption Password : 111
// Decyption Password : 000

class EncryptionDecryption {
	private:
		string outputstring;
		string inputstring;
		string encpass;
		string decpass;
		int enckey;
		int deckey;
		int temp;
		char tempc;

		//function to do Encryption
		void doEncryption();
		//Function Overloading
		void doEncryption(int); 

		//function to do Decryption
		void doDecryption(); 
		//Function overloading
		void doDecryption(int);

	public:
		//initializer Default Constructor
		EncryptionDecryption(); 
		//parameterized constructor
		EncryptionDecryption(string); 	
		void setInputString(string); 
		//Destructor
		~EncryptionDecryption();
		// Methods for checking the passwords
		int checkEncPass(string,int);
		int checkDecPass(string, int);
		//get the encrypted string
		void getOutputString(); 

};

//Use this function to do Encryption
void EncryptionDecryption::doEncryption() {

	for(int i=0;i<inputstring.size();i++) {

		temp = (int)inputstring[i];
		temp = temp + enckey;
		tempc = (char)temp;
		outputstring += tempc;

		}
	//End of encryption function
}

//Overloaded for handling encryption of files
void EncryptionDecryption::doEncryption(int a){

	string fname; 
	char ch, choice;
	fstream fps, fpt;

	cout<<"Enter file name (with extension like- file.txt) to encrypt : ";
	getline(cin, fname);
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening file..!!";
		exit(1);
	}
	fpt.open("temp.txt", fstream::in | fstream::out | fstream::trunc);
	if(!fpt)
	{
		cout<<"Error in creating temp.txt file..!!";
		fps.close();
		exit(2);
	}
	while(fps.eof()==0)
	{
		fps>>ch;
		//Checking if the end character is not send there
		if(!(ch=='\n' && fps.eof())){
			ch=ch+5;
			fpt<<ch;
		}	
	}
	fps.close();
	fpt.close();
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening source file..!!";
		exit(3);
	}
	fpt.open("temp.txt");
	if(!fpt)
	{
		cout<<"Error in opening temp.txt file...!!";
		fps.close();
		exit(4);
	}
	while(fpt.eof()==0)
	{
		fpt>>ch;
		//Checking if the end character is not send there
		if(!(ch=='\n' && fpt.eof())){
			fps<<ch;
		}
		
	}
	cout << "\033[2J\033[1;1H";
	cout<<"\n\n!!!!!!!     File "<<fname<<" encrypted successfully    !!!!!!!!!";
	fps.close();
	fpt.close();
	remove("temp.txt");
}

//Use this function to do Decryption
void EncryptionDecryption::doDecryption() {

	for(int i=0;i<inputstring.size();i++) {

		temp = (int)inputstring[i];
		temp = temp + deckey;
		tempc = (char)temp;
		outputstring += tempc;

		}
	//End of decryption function

}

void EncryptionDecryption::doDecryption(int a){
	string fname; 
	char ch, choice;
	fstream fps, fpt;

	cout<<"Enter file name (with extension like- file.txt) to decrypt : ";
	getline(cin, fname);
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening file..!!";
		exit(1);
	}
	fpt.open("temp.txt", fstream::in | fstream::out | fstream::trunc);
	if(!fpt)
	{
		cout<<"Error in creating temp.txt file..!!";
		fps.close();
		exit(2);
	}
	while(fps.eof()==0)
	{
		fps>>ch;

		//Checking if the end character is not there
		if(!(ch=='\n' && fps.eof())){
			ch=ch-5;
			fpt<<ch;
		}
	}
	fps.close();
	fpt.close();
	fps.open(fname);
	if(!fps)
	{
		cout<<"Error in opening source file..!!";
		exit(3);
	}
	fpt.open("temp.txt");
	if(!fpt)
	{
		cout<<"Error in opening temp.txt file...!!";
		fps.close();
		exit(4);
	}
	while(fpt.eof()==0)
	{
		fpt>>ch;
		//restained the coying of null character
		if(!(ch=='\n' && fpt.eof())){
			fps<<ch;
	}
	}
	cout << "\033[2J\033[1;1H";
	cout<<"\n\n!!!!!!!!     File "<<fname<<" decrypted successfully..  !!!!!!!!";
	fps.close();
	fpt.close();
	remove("temp.txt");
}

void EncryptionDecryption::getOutputString() {
	outputstring += '\0';
	cout << "\033[2J\033[1;1H";

	cout << "\n\n!!!!!!  The Encrypted/Decrypted string is"  <<" : "<<outputstring<<"      !!!!!!";	
	outputstring="";
}

//first check the password
int EncryptionDecryption::checkEncPass(string pass, int a=0) {

	//check password before encrypting
	//Here Default Argument have been used 
	if(pass!=encpass)
	{	
		cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
		return 0;
	}	
	else if(a==0){
		doEncryption();
		return 1;
	}

	else{
		//Calling the overloaded function here
		//Using a default integer
		doEncryption(10);
		return 1;
	}

}

//first check the password
int EncryptionDecryption::checkDecPass(string pass, int a=0) {

	//check password before encrypting
	if(pass!=decpass)
	{	
		cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
		return 0;
	}	
	else if(a==0){
		doDecryption();
		return 1;
	}	
	else{
		//Calling the overloaded function 
		//using teh default argment integer
		doDecryption(10);
		return 1;
	}	
}

//Initializer
EncryptionDecryption::EncryptionDecryption() {

	inputstring = "";
	outputstring = "";
	encpass= "111"; //this is the password
	decpass= "000";
	enckey= 5; //this is the key
	deckey= -1 * enckey;
	temp= 0;
	tempc='\0';

}

EncryptionDecryption::EncryptionDecryption(string e) { 
	inputstring = e;
}

void EncryptionDecryption::setInputString(string f) {
	inputstring=f;
}

EncryptionDecryption::~EncryptionDecryption() {
}

//The program begins here
int main() 
{
	//Command to clear the screen at regular intervals
	cout << "\033[2J\033[1;1H";
	string inputstring;
	string pass;
	char ch;
	bool quit=false;
	EncryptionDecryption O1; //creating object

	cout<<"+++++++++ Welcome to the project SASHAKT : Enabling security ++++++++++++\n";
	cout<<right<<setw(70)<<"-Developed Jointly by Dechan, Aryan, Aviral :)\n\n";
	cout<<"The project is developed to enable seurity for the personal text like passwords\n";
	cout<<"and crucial information by making them present in a un-readable manner, hence\n";
	cout<<"Encryption and decryption.\nYou can encrypt and decrypt a single word or a text stored in a file\n";
	cout<<"just in time of moments. Software includes the concepts of OOPs and algorithms !!\n";

	//Starting the loop to take the instructions

	while(!quit)
	{
		//Which operation you want to perform
		cout << "\n===================================================\n";
		cout << "1. Encryption of string (Single word or line)\n\n";
		cout << "2. Decryption of string (Single Word or line)\n\n";
		cout << "3. Encryption of file   (For multiple lines)\n\n";
		cout << "4. Decryption of file   (For multiple lines)\n\n";
		cout << "5. Quit\n";
		cout << "*****************************************************";
		quit = false;
		cout << "\n\nEnter the choice to perform the task";
		cout << "\nEnter 1 or 2 or 3 or 4 or 5:   ";	
		cin >> ch;

		//Ensuring that only integral value in entered
		if(ch>57 || ch<48){
			cout<<"\n\nPlease enter a integral value XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
			cout<<"********************** TRY AGAIN *****************************************\n\n";
			continue;
		}
		
		switch(ch)
		{

				case '1':
					cout << "Enter a word to Encrypt: ";
					cin.ignore();
					getline(cin, inputstring);
						
					O1.setInputString(inputstring); 
					//set the encryption text
					
					cout << "Enter the password (111) to proceed Encryption: ";
					getline(cin, pass);
					
					if(O1.checkEncPass(pass)==1) { 
						//check encryption password and then do encryption if the password is correct
						O1.getOutputString();
					}
					else {
						break;
					}
		
					break;

				case '2':
					cout << "Enter word to Decrypt: ";
					cin.ignore();
					getline(cin, inputstring);

					O1.setInputString(inputstring); 
					//set the decryption string

					cout << "Enter the password (000) to proceed Decryption: ";
					getline(cin, pass);
					
					if(O1.checkDecPass(pass)==1) { 
						//check decryption password and then do decryption if the password is correct
						O1.getOutputString();
					}
					else {
						break;
					} 		
					break;

				case '3':
					//calling the overloaded encrypting function for files.
					cout << "Enter the password (111) to proceed Encryption: ";
					cin.ignore();
					getline(cin, pass);
					
					if(O1.checkEncPass(pass,10)==1) { 
						//check encryption password and then do encryption if the password is correct
					}
					else {
						break;
					}
					break;

				case '4' :
					//calling the overloaded decrypting function for files.
					cout << "Enter the password (000) to proceed Decryption: ";
					cin.ignore();
					getline(cin, pass);
					
					if(O1.checkDecPass(pass,10)==1) { 
						//check decryption password and then do decryption if the password is correct
					}
					else {
						break;
					}
					break;

				case '5':
						cout<< "-------------------Exiting the program----------------------------------\n\n";
						cout<<"**********************THANKS FOR USING SASHAKT*****************************\n";
						quit=true;
						break;
				case '\n':
        		case '\t':
        		case ' ':
            			break;			   
				default:
						cout<<"\n\n----------------Please enter the value in range !!-------------------\n\n";
						continue;
			}
		cout << "\n\n";
	}

	return 0;
}