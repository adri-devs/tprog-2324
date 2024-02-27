import java.util.Stack;

public class Write implements Instruccion {
    public void ejecutar(Stack<Integer> pila, int pc) {
        System.out.println(pila.peek());
        pc++;
    }

    public String toString() {
        return "write";
    }
}