/* 

Creative Group Project 

CIS / CSC - 5 Spring 2025 Professor Sandra Ruiz 

Authors: 
Anastasio Jose Martinez 
Leen Sawas 
Bruno Ceron

 Program will :
- greet the user
- let them choose a language
- ask 7 math questions at a 4th grade level- all arithmetic
- displays the feedback after each question answered
- displays a fun fact from around the world after a correct answer
- saves their score and presents it to them at the end of the program

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <fstream>

//We found that we were cointenuisely getting the same questions generated, so we decided to
//find a work aorund that by including the ctime package to have different random values 
//each time the program is run

using namespace std; 
const int numQues = 7; //number of questions = 7

// getting name of user by using cin for them to type in and retrive a string to store into 'name' variable
string helloUser(string language)
{
		string name;
		if (language == "English") {
			cout << "\nPlease enter your name: ";
		}
		else if (language == "Spanish") {
			cout << "\nPor favor, ingresa tu nombre: ";
		}
		else {
			cout << "\nVeuillez entrer votre nom : ";
		}

		getline(cin, name);

		if (language == "English") {
			cout << "\nHello and welcome to the SUPER AWESOME MATH QUIZ, " << name << "!" << endl;
		}
		else if (language == "Spanish") {
			cout << "\nHola y bienvenido al SUPER INCREIBLE QUIZ DE MATEMATICAS, " << name << "!" << endl;
		}
		else {
			cout << "\nBonjour et bienvenue au SUPER QUIZ DE MATHEMATIQUES, " << name << "!" << endl;
		}

		return name;
}

string selectLanguage()
{
	// giving the user an option between 3 languages to play in
	// They will input their choice from 1-3, 
	// value stored into langChoice as a string and then converted to an int by stoi()
	// if statements to confirm language choice with user and store language choice
	// 1 = English, 2 = Spanish, 3 = French

	string langChoice;
	cout << "Please select a language / Por favor selecciona un idioma / Veuillez sélectionner une langue:\n";
	cout << "1. English\n2. Espanol\n3. Francais\n" << endl;
	getline(cin, langChoice);
	int choice = stoi(langChoice); // converts the choice into a number for if/else statements
	string lang; // will be the language stored
	//repeated logic in different language
	if (choice == 1)
	{
		lang = "English";
		cout << "\nYou've selected English." << endl;
	}
	else if (choice == 2)
	{
		lang = "Spanish";
		cout << "\nHas seleccionado espanol." << endl;

	}
	else
	{
		lang = "French"; 
		cout << "\nVous avez choisi le francais." << endl;
	}

	return lang; 
}

//the arrays of different fun facts around the world 
// repeated logic in all different languages
string funFactSpanish [ ] =
{
	"Aqui hay un dato curioso!\nSabias que el frances se habla en cinco continentes?\n", 
	"Aqui hay un dato curioso!\nSabias que chespirito interpreto a mas de 10 personajes en television!\n", 
	"Aqui hay un dato curioso!\nLos tacos de pastor son los mas famosos de todo el mundo!\n", 
	"Aqui hay un dato curioso!\nLos Angeles es la segunda ciudad con mas mexicanos en el mundo!\n", 
	"Aqui hay un dato curioso!\nEl chicharito es el maximo goleador de la seleccion mexicana de futbol!\n", 
	"Aqui hay un dato curioso!\nMexico es el tercer pais mas visitado en las vacaciones en el mundo!\n", 
	"Aqui hay un dato curioso!\nAvatar es la pelicula que mas dinero ha recaudado de la historia!\n"
}; 

string funFactEnglish [ ] = 
{
	"Here's a fun fact!\nDid you know? French is spoken on 5 continents!\n", 
	"Here's a fun fact!\nSpanish is the 2nd most spoken language in the world!\n", 
	"Here's a fun fact!\nEnglish is used in international aviation and diplomacy!\n", 
	"Here's a fun fact!\nIn Japan, students clean their classrooms every day!\n", 
	"Here's a fun fact!\nIn Kenya, children learn in Swahili and English!\n", 
	"Here's a fun fact!\nFinland starts school later but scores high!\n", 
	"Here's a fun fact!\nIndia has more than 22 official languages!\n"
};

string funFactFrench [ ] = 
{
	"Voici un fait amusant !\nLe francais est parle sur cinq continents !\n", 
	"Voici un fait amusant !\nL'espagnol est la 2e langue la plus parlee au monde !\n", 
	"Voici un fait amusant !\nL'anglais est utilise dans l'aviation et la diplomatie !\n", 
	"Voici un fait amusant !\nAu Japon, les eleves nettoient leurs classes chaque jour !\n", 
	"Voici un fait amusant !\nAu Kenya, les enfants apprennent le swahili et l'anglais !\n", 
	"Voici un fait amusant !\nLa Finlande commence l'ecole tard mais reussit tres bien !\n", 
	"Voici un fait amusant !\nL'Inde a plus de 22 langues officielles !\n"
}; 

// this funciton will ask the user the arithmetic 4th grade questions
// it is a boolean because it returns true or false in terms of getting the answer correct
// Uses random num generator to keep making questions
bool askQues(string language, bool usedFacts[]) 
// boolean will return 1 for true and 0 for false, so we chose to track points that way
{
	const int maxNum = 20; //assigns numbers from 0-20
	int firstNum = rand() % maxNum;
	int secondNum = rand() % maxNum;
	int correctAns; 
	int input;
	int factIndex; 
	// we kept getting repeated facts in our program so we had to add a
	// way to prevent repeated facts
	do
	{
		factIndex = rand() % numQues;
	} while (usedFacts[factIndex]);
	usedFacts[factIndex] = true;

	// we are assigning 0, 1, 2, and 3 to operators in math:
	// 0 = multiplication, 
	// 1 = addition, 
	// 2 = subtraction, 
	// 3 = division, 

	int operRator = rand() % 4; //picks one randomly from the 4 options
	
	if (language == "English") 
	{
		if (operRator == 1)
		{
			cout << "What would " << firstNum << "+" << secondNum << " be?" << endl;
			correctAns = firstNum + secondNum; // this is the actual right answer
			cin >> input; // player will input their answer
			cin.ignore(); //ignores the extra line produced by cin 
			if (input == correctAns) //comparing answer to right answer in if/else statement
			{
				cout << "\nGreat Job! +1 point to total score.\n" << endl;
				cout << funFactEnglish[factIndex] << endl; // returns a unique fun fact
			}
			else
			{
				cout << "\nOops... wrong answer!\n" << endl;
			}

			return input == correctAns; // returns either true or false
		}
		else if (operRator == 2)
		{
			cout << "What would " << firstNum << "-" << secondNum << " be?" << endl;
			correctAns = firstNum - secondNum;
			cin >> input; 
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nGreat Job! +1 point to total score.\n" << endl;
				cout << funFactEnglish[factIndex] << endl;
			}
			else
			{
				cout << "\nOops... wrong answer!\n" << endl;
			}
			return input == correctAns;
		}
		else if (operRator == 3)
		{
			if (secondNum == 0) // preventing divison by zero -> UNDEF and 4th graders do not know this
			{
				secondNum = 1;
			}
			cout << "What would " << firstNum << "/" << secondNum << " be? \nDisregard the decimal points.\n" << endl;
			correctAns = firstNum / secondNum;
			cin >> input; 
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nGreat Job! +1 point to total score.\n" << endl;
				cout << funFactEnglish[factIndex] << endl;
			}
			else
			{
				cout << "\nOops... wrong answer!\n" << endl;
			}
			return input == correctAns;
		}
		else
		{
			cout << "What would " << firstNum << "x" << secondNum << " be?" << endl;
			correctAns = firstNum * secondNum;
			cin >> input; 
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nGreat Job! +1 point to total score.\n" << endl;
				cout << funFactEnglish[factIndex] << endl;
			}
			else
			{
				cout << "\nOops... wrong answer!\n" << endl;
			}
			return input == correctAns;
		}
	} // end code for english 

	else if (language == "Spanish") //spanish - repeated logic in different language
	{
		if (operRator == 1)
		{
			cout << "Cuanto es " << firstNum << "+" << secondNum << " ?" << endl;
			correctAns = firstNum + secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBuen trabajo! +1 punto para ti.\n" << endl;
				cout << funFactSpanish[factIndex] << endl;
			}
			else
			{
				cout << "\nUy... respuesta incorrecta.\n" << endl;
			}

			return input == correctAns;
		}
		else if (operRator == 2)
		{
			cout << "Cuanto es " << firstNum << "-" << secondNum << " ?" << endl;
			correctAns = firstNum - secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBuen trabajo!  +1 punto para ti.\n" << endl;
				cout << funFactSpanish[factIndex] << endl;
			}
			else
			{
				cout << "\nUy... respuesta incorrecta.\n" << endl;
			}
			return input == correctAns;
		}
		else if (operRator == 3)
		{
			if (secondNum == 0)
			{
				secondNum = 1;
			}
			cout << "Cuanto es " << firstNum << "/" << secondNum << " ? \nSin importar el punto decimal.\n" << endl;
			correctAns = firstNum / secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBuen trabajo! +1 punto para ti.\n" << endl;
				cout << funFactSpanish[factIndex] << endl;
			}
			else
			{
				cout << "\nUy... respuesta incorrecta.\n" << endl;
			}
			return input == correctAns;
		}
		else
		{
			cout << "Cuanto es " << firstNum << "x" << secondNum << " ?" << endl;
			correctAns = firstNum * secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBuen trabajo!  +1 punto para ti.\n" << endl;
				cout << funFactSpanish[factIndex] << endl;
			}
			else
			{
				cout << "\nUy... respuesta incorrecta.\n" << endl;
			}
			return input == correctAns;
		}
	}
	else // french- repeated logic in different language
	{
		if (operRator == 1)
		{
			cout << "Combien font " << firstNum << "+" << secondNum << " ?" << endl;
			correctAns = firstNum + secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBravo ! +1 point pour toi.\n" << endl;
				cout << funFactFrench[factIndex] << endl;
			}
			else
			{
				cout << "\nOups... mauvaise reponse.\n" << endl;
			}

			return input == correctAns;
		}
		else if (operRator == 2)
		{
			cout << "Combien font " << firstNum << "-" << secondNum << " ?" << endl;
			correctAns = firstNum - secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBravo ! +1 point pour toi.\n" << endl;
				cout << funFactFrench[factIndex] << endl;
			}
			else
			{
				cout << "\nOups... mauvaise reponse.\n" << endl;
			}
			return input == correctAns;
		}
		else if (operRator == 3)
		{
			if (secondNum == 0) // prevents divison by 0
			{
				secondNum = 1;
			}
			cout << "Combien font " << firstNum << "/" << secondNum << " ? \nSin importar el punto decimal.\n" << endl;
			correctAns = firstNum / secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBravo ! +1 point pour toi.\n" << endl;
				cout << funFactFrench[factIndex] << endl;
			}
			else
			{
				cout << "\nOups... mauvaise reponse.\n" << endl;
			}
			return input == correctAns;
		}
		else
		{
			cout << "Combien font " << firstNum << "x" << secondNum << " ?" << endl;
			correctAns = firstNum * secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\nBravo ! +1 point pour toi.\n" << endl;
				cout << funFactFrench[factIndex] << endl;
			}
			else
			{
				cout << "\nOups... mauvaise reponse.\n" << endl;
			}
			return input == correctAns;
		}//end french questions
	}

}

// this function counts the points and returns a final score, 
// tracks the points from the boolean function, true = 1 and false = 0
// It also calls askQues() function 7 times and adds score using a for loop
// Uses constant numQues
// It writes to an external file
int showScore(string language)
{

	ofstream outFile("scores.txt"); 

	if (outFile.is_open()) // writing to an external file
	{
		int score = 0;
		bool usedFacts[numQues] = { false };
		for (int i = 0; i < numQues; i++)
		{
			if (askQues(language, usedFacts))
			{
				score++;
			}
		}
		// goodbye message with score presentation in specified language
		if (language == "English")
		{
			outFile << "You earned a total of: " << score << " points!\nGreat job and thank you for playing! :)\n" << endl;
			outFile.close();
		}

		else if (language == "Spanish")
		{
			outFile << "Ganaste un total de: " << score << " puntos!\nBuen trabajo y gracias por jugar! :)\n" << endl;
			outFile.close();
		}

		else //french
		{
			outFile << "Tu as gagne un total de: " << score << " points!\nBravo et merci d’avoir joue! :)\n" << endl;
			outFile.close();
		}

		return score;
	}
	else
	{
		cout << "Unable to write file." << endl;
	}
}

int main()
{
	srand(time(0));
	string language = selectLanguage(); //calling funciton for language
	helloUser(language); // calling the funciton for name
	showScore(language); // runs askQues() function with in and tracks the score
	return 0;
}
