//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include "AplicacionBanco.h"
#include <iostream>

//Clase AplicacionBanco donde implemento, composicion y agregación.
AplicacionBanco::AplicacionBanco() : nombreApp_(""), idApp_(0) {}
AplicacionBanco::AplicacionBanco(const std::string& nombre, int id) : nombreApp_(nombre), idApp_(id) {}

void AplicacionBanco::IniciarSesion() const {
    std::cout << "Sesion iniciada en:" << nombreApp_ << "ID:" << idApp_ << std::endl;
}
void AplicacionBanco::CerrarSesion() const {
    std::cout << "Sesion cerrada." << std::endl;
}

void AplicacionBanco::CrearCliente(const std::string& nombre, int id, int edad) {
    clientes_.push_back(Cliente(nombre, id, edad));
    std::cout << "Cliente creado: " << nombre << "ID:" << id << std::endl;
}

void AplicacionBanco::RegistrarCuenta(const CuentaBancaria& c) {
    cuentas_.push_back(c);
    std::cout << "Cuenta registrada:" << c.GetNumeroCuenta() << std::endl;
}
void AplicacionBanco::RegistrarTarjeta(const Tarjeta& t) {
    tarjetas_.push_back(t);
    std::cout << "Tarjeta registrada:" << t.GetNombreProducto() << " | ID: " << t.GetIdProducto() << std::endl;
}
void AplicacionBanco::RegistrarInversiones(const Inversion& i) {
    inversiones_.push_back(i);
    std::cout << "Inversion registrada:ID" << i.GetIdProducto() << std::endl;
}

void AplicacionBanco::MostrarCatalogoCuentas() const {
    std::cout << "Catalogo de Cuentas" << std::endl;
    for (const auto& c : cuentas_) c.MostrarCuenta();
}
void AplicacionBanco::MostrarCatalogoTarjetas() const {
    std::cout << "Catalogo de Tarjetas" << std::endl;
    for (const auto& t : tarjetas_) t.MostrarTarjeta();
}
void AplicacionBanco::MostrarCatalogoInversiones() const {
    std::cout << "Catalogo de Inversiones" << std::endl;
    for (const auto& i : inversiones_) i.MostrarInversion();
}
