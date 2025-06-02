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


const int numQues = 7; //number of questions = 7


string funFactSpanish [ ] =
{
	"¿Sabías que el francés se habla en cinco continentes?", 
	"¡El español es el segundo idioma más hablado del mundo!", 
	"¡El inglés se usa en la aviación y la diplomacia!", 
	"¡En Japón, los estudiantes limpian sus salones!", 
	"¡En Kenia, los niños aprenden en suajili e inglés!", 
	"¡Finlandia comienza las clases tarde y aún así sobresale!", 
	"¡India tiene más de 22 idiomas oficiales!"
}; 

string funFactEnglish [ ] = 
{
	"Did you know? French is spoken on 5 continents!", 
	"Spanish is the 2nd most spoken language in the world!", 
	"English is used in international aviation and diplomacy!", 
	"In Japan, students clean their classrooms every day!", 
	"In Kenya, children learn in Swahili and English!", 
	"Finland starts school later but scores high!", 
	"India has more than 22 official languages!"
};

string funFactFrench [ ] = 
{
	"Le français est parlé sur cinq continents !", 
	"L'espagnol est la 2e langue la plus parlée au monde !", 
	"L'anglais est utilisé dans l'aviation et la diplomatie !", 
	"Au Japon, les élèves nettoient leurs classes chaque jour !", 
	"Au Kenya, les enfants apprennent le swahili et l'anglais !", 
	"La Finlande commence l'école tard mais réussit très bien !", 
	"L'Inde a plus de 22 langues officielles !"
}; 

// this funciton will ask the user the arithmetic 4th grade questions
// it is a boolean because it returns true or false in terms of getting the answer correct
// Uses random num generator to keep making questions
bool askQues(string language, bool usedFacts[])
{
	cout << "And....Here's a question!!!" << endl;

	//assigns numbers from 0-99

	int firstNum = rand() % 20;
	int secondNum = rand() % 20;
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

	int operRator = rand() % 4;
	
	if (language == "English") 
	{
		if (operRator == 1)
		{
			cout << "What would " << firstNum << "+" << secondNum << " be?" << endl;
			correctAns = firstNum + secondNum;
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
			if (secondNum == 0)
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
	else if (language == "Spanish")
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
			cout << "¿Cuánto es " << firstNum << "/" << secondNum << " ?" << endl;
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
	else // french
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
			cout << "Combien font " << firstNum << "/" << secondNum << " ?" << endl;
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
		}
	}

}

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
	showScore(language);
	return 0;
}
