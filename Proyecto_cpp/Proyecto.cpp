/AA_GO_777
//fecha de última modificación: 07/12/2025
//Proyecto POO C++
//Sistema Bancario
#include <iostream>
#include <string>
#include <cmath>

//Clase la clase padre o "el producto base"
class ProductoFinanciero {
    protected:
        string nombreProducto_;
        int idProducto_;
        bool activo_;
    public:
        ProductoFinanciero(): nombreProducto_(""), idProducto_(0),activo_(true){    
        }
        ProductoFinanciero(const string& nombre, int id):nombreProducto_(nombre),idProducto_(id),activo_(true){
        }
    //Getters
    string getNombreProducto() const {
        return nombreProducto_;
    }
    int getIdProducto() const { 
        return idProducto_;
    }
    bool getActivo() const {
        return activo_;
    }
    //Setters
    void setNombreProducto(const string& nombre){
        nombreProducto_=nombre;
    }
    void setIdProducto(int id){
        idProducto_= id;
    }
    void setActivo(bool estado){
        activo_ = estado;
    }

    void MostrarProducto() const{
        cout<<"Producto: "<< nombreProducto_<<"ID: "<<idProducto_<<"Activo: "<<(activo_ ?"Si":"No")<< endl;
    }
};
//Clase aplicacion del banco 
class AplicacionBanco {
    private:
        string nombreApp_;
        int idApp_;
        vector<Cliente> clientes_;                  //composicion
        vector<CuentaBancaria> cuentas_;            //Agregacion
        vector<Tarjeta> tarjetas_;       
        vector<Inversion> inversiones_;

    public:
    AplicacionBanco(const string& nombre, int id):nombreApp_(nombre), idApp_(id) {
    }
    void IniciarSesion() {
        cout << "Sesion iniciada en:" << nombreApp_ << "ID "<< idApp_ << ")" << endl;
    }
    void CerrarSesion() {
        cout << "Sesion cerrada." << endl;
    }
    //Composicion porque crea los clientes
    void CrearCliente(const string& nombre, int id, int edad) {
        clientes_.push_back(Cliente(nombre, id, edad));
        cout << "Cliente creado:" << nombre << endl;
    }
    //Agregacion se agregan productos ya creados afuera osea en otras clases
    void RegistrarCuenta(const CuentaBancaria& c) {
        cuentas_.push_back(c);
        cout << "Cuenta registrada." << endl;
    }
    void RegistrarTarjeta(const Tarjeta& t) {
        tarjetas_.push_back(t);
        cout << "Tarjeta registrada." << endl;
    }
    void RegistrarInversion(const Inversion& i) {
        inversiones_.push_back(i);
        cout << "Inversion registrada." << endl;
    }

    //Muestra los catalogos
    void MostrarCatalogo() const {
        cout << "Catalogos del Banco";
        cout << "\nCuentas:\n";
        for (const auto& c : cuentas_) c.MostrarCuenta();
        cout << "\nTarjetas:\n";
        for (const auto& t : tarjetas_) t.MostrarTarjeta();
        cout << "\nInversiones:\n";
        for (const auto& i : inversiones_) i.MostrarInversion();
    }
};

//clase CuentaBancaria, que hereda de ProductoFinanciero

class CuentaBancaria : public ProductoFinanciero{
    private:
        string numeroCuenta_;
        double saldo_;

    public:
        CuentaBancaria():ProductoFinanciero(), numeroCuenta_(""), saldo_(0.0){
        }
        CuentaBancaria(const string& numero, double saldoInicial, int id):ProductoFinanciero("CuentaBancaria", id),numeroCuenta_(numero), saldo_(saldoInicial){
        }
        
    //Getters
        string getNumeroCuenta() const{
            return numeroCuenta_;
        }
        double getSaldo()const {
            return saldo_;
        }

    //Setters
        void setNumeroCuenta(const string& numero){
            numeroCuenta_= numero;
        }

        void setSaldo(double saldo){
            saldo_= saldo;
        }

        //Operaciones de la Cuenta
        void Depositar(double cantidad) {
            if (cantidad <= 0) {
                cout << "Deposito: Cantidad invalida.\n"<<endl;
                return;
            }
            saldo_ += cantidad;
            cout << "Depósito:"<<cantidad<<"saldo:"<<saldo_<<endl;
        }

        void Retirar(double cantidad) {
            if (cantidad <= 0.0) {
                cout << "Retiro fallido: la cantidad debe ser mayor a cero."<<endl;
                return;
            }
            if (cantidad > saldo_) {
                cout << "Retiro fallido: fondos insuficientes."<< endl;
                return;
            } 
            saldo_-= cantidad;
            cout<<"Retiro exitoso:-"<<cantidad<<"Saldo actual: $"<<saldo_<<endl;  
            }

        void MostrarCuenta() const{
            cout << "Cuenta: " << numeroCuenta_ << " | Saldo: $" << saldo_ <<endl;
        }
};

//clase  cliente, que no hereda nada y mantiene los identificadores de los productos

