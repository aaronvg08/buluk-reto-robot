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
    
    // Microsegundos
    int microsecond = 1000000;

    // Tiempo para el autonomo
    int aut_time = 15;

    // Modo autonomo
    cout << "\nModo autonomo! Tiempo: " << aut_time << " segundos.";
    int aut_input;

    // Imprimir opciones autonomo
    cout << "\n\nSelecciona una de las siguientes opciones:";
    cout << "\n--------------------------------------";
    cout << "\n- Quitar herramientas, x segundos (1)";
    cout << "\n- Quitar llantas, x segundos (2)";
    cout << "\n- Poner llantas, x segundos (3)";
    cout << "\n--------------------------------------";

    while (true) {
        cout << "\n\nSelecciona una opcion (1, 2...): ";
        cin >> aut_input;
        cin.clear();
        cin.ignore(1000, '\n');

        // Variable para ver si el proceso fue exitoso
        bool success = true;

        if (aut_input >= 1 && aut_input < 4) {
            // La opcion si existe
            if (aut_input == 1) {
                cout << "Quitando herramientas...";
                std::cout << " " << std::flush;
                
                // Esperando el tiempo que tarda
                usleep(5 * microsecond);
                aut_time = aut_time - 5;
            } else if (aut_input == 2) {
                cout << "Quitando llantas...";
                std::cout << " " << std::flush;

                // Esperando el tiempo que tarda
                usleep(5 * microsecond);
                aut_time = aut_time - 5;
            } else {
                cout << "Colocando llantas...";
                std::cout << " " << std::flush;

                // Esperando el tiempo que tarda
                usleep(5 * microsecond);
                aut_time = aut_time - 5;
            }
            cout << "Listo!";
            std::cout << " " << std::flush;
            usleep(microsecond / 2);

            // Mostrar tiempo autonomo restante
            cout << "\n" << aut_time << " segundos restantes!";
            std::cout << " " << std::flush;
            usleep(1 * microsecond);

            // Si se acabo el tiempo, se acaba el modo autonomo
            if (aut_time <= 0) {
                break;
            }
        } else {
            if (aut_input == 50) {
                // Esto es para razones de debug
                cout << "\nDEBUG SKIP ACTIVADO!";
                break;
            }
            cout << "Selecciona una opcion disponible!";
        }
    }
    
    cout << "\nFin del modo autonomo!";
    std::cout << " " << std::flush;
    usleep(3 * microsecond);

    // Modo teleoperado
    cout << "\n\nModo teleoperado!";

    // Variable de tiempo
    double tele_time_secs = 165;
    cout << "\nTiempo: " << tele_time_secs << " segundos";

    std::cout << " " << std::flush;
    usleep(1 * microsecond);

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

                // Nota: Activa puertos 1, 9, 10, 13, 15, 17 y 19.

                // Nota: Flush es para que se vea el texto antes de esperar. Si se quita, se salta el cout.
                std::cout << " " << std::flush;

                // Restando el tiempo
                tele_time_secs = tele_time_secs - secs;

                // Distancia
                // NOTA: LA DISTANCIA ES UNA APROXIMACION!! NO ES EXACTO!!
                double robot_distance = 0.277778 * secs;

                // Espereando el tiempo
                usleep(secs * microsecond);
                cout << "Listo! " << robot_distance << " metros recorridos!";
                std::cout << " " << std::flush;
                usleep(microsecond / 2);

            } else if (input == buttons[0] || input == buttons[1]) {
                // Es un gatillo
                // Va a servir para activar el mecanismo que va a sacar la llanta
                if (input == buttons[0]) {
                    cout << "Cerrar mecanismo!";
                    tele_time_secs = tele_time_secs - 1;
                } else {
                    cout << "Abrir mecanismo!";
                    tele_time_secs = tele_time_secs - 1;
                }
            } else if (input == buttons[3] || input == buttons[4]) {
                // Es un tab
                if (input == buttons[3]) {
                    // Izquierda
                    cout << "Activando ruedas de chasis derecho.";
                    cout << "\nGirando 90 grados a la izquierda...";
                    std::cout << " " << std::flush;
                    usleep(microsecond);
                } else {
                    // Derecha
                    cout << "Activando ruedas de chasis izquierdo.";
                    cout << "\nGirando 90 grados a la derecha...";
                    std::cout << " " << std::flush;
                    usleep(microsecond);
                }

                tele_time_secs = tele_time_secs - 2;
            }

            // Checar si el tiempo se acabó
            if (tele_time_secs <= 0) {
                cout << "\n\nSe acabo el tiempo!! Deteniendo programa...";
                std::cout << " " << std::flush;
                usleep(5 * microsecond);
                break;
            } else {
                cout << "\nTiempo restante: " << tele_time_secs << " segundos";
            }
        } else {
            // Debug
            if (input == "debugskip") {
                cout << "\nDEBUG SKIP ACTIVADO! Saltando tiempo...";
                std::cout << " " << std::flush;
                usleep(microsecond);
                break;
            }
            // El boton no existe
            cout << "Tu boton no existe!!";
        }
    }
    cout << "\nPuntaje final: ";
    cout << "\nOjala ganamos :)";
    return 0;
}
