/* Este programa gestionara la información
relacionada con los vehículos que administra y comercializa una empresa
consignataria de vehículos (compra-venta de vehículos).
fecha: 12/02/2024
autor: Santiago Guevara Mendez
 */
#include <iostream>
#include <fstream>

using namespace std;

struct vehiculo{
    string marca, modelo, color, placa;
    int anio;
    float precio;
    bool estado,estado2;
};

bool placaExiste(const string& placa) {
    ifstream archivo("vehiculos.bin", ios::binary);
    vehiculo unVehiculo;
    while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))) {
        if (unVehiculo.placa == placa) {
            archivo.close();
            return true; // Si la placa existe, devuelve verdadero
        }
    }
    archivo.close();
    return false; // Si no se encontró la placa, devuelve falso
}

void ingresarVehiculo (){
    char opcionEstado,opcionEstado2;
    ofstream archivo("vehiculos.bin", ios::binary | ios::app);
    vehiculo unVehiculo;

    do {
        cout << "Ingrese la placa del vehiculo: ";
        cin >> unVehiculo.placa;
        if (placaExiste(unVehiculo.placa)) {
            cout << "La placa ya existe en el archivo. Por favor, ingrese una placa diferente." << endl;
        }
    } while (placaExiste(unVehiculo.placa));
    


    cout << "Ingrese la marca del vehiculo: ";
    cin >> unVehiculo.marca;
    cout << "Ingrese el modelo del vehiculo: ";
    cin >> unVehiculo.modelo;
    cout << "Ingrese el color del vehiculo: ";
    cin >> unVehiculo.color;
    cout << "Ingrese el ano del vehiculo: ";
    cin >> unVehiculo.anio;
    cout << "Ingrese el precio del vehiculo: ";
    cin >> unVehiculo.precio;
    cout << "Ingrese el estado del vehiculo (P-propio, C-consignado): ";
    cin >> opcionEstado;
    if (opcionEstado == 'P' || opcionEstado == 'p'){
        unVehiculo.estado = true;
    } else {
        unVehiculo.estado = false;
    }
    cout << "Estado del vehiculo (A-activo, E-eliminado).";
    cin >> opcionEstado2;
    if (opcionEstado2 == 'A' || opcionEstado2 == 'a'){
        unVehiculo.estado2 = true;
    } else {
        unVehiculo.estado2 = false;
    }
    cout << "Vehiculo ingresado correctamente" << endl;
     archivo.write(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo));
     archivo.close();
}

    void buscarVehiculo (){
        ifstream archivo;
        archivo.open("vehiculos.bin", ios::binary);
        vehiculo unVehiculo;
        int opcion,anio;
        cout << "Desea buscar el vehiculo por: ";
        cout << "1. Marca" << endl;
        cout << "2. Modelo" << endl;
        cout << "3. Color" << endl;
        cout << "4. Placa" << endl;
        cout << "5. Ano" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        string marca, modelo, color, placa;
        switch (opcion){
            case 1:
                cout << "Ingrese la marca del vehiculo: ";
                cin >> marca;
                while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))){
                    if (unVehiculo.marca == marca){
                        cout << "Marca: " << unVehiculo.marca << endl;
                        cout << "Modelo: " << unVehiculo.modelo << endl;
                        cout << "Color: " << unVehiculo.color << endl;
                        cout << "Placa: " << unVehiculo.placa << endl;
                        cout << "Ano: " << unVehiculo.anio << endl;
                        cout << "Precio: " << unVehiculo.precio << endl;
                        if (unVehiculo.estado){
                            cout << "Estado: Propio" << endl;
                        } else {
                            cout << "Estado: Consignado" << endl;
                        }
                    }
                }
                if(unVehiculo.estado2){
                    cout << "Estado: Activo" << endl;
                } else {
                    cout << "Estado: Eliminado" << endl;
                }
                break;
            case 2:

                cout << "Ingrese el modelo del vehiculo: ";
                cin >> modelo;
                while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))){
                    if (unVehiculo.modelo == modelo){
                        cout << "Marca: " << unVehiculo.marca << endl;
                        cout << "Modelo: " << unVehiculo.modelo << endl;
                        cout << "Color: " << unVehiculo.color << endl;
                        cout << "Placa: " << unVehiculo.placa << endl;
                        cout << "Ano: " << unVehiculo.anio << endl;
                        cout << "Precio: " << unVehiculo.precio << endl;
                        if (unVehiculo.estado){
                            cout << "Estado: Propio" << endl;
                        } else {
                            cout << "Estado: Consignado" << endl;
                        }
                    }
                }
                if(unVehiculo.estado2){
                    cout << "Estado: Activo" << endl;
                } else {
                    cout << "Estado: Eliminado" << endl;
                }
                break;
            case 3:
                cout << "Ingrese el color del vehiculo: ";
                cin >> color;
                while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))){
                    if (unVehiculo.color == color){
                        cout << "Marca: " << unVehiculo.marca << endl;
                        cout << "Modelo: " << unVehiculo.modelo << endl;
                        cout << "Color: " << unVehiculo.color << endl;
                        cout << "Placa: " << unVehiculo.placa << endl;
                        cout << "Ano: " << unVehiculo.anio << endl;
                        cout << "Precio: " << unVehiculo.precio << endl;
                        if (unVehiculo.estado){
                            cout << "Estado: Propio" << endl;
                        } else {
                            cout << "Estado: Consignado" << endl;
                        }
                    }
                }
                if(unVehiculo.estado2){
                    cout << "Estado: Activo" << endl;
                } else {
                    cout << "Estado: Eliminado" << endl;
                }
                break;

            case 4:
                cout << "Ingrese la placa del vehiculo: ";
                cin >> placa;
                while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))){
                    if (unVehiculo.placa == placa){
                        cout << "Marca: " << unVehiculo.marca << endl;
                        cout << "Modelo: " << unVehiculo.modelo << endl;
                        cout << "Color: " << unVehiculo.color << endl;
                        cout << "Placa: " << unVehiculo.placa << endl;
                        cout << "Ano: " << unVehiculo.anio << endl;
                        cout << "Precio: " << unVehiculo.precio << endl;
                        if (unVehiculo.estado){
                            cout << "Estado: Propio" << endl;
                        } else {
                            cout << "Estado: Consignado" << endl;
                        }
                    }
                }
                if(unVehiculo.estado2){
                    cout << "Estado: Activo" << endl;
                } else {
                    cout << "Estado: Eliminado" << endl;
                }
                break;

            case 5:
                cout << "Ingrese el ano del vehiculo: ";
                cin >> anio;
                while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))){
                    if (unVehiculo.anio == anio){
                        cout << "Marca: " << unVehiculo.marca << endl;
                        cout << "Modelo: " << unVehiculo.modelo << endl;
                        cout << "Color: " << unVehiculo.color << endl;
                        cout << "Placa: " << unVehiculo.placa << endl;
                        cout << "Ano: " << unVehiculo.anio << endl;
                        cout << "Precio: " << unVehiculo.precio << endl;
                        if (unVehiculo.estado){
                            cout << "Estado: Propio" << endl;
                        } else {
                            cout << "Estado: Consignado" << endl;
                        }
                    }
                }
                if(unVehiculo.estado2){
                    cout << "Estado: Activo" << endl;
                } else {
                    cout << "Estado: Eliminado" << endl;
                }
                break;
            default:    
                cout << "Opcion no valida" << endl;
                break;
        }

        archivo.close();
    }

