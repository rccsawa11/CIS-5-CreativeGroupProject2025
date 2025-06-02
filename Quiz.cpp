/* Creative Group Project - 
CIS / CSC - 5 Spring 2025 
Professor Sandra Ruiz 
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std; 

/* Program will : 
- greet the user
- let them choose a language
- ask 7 math questions
- displays the feedback after each question answered
- saves their score to a file and presents it to them
*/

string helloUser()
{
	string name;
	cout << "Please enter your name: "; 
	getline(cin, name);
	cout << "Hello and Welcome to the SUPER AWESOME MATH QUIZ " << name << "!" << endl;
	return name; 
}

string selectLanguage()
{
	string langChoice;
	cout << "This quiz has 3 world-wide-spoken language to choose from. \n" <<  "Please enter the number next to the language you chose.\n" << "1. English\n" << "2. Spanish\n" << "3. French\n" << endl;
	getline(cin, langChoice); 
	int choice = stoi(langChoice); // converts the choice into a number for if/else statements
	string lang; // will be the language stored
	if (choice == 1)
	{
		lang = "English";
		cout << "You've selected English." << endl;
	}
	else if (choice == 2)
	{
		lang = "Spanish";
		cout << "Has seleccionado el espanol." << endl;

	}
	else
	{
		lang = "French"; 
		cout << "Vous avez choisi le francais." << endl;
	}

	return lang; 
}





int main()
{
	helloUser(); // calling the funciton for name
	selectLanguage(); //calling funciton for language
	srand(time(0)); //a random number generator


	return 0;
}

const int numQues = 7; // fun facts in English

string funFactEnglish[numQues] = 
{
"Did you know? French is spoken on 5 continents!", 
"Spanish is the 2nd most spoken language in the world!", 
"English is used in international aviation and diplomacy!", 
"In Japan, students clean their classrooms every day!", 
"In Kenya, children learn in Swahili and English!", 
"Finland starts school later but scores high!", 
"India has more than 22 official languages!"
};
