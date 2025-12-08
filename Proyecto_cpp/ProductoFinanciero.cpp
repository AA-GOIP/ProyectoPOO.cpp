//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include "ProductoFinanciero.h"
#include <iostream>

//Clase la clase padre o "el producto base"
ProductoFinanciero::ProductoFinanciero()
    : idProducto_(0), nombreProducto_(""), activo_(true) {
    }

ProductoFinanciero::ProductoFinanciero(const std::string& nombre, int id):idProducto_(id), nombreProducto_(nombre), activo_(true) {
}

int ProductoFinanciero::GetIdProducto() const {
     return idProducto_; 
    }
std::string ProductoFinanciero::GetNombreProducto() const {
     return nombreProducto_; 
    }
bool ProductoFinanciero::IsActivo() const { 
    return activo_;
 }

void ProductoFinanciero::SetNombreProducto(const std::string& nombre) { 
    nombreProducto_ = nombre; 
}
void ProductoFinanciero::SetIdProducto(int id) { 
    idProducto_ = id;
 }
void ProductoFinanciero::SetActivo(bool activo) { 
    activo_ = activo; 
}

void ProductoFinanciero::MostrarProducto() const {
    std::cout << "Producto: " << nombreProducto_<< "ID: " << idProducto_<< "Activo: " << (activo_ "SI" : "NO") << std::endl;
}
