//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include <iostream>
#include "AplicacionBanco.h"
#include "Cliente.h"
#include "CuentaBancaria.h"
#include "Tarjeta.h"
#include "Inversion.h"

int main(){
    //Lo primero es para que se cree la aplicacion del banco y se pueda ejecutar.
    AplicacionBanco app("Banco Digital MX",101);
    app.IniciarSesion();

    //1.Composicion, el banco crea clientes desde adentro.
    app.CrearCliente("Atena Girón",1,18);

    //2.Crea productos financieros fuera de la app.
    //Agregación, se registran dentro de la cuenta.

    //Cuenta bancaria
    CuentaBancaria cuenta1("123-789", 2500,52);
    Tarjeta tarjeta1("Visa Clasica",5000.0,24.0,20);
    //Inversión
    Inversion inversion1(10000.0,8.5,12,30);//tasa anual
    //Se Registran los productos en la aplicación, agregacion.
    app.RegistrarCuenta(cuenta1);
    app.RegistrarTarjeta(tarjeta1);
    app.RegistrarInversiones(inversion1);

    //3. Se muestran todos los productos dentro de la app
    //Mostrar catálogo de todo
    std::cout << std::endl << "Mostrando los productos registrados"<<std::endl;
    app.MostrarCatalogoCuentas();
    app.MostrarCatalogoTarjetas();
    app.MostrarCatalogoInversiones();


    //Pruebas de las operaciones que se pueden hacer con las tarjetas
    std::cout << std::endl <<"Operaciones"<<std::endl;
    cuenta1.Depositar(500);
    cuenta1.Retirar(200);

    tarjeta1.Comprar(1200);
    tarjeta1.Pagar(300);

    
    std::cout << std::endl << "Intereses"<<std::endl;
    inversion1.MostrarInversion();
    std::cout<<"Ganancia: $"<<inversion1.CalcularGanancia()<< std::endl;

    app.CerrarSesion();

    return 0;
}