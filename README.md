# POO Gestor de portafolio (Aplicacion Bancaria en C++).cpp
Gestor de portafolio (Tarjeta de credito)
Materia:POO
Lenguaje:C++
Fecha:07/12/2025

Problema:
- El objetivo de este proyecto es simular un sistema financiero básico utilizando La programación orientada a objetos.
- El usuario podrá representar un cliente, su cuenta bancaria, su app de Banco y una tarjeta de crédito.
- La mayoría de adolescentes al momento de entrar a la edad adulta obtienen una tarjeta de crédito para obtener un buen historial financiero, sinembargo la mayoría fracasa porque no saben como funcionan las tasas de interés, por eso este proyecto pretende simular los pagos que se deben de dar al banco en caso de deuda y las tasas de interés.

Objetivo del programa:
- Crear un objeto de tipo cliente.
- Crear una cuenta bancaria con saldo inicial.
- Crear una tarjeta de crédito con límite de crédito.
- Mostrar la información de los objetos que se crearán.
- Permitir creear acciones simples como depósitos, retiros, compras, pagos).
- Mostrar los resultados de cada operación en la pantalla.

Conceptos utilizados:
-Herencia
-Composicion
-Agregacion
-Encapsulamiento
-Archivos .h, .txt y .cpp


Clases del proyecto:

1. Cliente:
- Representa a la persona que utiliza el sistema.
-  Tiene nombre y edad e ID
-  Función:Imprimir toda la información del cliente
-  Registra las diferencias de el número de cuenta, ID de tarjeta y el ID de inversión.
-  Existe únicamente dentro de la aplicación de composición

2.ProductoFinanciero, la clase padre:
-Es la clase padre para todos los productos que ofrece la app.
-Atributos heredados por los demás productos:
-nombreProducto.
-idProducto.
-activo.
  
3. Cuenta bancaria:
- Representa una cuenta.
- Tiene número y saldo.
- Función: Depositar retirar y mostrar datos.

4. Tarjeta de crédito:
- Simula una tarjeta de crédito.
- Tiene limite, deuda y tasa de interés.
- Función: Comprar, pagar deuda y mostrar información.

5. Inversion, hereda de producto financiero:
-Es un producto que genera rendimiento sobre un monto inicial.
-Tiene: Monto inicial, meses y la tasa anual.
-Función: calcula la ganancia y muestra la inversion.

6.AplicacionBancoÑ
-Coordina todo el sistema
-Incluye:
1. composición: vector<Cliente_>,ya que los clientes solo existen dentro del app.
2. Agregacion: de la CunetaBancaria, las tarjetas y la inversión, ya que estos productos se crean fuera y la app los registra únicamente.
   
Compilación:
1. Manual:
g++ main.cpp \AplicacionBanco.cpp \Cliente.cpp \ProductoFinanciero.cpp \CuentaBancaria.cpp \Tarjeta.cpp \
Inversion.cpp \-o main
2.Powershell
g++ main.cpp AplicacionBanco.cpp Cliente.cpp ProductoFinanciero.cpp CuentaBancaria.cpp Tarjeta.cpp Inversion.cpp -o main
3.Compilar automaticamente los cpp
g++ *.cpp -o main
.\main



