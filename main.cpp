#include <iostream>   // Incluimos la biblioteca estándar de entrada y salida
#include <vector>     // Incluimos la biblioteca para usar vectores
#include <string>     // Incluimos la biblioteca para usar strings

using namespace std;  // Usamos el espacio de nombres estándar

// Función para limpiar la pantalla
void clearScreen() {
    #ifdef _WIN32
        system("cls");    // Comando para Windows
    #else
        system("clear");  // Comando para otros sistemas operativos
    #endif
}

// Función para mostrar el menú
void showMenu() {
    cout << "--------------------------------------------" << endl;
    cout << "       BIENVENIDO AL SISTEMA DE LA UVM      " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Agregar Alumno" << endl;
    cout << "2. Agregar Profesor" << endl;
    cout << "3. Agregar Materia" << endl;
    cout << "4. Visualizar Alumnos" << endl;
    cout << "5. Visualizar Profesores" << endl;
    cout << "6. Visualizar Materias" << endl;
    cout << "7. Buscar Profesor por ID" << endl;   // Nueva opción para buscar profesor por ID
    cout << "8. Buscar Materia por ID" << endl;    // Nueva opción para buscar materia por ID
    cout << "9. Buscar Alumno por ID" << endl;     // Nueva opción para buscar alumno por ID
    cout << "10. Salir" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Seleccione una opción: ";
}

// Definición de la clase Profesor
class Profesor {
    static int nextID;        // Variable estática para generar IDs únicos
    int id;                   // ID del profesor
    string nombre;            // Nombre del profesor
    string apellido;          // Apellido del profesor
    string sexo;              // Sexo del profesor
    int edad;                 // Edad del profesor
    string titulo;            // Título o profesión
    int noCedulaProfesional;  // Número de cédula profesional

public:
    // Constructor de la clase Profesor
    Profesor(string nombre, string apellido, string sexo, int edad, string titulo, int noCedulaProfesional) {
        id = nextID++;                // Asignamos un ID único
        this->nombre = nombre;        // Asignamos el nombre
        this->apellido = apellido;    // Asignamos el apellido
        this->sexo = sexo;            // Asignamos el sexo
        this->edad = edad;            // Asignamos la edad
        this->titulo = titulo;        // Asignamos el título
        this->noCedulaProfesional = noCedulaProfesional;  // Asignamos el número de cédula
    }

    // Método para mostrar la información del profesor
    void mostrarProfesor() const {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "Sexo: " << sexo << ", Edad: " << edad << ", Título: " << titulo << endl;
        cout << "No. de Cédula Profesional: " << noCedulaProfesional << endl;
        cout << "---------------------------" << endl;
    }

    // Método para obtener el ID del profesor
    int getID() const {
        return id;
    }

    // Método para obtener el nombre completo del profesor
    string getNombreCompleto() const {
        return nombre + " " + apellido;
    }
};

int Profesor::nextID = 1;  // Inicializamos el contador estático de IDs para Profesor

// Definición de la clase Materia
class Materia {
    static int nextID;        // Variable estática para generar IDs únicos
    int id;                   // ID de la materia
    string nombre;            // Nombre de la materia
    int creditos;             // Créditos de la materia
    Profesor profesor;        // Profesor asignado a la materia

public:
    // Constructor de la clase Materia
    Materia(string nombre, int creditos, const Profesor& profesor) : profesor(profesor) {
        id = nextID++;              // Asignamos un ID único
        this->nombre = nombre;      // Asignamos el nombre de la materia
        this->creditos = creditos;  // Asignamos los créditos
    }

    // Método para mostrar la información de la materia
    void mostrarMateria() const {
        cout << "ID: " << id << endl;
        cout << "Materia: " << nombre << ", Créditos: " << creditos << endl;
        cout << "Profesor: " << profesor.getNombreCompleto() << endl;
        cout << "---------------------------" << endl;
    }

    // Método para obtener el ID de la materia
    int getID() const {
        return id;
    }

    // Método para obtener el nombre de la materia
    string getNombre() const {
        return nombre;
    }
};

int Materia::nextID = 1;  // Inicializamos el contador estático de IDs para Materia

