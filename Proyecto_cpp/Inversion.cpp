//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include "Inversion.h"
#include <iostream>
#include <cmath>

//Clase inversiones
Inversion::Inversion() : ProductoFinanciero(), montoInicial_(0.0), tasaAnual_(0.0), meses_(0) {}
Inversion::Inversion(double monto, double tasa, int meses, int id):ProductoFinanciero("Inversion", id), montoInicial_(monto), tasaAnual_(tasa), meses_(meses) {}

double Inversion::GetMontoInicial() const { 
    return montoInicial_; 
}
double Inversion::GetTasaAnual() const { 
    return tasaAnual_; 
}
int Inversion::GetMeses() const { 
    return meses_;
 }

double Inversion::CalcularGanancia() const {
    double tasaMensual = (tasaAnual_ / 100.0) / 12.0;
    double monto = montoInicial_;
    for (int i = 0; i < meses_; ++i) {
        monto += monto * tasaMensual;
    }
    double ganancia = monto - montoInicial_;
    return std::round(ganancia * 100.0) / 100.0;
}

void Inversion::MostrarInversion() const {
    std::cout << "Inversion, Monto inicial:$" << montoInicial_<< "Meses:"<< meses_<< "Tasa anual: "<< tasaAnual_ << "%" << std::endl;
}
Inversion::Inversion() : ProductoFinanciero(), montoInicial_(0.0), tasaAnual_(0.0), meses_(0) {
}
Inversion::Inversion(double monto, double tasa, int meses, int id): ProductoFinanciero("Inversion", id), montoInicial_(monto), tasaAnual_(tasa), meses_(meses) {
}
//getters
double Inversion::getMontoInicial() const { 
    return montoInicial_; 
}
double Inversion::getTasaAnual() const { 
    return tasaAnual_;
 }
int Inversion::getMeses() const { 
    return meses_; 
}
//operaciones para calcular ganancias
double Inversion::CalcularGanancia() const {
    double tasaMensual = (tasaAnual_ / 100.0) / 12.0;
    double monto = montoInicial_;
    for (int i = 0; i < meses_; ++i) {
        monto += monto * tasaMensual;
    }
    double ganancia = monto - montoInicial_;
    return std::round(ganancia * 100.0) / 100.0;
}

void Inversion::MostrarInversion() const {
    std::cout << "Inversion, Monto inicial:$" << montoInicial_<<"Meses:" << meses_<<"Tasa anual: " << tasaAnual_ << "%" << std::endl;
}
