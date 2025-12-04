//AA_GIOP
#include <iostream>
#include <string>

//clase 1 cliente, que no hereda nada

class Cliente{
private:
    std::string nombre_; 
    int edad_;
public:
    Cliente(const std::string& nombre, int edad)
        : nombre_(nombre), edad_(edad) {}

    void MostrarInformacion() const{
        std::cout<<"Cliente: "<<nombre_<<", Edad: "<<edad_<<"\n";
    }
};

