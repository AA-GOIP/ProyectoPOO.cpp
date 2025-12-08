//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include "CuentaBancaria.h"
#include <iostream>

//clase CuentaBancaria, que hereda de ProductoFinanciero
CuentaBancaria::CuentaBancaria():ProductoFinanciero(), numeroCuenta_(""), saldo_(0.0) {}

CuentaBancaria::CuentaBancaria(const std::string& numero, double saldoInicial, int id):ProductoFinanciero("Cuenta Bancaria", id), numeroCuenta_(numero), saldo_(saldoInicial) {}

std::string CuentaBancaria::GetNumeroCuenta() const {
     return numeroCuenta_; 
    }
double CuentaBancaria::GetSaldo() const {
     return saldo_; 
    }
void CuentaBancaria::SetNumeroCuenta(const std::string& numero) {
     numeroCuenta_ = numero; 
    }
void CuentaBancaria::SetSaldo(double saldo) {
     saldo_ = saldo; 
    }

void CuentaBancaria::Depositar(double cantidad) {
    if (cantidad <= 0.0) {
        std::cout << "Deposito fallido: la cantidad debe ser mayor a cero." << std::endl;
        return;
    }
    saldo_ += cantidad;
    std::cout << "Deposito:" << cantidad << "Saldo: " << saldo_ << std::endl;
}

void CuentaBancaria::Retirar(double cantidad) {
    if (cantidad <= 0.0) {
        std::cout << "Retiro fallido: la cantidad debe ser mayor a cero." << std::endl;
        return;
    }
    if (cantidad > saldo_) {
        std::cout << "Retiro fallido: fondos insuficientes." << std::endl;
        return;
    }
    saldo_ -= cantidad;
    std::cout << "Retiro:" << cantidad << "Saldo: " << saldo_ << std::endl;
}

void CuentaBancaria::MostrarCuenta() const {
    std::cout << "Cuenta: " << numeroCuenta_<<"ProductoID: " << GetIdProducto()<<"Saldo: $" << saldo_<< std::endl;
}
