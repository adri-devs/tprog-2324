/*
 * Clase Main
 * Autor: Adrián Pérez Pallarés
 * NIP: 816624
 * Fecha: 14/02/2024
 * Descripción: Clase main que simula el uso de una flota de vehículos de
 * movilidad personal.
 */
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#.##");
        Flota flota = new Flota();
        final int nVMP = 15;
        // Agregar VMP a la flota (generando un listado de 25 vehiculos con ubicacion, electrico o no, etc. aleatorio)
        for (int i = 0; i < nVMP; i++) {
            double[] ubicacion = new double[]{Math.random() * 10, Math.random() * 10};
            if (i % 2 == 0) {
                VMP bicicleta = new Bicicleta(i, ubicacion);
                flota.agregarVMP(bicicleta);
            } else if (i % 3 == 0) {
                VMP patinete = new Patinete(i, ubicacion);
                flota.agregarVMP(patinete);
            } else if (i % 5 == 0) {
                // Porcentaje carga aleatorio
                int porcentajeCarga = (int) (Math.random() * 100);
                VMP electricBici = new eBici(i, ubicacion, porcentajeCarga, false);
                flota.agregarVMP(electricBici);
            } else {
                int porcentajeCarga = (int) (Math.random() * 100);
                VMP electricPatinete = new ePatinete(i, ubicacion, porcentajeCarga, false);
                flota.agregarVMP(electricPatinete);
            }
            System.out.print("ID: " + i + " - ");
            System.out.println("Vehículo del tipo " + flota.obtenerFlota().get(i).getClass().getSimpleName() + " agregado a la flota.");
            if(flota.obtenerFlota().get(i) instanceof VMPElectrico vehiculoElectrico) {
                System.out.println("Porcentaje de carga: " + vehiculoElectrico.getPorcentajeCarga() + "%");
            }
            System.out.println("Ubicación: " + ubicacion[0] + ", " + ubicacion[1] + "\n");

        }

        // Ahora se realizarán las operaciones aleatorias simuladas por 50 usuarios: alquilar, devolver, cargar, etc.
        for (int i = 0; i < 15; i++) {
            int idVehiculo = (int) (Math.random() * nVMP);
            VMP vehiculo = flota.obtenerFlota().get(idVehiculo);
            if (vehiculo.isDisponible()) {
                System.out.println("Usuario " + i + " alquila vehículo con ID: " + idVehiculo);
                vehiculo.alquilar();
            } else {
                System.out.println("Usuario " + i + " devuelve vehículo con ID: " + idVehiculo);
                vehiculo.devolver();
            }
            // Generar un numero aleatorio entre 0 y 10 y si es menor que 3,
            // liberar el vehiculo, si es menor que 6, bloquearlo y si es menor
            // que 9, cargarlo
            int operacion = (int) (Math.random() * 10);
            if (operacion < 3) {
                System.out.println("admin " + i + " libera vehículo con ID: " + idVehiculo);
                vehiculo.liberar();
            } else if (operacion < 6) {
                System.out.println("admin " + i + " bloquea vehículo con ID: " + idVehiculo);
                vehiculo.bloquear();
            } else if (operacion < 9 && vehiculo instanceof
                    VMPElectrico vehiculoElectrico) {
                vehiculoElectrico.setCargando(true);
                System.out.println("Usuario " + i + " carga vehículo con ID: " + idVehiculo);
            }
        }

        // Vehículo más alejado del centro
        System.out.println("\nVehículo más alejado del centro:");
        VMP masAlejado = flota.obtenerVehiculoMasAlejado();
        System.out.println("ID: " + masAlejado.getId() + ", Distancia al centro: " + masAlejado.distanciaAlCentro() + " unidades");

        // Vehículos abandonados
        System.out.println("\nVehículos abandonados fuera de un radio de 1.2 unidades:");
        double radio = 1.2;
        for (VMP vmp : flota.obtenerVehiculosAbandonados(radio)) {
            System.out.print("ID: " + vmp.getId());
            System.out.println("... Bloqueando vehículo.");
            vmp.bloquear();
        }

        // Vehiculos con batería baja
        System.out.println("\nVehículos eléctricos con batería baja (menor al 50%):");
        double porcentajeBateria = 50.0;
        for (VMPElectrico vehiculo : flota.obtenerVehiculosElectricosBateriaBaja(porcentajeBateria)) {
            System.out.print("ID: " + vehiculo.getId());
            System.out.println("... Bloqueando vehículo.");
            vehiculo.bloquear();
        }

        // Porcentaje de usos
        System.out.println("\nPorcentaje de vehículos en uso de tipo patinete:");
        double porcentajeUsoPatinete = flota.calcularPorcentajeVehiculosEnUsoPatinete();
        System.out.println(df.format(porcentajeUsoPatinete) + "% de patinetes en uso");
    }
}
