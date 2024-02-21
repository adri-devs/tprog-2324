/*
 * Clase Bicicleta
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase bicicleta que hereda de VMP.
 */
public class Bicicleta extends VMP {
    public Bicicleta(int id, double[] location) {
        super(id, location);
    }

    public Bicicleta(int id, double[] location, boolean aparcado,
                     boolean disponible) {
        super(id, location, aparcado, disponible);
    }
}