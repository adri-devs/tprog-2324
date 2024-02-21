/*
 * Clase VMPElectrico
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase que representa un vehículo de movilidad personal eléctrico.
 */
// Interfaz VMPElectrio

public class VMPElectrico extends VMP {
    // Atributos
    private int porcentajeCarga;
    private boolean cargando;

    // Constructores
    public VMPElectrico(int id, double[] ubicacion, boolean aparcado,
                        boolean disponible, int porcentajeCarga,
                        boolean cargando) {
        super(id, ubicacion, aparcado, disponible);
        this.porcentajeCarga = porcentajeCarga;
        this.cargando = cargando;
    }

    public VMPElectrico(int id, double[] ubicacion,
                        int porcentajeCarga, boolean cargando) {
        super(id, ubicacion);
        this.porcentajeCarga = porcentajeCarga;
        this.cargando = cargando;
    }

    // Getters y setters
    public int getPorcentajeCarga() {
        return porcentajeCarga;
    }

    public void setPorcentajeCarga(int porcentajeCarga) {
        this.porcentajeCarga = porcentajeCarga;
    }

    public boolean isCargando() {
        return cargando;
    }

    public void setCargando(boolean cargando) {
        this.cargando = cargando;
    }
}