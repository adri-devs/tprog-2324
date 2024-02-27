import java.util.Stack;

public class Sumador extends Programa {
    public Sumador() {
        super(4);
        setInstruccion(0, new Read());
        setInstruccion(1, new Read());
        setInstruccion(2, new Add());
        setInstruccion(3, new Write());
    }
}