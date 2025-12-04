#include <iostream>
#include <string>
#include <vector>
#include "CuentaBancaria.cpp"
#include "TarjetaCredito.cpp"

//clase 4 Banco, que tiene 2 opciones composicion y agregacion
class Banco {
private:
    std::vector<CuentaBancaria> cuentas_;       
    std::vector<TarjetaCredito*> tarjetas_;     

public:
    void CrearCuenta(const std::string& numero, double saldo) {
        cuentas_.push_back(CuentaBancaria(numero, saldo));
    }

    void RegistrarTarjeta(TarjetaCredito* tarjeta) {
        tarjetas_.push_back(tarjeta);
    }

    void MostrarCuentas() const {
        for (const auto& c : cuentas_) {
            c.MostrarCuenta();
        }
    }

    void MostrarTarjetas() const {
        for (const auto& t : tarjetas_) {
            t->MostrarInformacion();
        }
    }
};