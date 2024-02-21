
# Makefile para cuentas.cc, cuentas.h y main.cc

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Nombre del ejecutable
TARGET = programa

# Lista de archivos fuente
SRCS = cuentas.cc main.cc

# Generar nombres de archivos objeto
OBJS = $(SRCS:.cc=.o)

# Regla principal para construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para construir archivos objeto desde archivos fuente
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)
