//
// Created by Aarón Vázquez Guzmán on 04/09/23.
//

#include <iostream>
using namespace std;

int main() {
    string buttons[10] = {"triggerL", "triggerR", "joystick1", "joystick2", "a", "b", "x", "y", "tabL", "tabR"};
    cout << "Modo manejado!";
    cout << "\nLos botones disponibles son:\n";
    cout << "\n--------------------------------------";
    for (string b : buttons) {
        cout << "\n" << b;
    }
    cout << "\n--------------------------------------\n";
    cout << "Inserta tu boton:";
    return 0;
}
