//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#pragma once
#include "ProductoFinanciero.h"
using namespace std;

//Clase inversiones
class Inversion : public ProductoFinanciero {
private:
    double montoInicial_;
    double tasaAnual_;
    int meses_;
public:
    Inversion();
    Inversion(double monto, double tasa, int meses, int id);
    
    //Getters
    double getMontoInicial() const;
    double getTasaAnual() const;
    int getMeses() const;

    //Operacion para calcular las ganancias
    double CalcularGanancia() const;

    //Para que se muestre la inversion
    void MostrarInversion() const;
};