class Cliente{
    private:
        string nombreCliente_; 
        int idCliente_;
        int edad_;
        vector<string> cuentasNumeros_;
        vector<int> tarjetasIds_;
        vector<int> inversionesIds_;
    public:
        Cliente(): nombreCliente_(""), idCliente_(0), edad_(0){
        }
        Cliente(const string& nombre, int id, int edad): nombreCliente_(nombre), idCliente_(id), edad_(edad){
        }
    //Getters
    string getNombre() const{
        return nombreCliente_;
    }
    int getId() const{
        return idCliente_;
    }
    int getEdad() const{
        return edad_;
    }
    //Setter
    void setEdad(int edad){
        edad_=edad;
    }
    //Agraga las referencias osea los numeros de cuenta
    void AgregarCuentaNumero(const string& numeroCuenta){ 
        cuentasNumeros_.push_back(numeroCuenta);
    }
    void AgregarTarjetaId(int tarjetaId){
        tarjetasIds_.push_back(tarjetaId);
    }
    void AgregarInversionId(int inversionId){
        inversionesIds_.push_back(inversionId);
    }
    //Getters de las listas 
    const vector<string>& getCuentasNumeros() const {
        return cuentasNumeros_;
    }
    const vector<int>& getTarjetasIds() const{
        return tarjetasIds_;
    }
    const vector<int>& getInversionesIds()const{
        return inversionesIds_;
    }

    void MostrarCliente() const{
        cout<<"Cliente: "<< nombreCliente_<<"ID: "<<idCliente_<<"Edad: "<<edad_<< endl;
    }
};

//clase tarjeta de credito, que hereda de La aplicacion de Banco
class Tarjeta : public ProductoFinanciero {
    private:
        double limite_;
        double deuda_;
        double tasaInteresAnual_;//en porcentaje
    public:
        Tarjeta():ProductoFinanciero(),limite_(0.0), deuda_(0.0),tasaInteresAnual_(0.0){
        }
        Tarjeta(const string& nombre, double limite, double tasaAnual, int id): ProductoFinanciero(nombre, id),limite_(limite), deuda_(0.0), tasaInteresAnual_(tasaAnual){
        }
    //Getters
    double getLimite()const{
        return limite_;
    }
    double getDeuda()const{
        return deuda_;
    }
    double getTasaInteresAnual(double t){
        tasaInteresAnual_=t;
    }
    //setters
    void setLimite(double limite){///1
        limite_= 1;
    }
    void setTasaInteresAnual(double t){
        tasaInteresAnual_=t;
    }
    void Comprar(double cantidad){
        if(cantidad <= 0.0){
            cout<<"Compra: cantidad invalida."<<endl;
            return;
        }
        if(deuda_+cantidad>limite_){
            cout<<"compra rechazada: excede limite."<<endl;
            return;
        }
        deuda_ += cantidad;
        cout<<"Compra: "<<cantidad<<"Deuda: "<<deuda_<<endl;
    }
    void Pagar(double cantidad){
        if (cantidad <= 0.0) {
            cout << "Pago invalido."<< endl;
            return;
        }
        deuda_= std::max(0.0,deuda_-cantidad);
        cout << "Pago realizado:"<<cantidad<<"Deuda"<< deuda_ << endl;
    }
    void AplicarInteresMensual() {
        if (deuda_ <= 0.0) return;
        double tasaMensual = (tasaInteresAnual_ / 100.0) / 12.0;
        double interes =  std::round(deuda_ * tasaMensual*100.0)/100.0;
        deuda_ += interes;
        cout << "Interes mensual aplicado en Tarjeta: $" << interes << "Deuda:" << deuda_ << endl;
    }
    void MostrarTarjeta() const {
        cout << "Tarjeta: "<< getNombreProducto()<< "Limite: $" << limite_<< "Deuda: $" << deuda_<< "Tasa interés Anual: " << tasaInteresAnual_ << "%"<< endl;
    }
};
//Clase inversiones

class Inversion: public ProductoFinanciero{
    private:
        double montoInicial_;
        double tasaAnual_;//comunmente dado como porcentaje
        int meses_;
    public:
        Inversion(): ProductoFinanciero(), montoInicial_(0.0), tasaAnual_(0.0),meses_(0){
        }
        Inversion(double monto, double tasaAnual, int meses, int id): ProductoFinanciero("Inversion",id),montoInicial_(monto), tasaAnual_(tasaAnual), meses_(meses){
        }
    //Getters
    double getMontoInicial()const{
        return montoInicial_;
    }
    double getTasaAnual()const{
        return tasaAnual_;
    }
    int getMeses()const{
        return meses_;
    }

    double CalcularGanancia()const{
        double tasaMensual = (tasaAnual_/100.0)/12.0;
        double monto = montoInicial_;
        for(int i = 0; i < meses_; ++i){
            monto += monto*tasaMensual;
        }
        double ganancia = monto-montoInicial_;
        return std::round(ganancia*100.0)/100.0;
    }
    void MostrarInversion()const{
        cout<<"Inversion: Monto inicial $"<<montoInicial_<<"Meses: "<<meses_<<"Tasa anual: "<<tasaAnual_<<"%"<< endl;
    }
};
















