//AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#pragma once
#include <string>

//Clase la clase padre o "el producto base"
class ProductoFinanciero {
protected:
    int idProducto_;
    std::string nombreProducto_;
    bool activo_;
public:
    ProductoFinanciero();
    ProductoFinanciero(const std::string& nombre, int id);

    //Getters
    int getIdProducto() const;
    std::string getNombreProducto() const;
    bool isActivo() const;

    //Setters
    void setNombreProducto(const std::string& nombre);
    void setIdProducto(int id);
    void setActivo(bool activo);

    //Mostrar el procuto
    void MostrarProducto() const;
};

