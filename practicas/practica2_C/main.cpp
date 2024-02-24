#include <iostream>
#include <iomanip>
#include <stack>

/*
Instrucción: Deberá ser capaz de representar una instrucción del juego de instrucciones del microcontrolador. 
Cada una de las instrucciones tiene un comportamiento diferente sobre la pila al ser ejecutadas. 
Ese comportamiento diferente deberás representarlo mediante polimorfismo por inclusión, representando cada instrucción 
concreta como una clase derivada de una clase base dentro de una jerarquía de herencia. 
Las clases derivadas serán cada una de las instrucciones del juego de instrucciones, y
tendrán diferente comportamiento. Específicamente, una instrucción es algo que puede ejecutarse, y al
ejecutarse modifica la pila (cada instrucción particular de forma diferente), y avanza en 1 (o en otro valor, 
dependiendo de la instrucción) el pc de instrucciones para determinar la siguiente instrucción
a ejecutar. Adicionalmente, para poder listar el programa, cada instrucción deberá poder devolver una
cadena de texto que represente la propia instrucción.
*/

class Instruccion {
    public:
        virtual void ejecutar(std::stack<int>& pila, int& pc) = 0;
        virtual std::string toString() const = 0;
};

class Add : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc) {
            int a = pila.top();
            pila.pop();
            int b = pila.top();
            pila.pop();
            pila.push(a + b);
            pc++;
        }
        std::string toString() const {
            return "add";
        }
};

class Read : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc) {
            int a;
            std::cin >> a;
            pila.push(a);
            pc++;
        }
        std::string toString() const {
            return "read";
        }
};

class Write : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc) {
            std::cout << pila.top() << std::endl;
            pila.pop();
            pc++;
        }
        std::string toString() const {
            return "write";
        }
};

class Programa {
    private:
        int nInstrucciones, pc;
        using InstruccionPtr = Instruccion*;
        InstruccionPtr* prog;
        
    public:
        Programa(int nInstrucciones) : nInstrucciones(nInstrucciones) {
            prog = new InstruccionPtr[nInstrucciones];
            pc = 0;
        }
        ~Programa() {
            delete[] prog;
        }
        void setInstruccion(int i, InstruccionPtr instruccion) {
            prog[i] = instruccion;
        }
        InstruccionPtr getInstruccion(int i) const {
            return prog[i];
        }
        int getNInstrucciones() const {
            return nInstrucciones;
        }
        void ejecutar(std::stack<int>& pila) {
            pc = 0; // Modificar cuando haya que añadir saltos o movimientos de pc
            while (pc < nInstrucciones) {
                prog[pc]->ejecutar(pila, pc);
            }
        }
        std::string toString() const {
            std::string s;
            for (int i = 0; i < nInstrucciones; i++) {
                s += std::to_string(i) + " " + prog[i]->toString() + "\n";
            }
            return s;
        }

};

class ProgramaSumador : public Programa {       
    public:
        ProgramaSumador() : Programa(4) {
            setInstruccion(0, new Read());
            setInstruccion(1, new Read());
            setInstruccion(2, new Add());
            setInstruccion(3, new Write());
        }
        ~ProgramaSumador() {
            for (int i = 0; i < getNInstrucciones(); i++) {
                delete getInstruccion(i);
            }
        }
};

int main() {
    ProgramaSumador p;
    std::stack<int> pila;
    p.ejecutar(pila);
    // Mostrar todo en pantalla
    std::cout << p.toString();
    return 0;
}
