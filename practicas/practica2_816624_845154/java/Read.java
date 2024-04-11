import java.util.Stack;
import java.util.Scanner;

public class Read implements Instruccion {
    public void ejecutar(Stack<Integer> pila, int pc) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        pila.push(a);
        pc++;
    }

    public String toString() {
        return "read";
    }
}