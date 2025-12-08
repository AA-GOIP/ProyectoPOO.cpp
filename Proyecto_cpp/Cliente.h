//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#pragma once
#include <string>
#include <vector>
using namespace std;

//clase  cliente, que no hereda nada y mantiene los identificadores de los productos
class Cliente {
private:
    std::string nombre_;
    int id_;
    int edad_;
    std::vector<std::string> cuentasNum_;
    std::vector<int> tarjetasIds_;
    std::vector<int> inversionesIds_;
public:
    Cliente();
    Cliente(const std::string& nombre, int id, int edad);

    //Getters
    std::string GetNombre() const;
    int getId() const;
    int getEdad() const;

    //Setters
    void setNombre(const std::string& nombre);
    void setEdad(int edad);

    //Asociaciones para agragar en este caso las inversiones, tarjetas y cuentas
    void AgregarCuenta(const std::string& numero);
    void AgregarTarjeta(int idTarjeta);
    void AgregarInversion(int idInversion);

    const std::vector<std::string>& GetCuentas() const;
    const std::vector<int>& GetTarjetas() const;
    const std::vector<int>& GetInversiones() const;

    void MostrarCliente() const;
};
