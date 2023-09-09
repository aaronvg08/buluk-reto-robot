//
// Created by Aarón Vázquez Guzmán on 04/09/23.
//

#include <iostream>
#include <unistd.h>

using namespace std;

void printButtons() {
    // Imprimir lista de botones
    string buttons[5] = {"triggerL (1) (Cerrar Mecanismo)", "triggerR (2) (Abrir Mecanismo)", "arrows (3) (Mover adelante y atrás)", "tabL (4) (Girar 90 grados a la izq)", "tabR (5) (Girar 90 grados a la izq)"};
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

    // Variable de puntos
    int points = 0;

    // Imprimir opciones autonomo
    cout << "\n\nSelecciona una de las siguientes opciones:";
    cout << "\n--------------------------------------";
    cout << "\n- Quitar llanta 1, 15 segundos (1)";
    cout << "\n- Quitar llanta 2, 15 segundos (2)";
    cout << "\n- Quitar llanta 3, 15 segundos (3)";
    cout << "\n- Quitar llanta 4, 15 segundos (4)";
    cout << "\n--------------------------------------";

    while (true) {
        cout << "\n\nSelecciona una opcion (1, 2...): ";
        cin >> aut_input;
        cin.clear();
        cin.ignore(1000, '\n');

        // Variable para ver si el proceso fue exitoso
        bool success = true;

        if (aut_input >= 1 && aut_input < 5) {
            // La opcion si existe
            if (aut_input == 1) {
                cout << "\nAvanzando 6.5 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                
                // Esperando el tiempo que tarda
                // NOTA: Los metros al que esta el carro fue dividido por los metros por segundo del robot
                usleep(3.71408398393 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nGirando 90 grados a la izquierda...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvancando 1.2 metros...";
                std::cout << " " << std::flush;
                usleep(0.76056327316 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 0.6 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.57042245487 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nAvanzando 0.1 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                // NOTA: El mecanismo es para quitar la llanta. Mas info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                cout << "\nAvanzando 0.1 metros atras...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 6.6 metros adelante...";
                std::cout << " " << std::flush;
                usleep(4.18309800238 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 1.85 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(1.17253504612 * microsecond);

                cout << "\nGirando 90 grados a la izquierda...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 1 metro adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.63380272763 * microsecond);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 1 fuera. +5 puntos.";
                points = points + 5;
                aut_time = aut_time - 15.56;

            } else if (aut_input == 2) {

                cout << "\nAvanzando 6.5 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;

                // Esperando el tiempo que tarda
                // NOTA: Los metros al que esta el carro fue dividido por los metros por segundo del robot
                usleep(3.71408398393 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nGirando 90 grados a la derecha...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvancando 1.2 metros...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.76056327316 * microsecond);

                cout << "\nGirando 90 grados a la izquierda....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 0.6 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.57042245487 * microsecond);

                cout << "\nGirando 90 grados a la izquierda....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nAvanzando 0.1 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                // NOTA: El mecanismo es para quitar la llanta. Mas info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                cout << "\nAvanzando 0.1 metros atras...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                cout << "\nGirando 90 grados a la izquierda....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 6.6 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(4.18309800238 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 5 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(3.16901363817 * microsecond);

                cout << "\nGirando 90 grados a la izquierda...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 1 metro adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.63380272763 * microsecond);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 2 fuera. +5 puntos.";
                points = points + 5;

                aut_time = aut_time - 15.56;

            } else if (aut_input == 3) {
                cout << "\nAvanzando 6.5 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;

                // Esperando el tiempo que tarda
                // NOTA: Los metros al que esta el carro fue dividido por los metros por segundo del robot
                usleep(3.71408398393 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nGirando 90 grados a la izquierda...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvancando 1.2 metros...";
                std::cout << " " << std::flush;
                usleep(0.76056327316 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 6.11 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.57042245487 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nAvanzando 0.1 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                // NOTA: El mecanismo es para quitar la llanta. Más info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                cout << "\nAvanzando 0.1 metros atras...";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 8.3 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(4.18309800238 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 1.85 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(1.17253504612 * microsecond);

                cout << "\nGirando 90 grados a la izquierda...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 1 metro adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.63380272763 * microsecond);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 3 fuera. +5 puntos.";
                points = points + 5;
                aut_time = aut_time - 15.56;

            } else if (aut_input == 4) {
                cout << "\nAvanzando 6.5 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;

                // Esperando el tiempo que tarda
                // NOTA: Los metros al que esta el carro fue dividido por los metros por segundo del robot
                usleep(3.71408398393 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nGirando 90 grados a la derecha...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvancando 1.2 metros...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.76056327316 * microsecond);

                cout << "\nGirando 90 grados a la izquierda....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 7.84 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(4.96901338465 * microsecond);

                cout << "\nGirando 90 grados a la izquierda....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);
                aut_time = aut_time - 3;

                cout << "\nAvanzando 0.1 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                // NOTA: El mecanismo es para quitar la llanta. Mas info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                cout << "\nAvanzando 0.1 metros atras...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.06338027276 * microsecond);

                cout << "\nGirando 90 grados a la izquierda....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 8.3 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(4.18309800238 * microsecond);

                cout << "\nGirando 90 grados a la derecha....";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 5 metros adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(3.16901363817 * microsecond);

                cout << "\nGirando 90 grados a la izquierda...";
                std::cout << " " << std::flush;
                usleep(0.5 * microsecond);

                cout << "\nAvanzando 1 metro adelante...";
                cout << "\nVelocidad del motor: 1";
                std::cout << " " << std::flush;
                usleep(0.63380272763 * microsecond);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 4 fuera. +5 puntos.";
                points = points + 5;

                aut_time = aut_time - 15.56;
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
    int input;
    while (true) {
        if (tele_time_secs <= 165 && tele_time_secs > 100) {
            cout << "\nRECOMENDACION: Quitar llantas!";
        } else if (tele_time_secs <= 100) {
            cout << "\nRECOMENDACION: Colocar llantas!";
        } else if (tele_time_secs < 30) {
            cout << "\nRECOMENDACION: Apretar car release!";
        } else if (tele_time_secs < 20) {
            cout << "\nRECOMENDACION: Empujar coche a la salida!";
        }

        cout << "\n\nInserta tu boton (o \"100\" para imprimir los botones): ";
        cin >> input;
        cin.clear();
        cin.ignore(1000, '\n');

        // Ver si es "help"
        if (input == 100) {
            printButtons();
            continue;
        }

        // Verificar si el boton existe
        if (input >= 1 && input < 6) {
            // El boton si existe

            // Detectar que boton fue
            if (input == 3) {
                // Es una flecha
                int direction;
                double secs;
                while (true) {
                    // Solo adelante y atras, para girar se utiliza tab
                    cout << "Inserta tu direccion deseada (adelante (1), atras (2)): ";
                    cin >> direction;
                    cin.clear();
                    cin.ignore(1000, '\n');

                    // Checar si tenemos una respuesta que si existe
                    if (direction == 1 || direction  == 2) {
                        break;
                    } else {
                        cout << "\nSelecciona una direccion disponible!";
                    }
                }
                // Pidiendo tiempo
                cout << "Tiempo deseado (segundos): ";
                cin >> secs;
                if (direction == 1) {
                    cout << "Activando motor x, avanzando a la direccion: \"adelante\"...";
                } else {
                    cout << "Activando motor x, avanzando a la direccion: \"atras\"...";
                }
                cout << "\nVelocidad del motor: 1";

                // Nota: Motores conectados a los spark max

                // Nota: Flush es para que se vea el texto antes de esperar. Si se quita, se salta el cout.
                std::cout << " " << std::flush;

                // Restando el tiempo
                tele_time_secs = tele_time_secs - secs;

                // Distancia
                // NOTA: LA DISTANCIA ES UNA APROXIMACION!! NO ES EXACTO!!
                double robot_distance = 1.577778 * secs;

                // Espereando el tiempo
                usleep(secs * microsecond);
                cout << "Listo! " << robot_distance << " metros recorridos!";
                std::cout << " " << std::flush;
                usleep(microsecond / 2);

            } else if (input == 1 || input == 2) {
                // Es un gatillo
                // Va a servir para activar el mecanismo que va a sacar la llanta
                if (input == 1) {
                    string yesno;
                    cout << "Cerrar mecanismo!";
                    tele_time_secs = tele_time_secs - 1;

                    cout << "\nLograste quitar o poner una llanta? (Y/N): ";
                    cin >> yesno;

                    if (yesno == "y" ) {
                        cout << "\nFelicidades!! +3 puntos! :)";
                        points = points + 3;
                    } else if (yesno == "n") {
                        cout << "\nBueno ni modo :(";
                    } else {
                        cout << "\nInput invalido!";
                    }
                } else {
                    cout << "Abrir mecanismo!";
                    tele_time_secs = tele_time_secs - 1;
                }
            } else if (input == 4 || input == 5) {
                // Es un tab
                if (input == 4) {
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
            if (input == 888) {
                cout << "\nDEBUG SKIP ACTIVADO! Saltando tiempo...";
                std::cout << " " << std::flush;
                usleep(microsecond);
                break;
            }
            // El boton no existe
            cout << "Tu boton no existe!!";
        }
    }
    cout << "\nPuntaje final (aproximacion): " << points;
    cout << "\nOjala ganamos :)";
    return 0;
}
