import java.util.Stack;

public class Swap implements Instruccion {
    public void ejecutar(Stack<Integer> pila, int pc) {
        int a = pila.pop();
        int b = pila.pop();
        pila.push(a);
        pila.push(b);
        pc++;
    }

    public String toString() {
        return "swap";
    }
}