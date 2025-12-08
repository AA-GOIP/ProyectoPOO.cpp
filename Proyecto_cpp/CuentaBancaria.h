//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#pragma once
#include "ProductoFinanciero.h"
#include <string>
using namespace std;

//clase CuentaBancaria, que hereda de ProductoFinanciero
class CuentaBancaria : public ProductoFinanciero {
private:
    std::string numeroCuenta_;
    double saldo_;
public:
    CuentaBancaria();
    CuentaBancaria(const std::string& numero, double saldoInicial, int id);

    //Getters
    std::string getNumeroCuenta() const;
    double getSaldo() const;
    
    //Setters
    void setNumeroCuenta(const std::string& numero);
    void setSaldo(double saldo);

    // Operaciones
    void Depositar(double cantidad);
    void Retirar(double cantidad);

    //Muestra la cuenta
    void MostrarCuenta() const;
};
