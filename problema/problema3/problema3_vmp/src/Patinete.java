/*
 * Clase Patinete
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase patinete que hereda de VMP.
 */
public class Patinete extends VMP {
    public Patinete(int id, double[] location) {
        super(id, location);
    }

    public Patinete(int id, double[] location, boolean aparcado, boolean disponible) {
        super(id, location, aparcado, disponible);
    }
}