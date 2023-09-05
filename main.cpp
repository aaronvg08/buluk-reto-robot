//
// Created by Aarón Vázquez Guzmán on 04/09/23.
//

#include <iostream>
#include <unistd.h>

using namespace std;

void printButtons() {
    // Imprimir lista de botones
    string buttons[5] = {"triggerL", "triggerR", "arrows", "tabL", "tabR"};
    cout << "\nLos botones disponibles son:\n";
    cout << "\n--------------------------------------";
    for (string b :  buttons) {
        cout << "\n" << b;
    }
    cout << "\n--------------------------------------\n";
}

int main() {
    // Lista de botones
    string buttons[5] = {"triggerl", "triggerr", "arrows", "tabl", "tabr"};
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

            // Detectar que boton fue
            if (input == buttons[2]) {
                // Es una flecha
                string direction;
                double secs;
                while (true) {
                    // Solo adelante y atras, para girar se utiliza tab
                    cout << "Inserta tu direccion deseada (forward, backward): ";
                    cin >> direction;
                    cin.clear();
                    cin.ignore(1000, '\n');

                    // Transformar a minusculas
                    transform(direction.begin(), direction.end(), direction.begin(), ::tolower);

                    // Chechar si tenemos una respuesta que si existe
                    if (direction == "forward" || direction  == "backward") {
                        break;
                    } else {
                        cout << "\nSelecciona una direccion disponible!";
                    }
                }
                // Pidiendo tiempo
                cout << "Tiempo deseado (segundos): ";
                cin >> secs;
                cout << "Activando motor x, avanzando a la direccion: \"" << direction << "\"...";

                // Nota: Flush es para que se vea el texto antes de esperar. Si se quita, se salta el cout.
                std::cout << " " << std::flush;

                // Espereando el tiempo
                usleep(secs * 1000000);
                cout << "Listo!";
                std::cout << " " << std::flush;
                usleep(1000000 / 2);

            } else if (input == buttons[0] || input == buttons[1]) {
                // Es un gatillo
                // Va a servir para activar el mecanismo que va a sacar la llanta
                if (input == buttons[0]) {
                    cout << "Cerrar mecanismo!";
                } else {
                    cout << "Abrir mecanismo!";
                }
            } else if (input == buttons[3] || input == buttons[4]) {
                // Es un tab
                if (input == buttons[3]) {
                    // Izquierda
                    cout << "Activando ruedas de chasis derecho.";
                    cout << "\nGirando 90 grados a la izquierda...";
                    std::cout << " " << std::flush;
                    usleep(1000000);
                } else {
                    // Derecha
                    cout << "Activando ruedas de chasis izquierdo.";
                    cout << "\nGirando 90 grados a la derecha...";
                    std::cout << " " << std::flush;
                    usleep(1000000);
                }
            }
        } else {
            // El boton no existe
            cout << "Tu boton no existe!!";
        }
    }
    return 0;
}
