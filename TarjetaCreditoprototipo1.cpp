#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "AplicacionBanco.cpp"

//clase 3 tarjeta de credito, que hereda de La aplicacion de Banco
class TarjetaCredito : public AplicacionBanco {
private:
    double limite_;
    double deuda_;
    double tasaInteres_;

public:
    TarjetaCredito(double limite, double tasa)
        : AplicacionBanco("Módulo: Tarjeta de Crédito", 102),
          limite_(limite), deuda_(0.0), tasaInteres_(tasa) {}

    void MostrarInformacion() const {
        std::cout << "Tarjeta de Crédito"
                  << "\nLimite: $" << limite_
                  << "\nDeuda: $" << deuda_
                  << "\nTasa interés: " << tasaInteres_ << "%\n";
    }

    void Comprar(double cantidad) {
        if (cantidad <= 0) {
            std::cout << "Cantidad inválida.\n";
            return;
        }
        if (deuda_ + cantidad <= limite_) {
            deuda_ += cantidad;
            std::cout << "Compra realizada. Deuda actual: $" << deuda_ << "\n";
        } else {
            std::cout << "Compra rechazada. Excede el límite.\n";
        }
    }

    void Pagar(double cantidad) {
        if (cantidad <= 0) {
            std::cout << "Pago invalido.\n";
            return;
        }
        if (cantidad >= deuda_) {
            std::cout << "Pago total de " << deuda_ << " realizado.\n";
            deuda_ = 0.0;
        } else {
            deuda_ -= cantidad;
            std::cout << "Pago realizado. Deuda actual: " << deuda_ << "\n";
        }
    }

    void AplicarInteresMensual() {
        if (deuda_ <= 0) {
            std::cout << "Sin deuda. No hay interes.\n";
            return;
        }
        double tasaMensual = (tasaInteres_ / 100.0) / 12.0;
        double interes = deuda_ * tasaMensual;
        interes = std::round(interes * 100) / 100.0;
        deuda_ += interes;

        std::cout << "Interes aplicado: $" << interes
                  << "Nueva deuda: $" << deuda_ << "\n";
    }
};
