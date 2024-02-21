#pragma once

class Cuenta {
    public: // No es necesario agrupar todo en el mismo public o private
        enum TipoCuenta {
        CORRIENTE,
        AHORRO,
        PLAZO_FIJO,
        HIPOTECA,
        PRESTAMO,
        NOMINA,
        DEBITO,
        CREDITO
    };
    private:
        // Comun
        TipoCuenta tipo;
        double Capital;
        double interes;
        // Solo plazo fijo
        int plazo;

    public:
        Cuenta(TipoCuenta t, double Ci, double i, int p=0);
        Cuenta(double Ci, double i);
        Cuenta(double Ci, double i, int p);
        // no podríamos poner Cuenta(double Ci, double i, int p=0)
        // porque ya existe otro constructor con esos parámetros (el de arriba)
        double valor(int t);
        double tae(int t);
};
