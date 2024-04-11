import java.util.Stack;

public class Push implements Instruccion {
    private int c;

    public Push(int val) {
        this.c = val;
    }

    public void ejecutar(Stack<Integer> pila, int pc) {
        pila.push(c);
        pc++;
    }

    public String toString() {
        return "push " + c;
    }
}