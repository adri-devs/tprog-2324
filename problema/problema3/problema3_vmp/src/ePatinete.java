/*
 * Clase ePatinete
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase patinete electrico que hereda de VMP eléctrico.
 */
public class ePatinete extends VMPElectrico {
    public ePatinete(int id, double[] location, int porcentajeCarga,
                     boolean cargando) {
        super(id, location, porcentajeCarga, cargando);
    }

    public ePatinete(int id, double[] location, boolean aparcado,
                     boolean disponible, int porcentajeCarga, boolean cargando){
        super(id, location, aparcado, disponible, porcentajeCarga, cargando);
    }
}
