//
// Created by Aarón Vázquez Guzmán on 04/09/23.
//

#include <iostream>
using namespace std;

int main() {
    // Lista de botones
    string buttons[10] = {"triggerL", "triggerR", "joystick1", "joystick2", "a", "b", "x", "y", "tabL", "tabR"};
    cout << "Modo manejado!";

    // Imprimir lista de botones
    cout << "\nLos botones disponibles son:\n";
    cout << "\n--------------------------------------";
    for (string b : buttons) {
        cout << "\n" << b;
    }
    cout << "\n--------------------------------------\n";

    // Pedir boton
    string input;
    while (true) {
        cout << "\nInserta tu boton: ";
        cin >> input;
        cin.clear();
        cin.ignore(1000, '\n');

        // Transformar a minusculas
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        // Verificar si el boton existe
        if (std::find(std::begin(buttons), std::end(buttons), input) != end(buttons)) {
            cout << "Tu boton si existe!!";
        } else {
            cout << "Tu boton no existe!!";
        }
    }
    return 0;
}
