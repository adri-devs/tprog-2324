/*
    * Clase VMP (Vehículo de Movilidad Personal)
    * Autor: Adrián Pérez Pallarés
    * NIP: 816624
    * Fecha: 14/02/2024
    * Descripción: Clase que representa un vehículo de movilidad personal.
 */
public class VMP {
    // Atributos
    private int id;
    private double[] ubicacion;
    private boolean aparcado;
    private boolean disponible;

    // Constructores
    public VMP(int id, double[] ubicacion, boolean aparcado, boolean disponible) {
        this.id = id;
        this.ubicacion = ubicacion;
        this.aparcado = aparcado;
        this.disponible = disponible;
    }

    public VMP(int id, double[] ubicacion) {
        this.id = id;
        this.ubicacion = ubicacion;
        this.aparcado = true;
        this.disponible = true;
    }

    // Getters y setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double[] getUbicacion() {
        return ubicacion;
    }

    public void setUbicacion(double[] ubicacion) {
        this.ubicacion = ubicacion;
    }

    public boolean isAparcado() {
        return aparcado;
    }

    public void setAparcado(boolean aparcado) {
        this.aparcado = aparcado;
    }

    public boolean isDisponible() {
        return disponible;
    }

    public void setDisponible(boolean disponible) {
        this.disponible = disponible;
    }

    // Método que devuelve la distancia al centro de la ciudad
    public double distanciaAlCentro() {
        return Math.sqrt(Math.pow(ubicacion[0], 2) + Math.pow(ubicacion[1], 2));
    }

    // Metodo para alquilar
    public void alquilar() {
        if (disponible) {
            aparcado = false;
            disponible = false;
        }
    }

    // Metodo para devolver un patinete alquilado a una base
    public void devolver() {
        if (!disponible) { // && es_zona_base(ubicacion)
            aparcado = true;
            disponible = true;
        }
    }

    // Metodo para liberar un patinete en cualquier punto de la ciudad,
    // no hace falta poner aparcado = false puesto que solo se puede liberar
    // si no está aparcado. Aún así, tras librerar se podría alquilar.
    public void liberar() {
        disponible = true;
    }

    // Metodo para bloquear un patinete
    public void bloquear() {
        disponible = false;
    }
}

