//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#pragma once
#include "ProductoFinanciero.h"
using namespace std;

//clase tarjeta de credito, que hereda de La aplicacion de Banco
class Tarjeta : public ProductoFinanciero {
private:
    double limite_;
    double deuda_;
    double tasaAnual_;
public:
    Tarjeta();
    Tarjeta(const std::string& nombre, double limite, double tasa, int id);

    //Getters
    double getLimite() const;
    double getDeuda() const;
    double getTasaAnual() const;

    //Setters
    void setLimite(double limite);
    void setTasaAnual(double tasa);

    // Operaciones de la tarjeta
    void Comprar(double cantidad);
    void Pagar(double cantidad);
    void AplicarInteresMensual();
    
    //para que se vea lo que se puede hacer
    void MostrarTarjeta() const;
};