// Definición de la clase Alumno
class Alumno {
    static int nextID;        // Variable estática para generar IDs únicos
    int id;                   // ID del alumno
    string nombre;            // Nombre del alumno
    string apellido;          // Apellido del alumno
    int noControlEscolar;     // Número de control escolar
    int edad;                 // Edad del alumno
    string sexo;              // Sexo del alumno
    string semestre;          // Semestre que cursa
    vector<Materia> materias; // Lista de materias inscritas

public:
    // Constructor de la clase Alumno
    Alumno(string nombre, string apellido, int noControlEscolar, int edad, string sexo, string semestre) {
        id = nextID++;                      // Asignamos un ID único
        this->nombre = nombre;              // Asignamos el nombre
        this->apellido = apellido;          // Asignamos el apellido
        this->noControlEscolar = noControlEscolar;  // Asignamos el número de control
        this->edad = edad;                  // Asignamos la edad
        this->sexo = sexo;                  // Asignamos el sexo
        this->semestre = semestre;          // Asignamos el semestre
    }

    // Método para agregar una materia al alumno
    void agregarMateria(const Materia& materia) {
        materias.push_back(materia);  // Agregamos la materia al vector de materias
    }

    // Método para mostrar la información del alumno
    void mostrarAlumno() const {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "No. de Control Escolar: " << noControlEscolar << endl;
        cout << "Edad: " << edad << ", Sexo: " << sexo << ", Semestre: " << semestre << endl;
        cout << "Materias: " << endl;
        for (const auto& materia : materias) {  // Iteramos sobre las materias
            cout << "- " << materia.getNombre() << endl;  // Mostramos el nombre de cada materia
        }
        cout << "---------------------------" << endl;
    }

    // Método para obtener el ID del alumno
    int getID() const {
        return id;
    }
};

int Alumno::nextID = 1;  // Inicializamos el contador estático de IDs para Alumno

// Vectores globales para almacenar los datos
vector<Alumno> alumnos;                 // Vector para almacenar alumnos
vector<Profesor> profesores;            // Vector para almacenar profesores
vector<Materia> materiasDisponibles;    // Vector para almacenar materias

// Funciones para buscar registros por ID
Profesor* findProfesorByID(int id) {
    for (auto& profesor : profesores) {    // Iteramos sobre los profesores
        if (profesor.getID() == id) {      // Si el ID coincide
            return &profesor;              // Retornamos un puntero al profesor
        }
    }
    return nullptr;                        // Si no se encuentra, retornamos nullptr
}

Materia* findMateriaByID(int id) {
    for (auto& materia : materiasDisponibles) {  // Iteramos sobre las materias
        if (materia.getID() == id) {             // Si el ID coincide
            return &materia;                     // Retornamos un puntero a la materia
        }
    }
    return nullptr;                              // Si no se encuentra, retornamos nullptr
}

Alumno* findAlumnoByID(int id) {
    for (auto& alumno : alumnos) {     // Iteramos sobre los alumnos
        if (alumno.getID() == id) {    // Si el ID coincide
            return &alumno;            // Retornamos un puntero al alumno
        }
    }
    return nullptr;                    // Si no se encuentra, retornamos nullptr
}