void modificarVehiculo() {
    fstream archivo;
    archivo.open("vehiculos.bin", ios::binary | ios::in | ios::out);

    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    vehiculo unVehiculo;
    string placa;
    cout << "Ingrese la placa del vehiculo a modificar: ";
    cin >> placa;
    char opcion;

    while (archivo.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))) {
        if (unVehiculo.placa == placa) {
            cout << "Que desea modificar?" << endl;
            cout << "1. Modelo" << endl;
            cout << "2. Anio" << endl;
            cout << "3. Color" << endl;
            cout << "4. Propio/Consignado" << endl;
            cout << "5. Precio" << endl;
            cout << "6. Estado (Activo/Eliminado)" << endl;
            cout << "Ingrese la opcion: ";
            cin >> opcion;
            
            switch(opcion) {
                case '1':
                    cout << "Ingrese el nuevo modelo del vehiculo: ";
                    cin >> unVehiculo.modelo;
                    break;
                case '2':
                    cout << "Ingrese el nuevo año del vehiculo: ";
                    cin >> unVehiculo.anio;
                    break;
                case '3':
                    cout << "Ingrese el nuevo color del vehiculo: ";
                    cin >> unVehiculo.color;
                    break;
                case '4':
                    cout << "Ingrese el nuevo estado del vehiculo (P-propio, C-consignado): ";
                    cin >> opcion;
                    unVehiculo.estado = (opcion == 'P' || opcion == 'p');
                    break;
                case '5':
                    cout << "Ingrese el nuevo precio del vehiculo: ";
                    cin >> unVehiculo.precio;
                    break;
                case '6':
                    cout << "Ingrese el nuevo estado del vehiculo (A-activo, E-eliminado): ";
                    cin >> opcion;
                    unVehiculo.estado2 = (opcion == 'A' || opcion == 'a');
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }

            // Mueve el cursor hacia atrás para sobrescribir la estructura en el mismo lugar
            archivo.seekp(-static_cast<int>(sizeof(vehiculo)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo));
            cout << "Vehiculo modificado exitosamente." << endl;
            archivo.close();
            return; // Sal del bucle después de modificar el vehículo
        }
    }

    cout << "No se encontró ningún vehículo con la placa especificada." << endl;
    archivo.close();
}


void eliminarVehiculo() {
    string placaAEliminar;
    cout << "Ingrese la placa del vehiculo a eliminar: ";
    cin >> placaAEliminar;

    ifstream archivoEntrada("vehiculos.bin", ios::binary); // Abre el archivo en modo binario
    ofstream archivoTemporal("temporal.bin", ios::binary); // Archivo temporal para escribir los vehículos excepto el que queremos eliminar

    vehiculo unVehiculo;

    while (archivoEntrada.read(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo))) {
        // Si la placa del vehículo actual no coincide con la placa a eliminar, escribirlo en el archivo temporal
        if (unVehiculo.placa != placaAEliminar) {
            archivoTemporal.write(reinterpret_cast<char*>(&unVehiculo), sizeof(vehiculo));
        }
    }

    archivoEntrada.close();
    archivoTemporal.close();

    // Eliminar el archivo original y renombrar el archivo temporal
    remove("vehiculos.bin");
    rename("temporal.bin", "vehiculos.bin");
}



int mostrarMenu(int opcion){
    
    cout << "1. Ingresar un vehiculo" << endl;
    cout << "2. Buscar vehiculo" << endl;
    cout << "3. Modificar vehiculo" << endl;
    cout << "4. Eliminar vehiculo" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

int main () {
    int opcion;
    
    do {
        opcion = mostrarMenu(0);
        switch (opcion){
        case 1:
            ingresarVehiculo();
            break;
        case 2:
            buscarVehiculo();
            break;
        case 3:
            modificarVehiculo();
            break;
        case 4:
            eliminarVehiculo();
            break;
        case 5:
            cout << "Gracias por usar el programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }
    } while (opcion != 5);
    

    return 0;
}