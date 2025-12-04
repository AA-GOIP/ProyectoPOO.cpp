//AA_GIOP
#include <iostream>
#include <string>
#include <math.h>

//clase 1 cliente

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

//clase 2 cuenta del banco
class CuentaBancaria{ 
private:
    std::string numeroCuenta_;
    double saldo_;
public: 
    CuentaBancaria(const std::string& numero, double saldoInicial)
        : numeroCuenta_(numero), saldo_(saldoInicial){}

    void MostrarCuenta() const {
        std::cout<<"Cuenta Bancaria:"<<numeroCuenta_<<", saldo: "<<saldo_<<"\n";
    }

    void Depositar(double cantidad){
        if (cantidad<=0){
            std::cout<<"Cantidad invalida para deposito.\n";
            return;
        }
        saldo_ += cantidad;
        std::cout<<"Deposito realizado. Su saldo actual es de: $"<<saldo_<<"\n";
    }

    void Retirar(double cantidad){
        if(cantidad<= 0){
            std::cout<<"Cantidad invalida para deposito.\n";
            return;
        }
        if(cantidad <= saldo_){
            saldo_-=cantidad;
            std::cout<<"Retiro realizado. Saldo actual: $" <<saldo_<<"\n";
        } else{
            std::cout<<"Fondos insuficientes\n";
        }
    }
};

//clase 3 tarjeta de credito
class TarjetaCredito{
private: 
    std::string nombre_;
    double limite_;
    double deuda_;
    double tasaInteres_;

public:
    TarjetaCredito(const std::string& nombre, double limite, double tasa)
        : nombre_(nombre), limite_(limite), deuda_(0.0), tasaInteres_(tasa){}

    void MostrarInformacion() const{
        std::cout<<"Tarjeta de Crédito: "<<nombre_
                 <<"\n Límite: $"<<limite_
                 <<"\n Deuda actual:"<<deuda_
                 <<"\n Tasa de interés:"<<tasaInteres_<<"\n";
    }

    void Comprar(double cantidad){
        if (cantidad<=0){
            std::cout<<"Cantidad invalida para deposito.\n";
            return;
        }
        if(deuda_+cantidad <= limite_){
            deuda_ +=cantidad;
            std::cout<<"Compra realizada. Nueva deuda: $"<<deuda_<<"\n";
        } else{
            std::cout<<"compra denegada. Excede el límite de crédito\n";
        }
    }

    void Pagar(double cantidad){
        if (cantidad<=0){
            std::cout<<"Cantidad invalida para deposito.\n";
            return;
        }

        if (cantidad>=deuda_){
            std::cout<<"pago de $" << deuda_<<"saldo total realizado. Deuda ahora: $0\n";
            deuda_=0.0;
        }else {
            deuda_-=cantidad;
            std::cout<<"Pago de $"<<cantidad<<"realizado. Deuda actual: $"<<deuda_<<"\n";
        }
    }

    //pago del interes
    void AplicarInteresMensual(){
        if (deuda_ <=0.0){
            std::cout<<"No hay deuda. No se aplica interés.\n";
            return;
        }
        double tasaMensual = (tasaInteres_ / 100.0) / 12.0; 
        double interes = deuda_ * tasaMensual;
        interes = std::round(interes * 100.0) / 100.0;
        deuda_ += interes;
        std::cout << "Interés mensual aplicado: $" << interes << ". Deuda nueva: $" << deuda_ << "\n";
    }

    double ObtenerDeuda() const {
        return deuda_;
    }
};

//main para la demostracion sin interaccion
int main(){
    //cliente ficticio creacion
    Cliente cliente1("Atena Giron", 18);
    cliente1.MostrarInformacion();

    //cuenta ficticia creacion
    CuentaBancaria cuenta1("123-456", 2000.0);
    cuenta1.MostrarCuenta();

    //operaciones simuladas deposito y retiro
    std::cout<<"Operaciones Bancarias\n";
    cuenta1.Depositar(300);
    cuenta1.Retirar(200);

    //creacion de la tarjeta con la tasa anual dada en porcentaje 24% como es comun 
    std::cout<<"Operaciones con tarjeta\n";
    TarjetaCredito tarjeta1("Visa clásica", 5000.0, 24.0);
    tarjeta1.MostrarInformacion();

    //simulacion de la compra de productos y pagos con la tarjeta
    tarjeta1.Comprar(1200);
    tarjeta1.Pagar(100);
    tarjeta1.MostrarInformacion();

    //aplicacion de interes mensual en la tarjeta
    tarjeta1.AplicarInteresMensual();

    //otro pago para que se pueda demostrar mas el funcionamiento de la tarjeta
    tarjeta1.Pagar(400.0);

    //al momento de aplicar el interes se simula que ya paso otro mes
    tarjeta1.AplicarInteresMensual();
    
    //pago total
    tarjeta1.Pagar(2000.0);
    tarjeta1.MostrarInformacion();

    return 0;
}

