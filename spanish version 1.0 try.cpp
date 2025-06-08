#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

const int numQues = 7;

string selectLanguage() 
{
    string langChoice;
    cout << "Please select a language / Por favor selecciona un idioma / Veuillez sélectionner une langue:\n";
    cout << "1. English\n2. Español\n3. Français\n" << endl;
    getline(cin, langChoice);
    int choice = stoi(langChoice);
    string lang;

    if (choice == 1) {
        lang = "English";
        cout << "\nYou've selected English." << endl;
    }
    else if (choice == 2) {
        lang = "Spanish";
        cout << "\nHas seleccionado español." << endl;
    }
    else {
        lang = "French";
        cout << "\nVous avez choisi le francais." << endl;
    }

    return lang;
}

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
        cout << "\n¡Hola y bienvenido al SÚPER INCREÍBLE QUIZ DE MATEMÁTICAS, " << name << "!" << endl;
    }
    else {
        cout << "\nBonjour et bienvenue au SUPER QUIZ DE MATHÉMATIQUES, " << name << "!" << endl;
    }

    return name;
}

int main() {
    srand(time(0));
    string language = selectLanguage(); 
    string name = helloUser(language);  
    return 0;
}
