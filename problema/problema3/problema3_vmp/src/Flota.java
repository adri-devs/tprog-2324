/*
 * Clase Flota
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase flota que representa una flota de vehículos
 * de movilidad personal.
 */
import java.util.ArrayList;
import java.util.List;

public class Flota {
    private final List<VMP> vehiculos;

    public Flota() {
        vehiculos = new ArrayList<>();
    }

    public void agregarVMP(VMP vmp) {
        vehiculos.add(vmp);
    }

    public VMP obtenerVehiculoMasAlejado() {
        VMP masAlejado = null;
        double distanciaMaxima = Double.MIN_VALUE;
        for (VMP vmp : vehiculos) {
            double distancia = vmp.distanciaAlCentro();
            if (distancia > distanciaMaxima) {
                distanciaMaxima = distancia;
                masAlejado = vmp;
            }
        }
        return masAlejado;
    }

    public List<VMP> obtenerVehiculosAbandonados(double radio) {
        List<VMP> abandonados = new ArrayList<>();
        for (VMP vmp : vehiculos) {
            if (!vmp.isAparcado() && vmp.distanciaAlCentro() > radio) {
                abandonados.add(vmp);
                vmp.bloquear();
            }
        }
        return abandonados;
    }

    public List<VMPElectrico> obtenerVehiculosElectricosBateriaBaja(double porcentajeBateria) {
        List<VMPElectrico> electricosBateriaBaja = new ArrayList<>();
        for (VMP vmp : vehiculos) {
            if (vmp instanceof VMPElectrico vehiculoElectrico) {
                if (vehiculoElectrico.getPorcentajeCarga() < porcentajeBateria) {
                    electricosBateriaBaja.add(vehiculoElectrico);
                    vehiculoElectrico.setCargando(true);
                }
            }
        }
        return electricosBateriaBaja;
    }

    public List<VMP> obtenerFlota() {
        return vehiculos;
    }

    public double calcularPorcentajeVehiculosEnUsoPatinete() {
        int totalPatinetes = 0;
        int patinetesEnUso = 0;
        for (VMP vmp : vehiculos) {
            if (vmp instanceof Patinete || vmp instanceof ePatinete) {
                totalPatinetes++;
                if (!vmp.isAparcado() && !vmp.isDisponible()) {
                    patinetesEnUso++;
                }
            }
        }
        return (double) patinetesEnUso / totalPatinetes * 100;
    }
}
