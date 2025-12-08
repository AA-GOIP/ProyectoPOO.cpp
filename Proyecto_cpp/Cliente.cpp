//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include "Cliente.h"
#include <iostream>

//clase  cliente, que no hereda nada y mantiene los identificadores de los productos
Cliente::Cliente() : nombre_(""), id_(0), edad_(0) {
}
Cliente::Cliente(const std::string& nombre, int id, int edad) : nombre_(nombre), id_(id), edad_(edad) {
}

std::string Cliente::GetNombre() const { 
    return nombre_; 
}
int Cliente::GetId() const {
     return id_; 
}
int Cliente::GetEdad() const { 
    return edad_; 
}

void Cliente::SetNombre(const std::string& nombre) { 
    nombre_ = nombre; 
}
void Cliente::SetEdad(int edad) { 
    edad_ = edad; 
}

void Cliente::AgregarCuenta(const std::string& numero) {
     cuentasNum_.push_back(numero); 
    }
void Cliente::AgregarTarjeta(int idTarjeta) {
     tarjetasIds_.push_back(idTarjeta); 
    }
void Cliente::AgregarInversion(int idInversion) {
     inversionesIds_.push_back(idInversion); 
    }

const std::vector<std::string>& Cliente::GetCuentas() const {
     return cuentasNum_;
     }
const std::vector<int>& Cliente::GetTarjetas() const {
     return tarjetasIds_; 
    }
const std::vector<int>& Cliente::GetInversiones() const {
     return inversionesIds_; 
    }

void Cliente::MostrarCliente() const {
    std::cout << "Cliente: " << nombre_ << "ID:" << id_ << "Edad: " << edad_ << std::endl;
}

