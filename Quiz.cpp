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

const int numQues = 7; // number of questions in the quiz 

string funFactSpanish [numQues] =
{
	"¿Sabías que el francés se habla en cinco continentes?", 
	"¡El español es el segundo idioma más hablado del mundo!", 
	"¡El inglés se usa en la aviación y la diplomacia!", 
	"¡En Japón, los estudiantes limpian sus salones!", 
	"¡En Kenia, los niños aprenden en suajili e inglés!", 
	"¡Finlandia comienza las clases tarde y aún así sobresale!", 
	"¡India tiene más de 22 idiomas oficiales!"
}; 

string funFactEnglish [numQues] = 
{
	"Did you know? French is spoken on 5 continents!", 
	"Spanish is the 2nd most spoken language in the world!", 
	"English is used in international aviation and diplomacy!", 
	"In Japan, students clean their classrooms every day!", 
	"In Kenya, children learn in Swahili and English!", 
	"Finland starts school later but scores high!", 
	"India has more than 22 official languages!"
};

string funFactFrench[numQues] = 
{
	"Le français est parlé sur cinq continents !", 
	"L'espagnol est la 2e langue la plus parlée au monde !", 
	"L'anglais est utilisé dans l'aviation et la diplomatie !", 
	"Au Japon, les élèves nettoient leurs classes chaque jour !", 
	"Au Kenya, les enfants apprennent le swahili et l'anglais !", 
	"La Finlande commence l'école tard mais réussit très bien !", 
	"L'Inde a plus de 22 langues officielles !"
}; 

bool askQuestion(string language) {
    // Step 1: Generate two random numbers
    int num1; 3
    int num2; 5

    // Step 2: Ask the question in the selected language
    cout << "English is used in international aviation and diplomacy!" << endl;
    // TODO: Print question based on language
    
    // Step 3: Get user input
    int userAnswer; 
    // TODO: Use cin to get their answer
    cin >> userAnswer;
    // Step 4: Check if answer is correct
    int correctAnswer; // TODO: calculate the correct answer

    if (userAnswer == correctAnswer) {
        // Step 5: Show positive feedback message
        cout <<  "Your work is looking good!" << endl;
        // TODO: Print a fun fact from the correct language array
        cout << "India has more than 22 official languages!" << endl;

        return true; // correct
    } else {
        // Step 6: Show encouragement for incorrect answer
        cout << "No worries, keep trying!" << endl;
        // TODO: Print "Oops! Try the next one..." in chosen language
        cout << "Oops! Try the next one..." << endl;

        return false; // incorrect
    }
