#pragma once
#include <iostream>
#include <string>
#include "AplicacionBanco.cpp"

//clase 2 cuenta del CuentaBancaria, que hereda de La aplicacion de Banco

class CuentaBancaria : public AplicacionBanco {
private:
    std::string numero_;
    double saldo_;

public:
    CuentaBancaria(const std::string& numero, double saldoInicial)
        : AplicacionBanco("Módulo: Cuenta Bancaria", 101),
          numero_(numero), saldo_(saldoInicial) {}

    void MostrarCuenta() const {
        std::cout << "Cuenta: " << numero_ << " | Saldo: $" << saldo_ << "\n";
    }

    void Depositar(double cantidad) {
        if (cantidad <= 0) {
            std::cout << "Cantidad inválida.\n";
            return;
        }
        saldo_ += cantidad;
        std::cout << "Depósito realizado. Nuevo saldo: " << saldo_ << "\n";
    }

    void Retirar(double cantidad) {
        if (cantidad <= 0) {
            std::cout << "Cantidad invalida.\n";
            return;
        }
        if (cantidad <= saldo_) {
            saldo_ -= cantidad;
            std::cout << "Retiro realizado. Nuevo saldo: " << saldo_ << "\n";
        } else {
            std::cout << "Fondos insuficientes.\n";
        }
    }
};
