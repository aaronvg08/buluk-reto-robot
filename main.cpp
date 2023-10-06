//
// Created by Aarón Vázquez Guzmán on 04/09/23.
//

#include <iostream>
#include <unistd.h>

using namespace std;

void printButtons() {
    // Imprimir lista de botones
    string buttons[5] = {"button0 (1) (Cerrar Mecanismo)", "button1 (2) (Abrir Mecanismo)", "pov (3) (Mover adelante y atrás)", "button4 (4) (Girar 90 grados a la izq)", "button5 (5) (Girar 90 grados a la izq)"};
    cout << "\nLos botones disponibles son:\n";
    cout << "\n--------------------------------------";
    for (string b :  buttons) {
        cout << "\n" << b;
    }
    cout << "\n--------------------------------------\n";
}

void moveRobot(int mode, double quantity, double secs, int orientation = 0, double speed = 1) {
    int microsecond = 1000000;
    if (mode == 1) {
        // Avanzar
        if (orientation == 0) {
            cout << "\nAvanzando" << quantity << "metros adelante...";
        } else {
            cout << "\nAvanzando" << quantity << "metros atras...";
        }
        cout << "\nVelocidad del motor: " << speed;
        std::cout << " " << std::flush;
        usleep(secs * microsecond);
    } else {
        // Girar
        if (orientation == 1) {
            cout << "\nGirando" << quantity << "grados a la izquierda...";
        } else {
            cout << "\nGirando" << quantity << "grados a la derecha...";
        }
        std::cout << " " << std::flush;

        // Esperando el tiempo que tarda
        // NOTA: Los metros al que esta el carro fue dividido por los metros por segundo del robo
        usleep(secs * microsecond);
    }
}

int main() {
    // Lista de botones
    string buttons[5] = {"button0", "button1", "pov", "button4", "button5"};
    
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
    cout << "\n\nLlantas:\n\n";
    cout << "        °°#####################°°\n"
            "    2   °°°####################°°°   1\n"
            "        °°°####################°°°\n"
            "        °°#####################°°\n"
            "        #######################\n"
            "        #######################\n"
            "        °°#####################°°\n"
            "    4   °°°####################°°°    3\n"
            "        °°°####################°°°\n"
            "        °°#####################°°";
    cout << "\n\nSelecciona una de las siguientes opciones:";
    cout << "\n--------------------------------------";
    cout << "\n- Quitar llanta 1, 15 segundos (1)";
    cout << "\n   - Conducir hasta llanta 1 con ruta predeterminada";
    cout << "\n   - Quitarla con el mecanismo";
    cout << "\n   - Ponerla en el lugar correspondiente";
    cout << "\n- Quitar llanta 2, 15 segundos (2)";
    cout << "\n   - Conducir hasta llanta 2 con ruta predeterminada";
    cout << "\n   - Quitarla con el mecanismo";
    cout << "\n   - Ponerla en el lugar correspondiente";
    cout << "\n- Quitar llanta 3, 15 segundos (3)";
    cout << "\n   - Conducir hasta llanta 3 con ruta predeterminada";
    cout << "\n   - Quitarla con el mecanismo";
    cout << "\n   - Ponerla en el lugar correspondiente";
    cout << "\n- Quitar llanta 4, 15 segundos (4)";
    cout << "\n   - Conducir hasta llanta 4 con ruta predeterminada";
    cout << "\n   - Quitarla con el mecanismo";
    cout << "\n   - Ponerla en el lugar correspondiente";
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
                // Movimiento
                moveRobot(1, 6.5, 3.71408398393);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1.2, 0.76056327316);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 0);

                // Movimiento
                moveRobot(1, 0.6, 0.57042245487);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 0);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276);

                // NOTA: El mecanismo es para quitar la llanta. Mas info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276, 1);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 0);

                // Movimiento
                moveRobot(1, 6.6, 4.18309800238);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 0);

                // Movimiento
                moveRobot(1, 1.8, 1.17253504612);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1, 0.63380272763);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 1 fuera. +5 puntos.";
                points = points + 5;
                aut_time = aut_time - 15.56;

            } else if (aut_input == 2) {
                // Movimiento
                moveRobot(1, 6.5, 3.71408398393);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1.2, 0.76056327316);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 0.6, 0.57042245487);


                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276);

                // NOTA: El mecanismo es para quitar la llanta. Mas info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276, 1);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 6.6, 4.18309800238);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 5, 3.16901363817);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1, 0.63380272763);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 2 fuera. +5 puntos.";
                points = points + 5;

                aut_time = aut_time - 15.56;

            } else if (aut_input == 3) {
                // Movimiento
                moveRobot(1, 6.5, 3.71408398393);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1.2, 0.76056327316);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 6.11, 0.57042245487);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276);

                // NOTA: El mecanismo es para quitar la llanta. Más info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276, 1);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 8.3, 4.18309800238);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1.85, 1.17253504612);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1, 0.63380272763);

                cout << "\nCerrando mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Rutina completada!
                cout << "\nListo! Rueda 3 fuera. +5 puntos.";
                points = points + 5;
                aut_time = aut_time - 15.56;

            } else if (aut_input == 4) {
                // Movimiento
                moveRobot(1, 6.5, 3.71408398393);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1.2, 0.76056327316);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 7.84, 4.96901338465);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276);

                // NOTA: El mecanismo es para quitar la llanta. Mas info en mecanica
                cout << "\nAbriendo mecanismo...";
                std::cout << " " << std::flush;
                usleep(1 * microsecond);

                // Movimiento
                moveRobot(1, 0.1, 0.06338027276, 1);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 8.3, 4.18309800238);

                // Girando 90 grados a la derecha
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 5, 3.16901363817);

                // Girando 90 grados a la izq
                moveRobot(2, 90, 0.5, 1);

                // Movimiento
                moveRobot(1, 1, 0.63380272763);

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
                    cout << "Inserta tu direccion deseada (adelante (0), atras (180)): ";
                    cin >> direction;
                    cin.clear();
                    cin.ignore(1000, '\n');

                    //NOTA: LA DIRECCION ES ACORDE AL CONTROL Y LAS POSICIONES QUE HAY EN "POV"

                    // Checar si tenemos una respuesta que si existe
                    if (direction >= 0 && direction <= 315) {
                        break;
                    } else {
                        cout << "\nSelecciona una direccion disponible!\n";
                    }
                }
                // Pidiendo tiempo
                cout << "Tiempo deseado (segundos): ";
                cin >> secs;

                //NOTA: LA DIRECCION ES ACORDE AL CONTROL Y LAS POSICIONES QUE HAY EN "POV"
                if ((direction >= 0 && direction <= 90) || (direction >= 270 && direction <= 315)) {
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

                    if (yesno == "y" || yesno == "Y") {
                        cout << "\nFelicidades!! +3 puntos! :)";
                        points = points + 3;
                    } else if (yesno == "n" || yesno == "N") {
                        cout << "\nBueno ni modo :(";
                    } else {
                        cout << "\nInput invalido!";
                    }
                } else {
                    cout << "Abrir mecanismo!";
                    tele_time_secs = tele_time_secs - 1;
                }
            } else if (input == 4 || input == 5) {
                // Girar 90 grados
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
