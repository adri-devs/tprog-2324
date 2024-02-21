/*
 * Clase eBici
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase eBici que representa una bicicleta eléctrica.
 */
public class eBici extends VMPElectrico {
    public eBici(int id, double[] location, int porcentajeCarga, boolean cargando) {
        super(id, location, porcentajeCarga, cargando);
    }

    public eBici(int id, double[] location, boolean aparcado, boolean disponible,
                 int porcentajeCarga, boolean cargando) {
        super(id, location, aparcado, disponible, porcentajeCarga, cargando);
    }
}