// Función para manejar las opciones seleccionadas en el menú
void handleOption(int option) {
    switch (option) {
        case 1: {
            // Agregar Alumno
            string nombre, apellido, sexo, semestre;
            int noControlEscolar, edad;
            size_t numMaterias;

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);  // Leemos el nombre
            cout << "Apellido: ";
            getline(cin, apellido);  // Leemos el apellido
            cout << "No. de Control Escolar: ";
            cin >> noControlEscolar;  // Leemos el número de control
            cout << "Edad: ";
            cin >> edad;              // Leemos la edad
            cin.ignore();             // Limpiamos el buffer de entrada
            cout << "Sexo: ";
            getline(cin, sexo);       // Leemos el sexo
            cout << "Semestre: ";
            getline(cin, semestre);   // Leemos el semestre

            // Creamos un nuevo objeto Alumno
            Alumno alumno(nombre, apellido, noControlEscolar, edad, sexo, semestre);

            if(materiasDisponibles.empty()) {  // Verificamos si hay materias disponibles
                cout << "No hay materias disponibles. Por favor, agregue materias primero." << endl;
            } else {
                cout << "¿Cuántas materias desea agregar?: ";
                cin >> numMaterias;     // Leemos el número de materias a agregar
                cin.ignore();           // Limpiamos el buffer de entrada

                for(size_t i = 0; i < numMaterias; i++) {
                    cout << "Seleccione una materia para agregar al alumno:" << endl;
                    for(size_t j = 0; j < materiasDisponibles.size(); j++) {
                        // Mostramos las materias disponibles
                        cout << j+1 << ". " << materiasDisponibles[j].getNombre() << endl;
                    }
                    size_t seleccion;
                    cout << "Opción: ";
                    cin >> seleccion;    // Leemos la selección del usuario
                    cin.ignore();        // Limpiamos el buffer de entrada
                    if(seleccion > 0 && seleccion <= materiasDisponibles.size()) {
                        // Agregamos la materia seleccionada al alumno
                        alumno.agregarMateria(materiasDisponibles[seleccion - 1]);
                    } else {
                        cout << "Selección inválida." << endl;
                    }
                }
            }

            alumnos.push_back(alumno);  // Agregamos el alumno al vector de alumnos
            cout << "Alumno agregado exitosamente!" << endl;
            break;
        }
        case 2: {
            // Agregar Profesor
            string nombre, apellido, sexo, titulo;
            int edad, noCedulaProfesional;

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);  // Leemos el nombre
            cout << "Apellido: ";
            getline(cin, apellido);  // Leemos el apellido
            cout << "Sexo: ";
            getline(cin, sexo);      // Leemos el sexo
            cout << "Edad: ";
            cin >> edad;             // Leemos la edad
            cin.ignore();            // Limpiamos el buffer de entrada
            cout << "Título o Profesión: ";
            getline(cin, titulo);    // Leemos el título
            cout << "No. de Cédula Profesional: ";
            cin >> noCedulaProfesional;  // Leemos el número de cédula
            cin.ignore();                // Limpiamos el buffer de entrada

            // Creamos un nuevo objeto Profesor
            Profesor profesor(nombre, apellido, sexo, edad, titulo, noCedulaProfesional);
            profesores.push_back(profesor);  // Agregamos el profesor al vector de profesores
            cout << "Profesor agregado exitosamente!" << endl;
            break;
        }
        case 3: {
            // Agregar Materia
            string nombreMateria;
            int creditos;
            size_t seleccionProfesor;

            if(profesores.empty()) {  // Verificamos si hay profesores disponibles
                cout << "No hay profesores disponibles. Por favor, agregue un profesor primero." << endl;
                break;
            }

            cout << "Nombre de la materia: ";
            cin.ignore();
            getline(cin, nombreMateria);  // Leemos el nombre de la materia
            cout << "Número de créditos: ";
            cin >> creditos;              // Leemos los créditos
            cin.ignore();                 // Limpiamos el buffer de entrada

            cout << "Seleccione un profesor para esta materia:" << endl;
            for(size_t i = 0; i < profesores.size(); i++) {
                // Mostramos los profesores disponibles
                cout << i+1 << ". " << profesores[i].getNombreCompleto() << endl;
            }
            cout << "Opción: ";
            cin >> seleccionProfesor;  // Leemos la selección del usuario
            cin.ignore();              // Limpiamos el buffer de entrada

            if(seleccionProfesor > 0 && seleccionProfesor <= profesores.size()) {
                // Creamos una nueva materia con el profesor seleccionado
                Materia materia(nombreMateria, creditos, profesores[seleccionProfesor - 1]);
                materiasDisponibles.push_back(materia);  // Agregamos la materia al vector de materias
                cout << "Materia agregada exitosamente!" << endl;
            } else {
                cout << "Selección inválida." << endl;
            }
            break;
        }
        case 4: {
            // Visualizar Alumnos
            if(alumnos.empty()) {  // Verificamos si hay alumnos registrados
                cout << "No hay alumnos registrados." << endl;
            } else {
                cout << "Lista de Alumnos:" << endl;
                for(const auto& alumno : alumnos) {
                    alumno.mostrarAlumno();  // Mostramos la información de cada alumno
                }
            }
            break;
        }
        case 5: {
            // Visualizar Profesores
            if(profesores.empty()) {  // Verificamos si hay profesores registrados
                cout << "No hay profesores registrados." << endl;
            } else {
                cout << "Lista de Profesores:" << endl;
                for(const auto& profesor : profesores) {
                    profesor.mostrarProfesor();  // Mostramos la información de cada profesor
                }
            }
            break;
        }
        case 6: {
            // Visualizar Materias
            if(materiasDisponibles.empty()) {  // Verificamos si hay materias registradas
                cout << "No hay materias registradas." << endl;
            } else {
                cout << "Lista de Materias:" << endl;
                for(const auto& materia : materiasDisponibles) {
                    materia.mostrarMateria();  // Mostramos la información de cada materia
                }
            }
            break;
        }
        case 7: {
            // Buscar Profesor por ID
            int id;
            cout << "Ingrese el ID del profesor: ";
            cin >> id;  // Leemos el ID del profesor
            Profesor* profesor = findProfesorByID(id);  // Buscamos el profesor por ID
            if (profesor != nullptr) {
                profesor->mostrarProfesor();  // Mostramos la información del profesor
            } else {
                cout << "Profesor no encontrado con el ID proporcionado." << endl;
            }
            break;
        }
        case 8: {
            // Buscar Materia por ID
            int id;
            cout << "Ingrese el ID de la materia: ";
            cin >> id;  // Leemos el ID de la materia
            Materia* materia = findMateriaByID(id);  // Buscamos la materia por ID
            if (materia != nullptr) {
                materia->mostrarMateria();  // Mostramos la información de la materia
            } else {
                cout << "Materia no encontrada con el ID proporcionado." << endl;
            }
            break;
        }
        case 9: {
            // Buscar Alumno por ID
            int id;
            cout << "Ingrese el ID del alumno: ";
            cin >> id;  // Leemos el ID del alumno
            Alumno* alumno = findAlumnoByID(id);  // Buscamos el alumno por ID
            if (alumno != nullptr) {
                alumno->mostrarAlumno();  // Mostramos la información del alumno
            } else {
                cout << "Alumno no encontrado con el ID proporcionado." << endl;
            }
            break;
        }
        case 10:
            // Salir del programa
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            // Opción no válida
            cout << "Opción no válida, intenta de nuevo." << endl;
            break;
    }
}

