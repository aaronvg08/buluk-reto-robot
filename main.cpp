//
// Created by Aarón Vázquez Guzmán on 04/09/23.
//

#include <iostream>
using namespace std;

void printButtons() {
    // Imprimir lista de botones
    string buttons[12] = {"triggerl", "triggerr", "arrows", "a", "b", "x", "y", "tabL", "tabR"};
    cout << "\nLos botones disponibles son:\n";
    cout << "\n--------------------------------------";
    for (string b :  buttons) {
        cout << "\n" << b;
    }
    cout << "\n--------------------------------------\n";
}

int main() {
    // Lista de botones
    string buttons[12] = {"triggerl", "triggerr", "arrows", "a", "b", "x", "y", "tabL", "tabR"};
    cout << "Modo manual!";

    // Imprimir botones
    printButtons();

    // Pedir boton
    string input;
    while (true) {
        cout << "\nInserta tu boton (o \"help\" para imprimir los botones): ";
        cin >> input;
        cin.clear();
        cin.ignore(1000, '\n');

        // Transformar a minusculas
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        // Ver si es "help"
        if (input == "help") {
            printButtons();
            continue;
        }

        // Verificar si el boton existe
        if (std::find(std::begin(buttons), std::end(buttons), input) != end(buttons)) {
            // El boton si existe
            if (input == buttons[2]) {
                // Es una flecha
                string direction;
                double time;
                cout << "Inserta tu direccion deseada (up, down, left, right): ";
                cin >> direction;
                cout << "Tiempo deseado (segundos): ";
                cin >> time;
                cout << "Activando motor x, avanzando...";
            } else if (input == buttons[0] || input == buttons[1]) {
                // Es un gatillo
            } else if (input == buttons[3] || input == buttons[4] || input == buttons[5] || input == buttons[6]) {
                // Es un boton a b x y
            } else if (input == buttons[7] || input == buttons[8]) {
                // Es un tab
            }
        } else {
            // El boton no existe
            cout << "Tu boton no existe!!";
        }
    }
    return 0;
}
