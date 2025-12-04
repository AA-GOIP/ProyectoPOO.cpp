#pragma once
#include <iostream>
#include <string>


//Clase 4, la clase padre encargada de heredar 
class AplicacionBanco {
protected:
    std::string nombreModulo_;
    int idModulo_;

public:
    AplicacionBanco(const std::string& nombre, int id)
        : nombreModulo_(nombre), idModulo_(id) {}

    virtual void MostrarModulo() const {
        std::cout << "Módulo [" << idModulo_ << "]: " << nombreModulo_ << "\n";
    }

    virtual void Sincronizar() const {
        std::cout << "Sincronizando módulo ID " << idModulo_ << "...\n";
    }

    virtual ~AplicacionBanco() = default;
};