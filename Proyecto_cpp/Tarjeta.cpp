//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include "Tarjeta.h"
#include <iostream>
#include <algorithm>
#include <cmath>

//clase tarjeta de credito, que hereda de La aplicacion de Banco
Tarjeta::Tarjeta() : ProductoFinanciero(), limite_(0.0), deuda_(0.0), tasaAnual_(0.0) {}

Tarjeta::Tarjeta(const std::string& nombre, double limite, double tasa, int id):ProductoFinanciero(nombre, id), limite_(limite), deuda_(0.0), tasaAnual_(tasa) {}

double Tarjeta::GetLimite() const {
     return limite_; 
    }
double Tarjeta::GetDeuda() const { 
    return deuda_; 
}
double Tarjeta::GetTasaAnual() const { 
    return tasaAnual_; 
}

void Tarjeta::SetLimite(double limite) {
     limite_ = limite; 
    }
void Tarjeta::SetTasaAnual(double tasa) { 
    tasaAnual_ = tasa; 
}

void Tarjeta::Comprar(double cantidad) {
    if (cantidad <= 0.0) {
        std::cout << "Compra fallida: la cantidad debe ser mayor a cero." << std::endl;
        return;
    }
    if (deuda_ + cantidad > limite_) {
        std::cout << "Compra rechazada: excede el límite." << std::endl;
        return;
    }
    deuda_ += cantidad;
    std::cout << "Compra:" << cantidad << "Deuda: " << deuda_ << std::endl;
}

void Tarjeta::Pagar(double cantidad) {
    if (cantidad <= 0.0) {
        std::cout << "Pago fallido: la cantidad debe ser mayor a cero." << std::endl;
        return;
    }
    deuda_ = std::max(0.0, deuda_ - cantidad);
    std::cout << "Pago:" << cantidad << "Deuda: " << deuda_ << std::endl;
}

void Tarjeta::AplicarInteresMensual() {
    if (deuda_ <= 0.0) {
        std::cout << "No hay deuda. No se aplica interés." << std::endl;
        return;
    }
    double tasaMensual = (tasaAnual_ / 100.0) / 12.0;
    double interes = std::round(deuda_ * tasaMensual * 100.0) / 100.0;//conversion
    deuda_ += interes;
    std::cout << "Interés mensual aplicado:$" << interes << "Deuda nueva:$" << deuda_ << std::endl;
}

void Tarjeta::MostrarTarjeta() const {
    std::cout << "Tarjeta:" << GetNombreProducto()<< "ID:" << GetIdProducto()<< "Límite:$" << limite_<< "Deuda:$" << deuda_<< "Tasa anual:" << tasaAnual_ << "%" << std::endl;
}