int main() {
    // Pre-cargar datos iniciales para establecer relaciones entre clases

    // Agregar 2 profesores
    profesores.push_back(Profesor("Juan", "Perez", "Masculino", 45, "Matemáticas", 123456));
    profesores.push_back(Profesor("Maria", "Lopez", "Femenino", 38, "Física", 234567));

    // Agregar 3 materias, asignándolas a los profesores previamente creados
    materiasDisponibles.push_back(Materia("Álgebra", 6, profesores[0]));
    materiasDisponibles.push_back(Materia("Cálculo", 8, profesores[0]));
    materiasDisponibles.push_back(Materia("Física", 6, profesores[1]));

    // Agregar 2 alumnos y asignarles materias
    Alumno alumno1("Carlos", "Gonzalez", 1001, 20, "Masculino", "Segundo");
    alumno1.agregarMateria(materiasDisponibles[0]);  // Agregamos "Álgebra" a Carlos
    alumno1.agregarMateria(materiasDisponibles[2]);  // Agregamos "Física" a Carlos
    alumnos.push_back(alumno1);                      // Agregamos a Carlos al vector de alumnos

    Alumno alumno2("Ana", "Martinez", 1002, 19, "Femenino", "Segundo");
    alumno2.agregarMateria(materiasDisponibles[1]);  // Agregamos "Cálculo" a Ana
    alumno2.agregarMateria(materiasDisponibles[2]);  // Agregamos "Física" a Ana
    alumnos.push_back(alumno2);                      // Agregamos a Ana al vector de alumnos

    int option = 0;  // Variable para almacenar la opción seleccionada por el usuario
    do {
        clearScreen();   // Limpiamos la pantalla
        showMenu();      // Mostramos el menú
        cin >> option;   // Leemos la opción seleccionada
        clearScreen();   // Limpiamos la pantalla nuevamente
        handleOption(option);  // Maneja la opción seleccionada
        if (option != 10) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();   // Pausamos hasta que el usuario presione Enter
        }
    } while (option != 10);  // Repetimos hasta que el usuario elija salir

    return 0;  // Retornamos 0 indicando que el programa finalizó correctamente
}
