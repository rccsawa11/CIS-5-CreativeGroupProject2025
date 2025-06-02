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
using namespace std; 
const int numQues = 7; //number of questions = 7

string helloUser()
{ // getting name of user by using cin for them to type in and retrive a string to store into 'name' variable
	string name;
	cout << "Please enter your name: "; 
	getline(cin, name);
	cout << "Hello and Welcome to the SUPER AWESOME MATH QUIZ " << name << "!" << endl;
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
	cout << "This quiz has 3 world-wide-spoken language to choose from. \n" <<  "Please enter the number next to the language you chose.\n" << "1. English\n" << "2. Spanish\n" << "3. French\n" << endl;
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
		cout << "\nHas seleccionado el espanol." << endl;

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
	"¿Sabías que el francés se habla en cinco continentes?\n", 
	"¡El español es el segundo idioma más hablado del mundo!\n", 
	"¡El inglés se usa en la aviación y la diplomacia!\n", 
	"¡En Japón, los estudiantes limpian sus salones!\n", 
	"¡En Kenia, los niños aprenden en suajili e inglés!\n", 
	"¡Finlandia comienza las clases tarde y aún así sobresale!\n", 
	"¡India tiene más de 22 idiomas oficiales!\n"
}; 

string funFactEnglish [ ] = 
{
	"Did you know? French is spoken on 5 continents!\n", 
	"Spanish is the 2nd most spoken language in the world!\n", 
	"English is used in international aviation and diplomacy!\n", 
	"In Japan, students clean their classrooms every day!\n", 
	"In Kenya, children learn in Swahili and English!\n", 
	"Finland starts school later but scores high!\n", 
	"India has more than 22 official languages!\n"
};

string funFactFrench [ ] = 
{
	"Le français est parlé sur cinq continents !\n", 
	"L'espagnol est la 2e langue la plus parlée au monde !\n", 
	"L'anglais est utilisé dans l'aviation et la diplomatie !\n", 
	"Au Japon, les élèves nettoient leurs classes chaque jour !\n", 
	"Au Kenya, les enfants apprennent le swahili et l'anglais !\n", 
	"La Finlande commence l'école tard mais réussit très bien !\n", 
	"L'Inde a plus de 22 langues officielles !\n"
}; 

// this funciton will ask the user the arithmetic 4th grade questions
// it is a boolean because it returns true or false in terms of getting the answer correct
// Uses random num generator to keep making questions
bool askQues(string language, bool usedFacts[]) 
// boolean will return 1 for true and 0 for false, so we chose to track points that way
{
	cout << "\nAnd....Here's a question!!!\n" << endl;

	//assigns numbers from 0-99

	const int maxNum = 20;
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
			cout << "¿Cuánto es " << firstNum << "+" << secondNum << " ?" << endl;
			correctAns = firstNum + secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\n¡Buen trabajo! + 1 punto para ti.\n" << endl;
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
			cout << "¿Cuánto es " << firstNum << "-" << secondNum << " ?" << endl;
			correctAns = firstNum - secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\n¡Buen trabajo! + 1 punto para ti.\n" << endl;
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
			cout << "¿Cuánto es " << firstNum << "/" << secondNum << " ? \nDisregard the decimal points.\n" << endl;
			correctAns = firstNum / secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\n¡Buen trabajo! + 1 punto para ti.\n" << endl;
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
			cout << "¿Cuánto es " << firstNum << "x" << secondNum << " ?" << endl;
			correctAns = firstNum * secondNum;
			cin >> input;
			cin.ignore();
			if (input == correctAns)
			{
				cout << "\n¡Buen trabajo! + 1 punto para ti.\n" << endl;
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
				cout << "\nOups... mauvaise réponse.\n" << endl;
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
				cout << "\nOups... mauvaise réponse.\n" << endl;
			}
			return input == correctAns;
		}
		else if (operRator == 3)
		{
			if (secondNum == 0) // prevents divison by 0
			{
				secondNum = 1;
			}
			cout << "Combien font " << firstNum << "/" << secondNum << " ? \nDisregard the decimal points.\n" << endl;
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
				cout << "\nOups... mauvaise réponse.\n" << endl;
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
				cout << "\nOups... mauvaise réponse.\n" << endl;
			}
			return input == correctAns;
		}//end french questions
	}

}

// this function counts the points and returns a final score, 
// tracks the points from the boolean function, true = 1 and false = 0
// It also calls askQues() function 7 times and adds score using a for loop
// Uses constant numQues
int showScore(string language)
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
		cout << "\nYou earned a total of: " << score << " points!\n Great job and thank you for playing! :)\n" << endl;
	}

	else if (language == "Spanish")
	{
		cout << "\n¡Ganaste un total de: " << score << " puntos!\n ¡Buen trabajo y gracias por jugar! :)\n" << endl;

	}

	else //french
	{
		cout << "\nTu as gagné un total de: " << score << " points!\n  Bravo et merci d’avoir joué! :)\n" << endl;

	}

	return score;
}

int main()
{
	helloUser(); // calling the funciton for name
	string language = selectLanguage(); //calling funciton for language
	showScore(language); // runs askQues() function with in and tracks the score
	return 0;
}
