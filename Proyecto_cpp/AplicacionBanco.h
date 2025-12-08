//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#pragma once
#include <vector>
#include <string>
#include "Cliente.h"
#include "CuentaBancaria.h"
#include "Tarjeta.h"
#include "Inversion.h"

//Clase AplicacionBanco donde implemento, composicion y agregación.
class AplicacionBanco {
private:
    std::string nombreApp_;
    int idApp_;
    std::vector<Cliente> clientes_;       // composición
    std::vector<CuentaBancaria> cuentas_; // agregación 
    std::vector<Tarjeta> tarjetas_;
    std::vector<Inversion> inversiones_;
public:
    AplicacionBanco();
    AplicacionBanco(const std::string& nombre, int id);
    //inicio y cierre 
    void IniciarSesion() const;
    void CerrarSesion() const;

    //Composición porque se le permite crear
    void CrearCliente(const std::string& nombre, int id, int edad);

    //Agregación, usa de las copias
    void RegistrarCuenta(const CuentaBancaria& c);
    void RegistrarTarjeta(const Tarjeta& t);
    void RegistrarInversiones(const Inversion& i);

    //Mostrar catálogos la funcion para que el usuario pueda ver lo que tiene 
    void MostrarCatalogoCuentas() const;
    void MostrarCatalogoTarjetas() const;
    void MostrarCatalogoInversiones() const;
};
